#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> val;

bool solve(int pos, int sum, int value){
    if(pos >= n){
        if(sum == value) return true;
        return false;
    }
    bool ret = solve(pos + 1, sum, value);
    bool bet = solve(pos + 1, sum + val[pos], value);
    bool ket = solve(pos + 1, sum - val[pos], value);
    return ret | bet | ket;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        val.resize(n);
        map<int, int> cnt;
        for(int i = 0; i < n; i++){
            cin >> val[i];
            val[i] = abs(val[i]);
            cnt[val[i]]++;
        }
        if(n == 1){
            if(val[0] == 0) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
        else if(cnt.size() < n){
            cout << "YES" << endl;
        }
        else if(cnt.find(0) != cnt.end()){
            cout << "YES" << endl;
        }
        else{
            bool flag = false;
            for(int i = 0; i < n; i++){
                int temp = val[i];
                val[i] = 0;
                if(solve(0, 0, (temp))){
                    flag = true;
                    break;
                }
                val[i] = temp;
            }
            if(flag) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
    return 0;
}




