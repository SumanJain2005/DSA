#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    // Constructor for full initialization
    Node(int data1, Node* next1 = nullptr, Node* prev1 = nullptr) {
        data = data1;
        next = next1;
        prev = prev1;
    }
};

Node* inputAtHead(Node* head, int n) {
    Node* new_node = new Node(n);
    new_node->next = head;
    if (head != nullptr) {
        head->prev = new_node;
    }
    return new_node;
}

Node* inputAtTail(Node* head, int n) {
 	Node* new_node = new Node(n);
    if (head == nullptr) {
        return new_node;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    } 
    temp->next = new_node;
    new_node->prev = temp;
    return head;
}
Node* inputAtPosition(Node* head, int pos, int n) {
    Node* new_node = new Node(n);

    if (pos <= 1 || head == nullptr) {
        new_node->next = head;
        if (head != nullptr) {
            head->prev = new_node;
        }
        return new_node;
    }

    Node* temp = head;
    int count = 1;

    while (count < pos - 1 && temp->next != nullptr) {
        count++;
        temp = temp->next;
    }

    if (temp->next != nullptr) {
        new_node->next = temp->next;
        new_node->prev = temp;
        temp->next->prev = new_node;
        temp->next = new_node;
    } else{
        new_node->prev = temp;
        temp->next = new_node;
    }
    return head;
}
Node* inputBeforeValue(Node* head , int val , int n) {
	Node* new_node = new Node(n);
	
	if(head == nullptr){
		return new_node;
	}

	if(head->data == val){
		new_node->next = head;
		head->prev  = new_node;
		return new_node;
	}
	Node* temp = head;
	while(temp->next!=nullptr ){
		if(temp->next->data == val){
			break;
		}
		temp = temp->next;
	}

	if(temp->next == nullptr){
		free(new_node);
		return head;
	}

	new_node->prev = temp;
	new_node->next = temp->next;
	temp->next->prev = new_node;
	temp->next = new_node;

	return head;
}
Node* deleteAtHead(Node* head) {
    if (head == nullptr) {
        cout << "List is empty \n";
        return nullptr;
    }
    Node* temp = head;
    head = head->next;
    if (head != nullptr) {
        head->prev = nullptr;
    }
    delete temp;
    return head;
}
Node* deleteAtTail(Node* head) {
    if (head == nullptr){
        cout << "List is empty\n";
        return nullptr;
    }
    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->prev->next = nullptr;
    delete temp;
    return head;
}
Node* deleteAtPosition(Node* head , int pos){
    // pehele head check
    if(pos == 1){
        Node* temp = head;
        head = head->next;
        if(head!=nullptr){
            head->prev = nullptr;
        }
        delete temp;
        return head;
    }
    // desired position pe traverse
    Node* temp = head;
    int count = 1;
    while(temp!=nullptr && count<pos){
        temp = temp->next;
        count++;
    }
    // check if temp is nullptr or not
    if(temp == nullptr){
        return head;
    }
    // ab agar koi edge case nahi hain then simply delete
    if (temp->prev != nullptr) {
        temp->prev->next = temp->next;
    }
    if (temp->next != nullptr) {
        temp->next->prev = temp->prev;
    }
    delete temp;
    return head;
}
Node* deleteValue(Node* head , int val){
    if(head->data == val){
        Node* temp = head;
        head = head->next;
        if(head!=nullptr){
            head->prev = nullptr;
        }
        delete temp;
        return head;
    }
    Node* temp = head;
    while(temp!=nullptr && temp->data != val){
        temp = temp->next;
    }
    if(temp == nullptr){
        return head;
    }
    if (temp->prev != nullptr) {
        temp->prev->next = temp->next;
    }
    if (temp->next != nullptr) {
        temp->next->prev = temp->prev;
    }
    delete temp;
    return head;
}
void printLL(Node* head) {
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert\n";
        cout << "2. Delete head\n";
        cout << "3. Print linked list\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int ch;
            cout << "1. At head 2. At tail 3. At Position 4. Before value \n";
            cin >> ch;
            switch (ch) {
            case 1: {
                int data;
                cout << "Enter the value to insert: ";
                cin >> data;
                head = inputAtHead(head, data);
                printLL(head);
                break;
            }
            case 2: {
                int data1;
                cout << "Enter the value to insert at tail: ";
                cin >> data1;
                head = inputAtTail(head, data1);
                printLL(head);
                break;
            }
        	case 3:{
        		int data2 , pos;
        		cout<<"Enter the value : ";
        		cin>>data2;
        		cout<<"Enter the position : ";
        		cin>>pos;
        		head = inputAtPosition(head, pos , data2);
                printLL(head);
        		break; 
        	}
           	case 4:{
        		int data3 , val;
        		cout<<"Enter the new value : ";
        		cin>>data3;
        		cout<<"Enter the value before which the new value is to be inserted : ";
        		cin>>val;
        		head = inputBeforeValue(head, val , data3);
                printLL(head);
        		break; 
        	}
            default:
                cout << "Wrong Input \n";
            }
            break;
        }
        case 2:
            int ch;
            cout << "1. At head 2. At tail 3. At Position 4.by value \n";
            cin >> ch;
            switch (ch) {
            case 1: {
                head = deleteAtHead(head);
                break;
            }
            case 2: {
                head = deleteAtTail(head);
                break;
            }
            case 3:{
                int pos;
                cout<<"Enter the position : ";
                cin>>pos;
                head = deleteAtPosition(head ,pos);
                break;
            }
        case 4:{
                int pos;
                cout<<"Enter the value : ";
                cin>>pos;
                head = deleteValue(head ,pos);
                break;
            }
            default:
                break;
            }
        case 3:
            printLL(head);
            break;
        case 4:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}