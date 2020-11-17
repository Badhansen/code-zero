#include<bits/stdc++.h>
using namespace std;
typedef long long Long;

int main()
{
    int t;
    cin >> t;
    while(t--){
        Long n, w, cap;
        vector<pair<Long, int>> inp;
        cin >> n >> cap;
        for(int i = 0; i < n; i++){
            cin >> w;
            inp.push_back({w,i});
        }
        sort(inp.begin(), inp.end());
        Long sum = 0, flg = 0;
        vector<int> path;
        reverse(inp.begin(), inp.end());
        Long target = (cap + 1) / 2;
        for(auto v : inp){
            if(sum >= target) break;
            if(sum + v.first <= cap){
                path.push_back(v.second + 1);
                sum+=v.first;
            }
        }
        if(sum >= target && sum <=cap){
            cout << path.size() << endl;
            for(auto v : path) cout<< v << " ";
            cout << endl;
        }
        else cout << -1 << endl;
    }
    return 0;
}
