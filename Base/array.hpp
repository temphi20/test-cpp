#pragma once
#include "base.h"

namespace tmphi
{
	template<typename T>
	class array
	{
	public:
		array() : m_data(new T), m_size(0) {}
		array(const size_t size, const T init = 0) : m_data(new T[size]), m_size(size)
		{
			if(init != 0) std::memset(m_data, static_cast<int>(init), size);
		}
		array(const array<T>& other)
		{
			copyTo(other);
		}
		array(const std::span<T>& data)
		{
			copyTo(data);
		}
		~array() { clear(); }

		void* get() const { return (void*)m_data; }
		void clear()
		{
			delete[] m_data;
			m_size = 0;
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

		T first() const { return m_data[0]; }
		T last() const { return m_data[m_size - 1]; }

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
