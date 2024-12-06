#include<iostream>
using namespace std;
class ArrayStack{
private:
	int* stackArray;
	int topIndex;
	int capacity;
public:
	ArrayStack(int size = 10){
		capacity = size;
		stackArray = new int[capacity];
		topIndex = -1;
	}
	//destructor, optional hai
	~ArrayStack(){
		delete[] stackArray;
	}
	void push(int x){
		if(topIndex >= capacity-1){
			cout<<"Stack Overflow \n";
			return;
		}
		stackArray[++topIndex] = x;
	}
	int pop(){
		if(isEmpty()){
			cout<<"Stack Empty \n";
			return -1;
		}
		//topIndex--; pehele define ho ja raha, it should be inside the stackArray function taaki value sahi jaaye
		return stackArray[topIndex--];
	}
	int top(){
		if(isEmpty()){
			cout<<"Stack is Empty \n";
			return -1;
		}
		return stackArray[topIndex];
	}
	bool isEmpty(){
		return topIndex == -1; // agar khali hai toh 1 nahi toh 0
	}
	void display(){
		if(topIndex == -1){
			cout<<"Stack is Empty \n";
			return;
		}
		for(int i = 0 ; i<=topIndex ; i++){
			cout<<stackArray[i]<<" ";
		}
		cout<<endl;
	}
};
int main() {
    int capacity;
    cout << "Enter the size of the stack: ";
    cin >> capacity;

    ArrayStack stack(capacity); // creates an object, and also initializes the capacity using the constructor;

    while (true) {
        cout << "\nChoose an operation:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Top\n";
        cout << "4. Display Stack\n";
        cout << "5. Exit\n";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            int value;
            cout << "Enter the value to push: ";
            cin >> value;
            stack.push(value);
            break;
        }
        case 2: {
            int poppedValue = stack.pop();
            if (poppedValue != -1) {
                cout << "Popped value: " << poppedValue << endl;
            }
            break;
        }
        case 3: {
            int topValue = stack.top();
            if (topValue != -1) {
                cout << "Top value: " << topValue << endl;
            }
            break;
        }
        case 4: {
            stack.display();
            break;
        }
        case 5: {
            cout << "Exiting program.\n";
            return 0;
        }
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
}