#include "uwecSocket.h"

int setupServerSocket(int portno){
   /*vars*/
   int sock;
   struct sockaddr_in serv_addr;

   /* create socket*/
   sock = socket(AF_INET, SOCK_STREAM,0);
   if(sock < 0){
     perror("Failed to create socket");
     exit(1);
   }

   serv_addr.sin_family = AF_INET;
   serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
   serv_addr.sin_port = portno;

   /*Call bind*/
   if(bind(sock,(struct sockaddr*) &serv_addr, sizeof(serv_addr))<0){
      perror("bind failed");
      exit(1);
   }
   
   /*Listen*/
   listen(sock, 5);
   
   printf("listening on port: %d\n", portno);

   return sock;
}

int callServer(char* host, int portno){
   printf("The port number is: %d\n", portno);
   
   int sock;
   sock = socket(AF_INET, SOCK_STREAM, 0);
   if(sock < 0){
      fprintf(stderr, "ERROR opening socket\n");
      exit(0);
   }
   
   struct sockaddr_in serv_addr;
   
   memset(&serv_addr, '0', sizeof(serv_addr));

   serv_addr.sin_family = AF_INET;

   serv_addr.sin_port = htons(portno);

   struct hostent *server;
   server = gethostbyname(host);
   if(server == NULL) {
      fprintf(stderr, "ERROR, no such host\n");
      exit(0);
   }
   memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);

   if(connect(sock,(struct sockaddr *) &serv_addr, sizeof(serv_addr)) <0){
      printf("ERROR connecting\n");
      exit(0);
   }
   return sock;
}

int serverSocketAccept(int serverSocket){
     int newsockfd;
     struct sockaddr_in cli_addr;
     socklen_t clilen = sizeof(cli_addr);
     
     //waiting for a call//
     printf("waiting for a call...\n");
     newsockfd = accept(serverSocket, (struct sockaddr*) &cli_addr, &clilen);
     printf("Connected\n");
     if(newsockfd < 0){
        printf("ERROR on accept");
        exit(1);
     }
     return newsockfd;
}

void writeInt(int x, int socket){
    
    int n = write(socket, &x, sizeof(int));
    if(n < 0){
       printf("ERROR writing to socket\n");
       exit(1);
    }
}

int readInt(int socket){
    int x;
    int n = read(socket, &x, sizeof(int));
    if(n<0){
       printf("Error reading from socket\n");
       exit(1);
    }
    return x;
}
