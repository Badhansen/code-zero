#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        unordered_map<int, int> mp;
        vector<int> vt(n);
        for(int i = 0; i < n; i++){
            cin >> vt[i];
            mp[vt[i]]++;
        }
        for(int i = 0; i < n; i++){
            if(mp[vt[i]] > 1){
                mp[vt[i] + 1]++;
                mp[vt[i]]--;
            }
        }
        cout << mp.size() << endl;
    }
    return 0;
}

