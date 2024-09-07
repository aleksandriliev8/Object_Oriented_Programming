#include "../Headers/helperFunctions.h"
#include <iostream>

size_t customStrLen(const char* string) {
	if (string == nullptr)
		return 0;

	size_t length = 0;

	while (string[length] != '\0') {
		++length;
	}

	return length;
}

void customStrCpy(char*& forConfig, const char* original){
	if (original == nullptr) {
		return;
	}

	size_t length = customStrLen(original);

	if (length == 0) {
		forConfig = new char[1];
		forConfig[0] = '\0';
		return;
	}

	size_t index = 0;

	forConfig = new char[length + 1];

	for (size_t index = 0; original[index] != '\0'; ++index)
	{
		forConfig[index] = original[index];
	}

	forConfig[length] = '\0';
}

bool customStrCmp(const char* str1, const char* str2) {
	size_t length1 = customStrLen(str1);
	size_t length2 = customStrLen(str2);

	if (length1 != length2)
		return false;

	for (size_t i = 0; i < length1; i++)
	{
		if (str1[i] != str2[i])
			return false;
	}

	return true;
}

void newLine() {
	std::cout << std::endl;
}

