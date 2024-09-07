#include "../Headers/HelperFunctions.h"
#include <iostream>

void customStrCpy(char*& str1, const char* str2) {
	if (!str2) {
		str1 = nullptr;
		return;
	}

	delete[] str1;
	str1 = new char[strlen(str2) + 1];

	for (size_t i = 0; str2[i] != '\0'; ++i)
	{
		str1[i] = str2[i];
	}

	str1[strlen(str2)] = '\0';
}