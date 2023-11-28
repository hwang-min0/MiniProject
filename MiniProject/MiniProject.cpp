// MiniProject.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

//#include <iostream>
//#include "BankAccount.h"
#include "BankAccountControl.h"
int main()
{
    /*BankAccount bank1\
    = BankAccount({ "10920-1093", "KarL", "Chengju", MALE });

    bank1.input_password();*/

    BankAccountControl bank_control;
    size_t account_size{ 0u };
    std::cout << "몇개의 계정을 만들건가요?  ";
    std::cin >> account_size;
    if (account_size <= 0) return 1;
    BankAccount::set_indexer(account_size);
    for (int i = 0; i < account_size; ++i)
    {
        BankAccount bank = BankAccount();
        bank_control.input_account_bank(bank);
        bank_control.add_account_bank(bank);
    }
    while (true)
    {
        bank_control.search_account_bank();
    }
    return int{ 0 }; //임시생성자를 통한 임시객체
}
