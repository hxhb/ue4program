#include "string_tools.h"


void StringTools::create_recursion_dir(const std::string& basepath,const std::string& rela_path)
{
	// std::cout<<rela_path<<std::endl;
	std::string recursion_path=basepath;

	std::string::size_type begin_index=0;
	std::string::size_type pos_index=rela_path.find("\\",begin_index);
	if(rela_path.find(":")!=std::string::npos){
		std::string::size_type tempcolon = rela_path.find(":");
		begin_index=tempcolon+1;
		pos_index = rela_path.find("\\",begin_index);
	}

	while(pos_index!=std::string::npos)
	{
		if(!recursion_path.empty())
			recursion_path+="\\";
		recursion_path+=std::string(rela_path,begin_index,pos_index-begin_index);
		// cout<<"begin_index "<<begin_index<<"\t"<<"pos_index "<<pos_index<<" recursion_path is "<<recursion_path<<endl;
		if(!mkdir(recursion_path.c_str())){
			// std::cout<<"create "<<recursion_path<<std::endl;
		}
		begin_index = pos_index+1;
		pos_index = rela_path.find("\\",begin_index);
	}

	if(begin_index < rela_path.size()-1)
	{
		recursion_path+="\\"+std::string(rela_path,begin_index,rela_path.size()-1);
		// cout<<"begin_index "<<begin_index<<"\t"<<"pos_index "<<rela_path.size()<<" recursion_path is "<<recursion_path<<endl;
		if(!mkdir(recursion_path.c_str())){
			// std::cout<<"create "<<recursion_path<<std::endl;
		}
	}
}

std::string StringTools::replace_substring(const std::string& file,const std::string& replace_src,const std::string& replace_target)
{
	std::string resault("");

	std::string::size_type begin_index=0;
	std::string::size_type pos_index=file.find(replace_src,begin_index);

	while(pos_index != std::string::npos)
	{
		resault += std::string(file.begin()+begin_index,file.begin()+pos_index);
		resault += replace_target;
		begin_index = pos_index+replace_src.size();
		pos_index = file.find(replace_src,begin_index);
	}
	resault += std::string(file,begin_index,file.size()-1);
	return resault;
}