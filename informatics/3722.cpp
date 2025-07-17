#include <iostream>
#include <cmath>
#include <iomanip>
#define ll long long

using namespace std;

int main() {
    double a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << fixed << setprecision(5) << cbrt(-d/a);
}