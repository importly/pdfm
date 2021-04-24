#include "file_manager.hpp"
#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include <limits>

namespace fs = std::filesystem;

using namespace std;

float file_manager::version = (float)0.001;
vector<file_manager::file_object> file_manager::files;

file_manager::file_object::file_object(file_manager::obj_types type, string namen, string pathn, unsigned int pagen) {
	//cout << type << " " << name << " " << path;
	file_type = type;
	path = pathn;
	name = namen;
	page = pagen;
}

void to_line(std::fstream& file, unsigned int num) {
	file.seekg(std::ios::beg);
	for (unsigned int i = 1; i < num; ++i) {
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
	string fullstring, name, pdf_path, page;
	unsigned int pagen = 0;

	stream.open(path, ios::in);
	to_line(stream, 2);
	while (getline(stream, fullstring)) {
		size_t pos;
		size_t number = 0;
		while ((pos = fullstring.find(',')) != std::string::npos) {
			string token = fullstring.substr(0, pos);

			switch (number) {
			case 0: {
				name = token;
				break;
			}
			case 1: {
				pdf_path = token;
				break;
			}
			case 2: {
				page = token;
				pagen = stoi(page);
				break;
			}
			default: {
				cout << "ERROR: File unreadable";
				break;
			}
			}
			fullstring.erase(0, pos + 1);
			++number;
		}

		file_object current_object(obj_types::pdf, name, pdf_path, pagen);
		files.push_back(current_object);
	}

	//for (file_object i : files) {
	//	cout << " " << i.file_type << " " << i.name << " " << i.page << endl; // debuging
	//}
}

void file_manager::write_data_file(string path)
{
	fstream stream;
	stream.open(path, ios::out);

	stream << file_manager::version << ',' << endl;
	stream.close();
}

void file_manager::make_pdf_data_file(string path) {
	fstream stream;
	float dataopen;

	stream.open(path, ios::in);
	stream >> dataopen;
	if (dataopen <= 0) {
		file_manager::write_data_file(path);
	}
	read_data_file(path);
	/*else if (dataopen <= file_manager::version) {
		stream.open(path, ios::out);
		file_manager::write_data_file(path);
	}*/
}

std::ostream& file_manager::operator<<(std::ostream& strm, const obj_types& a) {
	if (a == obj_types::pdf) {
		return strm << "pdf"; // defines which is what and returns a string
	}
	else if (a == obj_types::folder) {
		return strm << "folder";
	}
	else {
		return strm << "other";
	}
}