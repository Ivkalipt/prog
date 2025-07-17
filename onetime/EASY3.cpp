#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0);
#define all(a) a.begin(), a.end()
#define S second
#define F first

using namespace std;
using ll = long long;
using vll = vector<long long>;

const ll inf = 1e16, maxn = 2e5;

struct Date {
  ll day, month, year;
};

bool leap(ll year) {
  if (year % 4 != 0)
    return false;
  if (year % 100 != 0)
    return true;
  return (year % 400 == 0);
}

ll dnm(ll month, ll year) {
  if (month == 2)
    return leap(year) ? 29 : 28;
  if (month == 4 || month == 6 || month == 9 || month == 11)
    return 30;
  return 31;
}

ll dtdays(const Date &date) {
  ll days = 0;
  for (ll y = 1; y < date.year; ++y) {
    days += leap(y) ? 366 : 365;
  }
  for (ll m = 1; m < date.month; ++m) {
    days += dnm(m, date.year);
  }
  days += date.day - 1;
  return days;
}

Date dtdate(ll days) {
  Date date = {1, 1, 1};
  while (days >= (leap(date.year) ? 366 : 365)) {
    days -= leap(date.year) ? 366 : 365;
    date.year++;
  }
  while (days >= dnm(date.month, date.year)) {
    days -= dnm(date.month, date.year);
    date.month++;
  }
  date.day += days;
  return date;
}

void addYears(Date &date, ll years) {
  date.year += years;
  if (date.month == 2 && date.day == 29 && !leap(date.year)) {
    date.day = 28;
  }
}

int main() {
  ll N;
  cin >> N;
  vector<pair<ll, ll>> llerv;
  vector<ll> original_indices;
  for (ll i = 0; i < N; ++i) {
    Date birth, death;
    cin >> birth.day >> birth.month >> birth.year >> death.day >> death.month >>
        death.year;
    Date start = birth;
    addYears(start, 18);
    Date end = birth;
    addYears(end, 80);
    if (dtdays(end) > dtdays(death)) {
      end = death;
    }
    ll start_days = dtdays(start);
    ll end_days = dtdays(end);
    if (start_days < end_days) {
      llerv.emplace_back(start_days, end_days);
      original_indices.push_back(i + 1);
    }
  }

  if (llerv.empty()) {
    cout << 0 << endl;
    return 0;
  }

  vector<pair<ll, ll>> events;
  for (ll i = 0; i < llerv.size(); ++i) {
    events.emplace_back(llerv[i].first, i + 1);
    events.emplace_back(llerv[i].S, -i - 1);
  }
  sort(events.begin(), events.end());

  set<ll> curr;
  set<set<ll>> max_sets;
  for (const auto &event : events) {
    ll id = event.S;
    if (id > 0) {
      curr.insert(id);
    } else {
      curr.erase(-id);
    }
    if (!curr.empty()) {
      max_sets.insert(curr);
    }
  }

  vector<set<ll>> result;
  for (const auto &s : max_sets) {
    bool is_maximal = true;
    for (const auto &other : max_sets) {
      if (s != other &&
          includes(other.begin(), other.end(), s.begin(), s.end())) {
        is_maximal = false;
        break;
      }
    }
    if (is_maximal) {
      result.push_back(s);
    }
  }

  if (result.empty()) {
    cout << 0 << endl;
    return 0;
  }

  for (const auto &s : result) {
    bool first = true;
    for (ll id : s) {
      if (!first)
        cout << " ";
      cout << original_indices[id - 1];
      first = false;
    }
    cout << endl;
  }

  return 0;
}
