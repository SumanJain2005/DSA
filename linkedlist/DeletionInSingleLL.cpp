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
public: // eta just for the sake jokhon lokera sudhu data diye debe then it will work and null ptr hisab e treat hobe
	Node(int data1){
		data = data1;
	}
};
void HeadInsert(Node*& head , int n){
	Node* newNode = new Node(n, head); // newnode is pointer to the new value stored 
	head = newNode; // head shifts to the new pointer store another value
}
Node* TailInsert(Node*& head , int n){
	Node* temp = head;
	if(head == nullptr){
		return new Node(n);
	}
	while(temp->next != nullptr){
		temp = temp->next;
	}
	Node* newNode = new Node(n);
	temp->next = newNode;
	return head;
}
Node* PositionInsert(Node*& head , int k ,int n){
	if(head == nullptr){
		if(k==1) return new Node(n);
		else return NULL;	
	}
	else if(k==1){
		Node* temp = new Node(n,head);
		return head;;
	}
	int counter = 0;
	Node* temp = head;
	while(temp!= nullptr){
		counter++;
		if(k == counter+1){
			Node* x = new Node(n);
			x->next = temp->next; // aage x er porer number is same as temp er porer number
			temp->next = x; // then temp er porer number is x
			break;
		}
		temp = temp->next;	 
	}
	return head;
}
Node* InsertBeforeVlaue(Node*& head, int b ,int n){
	Node* prev = nullptr;
	Node* temp = head;
	if(head==nullptr){
		cout<<"Empty list \n";
		return NULL;
	}
	int count = 0;
	while(temp!=nullptr){
		if(temp->next->data == b){
			count++;
			Node* x = new Node(n);
			x->next = temp->next;
			temp->next = x;
			break;
		}
		temp = temp->next;
	}
	if(count == 0){
		cout<<"Value not found \n";
		return NULL;
	}
	return head;
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
			cout<<"Enter the type of insertion: 1. head 2. Tail 3. Position 4. Value \n";
			int ch;
			cin>>ch;	
			switch(ch){
			case 1:
				int n;
				cout<<"Enter value : ";
				cin>>n;	
				HeadInsert(head , n);
			break;
			case 2:
				int m;
				cout<<"Enter value : ";
				cin>>m;
				head = TailInsert(head , m);
			break;
			case 3:
				int o;
				int k;
				cout<<"Enter Position of inertion : ";
				cin>>k;
				cout<<"Enter Value : ";
				cin>>o;
				head = PositionInsert(head,k,o);
			break;
			case 4:
				int p;
				int b;
				cout<<"Enter value before of inertion : ";
				cin>>b;
				cout<<"Enter Value for insertion : ";
				cin>>p;
				head = InsertBeforeVlaue( head,  b , p);
			break;
			default:
				cout<<"Wrong input \n";
			}	
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