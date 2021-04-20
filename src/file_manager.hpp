#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <tuple>
#include <string>

using namespace std;

namespace file_manager
{

	enum class obj_types
	{
		pdf,
		folder,
		other
	};

	class file_object
	{
	public:
		obj_types file_type;
		vector<file_object> objects;

		file_object(obj_types type, string name, string path);
	};

	std::ostream& operator<<(std::ostream& strm, const obj_types& a);
}
