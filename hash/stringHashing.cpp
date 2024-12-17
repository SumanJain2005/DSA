#include<iostream>
#include<string>
using namespace std;
int main(){
	string s;
	cout<<"Enter the string : \n";
	cin>>s;
	//int hash[26 - 'a'] = {0}; considering only small cased letters
	int hash[256] = {0}; // considering all the characters in c++ existence
	for(int i = 0 ; i<s.size() ; i++){
		// hash[s[i] - 'a']++; agar only small case deta then this was the approach
		hash[s[i]]++; //typecasting and adding 1 to it.
	}
	int queries;
	cout<<"Enter the number of queries : \n";
	cin>>queries;
	while(queries!=0){
		char c;
		cin>>c;
		cout<<hash[c]<<endl;
		queries--;
	}
	return 0;
}