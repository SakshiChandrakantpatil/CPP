#include <iostream>
using namespace std;

#define MAX_SIZE 100

class StaticList {
private:
    int data[MAX_SIZE];
    int size;
public:
    StaticList() {
        size = 0;
    }

    void insert(int val) {
        if (size < MAX_SIZE) {
            data[size++] = val;
            cout << "Inserted " << val << " into the list." << endl;
        } else {
            cout << "List is full. Cannot insert more elements." << endl;
        }
    }

    void display() {
        cout << "Static List: ";
        for (int i = 0; i < size; ++i) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() {
        head = nullptr;
    }

    void insert(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cout << "Inserted " << val << " into the list." << endl;
    }

    void display() {
        cout << "Linked List: ";
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    StaticList staticList;
    staticList.insert(5);
    staticList.insert(10);
    staticList.display();

    LinkedList linkedList;
    linkedList.insert(15);
    linkedList.insert(20);
    linkedList.display();

    return 0;
}
