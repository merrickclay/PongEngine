#include "fileutils.h"


namespace pongEngine {

	std::string read_file(const char* filepath) {
		FILE* file = fopen(filepath, "rt");
		fseek(file, 0, SEEK_END);
		unsigned long length = ftell(file);
		char* data = new char[(double)length + 1];
		memset(data, 0, (double)length + 1);
		fseek(file, 0, SEEK_SET);
		fread(data, 1, length, file);
		fclose(file);

		std::string result(data);
		delete[] data;
		return result;
	}

}