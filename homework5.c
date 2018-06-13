//Philip Mante
//Homework 5
//Threads
//CSCI342

#include <pthread.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
 
void *plane(void *socket_desc);
int mysock;
char seats[20];
int main(int argc,char **argv)
{
  //Variables
  int sock;
  struct sockaddr_in server;
  
  
  int addr_len = sizeof(server);
  
	//Seat List
	
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
  pthread_t thread_id;
   while( (mysock = accept(sock, (struct sockaddr *)&server, (socklen_t*)&addr_len)) )
    {
        puts("Connection accepted");
         
        if( pthread_create( &thread_id , NULL ,  plane , (void*) &mysock) < 0)
        {
            perror("could not create thread");
            return 1;
        }
         
        
        puts("Thread Created");

		
		
		
		}
  
  
	
  
  //accept
  
 
	  
  
  
	return 0;
  
}

void *plane(void *socket_desc)
{
	int sock = *(int*)socket_desc;
	int read_len;
	char *message , client_message[2000];
	int rval;
  char buff[2];
	
	message = "Hello you connected to the seat reservation server \n";
	write(sock, message, strlen(message));
	

	
		if(sock == -1)
		{
			perror("accept failed");
		}
		else
		{
		
			memset(buff, 0, sizeof(buff));
				if((rval = recv(sock, buff, sizeof(buff), 0)) < 0)
				{
						perror("reading stream message error");
						
				}
				else if (rval==0)
				{
						printf("Ending connection\n");
					
				}
				else
				{
				pthread_mutex_lock(&lock);
				
			//MY server method	
				if(buff[0]<'1'||buff[0]>'9'||buff[1]<'A'||buff[1]>'B')
				{
						write(sock,"?\n",2);
					
				}
			else{		
					
					
					int seat = (buff[0]-'0')+10*(buff[1]-'A');
					
	
					if(seats[seat] == 0)
					{
						write(sock,"yes\n",4);
						seats[seat] = 1;
					}
					else if (seat != -1)
					{	
						write(sock,"no\n",3);
		
					}
					
				}
				
				pthread_mutex_unlock(&lock);
				close(sock);

		}
		
		}		
	  
	  
	
}
