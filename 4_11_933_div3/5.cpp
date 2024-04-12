
#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int n, m, k, d;
    cin >> n >> m >> k >> d;
    int a[n][m];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            a[i][j]++;
        }
    vector<long long> ans;

    ans.push_back(-1);
    for(int i = 0; i < n; i++) {
        vector<long long> dp(m, 1);
        //dp[0] = 0;
        deque<int> s;
        s.push_back(0);
        for(int j = 1; j < m; j++) {
            while((!s.empty()) && s.front() < max(0, j - d - 1)) s.pop_front();
            dp[j] = dp[s.front()] + a[i][j];
            while(!s.empty() && dp[j] <= dp[s.back()]) s.pop_back();
            s.push_back(j);
        }
        ans.push_back(dp[m - 1]);
    }
    long long minn=0;
    for(int i=1;i<=k;i++){
        minn+=ans[i];
    }
    long long tmp=minn;
    for(int i=k+1;i<=n;i++){
        tmp=tmp-ans[i-k]+ans[i];
        if(tmp<minn) minn=tmp;
    }
    cout<<minn<<endl;
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
