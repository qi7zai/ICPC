

#include<bits/stdc++.h>
using namespace std;
vector<long>d;
vector<long>f;
long a[200005];
void solve()
{
    int n,m,k;
    cin>>n>>m>>k;
    d.clear();
    f.clear();

    long max_dis = 0;
    long second_dis = 0;
    long left = 0;
    long right = 0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(i>1)
        {
            if(a[i]-a[i-1] >= max_dis)
            {
                second_dis = max_dis;
                max_dis = a[i]-a[i-1];
                right = i;
            }
        }
    }
    long mid = (a[right] + a[right-1]) / 2;
    for(int i = 1;i<=m;i++)
    {
        long p;
        cin>>p;
        d.push_back(p);
    }
    for(int i=1;i<=k;i++)
    {
        long p;
        cin>>p;
        f.push_back(p);
    }
    if(max_dis == second_dis)
    {
        cout<<second_dis<<endl;
        return;
    }
    sort(d.begin(),d.end());
    sort(f.begin(),f.end());
    
    for(auto i:d)
    {
        if(i + f[0]>= a[right])break;
        auto j = lower_bound(f.begin(),f.end(),mid - i) - f.begin();
        long ans1 = 2000000009,ans2 = 2000000009;
        if(f[j] + i < a[right] && f[j] + i > a[right-1] && j < f.end() - f.begin())
        {
            ans1 = max(abs(i+f[j]-a[right]),abs(i+f[j]-a[right-1]));
        }
        if(f[j-1] + i>a[right-1] && f[j-1] + i<a[right])
        {
            ans2 = max(abs(i+f[j-1]-a[right]),abs(i+f[j-1]-a[right-1]));
        }
        ans1 = min(ans1,ans2);
        max_dis = min(ans1,max_dis);
    }
    cout<<max(max_dis,second_dis)<<endl;
}
int main()
{
  int t;
  cin>>t;
  while (t--)
  {
    solve();
  }
  
}
