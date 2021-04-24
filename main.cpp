#include "src/file_manager.hpp"
#include <fstream>

namespace fm = file_manager;

int main() {
	fm::make_dir("./books");
	fm::make_pdf_data_file("books/pdf_datafile.data");
	string command;

	string thisr = fm::files[2].path;
	string pages = to_string(fm::files[2].page);

	command = "start firefox file:///" + thisr + "#page=" + pages; //example:file:///C:/Users/aryan/Documents/cpp_programming/pdfmvs/pdfm/pdfm/books/mm.pdf#page=12
	// running to a command
	cout << command << endl;
	system(command.c_str());
	return 0;
}