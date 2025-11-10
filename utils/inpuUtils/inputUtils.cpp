#include "inputUtils.h"
#include "../printUtils/printUtils.h"

int verifyIntInput(int value, const int min_range, const int max_range) {
	while (true) {
		if (std::cin.fail()) {
			clearConsole();
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Inserted value is not a number!" << '\n';
			std::cout << "Insert number: ";
			std::cin >> value;
			continue;
		}
		if (value < min_range || value > max_range) {
			clearConsole();
			std::cout << "Value out of range!" << '\n';
			std::cout << "Insert value: ";
			std::cin >> value;
			continue;
		}
		clearConsole();
		break;
	}
	return value;
}
std::string verifyStringInput(const std::string& value) {
	if (!value.empty()) { 
		clearConsole();
		return value; 
	}
	else {
		std::string new_value = "";
		while (new_value.empty()) {
			clearConsole();
			std::cout << "Field value cannot be empty!" << '\n';
			std::cout << "Insert value: ";
			std::getline(std::cin, new_value);
		}
		clearConsole();
		return new_value;
	}
}
std::string verifyEmailInput(const std::string& email) {
	std::string new_mail = email;
	if (email.find("@") != std::string::npos) {
		clearConsole();
		return email;
	}
	while(new_mail.find("@") == std::string::npos) {
		clearConsole();
		std::cout << "Inserted value is not an email!" << '\n';
		std::cout << "Insert email: ";
		std::cin >> new_mail;
	}
	clearConsole();
	return new_mail;
}