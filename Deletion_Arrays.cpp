#include<iostream>
using namespace std;

void display(int arr[],int size){
    for (int i = 0; i < size; i++)

    {
        cout<<arr[i]<<" " ;
    }
    
}

void indDeletion(int arr[],int index,int capacity,int size){
    if (index>=capacity)
    {
        cout<<"Out of Reach";
    }

    for (int i = index; i < size; i++)
    {
        arr[i] = arr[i+1];     // At i position elemet we want (i+1)s position element
    }
    
    
}



int main(){
    int array[100]={1,2,3,4,5};
    int size = 5,index = 2,capacity = 100;
    display(array,size);
    cout<<endl;

    indDeletion(array,index,capacity,size);
    display(array,size-1);

    return 0;
}