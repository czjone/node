// #include "Path.h"
// #include "StringTool.hpp"
// #include <string>

// XSE_NS_USING;

// Path::Path(std::string path) :
// _path(StringTool::split(StringTool::replace_all(std::string(path), "\\", "/"), std::string("/")))
// {

// }
// Path::~Path(void){

// }
// std::string Path::getParentFolderName(){
// 	return _path[_path.size() - 2];
// }
// std::string Path::getFileName(){
// 	return _path[_path.size() - 1];
// }

// std::string Path::getFileNameWithOutExteion(){
// 	std::string& filename = _path[_path.size() - 1];
// 	auto pos = filename.find_first_of('.');
// 	return std::string(filename.c_str(), pos);
// }

// std::string Path::getFileExtention(){
// 	std::string& filename = _path[_path.size() - 1];
// 	int pos = filename.find_first_of('.');
// 	if (pos < 0) return std::string();
// 	//if (pos < 0) pos = filename.length();
// 	std::string str(filename.c_str() + pos + 1, filename.length() - pos -1);
// 	return str;

// }
// void Path::rename(const char* newname){
// 	std::string& filename = _path[_path.size() - 1];
// 	auto pos = filename.find_first_of('.');
// 	std::string ext(filename.c_str() + pos, filename.length() - pos);
// 	filename.clear();
// 	filename.append(newname);
// 	filename.append(ext);
// }
// void Path::renamewithFileExtention(const char* newfilename){
// 	std::string& filename = _path[_path.size() - 1];
// 	filename.clear();
// 	filename.append(newfilename);
// }
// std::string Path::getFolderName(){
// 	std::string path;
// 	for (int i = 0; i < _path.size() - 1; i++){
// 		std::string &pathnode = _path[i];
// 		if (path.length() != 0) path.append("/");
// 		path.append(pathnode.c_str());
// 	}
// 	return  path;
// }
// std::string  Path::getFullPath(){
// 	std::string path;
// 	for (std::string &foldernode : _path){
// 		if (path.length() != 0)
// 			path.append("/");
// 		path.append(foldernode.c_str());

// 	}
// 	return path;
// }

// std::string  Path::getParentFolderFullPath(){
// 	std::string path;
// 	for (int i = 0; i < this->_path.size() - 1; i++){
// 		std::string &foldernode = this->_path[i];
// 		if (path.length() != 0)
// 			path.append("/");
//  		path.append(foldernode.c_str());

// 	}
// 	return path;
// }

// bool Path::isFolder(){
// 	int ret = this->_path[_path.size() - 1].find_first_of(".");
// 		return ret < 0;
// }

// std::string Path::getPathWithOutRooPath(Path& root){
// 	std::string path;
// 	for (int i = root._path.size(); i < _path.size(); i++){
// 		if (path.length() != 0) path.append("/");
// 		path.append(_path[i]);
// 	}
// 	return path;
// }

// std::string Path::getPathWithOutRooPathWithoutExtention(Path& root){
// 	std::string path;
// 	for (int i = root._path.size(); i < _path.size() - 1; i++){
// 		if (path.length() != 0) path.append("/");
// 		path.append(_path[i]);
// 	}
// 	path.append("/");
// 	path.append(this->getFileNameWithOutExteion());
// 	return path;
// }

// void  Path::reFileExtention(const char* ext){
// 	std::string filename = this->getFileNameWithOutExteion();
// 	if (ext[0] != '.') filename.append(".");
// 	filename.append(ext);
// 	this->renamewithFileExtention(filename.c_str());
// }

// std::string Path::folderformat(const char* pathstr){
// 	Path path(pathstr);
// 	std::string &filename = path._path[path._path.size() - 1];
// 	int lastpos = filename.find_last_of("/");
// 	int len = path.getFileExtention().length();
// 	bool b = len == 0;
// 	if (b && lastpos > filename.size()){
// 		std::string fullpat = path.getFullPath();
// 		fullpat.append("/");
// 		return fullpat;
// 	}
// 	else
// 		return path.getFullPath();
// }
// std::string Path::winfolderformat(const char *path){
// 	std::string str = StringTool::replace_all(std::string(path), "/", "\\");
// 	return str;
// }


// std::string Path::unixformat(const char* pathstr){
// 	Path path(pathstr);
// 	std::string str = StringTool::replace_all(std::string(pathstr), "\\", "/");
// 	return str;
// }

// int  Path::getDepth() const
// {
// 	return _path.size();
// }
