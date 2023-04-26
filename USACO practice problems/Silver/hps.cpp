using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'

signed main() {
    ifstream cin("hps.in");
    ofstream cout("hps.out");
    int n; cin >> n;
    int a[n] = {};
    for (int i = 0; i < n; i++) {
        char c; cin >> c;
        a[i] = (c == 'H' ? 0 : c == 'P' ? 1 : 2);
        // H = 0, P = 1, S = 2;
    }

    int psum[n + 1][3] = {};
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++)
            psum[i][j] = psum[i - 1][j];
        psum[i][a[i - 1]]++;
    }

    int b = 0;
    for (int i = 0; i < 3; i++)
        b = max(b, psum[n][i]);

    int h = 0, s = 1, p = 2;

    for (int i = 1; i <= n; i++) {
        b = max(b, psum[i][s] + (psum[n][p] - psum[i][p])); // h -> s
        b = max(b, psum[i][p] + (psum[n][s] - psum[i][s])); // s -> h
        b = max(b, psum[i][h] + (psum[n][p] - psum[i][p])); // p -> s
        b = max(b, psum[i][p] + (psum[n][h] - psum[i][h])); // s -> p
        b = max(b, psum[i][s] + (psum[n][h] - psum[i][h])); // h -> p
        b = max(b, psum[i][h] + (psum[n][s] - psum[i][s])); // p -> h
    }

    cout << b << nl;

}