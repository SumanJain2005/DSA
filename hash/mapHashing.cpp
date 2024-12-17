#include<iostream>
#include<map>
using namespace std;
int main(){
	// the code might throw warning as map is used in c++11, nothing to worry it will run fine.
	int n;
	cout<<"Enter the size of the array : \n";
	cin>>n;
	int arr[n];
	for(int i = 0 ; i<n ; i++){
		cin>>arr[i];
	}
	// Pre - compute can also be done in the input loop but doing it separately won't create any problem as it will create a O(2n) which is in general treated as O(n).
	map<int , int>mpp; // yeh ek data ka counter rakhta hain, you can also change the data type to something else like long -> long and it won't matter and it will work uptil like 10^18.
	for(int i =0 ; i<n ; i++){
		mpp[arr[i]]++;
	}
	// iteration in a map is done using an auto iterator.
	// in map all the data types are sorted and secondly it is the format of key->value;
	cout<<"Iterating through the map just for demo : \n";
	for(auto it:mpp){
		cout<<it.first<<" -> "<<it.second<<endl;
	}
	int queries;
	cout<<"Enter the number of queries : \n";
	cin>>queries;
	while(queries!=0){
		int c;
		cin>>c;
		cout<<c<<" is present : "<<mpp[c]<<endl;
		queries--;
	}
	return 0;
}