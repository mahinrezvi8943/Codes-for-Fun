#include<iostream>
using namespace std;
int main()
{   int x=1;
    cout<<"I am thinking of a number. Can you guess what number that is?\n";
    int m=rand()%100;
    while(x)
    {
        int n;
        cin>>n;
        if(n>=100) cout<<"Oh no! It's not more than 100! Try again: ";
        else if(n<m) cout<<"Nope, guess higher!\nTry again: ";
        else if(n>m) cout<<"Nope, guess lower!\nTry again: ";
        else if(n==m)
        {
            cout<<"Right You are!!!\nWant to play more?(Yes/No): ";
            string s;
            while(x){
                cin>>s;
                if(s=="yes"||s=="YES"||s=="Yes"||s=="yEs"||s=="yeS" || s=="yES"||s=="YEs"||s=="YeS")
                {
                    m=rand()%100;
                    cout<<"Try to guess Which number I am thinkig now: ";
                    break;
                }
                else if(s=="No"||s=="NO"||s=="nO"||s=="no") x=0;
                else cout<<"Invalid choice! Try again.";
            }
        }
    }
}