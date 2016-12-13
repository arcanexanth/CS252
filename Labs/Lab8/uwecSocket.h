#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/types.h>

int setupServerSocket(int portno);
int callServer(char* host, int portno);
int serverSocketAccept(int serverSocket);
void writeInt(int x, int socket);
int readInt(int socket);
