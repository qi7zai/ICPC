#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    map<int, int> mpa;
    map<int, int> mpb;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i < m)
            mpa[a[i]]++;
    }
    vector<int> b(m);
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
        mpb[b[i]]++;
    }
    int cnt = 0; // 记录匹配的元素的个数
    for (auto [x, num] : mpb)
        if (mpa[x])
            cnt += min(num, mpa[x]);
    int ans = 0;
    if (cnt >= k)
        ans++;
    for (int i = 0; i + m < n; i++)
    {
        if (mpa[a[i]])
        {
            cnt -= min(mpb[a[i]], mpa[a[i]]);
        }
        mpa[a[i]]--;
        if (mpa[a[i]])
        {
            cnt += min(mpb[a[i]], mpa[a[i]]);
        }
        int id = i + m;
        if (mpa[a[id]])
        {
            cnt -= min(mpb[a[id]], mpa[a[id]]);
        }
        mpa[a[id]]++;
        if (mpa[a[id]])
        {
            cnt += min(mpb[a[id]], mpa[a[id]]);
        }
        if (cnt >= k)
            ans++;
    }
    cout << ans << endl;
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