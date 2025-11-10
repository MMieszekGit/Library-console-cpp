#pragma once
#include <iostream>
#include <string>
#include <limits>

int verifyIntInput(int value, const int min_range, const int max_range);
std::string verifyStringInput(const std::string& value);
std::string verifyEmailInput(const std::string& email);