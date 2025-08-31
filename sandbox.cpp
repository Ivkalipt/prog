#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    ll left = 0, right = n - 1;
    ll min_val = a[0], max_val = a[n - 1];

    while (left < right && k > 0) {
        // Считаем сколько зданий имеют минимальную высоту
        while (left < n - 1 && a[left] == a[left + 1]) left++;
        // Считаем сколько зданий имеют максимальную высоту
        while (right > 0 && a[right] == a[right - 1]) right--;

        if (left >= right) break;

        ll count_min = left + 1;
        ll count_max = n - right;

        if (count_min <= count_max) {
            // Выгоднее увеличить минимум
            ll diff = a[left + 1] - a[left];
            ll needed = diff * count_min;

            if (needed <= k) {
                k -= needed;
                min_val = a[++left];
            } else {
                min_val += k / count_min;
                k = 0;
            }
        } else {
            // Выгоднее уменьшить максимум
            ll diff = a[right] - a[right - 1];
            ll needed = diff * count_max;

            if (needed <= k) {
                k -= needed;
                max_val = a[--right];
            } else {
                max_val -= k / count_max;
                k = 0;
            }
        }
    }

    cout << max(0LL, max_val - min_val) << endl;
    return 0;
}