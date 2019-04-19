#ifndef _server_h_
#define _server_h_

#include <iostream>
#include <vector>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string.h>                // for memset and strlength

#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h> 


#include "mythread.h"
#include "client.h"

#define PORT 8080                  // port to be used for the communication#define PORT 30666

using namespace std;

class Server {

  private:
    static vector<Client> clients;

    //Socket stuff
    int server_fd, clientSock;
    struct sockaddr_in serverAddr, clientAddr;
    char buff[256];

  public:
    Server();
    void AcceptAndDispatch();
    static void * HandleClient(void *args);

  private:
    static void ListClients();
    static void SendToAll(string in_mes);
    static int FindClientIndex(Client *c); 
};

#endif
