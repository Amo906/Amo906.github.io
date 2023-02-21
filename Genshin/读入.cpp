#include<bits/stdc++.h>
using namespace std;
int main(){
    string suf;
    freopen("in.txt","r",stdin);
    freopen("out2.txt","w",stdout);
    while(getline(cin,suf)){
        cout << "<img src=";
		printf("%c",'"');
		cout << suf;
		printf("%c",'"');
		cout << ">" << '\n';
    }
}