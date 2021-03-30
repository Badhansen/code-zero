#include<bits/stdc++.h>
using namespace std;

/*
    @author: Badhan Sen
    @mail: badhan.cse@gmail.com
    @My code start from here
*/

int solve(vector<int> value){
    vector<int> temp = value;
    sort(value.begin(), value.end());
    int n = value.size();
    int answer = 0;
    for(int i = 0; i < n - 1; i++){
        int j = i;
        for(; j < n; j++){
            if(value[i] == temp[j]) break;
        }
        answer += (j - i + 1);
        bool flag = true;
        if(i != j){
            reverse(temp.begin() + i, temp.begin() + j + 1);
        }
    }
    return answer;
}
vector<vector<int>> generate(int n){
    vector<int> ans;
    vector<vector<int>> answer;
    for(int i = 1; i <= n; i++){
        ans.push_back(i);
    }
    do{
        answer.push_back(ans);
    }
    while(next_permutation(ans.begin(), ans.end()));
    return answer;
}
int main(){
    freopen("out.txt", "w", stdout);
    int t, ts = 1;
    cin >> t;
    while(t--){
        int n, c;
        cin >> n >> c;
        vector<vector<int>> answer = generate(n);
        vector<int> ans;
        bool flag = true;
        vector<vector<int>> vv[29];
        for(auto el : answer){

            vv[solve(el)].push_back(el);
        }
        for(int i = 6; i < 29; i++){
            cout << "------- " << i << " ----------" << endl;
            for(int j = 0; j < vv[i].size(); j++){
                for(auto &el : vv[i][j]){
                    cout << el << " ";
                }
                cout << endl;
            }
            cout << "---------------------------------" << endl;
        }
//        cout << "Case #" << ts++ << ":";
//        if(flag){
//            cout << " IMPOSSIBLE" << endl;
//        }
//        else{
//            for(auto &el : ans){
//                cout << " " << el;
//            }
//            cout << endl;
//        }
    }
    return 0;
}

