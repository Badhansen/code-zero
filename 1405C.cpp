#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t, ts = 1;
    cin >> t;
    while(t--){
        int n, k;
        string str;
        cin >> n >> k;
        cin >> str;
        int count_one = 0, count_zero = 0, count_what = 0;
        bool flag = true;
        for(int i = 0; i < k; i++){
            if(str[i] == '?'){
                for(int j = i + k; j < n; j += k){
                    if(str[j] != '?'){
                        str[i] = str[j];
                        break;
                    }
                }
            }
        }
        for(int i = 0; i < k; i++){
            if(str[i] == '0'){
                count_zero++;
            }
            else if(str[i] == '1'){
                count_one++;
            }
            else{
                count_what++;
            }
        }
        //cout << "Case " << ts++ << " " << count_zero << " " << count_one << " " << count_what << endl;
        if(count_zero > k / 2 || count_one > k / 2){
            flag = false;
        }
        else{
            for(int i = 0, j = count_zero; i < k && j < k / 2; i++){
                if(str[i] == '?'){
                    str[i] = '0';
                    j++;
                }
            }
            for(int i = 0, j = count_one; i < k && j < k / 2; i++){
                if(str[i] == '?'){
                    str[i] = '1';
                    j++;
                }
            }
            for(int i = 0; i < k; i++){
                for(int j = i + k; j < n; j += k){
                    if(str[j] == '?') continue;
                    else if(str[j] != str[i]){
                        flag = false;
                        break;
                    }
                }
            }
        }
        //cout << str << endl;
        if(flag){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}
