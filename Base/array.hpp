#pragma once
#include "base.h"

namespace tmphi
{
	template<typename T>
	class array
	{
	public:
		array() : m_data(new T), m_size(0) {}
		array(const size_t size, const T value = 0) : m_data(new T[size]), m_size(size)
		{
			initialize(value);
		}
		array(const array<T>& other)
		{
			copyTo(other.m_data, other.size());
		}
		array(const std::span<T>& data)
		{
			copyTo(data.data(), data.size());
		}
		array(const T* data, const size_t size)
		{
			copyTo(data, size);
		}
		~array() { clear(); }

		void* get() const { return (void*)m_data; }
		void initialize(const T value) { std::fill(m_data, m_data + m_size, value); }
		void clear()
		{
			if (m_size)
			{
				delete[] m_data;
				m_size = 0;
			}
		}

		void copyTo(const array<T>& other) { copyTo(other.m_data, other.size()); }
		void copyTo(const std::span<T>& data) { copyTo(data.data(), data.size()); }
		void copyTo(const T* data, const size_t size)
		{
			clear();
			m_data = new T[size];
			m_size = size;
			std::memcpy(m_data, data, size * sizeof(T));
		}

		void add(const T& value)
		{
			resize(m_size + 1);
			m_data[m_size - 1] = value;
		}
		void add(const array<T>& other) { add(other.m_data, other.size()); }
		void add(const std::span<T>& data) { add(data.data(), data.size()); }
		void add(const T* data, const size_t size)
		{
			const size_t oldSize = m_size;
			resize(m_size + size);
			std::memcpy(&m_data[oldSize], data, size * sizeof(T));
		}

		size_t byteSize() const { return sizeof(T); }
		size_t size() const { return m_size; }
		void resize(const size_t newSize)
		{
			T* newData = new T[newSize];
			const size_t minSize = std::min(m_size, newSize);
			std::memcpy(newData, m_data, minSize * sizeof(T));
			clear();

			m_size = newSize;
			m_data = newData;
		}
		bool isEmpty() const { return m_size == 0; }
		bool isExist(const T element) const
		{
			std::cout << size() << std::endl;
			for (size_t i = 0; i < m_size; i++)
			{
				/*uint s = sizeof(T) / 4;
				uint* tmp1 = new uint[s], * tmp2 = new uint[s];
				std::memcpy(tmp1, &m_data[i], sizeof(T));
				std::memcpy(tmp2, &element, sizeof(T));
				for (size_t j = 0; j < s; j++)
				{
					printf("%02x", tmp1[j]);
				}
				printf("\n");
				for (size_t j = 0; j < s; j++)
				{
					printf("%02x", tmp2[j]);
				}
				printf("\n");*/

				//std::cout << sizeof(T) << std::endl;
				//printf("[%d] %02x(%02x) / %02x(%02x)\n", i, m_data[i], &m_data[i], element, &element);
				if (std::memcmp(&m_data[i], &element, sizeof(T)) == 0) return true;
				//delete[] tmp1, tmp2;
				//if (m_data[i] == element) return true;
			}
			return false;
		}

		void makeSet()
		{
			array<T> set;
			for (size_t i = 0; i < m_size; i++)
			{
				byte* tmp = new byte[sizeof(T)];
				std::memcpy(tmp, &m_data[i], sizeof(T));
				for (size_t j = 0; j < sizeof(T); j++)
				{
					printf("%03d ", tmp[j]);
					//std::cout << (int)tmp[j] << " ";
				}
				std::cout << std::endl;
				/*for (size_t j = 0; j < sizeof(T); j++)
				{
					printf("%02x ", tmp[j]);
				}
				printf("\n");*/
				delete[] tmp;
				//printf("[%d] %02x\n", i, m_data[i]);
				if (!set.isExist(m_data[i])) set.add(m_data[i]);
			}
			
			clear();
			m_size = set.size();
			m_data = new T[set.size()];
			std::memcpy(m_data, set.m_data, m_size * sizeof(T));
		}

		T first() const { return m_data[0]; }
		T last() const { return m_data[m_size - 1]; }

		void ascend() { std::sort(m_data, m_data + m_size, [](T pre, T cur) { return pre < cur; }); }
		void descend() { std::sort(m_data, m_data + m_size, [](T pre, T cur) { return pre > cur; }); }

	public:
		T sum() const
		{
			T sum = m_data[0];
			for (size_t i = 1; i < m_size; i++) sum += m_data[i];
			return sum;
		}

		T average() const
		{
			if (isEmpty()) return 0;
			return sum() / m_size;
		}

		T variance()
		{
			if (isEmpty()) return 0;

			T avg = average(), sum = 0;
			for (size_t i = 0; i < m_size; i++)
			{
				T cal = m_data[i] - avg;
				sum += cal * cal;
			}
			return sum / m_size;
		}

		T standardDeviation() { return static_cast<T>(sqrt(static_cast<double>(variance()))); }

		T min() const { return *std::min_element(m_data, m_data + m_size); }
		T max() const { return *std::max_element(m_data, m_data + m_size); }

	public:
		T& operator[](const size_t index) const { return m_data[index]; }

		array<T> operator+(const array<T>& other)
		{
			array<T> newArr(*this);
			newArr.add(other);
			return newArr;
		}
		array<T> operator+(const std::span<T>& data)
		{
			array<T> newArr(*this);
			newArr.add(data);
			return newArr;
		}

	private:
		T* m_data;
		size_t m_size;
	};
}
