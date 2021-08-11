#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> val(n), path(n, 0);
        vector<pair<int, int>> frq;
        for(int i = 0; i < n; i++){
            cin >> val[i];
            frq.push_back({val[i], i});
        }
        sort(frq.begin(), frq.end());
        for(int i = 0; i < n;){
            if(i + k >= n) break;
            int cl = 1;
            while(i < n && cl <= k){
                path[frq[i].second] = cl++;
                i++;
            }
            while(i < n && frq[i].first == frq[i - k].first) i++;
        }
        for(int i = 0; i < n; i++){
            cout << path[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
