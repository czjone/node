#ifndef __CONSOLE_LIB_H
#define __CONSOLE_LIB_H 1

#include <string>
#include <map>
#include <vector>

using namespace std;

namespace ConsleTools {

	class Console {

		typedef std::map<std::string, std::vector<std::string>> ArgsMap;

	public:
		Console(int c, char** arg);

		virtual ~Console(void);

		bool CheckArg(std::string key, std::string arg) const;

		bool hasArg(std::string key) const;

	protected:

		void initArgs(int c, char** args) const;

	private:

		ArgsMap *mArgsMap;
	};

};

#endif