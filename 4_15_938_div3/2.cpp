#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve()
{
    int n, c, d;
    cin >> n >> c >> d;
    vector<ll> b(n * n);
    map<ll, int> bb;
    ll min_value = 1e9+1;
    for(int i = 0; i < n * n; i++) {
        cin >> b[i];
        min_value = min(b[i],min_value);
        bb[b[i]]++;
    }
    // sort(b.begin(), b.end());
    int flag = 1;
    ll pre = min_value;
    for(int i = 0; i < n && flag; i++) {
        ll tmp = pre;
        for(int j = 0; j < n && flag; j++) {
            if(!bb[tmp]) flag = 0;
            else {
                bb[tmp]--;
                tmp += d;
            }
        }
        pre += c;
    }
    if(flag) cout << "YES" << endl;
    else cout << "NO" << endl;

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