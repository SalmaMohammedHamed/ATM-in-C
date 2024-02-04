#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_
#define passwordLength 8
#define bank_id_length 10
#define valid 0
#define unvalid 1
#define account_user 0
#define Guard 1
typedef enum
{
	active,
	resricted,
	closed
}account_status;
typedef struct node
{
	char gender;
	unsigned char age;
	unsigned char status;
	struct node *next;
	unsigned long long int balance;
	unsigned long long int password;
	unsigned long long int bank_id;
	char national_id[14];
	//char padding1;
	char Guardian_national_id[14];
	//char padding2;
	char name[100];
	//char padding3;
	char Guardian [100];
	//char padding4;
	char adress[200];
}client;
/*creating a new space for an elemnt in the heap*/
client* creat_element();
/*Adding the created elemnt to the linkced list*/
client* add_element();
/*generate 8 digit password*/
void generate_password(client* user);
/*making sure the the entered name is valid "consists of 4 names or more"*/
int name_validation ( char* str);
/*valid 14 number national id*/
int national_id_validation (char* str);
/*generate 10 digit uniqe bank id */
void bank_id_generation (client* user);
/*search for an element in the list*/
client* search_element( unsigned long long int value);
/*function to take the client's name*/
void enter_name (client* user, int type);
/*function to take the client's national id*/
void enter_national_id (client* user, int type);
/*to take the gaurdian info if the client is not an adult*/
void Guardian_info (client* user);
/*display the clint's information*/
void display (client* user);
/*creating new account*/
void creat_account(void);
/*function to take the guardian's national id*/
void enter_Guardian_national_id (client* user, int type);
/*function to take the guardian's name*/
void enter_Guardian_name (client* user, int type);
#endif
