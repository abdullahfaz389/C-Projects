# C-Projects
Online Voting System (C++ – Console Based)  This project is a console-based Online Voting System developed in C++, designed to simulate a real-world voting process using core Data Structures and File Handling concepts. It ensures secure voter registration, controlled vote casting, and transparent result management.
Project Overview
The system allows eligible voters to register using valid CNIC and region information, cast votes through a managed queue, and ensures one-person-one-vote integrity.
All voter data, votes, and election results are stored persistently using text files.
Key Features
✅ Voter Registration
Validates Name, Age (18+), CNIC (13 digits), and Region
Prevents duplicate CNIC registrations
Stores registered voters in a Binary Search Tree (BST) for fast searching
Saves voter records in Register_voters.txt
🔍 Search, Update & Delete Voters
Search voters by CNIC
Update voter name or age (only if vote not cast)
Delete voters safely (blocked if vote already cast)
🧾 Voting Queue System
Uses Queue (Linked List) to manage voting requests
Only registered voters can enter the voting queue
Ensures FIFO voting order
🗳️ Vote Casting
Prevents multiple voting
Supports major political parties (PTI, PMLN, PP, JUI, MLQ, TLP)
Records every vote in VotesRecord.txt
📊 Results Management
Counts votes party-wise
Displays live results on console
Stores final results in Result.txt
📂 File Handling
Persistent storage for:
Registered voters
Votes cast
Final results
Reads and displays stored records anytime
🧠 Concepts Used
Binary Search Tree (BST)
Queue using Linked List
File Handling (ifstream / ofstream)
Input Validation
Recursion
Object-Oriented Programming (OOP)
🖥️ Technologies
Language: C++
Platform: Console Application
Compiler: GCC / MinGW / Any standard C++ compiler
🎯 Purpose
This project is ideal for:
Data Structures & Algorithms practice
OOP concepts
File handling projects
Academic / semester projects
👨‍💻 Author
Muhammad Abdullahfazal
Computer Science Student | C++ Programmer
