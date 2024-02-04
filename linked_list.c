#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
static client* start=NULL;
/*------------------------------------------------------*/
client* creat_element()
{
     return (client*)malloc(sizeof(client));

}
/*------------------------------------------------------*/
client* add_element()
{
	client* e = creat_element();
	e->next=NULL;
	if (start==NULL)
	{
		start = e;
		generate_password(e);
		e->balance=0;
		e->status=active;
		bank_id_generation(e);
		return e;
	}
	else
	{
		client* temp=start;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		if (temp->next==NULL)
		{
			temp->next=e;
			generate_password(e);
			e->balance=0;
			e->status=active;
			bank_id_generation(e);
			return e;
		}
	}
	
}
/*------------------------------------------------------*/
void generate_password(client* user) {
    srand(time(NULL));
    unsigned long long int pass = 0;
    for (int i = 0; i < passwordLength; i++) {
        int digit = rand() % 10;
        pass = pass * 10 + digit;
    }
    user->password = pass;
}
/*------------------------------------------------------*/

int name_validation ( char* str) {
    int count = 0;
    int isWord = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            isWord = 0;
        }
        else if (isWord == 0) {
            isWord = 1; 
            count++;
        }
    }
	if (count>=4)
	{
		return valid;
	}
	else
	{
		return unvalid;
	}
}

/*------------------------------------------------------*/
int national_id_validation (char* str)
{
	int length = 0;
    
    while (str[length] != '\0') {
        length++;
    }
    
    if (length==14)
	{
		return valid;
	}
	else 
	{
		return unvalid;
	}
}
/*------------------------------------------------------*/
void bank_id_generation (client* user)
{
	srand(time(NULL));
    unsigned long long int id = 0;
	client* result=NULL;
	do
	{
    for (int i = 0; i < bank_id_length; i++) {
        int digit = rand() % 10;
        id = id * 10 + digit;
    }
	result=search_element(id);
	}while(result!=NULL);
    user->bank_id = id;
}
/*------------------------------------------------------*/
client* search_element( unsigned long long int value)
{
    client* temp = start;
    while (temp != NULL)
    {
       
        
            if (temp->bank_id == value)
            {
                return temp;
            }
        temp = temp->next; 
    }
    return NULL;
}
/*------------------------------------------------------*/
void cpstr (char* str1,char* str2)
{
	int i=0;
	while (str1[i]!='\0')
	{
		str2[i]=str1[i];  //str2 os the distination
		i++;
	}
	str2[i]='\0';
}
/*------------------------------------------------------*/
void enter_name (client* user, int type)
{
	char scan_name[100];
	int res;
	printf("Enter the name(enter at least first four names): ");
	do
	{
		scanf(" %[^\n]",scan_name);
		res=name_validation(scan_name);
		if (res!=valid)
		{
			printf("Enter a full name(enter at least first four names): ");
		}
	}while(res!=valid);
	if (type == account_user)
	{
		cpstr(scan_name,user->name);
	}
	else if (type==Guard)
	{
		cpstr(scan_name,user->Guardian);
	}
	
}
/*------------------------------------------------------*/
void enter_national_id (client* user, int type)
{
	char scan_national_id[14];
	int res;
	printf("Enter the national ID (14 numbers): ");
	do
	{
		scanf("%s",scan_national_id);
		res=national_id_validation(scan_national_id);
		if (res!=valid)
		{
			printf("Enter a valid national ID (14 numbers): ");
		}
	}while(res!=valid);
	if (type == account_user)
	{
		cpstr(scan_national_id,user->national_id);
	}
	else if (type==Guard)
	{
		cpstr(scan_national_id,user->Guardian_national_id);
	}
	
}
/*------------------------------------------------------*/
void Guardian_info (client* user)
{
	printf("Enter the Guardian information\n");
	enter_name(user,Guard);
	enter_national_id(user,Guard);
}
/*------------------------------------------------------*/
void display(client* user) {
    printf("The name: %s\n", user->name);
    printf("The national ID: %s\n", user->national_id);
    printf("The bank ID: %llu\n", user->bank_id);
    printf("The password: %llu\n", user->password);
    printf("The age: %d\n", user->age);
    if (user->age < 21) {
        printf("Guardian information: \n");
        printf("The name: %s\n", user->Guardian);
        printf("The national ID: %s\n", user->Guardian_national_id);
    }
	switch(user->status)
	{
		case active: printf("The account is active\n" ); break;
		case resricted: printf("The account is resricted\n" ); break;
		case closed: printf("The account is closed\n" ); break;
		default: printf("Invalid status\n" ); break;
	}
	
	printf("The balance: %d\n", user->balance);
}