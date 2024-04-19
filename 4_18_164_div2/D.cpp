
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
    vector<ll> f(sum, 0);
    f[a[0]] = a[0];
    for(int i = 1; i < n; i++) {
        for(int j = sum - a[i]; j; j--) {
            if(!f[j]) continue;
            if(a[i] >= j) {
                f[a[i] + j] = (f[j] + a[i] + j) % mod;
            }
            else {
                f[a[i] + j] = (f[j] + a[i] + (j - a[i]) / 2 + (j - a[i]) & 1) % mod;
            }
        }
    }
    ll ans = 0;
    for(int i = 0; i <= sum; i++) ans = (ans + f[i]) % mod;
    cout << f[sum] << endl;
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