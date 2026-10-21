#include <iostream>
#include <string>
using namespace std;

// Node representing each song
struct Song {
    string title;
    Song* next;
};

// Playlist class
class Playlist {
private:
    Song* head;

public:
    Playlist() {
        head = nullptr;
    }

    // Add a song to the end
    void addSong(const string& title) {
        Song* newSong = new Song{title, nullptr};
        if (!head) {
            head = newSong;
        } else {
            Song* temp = head;
            while (temp->next)
                temp = temp->next;
            temp->next = newSong;
        }
        cout << "Added \"" << title << "\" to playlist.\n";
    }

    // Remove song by title
    void removeSong(const string& title) {
        if (!head) {
            cout << "Playlist is empty!\n";
            return;
        }

        // If song is first
        if (head->title == title) {
            Song* toDelete = head;
            head = head->next;
            delete toDelete;
            cout << "Removed \"" << title << "\" from playlist.\n";
            return;
        }

        // Find the song before the one to delete
        Song* temp = head;
        while (temp->next && temp->next->title != title)
            temp = temp->next;

        if (!temp->next) {
            cout << "Song \"" << title << "\" not found!\n";
            return;
        }

        Song* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
        cout << "Removed \"" << title << "\" from playlist.\n";
    }

    // Display playlist
    void displayPlaylist() {
        if (!head) {
            cout << "Playlist is empty.\n";
            return;
        }

        cout << "Current Playlist:\n";
        Song* temp = head;
        int index = 1;
        while (temp) {
            cout << index++ << ". " << temp->title << endl;
            temp = temp->next;
        }
    }

    // Simulate playing the playlist
    void playSongs() {
        if (!head) {
            cout << "Playlist is empty. Nothing to play.\n";
            return;
        }

        cout << "Playing playlist:\n";
        Song* temp = head;
        while (temp) {
            cout << "Now playing: " << temp->title << endl;
            temp = temp->next;
        }
    }

    // Destructor to free memory
    ~Playlist() {
        while (head) {
            Song* next = head->next;
            delete head;
            head = next;
        }
    }
};

// Main function
int main() {
    Playlist myPlaylist;

    myPlaylist.addSong("Shape of You");
    myPlaylist.addSong("Believer");
    myPlaylist.addSong("Faded");

    myPlaylist.displayPlaylist();
    cout << endl;

    myPlaylist.playSongs();
    cout << endl;

    myPlaylist.removeSong("Believer");
    myPlaylist.displayPlaylist();
    cout << endl;

    myPlaylist.removeSong("Non-existent Song");

    return 0;
}
