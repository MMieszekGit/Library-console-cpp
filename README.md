# 📚 Library Console (C++)

A **console-based library management system** written in modern C++(20).  
This project represents the **core version** of a larger multi-variant system (future REST API and GUI versions planned).

---

## 🚀 Features

- Add new books (ID, title, author, publication year, number of copies)
- Display all books in the system
- Search books by title, author, or both
- Add and remove users with validation
- Prevent user deletion when they have active loans
- Track book availability and prevent loaning when no copies remain
- Basic input validation:
  - Ensures numeric values are within valid ranges
  - Disallows empty strings for critical inputs
  - Checks for basic email validity (`@` required)
- Data consistency enforcement across repositories
- Separation of logic through clear **service**, **model**, and **repository** layers

---

## 🧱 Project Structure

```
Library-console-cpp/
├── models/                 ← Data models (Book, User, Loan)
├── interfaces/             ← Repository interfaces (IBookRepo, IUserRepo, ILoanRepo)
├── repositories/           ← In-memory implementations using std::vector
├── services/               ← Business logic layer (LibraryService)
├── enums/                  ← Enumerations (AddResult, RemoveResult, AddLoan)
├── utils/                  ← Helper utilities and input validation
├── Library.cpp             ← Main console application
├── Library-console.sln     ← Visual Studio solution
└── README.txt              ← This file
```

### 🔑 Key Components

- **Book** — stores metadata about library books (ID, title, author, year, copies)
- **User** — manages user data (ID, name, email)
- **Loan** — links users to borrowed books and due dates
- **LibraryService** — core logic handling validation and communication between repositories
- **Repositories** — in-memory collections of `Book`, `User`, and `Loan` objects
- **Enums** — define consistent return codes (e.g. `AddResult::Success`, `RemoveResult::InvalidName`)
- **Validation utilities** — protect against invalid inputs and maintain data integrity

---

## 🎯 Example Usage

Interactive console menu:

```
=== LIBRARY ===

1. Add Book
2. List All Books
3. Search Book

4. Add User
5. Delete User
6. List All Users
7. List All User's Loans

8. Borrow Book
9. Return Book
10. Renew Book

0. Exit
```

Sample book input:

```
ID: 100
Title: 1984
Author: George Orwell
Year: 1949
Copies: 4
```

Sample user input:

```
ID: 5
Name: Alice Smith
Email: alice.smith@example.com
```

---

## ⚙️ Installation & Running

### 🪟 Windows (Visual Studio)

1. Clone the repository:
   ```bash
   git clone https://github.com/MMieszekGit/Library-console-cpp.git
   ```
2. Open `Library-console.sln` in Visual Studio
3. Set `Library.cpp` as the startup file (if not already)
4. Run the project (**Ctrl + F5**)

### 🐧 Linux / macOS (CLI)

```bash
g++ -std=c++20 Library.cpp -o library_app
./library_app
```

> Note: Adjust include paths for `models/`, `interfaces/`, and other folders if needed.

---

## 🧠 Technologies & Concepts

- **C++20 standard**
- **STL containers** (`std::vector`, `std::string`)
- **Object-Oriented Design**
- **Repository pattern**
- **Encapsulation & Polymorphism**
- **Input validation & error handling**
- **Separation of concerns** (models, logic, UI)
- **Console UI** for interaction

---

## 🧩 Future Roadmap

- [ ] Complete loan system with return and due-date logic
- [ ] CSV/JSON-based data persistence
- [ ] REST API version using C++ web libraries
- [ ] GUI version using Qt or ImGui
- [ ] i18n multilingual support
- [ ] Unit testing with Catch2 or GoogleTest

---

## 👤 Author

**MM**  
Junior Developer  
🔗 [GitHub Profile](https://github.com/MMieszekGit)

---

## 📄 License

This project is licensed under the **MIT License**.  
You are free to use, modify, and distribute it.
