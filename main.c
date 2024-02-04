#include "linked_list.h"
#include "ATM.h"
#include <stdio.h>
#include <stdlib.h>
#define admin 1
#define client 2
# define FINISH 0
void main (void)
{
	char decision;
	char finish;
	system("cls");
	printf("*********WELLOME*********\n");
	do
	{
	printf("For Admin Mode press 1, for client mode press 2\n");
	scanf("%d",&decision);
	if (decision==admin)
	{
		//Admin main menu
	system("cls");
	take_pass();
	admin_main_menu();
	
		
	}
	else if (decision==client)
	{
		//client main menu
		system("cls");
		client_check();
	}
	else 
	{
		printf("Unvalid option\n");
		
	}
	printf("To finish the program press 0, to continue press anything else\n");
	scanf("%d",&finish);
	}while (finish!=0);
}
