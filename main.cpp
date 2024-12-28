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
};


int main() {
  Playlist playlist;

  playlist.addFromTheBeginning("Song A");
  playlist.addFromTheEnd("Song B");
  playlist.addFromTheBeginning("Song C");
  playlist.addFromTheEnd("Song D");
  playlist.ShowPlaylist();

  playlist.deleteFromTheBeginning();
  playlist.deleteFromTheEnd();
  playlist.ShowPlaylist();


  return 0;
}