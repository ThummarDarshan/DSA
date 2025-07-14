/*
Implement following operations of singly linked list. - Insert a node at front - Insert a node at end - Insert a node at given node information - Delete a node at front - Delete a node at last

Input Format

Input lines contain choices for insertion and deletion from front and end. For example,
Insert at front
insert at end
Insert a node at given node information
delete front
delete last,
display and 0 for exit.
For insertion functions, value must be given along with choice.
0 must be given at end of input.
Constraints

1 < data <= 100
Output Format

Modified Linked List
If no element present in the list, print the message "List is Empty".
Sample Input 0

1
14
1
13
1
12
6
0
Sample Output 0

12 13 14
Sample Input 1

2
4
2
6
2
8
2
10
6
0
Sample Output 1

4 6 8 10
Sample Input 2

1
5
1
3
2
9
6
4
6
0
Sample Output 2

3 5 9
5 9
Sample Input 3

1
2
1
5
2
7
2
9
4
5
4
5
6
0
Sample Output 3

List is Empty
Sample Input 4

4
0
Sample Output 4

List is Empty
Sample Input 5

2
4
2
5
2
7
2
10
3
5
6
6
0
Sample Output 5

4 5 6 7 10*/
#include <iostream>
using namespace std;

struct Node
{

    int data;
    Node *link;
} *head = NULL;

struct Node *creat(int data)
{
    struct Node *new1 = new Node;
    new1->data = data;
    new1->link = NULL;
    return new1;
}

void insert_at_front(int data)
{
    struct Node *new1 = creat(data);
    if (head == NULL)
    {
        head = new1;
    }
    else
    {
        new1->link = head;
        head = new1;
    }
}

void insert_at_end(int data)
{
    struct Node *new1 = creat(data);
    if (head == NULL)
    {
        head = new1;
    }
    else
    {
        struct Node *temp = head;
        while (temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = new1;
    }
}

void delete_front()
{
    if (head == NULL)
    {
        cout << "List is Empty" << endl;
        return;
    }
    struct Node *temp = head;
    head = head->link;
    delete temp;
}

void delete_last()
{
    if (head == NULL)
    {
        cout << "List is Empty" << endl;
        return;
    }
    if (head->link == NULL)
    {
        delete head;
        head = NULL;
        return;
    }
    struct Node *temp = head;
    while (temp->link->link != NULL)
    {
        temp = temp->link;
    }
    delete temp->link;
    temp->link = NULL;
}

void insert_at_given_node(int data, int given_data)
{
    struct Node *new1 = creat(data);
    if (head == NULL)
    {
        cout << "List is Empty" << endl;
        return;
    }
    struct Node *temp = head;
    while (temp != NULL && temp->data != given_data)
    {
        temp = temp->link;
    }
    if (temp == NULL)
    {
        cout << "Given node not found" << endl;
        delete new1; // Clean up the new node
        return;
    }
    new1->link = temp->link;
    temp->link = new1;
}

void delete_given_node(int given_data)
{
    if (head == NULL)
    {
        cout << "List is Empty" << endl;
        return;
    }
    if (head->data == given_data)
    {
        struct Node *temp = head;
        head = head->link;
        delete temp;
        return;
    }
    struct Node *temp = head;
    while (temp->link != NULL && temp->link->data != given_data)
    {
        temp = temp->link;
    }
    if (temp->link == NULL)
    {
        cout << "Given node not found" << endl;
        return;
    }
    struct Node *to_delete = temp->link;
    temp->link = to_delete->link;
    delete to_delete;
}

void display()
{
    if (head == NULL)
    {
        cout << "List is Empty" << endl;
        return;
    }
    struct Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->link;
    }
    cout << endl;
}

int main()
{
    int choice, data;

    do
    {
        // cout << "1.Insert at front" << endl;
        // cout << "2.Insert at end" << endl;
        // cout << "3.Insert at given node information" << endl;
        // cout << "4.Delete front" << endl;
        // cout << "5.Delete last" << endl;
        // cout << "6.Display" << endl;
        // cout << "0.Exit" << endl;

        // cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            // cout << "Enter data to insert at front: ";
            cin >> data;
            insert_at_front(data);
            break;

        case 2:
            // cout << "Enter data to insert at end: ";
            cin >> data;
            insert_at_end(data);
            break;

        case 6:
            display();

        default:
            break;
        }

    } while (choice != 0);
}