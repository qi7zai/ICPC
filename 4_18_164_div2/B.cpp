
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    ll min_len = n;
    ll cur_len = 0;
    for(ll i = 0; i < n; i++) {
        if(a[i] == a[0]) cur_len++;
        else {
            if(cur_len) min_len = min(min_len, cur_len);
            else if(i == 1) min_len = 1;
            cur_len = 0;
        }
    }
    if(cur_len) min_len = min(min_len, cur_len);
    if(min_len == n) cout << -1 << endl;
    else cout << min_len << endl;
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