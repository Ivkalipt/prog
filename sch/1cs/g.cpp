#include <iostream>
#include <stack>
#include <vector>

using namespace std;
using ll = long long;
using vll = vector<ll>;

int main() {
    ll n, k, t, t2;
    cin >> n >> k;
    vector<string> c(n, "");
    for(ll i = 0; i < k; i++) {
        cin >> t >> t2;
        if(t2 == 8) {
            if(c[t-1].empty()) {
                continue;
            }
            if(c[t-1].front() == '/') {
                c[t-1].pop_back();
                c[t-1].pop_back();
            }
            else {
                c[t-1].pop_back();
            }
        }
        else if(t2 == 13) {
            c[t-1]+="//";

        }
        else {
            c[t-1]+=t2;
        }
    }
    for(string cv:c) {
        cout << cv << '\n';
    }
}
