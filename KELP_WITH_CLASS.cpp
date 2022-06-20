#include<bits/stdc++.h>
using namespace std;
 
class Account{
    public:
    string number,name;
    float balance=0;
    void deposite_acc(string value){
        balance=balance+stof(value);
        // cout<<name<<" "<<balance<<endl;
    }
    void withdraw_acc(string value){
        balance=balance-stof(value);
    }
    void display_acc(){
        cout<<name<<" "<<balance<<endl;
    }  
};



int main(){
    vector<Account>banking;
    while(1){
        string in;
        getline(cin,in);
        //cout<<in<<endl;
	  if(in=="")
	  break;



        int i=0;
        string word="";
        vector<string>arr;

        while(in[i]!='\0'){
            if(in[i]==' '){
                // cout<<word;
                arr.push_back(word);
                word="";
            }
            else{
                word+=in[i];
            }
        i++;
        }
        arr.push_back(word);
        //cout<<arr[0]<<arr[1]<<arr[2];
        

        if(arr[0]=="CREATE"){
            Account a;
            a.number=arr[1];
            a.name=arr[2];
            banking.push_back(a);
        }
        
        
        else if(arr[0]=="DEPOSITE"){
            for(auto x: banking){
                if(x.number==arr[1]){
                    x.deposite_acc(arr[2]);
                    //cout<<x.balance<<endl; 
                    break;
                }
                    
            }
        }
        else if(arr[0]=="WITHDRAW"){
            for(auto x: banking){
                if(x.number==arr[1]){
                    if(x.balance>=stof(arr[2]))
                    x.withdraw_acc(arr[2]);
                    else{
                    cout<<"NOT SUFFICIENT AMOUNT IN BALANCE"<<endl;
                    }
                    //cout<<x.balance<<endl;
                   break; 
                }   
            }
        }
        else if(arr[0]=="BALANCE"){
             for(auto x: banking){
                if(x.number==arr[1]){
                    x.display_acc();
                    break;
                }   
            }
        }    
    }
}
