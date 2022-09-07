#pragma once
#include "base.h"

namespace tmphi
{
	class timer
	{
	public:
		timer();
		~timer();

		void start();
		void stop();

		void print(const std::wstring label = L"") const;

	private:
		class impl;
		std::unique_ptr<impl> pimpl;
	};
}