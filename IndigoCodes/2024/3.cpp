#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n; cin >> n;
    ll w[n];
    ll mn = 1e18, mx = 0;
    for(int i = 0; i < n; i++) {
        cin >> w[i];
        mn = min(mn, w[i]);
        mx = max(mx, w[i]);
    }
    sort(w, w + n);
    ll ans = 0;
    for(int i = 0; i < n - 1; i++) {
        ans += max(abs(w[i] - mn), abs(w[i] - mx));
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
