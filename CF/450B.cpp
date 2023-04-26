#include <iostream>
#define nl '\n'
using namespace std;

int main() {
    long long x, y, z = y, n;
    cin >> x >> y >> n;
    long long ans[6];
    ans[0] = x;
    ans[1] = y;
    for (int i = 2; i < 6; i++) {
        z = y - x;
        x = y; 
        y = z;
        ans[i] = z;
    }
    long long a = ans[(n - 1) % 6];
    if (a < 0) cout << (1000000007 + (a % 1000000007)) % 1000000007 << nl;
    else if (a >= 0) cout << a % 1000000007 << nl;
}