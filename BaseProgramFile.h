#ifndef PROGRAMFILE_HPP__
#define PROGRAMFILE_HPP__
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "string_tools.h"

class BaseProgramFile{
public:

	static std::vector<class BaseProgramFile*> file_list;
	// static std::string ProgramName;

	BaseProgramFile();
	virtual void Init(const std::string& pProgramName);
	virtual void WriteToFile();

protected:
	std::string ProgramName;
	std::string file_content;
	std::string file_path;
	std::string file_name;
};

#endif