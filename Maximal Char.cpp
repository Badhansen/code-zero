#include<bits/stdc++.h>
using namespace std;

vector<int> getMaxCharCount(string s, vector<vector<int>> queries) {
    // queries is a n x 2 array where queries[i][0] and queries[i][1] represents x[i] and y[i] for the ith query.
    int n = s.size();
    int sum[n + 1][27];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j < 26; j++){
            sum[i][j] = 0;
        }
    }
    for(int i = 1; i <= n; i++){
        int pos = tolower(s[i - 1]) - 'a';
        sum[i][pos] = 1;
        for(int j = 0; j < 26; j++){
            sum[i][j] += sum[i - 1][j];
        }
    }
    vector<int> pt;
    for(auto x : queries){
        int a, b;
        a = x[0], b = x[1];
        //cout << a << " " << b << " ee " << endl;
        for(int i = 25; i >= 0; i--){
            int s = sum[b + 1][i] - sum[a][i];
            if(s > 0){
                pt.emplace_back(s);
                break;
            }
        }
    }
    return pt;
}
int main(){

    int n;
    cin >> n;
    string s;
    cin >> s;

    int q;
    cin >> q;

    vector<vector<int>> query(q);

    for (int i = 0; i < q; i++) {
        query[i].resize(2);

        int a, b;
        cin >> a >> b;


        vector<int> query_row_temp = {a, b};

        for (int j = 0; j < 2; j++) {
            int query_row_item = query_row_temp[j];

            query[i][j] = query_row_item;
        }
    }

    vector<int> ans = getMaxCharCount(s, query);

    for (int i = 0; i < (int)ans.size(); i++) {
        cout << ans[i];

        if (i != (int)ans.size() - 1) {
            cout << "\n";
        }
    }
    return 0;
}
