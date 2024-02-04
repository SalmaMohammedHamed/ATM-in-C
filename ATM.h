#ifndef _ATM_H_
#define _ATM_H_
typedef enum
{
	Make_transaction=1,
	Change_account_status,
	Get_cash,
	Deposit_in_account,
	Return_to_main_menu
}afer_opening_options_admin;
typedef enum
{
	transaction=1,
	change_pass,
	get,
	deposit,
	main_menu
}client_options;
typedef enum
{
	creat=1,
	open,
	Exit
}admin;

#define default_pass 1234
/*viewing the admin mood main menu*/
void admin_main_menu (void);
void take_pass (void);
void client_check (void);
/*viewing the client mood main menu*/
void client_menu (client* user);
void change_password (client* user);
int hasMoreThan8Digits(unsigned long long int number);
void creat_account (void);
void open_existing_account(void);
void make_transaction(client* user);
void change_account_status(client* user);
void get_cash(client* user);
void deposit_in_account(client* user);
#endif