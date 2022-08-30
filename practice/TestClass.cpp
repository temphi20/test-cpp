#include "TestClass.h"
using namespace ex;

template <typename T>
TestClass<T>::TestClass(){
	
}
template <typename T>
TestClass<T>::TestClass(const TestClass& old) {
	Push(old.m_vector);
}
template <typename T>
TestClass<T>::~TestClass(){
	Reset();
}

template <typename T>
void TestClass<T>::Push(T value, int index){
	if (index >= 0 && index < m_vector.size()) {
		m_vector.insert(_At(index), value);
	}
	else {
		m_vector.push_back(value);
	}
}

template <typename T>
void TestClass<T>::Push(std::vector<T> values) {
	for (auto iter = values.begin(); iter != values.end(); iter++)
	{
		m_vector.push_back(*iter);
	}
}

template <typename T>
void TestClass<T>::Pop() {
	m_vector.pop_back();
}
template <typename T>
void TestClass<T>::Pop(T value) {
	auto tmp = std::find(m_vector.begin(), m_vector.end(), value);
	if (tmp == m_vector.end()) return;

	m_vector.erase(tmp);
}

template <typename T>
void TestClass<T>::Pop(int index) {
	if (index < 0 || m_vector.size() <= index) return;
	
	m_vector.erase(_At(index));
}

template <typename T>
void TestClass<T>::Pop(std::vector<T> values) {
	for (auto iter = values.begin(); iter != values.end(); iter++)
	{
		int index = Find(*iter);
		if (index > -1) Pop(index);
	}
}

template <typename T>
T TestClass<T>::At(int idx) {
	if (idx >= 0 && idx < m_vector.size()) {
		return *m_vector.end();
	}

	return *(m_vector.begin() + idx - 1);
}

template <typename T>
int TestClass<T>::Find(T value) {
	int index = 0;
	for (auto iter = m_vector.begin(); iter != m_vector.end(); iter++, index++)
	{
		if (*iter == value) return index;
	}

	return -1;
}

template <typename T>
void TestClass<T>::Reset() {
	std::vector<T> init;
	m_vector.swap(init);
}

template <typename T>
T TestClass<T>::Average() {
	if (m_vector.empty()) return 0;

	double sum = 0;
	for (auto iter = m_vector.begin(); iter != m_vector.end(); iter++)
	{
		sum += *iter;
	}

	return sum / m_vector.size();
}

template <typename T>
T TestClass<T>::Variance() {
	double avg = Average(), sum = 0;
	for (auto iter = m_vector.begin(); iter != m_vector.end(); iter++)
	{
		sum += pow(*iter - avg, 2);
	}

	return sum / m_vector.size();
}

template <typename T>
T TestClass<T>::StandardDeviation() {
	return sqrt(Variance());
}