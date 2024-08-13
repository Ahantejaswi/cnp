#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
void error(const char *msg)
{
perror(msg);
exit(1);
}
int main(int argc, char *argv[])
{
int sockfd, newsockfd, portno;
socklen_t clilen;
char buffer[256];
struct sockaddr_in serv_addr, cli_addr;
int n;
if (argc < 2)
{
fprintf(stderr,"You have'nt provided port Number, please enter port number\n");
exit(1);
}
sockfd = socket(AF_INET, SOCK_STREAM, 0);
if (sockfd < 0)
error("Server : error at port opening");
bzero((char *) &serv_addr, sizeof(serv_addr));
portno = atoi(argv[1]);
serv_addr.sin_family = AF_INET;
serv_addr.sin_addr.s_addr = INADDR_ANY;
serv_addr.sin_port = htons(portno);
if (bind(sockfd, (struct sockaddr *) &serv_addr,
sizeof(serv_addr)) < 0)
error("Server : Error at binding");
listen(sockfd,5);
clilen = sizeof(cli_addr);
newsockfd = accept(sockfd,
(struct sockaddr *) &cli_addr,
&clilen);
if (newsockfd < 0)
error("Server : Error while accepting");
bzero(buffer,256);
n = read(newsockfd,buffer,255);
if (n < 0) error("Server : ERROR reading from socket");
printf("MY message is : %s\n",buffer);
n = write(newsockfd,"I Have Recieved your message",30);
if (n < 0) error("Server : Error while writing to server");
close(newsockfd);
close(sockfd);
return 0;
}







#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
void error(const char *msg)
{
perror(msg);
exit(0);
}
int main(int argc, char *argv[])
{
int sockfd, portno, n;
struct sockaddr_in serv_addr;
struct hostent *server;
char buffer[256];
if (argc < 3) {
fprintf(stderr,"usage %s Enter your hostname & port number \n", argv[0]);
exit(0);
}
portno = atoi(argv[2]);
sockfd = socket(AF_INET, SOCK_STREAM, 0);
if (sockfd < 0)
error("Client : Error While opening socket");
server = gethostbyname(argv[1]);
if (server == NULL) {
fprintf(stderr,"Client : Error, host not found\n");
exit(0);
}
bzero((char *) &serv_addr, sizeof(serv_addr));
serv_addr.sin_family = AF_INET;
bcopy((char *)server->h_addr,
(char *)&serv_addr.sin_addr.s_addr,
server->h_length);
serv_addr.sin_port = htons(portno);
if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
error("Client : Error while connecting to server");
printf("Please enter your message: ");
bzero(buffer,256);
fgets(buffer,255,stdin);
n = write(sockfd,buffer,strlen(buffer));
if (n < 0)
error("Client : Error while writing to socket");
bzero(buffer,256);
n = read(sockfd,buffer,255);
if (n < 0)
error(" Client : Error while reading from socket");
printf("%s\n",buffer);
close(sockfd);
return 0;
}
