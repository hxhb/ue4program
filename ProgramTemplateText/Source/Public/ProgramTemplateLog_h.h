#ifndef PROGRAMTEMPLATELOG_H__
#define PROGRAMTEMPLATELOG_H__

#include "../../../BaseProgramFile.h"

const char* PROGRAMTEMPLATELOG_NAME=R"(Log.h)";
const char* PROGRAMTEMPLATELOG_PATH=R"(\\Source\\Public)";
const char* PROGRAMTEMPLATELOG_H=R"(
// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

DECLARE_LOG_CATEGORY_EXTERN(LogProgramTemplate, Verbose, All);
)";


class FileProgramTemplateLog_h:public BaseProgramFile
{
public:
	virtual void Init(const std::string& pProgramName)override
	{
		BaseProgramFile::Init(pProgramName);
		file_name=ProgramName+PROGRAMTEMPLATELOG_NAME;
		file_path=ProgramName+PROGRAMTEMPLATELOG_PATH;
		file_content=PROGRAMTEMPLATELOG_H;
	}
};

FileProgramTemplateLog_h ProgramTemplateLog_h=FileProgramTemplateLog_h();

#endif
