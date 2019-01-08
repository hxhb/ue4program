#ifndef CONSOLEMAIN_CPP_H__
#define CONSOLEMAIN_CPP_H__

#include "../../../../BaseProgramFile.h"

const char* CONSOLEMAIN_CPP_H_FILE_NAME=R"(ConsoleMain.cpp)";
const char* CONSOLEMAIN_CPP_H_PATH=R"(\\Source\\Private\\Console)";
const char* CONSOLEMAIN_CPP_H=R"(
// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "RealExecutionMain.h"

namespace StringLibs {
	FString Conv_CharArrayToFString(int elementNum, char* CharArray[]);
}

int main(int argc,char *argv[])
{
    int resault = RealExecutionMain(*StringLibs::Conv_CharArrayToFString(argc,argv));
    return resault;
}


namespace StringLibs {
	FString Conv_CharArrayToFString(int elementNum, char* CharArray[])
	{
		FString local_SavedCommandLine = TEXT("");

		for (int32 Option = 0; Option < elementNum; Option++)
		{
			local_SavedCommandLine += TEXT(" ");
			FString Argument(ANSI_TO_TCHAR(CharArray[Option]));
			if (Argument.Contains(TEXT(" ")))
			{
				if (Argument.Contains(TEXT("=")))
				{
					FString ArgName;
					FString ArgValue;
					Argument.Split(TEXT("="), &ArgName, &ArgValue);
					Argument = FString::Printf(TEXT("%s=\"%s\""), *ArgName, *ArgValue);
				}
				else
				{
					Argument = FString::Printf(TEXT("\"%s\""), *Argument);
				}
			}
			local_SavedCommandLine += Argument;
		}
		return local_SavedCommandLine;
	}
}
)";

class FileConsoleMain_cpp:public BaseProgramFile
{
public:
	virtual void Init(const std::string& pProgramName)override
	{
		BaseProgramFile::Init(pProgramName);
		
		file_name=CONSOLEMAIN_CPP_H_FILE_NAME;
		file_path=ProgramName+CONSOLEMAIN_CPP_H_PATH;
		file_content=CONSOLEMAIN_CPP_H;
	}
};

FileConsoleMain_cpp ConsoleMain_cpp=FileConsoleMain_cpp();

#endif