#include "file_manager.hpp"
#include <iostream>
#include <string>

using namespace std;

file_manager::file_object::file_object(file_manager::obj_types type, string name, string path) {
	cout << type << name << " " << path;
}

std::ostream& file_manager::operator<<(std::ostream& strm, const obj_types& a) {
	if (a == obj_types::pdf) {
		return strm << "pdf";
	}
	else if (a == obj_types::folder) {
		return strm << "folder";
	}
	else {
		return strm << "other";
	}
}