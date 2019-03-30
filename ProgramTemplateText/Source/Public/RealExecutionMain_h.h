#ifndef REALEXECUTIONMAIN_H__
#define REALEXECUTIONMAIN_H__

#include "../../../BaseProgramFile.h"

const char* REAL_EXECTION_MAINFILE_NAME=R"(RealExecutionMain.h)";
const char* REAL_EXECTION_MAIN_PATH=R"(\\Source\\Public)";
const char* REAL_EXECTION_MAIN_H=R"(
# pragma once

#include "ProgramTemplate.h"

#include "LaunchEngineLoop.h"
#include "StandaloneRenderer.h"
#include "Framework/Application/SlateApplication.h"
#include "CoreMinimal.h"
#include <iostream>

int RealExecutionMain(const TCHAR* pCmdLine);

)";

class FileRealExecutionMain_h:public BaseProgramFile
{
public:
	virtual void Init(const std::string& pProgramName)override
	{
		BaseProgramFile::Init(pProgramName);
		file_name=REAL_EXECTION_MAINFILE_NAME;
		file_path=ProgramName+REAL_EXECTION_MAIN_PATH;
		file_content=REAL_EXECTION_MAIN_H;
		
	}
};

FileRealExecutionMain_h RealExecutionMain_h=FileRealExecutionMain_h();
#endif