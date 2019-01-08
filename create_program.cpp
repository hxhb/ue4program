#include <iostream>
#include <vector>
#include <string>
#include "BaseProgramFile.h"

std::vector<class BaseProgramFile*> BaseProgramFile::file_list;

#include "ProgramTemplateText/ProgramTemplate_Target_cs.h"
#include "ProgramTemplateText/ProgramTemplate_Build_cs.h"
#include "ProgramTemplateText/GenerateProgramProject_bat.h"
#include "ProgramTemplateText/OpenProgramProject_bat.h"
#include "ProgramTemplateText/Source/Public/ProgramTemplate_h.h"
#include "ProgramTemplateText/Source/Public/ProgramTemplateLog_h.h"
#include "ProgramTemplateText/Source/Public/RealExecutionMain_h.h"
#include "ProgramTemplateText/Source/Private/ProgramTemplate_cpp.h"
#include "ProgramTemplateText/Source/Private/RealExecutionMain_cpp.h"
#include "ProgramTemplateText/Source/Private/Windows/WindowsMain_cpp.h"
#include "ProgramTemplateText/Source/Private/Console/ConsoleMain_cpp.h"

using namespace std;

int main(int argc,char* argv[])
{
	if(argc<2){
		std::cout<<"Usage:\n\t"<<"create_program.exe ProgramName"<<std::endl;
		return -1;
	}

	std::string ProgramName=std::string(argv[1]);

	for(auto& index:BaseProgramFile::file_list)
	{
		index->Init(ProgramName);
		index->WriteToFile();
	}
	std::cout<<"Create Standalone Program Successed!"<<std::endl;
	return 0;
}