#pragma once
#include "base.h"

namespace tmphi
{
	class filesystem
	{
	public:
		filesystem();
		~filesystem();

	public:
		static std::string getCurrentPath();
		
	public:
		void open(std::string path);
		void open(std::span<std::string> path);
		
		void close(std::string path);
		void close(std::span<std::string> path);

	private:
		class impl;
		std::unique_ptr<impl> pimpl;
	};
}
