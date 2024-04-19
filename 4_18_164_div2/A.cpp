#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve()
{
    int n,m,k;
    cin>>n>>m>>k;
    int ans = n/m;
    if(n % m)ans++;
    if(n - ans <= k)cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;

    while (t--)
    {
        solve();
    }
    

    return 0;
}