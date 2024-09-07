#include <iostream>
#include <fstream>
#include "User.h"
#include "System.h"

void MyStrcpy(char* dest, const char* src) {
    size_t index = 0;

    while (src[index] != '\0') {
        dest[index] = src[index];
        ++index;
    }

    dest[index] = '\0';
}

void readUser(User& user, std::ifstream& input) {

    input.getline(user.name, MAX_FIELD_SIZE);
    input.getline(user.email, MAX_FIELD_SIZE);
    input.getline(user.password, MAX_FIELD_SIZE);

    user.name[MAX_FIELD_SIZE] = user.email[MAX_FIELD_SIZE] = user.password[MAX_FIELD_SIZE] = '\0';
}

void writeUser(const User* user, std::ofstream& output) {

    output << user->name << "\n";
    output << user->email << "\n";
    output << user->password << "\n";

}

bool registerUser(System& system) {
    if (system.numberOfUsers >= MAX_USERS_SIZE) {
        std::cout << "Error! The system is full!" << std::endl;
        return false;
    }

    char buff[MAX_FIELD_SIZE + 1];

}

//void readSystem(System* system, const char fileName[]) {
//    std::ifstream input(fileName);
//
//    if (!input.is_open()) {
//        std::cout << "Couldn't open the file " << fileName << "!" << std::endl;
//        return;
//    }
//
//    for (size_t i = 0; input.eof(); i++)
//    {
//        readUser(system->users[i], input);
//    }
//
//    input.close();
//}

void writeSystem(const System* system, const char fileName[]) {
    std::ofstream output(fileName);

    if (!output.is_open()) {
        std::cout << "Couldn't open the file " << fileName << "!" << std::endl;
        return;
    }

    for (size_t i = 0; output.eof(); i++)
    {
        writeUser(system->users[i], output);
    }

    output.close();
}


int main()
{
    System* system1;
    User* user;

    readSystem(system1, "System.csv");
}
