#ifndef VERSION_RESOURCE_H__
#define VERSION_RESOURCE_H__

#include "../../BaseProgramFile.h"

const char* VERSION_RESOURCE_FILE_NAME=R"(VersionResource.inl)";
const char* VERSION_RESOURCE_PATH=R"(\\Resources)";
const char* VERSION_RESOURCE_H=R"(

// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#ifndef APSTUDIO_INVOKED

#include <windows.h>
#include "../../../../Runtime/Launch/Resources/Windows/resource.h"
#include "../../../../Runtime/Launch/Resources/Version.h"

#define IDICON_ProgramTemplate 2000
/////////////////////////////////////////////////////////////////////////////
//
// Version
//

VS_VERSION_INFO VERSIONINFO
 FILEVERSION ENGINE_MAJOR_VERSION,ENGINE_MINOR_VERSION,ENGINE_PATCH_VERSION,0
 PRODUCTVERSION ENGINE_MAJOR_VERSION,ENGINE_MINOR_VERSION,ENGINE_PATCH_VERSION,0
 FILEFLAGSMASK 0x17L
#ifdef _DEBUG
 FILEFLAGS 0x1L
#else
 FILEFLAGS 0x0L
#endif
 FILEOS 0x4L
 FILETYPE 0x2L
 FILESUBTYPE 0x0L
BEGIN
	BLOCK "StringFileInfo"
	BEGIN
		BLOCK "040904b0"
		BEGIN
			VALUE "CompanyName", "UnrealEngine"
			VALUE "LegalCopyright", EPIC_COPYRIGHT_STRING
			VALUE "ProductName", "ProgramTemplate"
			VALUE "ProductVersion", ENGINE_VERSION_STRING
			VALUE "FileDescription", "ProgramTemplate"
			VALUE "InternalName", EPIC_PRODUCT_IDENTIFIER
			VALUE "OriginalFilename", "ProgramTemplate.exe"
			VALUE "ShellIntegrationVersion", "2"
		END
	END
	BLOCK "VarFileInfo"
	BEGIN
		VALUE "Translation", 0x409, 1200
	END
END

#endif


// Icon with lowest ID value placed first to ensure application icon
// remains consistent on all systems.
IDICON_ProgramTemplate			ICON                    "Icon.ico"

)";


class VersionResource_inl:public BaseProgramFile
{
public:
    virtual void Init(const std::string& pProgramName)override
    {
        BaseProgramFile::Init(pProgramName);
        file_content=VERSION_RESOURCE_H;
        file_path=ProgramName+VERSION_RESOURCE_PATH;
        file_name=VERSION_RESOURCE_FILE_NAME;
    }
};

VersionResource_inl f_VersionResource_inl=VersionResource_inl();
#endif