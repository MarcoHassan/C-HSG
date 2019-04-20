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


