#include "Scene.h"

#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include "Utils\FileIO.h"

#include "GameObject.h"
#include "ComponentSystem.h"
#include "Utils\Parser.h"

#include "Utils\XML\pugixml.hpp"

using namespace std;

template<typename Out> void split(const string &s, char delim, Out result) {
	stringstream ss(s);
	string item;
	while (getline(ss, item, delim))
		*(result++) = item;
}

vector<string> split(const string &s, char delim) {
	vector<string> elems;
	split(s, delim, back_inserter(elems));
	return elems;
}

string remove(const string& str, char chr) {
	string r = "";
	for (auto c : str)
		if (c != chr)
			r += c;
	return r;
}

void SetTransform(GameObject* go, pugi::xml_attribute attr) {
	Parser* parser = Parser::Create(attr.value());
	go->GetTransform()->SetLocalPosition(parser->NextVec3());
	go->GetTransform()->SetLocalRotation(parser->NextVec3());
	go->GetTransform()->SetLocalScale(parser->NextVec3());
	Parser::Destroy(parser);
}

void DFS(pugi::xml_node node) {
	GameObject* go = GameObject::Create(node.name());

	auto attributes = node.attributes();
	auto it = attributes.begin();
	SetTransform(go, *it);
	for (++it; it != attributes.end(); ++it) {
		Component* comp = go->AddComponent((*it).name());
		ComponentSystem::DeserializeComponent(comp, (*it).value());
	}

	for (auto& child : node.children())
		DFS(child);
}

void Scene::Load(const char* filename) {
	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file(filename);

	if (!result) {
		cout << filename << " XML Error: " << result.description() << ' ' << "XML Error Offset: " << result.offset;
		return;
	}

	for (auto& root : doc.children())
		DFS(root);
}
