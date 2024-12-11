#include<iostream>
using namespace std;
class Node{
public:
	int data;
	Node* next;
	Node(int data1 , Node* next1 = nullptr){
		data = data1;
		next = next1;
	}
};
Node* enqueue(int n , Node* head){
	Node* new_node = new Node(n);
	if(head == nullptr){
		return new_node;
	}
	Node* temp = head;
	while(temp->next !=nullptr){
		temp = temp->next;
	}
	temp->next = new_node;
	return head;
}
int dequeue(Node*& head) {
    if (head == nullptr) {
        cout << "Queue Underflow \n";
        return -1;
    }
    Node* temp = head;      
    int data = temp->data;  
    head = head->next;      
    delete temp;            
    return data;            
}
void printQueue(Node* head){
	if(head == nullptr){}
	Node* temp = head;
	while(temp!=nullptr){
		cout<<temp->data<<" -> ";
		temp = temp->next;
	}
	cout<<"nullptr \n";
}
int main() {
    Node* head = nullptr; 
    int choice, value;

    cout << "Queue Operations Using Linked List\n";
    cout << "1. Enqueue\n";
    cout << "2. Dequeue\n";
    cout << "3. Print Queue\n";
    cout << "4. Exit\n";

    while (true) {
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the value to enqueue: ";
            cin >> value;
            head = enqueue(value, head);
            printQueue(head);
            break;

        case 2:
            value = dequeue(head);
            if (value != -1) {
                cout << "Dequeued: " << value << endl;
            }
            printQueue(head);
            break;

        case 3:
            printQueue(head);
            break;

        case 4:
            cout << "Exiting...\n";
            return 0;

        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}