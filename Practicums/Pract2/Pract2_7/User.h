#pragma once
#include "Constants.h";

struct User {
    char name[MAX_FIELD_SIZE + 1];
    char email[MAX_FIELD_SIZE + 1];
    char password[MAX_FIELD_SIZE + 1];
};