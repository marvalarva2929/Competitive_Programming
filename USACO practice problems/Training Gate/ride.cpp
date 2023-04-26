/*
  NAME: joshvig1
  LANG: C++
  PROG: ride
*/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;


int getNumberOf(string text){
      int number;
      int prevNumber=1;
      for(int i=0; i< (text.length()); i++) {
        int currentNumber = ((int)text[i] - 64);
        number = (prevNumber) * currentNumber;
        prevNumber = number;
      }
      return number;
    }

bool checkModOf(int num1, int num2) {
      if((num1 % 47) == (num2 % 47)){
        return true;
      }else{
        return false;
      }
    }

int main() {
ifstream fin("ride.in");
ofstream fout("ride.out");
string ln1, ln2;
fin >> ln1 >> ln2;  
int num1;
int num2;
  
num1 = getNumberOf(ln1);
num2 = getNumberOf(ln2);

if(checkModOf(num1, num2)){
  fout << "GO\n"  ;
} else {
  fout << "STAY\n";
}
fin.close();
fout.close();

}






