#include<bits/stdc++.h>
using namespace std;
int main(){
    
unordered_map<string,pair<string,float>>bank;
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
            if(bank.find(arr[1])!=bank.end())
            cout<<"ENTERED ACCOUNT NUMBER ALREADY USED"<<endl;
            else
            bank[arr[1]]={arr[2],0};
        }
        else if(arr[0]=="DEPOSITE"){
            auto x=bank.find(arr[1]);
                if(x!=bank.end()){
                    bank[x->first]={x->second.first,x->second.second+stof(arr[2])};
                    //cout<<x->second.first<<" "<<x->second.second<<endl;
                }
                else{
                    cout<<"ENTER PROPER ACCOUNT NUMBER"<<endl;
                }
        }
        else if(arr[0]=="WITHDRAW"){
           auto x=bank.find(arr[1]);
                if(x!=bank.end()){
                    if(x->second.second>=stof(arr[2]))
                     bank[x->first]={x->second.first,x->second.second-stof(arr[2])};
                     else{
                    cout<<"NOT SUFFICIENT AMOUNT IN BALANCE"<<endl;
                }
                }
                else{
                    cout<<"ENTER PROPER ACCOUNT NUMBER"<<endl;
                }
        }
        else if(arr[0]=="BALANCE"){
            auto x=bank.find(arr[1]);
                if(x!=bank.end()){
                    cout<<x->second.first<<" "<<x->second.second<<endl;
                }
                else{
                    cout<<"ENTER PROPER ACCOUNT NUMBER"<<endl;
                }
        }
        else{
            cout<<"ENTER THE PROPER COMMAND"<<endl;
        }
    }
}