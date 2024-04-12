#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int a[n + 10];
    int flag = 1;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n - 2; i++) {
        if(a[i] < 0) {
            flag = 0;
            break;
        }
        if(a[i] == 0) continue;
        a[i + 1] -= 2 * a[i];
        a[i + 2] -= a[i];
    }
    if(a[n - 2] != 0 || a[n - 1] != 0) flag = 0;
    if(flag) cout << "YES" << endl;
    else cout << "NO" << endl;
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