#pragma once
#include <iostream>
#include <span>
#include <vector>

namespace Ex
{
	using byte = unsigned char;

	template <typename T>
	class TT
	{
	public:
		TT(const std::span<T> data)
		{
			setData(data);
		}
		void setData(const std::span<T> data)
		{
			std::vector<byte> bData;
			for (auto iter = data.begin(); iter < data.end(); iter++)
			{
				bData.push_back((byte)*iter);
			}
			this->data = bData;
			//this->data = convByteData(data);
		}

		static std::span<byte> convByteData(const std::span<T> data)
		{
			std::vector<byte> bData;
			for (auto iter = data.begin(); iter < data.end(); iter++)
			{
				bData.push_back((byte)*iter);
			}
			return std::span<byte>(bData);
		}

		T getTData(int idx = 0) { return (T)data[idx]; }
	public:
		byte& operator[](int idx){ return data[idx]; }
	private:
		std::span<byte> data;
	};
}
