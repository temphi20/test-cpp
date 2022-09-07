#pragma once
#include "timer.h"

namespace tmphi
{
	using namespace boost::chrono;
	class timer::impl
	{
	public:
		impl() {}
		~impl() {}

	public:
		steady_clock::time_point m_start;
		steady_clock::time_point m_end;
	};

	timer::timer() : pimpl(std::make_unique<impl>()) {}
	timer::~timer() {}

	void timer::start() { pimpl->m_start = steady_clock::now(); }
	void timer::stop() { pimpl->m_end = steady_clock::now(); }

	void timer::print(const std::wstring label) const
	{
		if (label.length()) std::wcout << "[" << label << "] ";
		std::wcout << pimpl->m_end - pimpl->m_start << std::endl;
	}
}