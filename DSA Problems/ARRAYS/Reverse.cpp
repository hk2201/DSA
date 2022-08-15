#include <iostream>
using namespace std;

class array
{
    int size;
    int *arr;

public:
    array(int sz)
    {
        size = sz;
        int *arr = new int[sz];
    }

    void getele(){
        for (int i = 0; i < size; i++)
        {
            cout<<"Enter the element"<<endl;
            cin>>arr[i];
        }
        
    }

    void displayreverse(){
        getele();
        for (int i = size-1; i >= 0; i--)
        {
            // cout<<"The elements are "<<endl;
            cout<<arr[i]<<" ";
        }
        
    }

    void reverse(int start,int end){
        getele();
        while(start<end){
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start ++;
            end --;

        }
    }

    void normalDisplay(){
        for (int i = 0; i < size; i++)

        {
            cout<<arr[i]<<" ";
        }
        
    }
};

int main(){
    int tell;
    cout<<"Enter the size"<<endl;
    cin>>tell;
    array hk(tell);
    // hk.displayreverse();
    cout<<endl;
    hk.reverse(0,tell-1);
    hk.normalDisplay();
    return 0;
}