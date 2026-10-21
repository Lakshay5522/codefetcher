#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<string> undoStack;
    string text = "";

    int choice;
    string input;

    do {
        cout << "\nCurrent text: \"" << text << "\"" << endl;
        cout << "1. Type\n2. Undo\n3. Exit\nChoose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter text to append: ";
                cin >> input;
                undoStack.push(text); // Save current state
                text += input;        // text = text + input
                break;
            case 2:
                if (!undoStack.empty()) {
                    text = undoStack.top(); // Restore previous state
                    undoStack.pop();
                } else {
                    cout << "Nothing to undo." << endl;
                }
                break;
            case 3:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid option." << endl;
        }

    } while (choice != 3);

    return 0;
}
