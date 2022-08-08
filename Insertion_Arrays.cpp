#include<iostream>
using namespace std;

void display(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}

void indInsertion(int arr[], int index,int element, int n, int capacity){
    if (n>=capacity)
    {
        cout<<"Limit Reached"<<endl;
    }

    for (int i = n; i>=index; i--)
    {
        arr[i+1]=arr[i];     // elemnet at i will shift to i+1 for eg. element at i(5) will to go 6(i+1) as arry of size 100
    }
    arr[index]=element;   // after creating vacant space at that index we'll insert 
    cout<<"Insertion succesful"<<endl;
    
    
}



int main(){
    int arr[100] = {1,2,3,4,5};
    int n = 5,index = 1,capacity = 100,element = 11;
    // display(arr,n);

    indInsertion(arr,index,capacity,n,element);

    display(arr,n+1);



    return 0;
}