#include <iostream>
using namespace std;

int main()
{
    int balance=2000;
    int choice,amount;
   do{ 
    cout<<"\nBANK MENU"<<endl;
    cout<<"----------------"<<endl;
    cout<<"1.Check Balance"<<endl;
    cout<<"2.Deposit"<<endl;
    cout<<"3.Withdraw"<<endl;
    cout<<"4.Exit"<<endl;
    cout<<"Enter your choice = ";
    cin>>choice;
    
    if(choice==1)
    {
        cout<<"Balance = "<<balance<<endl;
    }
    else if(choice==2)
    {
        cout<<"Enter deposit amount = ";
        cin>>amount;
        balance+=amount;
        cout<<"Deposit successful !"<<endl;
        cout<<"New Balance = "<<balance<<endl;
    }
    else if(choice==3)
    {   cout<<"Enter withdrawal amount = ";
        cin>>amount;
        if(balance>=amount)
        {
            balance-=amount;
        cout<<"Withdrawal successful !"<<endl;
        cout<<"New Balance = "<<balance<<endl;
        }
        else
        {
            cout<<"Insufficient balance!"<<endl;
        }
    }
    else if(choice==4)
    {
        cout<<"Exiting......"<<endl;
    }
    else
    {
      cout<<"lnvalid choice!"<<"\n"<<"Please try again later."<<endl;
    }
   }
   while(choice!=4);
   return 0;
   
}
