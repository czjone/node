// #include "Console.h"
// // #include "../Core/stringext.h"
// #include <algorithm>
// using namespace ConsleTools;
// using namespace Core;

// Console::Console(int c,char** args):mArgsMap(nullptr){
// 	mArgsMap = new ArgsMap();
// 	initArgs(c, args);
// }

// Console::~Console(){
// 	DELETE(this->mArgsMap);
// }

// bool Console::CheckArg(std::string key,std::string tagArg) const
// {
// 	bool ret = false;
// 	auto mapItr = this->mArgsMap->find(key);
// 	if (mapItr == this->mArgsMap->end()) ret = false;
// 	else {
// 		auto &argsVect = mapItr->second;
// 		auto itr = argsVect.begin();
// 		while (itr != argsVect.end())
// 		{
// 			if (*(itr) == tagArg) {
// 				ret = true;
// 				break;
// 			}
// 			++itr;
// 		}
// 	}
// 	return ret;
// }

// bool Console::hasArg(std::string key) const
// {
// 	bool ret = false;
// 	auto mapItr = this->mArgsMap->find(key);
// 	if (mapItr == this->mArgsMap->end()) ret = false;
// 	else ret = true;
// 	return ret;
// }

// void Console::initArgs(int c,char **args) const
// {
// 	std::string key;
// 	for (int i = 0; i < c; ++i){
// 		std::string arg(*(args + i));
// 		if (arg.find("-") == 0 || arg.find("--") == 0 ){
// 			std::vector<std::string> vect;
// 			std::string keyArg = StrTool::replace_all(arg, "-", "");
// 			ArgsMap::value_type valtype(keyArg,vect);
// 			this->mArgsMap->insert(valtype);
// 			key = arg;
// 		}
// 		else {
// 			auto itr = this->mArgsMap->find(key);
// 			if (itr == this->mArgsMap->end())
// 			{
// 				LOG("��������");
// 				break;
// 			}
// 			itr->second.push_back(arg);
// 		}
// 	}
// }
