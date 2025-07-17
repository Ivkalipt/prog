// #pragma GCC optimize ("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma GCC push_options
#pragma GCC pop_options


#include <bits/stdc++.h>

#define ll long long
#define vll  vector<ll>
#define vvll vector<vector<ll>>
//#define v(a) vector<a>
//#define vv(a) vector<vector<a>>
#define F first
#define S second

using namespace std;

class St_min {
private:
    stack<ll> st, st_min;
public:
    void push(ll a) {
        st.push(a);
        if(st_min.size() == 0) {
            st_min.push(a);
        }
        else {
            if(a >= st_min.top()) {
                st_min.push(st_min.top());
            }
            else {
                st_min.push(a);
            }
        }
    }
    ll pop() {
        if(st.size() != 0) {
            return st.top();
            st.pop();
            st_min.pop();
        }
        
    }

    ll top() {
        return st.top();
    }

    ll min() {
        return st_min.top();
    }
};


int main() {
    St_min a;
    a.push(4);
    cout << a.min();
    a.push(3);
    cout << a.min();
    a.push(7);
    cout << a.min();
    a.pop();
    cout << a.min();
}