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
    vll st, st_min;
public:
    void push(ll a) {
        st.push_back(a);
        if(st_min.size() == 0) {
            st_min.push_back(a);
        }
        else {
            if(a >= st_min.back()) {
                st_min.push_back(st_min.back());
            }
            else {
                st_min.push_back(a);
            }
        }
        
    }
    ll pop() {
        return st.back();
        st.pop_back();
        st_min.pop_back();
    }

    ll top() {
        return st.back();
    }

    ll min() {
        return st_min.back();
    }

    ll size() {
        return st.size();
    }

    void clear() {
        st.clear();
        st_min.clear();
    }
};


int main() {
    St_min a;
    ll l;
    string q;
    while(q != "exit") {
        cin >> q;
        if(q == "push") {
            cin >> l;
            a.push(l);
            cout << "ok" << "\n";
        }
        if(q == "pop") {
            if(a.size() != 0) {
                cout << a.pop() << "\n";
            }
            else {
                cout << "error" << "\n";
            }
        }
        if(q == "back") {
            if(a.size() != 0) {
                cout << a.top() << "\n";
            }
            else {
                cout << "error" << "\n";
            }
        }
        if(q == "size") {
            cout << a.size() << "\n";
        }
        if(q == "clear") {
            a.clear();
            cout << "ok" << "\n";
        }
        
    }
    cout << "bye" << "\n";
}