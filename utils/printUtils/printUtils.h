#pragma once
#include <vector>
#include <iostream>
#include <limits>

template <typename T>
void printDataVector(const std::vector<T>& data) {
	if (data.empty()) {
		std::cout << std::endl;
		return;
	}
	for (const auto& value : data) {
		std::cout << value;
	}
}
void clearConsole();
void showMainMenu();
void showBackMenu();