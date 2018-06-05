#ifndef XSE_STRING_TOOL_HPP
#define XSE_STRING_TOOL_HPP 1

#include <vector>
#include <string>
#include <config.hpp>
#include <macros.hpp>

XSE_NS_BEGIN
	class StringTool{
	public:
		static std::string tolower(const std::string &val);
		static std::string touper(const std::string &val);
		static std::vector<std::string> split(std::string& str, std::string& splitstr);
		static std::string& replace_first(std::string &str, const  std::string &old_value, const  std::string &new_value);
		static std::string& replace_all(std::string &str, const  std::string &old_value, const  std::string &new_value);
		static std::string& replace_all_distinct(std::string &str, const  std::string &old_value, const  std::string &new_value);

#if ARC_WINDOWS
		/*static void chr2wch(const char* buffer, wchar_t* wBuf);
		static void wch2chr(char* buffer, wchar_t* wBuf);*/

		static char* w2c(char *pcstr, const wchar_t *pwstr, size_t len);
		static void c2w(wchar_t *pwstr, size_t len, const char *str);

		/**
		 * \brief ×ª»»³Éwindows api»áÓÃµÄµ½µÄ×Ö·û¼¯¡£
		 * \param pwstr 
		 * \param str 
		 * \return 
		 */
		static wchar_t* ctow(wchar_t *pwstr, const char *str)  = delete ; //ÄÚÔÚ¹ÜÀíÓÐÎÊÌâ£¬²»ÄÜÖ±½Ó Ê¹ÓÃ¡£
#endif
	};
XSE_NS_END

#endif