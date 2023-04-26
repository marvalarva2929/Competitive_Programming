#include <iostream>
#include <algorithm>
#define nl '\n'
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int j = 0; j < n; j++) {
string s;
    cin >> s;
    string b = s;
    reverse(b.begin(), b.end());
    s += b;
    cout << s << nl;

    }
}