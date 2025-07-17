#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int compute_mex(const vector<int>& a) {
    unordered_set<int> s(a.begin(), a.end());
    int mex = 0;
    while (s.count(mex)) mex++;
    return mex;
}

bool can_split(const vector<int>& a, int k, int x) {
    if (x == 0) return true;
    vector<int> counts(x, 0);
    for (int num : a) {
        if (num < x) counts[num]++;
    }
    if (counts.empty()) return false;
    int min_count = *min_element(counts.begin(), counts.end());
    return min_count >= k;
}

int solve() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        int mex = compute_mex(a);
        if (k == 1) {
            cout << mex << "\n";
            continue;
        }

        int left = 0, right = mex, answer = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (can_split(a, k, mid)) {
                answer = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        cout << answer << "\n";
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
