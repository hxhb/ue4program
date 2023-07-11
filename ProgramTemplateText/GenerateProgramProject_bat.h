#ifndef GENERATEPROGRAMPROJECT_BAT_H__
#define GENERATEPROGRAMPROJECT_BAT_H__
#include "../BaseProgramFile.h"

const char* GENERATEROGRAMPROJECT_BAT_PATH=R"(\\)";
const char* GENERATEROGRAMPROJECT_BAT_FILE_NAME=R"(GenerateProgramProject.bat)";

const char* GENERATEROGRAMPROJECT_BAT=R"(
@echo off

set "UE_Engine_Dir=..\..\..\..\Engine"

set "current_dir_name=%cd%"
:loop
set "current_dir_name=%current_dir_name:*\=%"
set "current_dir_nametmp=%current_dir_name:\=%"
if not "%current_dir_nametmp%"=="%current_dir_name%" goto loop

echo Engine Directory is %UE_Engine_Dir%.

if exist "%UE_Engine_Dir%\Build\InstalledBuild.txt" (
  ren %UE_Engine_Dir%\Build\InstalledBuild.txt %UE_Engine_Dir%\Build\InstalledBuildA.txt 
)

del %UE_Engine_Dir%\Intermediate\ProjectFiles%current_dir_name%.*
echo Intermediate\ProjectFiles%current_dir_name%.* is cleaed.

rem generate program solution
echo Using UnrealBuildTool Generate Program "%current_dir_name%" VisualStudio Solution.
echo %UE_Engine_Dir%\Binaries\DotNET\UnrealBuildTool\UnrealBuildTool.exe -notinstallengine -ProjectFiles %current_dir_name%
cmd /c "%UE_Engine_Dir%\Binaries\DotNET\UnrealBuildTool\UnrealBuildTool.exe -notinstallengine -ProjectFiles %current_dir_name%"

if exist "%UE_Engine_Dir%\Build\InstalledBuildA.txt" (
  ren %UE_Engine_Dir%\Build\InstalledBuildA.txt %UE_Engine_Dir%\Build\InstalledBuild.txt 
)

)";

class GenerateProgramProject_Bat_File:public BaseProgramFile
{
public:
    virtual void Init(const std::string& pProgramName)override
    {
        BaseProgramFile::Init(pProgramName);
        file_content=GENERATEROGRAMPROJECT_BAT;
        file_path=ProgramName+GENERATEROGRAMPROJECT_BAT_PATH;
        file_name=GENERATEROGRAMPROJECT_BAT_FILE_NAME;
        
    }
};

GenerateProgramProject_Bat_File genERate_program_project_bat=GenerateProgramProject_Bat_File();

#endif