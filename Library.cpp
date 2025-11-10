// Library.cpp - console

#include "utils/printUtils/printUtils.h"
#include "utils/inpuUtils/inputUtils.h"

#include "models/Book.h"
#include "models/User.h"
#include "models/Loan.h"

#include "interfaces/IBookRepo.h"
#include "interfaces/IUserRepo.h"
#include "interfaces/ILoanRepo.h"

#include "repositories/VectorBookRepo.h"
#include "repositories/VectorUserRepo.h"
#include "repositories/VectorLoanRepo.h"

#include "enums/LibraryEnums.h"
#include "services/LibraryService.h"

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <chrono>
#include <limits>

int main()
{	
	VectorBookRepo bookRepo;
	VectorUserRepo userRepo;
	VectorLoanRepo loanRepo;

	LibraryService library(bookRepo, userRepo, loanRepo);

	int selectedOption;
	for (;;) {
		showMainMenu();
		std::cin >> selectedOption;
		switch (selectedOption) {
		case 1: {
			clearConsole();
			int id, copies, year;
			std::string title, author;

			std::cout << "Book ID: ";
			std::cin >> id;
			id = verifyIntInput(id, 0, 9999);

			std::cout << "Title: ";
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::getline(std::cin, title);
			title = verifyStringInput(title);

			std::cout << "Author: ";
			std::getline(std::cin, author);
			author = verifyStringInput(author);

			std::cout << "Release Year: ";
			std::cin >> year;
			year = verifyIntInput(year, 0, 2026);

			std::cout << "Copies Amount: ";
			std::cin >> copies;
			copies = verifyIntInput(copies, 1, 100);

			Library::AddResult result = library.addBook(id, title, author, year, copies);
			switch (result) {
			case Library::AddResult::Success:
				clearConsole();
				std::cout << "SUCCESS: Book added!" << '\n';
				std::cout << std::endl;
				showBackMenu();
				break;
			case Library::AddResult::DuplicatedId:
				clearConsole();
				std::cout << "ERROR: Book with given ID already exists!" << '\n';
				std::cout << std::endl;
				showBackMenu();
				break;
			case Library::AddResult::DuplicatedTitle:
				clearConsole();
				std::cout << "ERROR: Book with given title already exists " << '\n';
				std::cout << std::endl;
				showBackMenu();
				break;
			}
			clearConsole();
			break;
		}
		case 2: {
			clearConsole();
			printDataVector(library.listAllBooks());
			showBackMenu();
			clearConsole();
			break;
		}
		case 3: {
			std::string title, author;
			int select;
			clearConsole();
			std::cout << "1. Search by Title" << '\n';
			std::cout << "2. Search by Author" << '\n';
			std::cout << "3. Search by Title and Author" << '\n';
			std::cin >> select;

			switch (select) {
			case 1:
				clearConsole();
				std::cout << "Insert Title: ";
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::getline(std::cin, title);
				title = verifyStringInput(title);
				author = "";
				break;
			case 2:
				clearConsole();
				std::cout << "Insert Author: ";
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::getline(std::cin, author);
				author = verifyStringInput(author);
				title = "";
				break;
			case 3:
				clearConsole();
				std::cout << "Insert Title: ";
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::getline(std::cin, title);
				title = verifyStringInput(title);
				std::cout << "Insert Author: ";
				std::getline(std::cin, author);
				author = verifyStringInput(author);
				break;
			default:
				clearConsole();
				break;
			}
			std::vector<Book> matchingBooks = library.findMatchingBooks(title, author);
			printDataVector(matchingBooks);
			showBackMenu();
			clearConsole();
			break;
		}
		case 4: {
			int userId;
			std::string name, mail;

			clearConsole();
			std::cout << "User ID: ";
			std::cin >> userId;
			userId = verifyIntInput(userId, 0, 9999);

			std::cout << "Username: ";
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::getline(std::cin, name);
			name = verifyStringInput(name);

			std::cout << "Email adress: ";
			std::getline(std::cin, mail);
			mail = verifyStringInput(mail);
			mail = verifyEmailInput(mail);

			Library::AddResult result = library.addUser(userId, name, mail);
			switch (result) {
			case Library::AddResult::Success:
				clearConsole();
				std::cout << "SUCCESS: User added!" << '\n';
				std::cout << std::endl;
				showBackMenu();
				break;
			case Library::AddResult::DuplicatedId:
				clearConsole();
				std::cout << "ERROR: User with given ID already exists!" << '\n';
				std::cout << std::endl;
				showBackMenu();
				break;
			case Library::AddResult::DuplicatedTitle:
				clearConsole();
				std::cout << "ERROR: Username already in use!" << '\n';
				std::cout << std::endl;
				showBackMenu();
			}
			clearConsole();
			break;
		}
		case 5: {
			std::string userName;

			clearConsole();
			std::cout << "Username: ";
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::getline(std::cin, userName);
			userName = verifyStringInput(userName);

			Library::RemoveUserResult result = library.removeUser(userName);
			switch (result) {
			case Library::RemoveUserResult::Success:
				clearConsole();
				std::cout << "SUCCESS: User deleted!" << '\n';
				std::cout << std::endl;
				showBackMenu();
				break;
			case Library::RemoveUserResult::InvalidUserName:
				clearConsole();
				std::cout << "ERROR: User with given name doesn't exist!" << '\n';
				std::cout << std::endl;
				showBackMenu();
				break;
			case Library::RemoveUserResult::HasActiveLoans:
				clearConsole();
				std::cout << "ERROR: User has active loans!" << '\n';
				std::cout << std::endl;
				showBackMenu();
				break;
			}
			clearConsole();
			break;
		}
		case 6: {
			clearConsole();
			printDataVector(library.listAllUsers());
			showBackMenu();
			clearConsole();
			break;
		}
		case 7: {
			int userId;
			clearConsole();
			std::cout << "User ID: ";
			std::cin >> userId;
			userId = verifyIntInput(userId, 0, 9999);
			printDataVector(library.listUserLoans(userId)); //PRINTS ENTIRE LOAN
			showBackMenu();
			clearConsole();
			break;
		}
		case 8: {
			int loanId, bookId, userId;

			clearConsole();
			std::cout << "Loan ID: ";
			std::cin >> loanId;
			loanId = verifyIntInput(loanId, 0, 9999);

			std::cout << "Book ID: ";
			std::cin >> bookId;
			bookId = verifyIntInput(bookId, 0, 9999);

			std::cout << "User ID: ";
			std::cin >> userId;
			userId = verifyIntInput(userId, 0, 9999);

			auto date = std::chrono::system_clock::now();
			auto days = floor<std::chrono::days>(date);
			std::chrono::year_month_day loanDate{ days };
			std::chrono::year_month_day dueDate{ days + std::chrono::days{ 30 } };

			Library::AddLoanResult result = library.addLoan(loanId, userId, bookId, loanDate, dueDate);
			switch (result) {
				case Library::AddLoanResult::Success:
					clearConsole();
					std::cout << "SUCCESS: Loan added!" << '\n';
					std::cout << std::endl;
					showBackMenu();
					break;
				case Library::AddLoanResult::InvalidLoanId:
					clearConsole();
					std::cout << "ERROR: Loan with given ID already exists!" << '\n';
					std::cout << std::endl;
					showBackMenu();
					break;
				case Library::AddLoanResult::InvalidUserId:
					clearConsole();
					std::cout << "ERROR: User with given ID doesn't exist!" << '\n';
					std::cout << std::endl;
					showBackMenu();
					break;
				case Library::AddLoanResult::InvalidBookId:
					clearConsole();
					std::cout << "ERROR: Book with given ID doesn't exist!" << '\n';
					std::cout << std::endl;
					showBackMenu();
					break;
				case Library::AddLoanResult::NoAvailableBook:
					clearConsole();
					std::cout << "ERROR: No available book copies!" << '\n';
					std::cout << std::endl;
					showBackMenu();
					break;
				case Library::AddLoanResult::NoAvailableUserLoanSlot:
					clearConsole();
					std::cout << "ERROR: User has reached loans limit of 5!" << '\n';
					std::cout << std::endl;
					showBackMenu();
					break;
				case Library::AddLoanResult::HasBorrowedBook:
					clearConsole();
					std::cout << "ERROR: User has already borrowed book with given ID!" << '\n';
					std::cout << std::endl;
					showBackMenu();
					break;
			}
			clearConsole();
			break;
		}
		case 9: {
			int loanId;

			clearConsole();
			std::cout << "Loan ID: ";
			std::cin >> loanId;
			loanId = verifyIntInput(loanId, 0, 9999);

			Library::RemoveLoanResult result = library.removeLoan(loanId);
			switch (result) {
			case  Library::RemoveLoanResult::Success:
				clearConsole();
				std::cout << "SUCCESS: Book returned!" << '\n';
				std::cout << std::endl;
				showBackMenu();
				break;
			case Library::RemoveLoanResult::InvalidLoanId:
				clearConsole();
				std::cout << "ERROR: Loan with given ID doesn't exist!" << '\n';
				std::cout << std::endl;
				showBackMenu();
				break;
			}
			clearConsole();
			break;
		}
		case 10: {
			clearConsole();
			int loanId;
			std::cout << "Loan ID: ";
			std::cin >> loanId;
			loanId = verifyIntInput(loanId, 0, 9999);
			Library::RenewLoanResult result = library.renewLoan(loanId);
			switch (result) {
			case Library::RenewLoanResult::Success:
				clearConsole();
				std::cout << "SUCCESS: Book renewed!" << '\n';
				std::cout << std::endl;
				showBackMenu();
				break;
			case Library::RenewLoanResult::InvalidLoanId:
				clearConsole();
				std::cout << "ERROR: Loan with given ID doesn't exist!" << '\n';
				std::cout << std::endl;
				showBackMenu();
				break;
			}
			clearConsole();
			break;
		}
		case 0:
			exit(0);
			break;
		default:
			clearConsole();
		}	
	}
}