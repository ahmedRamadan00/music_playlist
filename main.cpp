#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Node {
public:
  string songName;
  Node *next;
  Node *prev;
};

class Playlist {
  Node *head;
  stack<string> history;

public:
  Playlist() {
    head = NULL;
  }

  void addFromTheBeginning(string name) {
    Node *newNode = new Node;
    newNode->songName = name;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL)
      head = newNode;
    else {
      newNode->next = head;
      head->prev = newNode;
      head = newNode;
    }
  }

  void addFromTheEnd(string name) {
    Node *newNode = new Node;
    newNode->songName = name;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL)
      head = newNode;
    else {
      Node *temp = head;
      while (temp->next != NULL)
        temp = temp->next;
      temp->next = newNode;
      newNode->prev = temp;
    }
  }

  string deleteFromTheBeginning() {
    string name;
    if (head == NULL) {
      cout << "The playlist is empty!" << endl;
      exit ;
    } else if (head->next == NULL) {
      name = head->songName;
      delete head;
      head = NULL;
      return name;
    } else {
      Node *temp = head;
      head = head->next;
      name = temp->songName;
      delete temp;
      head->prev = NULL;
      return name;
    }
  }

  string deleteFromTheEnd() {
    string name;
    if (head == NULL) {
      cout << "The playlist is empty!" << endl;
      exit(0);
    } else if (head->next == NULL) {
      name = head->songName;
      delete head;
      head = NULL;
      return name;
    } else {
      Node *temp = head;
      while (temp->next != NULL)
        temp = temp->next;
      name = temp->songName;
      temp->prev->next = NULL;
      delete temp;
      return name;
    }
  }

  void ShowPlaylist() {
    Node *temp = head;
    if (!temp) {
      cout << "The playlist is empty!" << endl;
      return;
    }
    while (temp != NULL) {
      cout << temp->songName << " ";
      temp = temp->next;
    }
    cout << endl;
  }

  void removeSong(string name) {
    Node *temp = head;
    while (temp != NULL) {
      if (temp->songName == name) {
        if (temp->prev != NULL)
          temp->prev->next = temp->next;
        else
          head = temp->next;

        if (temp->next != NULL)
          temp->next->prev = temp->prev;

        delete temp;
        cout << "Song '" << name << "' removed from the playlist." << endl;
        return;
      }
      temp = temp->next;
    }
    cout << "Song not found: " << name << endl;
  }

  int getPlaylistLength() {
    int count = 0;
    Node *temp = head;
    while (temp != NULL) {
      count++;
      temp = temp->next;
    }
    return count;
  }

  void reversePlaylist() {
    Node *current = head;
    Node *temp = NULL;
    while (current != NULL) {
      temp = current->prev;
      current->prev = current->next;
      current->next = temp;
      current = current->prev;
    }
    if (temp != NULL)
      head = temp->prev;
  }

  void searchSong(string name) {
    Node *temp = head;
    int position = 0;
    while (temp != NULL) {
      if (temp->songName == name) {
        cout << "Song found: " << name << " at position " << position << endl;
        return;
      }
      temp = temp->next;
      position++;
    }
    cout << "Song not found: " << name << endl;
  }

  void playSong(string name) {
    Node *temp = head;
    while (temp != NULL) {
      if (temp->songName == name) {
        cout << "Playing: " << name << endl;
        history.push(name);
        return;
      }
      temp = temp->next;
    }
    cout << "Song not found: " << name << endl;
  }
};


int main() {
  Playlist playlist;

  playlist.addFromTheBeginning("Song A");
  playlist.addFromTheEnd("Song B");
  playlist.addFromTheBeginning("Song C");
  playlist.addFromTheEnd("Song D");
  playlist.ShowPlaylist();

  cout << "Deleting from the beginning:" << endl;
  playlist.deleteFromTheBeginning();
  playlist.ShowPlaylist();

  cout << "Deleting from the end:" << endl;
  playlist.deleteFromTheEnd();
  playlist.ShowPlaylist();

  cout << "Reversing playlist:" << endl;
  playlist.reversePlaylist();
  playlist.ShowPlaylist();

  cout << "Searching for 'Song B':" << endl;
  playlist.searchSong("Song B");

  cout << "Playing 'Song B':" << endl;
  playlist.playSong("Song B");

  cout << "Removing 'Song C':" << endl;
  playlist.removeSong("Song C");
  playlist.ShowPlaylist();

  cout << "Playlist length: " << playlist.getPlaylistLength() << endl;

  return 0;
}