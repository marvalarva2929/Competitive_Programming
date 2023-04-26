using namespace std;
#include <bits/stdc++.h>
#define nl '\n'
#define MAX (int)1e5 + 10
int pref[MAX];
int suff[MAX];

int ctoi(char a) {
    return a - 64;
}

bool equals(vector<int> a, vector<int> b) {
    for (int i = 0; i < a.size(); i++)
        if (a[i] != b[i])
            return false;

    return true;
}

void solve(string c) {
    stack<char> stroke;
    for (int i = 0; i < c.size(); i++) {
        pref[i + 1] = pref[i];
        while (!stroke.empty() && stroke.top() > c[i]) stroke.pop();
        if (stroke.empty() || stroke.top() < c[i]) {
            stroke.push(c[i]);
            pref[i + 1]++;
        }
    }

    stack<char> stroke2;
    reverse(c.begin(), c.end());
    for (int i = 0; i < c.size(); i++) {
        suff[i + 1] = suff[i];
        while (!stroke2.empty() && stroke2.top() > c[i]) stroke2.pop();
        if (stroke2.empty() || stroke2.top() < c[i]) {
            stroke2.push(c[i]);
            suff[i + 1]++;
        }
    }
}

int main() {
    int n, q; cin >> n >> q;
    string s; cin >> s;
    solve(s);
    for (int i = 0; i < q; i++) {
        int a, b; cin >> a >> b;
        cout << pref[a - 1] + suff[n - b] << nl;
    }
}