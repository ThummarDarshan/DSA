
// Given the head of a singly linked list, reverse the list, and return the reversed list.
// image

// Input Format

// First line contain the total number of nodes in linked list N:
// Second line contain the values of all nodes in linked list
// Constraints

// 0< N <=30
// Output Format

// THe output line contian the reverse linked list
// Sample Input 0

// 5
// 1 2 3 4 5
// Sample Output 0

// 5 4 3 2 1
// Contest ends in 13 days
// Submissions: 0
// Max Score: 20
// Difficulty: Medium

// More
// Rate This Challenge:

#include <iostream>
using namespace std;

struct Node 
{
    int data;
    Node* link;
};

Node* reverseList(Node* head) 
{
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;

    while (current != NULL) 
    {
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }
    return prev;
}

int main() {
    int n;
    cin >> n;

    if (n <= 0 || n > 30) {
        return 0;
    }

    Node* head = NULL;
    Node* tail = NULL;

    for (int i = 0; i < n; i++) {
        Node* node = new Node();
        cin >> node->data;
        node->link = NULL;

        if (head == NULL) {
            head = node;
            tail = node;
        } else {
            tail->link = node;
            tail = node;
        }
    }

    head = reverseList(head);

    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->link;
    }

    return 0;
}
