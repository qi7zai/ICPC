#include<bits/stdc++.h>
using namespace std;

int left1[1005],right1[1005];
void solve()
{
  int n,m,k;
  int ans = 0;
  cin>>n>>m>>k;

  for(int i=1;i<=n;i++)
  {
    cin>>left1[i];
  }
  for(int i=1;i<=m;i++)
  {
    cin>>right1[i];
  }
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      if(left1[i]+right1[j] <= k)
      {
        ans++;
      }
    }
  }

  cout<<ans<<endl;
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