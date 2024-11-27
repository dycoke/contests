#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    ll dp[n + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    ll pref = 0;
    for(int i = 1; i <= n; i++) {
        dp[i] = (dp[i] + dp[i - 1]) % MOD;
        if(i >= 2) {
            pref = (pref + dp[i - 2]);
            dp[i] = (dp[i] + dp[i - 2]) % MOD;
        }
        dp[i] = (dp[i] + 2 * pref) % MOD;
    }
    cout << dp[n] << '\n';
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
