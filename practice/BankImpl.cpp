#include "BankImpl.h"
using namespace std;
using namespace BankImpl;

Account::Account(char* name, char* pw)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<unsigned short> dis(0, 9);
	size_t len = strlen(name);

	account_number = (char*)calloc(ACCOUNT_NUMBER_COUNT + 1, sizeof(char));
	memcpy(client, name, sizeof(char) * (len + 1));
	memcpy(password, pw, sizeof(char) * 5);
	/*client = (char*)calloc(len + 1, sizeof(char));
	password = (char*)calloc(5, sizeof(char));*/

	if (account_number != NULL) {
		cout << "이름 확인: " << client << endl;
		cout << "비밀번호 확인: " << password << endl;

		for (size_t i = 0; i < ACCOUNT_NUMBER_COUNT; i++)
		{
			account_number[i] = dis(gen) + 48;
		}
		//account_number[ACCOUNT_NUMBER_COUNT] = '\0';
		cout << "생성된 계좌번호 확인: " << account_number << endl;
	}
}

Account::~Account()
{
	free(account_number);
	free(client);
	free(password);
}

void Account::Deposit(unsigned int money, char* recv, char* send) {

}

void Account::Withdraw(unsigned int money, char* password) {

}

void Account::GetBalance(char* password) {

}

void Account::PrintHistories() {

}