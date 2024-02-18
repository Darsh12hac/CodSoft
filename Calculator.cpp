#include<iostream>
#include<bits\stdc++.h>
using namespace std;




int main(){

  cout<<"Please Select one Operation to perform"<<endl;
    cout <<"1-> ADDITION (+) \n 2-> SUBTRACTION(-) \n 3-> MULTIPLICATION(*) \n 4->DIVISION(/)"<<endl;

    int choice;
    cout<<"Enter Your Choice - ";
    cin>>choice;
   int a,b;
    cout<<"Enter the number : "<<endl;
    cin>>a>>b;
    switch(choice){

        case 1:
           cout<< "Addition = "<<a+b <<endl;
           break;

        case 2:
           if(a>b){
            cout<< "Diff = "<<a-b;
           }else{
            cout<<"Diff = "<< b-a;
           }
           break;

        case 3:
          cout<< "Product = "<<a*b;
           break;

        case 4:
           cout<<"Division = "<< a/b;
           break;

        default:
           cout<<"INVALID"<<endl;
           break;         
   };
  
    
    return 0;
}