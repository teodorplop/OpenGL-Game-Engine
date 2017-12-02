#include "FileIO.h"
#include <Windows.h>

using namespace std;

string FileIO::GetFileContents(const char* filePath) {
	ifstream fileStream(filePath, ios::in);
	string content = "";
	if (fileStream.is_open()) {
		string line = "";
		while (getline(fileStream, line))
			content += line + "\n";
		fileStream.close();
	}
	return content;
}

vector<string> FileIO::GetFileLines(const char* filePath) {
	ifstream fileStream(filePath, ios::in);
	vector<string> content;
	if (fileStream.is_open()) {
		string line = "";
		while (getline(fileStream, line))
			content.push_back(line);
		fileStream.close();
	}
	return content;
}

void FileIO::WriteContent(const char* filePath, const std::string& content) {
	ofstream fileStream(filePath, ios::out);
	if (fileStream.is_open()) {
		fileStream << content;
		fileStream.close();
	}
}
void FileIO::WriteContent(const char* filePath, const char* content) {
	ofstream fileStream(filePath, ios::out);
	if (fileStream.is_open()) {
		fileStream << content;
		fileStream.close();
	}
}

void FileIO::ClearFileContent(const char* filePath) {
	WriteContent(filePath, "");
}