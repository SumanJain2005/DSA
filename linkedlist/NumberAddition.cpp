#include <iostream>
#include<math.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data1, Node* next = nullptr) {
        this->data = data1;
        this->next = next;
    }
};

// Function to create a linked list from an integer
Node* numberToLinkedList(int num) {
    Node* dummy = new Node(0);
    Node* current = dummy;

    do {
        current->next = new Node(num % 10);
        current = current->next;
        num /= 10;
    } while (num > 0);

    return dummy->next;
}

// Function to print a linked list
void printLinkedList(Node* head) {
   	int sum = 0, n , coutn = 0;
    while(head != nullptr){
    	n = head->data;
    	sum = n* pow(10,coutn) + sum;
    	coutn++;
    	head = head->next; 
    }
    cout<<sum<<endl;
}

// Function to add two linked lists
Node* addition(Node* l1, Node* l2) {
    Node* dummy = new Node(0);
    Node* current = dummy;
    int carry = 0;

    while (l1 != nullptr || l2 != nullptr || carry != 0) {
        int sum = carry;
        if (l1 != nullptr) {
            sum += l1->data;
            l1 = l1->next;
        }
        if (l2 != nullptr) {
            sum += l2->data;
            l2 = l2->next;
        }

        carry = sum / 10;
        current->next = new Node(sum % 10);
        current = current->next;
    }

    return dummy->next;
}

int main() {
    int a, b;
    cout << "Enter the numbers: ";
    cin >> a >> b;

    // Convert numbers to linked lists
    Node* l1 = numberToLinkedList(a);
    Node* l2 = numberToLinkedList(b);

    // Add the two linked lists
    Node* head = addition(l1, l2);

    // Print the result
    printLinkedList(head);

    return 0;
}