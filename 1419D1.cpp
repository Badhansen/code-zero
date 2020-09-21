#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, inp[100005], ans=0;
    cin >> n;
    for(int i = 0; i < n;i++)
        cin >> inp[i];
    sort(inp, inp + n);
    for(int i = 1; i < n; i += 2)
        swap(inp[i],inp[i-1]);
    for(int i = 1;i< n - 1; i++){
        if(inp[i]<inp[i-1] && inp[i]<inp[i+1]) ans++;
    }
    cout << ans << endl;
    for(int i = 0; i < n; i++) cout << inp[i] << " ";

    return 0;
}
//5 4 3 2 1
//5 3 4 1 2
/*
13
1 2 3 5 6 7 8 9 0 12 123 234 23
*/
