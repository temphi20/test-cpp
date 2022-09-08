#pragma once
#include "base.h"

namespace tmphi
{
	template <typename T>
	class list
	{
	public:
		list() {}
		list(const list<T>& ref) { push(ref); }
		~list() { reset(); }

	public:
		T* ptr(const size_t index = 0) const { return (T*)&m_list[index]; }
		T value(const size_t index = 0) const { return m_list[index]; }
		size_t index(const T value = 0) const
		{
			size_t index = 0;
			for (auto iter = m_list.begin(); iter != m_list.end(); iter++, index++)
			{
				if (*iter == value) return index;
			}
			return -1;
		}
		list<size_t> indexs(const T value = 0) const
		{
			list<size_t> arr;
			size_t index = 0;
			for (auto iter = m_list.begin(); iter != m_list.end(); iter++, index++)
			{
				if (*iter == value) arr.push(index);
			}
			return arr;
		}

		size_t size() const { return m_list.size(); }


	public:
		void assign(const list<T>& values)
		{
			m_list.resize(values.size());
			std::memcpy(ptr(), values.ptr(), sizeof(T) * size);
		}
		void assign(const std::span<T>& values)
		{
			m_list.resize(values.size());
			std::memcpy(ptr(), values.data(), sizeof(T) * size);
		}
		void assign(const T* values, const size_t size)
		{
			m_list.resize(size);
			std::memcpy(ptr(), values.data(), sizeof(T) * size);
		}


		void push(const T& value, const size_t index = -1)
		{
			if (index >= 0 && index < m_list.size()) m_list.insert(getIter(index), value);
			else m_list.push_back(value);
		}
		void push(const list<T>& other)
		{
			if (other.size() == 0) return;

			size_t start = m_list.size();
			m_list.resize(start + other.size());
			std::memcpy(ptr(start), other.ptr(), sizeof(T) * other.size());
		}
		void push(const std::span<T>& values)
		{
			if (values.size() == 0) return;

			size_t start = m_list.size();
			m_list.resize(start + values.size());
			std::memcpy(ptr(start), values.data(), sizeof(T) * values.size());
		}
		void push(const T* values, const size_t size)
		{
			if (size == 0) return;

			size_t start = m_list.size();
			m_list.resize(start + size);
			std::memcpy(ptr(start), values, sizeof(T) * size);
		}
		

		void pop() { m_list.pop_back(); }
		void pop(const T& value)
		{
			auto ret = std::find(m_list.begin(), m_list.end(), value);
			if (ret != m_list.end()) m_list.erase(ret);
		}
		void pop(const list<T>& other)
		{
			auto size = other.size();
			if (size == 0) return;

			m_list.erase(std::remove_if(m_list.begin(), m_list.end(),
				[&other, &size](T x)
				{
					for (size_t i = 0; i < size; i++)
						if (other[i] == x)
							return true;
					return false;
				}), m_list.end());
		}
		void pop(const std::span<T>& values)
		{
			auto size = values.size();
			if (size == 0) return;

			m_list.erase(std::remove_if(m_list.begin(), m_list.end(),
				[&values, &size](T x)
				{
					for (size_t i = 0; i < size; i++)
						if (values[i] == x)
							return true;
					return false;
				}), m_list.end());
		}
		void pop(const T* values, const size_t size)
		{
			if (size == 0) return;

			m_list.erase(std::remove_if(m_list.begin(), m_list.end(),
				[&values, &size](T x)
				{
					for (size_t i = 0; i < size; i++)
						if (values[i] == x)
							return true;
					return false;
				}), m_list.end());
		}

		void copyTo(const list<T>& ref)
		{
			assign(ref);
		}

		void reset()
		{
			std::vector<T> init;
			m_list.swap(init);
		}

		bool isExist(const T& element) const { return index(element) >= 0; }
		bool isEmpty() const { return m_list.empty(); }

		void toSet()
		{
			std::vector<size_t> trash;
			for (size_t i = 0; i < size();)
			{
				auto duple = indexs(m_list[i]);
				for (size_t j = 1; j < duple.size(); j++)
				{
					
				}
			}
			
			/*m_list.erase(std::remove_if(m_list.begin(), m_list.end(),
				[&trash](T x, )
				{
					if()
							return true;
					return false;
				}), m_list.end());*/
		}


	public:
		double average()
		{
			if (m_list.empty()) return 0;

			double sum = 0;
			for (auto iter = m_list.begin(); iter != m_list.end(); iter++)
			{
				sum += static_cast<double>(*iter);
			}

			return sum / m_list.size();
		}
		double variance()
		{
			double avg = average(), sum = 0;
			for (auto iter = m_list.begin(); iter != m_list.end(); iter++)
			{
				auto cal = static_cast<double>(*iter) - avg;
				sum += cal * cal;
			}

			return sum / m_list.size();
		}
		double standardDeviation() { return sqrt(static_cast<double>(variance())); }

		T min() const { return *std::min_element(m_list.cbegin(), m_list.cend()); }
		T max() const { return *std::max_element(m_list.cbegin(), m_list.cend()); }

		void ascend() {}
		void descend() {}
		

	public:
		T& operator[](const size_t index) { return m_list[index]; }

		list<T> operator +(const list<T>& other)
		{
			list<T> ret;
			ret.push(m_list);
			ret.push(other);
			return ret;
		}
		list<T> operator +(const T& value)
		{
			list<T> ret;
			ret.push(m_list);
			ret.push(value);
			return ret;
		}
		list<T> operator -(const list<T>& other)
		{
			list<T> ret;
			ret.push(m_list);

			for (auto iter = m_list.begin(); iter != m_list.end(); iter++)
			{
				size_t index = find(*iter);
				if (index > -1) ret.pop(*iter);
			}
			return ret;
		}

		list<T>& operator+=(const list<T>& other)
		{
			push(other);
			return *this;
		}
		list<T>& operator+=(const T& value)
		{
			push(value);
			return *this;
		}
		list<T>& operator-=(const list<T>& other)
		{
			pop(other.m_list);
			return *this;
		}
		list<T>& operator-=(const T& value)
		{
			pop(value);
			return *this;
		}

		list<T>& operator=(const list<T>& other)
		{
			reset();
			push(other);
			return *this;
		}

		bool operator==(const list<T>& other)
		{
			if (size() != other.size()) return false;
			return std::memcmp(ptr(), other.ptr(), size()) == 0;
		}

	protected:
	private:
		std::vector<T> m_list;

		inline std::vector<T>::iterator getIter(const size_t index) { return m_list.begin() + index - 1; }
	};
}
