6lab: TBigInt.h main.o TBigInt.o
	g++ -std=c++11 -Wall -pedantic -Werror -Wall -Wno-sign-compare -Wno-long-long -lm -g -o 6lab TBigInt.o main.o
main.o: TBigInt.h main.cpp
	g++ -std=c++11 -Wall -pedantic -Werror -Wall -Wno-sign-compare -Wno-long-long -lm -g -c -o main.o main.cpp
TBigInt.o: TBigInt.h TBigInt.cpp
	g++ -std=c++11 -Wall -pedantic -Werror -Wall -Wno-sign-compare -Wno-long-long -lm -g -c -o TBigInt.o TBigInt.cpp