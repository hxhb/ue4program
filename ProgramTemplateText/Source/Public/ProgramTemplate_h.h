#ifndef PROGRAMTEMPLATE_H__
#define PROGRAMTEMPLATE_H__

#include "../../../BaseProgramFile.h"

const char* PROGRAM_TEMPLATE_H_FILE_NAME=R"(.h)";
const char* PROGRAM_TEMPLATE_H_PATH=R"(\\Source\\Public)";
const char* PROGRAM_TEMPLATE_H=R"(
// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ProgramTemplateLog.h"

#include "GenericPlatform/GenericApplication.h"
#include "RequiredProgramMainCPPInclude.h"

#define LOCTEXT_NAMESPACE "ProgramTemplate"
)";


class FileProgramTemplate_h:public BaseProgramFile
{
public:
	virtual void Init(const std::string& pProgramName)override
	{
		BaseProgramFile::Init(pProgramName);
		
		file_name=ProgramName+PROGRAM_TEMPLATE_H_FILE_NAME;
		file_path=ProgramName+PROGRAM_TEMPLATE_H_PATH;
		file_content=PROGRAM_TEMPLATE_H;
	}
};

FileProgramTemplate_h ProgramTemplate_h=FileProgramTemplate_h();

#endif