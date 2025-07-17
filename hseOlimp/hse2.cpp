#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

char _1 = '#';
char _0 = '.';

unordered_set<pair<int, int>> get_bars(const string& s) {
    unordered_set<pair<int, int>> get_bars;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == _1) {
            if (i == 0 || s[i - 1] == _0) {
                int L = i;
                if (i == s.length() - 1 || s[i + 1] == _0) {
                    int R = i;
                    rb.insert(make_pair(L, R));
                }
            }
        }
    }
    return rb;
}

int get_rectangles_count(const string& ss_prev, const string& ss, unordered_set<pair<int, int>>& rect, int rect_count) {
    auto bar_is_white = [&](const string& s, int L, int R) {
        return s.substr(L, R - L + 1) == string(R - L + 1, _0);
    };

    auto cur_brs = get_bars(ss);
    auto finish_rect = rect;
    for (auto [L, R] : cur_brs) {
        finish_rect.erase(make_pair(L, R));
    }
    rect = move(finish_rect);
    for (auto [L, R] : finish_rect) {
        if (bar_is_white(ss, L, R)) {
            rect_count++;
        }
    }

    auto new_rect = cur_brs;
    for (auto [L, R] : rect) {
        new_rect.erase(make_pair(L, R));
    }
    for (auto [L, R] : new_rect) {
        if (ss_prev.empty() || bar_is_white(ss_prev, L, R)) {
            rect.insert(make_pair(L, R));
        }
    }
    return rect_count;
}

int main() {
    int n, m;
    cout << "n, m->";
    cin >> n >> m;
    unordered_set<pair<int, int>> rectangles;
    int rectangles_count = 0;
    string s_prev, s;
    for (int i = 0; i < n; i++) {
        s_prev = s;
        cout << "->";
        cin >> s;
        rectangles_count = get_rectangles_count(s_prev, s, rectangles, rectangles_count);
    }
    cout << rectangles_count + rectangles.size() << endl;
    return 0;
}

