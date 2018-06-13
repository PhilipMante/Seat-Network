//Philip Mante
//Homework 1
// Airplane reservation
#include <stdio.h>
#include <stdlib.h>

int check();

int main()
{
	
	char seats[20];
	
	for (int i=0; i<20;i++)
	{
		seats[i]=0;
	
		}
	//creates the seats
	
	while (1 ==1 )
	{
		//keeps seats updated
		int seat = check();
		if(seats[seat] == 0)
		{
			printf("yes\n");
			seats[seat] = 1;
		}
		else if (seat != -1)
		{	
		printf("no\n");
		
		}

	}
		
	}
	
		

int check()
{
		char user[2];
			scanf("%s", user);
			//checks user input
			if(user[0]<'1'||user[0]>'9'||user[1]<'A'||user[1]>'B')
		{
			printf("?\n");
			return -1;
	}	
	return (user[0]-'0')+10*(user[1]-'A');
		
	
}
		


	
	
	
	
	
	



		

