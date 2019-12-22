#ifndef WINDOWSMAIN_CPP_H__
#define WINDOWSMAIN_CPP_H__

#include "../../../../BaseProgramFile.h"

const char* WINDOWSMAIN_CPP_H_FILE_NAME=R"(WindowsMain.cpp)";
const char* WINDOWSMAIN_CPP_H_PATH=R"(\\Source\\Private\\Windows)";
const char* WINDOWSMAIN_CPP_H=R"(
// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "RealExecutionMain.h"
#include <windows.h>

int WinMain(
	_In_ HINSTANCE InhInstance,
	_In_opt_ HINSTANCE InhPrevInstance,
	_In_ LPSTR InlpCmdLine,
	_In_ int InShowCmd
)
{
	int resault=RealExecutionMain(GetCommandLineW());

	return resault;
}
)";


class FileWindowsMain_cpp:public BaseProgramFile
{
public:
	virtual void Init(const std::string& pProgramName)override
	{
		BaseProgramFile::Init(pProgramName);
		
		file_name=WINDOWSMAIN_CPP_H_FILE_NAME;
		file_path=ProgramName+WINDOWSMAIN_CPP_H_PATH;
		file_content=WINDOWSMAIN_CPP_H;
	}
};

FileWindowsMain_cpp WindowsMain_cpp=FileWindowsMain_cpp();

#endif