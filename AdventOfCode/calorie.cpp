#include <sstream>
#include <iostream>
#include <queue>
#include <fstream>
#define nl '\n'
using namespace std;

int main() {
    ifstream fin("cal.in");
    ofstream fout("cal.out");
    stringstream ss;
    string s;
    priority_queue<int> vals;
    int x = 0;
    while (getline(fin, s, nl)) {
        if (s.empty()) {
            vals.push(x);
            x = 0;
        } else {
            x += stoi(s);
        }
    }

    int a = vals.top();
    vals.pop();
    int b = vals.top();
    vals.pop();
    int c = vals.top();
    vals.pop();
    cout << a + b + c << nl;
}