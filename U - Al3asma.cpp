#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool can(ll mid, ll k, string s) {

    ll sum = 0;
    for (int i = mid; i >= 0; --i) {
        sum += (10 - ((s[i] + sum) % 10)) % 10;
    }

    return sum <= k;
}

void solve() {
    ll n, k;
    string s;

    cin >> n >> k >> s;

    for (char &digit: s) digit -= '0';

    ll l = 0, r = n - 1, ans = 0;
    while (l <= r) {
        ll mid = (l + r) / 2;

        if (can(mid, k, s)) {
            ans = mid + 1;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << ans << '\n';
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}