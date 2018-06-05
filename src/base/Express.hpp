#ifndef XSE_EXPRESS_HPP
#define XSE_EXPRESS_HPP 1

#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <string>
#include <stack>
#include <config.hpp>
#include <macros.hpp>
#include <base/Types.hpp>

using namespace std;

XSE_NS_BEGIN
class Express{
public:
    static string Evaluate(std::string cstr);
private:
	static std::string itoa(LLong val);
	static LLong additionSubtraction(deque<string> &deque);
	static void addValueToDeque(deque<string> &deque, LLong pre);
	static pair<LLong, LLong> getValue(const string &str, int index);
	static LLong getValue(const string &str);
};
XSE_NS_END
#endif