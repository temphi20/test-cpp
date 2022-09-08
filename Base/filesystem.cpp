#pragma once
#include "base.h"
#include "filesystem.h"

/*namespace tmphi
{
	class filesystem::impl
	{
	public:
		impl() {}
		~impl() {}
	
	public:
		tmphi::array<std::fstream> m_files;
		tmphi::array<std::string> m_paths;
	};

	filesystem::filesystem() : pimpl(std::make_unique<impl>())
	{}
	filesystem::~filesystem()
	{}

	std::string filesystem::getCurrentPath() { return std::filesystem::current_path().string(); }


	void filesystem::open(std::string path)
	{
		if (!pimpl->m_paths.isExist(path))
		{
			pimpl->m_files.push(std::fstream(path));
			pimpl->m_paths.push(path);
		}
		
	}
	void filesystem::open(std::span<std::string> path)
	{
		array<std::fstream> files;
		for (size_t i = 0; i < path.size(); i++)
		{
			files.push(std::fstream(path[i]));
		}
		pimpl->m_files.push(files);
		pimpl->m_paths.push(path);
		pimpl->m_files.toSet();
	}

	void filesystem::close(std::string path)
	{

	}
	void filesystem::close(std::span<std::string> path)
	{}
}*/