#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, inp[100005], ans=0, same[100005];
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> inp[i];
        same[i] = inp[i];
    }
    sort(inp, inp + n);
    vector<int> lw, up;
    if(n<=2){
        cout << 0 << endl;
        for(int i=0;i<n;i++) cout<<same[i]<<" ";
        return 0;
    }
    int pos = n/2;
    for(int i=0; i<pos; i++) lw.push_back(inp[i]);
    for(int i=pos; i<n; i++) up.push_back(inp[i]);

    inp[0] = up[0];
    int sz = up.size();
    int curr = 1,l=0,r=1;
    while(r<sz){
//            cout<<lw[l]<<" "<<up[r]<<endl;
        inp[curr++] = lw[l++];
//            cout<<inp[curr-1]<<" ";
        inp[curr++] = up[r++];
//            cout<<inp[curr-1]<<endl;;

    }
    while(l<lw.size()) inp[curr++] = lw[l++];
    while(r<up.size()) inp[curr++] = up[r++];

    ans = 0;
    for(int i = 1; i< n - 1; i++){
        if(inp[i]<inp[i-1] && inp[i]<inp[i+1]) ans++;
    }
    cout << ans << endl;
    if(ans==0)
    {
        for(int i = 0; i < n; i++) cout<< same[i] <<" ";
        return 0;
    }
    for(int i = 0; i < n; i++) cout << inp[i] << " ";

    return 0;
}
//5 4 3 2 1
//5 3 4 1 2
/*
6
 1 2 3 3 1 2
 3 2 1 3 2 3
  3 2 3 1 2
  1 - 1
  2 - 3
  3 - 6
  4 - 10 (1-4)
*/
