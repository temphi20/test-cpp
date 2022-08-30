#include "CTest.h"

int ex::CTest::m_callNumber = 0;

ex::CTest::CTest() {
	m_callNumber++;
	std::cout << "Construct" << std::endl;
}

ex::CTest::CTest(std::string name) {
	m_callNumber++;
	m_name = name;
	std::cout << "Construct " << m_name << std::endl;
}

ex::CTest::~CTest() {
	m_callNumber--;
	std::cout << "Distruct " << m_name << std::endl;
}

void ex::CTest::Set() {
	ex::TestClass::Set();
}