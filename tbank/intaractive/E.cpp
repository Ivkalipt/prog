#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;

const ll maxn = 60 + 1;
vector<vector<string>> a(maxn, vector<string>(maxn, "NO"));

string interact(string direct, ll x, ll y) {
    cout << direct << endl;
    string state;
    cin >> state;
    a[x][y] = state;
    return state;
}

inline string rev(string direct) {
    if(direct == "EAST") return "WEST";
    if(direct == "WEST") return "EAST";
    if(direct == "SOUTH") return "NORTH";
    return "SOUTH";
}

void dfs(ll x, ll y) {
    a[x][y] = "EMPTY";
    const vector<tuple<ll, ll, string>> directions = {
        {x + 1, y, "EAST"},
        {x - 1, y, "WEST"},
        {x, y + 1, "SOUTH"},
        {x, y - 1, "NORTH"}
    };
    
    for(const auto & [nx, ny, direct] : directions) {
        if(a[nx][ny] == "NO") {
            string state = interact(direct, nx, ny);
            if(state == "EMPTY") {
                dfs(nx, ny);
                interact(rev(direct), x, y);
            } else if(state == "BLOCK") {
                a[nx][ny] = "BLOCK";
            }
        }
    }
}
    /*if(a[x + 1][y] == "NO") {
        string state = interact("EAST", x );
        if(state == "EMPTY") {
            a[x + 1][y] = "EMPTY";
            dfs(x + 1, y);
        } else if(state == "BLOCK") {
            a[x + 1][y] = "BLOCK";
        } else exit(0);
    }
    if(a[x - 1][y] == "NO") {
        string state = interact("WEST");
        if(state == "EMPTY") {
            a[x - 1][y] = "EMPTY";
            dfs(x - 1, y);
        } else if(state == "BLOCK") {
            a[x - 1][y] = "BLOCK";
        } else exit(0);
    }
    if(a[x][y + 1] == "NO") {
        string state = interact("SOUTH");
        if(state == "EMPTY") {
            a[x][y + 1] = "EMPTY";
            dfs(x, y + 1);
        } else if(state == "BLOCK") {
            a[x][y + 1] = "BLOCK";
        } else exit(0);
    }
    if(a[x][y - 1] == "NO") {
        string state = interact("NORTH");
        if(state == "EMPTY") {
            a[x][y - 1] = "EMPTY";
            dfs(x, y - 1);
        } else if(state == "BLOCK") {
            a[x][y - 1] = "BLOCK";
        } else exit(0);
    }*/

void solve() {
    dfs(30, 30); 
    cout << "DONE" << endl;
}

int main() {
    fflush(stdout);
    solve();
}
