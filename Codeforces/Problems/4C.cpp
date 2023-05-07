#include <iostream>
#include <map>
#define nl "\n"
using namespace std;

int main() {
  int n;
  cin >> n;
  map<string,int> names;
  for (int i = 0; i < n; i++) {
    string name;
    cin >> name;
    names[name]++;
    names[name] == 1 ? cout << "OK" << nl : cout << name << names[name] - 1 << nl;
  }
  
}