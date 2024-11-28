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
Node* PositionInsert(Node*& head, int k, int n) {
    // Case 1: If the list is empty
    if (head == nullptr) {
        if (k == 1) { 
            return new Node(n); // If inserting at position 1, create a new node and return it as the new head
        } 
        else {
            return nullptr; // If k > 1 and the list is empty, return NULL
        }
    }

    // Case 2: Inserting at the head position
    else if (k == 1) {
        Node* temp = new Node(n, head); // Create a new node pointing to the current head
        head = temp; // Update head to point to the new node
        return head; 
    }

    // Case 3: Inserting at other positions
    int counter = 1; // Start counter from 1 since we're already at head
    Node* temp = head;

    while (temp != nullptr) {
        // When we reach the node just before the kth position
        if (k == counter + 1) { 
            Node* x = new Node(n); // Create a new node with value `n`
            x->next = temp->next; // x's next is temp's next
            temp->next = x; // temp's next is now x
            break;
        }
        temp = temp->next; // Move to the next node
        counter++;	 
    }

    // If k is greater than the length of the list, no insertion is done.
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
	if (head == nullptr) {
        return nullptr;
    }

    // Case 2: Deleting the head node
    if (k == 1) {
        Node* temp = head;  // Store the current head in a temporary pointer
        head = head->next;  // Move the head to the next node
        free(temp);         // Free the old head
        return head;        // Return the updated head
    }

    // Case 3 & 4: Deleting nodes other than the head
    Node* temp = head;      // Pointer to traverse the list
    Node* prev = nullptr;   // To keep track of the previous node
    int count = 1;

    // Traverse to find the kth node
    while (temp != nullptr && count < k) {
        prev = temp;
        temp = temp->next;
        count++;
    }

    // If the kth node exists
    if (temp != nullptr) {
        prev->next = temp->next;  // Skip the kth node
        free(temp);               // Free the kth node
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