#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n;
    ll m, k;
    cin >> n >> m >> k;
    ll p[n + 1];
    p[0] = 0;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        p[i + 1] = (p[i] + a) % m;
    }
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j <= n; j++) {
            if((p[j] - p[i] + m) % m == k) {
                ans++;
            }
        }
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
