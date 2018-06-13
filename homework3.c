//Philip Mante
//Philip Mante
//CSCI342
//Homework 3
// Airplane reservation Network
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 

 
int main(int argc,char **argv)
{
  //Variables
  int sock;
  struct sockaddr_in server;
  int mysock;
  int rval;
  char buff[2];
	//Seat List
	char seats[20];
	for (int i=0; i<20;i++)
	{
		seats[i]=0;
	
	}
  
  //Create Soocket
  sock = socket(AF_INET,SOCK_STREAM,0);
  if (sock <0)
  {
	  perror("failed to create");
	  exit(1);
	  
	  
	  
	  
  }
  
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = INADDR_ANY;
  server.sin_port = htons(1218);
  printf("Listening \n");
  //Call Bind
  if(bind(sock,(struct sockaddr *)& server,sizeof(server)))
  {
	  perror("bind failed");
	  exit(1);
	  
	  
	  
  }
  
  
  //listen
  
  listen(sock,5);
  
  
	
  
  //accept
  do {
		mysock = accept(sock, (struct sockaddr *) 0, 0);
		if(mysock == -1)
		{
			perror("accept failed");
		}
		else
		{
		
			memset(buff, 0, sizeof(buff));
				if((rval = recv(mysock, buff, sizeof(buff), 0)) < 0)
				{
						perror("reading stream message error");
						
				}
				else if (rval==0)
				{
						printf("Ending connection\n");
					
				}
				else
				{
				
				
			//MY server method	
				if(buff[0]<'1'||buff[0]>'9'||buff[1]<'A'||buff[1]>'B')
				{
						write(mysock,"?\n",2);
					
				}
			else{		
					
					
					int seat = (buff[0]-'0')+10*(buff[1]-'A');
					
	
					if(seats[seat] == 0)
					{
						write(mysock,"yes\n",4);
						seats[seat] = 1;
					}
					else if (seat != -1)
					{	
						write(mysock,"no\n",3);
		
					}
					
				}
				
				
				close(mysock);

		}
		}		
	  
	   } while (1);
  
  
	return 0;
  
}


