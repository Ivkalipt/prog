#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    vector<vector<int>> dp(N, vector<int>(N, 0));

    for (int len = 1; len <= N; ++len) {
        for (int l = 0; l + len - 1 < N; ++l) {
            int r = l + len - 1;
            if (l == r) {
                dp[l][r] = a[l];
                continue;
            }
            // Вариант 1: Объединить два крайних, если они равны
            if (a[l] == a[r]) {
                dp[l][r] = max(dp[l][r], (l + 1 <= r - 1 ? dp[l + 1][r - 1] : 0) + a[l] + a[r]);
            }
            // Вариант 2: Объединить три шарика (l, k, r), если a[l] == a[r]
            for (int k = l + 1; k < r; ++k) {
                if (a[l] == a[r]) {
                    dp[l][r] = max(dp[l][r], (l + 1 <= k - 1 ? dp[l + 1][k - 1] : 0) + 
                                             (k + 1 <= r - 1 ? dp[k + 1][r - 1] : 0) + 
                                             a[l] + a[k] + a[r]);
                }
            }
            // Вариант 3: Разделить подотрезок на две части
            for (int k = l; k < r; ++k) {
                dp[l][r] = max(dp[l][r], dp[l][k] + dp[k + 1][r]);
            }
        }
    }

    cout << dp[0][N - 1] << endl;
    return 0;
}
