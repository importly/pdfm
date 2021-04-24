#include "src/file_manager.hpp"
#include <fstream>

namespace fm = file_manager;

int main() {
	fm::file_object object(file_manager::obj_types::pdf, "object", "path");

	fm::make_dir("./books");
	
	fm::make_pdf_data_file("books/pdf_datafile.data");
	
	return 0;
}