#pragma once
#include "../interfaces/IBookRepo.h"
#include "../interfaces/IUserRepo.h"
#include "../interfaces/ILoanRepo.h"
#include "../enums/LibraryEnums.h"

#include <vector>
#include <string>
#include <chrono>

class LibraryService {
	IBookRepo* bookRepo;
	IUserRepo* userRepo;
	ILoanRepo* loanRepo;
public:
	LibraryService(IBookRepo& bookRepo, IUserRepo& userRepo, ILoanRepo& loanRepo);
	Library::AddResult addBook(int bookId, std::string& bookTitle, std::string& bookAuthor, int bookYear, int bookCopies);
	std::vector<Book> listAllBooks();
	std::vector<Book> findMatchingBooks(const std::string& bookTitle, const std::string& bookAuthor);
	Library::AddResult addUser(int id, std::string& name, std::string& mail);
	Library::RemoveUserResult removeUser(const std::string userName);
	Library::RemoveLoanResult removeLoan(const int loanId);
	std::vector<User> listAllUsers();
	Library::AddLoanResult addLoan(const int loanId, const int userId, const int bookId, std::chrono::year_month_day loanDate, std::chrono::year_month_day loanDueDate);
	std::vector<Loan> listUserLoans(const int userId);
	Library::RenewLoanResult renewLoan(const int loanId);
};