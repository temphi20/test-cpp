#pragma once
#include <iostream>
#include <vector>

namespace Ex
{
	template <typename T>
	class ExCal
	{
	public:
		ExCal() {}
		ExCal(const ExCal& old){ Push(old.m_vector); }
		~ExCal() { Reset(); }

		inline std::vector<T> Get() { return m_vector; }

		void Push(T value) { m_vector.push_back(value); }
		void Push(std::vector<T> values)
		{
			for (auto iter = values.begin(); iter != values.end(); iter++)
			{
				m_vector.push_back(*iter);
			}
		}

		void Pop() { m_vector.pop_back(); }
		void Pop(T value)
		{
			auto f = std::find(m_vector, value);
			m_vector.erase(f);
		}
		void Pop(std::vector<T> values)
		{
			for (auto iter = values.begin(); iter != values.end(); iter++)
			{
				int index = Find(*iter);
				if (index > -1) Pop(index);
			}
		}
		void PopIndex(int index)
		{
			if (index < 0 || m_vector.size() <= index) return;

			m_vector.erase(_At(index));
		}

		int Find(T value)
		{
			int index = 0;
			for (auto iter = m_vector.begin(); iter != m_vector.end(); iter++, index++)
			{
				if (*iter == value) return index;
			}

			return -1;
		}

		T At(int index)
		{
			if (index >= 0 && index < m_vector.size()) {
				return *m_vector.end();
			}

			return *(m_vector.begin() + index - 1);
		}

		virtual void Set() {}
		void Reset()
		{
			std::vector<T> init;
			m_vector.swap(init);
		}


		T Average()
		{
			if (m_vector.empty()) return 0;

			double sum = 0;
			for (auto iter = m_vector.begin(); iter != m_vector.end(); iter++)
			{
				sum += *iter;
			}

			return sum / m_vector.size();
		}
		T Variance()
		{
			if (!m_vector.size()) return 0;

			double avg = Average(), sum = 0;
			for (auto iter = m_vector.begin(); iter != m_vector.end(); iter++)
			{
				sum += pow(*iter - avg, 2);
			}

			return sum / m_vector.size();
		}
		T StandardDeviation() { return sqrt(Variance()); }

		void Print() {
			for (auto iter = m_vector.begin(); iter != m_vector.end(); iter++)
			{
				std::cout << *iter << " / ";
			}
			
			std::cout << "/:" << Average() << " / ";
			std::cout << Variance() << " / ";
			std::cout << StandardDeviation();
		}

		/*ExCal operator +(ExCal& other) {
			ExCal tmp;
			tmp.Push(m_vector);
			tmp.Push(other.Get());

			return tmp;
		}
		ExCal operator +(const ExCal& other) {
			ExCal tmp;
			tmp.Push(m_vector);
			tmp.Push(other.m_vector);
			return tmp;
		}
		ExCal operator +(T value) {
			ExCal tmp;
			tmp.Push(m_vector);
			tmp.Push(value);
			return tmp;
		}
		ExCal operator -(ExCal& other) {
			ExCal tmp;
			tmp.Push(m_vector);

			for (auto iter = m_vector.begin(); iter != m_vector.end(); iter++)
			{
				if (Find(*iter) > -1) tmp.Pop(*iter);
			}

			return tmp;
		}

		ExCal& operator+=(const ExCal& other) {
			Push(other.m_vector);
			return *this;
		}
		ExCal& operator+=(T value) {
			Push(value);
			return *this;
		}
		ExCal& operator-=(const ExCal& other) {
			Pop(other.m_vector);
			return *this;
		}
		ExCal& operator-=(T value) {
			Pop(value);
			return *this;
		}

		ExCal& operator=(const ExCal& other) {
			Reset();
			Push(other.m_vector);
			return *this;
		}*/

	protected:
	private:
		std::vector<T> m_vector;

		inline std::vector<T>::iterator _At(int index) {
			if (index >= 0 && index < m_vector.size()) {
				return m_vector.end();
			}
			return m_vector.begin() + index - 1;
		}
	};
}


