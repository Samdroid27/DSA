#include <iostream>
using namespace std;

void heapify(int a[],int i,int n){
    int largest = i;
    int l = (2*i) +1;
    int r = (2*i) +2;
    if(l<n && a[l]>a[largest]) largest=l;
    if(r<n && a[r]>a[largest]) largest = r;
    if(largest!=i){
        swap(a[largest],a[i]);
        heapify(a,largest,n);
    }
}

void buildHeap(int arr[], int n)
{
    int startIdx = (n / 2) - 1;

    for (int i = startIdx; i >= 0; i--) {
        heapify(arr, i,n);
    }
}

void heapsort(int a[],int n){
    for(int i=n-1;i>0;i--){
        swap(a[i],a[0]);
        heapify(a,0,i);
    }
}

int main() {
	// your code goes here
	int a[]={5,4,3,2,1};
	buildHeap(a,5);
	for(int i=0;i<5;i++){
	    std::cout << a[i] << " " ;
	}cout<<endl;
	heapsort(a,5);
	for(int i=0;i<5;i++){
	    std::cout << a[i] << " " ;
	}
	return 0;
}
