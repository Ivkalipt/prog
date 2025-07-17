// #pragma GCC optimize ("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma GCC push_options
// #pragma GCC pop_options


#include <bits/stdc++.h>

#define ll long long
#define vll  vector<ll>
#define vvll vector<vector<ll>>
//#define v(a) vector<a>
//#define vv(a) vector<vector<a>>
#define F first
#define S second

using namespace std;

int main() {
    stack <ll> p;
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        if(s[i]=='(' || s[i] == '{' || s[i] == '['){
            p.push(s[i]);
        }
        else{
            if(s[i] == ')' && !p.empty() && p.top() == '(') {
                p.pop();
            }
            else if (s[i] == '}' && !p.empty() && p.top() == '{') {
                p.pop();
            }
            else if (s[i] == ']' && !p.empty() && p.top() == '[') {
                p.pop();
            }
            else {
                p.push(s[i]);
            }
        }
    }
    if(p.empty()){
        cout << "yes\n";
    }else{
        cout << "no\n";
    }
}