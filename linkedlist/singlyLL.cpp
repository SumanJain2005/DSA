#include<iostream>
#include<vector>
using namespace std;
//struct Node {
class Node{ // why class? benifits of OOP concepts
public:
	int data;
	Node* next;
public:
	Node(int data1 , Node* next1){
		data = data1;
		next = next1;
	}
public: // Eta kora just for the sake  ki jokhon you assign a null ptr, baar baar likhte hobe na, it will be auto assigned.
	Node(int data1){
		data = data1;
	}
};
int main(){
	int arr[] = {1,2,3,4};
	Node *y = new Node(arr[1]);
	cout<<y<<" This is the pointer"<<endl; //will throw pointer.
	cout<<y->data<<endl; // will throw data
}