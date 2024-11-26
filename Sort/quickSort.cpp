#include<iostream>
#include<vector>
using namespace std;
int SortAndPivotFinder(vector <int> &arr , int low, int high){
	int i = low;
	int j = high;
	int pivot = arr[low];
	while(i<j){
		while(arr[i]<=pivot && i<high){
			i++;
		}
		while(arr[j]>pivot && j>low){
			j--;
		}
		if(i<j){
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[low],arr[j]);
	return j;
}
void quickSort(vector <int> &arr , int low , int high){
	if(low<high){
		int pivot = SortAndPivotFinder(arr ,low, high);
		quickSort(arr, low, pivot-1);
		quickSort(arr, pivot+1 , high); 		
	}
}

vector<int> quickSortReturn(vector <int>&arr){
	int n = arr.size();
	quickSort(arr, 0 ,n-1);
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
	vector <int>SortedArr = quickSortReturn(arr);
	cout << "After Qucik Sorting Array: " << endl;
    for (int i = 0; i < n; i++)
        cout << SortedArr[i] << " ";
    cout << endl;
	return 0;
}