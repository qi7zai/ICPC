#include<bits/stdc++.h>

using namespace std;

void solve()
{
    int n,a,b;
    cin>>n>>a>>b;
    int ans;
    if(a * 2 < b)
    {
        ans = n * a;
    }
    else
    {
        ans = (n / 2) * b;
        ans += (n % 2) * a;
    }
    cout<<ans<<endl;
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