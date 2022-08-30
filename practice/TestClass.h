#pragma once
#include <iostream>
#include <vector>
#include <memory>

namespace ex {
	template <typename T>
	class TestClass
	{
	public:
		TestClass();
		TestClass(const TestClass& old);
		~TestClass();

		inline std::vector<T> Get() { return m_vector; }
		
		void Push(T value, int index = -1);
		void Push(std::vector<T> values);

		void Pop();
		void Pop(T value);
		void Pop(int index);
		void Pop(std::vector<T> values);

		int Find(T value);
		T At(int index);

		virtual void Set(){}
		void Reset();

		
		T Average();
		T Variance();
		T StandardDeviation();

		inline TestClass operator +(TestClass& other) {
			TestClass tmp;
			tmp.Push(m_vector);
			tmp.Push(other.Get());

			return tmp;
		}
		inline TestClass operator +(const TestClass& other) {
			TestClass tmp;
			tmp.Push(m_vector);
			tmp.Push(other.m_vector);
			return tmp;
		}
		inline TestClass operator +(T value) {
			TestClass tmp;
			tmp.Push(m_vector);
			tmp.Push(value);
			return tmp;
		}
		inline TestClass operator -(TestClass& other) {
			TestClass tmp;
			tmp.Push(m_vector);

			for (auto iter = m_vector.begin(); iter != m_vector.end(); iter++)
			{
				int index = Find(*iter);
				if (index > -1) tmp.Pop(*iter);
			}

			return tmp;
		}

		inline TestClass& operator+=(const TestClass& other) {
			Push(other.m_vector);
			return *this;
		}
		inline TestClass& operator+=(double value) {
			Push(value);
			return *this;
		}
		inline TestClass& operator-=(const TestClass& other) {
			Pop(other.m_vector);
			return *this;
		}
		inline TestClass& operator-=(double value) {
			Pop(value);
			return *this;
		}

		inline TestClass& operator=(const TestClass& other) {
			Reset();
			Push(other.m_vector);
			return *this;
		}

	protected:
	private:
		std::vector<T> m_vector;

		inline std::vector<T>::iterator _At(int index) {
			if (idx >= 0 && idx < m_vector.size()) {
				return m_vector.end();
			}
			return m_vector.begin() + idx - 1;
		}
	};
}
