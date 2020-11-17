#include<bits/stdc++.h>
using namespace std;
typedef  long long Long;
int main()
{
    int test;
    cin >> test;
    while(test--){
        Long x;
        cin >> x;
        Long i,height = 0, buildCost=0, totalCost=0,ans=0;
        for(i = 1; totalCost<x; i++){
            height = (1ll << i)-1;
            buildCost = height*((height+1)/2);
            totalCost += buildCost;
            if(totalCost>x) break;
            ans++;
        }

        cout << ans << endl;    
    }
    return 0;
}