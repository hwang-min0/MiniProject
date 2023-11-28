#pragma once
#include "BankAccount.h"
#include <vector> // STL -> Java API -> Android Phone
typedef enum _MENU {
	ACCOUNT_NUMBER,
	ACCOUNT_NAME,
	ACCOUNT_ADDRESS,
	ACCOUNT_CREDIT,
	ACCOUNT_DEPOSIT,
	ACCOUNT_WITHDRAW
}MENU;
class BankAccountControl
{
private:
	std::vector<BankAccount> _vec;
	MENU menu;
public:
	BankAccountControl() = default;
	void add_account_bank(const BankAccount&);
	void search_account_bank();
	void input_account_bank(BankAccount&);
	void deposit();
	void withdraw();
};

