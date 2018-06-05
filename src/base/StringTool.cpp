#include <vector>
#include <string>
#include "StringTool.hpp"

XSE_NS_USING;

using namespace std;
std::string StringTool::tolower(const std::string &val){
	std::string str(val.c_str());
	for (int i = 0; i < str.length(); i++){
		char c = str[i];
		if (c >= 'A' && c <= 'Z') str[i] += ('A' - 'a');
	}
	return str;
}

std::string StringTool::touper(const std::string &val){
	std::string str(val.c_str());
	for (int i = 0; i < str.length(); i++){
		char c = str[i];
		if (c >= 'a' && c <= 'z') str[i] -= ('A' - 'a');
	}
	return str;
}

std::vector<std::string> StringTool::split(std::string& str, std::string& splitstr){
	std::vector<std::string> strings;
	const char * split = splitstr.c_str();
	char * p;
	p = strtok((char*)str.c_str(), split);
	while (p != nullptr) {
		std::string val(p);
		strings.push_back(val);
		p = strtok(nullptr, split);
	}
	return strings;
}

string& StringTool::replace_first(string&str, const string&  old_value, const string&  new_value)
{
	string::size_type   pos(0);
	if ((pos = str.find(old_value)) != string::npos){
		str.replace(pos, old_value.length(), new_value);
	}
	return   str;
}

string& StringTool::replace_all(string&str, const string&  old_value, const string&  new_value)
{
	while (true)   {
		string::size_type   pos(0);
		if ((pos = str.find(old_value)) != string::npos)
			str.replace(pos, old_value.length(), new_value);
		else   break;
	}
	return   str;
}
string& StringTool::replace_all_distinct(string&   str, const   string&   old_value, const   string&   new_value)
{
	for (string::size_type pos(0); pos != string::npos; pos += new_value.length())   {
		if ((pos = str.find(old_value, pos)) != string::npos)
			str.replace(pos, old_value.length(), new_value);
		else   break;
	}
	return  str;
}

#if ARC_WINDOWS
/*
void StrTool::chr2wch(const char* buffer, wchar_t* wBuf)
{
size_t len = strlen(buffer);
size_t wlen = MultiByteToWideChar(CP_ACP, 0, (const char*)buffer, int(len), NULL, 0);
MultiByteToWideChar(CP_ACP, 0, (const char*)buffer, int(len), wBuf, int(wlen));
};

void StrTool :: wch2chr (char* buffer, wchar_t* wBuf)
{
size_t len = strlen(buffer);
ZeroMemory((void*)buffer, len);
WideCharToMultiByte(CP_ACP, 0, wBuf, -1, buffer, len, nullptr, nullptr);
};*/

//½«wchar_t* ×ª³Échar*µÄÊµÏÖº¯ÊýÈçÏÂ£º

char *StrTool::w2c(char *pcstr, const wchar_t *pwstr, size_t len)
{
	int nlength = wcslen(pwstr);
	int nbytes = WideCharToMultiByte(0, 0, pwstr, nlength, nullptr, 0, nullptr, nullptr);
	if (nbytes > len)   nbytes = len;
	WideCharToMultiByte(0, 0, pwstr, nlength, pcstr, nbytes, nullptr, nullptr);
	return pcstr;
}

void StrTool::c2w(wchar_t *pwstr, size_t len, const char *str)
{
	if (str)
	{
		size_t nu = strlen(str);
		size_t n = static_cast<size_t>(MultiByteToWideChar(CP_ACP, 0, static_cast<const char *>(str), static_cast<int>(nu), nullptr, 0));
		if (n >= len)n = len - 1;
		MultiByteToWideChar(CP_ACP, 0, static_cast<const char *>(str), static_cast<int>(nu), pwstr, static_cast<int>(n));
		pwstr[n] = 0;
	}
}

////°Ñascii ×Ö·û×ª»»Îªunicode×Ö·û
//wchar_t* StrTool::ctow(wchar_t *pwstr, const char *str)
//{
//	wchar_t* buffer = nullptr;
//
//	if (str)
//	{
//		size_t nu = strlen(str);
//		size_t n = static_cast<size_t>(MultiByteToWideChar(CP_ACP, 0, static_cast<const char *>(str), int(nu), nullptr, 0));
//		buffer = nullptr;
//		buffer = new wchar_t[n + 1];
//		::MultiByteToWideChar(CP_ACP, 0, static_cast<const char *>(str), int(nu), buffer, int(n));
//	}
//	return buffer;
//	//delete buffer;
//}


#endif