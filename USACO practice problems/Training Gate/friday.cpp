/*
  ID: joshvig1
  LANG: C++
  TASK: friday
*/
#include <iostream>
#include <fstream>

using namespace std;

int main() {
  ifstream fin = ifstream("friday.in");
  ofstream fout = ofstream("friday.out");
  int N;
  int dayval; 
  int days[7] = {0,0,0,0,0,0,0}; //day[0] is Saturday
  fin >> N;
      int prevm = 0;

  for(int i = 0; i < N; i ++){
    dayval = ((i + ((i - 1)/4)) % 7); //find out how many days past Saturday the 13th is
    // if((i > 200) ) dayval -= ((i - 100) / 100); //acount for century years.
    if(i > 200) dayval -= 1;
    if(i > 300) dayval -= 1;
    // if(i == 300) cout << dayval << endl;
    if(dayval < 0) dayval = 7 + dayval;
    int leap = 0;
    if((i != 0) && (i % 100 != 0  || (i == 100))){
      leap = ((i % 4 == 0 )) ? 1 : 0;
    }    
      // if(i == 100) cout << leap;
    int prev = 0;
    days[dayval] += 1;
    prev = dayval;
    days[((prev + 31) % 7)] += 1;
    prev = (dayval + 31);
    days[((prev + 28 + leap) % 7)] += 1;
    prev = (dayval + 59);
    days[((prev + 31 + leap) % 7)] += 1;
    prev = (dayval + 90);
    days[((prev + 30 + leap) % 7)] += 1;
    prev = (dayval + 120);
    days[((prev + 31 + leap) % 7)] += 1;
    prev = (dayval + 151);
    days[((prev + 30 + leap) % 7)] += 1;
    prev = (dayval + 181);
    days[((prev + 31 + leap) % 7)] += 1;
    prev = (dayval + 212);
    days[((prev + 31 + leap) % 7)] += 1;
    prev = (dayval + 243);
    days[((prev + 30 + leap) % 7)] += 1;
    prev = (dayval + 273);
    days[((prev + 31 + leap) % 7)] += 1;
    prev = (dayval + 304);
    days[((prev + 30 + leap) % 7)] += 1;
    cout << 1900 + i << ": " << days[2]  - prevm<< endl;
    prevm = days[2];
  }
  fout << days[0] << " " << days[1] << " " << days[2] << " "  << days[3] << " "  << days[4] << " " << days[5] << " " << days[6] << endl;
}