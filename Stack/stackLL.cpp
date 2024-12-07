#include<iostream>
using namespace std;
class Node{
public:
	int data;
	Node* next;
	Node(int data1 , Node* next1=nullptr){
		data = data1;
		next = next1;
	}
};
Node* push(int n , Node* head){
	Node* new_node = new Node(n);
	new_node->next = head;
	return new_node;
}
int pop(Node*& head){ // make sure to use *& as you are changing the head itself and you are not changing the value of it so you ot pass head as a pointer so that when cahnged the value is refelcted or else pop after 1 use will throw massive errors of segmentation fault.
	if(head == nullptr){
		cout<<"Stack Empty \n";
		return -1;
	}
	Node* temp = head;
	int data = temp->data;
	head = head->next;
	delete temp;
	return data;
}
int top(Node* head){
	if(head == nullptr){
		cout<<"List is empty \n";
		return -1;
	}
	return head->data;
}
void printll(Node* head){
	if(head == nullptr){
		cout<<"List empty \n";
		return;
	}
	Node* temp = head;
	while(temp != nullptr){
		cout<<temp->data<<" -> ";
		temp = temp->next;
	}
	cout<<"nullptr \n";
}
int main() {
    Node* head = nullptr; // Initialize the stack as an empty linked list
    int choice, value;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Top\n";
        cout << "4. Print Linked List\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: // Push
                cout << "Enter value to push: ";
                cin >> value;
                head = push(value, head);
                cout << "Pushed " << value << " onto the stack.\n";
                break;

            case 2: // Pop
                try {
                    value = pop(head);
                    if(value == -1){
                    	break;
                    }
                    cout << "Popped value: " << value << "\n";
                } catch (const exception& e) {
                    cout << e.what() << "\n"; // dont focus on try catch that much these r generally used for the works in asynchronous JS and are used in functions and many more
                }
                break;

            case 3: // Top
                if (head == nullptr) {
                    cout << "Stack is empty.\n";
                } else {
                    cout << "Top of stack: " << top(head) << "\n";
                }
                break;

            case 4: // Print Linked List
                cout << "Current stack: ";
                printll(head);
                break;

            case 5: // Exit
                cout << "Exiting program. Goodbye!\n";
                return 0;

            default: // Invalid choice
                cout << "Invalid choice. Please try again.\n";
        }
    }
}