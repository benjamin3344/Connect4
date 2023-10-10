# Name
Connect_Four

# Inroduction
A simple matching software of boardgame Connect Four running on linux

# Operating System
Linux, Mac OS (Terminal), Windows (PowerShell)

# Installation
Unzip the projects and running the following two commands:
```bash
make -f makefile_server
make -f makefile_client

```
If you are matching using local area network (LAN), modified the IP address to the server's IP address and port in client.c.


# Instructions 
Once installation finished, running commands on  two terminals respectively on the server and client:

```
./bin/server
./bin/client
```
After starting up, the software is initialized and the match started as shown below:

```
PORT:8888 IP:127.0.0.1
0 1 2 3 4 5 6 7 
1 _ _ _ _ _ _ _ 
2 _ _ _ _ _ _ _ 
3 _ _ _ _ _ _ _ 
4 _ _ _ _ _ _ _ 
5 _ _ _ _ _ _ _ 
6 _ _ _ _ _ _ _ 
Connect Four START!......
Client's turn:
0 1 2 3 4 5 6 7 
1 _ _ _ _ _ _ _ 
2 _ _ _ _ _ _ _ 
3 _ _ _ _ _ _ _ 
4 _ _ _ _ _ _ _ 
5 _ _ _ _ _ _ _ 
6 _ _ _ _ _ _ 0 
Server's turn:
1
0 1 2 3 4 5 6 7 
1 _ _ _ _ _ _ _ 
2 _ _ _ _ _ _ _ 
3 _ _ _ _ _ _ _ 
4 _ _ _ _ _ _ _ 
5 _ _ _ _ _ _ _ 
6 * _ _ _ _ _ 0 
Client's turn:
0 1 2 3 4 5 6 7 
1 _ _ _ _ _ _ _ 
2 _ _ _ _ _ _ _ 
3 _ _ _ _ _ _ _ 
4 _ _ _ _ _ _ _ 
5 _ _ _ _ _ _ 0 
6 * _ _ _ _ _ 0 
Server's turn:
1
0 1 2 3 4 5 6 7 
1 _ _ _ _ _ _ _ 
2 _ _ _ _ _ _ _ 
3 _ _ _ _ _ _ _ 
4 _ _ _ _ _ _ _ 
5 * _ _ _ _ _ 0 
6 * _ _ _ _ _ 0 

```

# Others
The program was adapted from the Gomoku games: https://github.com/youngyangyang04/Gomoku

The rules were adapted to Connect Four and Game termination process was optimized
