#include "file_manager.hpp"
#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
namespace fs = std::filesystem;

using namespace std;

file_manager::file_object::file_object(file_manager::obj_types type, string namen, string pathn) {
	//cout << type << " " << name << " " << path;
	file_type = type;
	path = pathn;
	name = namen;
}

void file_manager::make_dir(string path) {
	fs::create_directories(path);
}

fstream file_manager::make_pdf_data_file(string path) {
	fstream stream;
	stream.open("pdf_datafile.data",ios::in);
	string data;
	stream >> data;
	if (data == "") {
		stream.open("pdf_datafile.data", ios::out);
	}


	return stream;
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