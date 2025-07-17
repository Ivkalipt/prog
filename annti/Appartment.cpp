#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long


using namespace std;

int main() {
    ll n, m, k, t, i = 0, j = 0, s = 0;
    vector<ll> applicants;
    vector<ll> flats;
    cin >> n >> m >> k;
    for(ll i = 0; i < n; i++) {
        cin >> t;
        applicants.push_back(t);
    }
    for(ll i = 0; i < n; i++) {
        cin >> t;
        flats.push_back(t);
    }
    sort(applicants.begin(), applicants.end());
    sort(flats.begin(), flats.end());
    while(i < n && j < m) {
        if(abs(applicants[i] - flats[j]) <= k) {
            i+=1;
            j+=1;
            s+=1;
        }
        else if(applicants[i] > flats[j]) j+=1;
        else i+=1;
    }
    cout << s;
}