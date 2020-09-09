#include<bits/stdc++.h>
using namespace std;
int main(){
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n), positive, negative;
        for(int i = 0; i < n; i++){
            cin >> v[i];
            if(v[i] < 0){
                negative.push_back(i);
            }
            if(v[i] > 0){
                positive.push_back(i);
            }
        }
        int i = 0, j = 0;
        int siz_positive = positive.size();
        int siz_negative = negative.size();
        while(i < siz_positive && j < siz_negative){
            if(positive[i] < negative[j]){
                int minimum = min(v[positive[i]], abs(v[negative[j]]));
                v[positive[i]] -= minimum;
                v[negative[j]] += minimum;
                if(v[positive[i]] == 0){
                    i++;
                }
                else{
                    j++;
                }
            }
            else{
                j++;
            }
        }
        long long ans = 0;
        for(int i = 0; i < n; i++){
            if(v[i] > 0) ans += v[i];
        }
        cout << ans << endl;
    }
    return 0;
}