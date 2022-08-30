#pragma once
#include <iostream>
//#include <chrono>
//#include <iomanip>
#include <random>
#include <cstring>

namespace BankImpl {
	enum Kind
	{
		deposit = 1,
		withdraw = -1
	};

	/*class History
	{
	public:
		History() {}
		~History() {}
		void Print();

	private:
		unsigned int money;
		time_t time;
		Kind kind;
		char* memo;
	};*/

	class Account
	{
	public:
		Account(char*, char*);
		~Account();

		void Deposit(unsigned int money, char* recv, char* send = nullptr);
		void Withdraw(unsigned int money, char* password);
		void GetBalance(char* password);
		void PrintHistories();

	private:
		int ACCOUNT_NUMBER_COUNT = 13;
		char* client;
		char* account_number;
		char* password;

		//History* histories;
	};
}