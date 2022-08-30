#pragma once
#include "TestClass.h"

namespace ex {
	class CTest : public TestClass
	{
	public:
		CTest();
		CTest(std::string name);
		~CTest();

		static int m_callNumber;
		void Set();
		/*CTest operator +(TestClass& other);
		CTest operator +(double value);
		CTest operator -(TestClass& other);

		CTest& operator+=(const TestClass& other);
		CTest& operator+=(double value);
		CTest& operator-=(const TestClass& other);
		CTest& operator-=(double value);

		CTest& operator=(const TestClass& other);*/
	private:
		std::string m_name;
	};
}


