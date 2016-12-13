#include "uwecSocket.h"

/* int setupServerSocket(int portno);
 * int callServer(char* host, int portno);
 * int serverSocketAccept(int serverSocket);
 * void writeInt(int x, int socket);
 * int readInt(int socket);
*/
int main(){
   int port = 23976;
   int start = 1000;
   int end = 1000000;
   int sock;
   int newsockfd;
   int i;
   sock = setupServerSocket(port);
   newsockfd = serverSocketAccept(sock);
}
