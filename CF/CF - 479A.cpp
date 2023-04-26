#include <iostream>

using namespace std;

int main() {
  int a, b, c, answer = 0;
  cin >> a >> b >> c;
  answer = max(answer, a+b+c);
  answer = max(answer, a*b*c);
  answer = max(answer, (a+b)*c);
  answer = max(answer, a*(b+c));
  answer = max(answer, a+(b*c));
  answer = max(answer, (a*b)+c);
  cout << answer << "\n";



}