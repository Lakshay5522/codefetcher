#include <iostream>
#include <string>
using namespace std;

// Define the Student structure
struct Student {
    int id;
    string name;
    float gpa;

    void display() {
        cout << "Student ID: " << id << "\nName: " << name << "\nGPA: " << gpa << endl;
    }

    void updateGPA(float newGPA) {
        gpa = newGPA;
    }
};

// Define the Book structure
struct Book {
    string title;
    string author;
    int year;
    bool isAvailable;

    void display() {
        cout << "Title: " << title << "\nAuthor: " << author
             << "\nYear: " << year << "\nAvailable: " << (isAvailable ? "Yes" : "No") << endl;
    }

    void borrowBook() {
        if (isAvailable) {
            isAvailable = false;
            cout << "Book borrowed successfully." << endl;
        } else {
            cout << "Book is not available." << endl;
        }
    }

    void returnBook() {
        isAvailable = true;
    }
};

// Define the Employee structure
struct Employee {
    int empID;
    string empName;
    double salary;

    void display() {
        cout << "Employee ID: " << empID << "\nName: " << empName
             << "\nSalary: $" << salary << endl;
    }

    void giveRaise(double percentage) {
        salary += salary * (percentage / 100);
    }
};

// Main function to demonstrate usage
int main() {
    // Student
    Student s1 = {1001, "Alice", 3.8};
    s1.display();
    s1.updateGPA(3.9);
    cout << "\nAfter GPA update:\n";
    s1.display();

    cout << "\n-------------------\n";

    // Book
    Book b1 = {"C++ Primer", "Lippman", 2012, true};
    b1.display();
    b1.borrowBook();
    b1.display();
    b1.returnBook();
    cout << "\nAfter returning the book:\n";
    b1.display();

    cout << "\n-------------------\n";

    // Employee
    Employee e1 = {501, "Bob", 55000.0};
    e1.display();
    e1.giveRaise(10); // 10% raise
    cout << "\nAfter raise:\n";
    e1.display();

    return 0;
}
