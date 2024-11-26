#include<iostream>
#include<vector>
using namespace std;

class Node{ 
public:
	int data;
	Node* next;
public:
	Node(int data1 , Node* next1){
		data = data1;
		next = next1;
	}
public: 
	Node(int data1){
		data = data1;
	}
};
void insert(Node*& head , int n){
	Node* newNode = new Node(n, head); // newnode is pointer to the new value stored 
	head = newNode; // head shifts to the new pointer store another value
}
void printLL(Node* head){
	Node* temp = head;
	while(temp != nullptr){
		cout<< temp->data << " -> "; // temp er data print holo
		temp = temp->next; // temp next e point korlo
	}
	cout<<"nullptr"<<endl;
}
int main(){
	int choice;
	Node* head = nullptr;
	while(1){
		cout<<"Enter your choice 1. Inser 2. Print 3. Delete\n";
		cin>>choice;
		switch(choice){
		case 1:
			int n;
			cout<<"Enter value : ";
			cin>>n;
			insert(head , n);
			break;
		case 2:
			printLL(head);
			break;
		case 3:
			cout<<"Thanks for exiting \n";
			exit(1);
			break;
		default:
			cout<<"Wrong value \n";
		}
	}
	return 0;
}