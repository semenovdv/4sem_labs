//               testadec.cpp
#include <iostream>
#include <iomanip>
#include "fsm.h"
using namespace std;

int main()
{
  tFSM Adec;
///////////////////////
//  �������� �������
  addstr(Adec,0,"0",1);
  addrange(Adec,0,'1','9',2);
  addrange(Adec,2,'0','9',2);
  addstr(Adec, 0, "+-", 3);
  addstr(Adec,3, "0", 1);
  addrange(Adec,3,'1','9',2);
  addstr(Adec, 1, "eE", 4);
  addstr(Adec, 2, "eE", 4);
  addstr(Adec,0, ".", 5);
  addstr(Adec,3, ".", 5);
  addstr(Adec,2, ".", 5);
  addstr(Adec,1, ".", 5);
  addrange(Adec, 5, '0', '9', 5);
  addstr(Adec, 5, "eE", 4);
  addstr(Adec, 4, "+-", 6);
  addstr(Adec,4, "0", 7);
  addrange(Adec, 6, '0', '9', 6);

//......................
 Adec.final(2);
 Adec.final(5);
 Adec.final(6);
 Adec.final(7);
//......................
///////////////////////
  cout << "*** xxx Adec "
       << "size=" << Adec.size()
       << " ***\n";
  cout << endl;

  while(true)
 {
  char input[81];
  cout << ">";
  cin.getline(input,81);
  if(!*input) break;
  int res = Adec.apply(input);
  cout << setw(res?res+1:0) << "^"
       << endl;
 }
 return 0;
}

