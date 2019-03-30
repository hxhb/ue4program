#ifndef OPENPROGRAMPROJECT_BAT_H__
#define OPENPROGRAMPROJECT_BAT_H__

#include "../BaseProgramFile.h"

const char* OPENPROGRAMPROJECT_BAT_PATH=R"(\\)";
const char* OPENPROGRAMPROJECT_BAT_FILE_NAME=R"(OpenProgramProject.bat)";

const char* OPENPROGRAMPROJECT_BAT=R"(
@echo off

set "UE_Engine_Dir=..\..\..\..\Engine"

set "current_dir_name=%cd%"
:loop
set "current_dir_name=%current_dir_name:*\=%"
set "current_dir_nametmp=%current_dir_name:\=%"
if not "%current_dir_nametmp%"=="%current_dir_name%" goto loop

call GenerateProgramProject.bat

rem open project vs solution
echo open Intermediate\ProjectFiles\%current_dir_name%.vcxproj
"%UE_Engine_Dir%\Intermediate\ProjectFiles\%current_dir_name%.vcxproj"
)";


class OpenProgramProject_Bat_File:public BaseProgramFile
{
public:
    virtual void Init(const std::string& pProgramName)override
    {
        BaseProgramFile::Init(pProgramName);
        file_content=OPENPROGRAMPROJECT_BAT;
        file_path=ProgramName+OPENPROGRAMPROJECT_BAT_PATH;
        file_name=OPENPROGRAMPROJECT_BAT_FILE_NAME;
        
    }
};

OpenProgramProject_Bat_File open_program_project_bat=OpenProgramProject_Bat_File();
#endif