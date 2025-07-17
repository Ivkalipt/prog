#include <iostream>
#include <vector>

using namespace std;

vector<int> push(vector<int> a, int k) {
    a.push_back(k);
    return a;
}

void rec(vector<int> pref, int n) {
    if (pref.size()==n) {
        for(auto &c:pref) {
            cout << c << " ";
        }
        cout << "\n";
    } else {
        for(int i = 0; i < n; i++) {

            rec(push(pref, i), n);
        }
    }
}

int main() {
    int n;
    vector<int> a;
    cin >> n;
    rec(a, n);
}