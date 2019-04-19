## Client-Server Socket connession and Simple - imperfect - Chatbot

This is the final project for the Programming with Advanced Languages contextual course of the University of St. Gallen. For the course
I decided to implement a simple Client-Sever Socket connession and develop on it a simple chatbot.

Based on it two versions were developed. On the one hand I implemented a simple one threaded Chatbot where one client at the time
can connect to the server. On the other hand I developed on the freely available multithreaded code available at [MultiClient Chat](https://github.com/rbaron/multichat).

### Simple Client - Server Chat

The code for the simple Cient-Server chat is available under the basics repository.

Before going into the code description it is possible to execute the code by compiling and running the compiled bytecode on a local computer or over
a server. This will instruct the machine to open a socket on a specified port and set it in listening mode waiting for a Client to connect.

Once the server program is running on a machine it is possible to connect to the former by running the compiled client code together with the IP
address of the machine where the server program is running. This will connect the machine running the client program through the TCP protocol
to the other machine on ```port 8080```, the port chosen for the communication.

Once the two machines are connected it is possible to follow the instructions appearing on monitor and enter messages followed by the send command.
The messages will then display on the other platform and the other person can continue the communication.

Finally, to close the conversation and to free up the socket connession it is just necessary for one of the two to type the ```bye``` message.

A simple demonstration of the execution of the above is demonstrated in the record below.

![asciinema](https://asciinema.org/connect/f3537cea-6363-4c89-8c17-0e92b05d4091.png)[https://asciinema.org/connect/f3537cea-6363-4c89-8c17-0e92b05d4091]



