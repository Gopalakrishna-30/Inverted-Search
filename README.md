# Inverted-Search
# 🔍 Inverted Search Engine

A command-line **Inverted Search Engine** developed in **C** that efficiently indexes multiple text files using **Hash Tables** and **Linked Lists**. The application allows users to search for words and instantly retrieve the list of files containing those words along with their occurrence count. It also supports saving and reloading the generated database.

---

## 📌 Project Overview

The Inverted Search Engine creates an index of words from multiple text files, enabling fast and efficient search operations. Instead of scanning every file during each search, the program stores indexed information in a hash table, significantly reducing search time.

---

## ✨ Features

- 📂 Index multiple text files
- 🔎 Fast word searching using Hash Tables
- 📄 Display files containing the searched word
- 🔢 Show occurrence count of each word
- 💾 Save indexed database to a file
- 📥 Reload saved database
- ✅ Duplicate file validation
- ⚡ Efficient collision handling using Linked Lists
- 🖥️ Menu-driven command-line interface

---

## 🛠️ Technologies Used

- C Programming
- Data Structures (Hash Tables, Linked Lists)
- File Handling
- Dynamic Memory Allocation
- Command-Line Programming
- GCC Compiler
- Linux

---

## 📁 Project Structure

```
Inverted_Search/
│
├── main.c
├── main.h
├── create_database.c
├── update_database.c
├── display_database.c
├── search_database.c
├── save_database.c
├── file_validation.c
├── makefile
├── sample_files/
│   ├── file1.txt
│   ├── file2.txt
│   └── file3.txt
└── README.md
```

---

## ⚙️ Working Principle

1. Read multiple text files.
2. Validate duplicate file names.
3. Extract every word from each file.
4. Generate a hash key based on the first character.
5. Store words in a hash table.
6. Handle collisions using linked lists.
7. Search words efficiently.
8. Save or reload the database when required.

---

## 📋 Menu Options

```
1. Create Database
2. Display Database
3. Search Word
4. Save Database
5. Update Database
6. Exit
```

---

## 📌 Sample Output

```
-------- MENU --------

1. Create Database
2. Display Database
3. Search Database
4. Save Database
5. Update Database
6. Exit

Enter your choice : 3

Enter the word : linux

Word Found

Word        : linux
File Count  : 2

File Name        Word Count
--------------------------------
file1.txt            4
file3.txt            2
```

---

## 💡 Key Challenges

- Implemented collision handling in Hash Tables using Linked Lists for efficient storage and retrieval.
- Managed dynamic indexing across multiple files while preventing duplicate entries and maintaining accurate occurrence counts.

---

## 📚 Key Learnings

- Strengthened understanding of Hash Tables and Linked Lists for efficient data indexing.
- Improved knowledge of File Handling, Dynamic Memory Allocation, and Search Algorithms in C.

---

## 🎯 Future Enhancements

- Case-insensitive searching
- Phrase searching
- Recursive directory indexing
- Stop-word removal
- Stemming support
- GUI version
- Multi-threaded indexing

---

## 👨‍💻 Author

**Gopalakrishna Telugu**

- GitHub: https://github.com/Gopalakrishna-30
- LinkedIn: https://www.linkedin.com/in/gopalakrishna-telugu

---

## ⭐ If you found this project useful, don't forget to Star ⭐ the repository!
