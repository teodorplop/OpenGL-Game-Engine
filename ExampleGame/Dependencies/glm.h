#pragma once

#ifdef e
#undef e
#endif

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtx/euler_angles.hpp>

#include <iostream>
#include <fstream>
#include <string>

/**
** overload ostream operator << for easy printing glm classes
*/
inline std::ostream &operator<< (std::ostream &out, const glm::ivec2 &vec) {
	out << "[" << vec.x << " " << vec.y << "]";
	return out;
}

inline std::ostream &operator<< (std::ostream &out, const glm::vec2 &vec) {
	out << "[" << vec.x << " " << vec.y << "]";
	return out;
}

inline std::ostream &operator<< (std::ostream &out, const glm::ivec3 &vec) {
	out << "[" << vec.x << " " << vec.y << " " << vec.z << "]";
	return out;
}

inline std::ostream &operator<< (std::ostream &out, const glm::vec3 &vec) {
	out << "[" << vec.x << " " << vec.y << " " << vec.z << "]";
	return out;
}

inline std::ostream &operator<< (std::ostream &out, const glm::ivec4 &vec) {
	out << "[" << vec.x << " " << vec.y << " " << vec.z << " " << vec.w << "]";
	return out;
}

inline std::ostream &operator<< (std::ostream &out, const glm::vec4 &vec) {
	out << "[" << vec.x << " " << vec.y << " " << vec.z << " " << vec.w << "]";
	return out;
}

inline std::ostream &operator<< (std::ostream &out, const glm::quat &rot) {
	out << "[" << rot.x << " " << rot.y << " " << rot.z << " " << rot.w << "]";
	return out;
}

inline bool vec2_fromString(const std::string& str, glm::vec2& v) {
	int p = (int)str.find("vec2");
	if (p == std::string::npos) return false;

	std::string content = str.substr(p + 5);
	std::string::size_type sz;
	v.x = std::stof(content, &sz);
	v.y = std::stof(content.substr(sz + 1));
	return true;
}

inline bool vec3_fromString(const std::string& str, glm::vec3& v) {
	int p = (int)str.find("vec3");
	if (p == std::string::npos) return false;

	std::string content = str.substr(p + 5);
	std::string::size_type sz;
	v.x = std::stof(content, &sz);
	v.y = std::stof(content = content.substr(sz + 1), &sz);
	v.z = std::stof(content.substr(sz + 1));
	return true;
}

inline bool vec4_fromString(const std::string& str, glm::vec4& v) {
	int p = (int)str.find("vec4");
	if (p == std::string::npos) return false;

	std::string content = str.substr(p + 5);
	std::string::size_type sz;
	v.x = std::stof(content, &sz);
	v.y = std::stof(content = content.substr(sz + 1), &sz);
	v.z = std::stof(content = content.substr(sz + 1), &sz);
	v.w = std::stof(content.substr(sz + 1));
	return true;
}
