#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        int siz = str.size() % 2;
        if(siz || str.front() == ')' || str.back() == '('){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
        }
    }
    return 0;
}

