#include <iostream>
#define nl '\n'
#define MAX (int)1e6
using namespace std;
int dp[MAX][2];

int main() {
    string a;
    cin >> a;
    for (int i = 1; i < a.size(); i++) {
        char b = a[i];
        char c = a[i - 1];
        if (c == 'A' && b == 'B') {
            int s = i - 1;
            while (s-- > 1) {
                if (a[s - 1] == 'B' && a[s] == 'A') {
                    cout << "YES" << nl;
                    return 0;
                }
            }
            s = i;
            while (s++ < a.size() + 1) {
                if (a[s] == 'B' && a[s + 1] == 'A') {
                    cout << "YES" << nl;
                    return 0;
                }
            }
        } else if (c == 'B' && b == 'A') {
            int s = i - 1;
            while (s-- > 1) {
                if (a[s - 1] == 'A' && a[s] == 'B') {
                    cout << "YES" << nl;
                    return 0;
                }
            }
            s = i;
            while (s++ < a.size() - 1) {
                if (a[s] == 'A' && a[s + 1] == 'B') {
                    cout << "YES" << nl;
                    return 0;
                }
            }
        }
    }
    cout << "NO" << nl;
}