#include "Parser.h"

using namespace std;
using namespace glm;

Parser* Parser::Create(const string& text) {
	Parser* p = new Parser();
	p->text = text;
	return p;
}

void Parser::Destroy(Parser* p) {
	delete p;
}

int Parser::NextInt() {
	int i = stoi(text, &idx);
	text = text.substr(idx + 1);
	return i;
}

float Parser::NextFloat() {
	float f = stof(text, &idx);
	text = text.substr(idx + 1);
	return f;
}

vec2 Parser::NextVec2() {
	int p = (int)text.find("vec2");
	if (p == string::npos) {
		cout << "Parser error on vec2\n";
		return vec2();
	}
	text = text.substr(p + 5);

	vec2 v;
	v.x = stof(text, &idx);
	text = text.substr(idx + 1);
	v.y = stof(text, &idx);
	text = text.substr(idx + 1);
	return v;
}

vec3 Parser::NextVec3() {
	int p = (int)text.find("vec3");
	if (p == string::npos) {
		cout << "Parser error on vec3\n";
		return vec3();
	}
	text = text.substr(p + 5);

	vec3 v;
	v.x = stof(text, &idx);
	text = text.substr(idx + 1);
	v.y = stof(text, &idx);
	text = text.substr(idx + 1);
	v.z = stof(text, &idx);
	text = text.substr(idx + 1);
	return v;
}

vec4 Parser::NextVec4() {
	int p = (int)text.find("vec4");
	if (p == string::npos) {
		cout << "Parser error on vec4\n";
		return vec4();
	}
	text = text.substr(p + 5);

	vec4 v;
	v.x = stof(text, &idx);
	text = text.substr(idx + 1);
	v.y = stof(text, &idx);
	text = text.substr(idx + 1);
	v.z = stof(text, &idx);
	text = text.substr(idx + 1);
	v.w = stof(text, &idx);
	text = text.substr(idx + 1);
	return v;
}

Color Parser::NextColor() {
	int p = (int)text.find("color");
	if (p == string::npos) {
		cout << "Parser error on Color\n";
		return Color();
	}
	text = text.substr(p + 6);

	Color c;
	c.r = stof(text, &idx);
	text = text.substr(idx + 1);
	c.g = stof(text, &idx);
	text = text.substr(idx + 1);
	c.b = stof(text, &idx);
	text = text.substr(idx + 1);
	c.a = stof(text, &idx);
	text = text.substr(idx + 1);
	return c;
}

string Parser::NextWord() {
	string word = "";
	while (idx < text.size() && text[idx] == ' ')
		++idx;
	while (idx < text.size() && text[idx] != ' ')
		word += text[idx++];
	return word;
}

int Parser::StringToInt(const string& text) {
	return stoi(text);
}

float Parser::StringToFloat(const string& text) {
	return stof(text);
}

vec2 Parser::StringToVec2(const string& text) {
	string aux = text;
	string::size_type idx;

	vec2 v;
	v.x = stof(aux, &idx);
	aux = aux.substr(idx + 1);
	v.y = stof(aux);
	return v;
}

vec3 Parser::StringToVec3(const string& text) {
	string aux = text;
	string::size_type idx;

	vec3 v;
	v.x = stof(aux, &idx);
	aux = aux.substr(idx + 1);
	v.y = stof(aux, &idx);
	aux = aux.substr(idx + 1);
	v.z = stof(aux);
	return v;
}

vec4 Parser::StringToVec4(const string& text) {
	string aux = text;
	string::size_type idx;

	vec4 v;
	v.x = stof(aux, &idx);
	aux = aux.substr(idx + 1);
	v.y = stof(aux, &idx);
	aux = aux.substr(idx + 1);
	v.z = stof(aux, &idx);
	aux = aux.substr(idx + 1);
	v.w = stof(aux);
	return v;
}

Color Parser::StringToColor(const string& text) {
	string aux = text;
	string::size_type idx;

	Color c;
	c.r = stof(aux, &idx);
	aux = aux.substr(idx + 1);
	c.g = stof(aux, &idx);
	aux = aux.substr(idx + 1);
	c.b = stof(aux, &idx);
	aux = aux.substr(idx + 1);
	c.a = stof(aux, &idx);
	return c;
}
