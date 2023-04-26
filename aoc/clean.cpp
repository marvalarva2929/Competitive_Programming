using namespace std;
#include <bits/stdc++.h>
#include <string.h>
typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int,int>> vpi;
#define pb push_back
#define int long long
#define nl '\n'
#define rsz resize
#define sz(x) int(x.size())
#define all(x) begin(x), end(x)
#define f first
#define s second


int32_t main() {
    ifstream fin("clean.in");
    string check;
    int count = 0;
    while (getline(fin, check, '\n')) {
        int x1, x2, y1, y2;
        stringstream ss;
        ss << check;
        string range1;
        string range2;
        stringstream sss;
        getline(ss, range1, ',');
        getline(ss, range2);
        int a, b, c, d;
        sss << range1;
        sss >> a >> b;
        sss.clear();
        sss << range2;
        sss >> c >> d;
        b = -b;
        d = -d;

        if (b >= c && a <= d) {
            count++;
            cout << a << ": " << b << ": " << c << ": " << d << nl;
        }
    }
    cout << count << nl;
} 