#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;

    ll mod = 998244353;
    vector<int> a(n);
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a.begin(), a.end());

    vector<ll> f(sum + 1, 0);
    //f[i][j]表示前i元素中选出的颜色的气球数之和为j时，其组合的个数。由第i-1维得i维，则第一维可省略
    //如{1, 1, 2} 则f[2] = 2，组合为{1, 1}或{2}
    f[0] = 1;
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = sum - a[i]; ~j; j--) {   //正反序都行 计算新增一种气球后带来的总value增加
            if(!f[j]) continue;
            if(a[i] >= j) ans = (ans + a[i] * f[j]) % mod;
            else ans = (ans + (a[i] + (j - a[i]) / 2 + ((j - a[i]) & 1)) * f[j]) % mod;
        }
        for(int j = sum; j >= a[i]; j--)    //同01背包，避免影响
            if(f[j - a[i]]) f[j] = (f[j] + f[j - a[i]]) % mod;  //更新f
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    t = 1;

    while (t--)
    {
        solve();
    }
    

    return 0;
}
