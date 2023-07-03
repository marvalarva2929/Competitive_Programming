#include <bits/stdc++.h>
#define int long long
#define nl '\n'

using namespace std;

signed main() {
    string a, b;
    cin >> a >> b;
    int movement = 0;
    int swaps = 0;

    for (char c : b)
        if (c == 'B')
            movement++;
        else if (c == 'K')
            movement--;
        else if (c == 'P')
            swaps++;
        else if (c == 'T')
            swaps--;

    for (char &c : a) {
        c += (movement % 26);
        c = ((c - 'a') % 26) + 'a';
    }

    if (swaps > 0)
        swaps = swaps % a.size(),
        a = a.substr(a.size() - swaps) + a,
        a = a.substr(0, a.size() - swaps);
    else if (swaps < 0) 
        swaps = ((-swaps) % a.size()),
        a = a + a.substr(0, swaps),
        a = a.substr(swaps);

    cout << a << nl;

}
