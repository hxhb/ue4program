#ifndef PROGRAMTEMPLATE_BUILD_CS_H__
#define PROGRAMTEMPLATE_BUILD_CS_H__

#include "../BaseProgramFile.h"

const char* PROGRAM_TEMPLATEB_BUILD_CS_PATH=R"(\\)";
const char* PROGRAM_TEMPLATE_BUILD_CS_FILE_NAME=R"(.Build.cs)";
const char* PROGRAMTEMPLATE_BUILD_CS=R"(
// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ProgramTemplate : ModuleRules
{
	public ProgramTemplate(ReadOnlyTargetRules Target) : base(Target)
	{
		PublicIncludePaths.Add("Runtime/Launch/Public");

		PrivateIncludePaths.Add("Runtime/Launch/Private");		// For LaunchEngineLoop.cpp include
		PrivateIncludePaths.Add("Programs/ProgramTemplate/Source");
        PrivateIncludePaths.Add("Programs/ProgramTemplate/Source/Public");
        PrivateIncludePaths.Add("Programs/ProgramTemplate/Source/Private");

        PrivateDependencyModuleNames.AddRange(
            new string[] {
                "AppFramework",
                "Core",
                "ApplicationCore",
                "Projects",
                "Slate",
                "SlateCore",
                "InputCore",
                "SlateReflector",
                "StandaloneRenderer"
            }
        );
    }
}
)";



class BuildCSFile:public BaseProgramFile
{
public:
    virtual void Init(const std::string& pProgramName)override
    {
        BaseProgramFile::Init(pProgramName);
        file_content=PROGRAMTEMPLATE_BUILD_CS;
        file_path=ProgramName+PROGRAM_TEMPLATEB_BUILD_CS_PATH;
        file_name=ProgramName+PROGRAM_TEMPLATE_BUILD_CS_FILE_NAME;
        
    }
};

BuildCSFile build_cs=BuildCSFile();
#endif
