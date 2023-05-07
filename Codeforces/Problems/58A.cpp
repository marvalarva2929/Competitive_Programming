#include <iostream>
#include <map>
using namespace std;

int main () {
  string ss, s = "hello";
  int j = 4;
  cin >> ss;

  for (int i = ss.size() -1; i >= 0; i--){
    if (s[j] == ss[i]) {
      s.pop_back();
      j--;
      if (j == -1) break;
    }
  }

  s.size() == 0 ? cout << "YES" << "\n" : cout << "NO" << "\n" ; 
}
