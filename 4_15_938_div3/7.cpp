#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
vector<vector<ll>> a(102,vector<ll >(102,0));
int n,m;
ll ans;

ll gcd(ll a,ll b)
{
    if(a < b)swap(a,b);
    if(!a || !b)return max(a,b);
    else
    {
        return gcd(b,a % b);
    }
}
void dfs(int i,int j,int now_value)
{
    if(i > n || j > m )return ;
    ll now_gcd = gcd(a[i][j],now_value);
    if(ans >= now_gcd)return ;
    if(i == n && j == m)
    {
        ans = max(ans,now_gcd);
        return;
    }
    else
    {
        dfs(i+1,j,now_gcd);
        dfs(i,j+1,now_gcd);
    }
    return ;
}

void solve()
{
    cin>>n>>m;
    ans = 0;
    a.clear();

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }
    dfs(1,1,0);
    cout<<ans<<endl;

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}