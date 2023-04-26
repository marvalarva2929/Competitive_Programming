#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <queue>
#define nl '\n'
using namespace std;

int main() {
    ifstream fin("family.in");
    ofstream fout("family.out");
    int n;
    fin >> n;
    map<string, vector<string>> adj;
    string s1, s2;
    fin >> s1 >> s2;
    for (int i = 0; i < n; i++) {
        string s, ss;
        fin >> s >> ss;
        adj[ss].push_back(s);
    }

    queue<pair<string, int>> gen1;
    queue<pair<string, int>> gen2;
    
    gen1.push({s1, 0});
    gen2.push({s2, 0});
    map<string, bool> visited;
    map<string, bool> visited2;
    map<string, int> p1;
    map<string, int> p2;
    bool yes = false;
    string o;
    int op;
    string t;
    int tp;

    while ((!gen1.empty() || !gen2.empty())) {
        o = (gen1.front().first);
        op = (gen1.front().second);
        gen1.pop();
        t = (gen2.front().first);
        tp = (gen2.front().second);
        gen2.pop();

        p1[o] = op;
        p2[t] = tp;

        fout << o << nl;

        if (!visited[o]) {
            visited[o] = true;
            for (string a : adj[o]) 
                if (!visited[a]) 
                    gen1.push({a, op + 1});
                
        }

        if (!visited2[t]) {
            visited2[t] = true;
            for (string a : adj[t]) 
                if (!visited2[a]) 
                    gen2.push({a, tp + 1});

        }

        fout << "e" << nl;
        // if (visited2[o]) {
        //     // yes = true;
        //     if (p2[o] == 0) {
        //         fout << "e" << nl;
        //         // if (p1[o] >= 2) {
        //         //     fout << s2 << " is the ";
        //         //     for (int i = 0; i < p1[o] - 2; i++) fout << "great-";
        //         //     fout << "grand-mother of " << s1;
        //         // } else {
        //         //     fout << s2 << " is the mother of " << s1 << nl;
        //         // }
        //     } else if (p2[o] == 1) {
        //         fout << "e" << nl;
        //         // if (p1[o] >= 2) {
        //         //     fout << s2 << " is the ";
        //         //     for (int i = 0; i < p1[o] - 2; i++) fout << "great-";
        //         //     fout << "aunt of " << s1 << nl;
        //         // } else {
        //         //     fout << s2 << " is the sibling of " << s1 << nl;
        //         // }
        //     } else {
        //         fout << s2 << " is the cousin of " << s1 << nl;
        //     }
        //     break;
        // }

        // if (visited[t]) {
        //     yes = true;
        //     if (p1[t] == 0) {
        //         if (p2[t] >= 2) {
        //             fout << s1 << " is the ";
        //             for (int i = 0; i < p2[t] - 2; i++) fout << "great-";
        //             fout << "grand-mother of " << s2 << nl;
        //         } else {
        //             fout << s1 << " is the mother of " << s2 << nl;
        //         }
        //     } else if (p1[t] == 1) {
        //         if (p2[t] >= 2) {
        //             fout << s1 << " is the ";
        //             for (int i = 0; i < p2[t] - 2; i++) fout << "great-";
        //             fout << "aunt of " << s2;
        //         } else {
        //             fout << s1 << " is the sibling of " << s2 << nl;
        //         }
        //     } else {
        //         fout << s1 << " is the cousin of " << s2 << nl;
        //     }
        //     break;
        // }
    }

    if (gen1.empty() && gen2.empty() && !visited2[s1] && !visited[s2]) fout << "NOT RELATED" << nl;
}