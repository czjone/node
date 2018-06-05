#ifndef XSE_PATH_HPP
#define XSE_PATH_HPP 1

#include <vector>
#include <string>
#include <config.hpp>
#include <macros.hpp>

using namespace std;

XSE_NS_BEGIN
	class Path{
		std::vector<std::string> _path;
	public:
		Path(std::string path);
		virtual ~Path(void);
		std::string getParentFolderName();
		std::string getFileName();
		std::string getFileNameWithOutExteion();
		std::string getFileExtention();
		void rename(const char* newname);
		void renamewithFileExtention(const char* newfilename);
		std::string getFolderName();
		std::string getFullPath();
		std::string getParentFolderFullPath();
		bool isFolder();
		std::string getPathWithOutRooPath(Path& root);
		std::string getPathWithOutRooPathWithoutExtention(Path& root);
		int getDepth() const;
		void reFileExtention(const char* ext);
		static std::string folderformat(const char* pathstr);
		static std::string winfolderformat(const char* pathstr);
		static std::string unixformat(const char* pathstr);
	};
XSE_NS_END
#endif