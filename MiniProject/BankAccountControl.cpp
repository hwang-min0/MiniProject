#include "BankAccountControl.h"
void BankAccountControl::add_account_bank(const BankAccount& bank)
{
	this->_vec.push_back(bank);
}

void BankAccountControl::input_account_bank(BankAccount& bank_account)
{
	// �����͸� �Է¹ޱ� ���� �ӽ� string ����
	std::string buffer;
	std::cout << "���¹�ȣ �Է� :  ";
	std::cin >> buffer;
	bank_account.set_account_number(buffer);
	std::cout << "�̸� �Է� :  ";
	std::cin >> buffer;
	bank_account.set_name(buffer);
	std::cout << "���� �Է� : F(0) / M(1)   ";
	int _sex{ 0 };
	std::cin >> _sex;
	bank_account.set_sex(static_cast<SEX>(_sex));
	std::cout << "��ȣ �Է� : ";
	bank_account.input_password();
}

void BankAccountControl::search_account_bank()
{
	std::cout << "0 - Account number, 1 - Account name, 2 - Account address, 3 - Account credit , 4 - Deoposit, 5 - Withdraw !!" << std::endl;
	int menu_number;
	std::cin >> menu_number;
	std::vector<BankAccount>::iterator ptr_iter{ this->_vec.begin() };
	while (ptr_iter != _vec.end())
	{
		switch (static_cast<MENU>(menu_number))
		{
		case ACCOUNT_NUMBER:
			std::cout << ptr_iter->get_account_number() << std::endl;
			break;
		case ACCOUNT_NAME:
			std::cout << ptr_iter->get_name() << std::endl;
			break;
		case ACCOUNT_ADDRESS:
			std::cout << ptr_iter->get_address() << std::endl;
			break;
		ss
		case ACCOUNT_WITHDRAW:
			this->withdraw();
			return;
		default:
			std::cout << "���� �޴�����" << std::endl;
		}
		++ptr_iter;
		std::cout << "-------------------------" << std::endl;
	}
}
#include <conio.h>
void BankAccountControl::deposit() {
	std::vector<BankAccount>::iterator ptr_iter{ this->_vec.begin() };
	std::string buffer;
	std::cout << "���� ��ȣ�� �Է����ּ���.  ";
	std::cin >> buffer;
	char password[BUFSIZ]{ '\0' };
	int size{ 0 };
	char ch{ '\0' };
	while (ptr_iter != _vec.end())
	{
		const std::string customer_account_number { ptr_iter->get_account_number() };
		if (buffer == customer_account_number) {
			do
			{
				std::cout << "�н����带 �Է����ּ���.  ";
				while ((ch = _getch()) != '\r')
				{
					std::cout << "*"; // ȭ�鿡 ���� ���
					password[size++] = ch;
				}
				std::cout << std::endl;
				password[size] = '\0'; // 3��üũ
			} while (!ptr_iter->check_password(password));
			std::cout << "�Ա��� �ݾ��� �Է����ּ���.  ";
			double _money;
			std::cin >> _money;
			while (_money <= 0) {
				std::cout << "�� �� �Է��߽��ϴ�." << std::endl;
				std::cout << "�Ա��� �ݾ��� �Է����ּ���.  ";
				std::cin >> _money;
			}
			ptr_iter->set_blance(_money);
			break;
		}
		++ptr_iter;
	}
}

void BankAccountControl::withdraw() 
{
	std::vector<BankAccount>::iterator ptr_iter{ this->_vec.begin() };
	std::string buffer;
	std::cout << "���� ��ȣ�� �Է����ּ���.  ";
	std::cin >> buffer;
	char password[BUFSIZ]{ '\0' };
	int size{ 0 };
	char ch{ '\0' };
	while (ptr_iter != _vec.end())
	{
		const std::string customer_account_number{ ptr_iter->get_account_number() };
		if (buffer == customer_account_number) {
			do
			{
				std::cout << "�н����带 �Է����ּ���.  ";
				while ((ch = _getch()) != '\r')
				{
					std::cout << "*"; // ȭ�鿡 ���� ���
					password[size++] = ch;
				}
				std::cout << std::endl;
				password[size] = '\0'; // 3��üũ
			} while (!ptr_iter->check_password(password));
			std::cout << "ã�� �ݾ��� �Է����ּ���.  ";
			double _money;
			std::cin >> _money;
			while (_money <= 0) {
				std::cout << "�� �� �Է��߽��ϴ�." << std::endl;
				std::cout << "ã�� �ݾ��� �Է����ּ���.  ";
				std::cin >> _money;
			}
			ptr_iter->get_blance(_money);
			break;
		}
		++ptr_iter;
	}

}