#include<iostream>
using namespace std;

class Arr{
    int T_size;
    int U_size;       // These all are ADT
    int* ptr;         // We are making this here pointer because we are creating dynamic arr in heap

    public:
        Arr(int Us){
            // T_size = Ts;
            U_size = Us;
            ptr = new int[Us];

        }

        void setData(){
            for (int i = 0; i < U_size ; i++)
            {
                cout<<"Enter the element for "<< i+1<<endl;
                cin>>ptr[i];
            }
            
        }

        void showData(){
            for (int i = 0; i < U_size; i++)
            {
                // cout<<x<<endl;
                cout<<"The elements are"<<ptr[i]<<endl;
            }
            
        }


};

int main(){
    Arr hk(15);

    hk.setData();
    hk.showData();


    return 0;
}