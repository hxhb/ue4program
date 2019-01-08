#ifndef PROGRAMTEMPLATE_TARGET_CS_H__
#define PROGRAMTEMPLATE_TARGET_CS_H__
// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "../BaseProgramFile.h"

const char* PROGRAM_TEMPLATE_TARGET_CS_PATH=R"(\\)";
const char* PROGRAM_TEMPLATE_TARGET_CS_FILE_NAME=R"(.Target.cs)";
const char* PROGRAM_TEMPLATE_TARGET_CS=R"(
using UnrealBuildTool;
using System.Collections.Generic;

[SupportedPlatforms(UnrealPlatformClass.All)]
public class ProgramTemplateTarget : TargetRules
{
	public ProgramTemplateTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Program;
		LinkType = TargetLinkType.Monolithic;
		LaunchModuleName = "ProgramTemplate";
        ExtraModuleNames.Add("EditorStyle");

        // Lean and mean
        bCompileLeanAndMeanUE = true;

		// No editor or editor-only data is needed
		bBuildEditor = false;
		//bBuildWithEditorOnlyData = false;

		// Compile out references from Core to the rest of the engine
		bCompileAgainstEngine = false;
		bCompileAgainstCoreUObject = true;

        // If ture the program entrance is WinMain,otherwise entrance is main
        bIsBuildingConsoleApplication = true;

    }
}
)";


class FileTarget_cs:public BaseProgramFile
{
public:
	virtual void Init(const std::string& pProgramName)override
	{
		BaseProgramFile::Init(pProgramName);
		file_content=PROGRAM_TEMPLATE_TARGET_CS;
		file_path=ProgramName+PROGRAM_TEMPLATE_TARGET_CS_PATH;
		file_name=ProgramName+PROGRAM_TEMPLATE_TARGET_CS_FILE_NAME;
		
	}
};

FileTarget_cs target_cs=FileTarget_cs();

#endif