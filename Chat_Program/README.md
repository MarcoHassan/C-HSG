## Client-Server Socket connession and Simple - imperfect - Chat

This is the final project for the Programming with Advanced Languages
contextual course of the University of St. Gallen. For the course I
decided to implement a simple Client-Sever Socket connession and
develop on it a simple chat.

Based on it two versions were developed. On the one hand I implemented
a simple one threaded Chat where one client at the time can connect to
the server. On the other hand I developed on the freely available
multithreaded code available at [MultiClient
Chat](https://github.com/rbaron/multichat).

### 1. Simple Client - Server Chat

The code for the simple Client-Server chat is available under the basics repository.

Before going into the code description it is possible to execute the
code by compiling and running the compiled bytecode on a local
computer or over a server. This will instruct the machine to open a
socket on a specified port and set it in listening mode waiting for a
Client to connect.

Once the server program is running on a machine it is possible to
connect to the former by running the compiled client code together
with the ```IP address``` of the machine where the server program is
running. This will connect the machine running the client program
through the TCP protocol to the other machine on ```port 8080```, the
port chosen for the communication.

Once the two machines are connected it is possible to follow the
instructions appearing on monitor and enter messages followed by the
send command. The messages will then display on the other platform and
the other person can continue the communication.

Finally, to close the conversation and to free up the socket
connession it is just necessary for one of the two to type the bye
message.

A simple demonstration of the execution of the above is demonstrated in the record below.

![ezgif com-video-to-gif](https://user-images.githubusercontent.com/42472072/56455758-d0a61180-6362-11e9-8eb7-1b59465d97d6.gif)

#### 1.1 Code Discussion

**Server Side:**

On the server side we firstly instantiate a socket defining the type
of addresses and type of communication protocol.

```
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)  // 0 means connession was successful
    { 
        perror("socket failed"); 
        exit(EXIT_FAILURE);                                  // close socket in case of unsuccessful connession. 
    } 
```

In this sense I decided to specify a socket of AF_INET address
type. This specifies that the socket can communicate with addresses of
Internet Protocol v4.

Moreover, I decided to specify the connection oriented TCP protocol by
specifying the SOCK_STREAM parameter. Finally, 0 stands as the default
protocol type for the previously specified arguments.

The if condition guarantees moreover that if the connections was
unsuccessful the socket is closed and the resources are released.

As a second step I attached a prespecified port to the opened socket
in order for the machine to connect with another machine and
communicate with it over the specified port.

The chosen port was 8080 as mentioned and it is important not to
select a port already used by the computer for other internet
communication. A list of available ports is available at [IANA port
numbers](https://www.iana.org/assignments/service-names-port-numbers/service-names-port-numbers.xhtml?).

```
if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, 
&opt, sizeof(opt))) 
{ 
 perror("setsockopt"); 
 exit(EXIT_FAILURE); 
}
```

Moreover, it is important to notice again the control operations
terminating the socket connection if a configuration error occurs.

As a third step it is necessary to specify the type of connection,
interface type and the port number in TCP/IP network byte order and to
set the socket in connection mode with devices respecting the above
conditions.

This was done specifying the above parameters into an address struct
and passing such parameters to the ```bind``` function of the
```sys/socket``` library.

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

This means that once the port is specified in byte order, the address
type is defined and the interface is defined any device trying to
connect to the device over the specified port with the
```INADDR_ANY``` is going to be connected to the device.

Once the conditions are successfully established it is finally
necessary to set the socket in listen mode so that it will be possible
for the server to process the connection request

```
    if (listen(server_fd, 3) < 0)  // notice the second argument represent the maximal number of connection allowed.
    { 
        perror("listen"); 
        exit(EXIT_FAILURE); 
    }
```

Once a client wish to connect it is then necessary to accept the
connection and save the address of the entity trying to connect in
order to interact with it in the chat execution and to finally close
the connection releasing the resources.

```
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address,  
			     (socklen_t*)&addrlen))<0)  // save connection address of the entity trying to connect with the socket.
    { 
        perror("accept"); 
        exit(EXIT_FAILURE); 
    } 
```

Once the connection is fully established a loop sets the server side
in reading mode receiving messages from the client until the
```send``` or ```bye``` messages arrives.

Conditional on which of the two occurs two different scenarios occurs.
If the client sends a ```bye``` message the server automatically
replies with ```bye``` message and closes the socket connection.

If a ```send``` message arrives, the latter will not be displayed and the
server will turn to writing mode accepting messages until either a
```send``` or ```bye``` message is written.

**Client Side:**

The client side program is the mirror to the server side program and differs slightly from it.

As in the server case it is necessary to open up a socket at first

```
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)   
    { 
        printf("\n Socket creation error \n"); 
        return -1; 
    }
```

Then as in the server case it is necessary to specify the connection parameters

```
/* Specify Socket Type and Port */
serv_addr.sin_family = AF_INET;                     
serv_addr.sin_port = htons(PORT);

/* Specify server IP address and convert it to binary form */
if(inet_pton(AF_INET, argv[1], &serv_addr.sin_addr)<=0)  
{ 
 printf("\nInvalid address/ Address not supported \n"); 
 return -1; 
} 
```

The difference is now that the crated socket is not set into listen mode
but rather connected to the the server specified port.

```
if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
    { 
        printf("\nConnection Failed \n"); 
        return -1; 
    }
```

Once the connection is established the code is analogous to the one
of the server side and two loops specifies the chat conditions. The
client is first set into write mode until the message ```send``` or
```bye``` is sent. At this stage depending on which terminating
message is sent the client moves either in reading mode or close the
socket connection in an analogous way the one described above.

### 2. Multithreaded Chat

The simple chat described above is expanded based on the multichat code
published on Github on the following link:

______________________

[MultiChat Repo](https://github.com/rbaron/multichat).
______________________


The code in the repository is expanded by

 * fixing a bug in the Client name declaration.

 * introducing a new function sending messages to all open client sockets but the one sending the current message.

 * programming the client thread termination and socket connection closure when the message ```bye``` is sent by the client.

Video demonstration of the ameiliorated program.

![ezgif com-video-to-gif (1)](https://user-images.githubusercontent.com/42472072/56458426-b120e000-6386-11e9-9fac-4dfc47430f8a.gif)

#### Code execution

To execute the program it is necessary to compile all the c++ files at first.

This can be done by executing the ```Makefile``` specified in the
multithread directory by running the make command in the shell.

```
$ make
```

The specified makefile will compile all of the source files with gdb
debugging option (through the ```-g flag```), enable all of the
compiler messages (through the ```-Wall flag```) and save the object
files in the ```obj``` directory.

Moreover, it will create a linker that will further combine all the
previously created object files in one single executable file
available at the ```multithread/bin/chat``` directory. Finally it is
important to see that the final executable file will be compiled with
the ```-pthread``` flag allowing for the usage of the POSIX linux
system standards based thread API for C/C++.

Given the above it is then possible to execute the main program by
running the ```multithread/bin/chat```.

The server will be in listening mode at this stage and it will be
possible for clients to connect either through an ad hoc created
```cpp``` program similar to the one created and discussed in the
previous section or through the telnet protocol specifying the IP
address of the server hosting the chat and the port on which to
connect as in the video example above.

#### Code discussion

The code of this multithreaded chat differs from the one outlined in
the previous section.  Being the code sufficiently complex the program
is separated into different ```cpp``` source files respectively backed by
header files containing the libraries dependencies of the program, the
global variable definitions (such as the Port chosen for the
Client-Server connection), and the general function structure.

The main idea and the main difference to the program previously
discussed consists in the creation of a an **array of Client arrays**
where clients id, socket connections ids will be saved and the
instantiation of a **array of threads** where the threads handling
each client will be saved.

Given this basics idea the rest of the program is straightforward.
The server object creation sets the server in listening mode with the
same parameters (interface, ports etc.) as the one chosen and explained
in the previous section.

Then the ```AcceptAndDispatch``` main loop continue the program.  It
creates a client array and a thread array for each client connecting.
It creates a char array for each client connected where the thread
will save the messages written by the client and it will forward the
message to all of the other connected clients through the
```SenToAllOther``` created function.

Finally the it is important to see how the ```AcceptAndDispatch```
function terminates the thread and the client connection if the input
message of the client is the ```bye``` message.

A final word is given to the ```LockMutex``` and ```UnlockMutex```
functions called when adding a client saving its id, when removing a
client and when sending messages. These functions are necessary in
critical sections where the concurrent execution of the code could
lead to poor program results. The ```LockMutex``` function let one
thread gain the exclusivity of running the critical section until the
```mutex``` is released with the ```UnlockMutex``` function.  To
understand the importance of such exclusivity think what would happen
if two clients would send a message concurrently. It might happen that
the clients would receive collage messages being a mix of the two
messages concurrently sent.

The ```LockMutex``` and ```UnlockMutex``` functions are defined in the
```mythread.cpp``` source file, however no magic hides below
them. They are simply the locking and the unlocking of the mutual
exclusivity of the threads through the ```pthread_mutex_lock``` and
```pthread_mutex_unlock``` functions of the ```pthread``` library with
additional printed messages returning the state of the operation.

The same holds for all of the other function definitions in the
```mythread.cpp``` source file. A discussion of them is therefore
omitted and left to the reader as is the discussion of the member
functions of the client class defined in the ```client.cpp``` source
file due to their triviality.



