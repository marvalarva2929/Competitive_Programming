#include <iostream>
#include <fstream>
#define nl '\n'
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        int maxU = 0, minD = 0, minR = 0, maxR = 0;
        int cx = 0, cy = 0;
        int rturns = 0, lturns = 0;
        int cdir;
        for (int i = 0; i < s.size() - 1; i++) {
            char c = s[i];
            if (c == 'N') {
                if (s[i + 1] != 'N') {
                    if (s[i + 1] == 'E') {
                        rturns++;
                    } else if (s[i + 1] == 'W') {
                        lturns++;
                    }
                }
            } else if (c == 'E') {
                if (s[i + 1] != 'E') {
                    if (s[i + 1] == 'N') {
                        lturns++;
                    } else if (s[i + 1] == 'S') {
                        rturns++;
                    }
                }
            } else if (c == 'S') {
                if (s[i + 1] != 'S') {
                    if (s[i + 1] == 'E') {
                        lturns++;
                    } else if (s[i + 1] == 'W') {
                        rturns++;
                    }
                }
            } else if (c == 'W') {
                if (s[i + 1] != 'W') {
                    if (s[i + 1] == 'N') {
                        rturns++;
                    } else if (s[i + 1] == 'S') {
                        lturns++;
                    }
                }
            }
        }
        cout << (lturns > rturns ? "CCW" : "CW") << nl;
    }
}