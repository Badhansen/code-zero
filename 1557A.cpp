#include<bits/stdc++.h>
using namespace std;

void solve()
{
    double sum = 0;
    vector<int> v;
    int n,temp;

    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        v.push_back(temp);
    }

    sort(v.begin(),v.end());

    for(int i=0;i<n-1;i++)
        sum += v[i];

    sum /= (n-1);
    sum += v[n-1];

    cout<<setprecision(9)<<sum<<endl;
}

int main ()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        solve();
    }
}
