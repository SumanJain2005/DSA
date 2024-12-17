#include<iostream>
#include<map>
#include<string>
using namespace std;
int main() {
    string s;    
    cout << "Enter the string : \n";
    getline(cin , s); // it will read the entire line and will pass as an input as cin is used to take in single word input;
    map<char, int> mpp; // the key here will ofc be a character as character ka mapping kr rahe hain
    for(int i = 0; i < s.size(); i++) {
        mpp[s[i]]++; // in this case like in case of the array it wont be typecasted.
    }
    int queries;
    cout << "Enter the number of queries : \n";
    cin >> queries;
    cin.ignore(); // it cleans up the buffer for the getline function
    while(queries != 0) {
        char c;
        cout<<"Enter the chracter for query : "<<endl;
        cin >> c;
        cout << c << " is present : " << mpp[c] << endl;
        queries--;
    }
    cout<<"all the present data in map :  \n";
    for(auto it:mpp){
        cout<<it.first<<" -> "<<it.second<<endl;
    }
    return 0;
}