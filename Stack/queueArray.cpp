#include<iostream>
using namespace std;
class Queue{
private:
	int* queueArray;
	int capacity;
	int backIndex;
	int topIndex;
public:
	Queue(int size = 10){
		capacity = size;
		queueArray = new int[capacity];
		backIndex = -1;
		topIndex = -1;
	}
	~Queue(){
		delete[] queueArray;
	}
	void enqueue(int n){
		if(topIndex >= capacity-1){
			cout<<"Queue OverFlow \n";
			return;
		}
		if(topIndex == backIndex == -1){
			topIndex = backIndex = 0;
		}
		queueArray[++topIndex] = n;
	}
	int dequeue(){
		if(isEmpty()){
			cout<<"Khali hain \n";
			return;
		}
		return queueArray[backIndex++];
	}
	int queueKaPehelaBanda(){
		return queueArray[backIndex];
	}
};
int main(){
	return 0;
}