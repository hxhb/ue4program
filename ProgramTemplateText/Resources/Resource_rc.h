#ifndef RESOURCE_RC_H__
#define RESOURCE_RC_H__

#include "../../BaseProgramFile.h"

const char* RESOURCE_RC_FILE_NAME=R"(Resource.rc)";
const char* RESOURCE_RC_PATH=R"(\\Resources)";
const char* RESOURCE_RC_H=R"(
// Microsoft Visual C++ generated resource script.
//
#include "resource.h"

#include "VersionResource.inl"

)";

class Resource_rc:public BaseProgramFile
{
public:
    virtual void Init(const std::string& pProgramName)override
    {
        BaseProgramFile::Init(pProgramName);
        file_content=RESOURCE_RC_H;
        file_path=ProgramName+RESOURCE_RC_PATH;
        file_name=RESOURCE_RC_FILE_NAME;
    }
};

Resource_rc f_Resource_rc=Resource_rc();
#endif