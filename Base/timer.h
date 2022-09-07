#pragma once
#include "include.h"

namespace tmphi
{
	using namespace boost::chrono;
	class timer
	{
	public:
		timer() {}
		~timer() {}

		void start() { m_start = steady_clock::now(); }
		void stop() { m_end = steady_clock::now(); }
		void print(std::string label = "")
		{
			if (label.length()) std::cout << "[" << label << "] ";
			std::cout << m_end - m_start << std::endl;
		}

	private:
		steady_clock::time_point m_start;
		steady_clock::time_point m_end;
	};
}