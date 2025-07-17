#include <iostream>
#include <vector>
#define ll long long

using namespace std;

int main() {
    vector<pair<string, string>> dict;
    string w1, w2, w;
    ll n;
    cin >> n;
    for(ll i = 0; i < n; i++) {
        cin >> w1 >> w2;
        dict.push_back({w1, w2});
    }
    cin >> w;

    for(ll i = 0; i < n; i++) {
        if (dict[i].first == w) {
            cout << dict[i].second;
            return 0;
        }
        if (dict[i].second == w) {
            cout << dict[i].first;
            return  0;
        }
    }
}
