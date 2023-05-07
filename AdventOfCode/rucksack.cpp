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

int priority(char a) {
    int score = (int)a;
    if (a == toupper(a)) score -= 38;
    else if (a == tolower(a)) score -= 96; 
    return score;
}

int32_t main() {
    ifstream fin("ruck.in");
    string ss, sss, ssss;
    int score = 0;
    while (fin >> ss >> sss >> ssss) {
        unordered_map<char, int> count;
        set<char> s1;
        set<char> s2;
        set<char> s3;
        for (char a : ss) s1.insert(a);
        for (char a : sss) s2.insert(a);
        for (char a : ssss) s3.insert(a);
        for (char a : s1) count[a]++;
        for (char a : s2) count[a]++;
        for (char a : s3) count[a]++;
        for (auto a : count) 
            if (a.s == 3) {
                cout << a.f << nl;
                score += priority(a.f);
                break;
            }

    }    
    cout << score << nl;
} 