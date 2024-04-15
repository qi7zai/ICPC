
#include<bits/stdc++.h>

using namespace std;

vector<int>a(5002);
bool if_cheak(int k,int n)
{
    deque<int> bianjie;
    int add_ind = 0;
    for(int i=0;n - i >= k;i++)
    {
        if(!bianjie.empty() && i == bianjie.front())
        {
            add_ind ^=1;
            bianjie.pop_front();
        }
        if(a[i] ^ add_ind == 0)
        {
            add_ind ^= 1;
            bianjie.push_back(i + k);
        }
    }
    for(int i = n - k + 1;i<n;i++)
    {
        if(!bianjie.empty() && i == bianjie.front())
        {
            add_ind ^=1;
            bianjie.pop_front();
        }
        if(a[i] ^ add_ind == 0)
        {
            return false;
        }
    }
    return true;
}
void solve()
{
    int n;
    cin>>n;
    a.clear();
    for(int i=0;i<n;i++)
    {
        char b;
        cin>>b;
        a[i] = b - '0';
    }
    int left = 0,right = n+1;
    int ans = 1;
    for(int i=n;i>=1;i--)
    {
        if(if_cheak(i,n))
        {
            ans = i;
            break;
        }
    }
    // while(left <= right)
    // {
    //     int mid = (left + right) / 2;
    //     if(if_cheak(mid,n))
    //     {
    //         ans = mid;
    //         left = mid + 1;
    //     }
    //     else
    //     {
    //         right = mid - 1;
    //     }
    // }
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;

    while(t--)
    {
        solve();
    }
    return 0;
}