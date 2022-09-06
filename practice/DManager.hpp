#pragma once
#include <iostream>
#include <span>
#include <vector>
#include <memory>

namespace tmphi
{
	template <typename T>
	class DManager
	{
	public:
		DManager(){}
		DManager(const DManager<T>& ref) { push(ref); }
		~DManager() { reset(); }

	public:
		inline std::vector<T>& get() { return m_list; }
		
		void push(T value, int index = -1)
		{
			if (index >= 0 && index < m_list.size()) m_list.insert(getIter(index), value);
			else m_list.push_back(value);
		}
		void push(std::span<T>& values)
		{
			size_t start = m_list.size();
			m_list.resize(start + size);
			T* ptr = &m_list[start];
			std::memcpy(ptr, values.data(), sizeof(T) * size);
		}
		void push(T* values, size_t size)
		{
			size_t start = m_list.size();
			m_list.resize(start + size);
			T* ptr = &m_list[start];
			std::memcpy(ptr, values, sizeof(T) *size);
		}
		void push(const DManager<T>& other) { push(other.m_list); }

		void pop() { m_list.push_back(); }
		void pop(T value)
		{
			auto tmp = std::find(m_list.begin(), m_list.end(), value);
			if (tmp == m_list.end()) return;

			m_list.erase(tmp);
		}
		void pop(int index)
		{
			if (index < 0 || m_list.size() <= index) return;
			m_list.erase(index);
		}
		void pop(std::span<T> values);

		int find(T value)
		{
			int index = 0;
			for (auto iter = m_list.begin(); iter != m_list.end(); iter++, index++)
			{
				if (*iter == value) return index;
			}
			return -1;
		}

		size_t size() { return m_list.size(); }

		virtual void set(){}
		void reset()
		{
			std::vector<T> init;
			m_list.swap(init);
		}

		
		T average()
		{
			if (m_list.empty()) return 0;

			double sum = 0;
			for (auto iter = m_list.begin(); iter != m_list.end(); iter++)
			{
				sum += *iter;
			}

			return sum / m_list.size();
		}
		T variance()
		{
			double avg = average(), sum = 0;
			for (auto iter = m_list.begin(); iter != m_list.end(); iter++)
			{
				sum += std::pow(*iter - avg, 2);
			}

			return sum / m_list.size();
		}
		T standardDeviation() { return sqrt(static_cast<double>(variance())); }

	public:
		T& operator[](int index) { return m_list[index]; }

		DManager operator +(DManager& other)
		{
			DManager ret;
			ret.push(m_list);
			ret.push(other);
			return ret;
		}
		DManager operator +(const DManager& other)
		{
			DManager ret;
			ret.push(m_list);
			ret.push(other);
			return ret;
		}
		DManager operator +(T value)
		{
			DManager ret;
			ret.push(m_list);
			ret.push(value);
			return ret;
		}
		DManager operator -(DManager& other)
		{
			DManager ret;
			ret.push(m_list);

			for (auto iter = m_list.begin(); iter != m_list.end(); iter++)
			{
				int index = find(*iter);
				if (index > -1) ret.pop(*iter);
			}
			return ret;
		}

		DManager& operator+=(const DManager<T>& other)
		{
			push(other);
			return *this;
		}
		DManager& operator+=(const T& value)
		{
			push(value);
			return *this;
		}
		DManager& operator-=(const DManager<T>& other)
		{
			pop(other.m_list);
			return *this;
		}
		DManager& operator-=(const T& value)
		{
			pop(value);
			return *this;
		}

		DManager& operator=(const DManager<T>& other)
		{
			reset();
			push(other);
			return *this;
		}

	protected:
	private:
		std::vector<T> m_list;

		inline std::vector<T>::iterator getIter(int index) { return m_list.begin() + index - 1; }
	};
}
