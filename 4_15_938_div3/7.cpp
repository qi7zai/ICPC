//暴力？
//遍历a[0][0]和a[n-1][m-1]的所有公因数，判断是否能有某条路径上的所有数都含有这个因子
//f数组定义在循环体内会！超！时！！！
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> a[i][j];

    int max_gcd = gcd(a[1][1], a[n][m]);
    int ans = 1;
    vector<vector<int>> f(n + 1, vector<int>(m + 1, 0));    //该因子是否能从左上角到i,j处
    //for(int num = max_gcd; num; num--) {  //这样遍历会超时
    for(int num = 1; num * num <= max_gcd; num++) {
        if(max_gcd % num) continue; //不是公因数
        vector<int> nums = {num, max_gcd / num};
        for(auto tmp : nums) {
            for(int i = 0; i <= n; i++) f[i].resize()
            f[1][0] = 1;
            for(int i = 1; i <= n; i++)
                for(int j = 1; j <= m; j++) {
                    if(a[i][j] % tmp) f[i][j] = 0; //不含该因数
                    else f[i][j] = f[i - 1][j] | f[i][j - 1];    //从上或左过来
                }

            if(f[n][m]) ans = max(ans, tmp);    //可达
        }
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
