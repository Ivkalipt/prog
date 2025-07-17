#pragma gcc optimize ("O3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define ll long long
#define vll vector<ll>
#define pll pair<ll, ll>
#define vpll vector<pll>
#define vvll vector<vector<ll>>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define F first
#define S second
#define all(a) a.begin(), a.end() 

using namespace std;

ll inf = 1e9 + 7;

int main() {
	ll n;
	cin >> n;
	vpll popul;
	for (ll i = 0; i < n; i++) {
        ll b;
		cin >> b;
		popul.push_back({b, i + 1});
	}
	vpll time;
	for (ll j = 0; j < n; j++) {
		for (ll i = 0; i < 2e4; i++) {
			ll c = 1000 - popul[j].F;
			if (i > 0)
				time.push_back({max(c , 1LL) + time[2e4 * j + i - 1].F, popul[j].S});
            else
				time.push_back({max(c , 1LL), popul[j].S});
			popul[j].F += 1;
		}
	}
	time.push_back({0, 1});
	sort(all(time));
	for (ll i = 0; i < time.size() - 1; i++) {
		if (time[i + 1].F < time[i].F + abs(time[i].S - time[i + 1].S)) {
			cout << time[i + 1].F;
			break;
		}
	}
	return 0;
}
