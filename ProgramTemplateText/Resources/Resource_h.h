#ifndef RESOURCE_H_H__
#define RESOURCE_H_H__

#include "../../BaseProgramFile.h"

const char* RESOURCE_H_FILE_NAME=R"(Resource.h)";
const char* RESOURCE_H_PATH=R"(\\Resources)";
const char* RESOURCE_H_H=R"(
// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

//{{NO_DEPENDENCIES}}
// Microsoft Visual C++ generated include file.
// Used by Resource.rc
//
#define IDD_SELECTBUILD                 101
#define IDD_ERRORDIALOG                 105
#define IDC_BROWSE                      1001
#define IDC_BUILDLIST                   1002
#define IDC_ERRORLOGTEXT                1005
#define IDC_ERRORMESSAGE                1006

// Next default values for new objects
// 
#ifdef APSTUDIO_INVOKED
#ifndef APSTUDIO_READONLY_SYMBOLS
#define _APS_NEXT_RESOURCE_VALUE        106
#define _APS_NEXT_COMMAND_VALUE         40001
#define _APS_NEXT_CONTROL_VALUE         1007
#define _APS_NEXT_SYMED_VALUE           101
#endif
#endif

)";

class RESOURCE_H:public BaseProgramFile
{
public:
    virtual void Init(const std::string& pProgramName)override
    {
        BaseProgramFile::Init(pProgramName);
        file_content=RESOURCE_H_H;
        file_path=ProgramName+RESOURCE_H_PATH;
        file_name=RESOURCE_H_FILE_NAME;
    }
};

RESOURCE_H f_RESOURCE_H=RESOURCE_H();
#endif