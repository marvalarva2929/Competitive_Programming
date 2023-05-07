#include <iostream>
#include <cmath>
#define nl '\n'
using namespace std;

int main() {
    long long t;
    cin >> t;
    for (int q = 0; q < t; q++) {
        long long n;
        cin >> n;
        long long min_factor = n;
        for (long long i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) {
                min_factor = i;   
                break;
            }
        }
        long long a = n / min_factor;
        long long b = n - a;
        cout << a << ' ' << b << nl;
    }
}