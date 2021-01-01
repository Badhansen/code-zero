#include<bits/stdc++.h>
using namespace std;
const int Max = 200005;
int main(){
    int n;
    cin >> n;
    for(int t = 0; t < n; t++){
        int ans = 0;
        stack<char> r, s;
        string str;
        cin >> str;
        for(int i = 0; i < str.size(); i++){
            if(str[i] == '('){
                r.push('(');
            }
            if(str[i] == '['){
                s.push('[');
            }
            if(str[i] == ')'){
                if(!r.empty()){
                    ans++;
                    r.pop();
                }
            }
            if(str[i] == ']'){
                if(!s.empty()){
                    ans++;
                    s.pop();
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}

