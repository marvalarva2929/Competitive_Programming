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

unordered_map<string, int> months = {
    {"Ox", 0},
    {"Tiger", 1},
    {"Rabbit", 2},
    {"Dragon", 3},
    {"Snake", 4},
    {"Horse", 5},
    {"Goat", 6},
    {"Monkey", 7},
    {"Rooster", 8},
    {"Dog", 9},
    {"Pig", 10},
    {"Rat", 11},
};

unordered_map<string, int> birthYear;
unordered_map<string, string> birthMonth;

int32_t main() {
    int n;
    cin >> n;
    int ans = 0;
    int finAns = 0;
    birthYear["Bessie"] = 0;
    birthMonth["Bessie"] = "Ox";
    for (int i = 0; i < n; i++) {
        string name1, born, in, order, month, year, from, name2;
        cin >> name1 >> born >> in >> order >> month >> year >> from >> name2;
        birthMonth[name1] = month;

        if (order == "previous") {
            int diffBetween = months[birthMonth[name2]] + (12 - months[month]);
            if (months[birthMonth[name1]] < months[birthMonth[name2]])
                diffBetween = months[birthMonth[name2]] - months[month];
            birthYear[name1] = birthYear[name2] - diffBetween;
        } else if (order == "next") {
            int diffBetween = (12 - months[birthMonth[name2]]) + (months[month]);
            if (months[month] > months[birthMonth[name2]])
                diffBetween = months[month] - months[birthMonth[name2]];
            birthYear[name1] = birthYear[name2] + diffBetween;
        }
        // cout << name1 << " : " << birthYear[name1] << nl;
        if (name1 == "Mildred") finAns = ans;
    }
    cout << abs(birthYear["Elsie"]) << nl;
} 