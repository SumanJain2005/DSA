#include<iostream>
#include<vector>
using namespace std;
void merge(vector <int> &arr, int low, int high , int mid){
	vector <int> temp;
	int left = low;
	int right = mid+1;
	while(left<=mid && right<=high){
		if(arr[left]>arr[right]){
			temp.push_back(arr[right]);
			right++;
		}
		else{
			temp.push_back(arr[left]);
			left++;
		}
	}
	while(left<=mid){
		temp.push_back(arr[left]);
		left++;
	}
	while(right<=high){
		temp.push_back(arr[right]);
		right++;
	}
	for(int i = low ; i<=high ; i++){
		arr[i] = temp[i-low];
	}
}  
void mergeSort(vector <int> &arr, int low, int high ){
	if(low == high) return;
	int mid = (low+high) /2;
	mergeSort(arr, low ,mid);
	mergeSort(arr, mid+1 , high);
	merge(arr, low,high, mid);
}
vector<int> mergeSortReturn(vector <int> &arr){
	int n = arr.size();
	mergeSort(arr, 0 ,n-1);
	return arr;
}

int main(){
	vector <int> arr;
	int a;
	int n;
	cout<<"Enter the size of array : \n";
	cin>>n;
	cout<<"Enter the elements \n";
	for(int i = 0 ; i<  n ; i++){
		a = 0;
		cin>>a;
		arr.push_back(a);
	}
	vector <int> SortedArr = mergeSortReturn(arr);
	cout << "After Merge Sorting Array: " << endl;
    for (int i = 0; i < n; i++)
        cout << SortedArr[i] << " ";
    cout << endl;
return 0;
}
