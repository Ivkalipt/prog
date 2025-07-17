#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <stdint.h>
#include <fstream>
#include <iomanip>
#include <numeric>
#include <string>
#include <vector>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
 
using namespace std;

#define fasttype ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using sigmed = signed;
using str = std::string;
using pii = std::pair<int, int>;
using pll = std::pair<ll, ll>;
using vint = std::vector<int>;
using vll = std::vector<ll>;
using vvll = std::vector<vll>;
using vdb = std::vector<double>;
using vbl = std::vector<bool>;
using vstr = std::vector<str>;
using vpii = std::vector<pii>;
using vpll = std::vector<pll>;
using vvint = std::vector<vint>;
using vvbl = std::vector<vbl>;
using mii = std::map<int,int>;
using mll = std::map<ll, ll>;
#define ff first
#define ss second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define INF (int)(1e9 + 7)
#define YES std::cout<< "YES" << '\n'
#define NO std::cout<< "NO" << '\n'
  
/*
    #ILoveCodestyle
                     */
 
template<typename T>
istream &operator>>(istream &in, vector<T> &a) {
  for (auto &x : a) in >> x;
  return in;
} 

template<typename T, typename K>
istream &operator>>(istream &in, pair<T, K> &a) {
  in >> a.ff >> a.ss;
  return in;
} 

template<typename T>
ostream &operator<<(ostream &out, vector<T> &a) {
  for (auto &x : a) out << x << ' ';
  out << '\n';
  return out;
} 

template<typename T>
ostream &operator<<(ostream &out, vector<vector<T>> &a) {
  for (auto &x : a) out << x;
  out << '\n';
  return out;
} 

ostream &operator<<(ostream &out, vstr &a) {
  for (auto &x : a) out << x << '\n';
  out << '\n';
  return out;
} 

template<typename T, typename K>
ostream &operator<<(ostream &out, const pair<T, K> &a) {
  out << a.ff << ' ' << a.ss << '\n';
  return out;
}

