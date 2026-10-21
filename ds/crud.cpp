#include <iostream>
using namespace std;

const int MAX = 100; // Maximum number of students

struct Student {
    int id;
    char name[50];
    int age;
};

// Create a new student
void createStudent(Student students[], int &count) {
    if (count >= MAX) {
        cout << "Maximum limit reached.\n";
        return;
    }

    cout << "Enter ID: ";
    cin >> students[count].id;
    cout << "Enter Name: ";
    cin.ignore();
    cin.getline(students[count].name, 50);
    cout << "Enter Age: ";
    cin >> students[count].age;

    count++;
    cout << "Student created successfully.\n";
}

// Update student by ID
void updateStudent(Student students[], int count) {
    int id;
    cout << "Enter ID to update: ";
    cin >> id;

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            cout << "Enter new name: ";
            cin.ignore();
            cin.getline(students[i].name, 50);
            cout << "Enter new age: ";
            cin >> students[i].age;
            cout << "Student updated successfully.\n";
            return;
        }
    }
    cout << "Student not found.\n";
}

// Delete student by ID
void deleteStudent(Student students[], int &count) {
    int id;
    cout << "Enter ID to delete: ";
    cin >> id;

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            // Shift remaining students left
            for (int j = i; j < count - 1; j++) {
                students[j] = students[j + 1];
            }
            count--;
            cout << "Student deleted successfully.\n";
            return;
        }
    }
    cout << "Student not found.\n";
}

// Display all students
void displayStudents(Student students[], int count) {
    cout << "\n--- Student List ---\n";
    for (int i = 0; i < count; i++) {
        cout << "ID: " << students[i].id
             << ", Name: " << students[i].name
             << ", Age: " << students[i].age << endl;
    }
    if (count == 0) {
        cout << "No students to display.\n";
    }
}

int main() {
    Student students[MAX];
    int count = 0;
    int choice;

    do {
        cout << "\n1. Create Student\n2. Update Student\n3. Delete Student\n4. Display Students\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: createStudent(students, count); break;
            case 2: updateStudent(students, count); break;
            case 3: deleteStudent(students, count); break;
            case 4: displayStudents(students, count); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
