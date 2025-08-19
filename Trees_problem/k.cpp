#include<bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'||s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
            s.erase(s.begin()+i);
        }
        else{
            cout<<'.'<<s[i];
        }
    }

    return 0;
}