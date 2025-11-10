#include "printUtils.h"
#include "../inpuUtils/inputUtils.h"

void clearConsole() {
	std::cout << "\033[2J\033[1;1H";
}
void showMainMenu() {
	std::cout << "=== LIBRARY ===" << '\n';
	std::cout << std::endl;
	std::cout << "1. Add Book" << '\n';
	std::cout << "2. List All Books" << '\n';
	std::cout << "3. Search Book" << '\n';
	std::cout << std::endl;
	std::cout << "4. Add User" << '\n';
	std::cout << "5. Delete User" << '\n';
	std::cout << "6. List All Users" << '\n';
	std::cout << "7. List All User's Loans" << '\n';
	std::cout << std::endl;
	std::cout << "8. Borrow Book" << '\n';
	std::cout << "9. Return Book" << '\n';
	std::cout << "10. Renew Book" << '\n';
	std::cout << std::endl;
	std::cout << "0. Exit" << '\n';
}
void showBackMenu() {
	bool navigate = 1;
	std::cout << "0. Go Back .." << std::endl;
	while (navigate) {
		std::cin >> navigate;
	}
}