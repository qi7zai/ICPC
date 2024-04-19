#include <bits/stdc++.h>
 
using namespace std;
using i64 = long long;
 
void solve() {
    int n, m;
    std::cin >> n >> m;

    // std::vector<std ::map<int, std::vector<int>>> gra(n);
    vector<set<int>> v_e(n);
    map<int,set<int>> e_v;
    // set<int> e_v[200005];

    for(int i = 0; i < m; i++)
    {
        int u,v,c;
        cin>>u>>v>>c;
        u--,v--;
        // gra[u][c].push_back(v);
        // gra[v][c].push_back(u);
        v_e[u].insert(c);
        v_e[v].insert(c);
        e_v[c].insert(u);
        e_v[c].insert(v);
    }
    int b,e;
    cin>>b>>e;
    b--;e--;

    vector<int> dis(n,-1);
    queue<pair<int,int>> q;
    set<int> is_here;
    q.push({0,b});
    int flag = 0;
    while (!q.empty() && !flag)
    {
        auto [d,x] = q.front();
        q.pop();
        if(dis[x] != -1)continue;
        dis[x] = d;
        if(x == e)break;
        for(auto c : v_e[x])
        {
            for(auto y : e_v[c])
            {
                if(dis[y] == -1 && is_here.find(y) == is_here.end())
                {q.push({d + 1,y});is_here.insert(y);
                if(y == e)
                {
                    dis[y] = d + 1;
                    flag = 1;
                }
                }
            }
        }
    }

    cout<<dis[e]<<endl<<endl;
    
    
    // std::vector<std::map<int, std::vector<int>>> adj(n);
    // for (int i = 0; i < m; i++) {
    //     int u, v, c;
    //     std::cin >> u >> v >> c;
    //     u--, v--;
    //     adj[u][c].push_back(v);
    //     adj[v][c].push_back(u);
    // }
    
    // std::map<std::pair<int, int>, int> dis;
    // std::deque<std::tuple<int, int, int>> q;
    // int b, e;
    // std::cin >> b >> e;
    // b--, e--;
    // q.emplace_back(0, b, 0);
    // while (!q.empty()) {
    //     auto [d, x, a] = q.front();
    //     q.pop_front();
        
    //     if (dis.count({x, a})) {
    //         continue;
    //     }
    //     dis[{x, a}] = d;
        
    //     if (a) {
    //         q.emplace_front(d, x, 0);
    //         for (auto y : adj[x][a]) {
    //             q.emplace_front(d, y, a);
    //         }
    //     } else {
    //         for (auto &[a, _] : adj[x]) {
    //             q.emplace_back(d + 1, x, a);
    //         }
    //     }
    // }
    
    // std::cout << dis[{e, 0}] << "\n";
}
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}