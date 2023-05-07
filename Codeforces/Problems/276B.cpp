#include <iostream>
#include <map>
#define nl '\n'
using namespace std;

int main() {
    string s;
    map<char, int> charMap;
    cin >> s;
    int odds = 0;
    for (char c : s) charMap[c]++;
    for (char c : s) {
        if (charMap[c] % 2 == 1) odds++;
    }
    if (odds <= 1) cout << "First" << nl;
    else if (odds % 2 == 0) cout << "Second" << nl;
    else cout << "First" << nl;
}