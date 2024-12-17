// the basic logic is to reduce the searching time to minimal by creating pre-compute memory
// in compilers 1s = 10^8 iterations so if the O(1e10) then it takes up 100 secs so thats why we need hashing

#include<iostream>
using namespace std;
//array size can only be of 10^6 in main and 10^7 globally 
int main(){
	cout<<"Enter the size of the array \n";
	int a;
	cin>>a;
	cout<<"Enter the elements of the array \n";
	int arr[a];
	for(int i = 0 ; i<a ; i++){
		cin>>arr[i];
	}
	// logic behind hashing, agar koi baar baar array se data ke existence and count ka request kare, then the array runs for O(n) each time.
	// to reduce the huge time complexity issue we use pre-compute to use that as a referal and massively decrease the time.
	int hash[100] = {0}; // for now considering the size of the array will be 100 {can be higher though}
	// yes a logical counter to this is if i put 10000 in it the hash array becomes big, but again, we can also see the iteration decreases and we just hit the 1000th position
	for(int i = 0 ; i<a ; i++){
		hash[arr[i]] += 1;
	}
	// number of queries
	int q;
	cout<<"Enter the number of queries : \n";
	cin>>q;
	while(q--){
		int number;
		cin>>number;
		// fetch karenge number ka existence
		cout<<"Number of repitions for the number :"<<number << " is " <<hash[number]<<endl;
	}
	return 0;
}