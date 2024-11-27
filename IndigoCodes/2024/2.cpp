#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n; cin >> n;
    vector<int> p(n);
    for(int i = 1; i < n; i++) {
        cin >> p[i];
    }
    int ans = 0;
    for(int i = 1; i < n; i++) {
        if(p[i] > p[n - i - 1]) {
            swap(p[i], p[n - i - 1]);
            ans++;
        }
    }
    for(int i = 0; i < n; i++) {
        if(p[i] != i + 1) {
            cout << -1 << '\n';
            return;
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
