#include <iostream>
#include <cmath>
#include <string.h>
#define nl "\n"
using namespace std;

int numOfDigits(int n) {
  int i = 0;
    while(n > 0) {n /= 10; i++;}
    return i;
}

long long karatsuba(string x, string y) {
    while(y.size() < x.size()) y = "0" + y;
    while(y.size() > x.size()) x = "0" + x;
    int n = x.size();
    if(n == 1){
      return (long long) stoll(x) * stoll(y);}
    string a = x.substr(0, x.size()/2),
         b = x.substr(x.size()/2, x.size()),
         c = y.substr(0, y.size()/2),
         d = y.substr(y.size()/2, y.size());
    long long ac = karatsuba(a, c);
//    cout << "ac " << ac << nl;
    long long bd = karatsuba(b, d);
//    cout << "bd " << bd << nl;
    long long ad_plus_bc = (karatsuba(to_string(stoll(a) + stoll(b)) , to_string(stoll(c) + stoll(d))) - ac - bd) * pow(10, x.size() - n/2);
//    cout << "adbc" << ad_plus_bc << nl;
    return (long long) (ac  * pow(10, n)) + bd + ad_plus_bc;
}

int main() {
    string x, y;
    cin >> x >> y;
    cout << karatsuba(x, y);
}