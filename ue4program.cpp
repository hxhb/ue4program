#include <iostream>
#include <vector>
#include <string>
#include "BaseProgramFile.h"
#include "ProgramTemplateText/AllProgramTemplateFiles.h"

using namespace std;

int main(int argc,char* argv[])
{
	if(argc<2){
		std::cout<<"Usage:\n\t"<<"create_program.exe ProgramName"<<std::endl;
		return -1;
	}

	std::string ProgramName=std::string(argv[1]);

	for(auto& index:BaseProgramFile::file_list)
	{
		index->Init(ProgramName);
		index->WriteToFile();
	}
	FILE* loadFP=fopen((ProgramName+"/Resources/Icon.ico").c_str(),"wb");
	fwrite(BinData,sizeof(BinData),1,loadFP);
	fclose(loadFP);
	std::cout<<"Create Standalone Program Successed!"<<std::endl;
	return 0;
}