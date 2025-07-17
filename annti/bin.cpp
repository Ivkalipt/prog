#include <iostream>
#include <vector>
using namespace std;

vector<int> a;

void rec(string pref, int n) {
    if (n==0) {
        cout << pref << "\n";
    } else {
        rec(pref+"0", n-1);
        rec(pref+"1", n-1);
    }
}

int main() {
    int n;
    cin >> n;
    rec("", 3);
    return 0;
}