#ifndef PROGRAMTEMPLATE_PULL_BINARIES_BAT_H__
#define PROGRAMTEMPLATE_PULL_BINARIES_BAT_H__
// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "../BaseProgramFile.h"

const char* PROGRAM_TEMPLATE_PULL_BINARIES_BAT_PATH=R"(\\)";
const char* PROGRAM_TEMPLATE_PULL_BINARIES_BAT_FILE_NAME=R"(.bat)";
const char* PROGRAM_TEMPLATE_PULL_BINARIES_BAT=R"(@echo off
set PROJECT_NAME=ProgramTemplate
md %PROJECT_NAME%\\Engine\\Binaries\\Win64
md %PROJECT_NAME%\\Engine\\Content\\Internationalization\\icudt53l
md %PROJECT_NAME%\\Engine\\Content\\Slate 
md %PROJECT_NAME%\\Engine\\Shaders\\StandaloneRenderer
copy ..\\..\\..\\Binaries\\Win64\\%PROJECT_NAME%.exe %PROJECT_NAME%\\Engine\\Binaries\\Win64
copy Register.reg %PROJECT_NAME%\\
xcopy /y/i/s/e ..\\..\\..\\Content\\Internationalization\\English\\icudt53l %PROJECT_NAME%\\Engine\\Content\\Internationalization\\icudt53l
xcopy /y/i/s/e ..\\..\\..\\Content\\Slate %PROJECT_NAME%\\Engine\\Content\\Slate
xcopy /y/i/s/e ..\\..\\..\\Shaders\\StandaloneRenderer %PROJECT_NAME%\\Engine\\Shaders\\StandaloneRenderer
copy Resources\\icon.ico %PROJECT_NAME%\\Engine\\Content\\Slate\\Icons
echo "Engine\\Binaries\\Win64\\%PROJECT_NAME%.exe">%PROJECT_NAME%\\%PROJECT_NAME%.bat
)";


class PULL_BINARIES_BAT_file:public BaseProgramFile
{
public:
	virtual void Init(const std::string& pProgramName)override
	{
		BaseProgramFile::Init(pProgramName);
		file_content=PROGRAM_TEMPLATE_PULL_BINARIES_BAT;
		file_path=ProgramName+PROGRAM_TEMPLATE_PULL_BINARIES_BAT_PATH;
		file_name=std::string("PullBinaries")+PROGRAM_TEMPLATE_PULL_BINARIES_BAT_FILE_NAME;
		
	}
};

PULL_BINARIES_BAT_file PULL_BINARIES_BAT=PULL_BINARIES_BAT_file();

#endif