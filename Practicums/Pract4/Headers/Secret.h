#pragma once

class Secret {
private:
	char* taskDescription;
	char* password;
	unsigned int failedEntries;
public:
	Secret();
	Secret(const char* _taskDescription, const char* _password);

	char* getTask(const char* pwd);//it's not const 
	//because with every incorrect password the number of fails increases
	unsigned int getLoginFails() const;

	void setPassword(const char* newPassword, const char* oldPassword);
	void setTask(const char* newTask, const char* passwd);

	void print();
};