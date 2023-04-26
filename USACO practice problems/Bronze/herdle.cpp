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
#define print(x, y, z) for (int i = y; i <= z; i++) {cout << x[i] << " ";} cout << nl;
char g1[3][3];
char g2[3][3];

int32_t main() {
    unordered_map<char, int> c1;
    unordered_map<char, int> c2;
    unordered_map<char, int> inc;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++){
            cin >> g1[i][j];
            c1[g1[i][j]]++;
        }
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++){
            cin >> g2[i][j];
            c2[g2[i][j]]++;
        }
    int green = 0, yellow = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)     
            if (g1[i][j] != g2[i][j])
                inc[(g2[i][j])]++;
            else {green++; c1[g2[i][j]]--;}

    for (pair<char, int> i : inc) {
        yellow +=( min(i.second, c1[i.first]));
        // cout << i.first << ": " << i.second << ": " << c1[i.first] << nl;
    }
    cout << green << nl << yellow << nl;
} 
