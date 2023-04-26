using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'


signed main() {
    int n; cin >> n;
    bool a[n] = {};
    int e[n] = {};
    string s; cin >> s;
    int g = 0, h = 0;
    for (int i = 0; i < n; i++)
        a[i] = (s[i] == 'G');

    g = count(a, a + n, 1);
    h = n - g;

    int ans = 0;

    for (int i = 0; i < n; i++)
        cin >> e[i], e[i]--;

    int fg, fh;

    int i = 0;
    while (!a[i] && i < n) i++;
    fg = i;
    int gCovered = 0;
    bool ggs = false;
    for (int j = i; j <= e[i]; j++) {
        if (a[j]) gCovered++;
    }
    if (gCovered == g) ggs = true;

    if (ggs) {
        for (int j = 0; j < fg; j++)
            if (!a[j] && e[j] >= fg)
                ans++;
    }

    i = 0;
    while (a[i] && i < n) i++;
    fh = i;
    int hCovered = 0;
    bool hhs = false;
    for (int j = i; j <= e[i]; j++) {
        if (!a[j]) hCovered++;
    }
    if (hCovered == h) hhs = true;

    if (hhs)
        for (int j = 0; j < fh; j++)
            if (a[j] && e[j] >= fh)
                ans++;
    
    if (ggs && hhs) ans++;

    cout << ans << nl;


}