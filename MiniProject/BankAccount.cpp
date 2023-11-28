#include "BankAccount.h"
size_t BankAccount::indexer{ 0u }; // 클래스 변수 초기화
BankAccount::BankAccount(const std::string& _account_number,
	const std::string& name, \
	const std::string& address, const SEX& sex) :
	account_number(_account_number), name(name),
	address(address), sex(sex)
{
	
	++BankAccount::indexer;
}
BankAccount::BankAccount(const BankAccount& rhs):
	account_number(rhs.account_number),
	name(rhs.name), address(rhs.address),
	credit_grade(rhs.credit_grade),
	sex(sex)
{
	strcpy_s(this->password, BUFSIZ, rhs.password);
	++BankAccount::indexer;
	
}

BankAccount::~BankAccount()
{
	--BankAccount::indexer;
}

const std::string& BankAccount::get_account_number() const
{
	return this->account_number;
}
const std::string& BankAccount::get_name() const
{
	return this->name;
}
const std::string& BankAccount::get_address() const
{
	return this->address;
}
const std::string& BankAccount::get_credit_grade() const
{
	return this->credit_grade;
}

const SEX& BankAccount::get_sex() const 
{
	return this->sex;
}

void BankAccount::set_indexer(const size_t indexer)
{
	BankAccount::indexer = indexer;
}

size_t BankAccount::get_indexer()
{
	return BankAccount::indexer;
}

void BankAccount::set_account_number(\
	const std::string& _account_number)
{
	this->account_number = _account_number;
}

void BankAccount::set_name(\
	const std::string& _name)
{
	this->name = _name;
}

void BankAccount::set_credit_grade(\
	const std::string& _grade)
{
	this->credit_grade = _grade;
}

void BankAccount::set_address(\
	const std::string& _address)
{
	this->address = _address;
}
void BankAccount::set_sex(const SEX& sex)
{
	this->sex = sex;
}
// 콘솔에서 입출력 하기 위한 문자한개를 받게 하는 함수들이 필요함
#include <conio.h>
void BankAccount::input_password()
{
	int size{ 0 };
	char ch{ '\0' }; 
	while ((ch = _getch()) != '\r')
	{
		std::cout << "*"; // 화면에 별이 출력
		this->password[size++] = ch;
	}
	std::cout << std::endl;
	this->password[size] = '\0';
	//std::cout << password << std::endl; // 주석처리
}

double BankAccount::check_balance() const {
	return this->balance;
}

void BankAccount::set_blance(const double money) {
	this->balance += money;
	if (static_cast<uint32_t>(this->check_balance()) >= 100'000'000)
	{
		this->credit_grade = "Platinum";
	}
	else if (static_cast<uint32_t>(this->check_balance()) >= 50'000'000)
	{
		this->credit_grade = "Gold";
	} 
	else if (static_cast<uint32_t>(this->check_balance()) >= 10'000'000)
	{
		this->credit_grade = "Silver";
	}
	else {
		this->credit_grade = "Bronze";
	}
}

double BankAccount::get_blance(const double money) {
	if (this->check_balance() <= 0)
	{
		std::cout << "잔액 부족" << std::endl;
		return this->balance;
	}
	this->balance -= money;
	if (static_cast<uint32_t>(this->check_balance()) >= 100'000'000)
	{
		this->credit_grade = "Platinum";
	}
	else if (static_cast<uint32_t>(this->check_balance()) >= 50'000'000)
	{
		this->credit_grade = "Gold";
	}
	else if (static_cast<uint32_t>(this->check_balance()) >= 10'000'000)
	{
		this->credit_grade = "Silver";
	}
	else {
		this->credit_grade = "Bronze";
	}
	return this->balance;
}
bool BankAccount::check_password(const std::string& password)
{
	const char* string_to_char{ password.c_str() };
	if (!strcmp(this->password, string_to_char)) return true;
	return false;
}