
// Client side C/C++ program to demonstrate Socket programming 
#include <iostream>
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h>
#include <unistd.h>        // for reading socket 
#include <arpa/inet.h>     // to convert IPv4 to IPv6 with inet_pton 
#define PORT 8080          // choose port to communicate.
   
int main(int argc, char const *argv[]) 
{ 
    struct sockaddr_in address; 
    int sock = 0, valread; 
    struct sockaddr_in serv_addr; 
    char *hello = (char*)"Hello from client"; 
    char buffer[1024] = {0};
    
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)   /* create a socket.
							   
							   AF_INET = address family that is used to designate the type of addresses 
							   that your socket can communicate with (in this case, Internet Protocol v4 addresses)

							   SOCK_STREAM = type of socket. In this case connection-oriented TCP protocol. 
							   Sequential duplex connession.
							   The connection is established and the two parties have a conversation until 
							   the connection is terminated by one of the parties or by a network error.

							   0 = Particolare protocollo da usare con la socket per la per gli arogomenti sopra indicati. 
							       O stands as the default protocal type for the previously specified argumetns.
							
							   Socket returns an int > 0 if successful referencing the socket and -1 if the connession was not
							   successful. Therefore the <0 to handle connectivity issue.

							*/
    { 
        printf("\n Socket creation error \n"); 
        return -1; 
    }

    /* Specify Socket Type and Port of the Server */
   
    memset(&serv_addr, '0', sizeof(serv_addr));         // save memory of sizeof(serv_addr) for the serv_addr pointer.
   
    serv_addr.sin_family = AF_INET;                     // specify server address type in accordance with the one set above.
    serv_addr.sin_port = htons(PORT);                   // htons function converts a u_short from host to TCP/IP network byte order (which is big-endian).
    

    /* Specify Socket Address */
    
    // Convert IPv4 and IPv6 addresses from text to binary form and save
    // the IP address of the server where we wish to connect.

    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)  
    { 
        printf("\nInvalid address/ Address not supported \n"); 
        return -1; 
    } 

    // Connect the above specified socket to the socket in listen mode on
    // the server with the IP, port and connession type specifed above.
    
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
    { 
        printf("\nConnection Failed \n"); 
        return -1; 
    }

    /* Send Messages throught the connected sock instance and read the 
       messages received 
    */
    
    send(sock , hello /* pointer containing message */ , strlen(hello) , 0 );

    valread = read( sock , buffer, 1024); 
    printf("%s\n",buffer );

    bool cont = true;

    while(cont)
      {	
	std::string in_mes = "";

	std::cout << "\nEnter message you would like to send: " << std::endl;

	bool messaging = true;
	
	while(messaging)
	  {
	    std::getline (std::cin, in_mes);

	    send(sock, in_mes.c_str(), in_mes.length(), 0);

	    if(in_mes == "send" || in_mes == "bye")
	      messaging = false;
	  }

	bool bye;                                       
	std::string test;

        printf("\nServer message:\n");                           
                                                                 
        bool iter = true;

	        while(iter)                                              
          {                                                      
            memset ( buffer, 0, 1024 );                          
            valread = read( sock , buffer, 1024);          
                                                                 
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
	    in_mes = "bye";
	    send(sock, in_mes.c_str(), in_mes.length(), 0);
	    break;
	  }	 
      }

    close(sock); // to close socket at the end of the communication.
    return 0; 
} 


