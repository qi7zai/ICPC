#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
void solve()
{
    ll n,k;

    cin>>n>>k;
    vector<ll>a(n);
    ll left ,right;
    left = k/2 + k%2;
    right = k/2;
    ll all = 0;
    ll all_num = 0;
    int left_ind = n-1;
    int right_ind = 0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        all_num += a[i];
    }
    for(int i=0;i<n;i++)
    {
        all += a[i];
        if(all > left)
        {
            left_ind = i;
            break;
        }
    }
    all = 0;
    for(int i=n-1;i>=0;i--)
    {
        all += a[i];
        if(all > right)
        {
            right_ind = i;
            break;
        }
    }
    int ans = 0;
    if(left_ind == right_ind)
    {
        if(all_num <= k)
        ans = 0;
        else ans = 1;
    }
    else if(left_ind < right_ind)
    {
        ans = right_ind - left_ind + 1;
    }
    else 
    {
        ans = 0;
    }
    cout<<n - ans<<endl;
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