// #pragma GCC optimize ("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma GCC push_options
// #pragma GCC pop_options
// #pragma GCC optimize ("Ofast")

#include <bits/stdc++.h>

#define ll long long
#define vll vector<ll>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
// #define v(a) vector<a>
// #define vv(a) vector<vector<a>>
#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define F first
#define S second
#define all(a) a.begin(), a.end()

using namespace std;

int main() {
    fastio;
    ll a, b, c, d, ans = 0, t1 = 0, t2;
    cin >> a >> b >> c >> d;
    if(b + c == 0) {
        cout << max(a, b) << '\n';
        return 0;
    }
    t1 += a + c;
    if(b > c) {
        t2 = c * 2 + 1;
        b -= 1;
        cout << t2 + ((b - c * 2) > 0);
    }
    else if(c > b) {
        t2 = b * 2 + 1;
        c -= 1;
        cout << t2 + ((c - b) > 0);
    }
    else {
        if((b + c) % 2 == 0) {
            cout << t1 + b + c;
        }
        else {
            cout << t1 + b + c;
        }
    }
}

    /*if(b > c) {
        t1 = b - c;
        if(t1 % 2 == 0) {
            b -= 1;
            t1 += 1;
        }
    }
    else if(b < c) {
        t1 = c - b;
        if(t1 % 2 == 0) {
            c -= 1;
            t1 += 1;
        }
    }
    else {
        if((b + c) % 2 == 0) {
            t1 += b + c - 1;
        }
        else {
            t1 += b + c;
        }
        cout << t1 + a + b + 1;
        return 0;
    }
    if(a != 0) {
        t1 += 1;
    }
    if(b != 0) {
        t1 += 1;
    }
    cout << t1 + a + b << '\n';

}*/

/*

def max_chain_length(a, b, c, d):
 """
 Функция для вычисления максимальной длины цепочки.

 Args:
  a: Количество учеников с белыми перчатками на обеих руках.
  b: Количество учеников с белой перчаткой на правой руке и черной на левой.
  c: Количество учеников с черной перчаткой на правой руке и белой на левой.
  d: Количество учеников с черными перчатками на обеих руках.

 Returns:
  Максимальная длина цепочки.
 """

 # Сначала соединяем учеников с одинаковыми перчатками на обеих руках
 max_length = min(a, d) # Количество пар "белая-белая" и "черная-черная"

 # Затем соединяем оставшихся учеников с разными перчатками
 remaining_b = b - max_length # Оставшиеся ученики с "белая-черная"
 remaining_c = c - max_length # Оставшиеся ученики с "черная-белая"

 # Дополнительная длина цепочки от пар с разными перчатками
 max_length += min(remaining_b, remaining_c)

 return max_length

# Ввод данных
a, b, c, d = map(int, input().split())

# Вывод результата
print(max_chain_length(a, b, c, d))
*/
