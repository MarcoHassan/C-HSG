
// Server side C/C++ program to demonstrate Socket programming 
#include <iostream>
#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h>                // for memset and strlength
#include <string>                  // to declare strings
#include <pthread.h>               // for using POSIX threads to deal with multiple connessions

#define PORT 8080                  // port to be used for the communication

using namespace std;

void *task1(void *);               // thread task to execute

static int new_socket;             // socket id as global variable

int main() 
{ 
    int server_fd; 
    struct sockaddr_in address; 
    int opt = 1; 
    int addrlen = sizeof(address);                          // to save the right amount of space on the disk

    pthread_t threadA[3];                                   // create thread object to deal with multiple clients
       
    // Creating socket file descriptor 
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)  // 0 means connession was successful
    { 
        perror("socket failed"); 
        exit(EXIT_FAILURE);                                  // close socket in case of unsuccessful connession. 
    } 
       
    // Attach the above specified socket - server_fd - to the selected port of choice - 8080 -.
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, 
                                                  &opt, sizeof(opt))) 
    { 
        perror("setsockopt"); 
        exit(EXIT_FAILURE); 
    }
    
    address.sin_family = AF_INET;                            // specify type of connession, port (in network byte code) and allows the 
    address.sin_addr.s_addr = INADDR_ANY;                    // server to communicate with any interface through the INADDR_ANY and 
    address.sin_port = htons( PORT );                        // not just with one specific client and its address.
       
    // This connects the socket to the specified client address (in this case any address connecting through the INADDR_ANY option)
    // on the port 8080
    if (bind(server_fd, (struct sockaddr *)&address,  
                                 sizeof(address))<0) 
    { 
        perror("bind failed"); 
        exit(EXIT_FAILURE); 
    }

    /* Set the specified Socket in listen mode so that it will be possible for the server to process the connession requests */

    if (listen(server_fd, 3) < 0)  // notice the second argument represent the maximal number of connession allowed.
    { 
        perror("listen"); 
        exit(EXIT_FAILURE); 
    }

    /* 
       Create a new element where to memorize the socket number 
       wishing to connect. This will allow to proceed with the 
       connession while keeping the origin socket in listen mode
       for new connessions. 
    */

    int noThread = 0;

    while (noThread < 3)
      {
        cout << "Listening" << endl;

        //this is where client connects. svr will hang in this mode until client conn
	if ((new_socket = accept(server_fd, (struct sockaddr *)&address,  
				 (socklen_t*)&addrlen))<0)  // save connession address of the enity trying to connect with the socket.
	  { 
	    perror("accept"); 
	    exit(EXIT_FAILURE); 
	  } 
        else
	  {
            cout << "Connection successful" << endl;
	  }
        
        pthread_create(&threadA[noThread], NULL, task1, NULL); 
        
        noThread++;
      }
    
    for(int i = 0; i < 3; i++)
      {
        pthread_join(threadA[i], NULL);
      }
    
    return 0; 
} 

void *task1 (void *dummyPt)
{
  int valread;
  char buffer[1024] = {0};                                // to save socket messages 
  char *hello = (char*)"Hello from server";               // Server Message

  cout << "Thread No: " << pthread_self() << endl;

  valread = read( new_socket , buffer, 1024); 
  printf("%s\n",buffer ); 

  send(new_socket , hello , strlen(hello) , 0 ); 

  bool cont = true, bye;
  string test;    

  while(cont)
    {
      printf("\nClient message:\n");

      bool iter = true;
	
      while(iter)
	{
	  memset ( buffer, 0, 1024 );
	  valread = read( new_socket , buffer, 1024);

	  int i = 0;

	  test = "";

	  do{
	    test = test + buffer[i];
	    i++;
	  }while(buffer[i] != 0);

	  if(test != "send")
	    printf("%s\n",buffer);
		

	  bye = test == "bye" ? true:false;

	  if(test == "bye" || test == "send")
	    iter = false;
	}


      if(bye)
	{
	  string close = "bye";
	  send(new_socket, close.c_str(), close.length(), 0);
	  break;
	}	 
	
      string in_mes = "";

      cout << "\nEnter message you would like to send: " << endl;

      bool messaging = true;
	
      while(messaging)
	{
	  getline (cin, in_mes);

	  send(new_socket, in_mes.c_str(), in_mes.length(), 0);

	  if(in_mes == "send" || in_mes == "bye")
	    messaging = false;
	}
    }
    

  /* Close Connession */
  cout << "\nClosing thread and conn" << endl;
  close(new_socket);
}


