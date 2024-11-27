#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;

const int N = 1e5 + 1;

void solve() {
    int n, x;
    cin >> n >> x;
    ll dp[N][2];
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        ll tot = 0, idk = 0;
        for(int j = -min(a, x); j <= x; j++) {
            if(a + j >= N) break;
            if(j == 0) continue;
            tot = (tot + dp[a + j][0]) % MOD;
            idk = (idk + dp[a + j][1]) % MOD;
        }
        tot = (tot + 1) % MOD;
        dp[a][0] = (dp[a][0] + tot) % MOD;
        dp[a][1] = (dp[a][1] + idk + tot * a) % MOD;
    }
    ll ans = 0;
    for(int i = 0; i < N; i++) {
        ans = (ans + dp[i][1]) % MOD;
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
