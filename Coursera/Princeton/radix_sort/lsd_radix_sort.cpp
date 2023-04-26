#include <iostream>
#include <map>
#include <vector>
#include <climits>
#define nl '\n'
using namespace std;

int charToInt(char n) { return n == ' ' ? 28 : int(n) - 96; }

vector<string> lsd_radix_sort(vector<string> toSort, int string_size) {
    vector<string> toReturn = toSort;
    vector<string> setTo = toReturn;
    for (int i = string_size - 1; i >= 0; i--) {
        int count[29];
        for (int i = 0; i < 29; i++) count[i] = 0;
        for (int j = 0; j < toReturn.size(); j++) 
            count[charToInt(toReturn[j][i]) + 1]++;
        for (int j = 1; j < 28; j++) 
            count[j] += count[j - 1];
        for (int j = 0; j < toReturn.size(); j++) {
            char letter = toReturn[j][i];
            // cout << letter << count[charToInt(letter)] << " ";
            setTo[count[charToInt(letter)]] = toReturn[j];
            count[charToInt(letter)]++;
        }
        // cout << nl;
        toReturn = setTo;
    }
    return toReturn;
}

int main() {
    int n, maxLegnth = INT_MIN;
    cin >> n;
    vector<string> toSort(n);
    for (int i = 0; i < n; i++) 
        cin >> toSort[i];
    for (string s : toSort) maxLegnth = max(maxLegnth, (int) s.size());
    cout << maxLegnth;
    for (string&s : toSort) {
        while(s.size() < maxLegnth) s += ' ';
    }
    vector<string> sorted = lsd_radix_sort(toSort, maxLegnth);
    for (string s : sorted) {
        cout << s << nl;
    }
}   