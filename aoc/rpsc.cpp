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

unordered_map<char, int> scores = {
    {'X', 1},
    {'Y', 2},
    {'Z', 3},
    {'A', 1},
    {'B', 2},
    {'C', 3},
};

int32_t main() {
    int rock = 1;
    int paper = 2;
    int scissors = 3;
    int loss = 0;
    int draw = 3;
    int win = 6;
    ifstream fin("rps.in");
    char one, two;
    int score = 0;
    while (fin >> one >> two) {
        switch (one)
        {
        case 'A': // rock
            if (two == 'X') score += loss + scissors; // lose
            else if (two == 'Y') score += draw + rock; // draw
            else if (two == 'Z') score += win + paper; // win
            break;
        case 'B': // paper
            if (two == 'X') score += loss + rock; // lose
            else if (two == 'Y') score += draw + paper; // draw
            else if (two == 'Z') score += win + scissors; // win
            break;
        case 'C': // scissors
            if (two == 'X') score += loss + paper; // lose
            else if (two == 'Y') score += draw + scissors; // draw
            else if (two == 'Z') score += win + rock; // win
            break;
        default:
            break;
        }
    }
    cout << score << nl;
} 