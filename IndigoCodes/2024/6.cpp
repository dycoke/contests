#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n; cin >> n;
    vector<int> p(n);
    vector<vector<int>> nxt(n, vector<int>(20)), dis(n, vector<int>(20));
    for(int i = 0; i < n; i++) {
        cin >> p[i];
        nxt[i][0] = (i + p[i]) % n;
        dis[i][0] = p[i];
    }
    for(int i = 0; i < 19; i++) {
        for(int j = 0; j < n; j++) {
            nxt[j][i + 1] = nxt[nxt[j][i]][i];
            dis[j][i + 1] = dis[j][i] + dis[nxt[j][i]][i];
        }
    }
    
    int ans = (1 << 20) - 1;
    for(int j = 0; j < n; j++) {
        int cur = 0, u = j, prv = ans;
        ll dist = 0;
        for(int i = 19; i >= 0; i--) {
            if(dist + dis[u][i] < n - 1) {
                dist += dis[u][i];
                u = nxt[u][i];
                cur ^= (1 << i);
            } else {
                prv = cur ^ (1 << i);
            }
        }
        ans = min(ans, prv);
    }
    cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // freopen("io.out", "w", stdout);

    int t = 1;
    // std::cin >> t;
    while (t--) solve();
    return 0;
}
