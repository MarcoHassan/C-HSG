## Client-Server Socket connession and Simple - imperfect - Chatbot

This is the final project for the Programming with Advanced Languages contextual course of the University of St. Gallen. For the course I decided to implement a simple Client-Sever Socket connession and develop on it a simple chatbot.

Based on it two versions were developed. On the one hand I implemented a simple one threaded Chatbot where one client at the time can connect to the server. On the other hand I developed on the freely available multithreaded code available at [MultiClient Chat](https://github.com/rbaron/multichat).

### 1. Simple Client - Server Chat
The code for the simple Cient-Server chat is available under the basics repository.

Before going into the code description it is possible to execute the code by compiling and running the compiled bytecode on a local computer or over a server. This will instruct the machine to open a socket on a specified port and set it in listening mode waiting for a Client to connect.

Once the server program is running on a machine it is possible to connect to the former by running the compiled client code together with the ```IP address``` of the machine where the server program is running. This will connect the machine running the client program through the TCP protocol to the other machine on ```port 8080```, the port chosen for the communication.

Once the two machines are connected it is possible to follow the instructions appearing on monitor and enter messages followed by the send command. The messages will then display on the other platform and the other person can continue the communication.

Finally, to close the conversation and to free up the socket connession it is just necessary for one of the two to type the bye message.

A simple demonstration of the execution of the above is demonstrated in the record below.

![ezgif com-video-to-gif](https://user-images.githubusercontent.com/42472072/56455758-d0a61180-6362-11e9-8eb7-1b59465d97d6.gif)

#### 1.1 Code Discussion

**Server Side:**

On the server side we firstly instantiate a socket defining the type of addresses and type of communication protocol.

```
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)  // 0 means connession was successful
    { 
        perror("socket failed"); 
        exit(EXIT_FAILURE);                                  // close socket in case of unsuccessful connession. 
    } 
```

In this sense I decided to specify a socket of AF_INET address type. This specifies that the socket can
communicate with addresses of Internet Protocol v4.

Moreover, I decided to specify the connection oriented TCP protocol by specifying the SOCK_STREAM parameter. Finally,
0 stands as the default protocol type for the previously specified arguments.

The if condition guarantees moreover that if the connessions was unsuccessful the socket is closed and the resources are released.

As a second step I attached a prespecified port to the opened socket in order for the machine to connect with another machine and communicate with it over the specified port.

The chosen port was 8080 as mentioned and it is important not to select a port already used by the computer for other internet communication. A list of avaialble ports is available at [IANA port numbers](https://www.iana.org/assignments/service-names-port-numbers/service-names-port-numbers.xhtml?).

```
if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, 
&opt, sizeof(opt))) 
{ 
 perror("setsockopt"); 
 exit(EXIT_FAILURE); 
}
```

Moreover, it is important to notice again the control operations terminating the socket connession if a configuration error occurs.

As a third step it is necessary to specify the type of connession, interface type and the port number in TCP/IP network byte order and to set the socket in connession mode with devices respecting the above conditions.

This was done specifing the above parameters into an address struct and passing such parameters to the ```bind``` function of the ```sys/socket``` library.

```
    address.sin_family = AF_INET;                            
    address.sin_addr.s_addr = INADDR_ANY;                    
    address.sin_port = htons( PORT );                        
       
    if (bind(server_fd, (struct sockaddr *)&address,  
                                 sizeof(address))<0) 
    { 
        perror("bind failed"); 
        exit(EXIT_FAILURE); 
    }
```

This means that once the port is specified in byte order, the address type is defined and the interface is defined any device trying to connect to the device over the specified port with the ```INADDR_ANY``` is going to be connected to the device.

Once the conditions are successfully established it is finally necessary to set the socket in listen mode so that it will be possible for the server
to process the connession request

```
    if (listen(server_fd, 3) < 0)  // notice the second argument represent the maximal number of connession allowed.
    { 
        perror("listen"); 
        exit(EXIT_FAILURE); 
    }
```

Once a client wish to connect it is then necessary to accept the connession and save the address of the entity trying to connect in order to interact with it in the chatbot execution and to finally close the connession releasing the resources.

```
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address,  
			     (socklen_t*)&addrlen))<0)  // save connession address of the enity trying to connect with the socket.
    { 
        perror("accept"); 
        exit(EXIT_FAILURE); 
    } 
```

Once the connession is fully established a loop sets the server side in reading mode receiving messages from the client until the ```send``` or ```bye``` messages arrives.

Conditional on which of the two occurs two different scenarios occurs.
If the client sends a ```bye``` message the server automatically replies with ```bye``` message and closes the socket connession.

If a ```send``` message arrives, the latter will not be displayed and the
server will turn to writing mode accepting messages until either a
```send``` or ```bye``` message is written.

**Client Side:**


