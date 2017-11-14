#include <iostream>
#include <sstream>
using namespace std;
void quicksort(int *&ar,int from,int to,int base){
	if(!(from<to)){
		return;
	}
	 
	int fromind=from;
	int toind=to;

	while(fromind<=toind){
		while(ar[fromind]<base)
		{
			fromind++;
		}
		while(ar[toind]>base){
			toind--;
		}
		if(fromind<=toind){
			swap(ar[fromind],ar[toind]);
			fromind++;
			toind--;
		}
	}
	
	quicksort(ar,from,fromind-1,ar[from]);
	quicksort(ar,fromind,to,ar[to]);
	
}
int main() {
   unsigned  int n;

    string line;
    getline(cin,line);
    istringstream numstream(line);
    if(!(numstream>>n)){
        cout<<"An error has occuried while reading input data.";
        exit(0);
    }

    getline(cin,line);
    istringstream arrstream(line);
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        if(!(arrstream>>arr[i])){
            cout<<"An error has occuried while reading input data.";
            delete[] arr;
            exit(0);
        }

    }

    
    
   quicksort(arr,0,n-1,arr[0]);
   

    
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    delete[] arr;
    return 0;
}
