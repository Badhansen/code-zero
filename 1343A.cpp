// AC
#include<bits/stdc++.h>
using namespace std;
using LL = long long int;
LL power(int a, int b){
    LL res = 1;
    for(int i = 0; i < b; i++){
        res *= a;
    }
    return res;
}
int main(){
    int t;
    cin >> t;
    while(t--){ 
        int n;
        cin >> n;
        LL res = 1;
        int pos = 1;
        while(1){
            res += power(2, pos);
            if(n % res == 0){
                cout << n / res << endl;
                break;
            }
            pos++;
        }
    }
    return 0;
}
