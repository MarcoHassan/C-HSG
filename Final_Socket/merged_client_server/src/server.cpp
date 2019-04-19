#include "server.h"

using namespace std;

//Actually allocate clients
vector<Client> Server::clients;

Server::Server() {

  //Initialize static mutex from MyThread
  MyThread::InitMutex();

  int opt = 1;

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
    
  serverAddr.sin_family = AF_INET;                            // specify type of connession, port (in network byte code) and allows the 
  serverAddr.sin_addr.s_addr = INADDR_ANY;                    // server to communicate with any interface through the INADDR_ANY and 
  serverAddr.sin_port = htons( PORT );                        // not just with one specific client and its address.
       
  // This connects the socket to the specified client address (in this case any address connecting through the INADDR_ANY option)
  // on the port 8080
  if (bind(server_fd, (struct sockaddr *)&serverAddr,  
	   sizeof(serverAddr))<0) 
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

}


/*
	AcceptAndDispatch();

	Main loop:
		Blocks at accept(), until a new connection arrives.
		When it happens, create a new thread to handle the new client.
*/

void Server::AcceptAndDispatch() {
  
  Client *c;
  MyThread *t;

  socklen_t cliSize = sizeof(sockaddr_in);

  while(1) {

          c = new Client();
	  t = new MyThread();

	  //Blocks here;
          c->sock = accept(server_fd, (struct sockaddr *) &clientAddr, &cliSize);

	  if(c->sock < 0) {
	    cerr << "Error on accept";
	  }
	  else {
	    t->Create((void *) Server::HandleClient, c);
	  }
  }
}

//Static
void *Server::HandleClient(void *args) {

  //Pointer to accept()'ed Client
  Client *c = (Client *) args;
  char buffer[1024] = {0};
  string in_mes, test;
  char clientid[200];
  int index;
  bool cont = true, bye;

  //Add client in Static clients <vector> (Critical section!)
  MyThread::LockMutex((const char *) c->name);
  
    //Before adding the new client, calculate its id. (Now we have the lock)
    c->SetId(Server::clients.size());
    sprintf(buffer, "Client n.%d", c->id);
    c->SetName(buffer);
    cout << "Adding client with id: " << c->id << endl;
    Server::clients.push_back(*c);

  MyThread::UnlockMutex((const char *) c->name);

  while(cont) {

    bool iter = true;
	
    while(iter)
      {
	Server::SendToAll("\nEnter message to send:\n");	
	
	memset ( buffer, 0, 1024 );
	read(c->sock , buffer, 1024);
	
	sprintf(clientid, "Client n.%d: \n", c->id);

	/* Messages to send */
	Server::SendToAllOther("\nNew Message Received:\n", c);	
	Server::SendToAllOther(clientid, c);
	Server::SendToAllOther(buffer, c);

	int i = 0;

	test = "";

	while(buffer[i] != 0)
	  {
	    test = test + buffer[i];
	    i++;
	  }

	cout << "test is: " << test << "nono";

	bye = test == "bye\n" ? true:false;

	cout << "bye is: " << bye << endl;

	if(test == "bye" || test == "send")
	  iter = false;
      }

    //Client disconnected?
    if(bye) {
      cout << "Client " << c->name << " diconnected" << endl;
      close(c->sock);
      
      //Remove client in Static clients <vector> (Critical section!)
      MyThread::LockMutex((const char *) c->name);

        index = Server::FindClientIndex(c);
        cout << "Erasing user in position " << index << " whose name id is: " 
	  << Server::clients[index].id << endl;
        Server::clients.erase(Server::clients.begin() + index);

      MyThread::UnlockMutex((const char *) c->name);

      break;
    }
  }

  //End thread
  return NULL;
}

void Server::SendToAllOther(string in_mes, Client *c) {

  //Acquire the lock
  MyThread::LockMutex("'SendToAllOther()'");
  size_t id = c->id;
    for(size_t i=0; i<clients.size(); i++) {
      if(i != id)
	send(Server::clients[i].sock, in_mes.c_str(), in_mes.length(), 0);
    }
   
  //Release the lock  
  MyThread::UnlockMutex("'SendToAllOther()'");
}

void Server::SendToAll(string in_mes) {

  //Acquire the lock
  MyThread::LockMutex("'SendToAll()'");
    for(size_t i=0; i<clients.size(); i++) {
      send(Server::clients[i].sock, in_mes.c_str(), in_mes.length(), 0);
    }
   
  //Release the lock  
  MyThread::UnlockMutex("'SendToAll()'");
}

void Server::ListClients() {
  for(size_t i=0; i<clients.size(); i++) {
    cout << clients.at(i).name << endl;
  }
}

/*
  Should be called when vector<Client> clients is locked!
*/
int Server::FindClientIndex(Client *c) {
  for(size_t i=0; i<clients.size(); i++) {
    if((Server::clients[i].id) == c->id) return (int) i;
  }
  cerr << "Client id not found." << endl;
  return -1;
}

