#ifndef STRING_TOOLS___
#define STRING_TOOLS___
#include <vector>
#include <string>
#include <iostream>
#include <direct.h>

namespace StringTools{
	void create_recursion_dir(const std::string& basepath,const std::string& rela_path);
	std::string replace_substring(const std::string& file,const std::string& replace_src,const std::string& replace_target);
}

#endif