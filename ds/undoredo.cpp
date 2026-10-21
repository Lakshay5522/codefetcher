#include <iostream>
using namespace std;

struct Action {
    string text;
    Action* prev;
    Action* next;

    Action(string t) : text(t), prev(nullptr), next(nullptr) {}
};

class TextEditor {
private:
    Action* current;

public:
    TextEditor(string initial = "") {
        current = new Action(initial);
    }

    void type(string newText) {
        Action* newAction = new Action(newText);
        current->next = nullptr;  // Clear redo stack
        newAction->prev = current;
        current->next = newAction;
        current = newAction;
    }

    void undo() {
        if (current->prev) {
            current = current->prev;
        } else {
            cout << "Nothing to undo.\n";
        }
    }

    void redo() {
        if (current->next) {
            current = current->next;
        } else {
            cout << "Nothing to redo.\n";
        }
    }

    void showText() {
        cout << "Current text: " << current->text << "\n";
    }
};

int main() {
    TextEditor editor("Hello");

    editor.type("Hello World");
    editor.type("Hello World!!!");
    editor.showText();  // Hello World!!!

    editor.undo();
    editor.showText();  // Hello World

    editor.undo();
    editor.showText();  // Hello

    editor.redo();
    editor.showText();  // Hello World

    editor.type("New content");  // Redo history cleared
    editor.showText();

    editor.redo();  // Nothing to redo
    return 0;
}
