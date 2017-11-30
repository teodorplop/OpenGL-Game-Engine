#pragma once

#include<vector>
#include<string>
#include<iostream>
#include<fstream>

class FileIO {
public:
	static std::string GetFileContents(const char* filePath);
	static std::vector<std::string> GetFileLines(const char* filePath);

	static void ClearFileContent(const char* filePath);

	static void WriteContent(const char* filePath, const std::string& content);
	static void WriteContent(const char* filePath, const char* content);
};