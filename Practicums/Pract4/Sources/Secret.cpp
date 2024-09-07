#include <iostream>
#include "../Headers/Secret.h"
#include "../Headers/helperFunctions.h"
#include "../Headers/constants.h"

Secret::Secret() {
	taskDescription = nullptr;
	password = nullptr;
	failedEntries = 0;
}

Secret::Secret(const char* _taskDescription, const char* _password) {
	failedEntries = 0;
	setPassword(_password, password);
	setTask(_taskDescription, taskDescription);
}

char* Secret::getTask(const char* pwd){
	if (customStrCmp(password, pwd))
		return taskDescription;
	else {
		std::cout << INVALID_PASSWORD_MESSAGE << std::endl;
		++failedEntries;
		return nullptr;
	}	
}

void Secret::setPassword(const char* newPassword, const char* oldPassword) {
	if (password != nullptr && !customStrCmp(oldPassword, password)) {
		std::cout << INVALID_PASSWORD_MESSAGE << std::endl;
		++failedEntries;
		return;
	}

	customStrCpy(password, newPassword);
}

void Secret::setTask(const char* newTask, const char* passwd) {
	if (password != nullptr && !customStrCmp(passwd, password)) {
		std::cout << INVALID_PASSWORD_MESSAGE << std::endl;
		++failedEntries;
		return;
	}

	customStrCpy(taskDescription, newTask);
}

void Secret::print(){
	std::cout << "Enter password for the task: ";
	char* pswd = new char[MAX_PASSWORD_LENGTH];
	std::cin.getline(pswd, MAX_PASSWORD_LENGTH);

	if (password == nullptr) {
		setPassword(pswd, nullptr);
	}

	if (!customStrCmp(pswd, password)) {
		std::cout << INVALID_PASSWORD_MESSAGE << std::endl;
		++failedEntries;
		return;
	}

	newLine();

	std::cout << "Secret description:" << std::endl;
	std::cout << "Task: " << taskDescription << std::endl;
	std::cout << "Password: " << password << std::endl;
	std::cout << "Number of failed entries: " << std::endl;
}

unsigned int Secret::getLoginFails() const{
	return failedEntries;
}
