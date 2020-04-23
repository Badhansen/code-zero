#include <bits/stdc++.h>
using namespace std;
typedef long long Long;
const int MAX = 1e9;
const int MIN = -1e9;
Long x, y;
Long pw[65];
void Power(){
    pw[0] = 1;
    for(int i = 1; i < 63; i++){
        pw[i] = pw[i - 1] * 2ll;
    }
}
bool isValid(Long a, Long b){
    if(a < MIN || a > MAX || b < MIN || b > MAX) return false;
    return true;
}
int main(){
    Power();
    //freopen("out.txt", "w", stdout);
    int t, ts = 1;
    scanf("%d", &t);
    while(t--){
        scanf("%lld%lld", &x, &y);
        map<pair<Long, Long>, string> mp;
        queue<pair<Long, Long>> qt;
        qt.push({0, 0});
        int pos = 0;
        string ans = "";
        bool flag = true;
        int cnt = 1e3;
        while(!qt.empty() && flag && cnt){
            int siz = qt.size();
            while(siz-- && flag && cnt){
                cnt--;
                Long a, b, c, d;
                a = qt.front().first;
                b = qt.front().second;
                qt.pop();
                if(a > 100 || a < -100 || b > 100 || b < -100) continue;
                if(a == x && b == y){
                    ans = mp[{a, b}];
                    flag = false;
                    break;
                }
                if(isValid(a, b + pw[pos])){
                    if(mp[{a, b + pw[pos]}].size() == 0 || mp[{a, b + pw[pos]}].size() > mp[{a, b}].size() + 1)
                        mp[{a, b + pw[pos]}] = mp[{a, b}] + 'N';
                    qt.push({a, b + pw[pos]});
                }
                if(isValid(a, b - pw[pos])){
                    if(mp[{a, b - pw[pos]}].size() == 0 || mp[{a, b - pw[pos]}].size() > mp[{a, b}].size() + 1)
                        mp[{a, b - pw[pos]}] = mp[{a, b}] + 'S';
                    qt.push({a, b - pw[pos]});
                }
                if(isValid(a + pw[pos], b)){
                    if(mp[{a + pw[pos], b}].size() == 0 || mp[{a + pw[pos], b}].size() > mp[{a, b}].size() + 1)
                        mp[{a + pw[pos], b}] = mp[{a, b}] + 'E';
                    qt.push({a + pw[pos], b});
                }
                if(isValid(a - pw[pos], b)){
                    if(mp[{a - pw[pos], b}].size() == 0 || mp[{a - pw[pos], b}].size() > mp[{a, b}].size() + 1)
                        mp[{a - pw[pos], b}] = mp[{a, b}] + 'W';
                    qt.push({a - pw[pos], b});
                }
            }

            pos++;
        }
        if(ans == ""){
            printf("Case #%d: IMPOSSIBLE\n", ts++);
        }
        else{
            printf("Case #%d: %s\n", ts++, ans.c_str());
        }
    }
    return 0;
}

