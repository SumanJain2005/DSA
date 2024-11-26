class ArrayStack {
private:
    int* stackArray;  
    int topIndex;     
    int capacity; 
public:
    ArrayStack(int size = 100) {
        capacity = size;
        stackArray = new int [capacity];
        topIndex = -1;
    }
    ~ArrayStack(){
        delete[] stackArray;
    }
    
    void push(int x) {
        if(topIndex >= capacity-1){
            return ;
        }
        stackArray[++topIndex] = x;
    }
    
    int pop() {
        if(isEmpty()){
            return -1; 
        }
        return stackArray[topIndex--];
    }
    int top() {
        if(isEmpty()){
            return -1;
        }
        return stackArray[topIndex];
    }  
    bool isEmpty() {
        return topIndex == -1;
    }
};