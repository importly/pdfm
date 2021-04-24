#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <fstream> 

using namespace std;

namespace file_manager {
	extern float version; 
	enum class obj_types {
		pdf,
		folder,
		other
	};

	void make_dir(string path);

	void read_data_file(string path);
	void write_data_file(string path);

	void make_pdf_data_file(string path);

	class file_object {
	public:
		obj_types file_type;
		vector<file_object> objects; 
		string path;
		string name; 
		unsigned int page;

		file_object(obj_types type, string name, string path,unsigned int page);
	};

	extern vector<file_object> files;

	std::ostream& operator<<(std::ostream& strm, const obj_types& a); // figure out string output for obj_types
}
