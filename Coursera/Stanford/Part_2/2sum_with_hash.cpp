#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include <vector>
#include <set>
#include <chrono>
#define nl '\n'
using namespace std;

int main() {
    ifstream fin("sum.in");
    ofstream fout("sum.out");
    vector<long long> numbers;
    set<long long> sums;
    auto start = chrono::high_resolution_clock::now();
    while (!fin.eof()) {
        long long num;
        fin >> num;
        numbers.push_back(num);
    }
    sort(numbers.begin(), numbers.end());
    for (long long number : numbers) {
        vector<long long> subNumbers(lower_bound(numbers.begin(), numbers.end(), -number - 10000), upper_bound(numbers.begin(), numbers.end(), -number + 10000));
        for (long long subNumber : subNumbers) sums.insert(number + subNumber); 
    }
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << duration.count() << nl;
    fout << sums.size();
}