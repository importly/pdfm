#include "file_manager.hpp"
#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include <limits>

namespace fs = std::filesystem;

using namespace std;

float file_manager::version = (float)0.001;

file_manager::file_object::file_object(file_manager::obj_types type, string namen, string pathn) {
	//cout << type << " " << name << " " << path;
	file_type = type;
	path = pathn;
	name = namen;
}


void to_line(std::fstream& file, unsigned int num) {
	file.seekg(std::ios::beg);
	for (int i = 0; i < num - 1; ++i) {
		file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}

// vector<file_manager::file_object> file_manager::files;

void file_manager::make_dir(string path) {
	fs::create_directories(path);
}

void file_manager::read_data_file(string path)
{
	fstream stream;
	stream.open(path, ios::out);
}

void file_manager::write_data_file(string path)
{
	fstream stream;
	stream.open(path, ios::out);
	stream << file_manager::version << endl;
}

void file_manager::make_pdf_data_file(string path) {
	fstream stream;
	float dataopen;

	stream.open(path, ios::in);
	stream >> dataopen;
	if (dataopen <= file_manager::version) {
		stream.open(path, ios::out);
		file_manager::write_data_file(path);
	}
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