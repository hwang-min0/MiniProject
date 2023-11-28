#pragma once
#include "iostream"
typedef enum _SEX {
	FEMALE,
	MALE
} SEX;
class BankAccount
{
private:
	static size_t indexer;
	const size_t PASSWORD_COUNT{ 3U };
	size_t length{ 0u };
	std::string account_number;
	std::string name;
	std::string address;
	std::string credit_grade;
	SEX sex; // SEX type
	char password[BUFSIZ]{ 0 };
	double balance{ 0.0 };
public:
	BankAccount() = default;
	BankAccount(const std::string&, const std::string&, \
		const std::string&, const SEX&);
	BankAccount(const BankAccount&); // 복사생성자
	~BankAccount();
	const std::string& get_account_number() const;
	const std::string& get_name() const;
	const std::string& get_address() const;
	const std::string& get_credit_grade() const;
	const SEX& get_sex() const;
	void set_account_number(const std::string&);
	void set_name(const std::string&);
	void set_address(const std::string&);
	void set_sex(const SEX&);
	void set_credit_grade(const std::string&);

	void input_password();
	double check_balance() const;
	void set_blance(const double);
	double get_blance(const double);
	bool check_password(const std::string&);

	//bool withdraw();
	//bool deposit();

	static void set_indexer(const size_t);
	static size_t get_indexer();

};

