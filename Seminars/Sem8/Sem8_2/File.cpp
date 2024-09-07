#include <iostream>
#include <cstring>
#include <fstream>
#include <stdexcept>
#include "File.h"

File::Line::Line() {
	setOrigin("");
	setDest("");
}

File::Line::Line(const char* _origin, const char* _dest, unsigned int _priceInEuro) {
	setOrigin(_origin);
	setDest(_dest);
	setPrice(_priceInEuro);
}

void File::Line::setOrigin(const char* _origin) {
	strcpy(origin, strlen(_origin) > FileConstants::LINE_MAX_LENGTH ? "" : _origin);
}

void File::Line::setDest(const char* _dest) {
	strcpy(dest, strlen(_dest) > FileConstants::LINE_MAX_LENGTH ? "" : _dest);
}

void File::Line::setPrice(unsigned int _priceInEuro) {
	priceInEuro = _priceInEuro;
}

File::File() : fileName(FileConstants::INPUT_NAME), capacity(FileConstants::INITIAL_CAPACITY) {
	data = new Line * [capacity];
}

File::~File() {
	free();
}

void File::free() {

}

void File::inputFile(){
	std::ifstream input(fileName, std::ios::binary);

	if (!input.is_open()) {
		std::cout << "Couldn't open the file!" << std::endl;
		return;
	}

	delete[] data;
	size_t fileSize = getFileSize(input);
	Line line;

	while (input.read((char*)&line, fileSize / sizeof(line))) {
		if (size == capacity) {
			resize();
		}
	}

	input.close();
}

size_t File::getFileSize(std::ifstream& _input) const {
	_input.seekg(0, std::ios::end);
	std::streampos fileSize = _input.tellg();
	_input.seekg(0, std::ios::beg);

	return fileSize;
}

