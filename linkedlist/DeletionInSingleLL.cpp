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
Node* headDel(Node* head){ // concept is head shift kore ager element e dariye jao !
	if(head == nullptr)
		return head;
	Node* temp = head;
	head = head->next;
	free(temp);// or we can use delete temp;
	return head;
}
Node* tailDel(Node* head){
	Node* temp = head;
	if(head == nullptr || head->next == nullptr)
		return nullptr;
	while(temp->next->next != nullptr){
		temp = temp->next;
	}
	free(temp->next);
	temp->next = nullptr;
	return head;
}
Node* PositionDel(Node* head , int k){
	// total 4 cases must be handled!
	if(head == nullptr)// ekhane nullptr
		return head;
	else if(k==1){ // ekhane 1 ta case cover hocche, which is head
		Node* temp = head;
		head = head->next;
		free(temp);
		return head;
	}
	int count = 1;
	Node* temp = head;
	Node* prev = nullptr;
	while(temp != nullptr){
		count++;
		if(count == k){ // ekhane 2 to case cover hocche, Kth positon r tail 
			prev->next = prev->next->next; // ager value ta theke direct porer value te point, majkhaner kth value got skipped
			free(temp);
			break;
		}
		prev = temp; // aager value ta mone rakhlm
		temp = temp->next; // porer value te chole gelam
	}
	return head;
}
Node* ValueDel(Node* head , int value){ 
	Node* temp = head;
	if(head == nullptr) return head;
	else if(head->data == value){ // ekhane 1 ta case cover hocche, which is head
		Node* temp = head;
		head = head->next;
		free(temp);
		return head;
	}
	Node* prev = nullptr;
	while(temp != nullptr){
		if(temp->data == value){
			prev->next = prev->next->next; // ager value ta theke direct porer value te point, majkhaner kth value got skipped
			free(temp);
			break;
		}
		prev = temp;
		temp = temp->next;
	}
	return head;
}
int main(){
	int choice;
	Node* head = nullptr;
	while(1){
		cout<<"Enter your choice 1. Insert 2. Print 3. Delete 4.Exit\n";
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
			int ch1;
			cout<<"Enter the type of deletion 1. Head 2. Tail 3. Position 4. Value \n";
			cin>>ch1;
				switch(ch1){
				case 1:
					head = headDel(head);
					cout<<"after head deletion \n";
					printLL(head);
				break;
				case 2:
					head = tailDel(head);
					cout<<"after tail deletion \n";
					printLL(head);
				break;
				case 3:
					int k;
					cout<<"Enter the Position for deletion : ";
					cin>>k;
					head = PositionDel(head , k+1);
					cout<<"after Position deletion \n";
					printLL(head);
				break;
				case 4:
					int value;
					cout<<"Enter the value for deletion : ";
					cin>>value;
					head = ValueDel(head , value);
					cout<<"After value deletion \n";
					printLL(head);
					break;
				default:
					cout<<"Wrong deletion \n";
				}
			break;
		case 4:
			cout<<"Thanks for exiting \n";
			exit(1);
			break;
		default:
			cout<<"Wrong value \n";
		}
	}
	return 0;
}