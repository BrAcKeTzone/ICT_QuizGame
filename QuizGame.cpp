#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

string playerName;

enum Difficulty {
  BEGINNER,
  INTERMEDIATE,
  EXPERT
};
enum Category {
  CS_FUNDAMENTALS,
  COMPUTER_PROGRAMMING,
  NETWORKING,
  PC_TROUBLESHOOTING,
  DATA_ANALYSIS,
  ALGORITHM,
  DATA_STRUCTURES,
  WEB_DEV
};

class Question {
  private:
  string question;
  vector < string > choices;
  char correctAnswer;
  Difficulty difficulty;
  Category category;

  public:
  Question(string q, vector < string > c, char correct, Difficulty diff, Category cat): question(q),
  choices(c),
  correctAnswer(correct),
  difficulty(diff),
  category(cat) {}

  void displayQuestion() {
    cout << "Category: ";
    switch (category) {
      case CS_FUNDAMENTALS:
        cout << "Fundamentals of Computer Science";
        break;
      case COMPUTER_PROGRAMMING:
        cout << "Computer programming (C++, C#, Python) ";
        break;
      case NETWORKING:
        cout << "Networking";
        break;
      case PC_TROUBLESHOOTING:
        cout << "PC Troubleshooting";
        break;
      case DATA_ANALYSIS:
        cout << "Data Analysis";
        break;
      case ALGORITHM:
        cout << "Algorithm";
        break;
      case DATA_STRUCTURES:
        cout << "Data Structures";
        break;
      case WEB_DEV:
        cout << "Web Development";
        break;
      default:
        cout << "invalid Selection";
        break;

    }
    cout << endl << "Difficulty: ";
    switch (difficulty) {
      case BEGINNER:
        cout << "Beginner";
        break;
      case INTERMEDIATE:
        cout << "Intermediate";
        break;
      case EXPERT:
        cout << "Expert";
        break;
      default:
        cout << "Invalid Selection";
        break;
    }
    cout << endl << endl << question << endl;
    for (int i = 0; i < choices.size(); ++i) {
      cout << static_cast<char > ('A' + i) << ") " << choices[i] << endl;
    }
  }

  bool checkAnswer(char userAnswer) {
    return toupper(userAnswer) == correctAnswer;
  }

  Category getCategory() {
    return category;
  }

  Difficulty getDifficulty() {
    return difficulty;
  }
};

void selectCategory(Category& chosenCategory) {
  char selectCategory;
  bool isValidCategory = false;
  
  cout << "Select category:\n"
          "1. Fundamentals of Computer Science\n"
          "2. Computer Programming (C++, C#, Python)\n"
          "3. Networking\n"
          "4. PC Troubleshooting\n"
          "5. Data Analysis\n"
          "6. Algorithm\n"
          "7. Data Structures\n"
          "8. Web Development\n";
  while (!isValidCategory) {
    cout << "Enter your choice (1-8): ";
    cin >> selectCategory;
    switch (selectCategory) {
      case '1':
        chosenCategory = CS_FUNDAMENTALS;
        isValidCategory = true;
        break;
      case '2':
        chosenCategory = COMPUTER_PROGRAMMING;
        isValidCategory = true;
        break;
      case '3':
        chosenCategory = NETWORKING;
        isValidCategory = true;
        break;
      case '4':
        chosenCategory = PC_TROUBLESHOOTING;
        isValidCategory = true;
        break;
      case '5':
        chosenCategory = DATA_ANALYSIS;
        isValidCategory = true;
        break;
      case '6':
        chosenCategory = ALGORITHM;
        isValidCategory = true;
        break;
      case '7':
        chosenCategory = DATA_STRUCTURES;
        isValidCategory = true;
        break;
      case '8':
        chosenCategory = WEB_DEV;
        isValidCategory = true;
        break;
      default:
        cout << "Invalid choice. Please enter a number between 1 and 8." << endl;
        break;
    }
  }
};

void selectDifficulty(Difficulty& chosenDifficulty){
  char selectDifficulty;
  bool isValidDifficulty = false;
  cout << "Select difficulty:\n"
          "1. Beginner\n"
          "2. Intermediate\n"
          "3. Expert\n";
  while (!isValidDifficulty) {
    cout << "Enter your choice (1-3): ";
    cin >> selectDifficulty;
    switch (selectDifficulty) {
      case '1':
      chosenDifficulty = BEGINNER;
      isValidDifficulty = true;
      break;
      case '2':
      chosenDifficulty = INTERMEDIATE;
      isValidDifficulty = true;
      break;
      case '3':
      chosenDifficulty = EXPERT;
      isValidDifficulty = true;
      break;
      default:
      cout << "Invalid choice. Please enter a number between 1 and 3." << endl;
      break;
    }
  }
};

int main() {
  vector < Question > allQuestions {
    Question("What is Computer Science?", {
      "Study of computers", "Study of ALGORITHM", "Study of programming languages", "All of the above"
    }, 'D', BEGINNER, CS_FUNDAMENTALS),
    Question("What is an algorithm?", {
      "A type of software", "A set of instructions to solve a problem", "A programming language", "A type of computer"
    }, 'B', BEGINNER, CS_FUNDAMENTALS),
    Question("What is the difference between high-level and low-level programming languages?", {
      "The speed of execution", "The level of abstraction from machine language", "The difficulty level of the language", "The popularity of the language"
    }, 'B', BEGINNER, CS_FUNDAMENTALS),
    Question("What is the role of an operating system in a computer?", {
      "Running applications", "Managing hardware resources", "Providing security", "All of the above"
    }, 'D', BEGINNER, CS_FUNDAMENTALS),
    Question("What is a data structure?", {
      "A way to store and organize data", "A type of algorithm", "A type of computer", "A type of software"
    }, 'A', BEGINNER, CS_FUNDAMENTALS),
    Question("What is the difference between a compiler and an interpreter?", {
      "A compiler translates the entire program before execution, while an interpreter translates one line at a time during execution", "A compiler is a type of data structure, while an interpreter is a type of algorithm", "A compiler is used for high-level languages, while an interpreter is used for low-level languages", "There is no difference"
    }, 'A', BEGINNER, CS_FUNDAMENTALS),
    Question("What is the concept of Object-Oriented Programming (OOP)?", {
      "Programming based on 'objects', which can contain data and code", "Programming based on a single, linear sequence of instructions", "Programming based on the use of multiple CPUs", "Programming based on the use of a single CPU"
    }, 'A', BEGINNER, CS_FUNDAMENTALS),
    Question("What is the binary number system?", {
      "A number system based on 10 digits", "A number system based on 2 digits", "A number system based on 16 digits", "A number system based on 8 digits"
    }, 'B', BEGINNER, CS_FUNDAMENTALS),
    Question("What is a database?", {
      "A collection of data organized in a manner that allows easy access, retrieval, and use of that data", "A type of programming language", "A type of operating system", "A type of algorithm"
    }, 'A', BEGINNER, CS_FUNDAMENTALS),
    Question("What is the Internet?", {
      "A large network of computers", "A type of database", "A type of programming language", "A type of algorithm"
    }, 'A', BEGINNER, CS_FUNDAMENTALS),

    Question("What is the purpose of an operating system?", {
      "To manage hardware resources and provide a user interface", "To execute programs and perform calculations", "To store and organize data", "Operating systems are not necessary for computers"
    }, 'A', INTERMEDIATE, CS_FUNDAMENTALS),
    Question("What is the difference between hardware and software?", {
      "Hardware refers to physical components, while software refers to programs and data", "Hardware and software are the same thing", "Hardware refers to software components, while software refers to physical components", "There is no difference between hardware and software"
    }, 'A', INTERMEDIATE, CS_FUNDAMENTALS),
    Question("What is the purpose of a programming language?", {
      "To write and execute computer programs", "To store and organize data", "To manage hardware resources", "Programming languages are not necessary for computers"
    }, 'A', INTERMEDIATE, CS_FUNDAMENTALS),
    Question("What is the difference between a compiler and an interpreter?", {
      "A compiler translates the entire program before execution, while an interpreter translates one line at a time during execution", "A compiler is used for high-level languages, while an interpreter is used for low-level languages", "A compiler and an interpreter perform the same function", "There is no difference between a compiler and an interpreter"
    }, 'A', INTERMEDIATE, CS_FUNDAMENTALS),
    Question("What is the purpose of a database?", {
      "To store and organize data in a structured manner", "To execute programs and perform calculations", "To manage hardware resources", "Databases are not necessary for computers"
    }, 'A', INTERMEDIATE, CS_FUNDAMENTALS),
    Question("What is the difference between RAM and hard drive storage?", {
      "RAM is volatile and faster, while hard drive storage is non-volatile and slower", "RAM is non-volatile and slower, while hard drive storage is volatile and faster", "RAM and hard drive storage are the same thing", "There is no difference between RAM and hard drive storage"
    }, 'A', INTERMEDIATE, CS_FUNDAMENTALS),
    Question("What is the purpose of a web browser?", {
      "To create and edit documents", "To browse and access websites on the internet", "To store and organize data", "Web browsers are not necessary for computers"
    }, 'B', INTERMEDIATE, CS_FUNDAMENTALS),
    Question("What is the difference between a function and a method in programming?", {
      "A function is a standalone unit of code, while a method is associated with an object", "A function is a type of data structure, while a method is a type of algorithm", "A function and a method perform the same function", "There is no difference between a function and a method"
    }, 'A', INTERMEDIATE, CS_FUNDAMENTALS),
    Question("What is the purpose of a firewall in computer networks?", {
      "To protect the network from unauthorized access and potential threats", "To store and organize data", "To manage hardware resources", "Firewalls are not necessary for computer networks"
    }, 'A', INTERMEDIATE, CS_FUNDAMENTALS),
    Question("What is the difference between a desktop computer and a laptop computer?", {
      "Desktop computers are larger and less portable, while laptop computers are smaller and more portable", "Desktop computers are more powerful than laptop computers", "Desktop computers and laptop computers are the same thing", "There is no difference between a desktop computer and a laptop computer"
    }, 'A', INTERMEDIATE, CS_FUNDAMENTALS),

    Question("What is the purpose of the A* algorithm?", {
      "To solve linear programming problems", "To find the shortest path in a graph", "To perform image recognition tasks", "A* algorithm is not used in computer science"
    }, 'B', EXPERT, CS_FUNDAMENTALS),
    Question("Which data structure is typically used to implement a Red-Black Tree?", {
      "Array", "Linked list", "Stack", "Balanced binary search tree"
    }, 'D', EXPERT, CS_FUNDAMENTALS),
    Question("What is the purpose of the CAP theorem in distributed systems?", {
      "To ensure consistency, availability, and partition tolerance", "To optimize network performance in distributed systems", "To prevent data corruption in distributed systems", "CAP theorem is not applicable to distributed systems"
    }, 'A', EXPERT, CS_FUNDAMENTALS),
    Question("What is the time complexity of the best algorithm for finding the longest common subsequence of two strings?", {
      "O(1)", "O(log n)", "O(n)", "O(n^2)"
    }, 'D', EXPERT, CS_FUNDAMENTALS),
    Question("What is the purpose of a Bloom filter?", {
      "To test the primality of a number", "To check if an element is present in a set", "To sort elements in a data structure", "To compress data for storage"
    }, 'B', EXPERT, CS_FUNDAMENTALS),
    Question("Which of the following is an example of a non-deterministic algorithm?", {
      "Depth-First Search (DFS)", "Breadth-First Search (BFS)", "Dijkstra's Algorithm", "Traveling Salesman Problem"
    }, 'D', EXPERT, CS_FUNDAMENTALS),
    Question("What is the purpose of memoization in dynamic programming?", {
      "To optimize program performance by caching intermediate results", "To ensure program correctness by checking for errors", "Memoization is not used in dynamic programming", "To parallelize computations in dynamic programming"
    }, 'A', EXPERT, CS_FUNDAMENTALS),
    Question("What is the difference between a Turing machine and a Finite State Machine (FSM)?", {
      "Turing machine can solve more complex problems than FSM", "Turing machine and FSM are the same thing", "FSM is a theoretical model, while Turing machine is a physical computer", "There is no difference between Turing machine and FSM"
    }, 'A', EXPERT, CS_FUNDAMENTALS),
    Question("What is the purpose of garbage collection in programming languages?", {
      "To reclaim memory that is no longer in use by the program", "To optimize program performance by reducing memory usage", "Garbage collection is not used in modern programming languages", "To prevent memory leaks in the program"
    }, 'A', EXPERT, CS_FUNDAMENTALS),
    Question("What is the difference between a compiler and an interpreter?", {
      "A compiler translates the entire program before execution, while an interpreter translates one line at a time during execution", "A compiler is used for high-level languages, while an interpreter is used for low-level languages", "A compiler and an interpreter perform the same function", "There is no difference between a compiler and an interpreter"
    }, 'A', EXPERT, CS_FUNDAMENTALS),

    Question("What is the purpose of a variable in programming?", {
      "To store and manipulate data", "To perform mathematical calculations", "To create loops and conditional statements", "Variables are not used in programming"
    }, 'A', BEGINNER, COMPUTER_PROGRAMMING),
    Question("What is the difference between a compiler and an interpreter?", {
      "A compiler translates the entire program before execution, while an interpreter translates one line at a time during execution", "A compiler is used for high-level languages, while an interpreter is used for low-level languages", "A compiler and an interpreter perform the same function", "There is no difference between a compiler and an interpreter"
    }, 'A', BEGINNER, COMPUTER_PROGRAMMING),
    Question("What is the purpose of a loop in programming?", {
      "To repeat a block of code multiple times", "To store and organize data", "To perform mathematical calculations", "Loops are not used in programming"
    }, 'A', BEGINNER, COMPUTER_PROGRAMMING),
    Question("What is the syntax for a single-line comment in Python?", {
      "// This is a comment", "/* This is a comment */", "# This is a comment", ""
    }, 'C', BEGINNER, COMPUTER_PROGRAMMING),
    Question("What is the purpose of a function in programming?", {
      "To perform a specific task or calculation", "To store and organize data", "To create loops and conditional statements", "Functions are not used in programming"
    }, 'A', BEGINNER, COMPUTER_PROGRAMMING),
    Question("What is the difference between a parameter and an argument in programming?", {
      "Parameters are used in function definitions, while arguments are the values passed into a function", "Parameters and arguments are the same thing", "Parameters are used in loops, while arguments are used in conditional statements", "There is no difference between a parameter and an argument"
    }, 'A', BEGINNER, COMPUTER_PROGRAMMING),
    Question("What is the purpose of conditional statements in programming?", {
      "To make decisions based on certain conditions", "To store and organize data", "To perform mathematical calculations", "Conditional statements are not used in programming"
    }, 'A', BEGINNER, COMPUTER_PROGRAMMING),
    Question("What is the syntax for declaring a variable in C++?", {
      "var x;", "int x;", "x = 5;", "variable x;"
    }, 'B', BEGINNER, COMPUTER_PROGRAMMING),
    Question("What is the purpose of an array in programming?", {
      "To store multiple values of the same data type", "To perform mathematical calculations", "To create loops and conditional statements", "Arrays are not used in programming"
    }, 'A', BEGINNER, COMPUTER_PROGRAMMING),
    Question("What is the purpose of an if-else statement in programming?", {
      "To perform different actions based on a condition", "To store and organize data", "To perform mathematical calculations", "If-else statements are not used in programming"
    }, 'A', BEGINNER, COMPUTER_PROGRAMMING),

    Question("What is the purpose of object-oriented programming (OOP)?", {
      "To write code that is easy to understand and maintain", "To improve program performance", "To create complex mathematical ALGORITHM", "Object-oriented programming is not used in modern programming languages"
    }, 'A', INTERMEDIATE, COMPUTER_PROGRAMMING),
    Question("What is the difference between a class and an object in object-oriented programming?", {
      "A class is a blueprint for creating objects, while an object is an instance of a class", "A class and an object are the same thing", "A class is a variable, while an object is a function", "There is no difference between a class and an object"
    }, 'A', INTERMEDIATE, COMPUTER_PROGRAMMING),
    Question("What is the purpose of inheritance in object-oriented programming?", {
      "To create new classes from existing classes", "To store and organize data", "To perform mathematical calculations", "Inheritance is not used in object-oriented programming"
    }, 'A', INTERMEDIATE, COMPUTER_PROGRAMMING),
    Question("What is the difference between a function and a method in programming?", {
      "A function is a standalone unit of code, while a method is associated with an object or class", "A function and a method are the same thing", "A function is used for mathematical calculations, while a method is used for data storage", "There is no difference between a function and a method"
    }, 'A', INTERMEDIATE, COMPUTER_PROGRAMMING),
    Question("What is the purpose of exception handling in programming?", {
      "To handle errors and prevent program crashes", "To improve program performance", "To create loops and conditional statements", "Exception handling is not necessary in programming"
    }, 'A', INTERMEDIATE, COMPUTER_PROGRAMMING),
    Question("What is the difference between pass by value and pass by reference in function parameter passing?", {
      "Pass by value creates a copy of the value, while pass by reference uses the original value", "Pass by value and pass by reference are the same thing", "Pass by value is used for integers, while pass by reference is used for strings", "There is no difference between pass by value and pass by reference"
    }, 'A', INTERMEDIATE, COMPUTER_PROGRAMMING),
    Question("What is the purpose of a pointer in C++ programming?", {
      "To store memory addresses", "To perform mathematical calculations", "To create loops and conditional statements", "Pointers are not used in C++ programming"
    }, 'A', INTERMEDIATE, COMPUTER_PROGRAMMING),
    Question("What is the difference between a stack and a heap in memory management?", {
      "Stack is used for static memory allocation, while heap is used for dynamic memory allocation", "Stack and heap are the same thing", "Stack is used for dynamic memory allocation, while heap is used for static memory allocation", "There is no difference between a stack and a heap in memory management"
    }, 'A', INTERMEDIATE, COMPUTER_PROGRAMMING),
    Question("What is the purpose of a try-catch block in exception handling?", {
      "To try out a piece of code and catch any exceptions that occur", "To perform mathematical calculations", "To create loops and conditional statements", "Try-catch blocks are not used in exception handling"
    }, 'A', INTERMEDIATE, COMPUTER_PROGRAMMING),
    Question("What is the purpose of recursion in programming?", {
      "To solve complex problems by breaking them down into smaller, similar subproblems", "To store and organize data", "To perform mathematical calculations", "Recursion is not used in programming"
    }, 'A', INTERMEDIATE, COMPUTER_PROGRAMMING),

    Question("What is the purpose of a lambda function in programming?", {
      "To create anonymous functions", "To perform mathematical calculations", "To store and organize data", "Lambda functions are not used in programming"
    }, 'A', EXPERT, COMPUTER_PROGRAMMING),
    Question("What is the difference between procedural programming and object-oriented programming?", {
      "Procedural programming focuses on procedures and functions, while object-oriented programming focuses on objects and classes", "Procedural programming and object-oriented programming are the same thing", "Procedural programming is used for low-level languages, while object-oriented programming is used for high-level languages", "There is no difference between procedural programming and object-oriented programming"
    }, 'A', EXPERT, COMPUTER_PROGRAMMING),
    Question("What is the purpose of a design pattern in software development?", {
      "To provide reusable solutions to common programming problems", "To perform complex mathematical calculations", "To store and organize data", "Design patterns are not used in software development"
    }, 'A', EXPERT, COMPUTER_PROGRAMMING),
    Question("What is the difference between static typing and dynamic typing in programming languages?", {
      "Static typing requires explicit declaration of variable types, while dynamic typing infers variable types at runtime", "Static typing and dynamic typing are the same thing", "Static typing is used for interpreted languages, while dynamic typing is used for compiled languages", "There is no difference between static typing and dynamic typing"
    }, 'A', EXPERT, COMPUTER_PROGRAMMING),
    Question("What is the purpose of a closure in programming?", {
      "To encapsulate data and functions together", "To perform mathematical calculations", "To store and organize data", "Closures are not used in programming"
    }, 'A', EXPERT, COMPUTER_PROGRAMMING),
    Question("What is the difference between a shallow copy and a deep copy in object cloning?", {
      "A shallow copy creates a new object with references to the original object's data, while a deep copy creates a new object with its own copy of the original object's data", "A shallow copy and a deep copy are the same thing", "A shallow copy creates a new object with its own copy of the original object's data, while a deep copy creates a new object with references to the original object's data", "There is no difference between a shallow copy and a deep copy in object cloning"
    }, 'A', EXPERT, COMPUTER_PROGRAMMING),
    Question("What is the purpose of multithreading in programming?", {
      "To achieve concurrency and improve program performance", "To perform complex mathematical calculations", "To store and organize data", "Multithreading is not used in programming"
    }, 'A', EXPERT, COMPUTER_PROGRAMMING),
    Question("What is the difference between stack memory and heap memory in memory management?", {
      "Stack memory is used for static memory allocation, while heap memory is used for dynamic memory allocation", "Stack memory and heap memory are the same thing", "Stack memory is used for dynamic memory allocation, while heap memory is used for static memory allocation", "There is no difference between stack memory and heap memory in memory management"
    }, 'A', EXPERT, COMPUTER_PROGRAMMING),
    Question("What is the purpose of a virtual function in object-oriented programming?", {
      "To achieve polymorphism and enable function overriding", "To perform mathematical calculations", "To store and organize data", "Virtual functions are not used in object-oriented programming"
    }, 'A', EXPERT, COMPUTER_PROGRAMMING),
    Question("What is the purpose of a template in C++ programming?", {
      "To create generic functions and classes that can work with different data types", "To perform complex mathematical calculations", "To store and organize data", "Templates are not used in C++ programming"
    }, 'A', EXPERT, COMPUTER_PROGRAMMING),

    Question("What is the purpose of an IP address in computer networking?", {
      "To identify a specific device on a network", "To establish a secure connection between devices", "To determine the physical location of a device", "IP addresses are not used in computer networking"
    }, 'A', BEGINNER, NETWORKING),
    Question("What is the function of a router in a computer network?", {
      "To connect devices within a local area network (LAN)", "To connect multiple networks together", "To provide wireless connectivity to devices", "Routers are not used in computer networks"
    }, 'B', BEGINNER, NETWORKING),
    Question("Which protocol is commonly used for sending and receiving emails?", {
      "HTTP", "FTP", "SMTP", "TCP"
    }, 'C', BEGINNER, NETWORKING),
    Question("What is the purpose of DNS (Domain Name System) in computer networking?", {
      "To secure network connections", "To convert domain names to IP addresses", "To establish peer-to-peer connections", "DNS is not used in computer networking"
    }, 'B', BEGINNER, NETWORKING),
    Question("What is the difference between TCP (Transmission Control Protocol) and UDP (User Datagram Protocol)?", {
      "TCP provides reliable, ordered, and error-checked delivery of data, while UDP does not guarantee reliable delivery", "TCP is used for video streaming, while UDP is used for web browsing", "TCP and UDP are the same protocol", "There is no difference between TCP and UDP"
    }, 'A', BEGINNER, NETWORKING),
    Question("What is the purpose of a firewall in computer networking?", {
      "To protect a network from unauthorized access and potential threats", "To convert IP addresses to domain names", "To establish secure connections between devices", "Firewalls are not used in computer networking"
    }, 'A', BEGINNER, NETWORKING),
    Question("Which protocol is commonly used for accessing websites over the internet?", {
      "FTP", "HTTP", "SMTP", "TCP"
    }, 'B', BEGINNER, NETWORKING),
    Question("What is the purpose of NAT (Network Address Translation) in computer networking?", {
      "To convert domain names to IP addresses", "To establish secure connections between devices", "To translate private IP addresses to public IP addresses", "NAT is not used in computer networking"
    }, 'C', BEGINNER, NETWORKING),
    Question("Which network topology connects all devices in a linear fashion?", {
      "Star topology", "Bus topology", "Ring topology", "Mesh topology"
    }, 'B', BEGINNER, NETWORKING),
    Question("What is the purpose of a subnet mask in computer networking?", {
      "To identify the network portion of an IP address", "To convert IP addresses to domain names", "To establish secure connections between devices", "Subnet masks are not used in computer networking"
    }, 'A', BEGINNER, NETWORKING),

    Question("What is the purpose of a MAC address in computer networking?", {
      "To identify a specific device on a network", "To establish a secure connection between devices", "To determine the physical location of a device", "MAC addresses are not used in computer networking"
    }, 'A', INTERMEDIATE, NETWORKING),
    Question("What is the function of a switch in a computer network?", {
      "To connect devices within a local area network (LAN)", "To connect multiple networks together", "To provide wireless connectivity to devices", "Switches are not used in computer networks"
    }, 'A', INTERMEDIATE, NETWORKING),
    Question("Which protocol is commonly used for transferring files between computers over a network?", {
      "HTTP", "FTP", "SMTP", "TCP"
    }, 'B', INTERMEDIATE, NETWORKING),
    Question("What is the purpose of a subnet in computer networking?", {
      "To divide a network into smaller, manageable segments", "To convert IP addresses to domain names", "To establish secure connections between devices", "Subnets are not used in computer networking"
    }, 'A', INTERMEDIATE, NETWORKING),
    Question("What is the difference between a hub and a switch in computer networking?", {
      "A hub broadcasts data to all connected devices, while a switch forwards data only to the intended recipient", "A hub and a switch perform the same function", "A hub is used for wired connections, while a switch is used for wireless connections", "There is no difference between a hub and a switch"
    }, 'A', INTERMEDIATE, NETWORKING),
    Question("What is the purpose of a default gateway in computer networking?", {
      "To connect two or more networks together", "To convert IP addresses to domain names", "To establish secure connections between devices", "Default gateways are not used in computer networking"
    }, 'A', INTERMEDIATE, NETWORKING),
    Question("Which protocol is commonly used for sending and receiving emails?", {
      "HTTP", "FTP", "SMTP", "TCP"
    }, 'C', INTERMEDIATE, NETWORKING),
    Question("What is the purpose of a VLAN (Virtual Local Area Network) in computer networking?", {
      "To logically divide a single physical network into multiple virtual networks", "To convert IP addresses to domain names", "To establish secure connections between devices", "VLANs are not used in computer networking"
    }, 'A', INTERMEDIATE, NETWORKING),
    Question("Which network topology connects all devices in a ring-like structure?", {
      "Star topology", "Bus topology", "Ring topology", "Mesh topology"
    }, 'C', INTERMEDIATE, NETWORKING),
    Question("What is the purpose of a proxy server in computer networking?", {
      "To act as an intermediary between a client and a server", "To convert IP addresses to domain names", "To establish secure connections between devices", "Proxy servers are not used in computer networking"
    }, 'A', INTERMEDIATE, NETWORKING),

    Question("What is the purpose of a subnet mask in computer networking?", {
      "To identify the network portion of an IP address", "To convert IP addresses to domain names", "To establish secure connections between devices", "Subnet masks are not used in computer networking"
    }, 'A', EXPERT, NETWORKING),
    Question("What is the difference between TCP (Transmission Control Protocol) and UDP (User Datagram Protocol)?", {
      "TCP provides reliable, ordered, and error-checked delivery of data, while UDP does not guarantee reliable delivery", "TCP is used for video streaming, while UDP is used for web browsing", "TCP and UDP are the same protocol", "There is no difference between TCP and UDP"
    }, 'A', EXPERT, NETWORKING),
    Question("What is the purpose of a DNS (Domain Name System) server in computer networking?", {
      "To convert domain names to IP addresses", "To establish secure connections between devices", "To perform load balancing for web traffic", "DNS servers are not used in computer networking"
    }, 'A', EXPERT, NETWORKING),
    Question("What is the difference between static routing and dynamic routing in networking?", {
      "Static routing requires manual configuration of routing tables, while dynamic routing uses protocols to automatically update routing information", "Static routing and dynamic routing are the same thing", "Static routing is used for wired networks, while dynamic routing is used for wireless networks", "There is no difference between static routing and dynamic routing"
    }, 'A', EXPERT, NETWORKING),
    Question("What is the purpose of a VPN (Virtual Private Network) in computer networking?", {
      "To establish secure connections over a public network", "To convert IP addresses to domain names", "To perform load balancing for web traffic", "VPNs are not used in computer networking"
    }, 'A', EXPERT, NETWORKING),
    Question("What is the difference between a stateful firewall and a stateless firewall?", {
      "A stateful firewall tracks the state of network connections, while a stateless firewall does not keep track of connection information", "A stateful firewall and a stateless firewall perform the same function", "A stateful firewall is used for wired networks, while a stateless firewall is used for wireless networks", "There is no difference between a stateful firewall and a stateless firewall"
    }, 'A', EXPERT, NETWORKING),
    Question("What is the purpose of NAT (Network Address Translation) in computer networking?", {
      "To translate private IP addresses to public IP addresses", "To convert IP addresses to domain names", "To establish secure connections between devices", "NAT is not used in computer networking"
    }, 'A', EXPERT, NETWORKING),
    Question("What is the function of an IDS (Intrusion Detection System) in computer networking?", {
      "To detect and prevent unauthorized access and attacks on a network", "To convert IP addresses to domain names", "To perform load balancing for web traffic", "IDS is not used in computer networking"
    }, 'A', EXPERT, NETWORKING),
    Question("What is the purpose of a load balancer in computer networking?", {
      "To distribute network traffic evenly across multiple servers", "To convert IP addresses to domain names", "To establish secure connections between devices", "Load balancers are not used in computer networking"
    }, 'A', EXPERT, NETWORKING),
    Question("What is the difference between a hub, a switch, and a router in computer networking?", {
      "A hub is a simple device that broadcasts data to all connected devices, a switch forwards data only to the intended recipient, and a router connects multiple networks together", "A hub, a switch, and a router perform the same function", "A hub is used for wired connections, a switch is used for wireless connections, and a router is used for both wired and wireless connections", "There is no difference between a hub, a switch, and a router in computer networking"
    }, 'A', EXPERT, NETWORKING),

    Question("Which of the following is a common cause of a computer not turning on?", {
      "Overheating", "Corrupted operating system", "Faulty power supply", "Insufficient RAM"
    }, 'C', BEGINNER, PC_TROUBLESHOOTING),
    Question("What is the purpose of a BIOS?", {
      "To control the flow of data between the CPU and other hardware components", "To provide a user interface for interacting with the operating system", "To store configuration settings for the computer's hardware", "To manage the computer's memory allocation"
    }, 'C', BEGINNER, PC_TROUBLESHOOTING),
    Question("A computer is experiencing frequent crashes and freezes. Which of the following could be the cause?", {
      "Faulty hard drive", "Outdated drivers", "Insufficient power supply", "Overheating"
    }, 'B', BEGINNER, PC_TROUBLESHOOTING),
    Question("What should you do if a computer is displaying a 'No bootable device' error?", {
      "Check the power cable connections", "Reinstall the operating system", "Replace the hard drive", "Check the boot order in the BIOS"
    }, 'D', BEGINNER, PC_TROUBLESHOOTING),
    Question("Which of the following is a symptom of a failing graphics card?", {
      "Blue screen of death (BSOD)", "Distorted or flickering display", "Slow performance", "Random restarts"
    }, 'B', BEGINNER, PC_TROUBLESHOOTING),
    Question("What is the purpose of running a disk cleanup utility?", {
      "To remove unnecessary files and free up disk space", "To scan for and fix errors on the hard drive", "To defragment the hard drive for better performance", "To update the operating system with the latest patches"
    }, 'A', BEGINNER, PC_TROUBLESHOOTING),
    Question("What should you do if a computer is experiencing slow internet speeds?", {
      "Upgrade the modem/router", "Clear the browser cache", "Restart the computer", "Contact the internet service provider (ISP)"
    }, 'B', BEGINNER, PC_TROUBLESHOOTING),
    Question("Which of the following is a sign of a failing power supply?", {
      "Random shutdowns or restarts", "Loud grinding noise", "Slow boot times", "Blue screen of death (BSOD)"
    }, 'A', BEGINNER, PC_TROUBLESHOOTING),
    Question("What should you do if a computer is overheating?", {
      "Install additional case fans", "Clean the dust from the cooling fans and heat sinks", "Replace the thermal paste on the CPU", "All of the above"
    }, 'D', BEGINNER, PC_TROUBLESHOOTING),
    Question("What is the purpose of running a malware scan on a computer?", {
      "To remove viruses and other malicious software", "To optimize the computer's performance", "To update the operating system", "To backup important files"
    }, 'A', BEGINNER, PC_TROUBLESHOOTING),

    Question("What could be the cause of a computer randomly restarting?", {
      "Overheating", "Faulty RAM", "Outdated drivers", "Corrupted operating system"
    }, 'A', INTERMEDIATE, PC_TROUBLESHOOTING),
    Question("What should you do if a computer is displaying a 'blue screen of death' (BSOD) error?", {
      "Restart the computer", "Update the operating system", "Check for hardware compatibility issues", "Run a memory diagnostic test"
    }, 'D', INTERMEDIATE, PC_TROUBLESHOOTING),
    Question("A computer is experiencing slow performance. Which of the following could be the cause?", {
      "Insufficient RAM", "Fragmented hard drive", "Outdated BIOS", "Malware infection"
    }, 'A', INTERMEDIATE, PC_TROUBLESHOOTING),
    Question("What should you do if a computer is not connecting to a Wi-Fi network?", {
      "Restart the router", "Update the wireless adapter drivers", "Reset the network settings", "Check for MAC address filtering"
    }, 'B', INTERMEDIATE, PC_TROUBLESHOOTING),
    Question("Which of the following is a symptom of a failing hard drive?", {
      "Clicking noise", "Slow boot times", "File system errors", "All of the above"
    }, 'D', INTERMEDIATE, PC_TROUBLESHOOTING),
    Question("What is the purpose of running a disk defragmentation?", {
      "To optimize the hard drive's performance", "To remove temporary files", "To scan for and fix disk errors", "To update the operating system"
    }, 'A', INTERMEDIATE, PC_TROUBLESHOOTING),
    Question("What should you do if a computer is not recognizing a USB device?", {
      "Check the USB port for physical damage", "Update the USB drivers", "Test the device on another computer", "All of the above"
    }, 'D', INTERMEDIATE, PC_TROUBLESHOOTING),
    Question("What should you do if a computer is not displaying anything on the monitor?", {
      "Check the monitor cable connections", "Test the monitor on another computer", "Reset the BIOS settings to default", "All of the above"
    }, 'D', INTERMEDIATE, PC_TROUBLESHOOTING),
    Question("Which of the following is a sign of a failing CPU?", {
      "System freezes or crashes", "High CPU temperature", "Slow processing speed", "All of the above"
    }, 'D', INTERMEDIATE, PC_TROUBLESHOOTING),
    Question("What should you do if a computer is experiencing frequent software crashes?", {
      "Update the operating system", "Reinstall the software", "Check for conflicting programs", "Run a system file checker scan"
    }, 'C', INTERMEDIATE, PC_TROUBLESHOOTING),

    Question("What could be the cause of a computer failing to boot and displaying a 'CMOS checksum error'?", {
      "Faulty motherboard", "Corrupted BIOS firmware", "Incompatible RAM", "Overclocking settings"
    }, 'B', EXPERT, PC_TROUBLESHOOTING),
    Question("A computer is experiencing intermittent power issues. Which component is most likely causing the problem?", {
      "Power supply", "Motherboard", "CPU", "Graphics card"
    }, 'A', EXPERT, PC_TROUBLESHOOTING),
    Question("What should you do if a computer is not recognizing any connected USB devices?", {
      "Check the USB port for physical damage", "Update the USB controller drivers", "Test the devices on another computer", "Check the motherboard for faulty USB ports"
    }, 'D', EXPERT, PC_TROUBLESHOOTING),
    Question("Which of the following could be the cause of a computer freezing during intense gaming sessions?", {
      "Overheating CPU", "Insufficient power supply", "Outdated graphics card drivers", "Faulty RAM modules"
    }, 'A', EXPERT, PC_TROUBLESHOOTING),
    Question("What should you do if a computer is experiencing frequent and sudden shutdowns?", {
      "Check the CPU temperature", "Test the power supply with a multimeter", "Update the BIOS firmware", "Replace the motherboard"
    }, 'A', EXPERT, PC_TROUBLESHOOTING),
    Question("A computer is displaying distorted or garbled graphics on the screen. Which component is most likely causing the issue?", {
      "Graphics card", "Monitor", "RAM", "CPU"
    }, 'A', EXPERT, PC_TROUBLESHOOTING),
    Question("What should you do if a computer is not outputting any audio?", {
      "Check the speaker connections", "Update the audio drivers", "Test the speakers on another device", "Check the sound settings in the operating system"
    }, 'D', EXPERT, PC_TROUBLESHOOTING),
    Question("Which of the following could be the cause of a computer not booting and displaying a 'disk boot failure' error?", {
      "Corrupted boot sector", "Faulty hard drive controller", "Incompatible operating system", "Virus infection"
    }, 'A', EXPERT, PC_TROUBLESHOOTING),
    Question("What should you do if a computer is experiencing frequent and unexpected system crashes?", {
      "Test the RAM modules with a memory diagnostic tool", "Update the device drivers", "Check for overheating components", "Perform a clean reinstall of the operating system"
    }, 'C', EXPERT, PC_TROUBLESHOOTING),
    
Question("What is Data Analysis?", {"Sorting data alphabetically", "Extracting useful information from data", "Storing data in a database", "Deleting unnecessary data"}, 'B', BEGINNER, DATA_ANALYSIS),
    Question("Which of the following is NOT a step in the Data Analysis process?", {"Data Collection", "Data Visualization", "Data Encryption", "Data Interpretation"}, 'C', BEGINNER, DATA_ANALYSIS),
    Question("What is the purpose of Data Cleaning in Data Analysis?", {"To make data look visually appealing", "To remove errors and inconsistencies from data", "To increase the size of the dataset", "To encrypt the data for security"}, 'B', BEGINNER, DATA_ANALYSIS),
    Question("Which programming language is commonly used for Data Analysis?", {"Java", "Python", "C++", "Ruby"}, 'B', BEGINNER, DATA_ANALYSIS),
    Question("What is the role of Data Visualization in Data Analysis?", {"To make data easier to understand through charts and graphs", "To hide data from unauthorized users", "To increase the size of the dataset", "To encrypt the data for security"}, 'A', BEGINNER, DATA_ANALYSIS),
    Question("Which of the following is a popular tool for Data Analysis and visualization?", {"Photoshop", "Microsoft Word", "Tableau", "Notepad"}, 'C', BEGINNER, DATA_ANALYSIS),
    Question("What is the purpose of Statistical Analysis in Data Analysis?", {"To make data look visually appealing", "To predict future trends based on historical data", "To increase the size of the dataset", "To encrypt the data for security"}, 'B', BEGINNER, DATA_ANALYSIS),
    Question("What is Machine Learning in the context of Data Analysis?", {"Teaching computers to learn from data and make decisions", "Manually analyzing data without any tools", "Deleting unnecessary data", "Sorting data alphabetically"}, 'A', BEGINNER, DATA_ANALYSIS),
    Question("What is the difference between Descriptive and Inferential Statistics?", {"Descriptive Statistics summarize data, while Inferential Statistics make predictions", "Descriptive Statistics predict future trends, while Inferential Statistics summarize data", "Descriptive Statistics analyze text data, while Inferential Statistics analyze numerical data", "Descriptive Statistics encrypt data, while Inferential Statistics decrypt data"}, 'A', BEGINNER, DATA_ANALYSIS),
    Question("What is the importance of Data Analysis in decision-making processes?", {"It helps in making decisions based on gut feelings", "It provides insights and trends to support informed decisions", "It increases the complexity of decision-making", "It decreases the accuracy of decision-making"}, 'B', BEGINNER, DATA_ANALYSIS),

    Question("What is the purpose of Exploratory Data Analysis (EDA) in Data Analysis?", {"To make data look visually appealing", "To summarize the main characteristics of the data", "To delete unnecessary data", "To encrypt the data for security"}, 'B', INTERMEDIATE, DATA_ANALYSIS),
    Question("What is the difference between Qualitative and Quantitative Data in Data Analysis?", {"Qualitative data is numerical, while Quantitative data is categorical", "Qualitative data is categorical, while Quantitative data is numerical", "Qualitative data is encrypted, while Quantitative data is not", "Qualitative data is visual, while Quantitative data is textual"}, 'B', INTERMEDIATE, DATA_ANALYSIS),
    Question("Which of the following is NOT a common Data Analysis technique?", {"Regression Analysis", "Cluster Analysis", "Data Encryption", "Time Series Analysis"}, 'C', INTERMEDIATE, DATA_ANALYSIS),
    Question("What is the purpose of Hypothesis Testing in Data Analysis?", {"To prove a theory correct", "To determine if there is a significant difference between groups", "To increase the size of the dataset", "To encrypt the data for security"}, 'B', INTERMEDIATE, DATA_ANALYSIS),
    Question("What is the role of Data Mining in Data Analysis?", {"To extract patterns and knowledge from large datasets", "To delete unnecessary data", "To increase the size of the dataset", "To encrypt the data for security"}, 'A', INTERMEDIATE, DATA_ANALYSIS),
    Question("What is the purpose of Data Transformation in Data Analysis?", {"To make data look visually appealing", "To convert data into a suitable format for analysis", "To delete unnecessary data", "To encrypt the data for security"}, 'B', INTERMEDIATE, DATA_ANALYSIS),
    Question("Which of the following is NOT a common Data Analysis tool?", {"R", "Excel", "Photoshop", "MATLAB"}, 'C', INTERMEDIATE, DATA_ANALYSIS),
    Question("What is the significance of Correlation Analysis in Data Analysis?", {"It helps in predicting future trends", "It measures the relationship between variables", "It increases the size of the dataset", "It encrypts the data for security"}, 'B', INTERMEDIATE, DATA_ANALYSIS),
    Question("What is the purpose of Data Sampling in Data Analysis?", {"To analyze the entire dataset", "To select a subset of data for analysis", "To increase the size of the dataset", "To encrypt the data for security"}, 'B', INTERMEDIATE, DATA_ANALYSIS),
    Question("What is the importance of Data Analysis in business decision-making?", {"It leads to random decision-making", "It provides insights for informed and strategic decisions", "It decreases the complexity of decision-making", "It increases the risk of decision-making"}, 'B', INTERMEDIATE, DATA_ANALYSIS),
    
    Question("What is the purpose of Principal Component Analysis (PCA) in Data Analysis?", {"To summarize and reduce the dimensionality of data", "To increase the complexity of the dataset", "To encrypt the data for security", "To visualize data in 3D space"}, 'A', EXPERT, DATA_ANALYSIS),
    Question("Which of the following is a common technique for outlier detection in Data Analysis?", {"Mean Imputation", "Z-score method", "Data Encryption", "Data Augmentation"}, 'B', EXPERT, DATA_ANALYSIS),
    Question("What is the purpose of Cross-Validation in Data Analysis?", {"To split the data into training and testing sets", "To validate the model's performance on unseen data", "To increase the size of the dataset", "To encrypt the data for security"}, 'B', EXPERT, DATA_ANALYSIS),
    Question("What is the significance of Feature Engineering in Machine Learning and Data Analysis?", {"To create new features from existing data for model improvement", "To delete unnecessary features from the dataset", "To visualize data in high dimensions", "To encrypt the data for security"}, 'A', EXPERT, DATA_ANALYSIS),
    Question("Which statistical test is appropriate for comparing means of two independent groups in Data Analysis?", {"ANOVA", "t-test", "Chi-square test", "Regression analysis"}, 'B', EXPERT, DATA_ANALYSIS),
    Question("What is the role of Natural Language Processing (NLP) in Data Analysis?", {"To analyze and extract insights from text data", "To increase the size of the dataset", "To encrypt the data for security", "To visualize data in textual format"}, 'A', EXPERT, DATA_ANALYSIS),
    Question("What is the purpose of Time Series Analysis in Data Analysis?", {"To analyze data collected over time to extract trends and patterns", "To sort data chronologically", "To increase the size of the dataset", "To encrypt the data for security"}, 'A', EXPERT, DATA_ANALYSIS),
    Question("Which of the following is NOT a common clustering algorithm in Data Analysis?", {"K-means", "Hierarchical clustering", "Support Vector Machine (SVM)", "DBSCAN"}, 'C', EXPERT, DATA_ANALYSIS),
    Question("What is the purpose of Ensemble Learning in Machine Learning and Data Analysis?", {"To combine multiple models for improved predictive performance", "To analyze data in isolation", "To increase the size of the dataset", "To encrypt the data for security"}, 'A', EXPERT, DATA_ANALYSIS),
    Question("What is the importance of Data Governance in Data Analysis processes?", {"To ensure data quality, security, and compliance", "To increase the complexity of data analysis", "To decrease the accuracy of predictions", "To encrypt the data for security"}, 'A', EXPERT, DATA_ANALYSIS),

    Question("What is an algorithm in computer science?", {"A type of computer hardware", "A step-by-step procedure for solving a problem", "A programming language", "A computer network protocol"}, 'B', BEGINNER, ALGORITHM),
    Question("Which of the following is NOT a characteristic of a good algorithm?", {"Efficiency", "Accuracy", "Complexity", "Simplicity"}, 'C', BEGINNER, ALGORITHM),
    Question("What is the purpose of analyzing the time complexity of an algorithm?", {"To determine the physical size of the algorithm", "To measure the amount of memory the algorithm uses", "To analyze how the running time of the algorithm grows with input size", "To determine the color of the algorithm"}, 'C', BEGINNER, ALGORITHM),
    Question("Which of the following data structures is commonly used in sorting ALGORITHM?", {"Stack", "Queue", "Array", "Tree"}, 'C', BEGINNER, ALGORITHM),
    Question("What is the role of iteration in ALGORITHM?", {"It represents the input data", "It defines the output of the algorithm", "It allows the algorithm to repeat a set of instructions", "It encrypts the algorithm for security"}, 'C', BEGINNER, ALGORITHM),
    Question("Which sorting algorithm has a worst-case time complexity of O(n^2)?", {"Merge Sort", "Quick Sort", "Bubble Sort", "Insertion Sort"}, 'C', BEGINNER, ALGORITHM),
    Question("What is the purpose of recursion in ALGORITHM?", {"To make the algorithm run faster", "To make the algorithm more complex", "To break down a problem into smaller, similar subproblems", "To encrypt the algorithm for security"}, 'C', BEGINNER, ALGORITHM),
    Question("Which of the following is a searching algorithm?", {"Bubble Sort", "Binary Search", "Selection Sort", "Insertion Sort"}, 'B', BEGINNER, ALGORITHM),
    Question("What does the term 'Big O notation' represent in ALGORITHM?", {"The size of the algorithm", "The running time of the algorithm", "The color of the algorithm", "The shape of the algorithm"}, 'B', BEGINNER, ALGORITHM),
    Question("What is the purpose of algorithm analysis in computer science?", {"To make ALGORITHM more complex", "To evaluate the efficiency and performance of ALGORITHM", "To determine the programming language of the algorithm", "To encrypt the algorithm for security"}, 'B', BEGINNER, ALGORITHM),

    Question("What is the difference between Greedy and Dynamic Programming ALGORITHM?", {"Greedy ALGORITHM always provide optimal solutions, while Dynamic Programming ALGORITHM may not", "Dynamic Programming ALGORITHM always provide optimal solutions, while Greedy ALGORITHM may not", "Greedy ALGORITHM are faster than Dynamic Programming ALGORITHM", "Greedy ALGORITHM are more memory-efficient than Dynamic Programming ALGORITHM"}, 'A', INTERMEDIATE, ALGORITHM),
    Question("Which of the following is a characteristic of Divide and Conquer ALGORITHM?", {"They do not break down the problem into smaller subproblems", "They solve the problem directly without recursion", "They combine the solutions of the subproblems to solve the main problem", "They do not use recursion"}, 'C', INTERMEDIATE, ALGORITHM),
    Question("What is the purpose of Backtracking in ALGORITHM?", {"To optimize the algorithm for speed", "To solve constraint satisfaction problems by exploring all possible solutions", "To encrypt the algorithm for security", "To break down the problem into smaller subproblems"}, 'B', INTERMEDIATE, ALGORITHM),
    Question("Which of the following is a common sorting algorithm with a worst-case time complexity of O(n log n)?", {"Bubble Sort", "Merge Sort", "Selection Sort", "Insertion Sort"}, 'B', INTERMEDIATE, ALGORITHM),
    Question("What is the significance of the Master Theorem in algorithm analysis?", {"It helps analyze the time complexity of recursive ALGORITHM", "It determines the best algorithm for a specific problem", "It encrypts the algorithm for security", "It measures the physical size of the algorithm"}, 'A', INTERMEDIATE, ALGORITHM),
    Question("Which of the following is a common graph traversal algorithm?", {"Bubble Sort", "Depth-First Search (DFS)", "Quick Sort", "Insertion Sort"}, 'B', INTERMEDIATE, ALGORITHM),
    Question("What is the purpose of Memoization in Dynamic Programming?", {"To optimize the algorithm for speed", "To store and reuse computed results to avoid redundant calculations", "To encrypt the algorithm for security", "To break down the problem into smaller subproblems"}, 'B', INTERMEDIATE, ALGORITHM),
    Question("Which of the following is NOT a common hashing algorithm?", {"MD5", "SHA-256", "Bubble Sort", "CRC32"}, 'C', INTERMEDIATE, ALGORITHM),
    Question("What is the significance of the P vs. NP problem in computational complexity theory?", {"It determines the best algorithm for a specific problem", "It explores the relationship between polynomial and non-polynomial time ALGORITHM", "It encrypts ALGORITHM for security", "It measures the physical size of ALGORITHM"}, 'B', INTERMEDIATE, ALGORITHM),
    Question("What is the purpose of Heuristic ALGORITHM in problem-solving?", {"To provide optimal solutions for complex problems", "To find approximate solutions in a reasonable time", "To encrypt ALGORITHM for security", "To break down the problem into smaller subproblems"}, 'B', INTERMEDIATE, ALGORITHM),

    Question("What is the significance of the Halting Problem in the theory of computation?", {"It proves the existence of an algorithm that can solve any computational problem", "It demonstrates that not all problems can be solved algorithmically", "It defines the computational complexity of ALGORITHM", "It encrypts ALGORITHM for security"}, 'B', EXPERT, ALGORITHM),
    Question("Which of the following is a common algorithm for finding the shortest path in a graph with non-negative edge weights?", {"Dijkstra's algorithm", "Bellman-Ford algorithm", "Floyd-Warshall algorithm", "Prim's algorithm"}, 'A', EXPERT, ALGORITHM),
    Question("What is the purpose of Network Flow ALGORITHM in graph theory?", {"To find the maximum flow in a network", "To encrypt network data for security", "To optimize network routing", "To visualize network connections"}, 'A', EXPERT, ALGORITHM),
    Question("Which of the following is a common algorithm for solving the traveling salesman problem (TSP)?", {"Prim's algorithm", "Kruskal's algorithm", "Genetic algorithm", "A* algorithm"}, 'C', EXPERT, ALGORITHM),
    Question("What is the significance of NP-complete problems in computational complexity theory?", {"They are the easiest problems to solve in polynomial time", "They are a class of problems that are at least as hard as the hardest problems in NP", "They can be solved in logarithmic time", "They have a linear time complexity"}, 'B', EXPERT, ALGORITHM),
    Question("Which of the following is a common algorithm for pattern matching in strings?", {"Knuth-Morris-Pratt algorithm", "Quick Sort", "Radix Sort", "Merge Sort"}, 'A', EXPERT, ALGORITHM),
    Question("What is the purpose of Approximation ALGORITHM in computational optimization?", {"To find exact solutions to optimization problems", "To provide near-optimal solutions in polynomial time", "To encrypt optimization data for security", "To increase the complexity of optimization problems"}, 'B', EXPERT, ALGORITHM),
    Question("Which algorithm is commonly used for clustering in unsupervised machine learning?", {"K-means algorithm", "Dijkstra's algorithm", "Depth-First Search", "A* algorithm"}, 'A', EXPERT, ALGORITHM),
    Question("What is the purpose of Quantum ALGORITHM in quantum computing?", {"To solve classical computing problems faster", "To encrypt data using quantum principles", "To simulate classical ALGORITHM on quantum computers", "To explore new computational possibilities beyond classical ALGORITHM"}, 'D', EXPERT, ALGORITHM),
    Question("Which algorithm is commonly used for solving linear programming problems?", {"Simplex algorithm", "Prim's algorithm", "Floyd-Warshall algorithm", "Bellman-Ford algorithm"}, 'A', EXPERT, ALGORITHM),

Question("What is a Data Structure in computer science?", {"A way to store and organize data for efficient access and modification", "A computer hardware component", "An algorithm for sorting data", "A programming language"}, 'A', BEGINNER, DATA_STRUCTURES),
    Question("Which of the following is a linear data structure?", {"Stack", "Tree", "Graph", "Heap"}, 'A', BEGINNER, DATA_STRUCTURES),
    Question("What is the primary difference between an array and a linked list?", {"Arrays have a fixed size, while linked lists can dynamically grow", "Arrays are faster for insertion and deletion operations", "Linked lists use less memory than arrays", "Arrays can store different data types, while linked lists cannot"}, 'A', BEGINNER, DATA_STRUCTURES),
    Question("Which data structure uses the Last In, First Out (LIFO) principle?", {"Queue", "Stack", "Heap", "Linked List"}, 'B', BEGINNER, DATA_STRUCTURES),
    Question("What is the purpose of a Queue data structure?", {"To store data in a sorted order", "To retrieve data in reverse order", "To implement First In, First Out (FIFO) behavior", "To encrypt data for security"}, 'C', BEGINNER, DATA_STRUCTURES),
    Question("Which data structure is used to represent hierarchical relationships?", {"Array", "Queue", "Tree", "Stack"}, 'C', BEGINNER, DATA_STRUCTURES),
    Question("What is the advantage of using a Hash Table data structure?", {"Constant time access to elements", "Limited storage capacity", "Slow retrieval of elements", "Inability to store key-value pairs"}, 'A', BEGINNER, DATA_STRUCTURES),
    Question("Which data structure is suitable for implementing Undo functionality in text editors?", {"Stack", "Queue", "Linked List", "Tree"}, 'A', BEGINNER, DATA_STRUCTURES),
    Question("What is the purpose of a Binary Search Tree (BST) data structure?", {"To store data in a sorted order", "To implement Last In, First Out (LIFO) behavior", "To represent hierarchical relationships", "To retrieve data in reverse order"}, 'A', BEGINNER, DATA_STRUCTURES),
    Question("Which data structure is commonly used for implementing graphs?", {"Array", "Stack", "Linked List", "Adjacency List"}, 'D', BEGINNER, DATA_STRUCTURES),

Question("What is the primary difference between a stack and a queue data structure?", {"Stacks use First In, First Out (FIFO) principle, while queues use Last In, First Out (LIFO) principle", "Stacks allow access to elements in any order, while queues allow access only to the front and rear", "Stacks have a dynamic size, while queues have a fixed size", "Stacks are implemented using arrays, while queues are implemented using linked lists"}, 'B', INTERMEDIATE, DATA_STRUCTURES),
    Question("Which data structure is commonly used to implement a priority queue?", {"Stack", "Queue", "Heap", "Linked List"}, 'C', INTERMEDIATE, DATA_STRUCTURES),
    Question("What is the purpose of a Hash Map data structure?", {"To store elements in a sorted order", "To implement Last In, First Out (LIFO) behavior", "To provide constant time access to key-value pairs", "To encrypt data for security"}, 'C', INTERMEDIATE, DATA_STRUCTURES),
    Question("Which data structure is used to efficiently search, insert, and delete elements in a sorted list?", {"Array", "Linked List", "Binary Search Tree", "Queue"}, 'C', INTERMEDIATE, DATA_STRUCTURES),
    Question("What is the difference between a singly linked list and a doubly linked list?", {"Singly linked lists can only be traversed in one direction, while doubly linked lists can be traversed in both directions", "Singly linked lists use less memory than doubly linked lists", "Singly linked lists have constant time access to elements, while doubly linked lists have linear time access", "Singly linked lists store elements in reverse order, while doubly linked lists store elements in forward order"}, 'A', INTERMEDIATE, DATA_STRUCTURES),
    Question("What is the purpose of a Trie data structure?", {"To store elements in a sorted order", "To implement Last In, First Out (LIFO) behavior", "To efficiently store and search for strings", "To encrypt data for security"}, 'C', INTERMEDIATE, DATA_STRUCTURES),
    Question("Which data structure is used to implement a LRU (Least Recently Used) cache?", {"Queue", "Stack", "Linked List", "Hash Map"}, 'C', INTERMEDIATE, DATA_STRUCTURES),
    Question("What is the advantage of using a B-tree data structure over a binary search tree?", {"B-trees have faster search operations", "B-trees have a simpler structure", "B-trees are implemented using arrays", "B-trees have a fixed size"}, 'A', INTERMEDIATE, DATA_STRUCTURES),
    Question("Which data structure is commonly used for implementing a stack in programming languages?", {"Array", "Linked List", "Queue", "Heap"}, 'A', INTERMEDIATE, DATA_STRUCTURES),
    Question("What is the purpose of a Skip List data structure?", {"To skip elements during traversal", "To efficiently search and insert elements in a sorted list", "To store elements in reverse order", "To encrypt data for security"}, 'B', INTERMEDIATE, DATA_STRUCTURES),

Question("Which data structure is commonly used for implementing a self-balancing binary search tree?", {"AVL Tree", "Red-Black Tree", "B-tree", "Trie"}, 'B', EXPERT, DATA_STRUCTURES),
    Question("What is the purpose of a Bloom Filter data structure?", {"To efficiently store and query large sets of data", "To implement Last In, First Out (LIFO) behavior", "To encrypt data for security", "To visualize data relationships"}, 'A', EXPERT, DATA_STRUCTURES),
    Question("Which data structure is used for efficient range queries and prefix searches?", {"Segment Tree", "Skip List", "Suffix Array", "Fibonacci Heap"}, 'A', EXPERT, DATA_STRUCTURES),
    Question("What is the advantage of using a Fenwick Tree (Binary Indexed Tree) over a Segment Tree?", {"Fenwick Trees have faster query and update operations", "Segment Trees have a simpler structure", "Fenwick Trees are more memory-efficient", "Segment Trees can handle dynamic updates more efficiently"}, 'A', EXPERT, DATA_STRUCTURES),
    Question("Which data structure is commonly used for solving disjoint-set (union-find) problems?", {"AVL Tree", "Radix Tree", "Disjoint-set Forest", "Ternary Search Tree"}, 'C', EXPERT, DATA_STRUCTURES),
    Question("What is the purpose of a Patricia Trie data structure?", {"To store elements in a sorted order", "To implement efficient string searching and storage", "To visualize hierarchical data relationships", "To encrypt data for security"}, 'B', EXPERT, DATA_STRUCTURES),
    Question("Which data structure is used for efficient priority queue operations with O(log n) time complexity for both insertion and deletion?", {"Fibonacci Heap", "Binomial Heap", "Radix Heap", "Skew Heap"}, 'A', EXPERT, DATA_STRUCTURES),
    Question("What is the significance of a Splay Tree data structure?", {"It self-adjusts to bring frequently accessed elements closer to the root for faster access", "It encrypts data for security", "It is used for efficient graph traversal", "It stores data in a sorted order"}, 'A', EXPERT, DATA_STRUCTURES),
    Question("Which data structure is commonly used for efficient string matching and pattern searching?", {"Suffix Tree", "Radix Tree", "AVL Tree", "B+ Tree"}, 'A', EXPERT, DATA_STRUCTURES),
    Question("What is the purpose of a Van Emde Boas Tree data structure?", {"To efficiently store and query large sets of data", "To implement Last In, First Out (LIFO) behavior", "To visualize data relationships", "To support operations on large integer keys in a limited universe"}, 'D', EXPERT, DATA_STRUCTURES),

Question("What is the role of HTML in web cdevelopment?", {"Handling server-side logic", "Styling web pages", "Defining the structure of web pages", "Managing databases"}, 'C', BEGINNER, WEB_DEV),
    Question("Which programming language is commonly used for adding interactivity to web pages?", {"HTML", "CSS", "JavaScript", "SQL"}, 'C', BEGINNER, WEB_DEV),
    Question("What does CSS stand for in webd development?", {"Computer Style Sheets", "Creative Style Sheets", "Cascading Style Sheets", "Code Style Sheets"}, 'C', BEGINNER, WEB_DEV),
    Question("What is the purpose of responsive web design?", {"Making the website load faster", "Ensuring the website works well on different devices and screen sizes", "Adding animations to the website", "Encrypting user data"}, 'B', BEGINNER, WEB_DEV),
    Question("Which of the following is NOT a commonly used web development framework?", {"React", "Angular", "Django", "Java"}, 'D', BEGINNER, WEB_DEV),
    Question("What is the purpose of a web server in web development?", {"Storing web content", "Executing client-side scripts", "Handling client requests and serving web pages", "Designing user interfaces"}, 'C', BEGINNER, WEB_DEV),
    Question("What is the function of a database in web development?", {"Defining the structure of web pages", "Styling web pages", "Storing and organizing data for the website", "Managing user interactions"}, 'C', BEGINNER, WEB_DEV),
    Question("Which technology is used for real-time communication between the client and server in web development?", {"RESTful API", "WebSocket", "AJAX", "GraphQL"}, 'B', BEGINNER, WEB_DEV),
    Question("What is the purpose of a Content Management System (CMS) in web development?", {"Managing web server configurations", "Creating and managing digital content on websites", "Designing user interfaces", "Running server-side scripts"}, 'B', BEGINNER, WEB_DEV),
    Question("What is the function of a domain name in web development?", {"Storing web content", "Defining the website's layout", "Providing a human-readable address for the website", "Handling client requests"}, 'C', BEGINNER, WEB_DEV),
    
    Question("What is the purpose of AJAX in web development?", {"Allowing asynchronous server-side processing", "Styling web pages", "Defining the structure of web pages", "Managing databases"}, 'A', INTERMEDIATE, WEB_DEV),
    Question("Which of the following is NOT a front-end web development framework?", {"React", "Django", "Angular", "Vue.js"}, 'B', INTERMEDIATE, WEB_DEV),
    Question("What is the significance of RESTful API in web development?", {"It allows websites to be more visually appealing", "It enables communication between different software systems", "It encrypts user data for security", "It speeds up the loading time of web pages"}, 'B', INTERMEDIATE, WEB_DEV),
    Question("What is the purpose of a cookie in web development?", {"Storing user session information", "Defining the structure of web pages", "Managing server configurations", "Handling client requests"}, 'A', INTERMEDIATE, WEB_DEV),
    Question("Which technology is commonly used for building scalable and real-time web applications?", {"Node.js", "PHP", "Ruby on Rails", "ASP.NET"}, 'A', INTERMEDIATE, WEB_DEV),
    Question("What is the role of a CDN (Content Delivery Network) in web development?", {"Managing server-side scripts", "Storing and delivering web content to users efficiently", "Defining the layout of web pages", "Encrypting user data"}, 'B', INTERMEDIATE, WEB_DEV),
    Question("What is the purpose of a web framework in web development?", {"Providing a visual representation of the website", "Enhancing website security", "Simplifying the development of web applications by providing pre-built components and tools", "Managing databases"}, 'C', INTERMEDIATE, WEB_DEV),
    Question("Which technology is commonly used for building interactive and dynamic user interfaces in web development?", {"jQuery", "Bootstrap", "Sass", "Handlebars"}, 'A', INTERMEDIATE, WEB_DEV),
    Question("What is the significance of SEO (Search Engine Optimization) in web development?", {"Improving website security", "Enhancing user experience", "Optimizing websites for better visibility and ranking on search engines", "Encrypting user data"}, 'C', INTERMEDIATE, WEB_DEV),
    Question("What is the purpose of a web cache in web development?", {"Storing user session information", "Speeding up website performance by storing frequently accessed data", "Defining the structure of web pages", "Managing server configurations"}, 'B', INTERMEDIATE, WEB_DEV),
    
    Question("What is the purpose of a reverse proxy server in web development?", {"Caching static content for faster delivery", "Handling client requests directly", "Encrypting user data for security", "Managing database connections"}, 'A', EXPERT, WEB_DEV),
    Question("Which of the following is NOT a common HTTP status code in web development?", {"200 (OK)", "404 (Not Found)", "500 (Internal Server Error)", "302 (Moved Temporarily)"}, 'D', EXPERT, WEB_DEV),
    Question("What is the purpose of a JWT (JSON Web Token) in web development?", {"Encrypting user passwords", "Storing session information on the client side", "Managing database connections", "Handling AJAX requests"}, 'B', EXPERT, WEB_DEV),
    Question("Which technology is commonly used for server-side scripting in web development?", {"Node.js", "React", "Angular", "Vue.js"}, 'A', EXPERT, WEB_DEV),
    Question("What is the significance of a Single Page Application (SPA) in web development?", {"It reduces server load by caching data", "It reloads the entire page for each user interaction", "It provides a seamless user experience by dynamically updating content", "It encrypts user data for security"}, 'C', EXPERT, WEB_DEV),
    Question("What is the purpose of a web socket in web development?", {"Managing server configurations", "Enabling real-time communication between the client and server", "Storing and delivering web content to users efficiently", "Defining the structure of web pages"}, 'B', EXPERT, WEB_DEV),
    Question("Which technology is commonly used for building scalable and maintainable CSS in web development?", {"Sass", "Less", "Stylus", "PostCSS"}, 'A', EXPERT, WEB_DEV),
    Question("What is the role of a microservices architecture in web development?", {"It combines all services into a single monolithic application", "It breaks down applications into smaller, independent services for better scalability and flexibility", "It encrypts user data for security", "It speeds up the loading time of web pages"}, 'B', EXPERT, WEB_DEV),
    
    Question("What is the purpose of a web hook in web development?", {"Handling client requests directly", "Triggering automated actions based on events in web applications", "Managing server-side scripts", "Defining the layout of web pages"}, 'B', EXPERT, WEB_DEV),
    Question("What is the significance of Progressive Web Apps (PWAs) in web development?", {"They enable offline access to web applications", "They enhance website security", "They optimize websites for search engines", "They provide a visual representation of the website"}, 'A', EXPERT, WEB_DEV)
};

  srand(time(0));

  system("clear");
  cout << "Enter your name: ";
  getline(cin, playerName);

  Category chosenCategory;
  system("clear");
  selectCategory(chosenCategory);

  Difficulty chosenDifficulty;
  system("clear");
  selectDifficulty(chosenDifficulty);


  vector < Question > selectedQuestions;
  for (Question q: allQuestions) {
    if (q.getCategory() == chosenCategory && q.getDifficulty() == chosenDifficulty) {
      selectedQuestions.push_back(q);
    }
  }

  int score = 0;
  int questionsAnswered = 0;

  char continueGame = 'Y';

  while (toupper(continueGame) == 'Y' && !selectedQuestions.empty()) {
    system("clear");

    cout << "Welcome, " << playerName << "!" << endl;

    int randomIndex = rand() % selectedQuestions.size();
    selectedQuestions[randomIndex].displayQuestion();

    char userAnswer;
    bool isValidAnswer = false;

    while (!isValidAnswer) {
      cout << "Enter your answer (A, B, C, or D): ";
      cin >> userAnswer;
      userAnswer = toupper(userAnswer);

      if (userAnswer < 'A' || userAnswer > 'D') {
        cout << "Invalid input! Please enter A, B, C, or D." << endl;
      } else {
        isValidAnswer = true;
      }
    }

    if (selectedQuestions[randomIndex].checkAnswer(userAnswer)) {
      cout << "Correct answer! You earn 1 point." << endl;
      ++score;
    } else {
      cout << "Incorrect answer!" << endl;
    }

    ++questionsAnswered;

    selectedQuestions.erase(selectedQuestions.begin() + randomIndex);

    if (!selectedQuestions.empty()) {
      bool isValidContinue = false;
      while (!isValidContinue) {
        cout << "Continue? (Y/N): ";
        cin >> continueGame;
        if (toupper(continueGame) != 'Y' && toupper(continueGame) != 'N') {
          cout << "Invalid input! Please enter Y or N." << endl;
        } else {
          isValidContinue = true;
        }
      }
    }
  }

  cout << endl
       << "You finished all the questions!"
       << endl
       << "Press Enter to see your score...";
        cin.ignore();
        cin.get();
  system("clear");
  
  cout << "Total score: " << score << "/10" << endl;

  char restart;
  bool isValidRestart = false;
  while (!isValidRestart) {
    cout << "Do you want to restart? (Y/N): ";
    cin >> restart;
    if (toupper(restart) != 'Y' && toupper(restart) != 'N') {
      cout << "Invalid input! Please enter Y or N." << endl;
    } else {
      isValidRestart = true;
    }
  }

  if (toupper(restart) == 'Y') {
    cin.ignore();
    main();
  } else {
    cout << "Thank you for playing! Goodbye." << endl;
  }

  return 0;
}