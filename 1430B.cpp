#include<bits/stdc++.h>
using namespace std;

typedef long long Long;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        priority_queue<Long> qt;
        for(int i = 0 ;i < n ; i++){
            int a;
            cin >> a;
            qt.push(a);
        }
        int i = 0;
        while(k--){
            if(qt.size() < 2)
                break;
            Long a = qt.top();
            qt.pop();
            Long b = qt.top();
            qt.pop();
            if(a == 0)
                break;
            qt.push(a + b);
        }
        cout << qt.top() << endl;
    }
    return 0;
}
