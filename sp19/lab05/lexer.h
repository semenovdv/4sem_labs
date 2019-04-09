//                 lexer.h 2019
#ifndef LEXER_H
#define LEXER_H
#include "baselexer.h"
//********************************************
//*        Developed by  xxx		     *
//*             (c)  2019                    *
//********************************************
class tLexer:public tBaseLexer{
public:
// персональный код разработчика
 std::string Authentication()const{
                     return "xxx"
                +std::string("2019");}
//конструктор
 tLexer():tBaseLexer(){
//создать автоматы:

//  ноль Azero
    addstr  (Azero,0,"+-", 2);
    addstr  (Azero,0,"0",  1);
    addstr  (Azero,2,"0",  1);
  Azero.final(1);

//________________________________________

// число
/*
    addstr  (Adec,0,"0",   3);
    addstr  (Adec,3,".",   2);
    addrange(Adec,0,'1','9',1);
    addstr  (Adec,1,".",   2);
    addrange(Adec,2,'0','9',2);
  Adec.final(1);
  Adec.final(2);
*/

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
  addrange(Adec, 6, '0', '9', 7);
  addrange(Adec, 7, '0', '9', 7);

//......................
 Adec.final(2);
 Adec.final(5);
 Adec.final(7);
//________________________________________

// идентификатор
    addrange(Aid,0,'a','z',1);
    addrange(Aid,0,'A','Z',1);
    addstr(Aid, 0, "!", 1);

    addrange(Aid,1,'a','z',1);
    addrange(Aid,1,'A','Z',1);
    addrange(Aid,1,'0','9',1);
    addstr(Aid,1,"-",1);
    addstr(Aid,1,"!",1);

    addstr(Aid, 0, "?", 2);
    addstr(Aid, 1, "?", 2);

    addstr(Aid, 2, "-", 1);
    addrange(Aid,2, 'a', 'z', 1);
    addrange(Aid,2, 'A', 'Z', 1);
    addrange(Aid,2, '0', '9', 1);
    addstr(Aid, 2, "!", 3);
    addstr(Aid, 2, "?", 2);

    addrange(Aid, 3, 'a', 'z', 1);
    addrange(Aid, 3, 'A', 'Z', 1);
    addrange(Aid, 3, '0', '9', 1);
    addstr(Aid, 3, "!", 1); // без - 
    addstr(Aid, 3, "?", 2);


  Aid.final(1);
//________________________________________

// идентификатор предиката
    addstr(Aidq, 0, "-", 1);
    addrange(Aidq, 0, 'a', 'z', 1);
    addrange(Aidq, 0, 'A', 'Z', 1);
    addstr(Aidq, 0, "!", 2);


    addstr(Aidq, 0, "?", 3);
 
    addstr(Aidq, 1, "?", 3);
    addrange(Aidq, 1, 'a', 'z', 1);
    addrange(Aidq, 1, 'A', 'Z', 1);
    addrange(Aidq, 1, '0', '9', 1);
    addstr(Aidq, 1, "-", 1); 
    addstr(Aidq, 1, "!", 2);
    
    addstr(Aidq, 3, "?", 3);
    addstr(Aidq, 3, "!", 2);
    addrange(Aidq, 3, 'a', 'z', 1);  
    addrange(Aidq, 3, 'A', 'Z', 1);
    addrange(Aidq, 3, '0', '9', 1);
    addstr(Aidq, 3, "-", 1);


    addstr(Aidq, 2, "-", 1);
    addrange(Aidq, 2, 'a', 'z', 1);
    addrange(Aidq, 2, 'A', 'Z', 1);
    addrange(Aidq, 2, '0', '9', 1);

    
    

  Aidq.final(3);
}
};
#endif

