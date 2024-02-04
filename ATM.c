#include "linked_list.h"
#include "ATM.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*------------------------------------------------------*/
void admin_main_menu (void)
{
	int decision2;  //note
	system("cls");
	printf("Press: \n");
	printf("1 to Create New Account\n");
	printf("2 to Open Existing Account\n");
	printf("3 to Exit the System\n");
	scanf("%d",&decision2);
	switch(decision2)
	{
		case creat : creat_account (); break;
		case open : open_existing_account(); break;
		case Exit : system("cls"); exit(0); break;
		default : printf("Invalid option\n"); break;
	}
}
/*------------------------------------------------------*/

void take_pass (void)
{
	unsigned int pass;
	unsigned short int i=0;
	system("cls");
	printf("Please enter the Admin password: ");

		for ( i=0;i<3;i++)
		{
			scanf("%d",&pass);
			if (pass==default_pass)
			{
				break;
			}
			else if (i<2)
			{
				printf("Incorrect password, Try again: ");
			}
		}
		if (i==3)
		{
			printf("You ran out of trials\n");
			exit(0);
		}

}
/*------------------------------------------------------*/
void client_check (void)
{
	unsigned long long int scan_bank_id;
	unsigned long long int scan_password;
	client* result=NULL;
	printf("Please entre your Id: ");
	scanf("%llu", &scan_bank_id);
	result=search_element(scan_bank_id);
	if (result!=NULL)
	{
		printf("Please entre your password: ");
		scanf("%llu", &scan_password);
		if (scan_password==result->password)
		{
			printf("Your information is:\n");
			display(result);
			client_menu(result);
		}
		else
		{
			printf("WRONG PASSWORD\n");
		}
	}
	else
	{
		printf("this ID does not exist\n");
	}
}
/*------------------------------------------------------*/
void client_menu (client* user)
{
		int desision;
		system("cls");
		printf("Press: \n");
		printf("1 to Make Transaction\n");
		printf("2 to Change Account password\n");
		printf("3 to Get Cash\n");
		printf("4 to Deposit in Account\n");
		printf("5 to Return to main menu\n");
		scanf("%d",&desision);
		switch(desision)
		{
			case transaction: make_transaction(user); break;
			case change_pass: change_password(user); break;
			case get: get_cash(user); break; 
			case deposit: deposit_in_account(user); break;
			case main_menu: client_menu(user); break;
			default: printf("Invalid option\n"); break;
		}
}

/*------------------------------------------------------*/
void change_password (client* user)
{
	unsigned long long int scan_password;
	system("cls");
	printf("Please entre your new password(a number with 8 digits): ");
	do
	{
		scanf("%llu", &scan_password);
		if (!hasMoreThan8Digits(scan_password))
		{
			printf("Please entre a valid new password(a number with 8 digits): ");
		}
	}while(!hasMoreThan8Digits(scan_password));
	user->password=scan_password;
	printf("DONE\n");
}
/*------------------------------------------------------*/

int hasMoreThan8Digits(unsigned long long int number)
{
    int digitCount = 0;
    unsigned long long int temp = number;

    while (temp != 0) {
        temp /= 10;
        digitCount++;
    }

    return (digitCount = 8);
}

/*------------------------------------------------------*/

void creat_account (void)
{
	
	system("cls");
	client* user = add_element();
	user->balance=0;
	enter_name(user,account_user);
	printf("Enter your full adress: ");
	scanf(" %[^\n]",&(user->adress));
	printf("Enter your age: ");
	scanf("%d",&(user->age));
	enter_national_id(user,account_user);
	if (user->age<21)
	{
		Guardian_info(user);
	}
	display(user);
}
/*------------------------------------------------------*/
void open_existing_account(void)
{
	unsigned long long int scan_bank_id;
	printf("Enter the bank ID of the account you want to open\n");
	scanf("%llu", &scan_bank_id);
	client* result=NULL;
	result=search_element(scan_bank_id);
	if (result!=NULL)
	{
		printf("the account information: \n");
		display(result);
		int desision;
		printf("Press: \n");
		printf("1 to Make Transaction\n");
		printf("2 to Change Account Status\n");
		printf("3 to Get Cash\n");
		printf("4 to Deposit in Account\n");
		printf("5 to Return to main menu\n");
		scanf("%d",&desision);
		switch(desision)
		{
			case Make_transaction: make_transaction(result); break;
			case Change_account_status: change_account_status(result); break;
			case Get_cash: get_cash(result); break; 
			case Deposit_in_account: deposit_in_account(result); break;
			case Return_to_main_menu: admin_main_menu(); break;
			default: printf("Invalid option\n"); break;
		}
	}		
	else
	{
		printf("this ID does not exist\n");
	}
}
/*------------------------------------------------------*/
void make_transaction(client* user)
{
	unsigned long long int scan_bank_id;
	unsigned int amount;
	client* result=NULL;
	printf("Enter the bank ID of the account you want to transfer money to\n");
	scanf("%llu", &scan_bank_id);
	result=search_element(scan_bank_id);
	if (result!=NULL)
	{
		printf("Enter the amount of money you want to transfer\n");
		scanf("%u", &amount);
		if (amount<=user->balance)
		{
			user->balance=user->balance-amount;
			result->balance=result->balance+amount;
		}
		
	}
	else
	{
		printf("this ID does not exist\n");
	}
	printf("the accounts after the operations: \n");
	display(user);
	display(result);
	
}
/*------------------------------------------------------*/
void change_account_status(client* user)
{
	int desision;
	printf("Press: \n");
	printf("1 to activate the account\n");
	printf("2 to resricte the account\n");
	printf("3 to close the account\n");
	scanf("%d",&desision);
	user->status=desision;
	display(user);
}
/*------------------------------------------------------*/

/*------------------------------------------------------*/
void get_cash(client* user)
{
	unsigned int amount;
	printf("Enter the amount of money you want to get\n");
	scanf("%u", &amount);
	user->balance=user->balance-amount;
	display(user);
}
/*------------------------------------------------------*/


/*------------------------------------------------------*/
void deposit_in_account(client* user)
{
	unsigned int amount;
	printf("Enter the amount of money you want to deposit\n");
	scanf("%u", &amount);
	user->balance=user->balance+amount;
	display(user);
	
}
/*------------------------------------------------------*/


