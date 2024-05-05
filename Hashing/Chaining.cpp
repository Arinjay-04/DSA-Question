#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int d) {
        data = d;
        next = nullptr;
    }
};

class LinkList {
public:
    Node* root;

    LinkList() {
        root = nullptr;
    }

    void Insert(int x) {
        if (root == nullptr) {
            root = new Node(x);
            return;
        }

        Node* temp = root;
        Node* prev = nullptr;

        while (temp != nullptr && temp->data < x) {
            prev = temp;
            temp = temp->next;
        }

        Node* newNode = new Node(x);
        newNode->next = temp;

        if (prev == nullptr) {
            root = newNode; 
        } else {
            prev->next = newNode;
        }
    }

    Node* Search(int x) {
        Node* temp = root;

        while (temp != nullptr) {
            if (temp->data == x) {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }

    void Delete(int x) {
        if (root == nullptr) {
            cout << "The Root is empty" << endl;
            return;
        }

        Node* temp = root;
        Node* prev = nullptr;

        while (temp != nullptr) {
            if (temp->data == x) {
                if (prev == nullptr) {
                    root = temp->next; 
                } else {
                    prev->next = temp->next;
                }
                delete temp;
                cout << "The Node " << x << " has been deleted successfully" << endl;
                return;
            }
            prev = temp;
            temp = temp->next;
        }

        cout << "Node Not found for deletion" << endl;
    }
};

class Hashing {
public:
    LinkList H[10];

    int hashing(int key) {
        return key % 10;
    }

    void Insert(int k) {
        int index = hashing(k);
        H[index].Insert(k);
    }

    void Delete(int k) {
        int index = hashing(k);
        H[index].Delete(k);
    }

    Node* Search(int k) {
        int index = hashing(k);
        return H[index].Search(k);
    }
};

int main() {
    Hashing h;

    h.Insert(10);
    h.Insert(22);
    h.Insert(12);
    h.Insert(7);
    h.Delete(12);

    // Search for an element
    Node* temp = h.Search(22);
    if (temp != nullptr) {
        cout << "Found: " << temp->data << endl;
    } else {
        cout << "Not Found" << endl;
    }

    return 0;
}
