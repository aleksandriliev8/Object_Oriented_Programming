#pragma once
#include "User.h"
#include "Constants.h"

struct System {
	User* users[MAX_USERS_SIZE];
	unsigned int numberOfUsers = 0;
};