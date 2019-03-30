#ifndef PROGRAMTEMPLATE_CPP_H__
#define PROGRAMTEMPLATE_CPP_H__

#include "../../../BaseProgramFile.h"

const char* PROGRAMTEMPLATE_CPP_FILE_NAME=R"(.cpp)";
const char* PROGRAMTEMPLATE_CPP_PATH=R"(\\Source\\Private)";
const char* PROGRAMTEMPLATE_CPP_H=R"(

#include "ProgramTemplate.h"
#include "ProgramTemplateLog.h"

DEFINE_LOG_CATEGORY(LogProgramTemplate);

)";


class FileProgramTemplate_cpp:public BaseProgramFile
{
public:
	virtual void Init(const std::string& pProgramName)override
	{
		BaseProgramFile::Init(pProgramName);
		
		file_name=ProgramName+PROGRAMTEMPLATE_CPP_FILE_NAME;
		file_path=ProgramName+PROGRAMTEMPLATE_CPP_PATH;
		file_content=PROGRAMTEMPLATE_CPP_H;
	}
};

FileProgramTemplate_cpp ProgramTemplate_cpp=FileProgramTemplate_cpp();
#endif