#include "TBigInt.h"

int main(){

    std::string BI1;
    std::string BI2;
    char op = ' ';
    while (std::cin >> BI1 >> BI2 ) {
        TBigInt S1(BI1);
        TBigInt S2(BI2);
        std::cin >> op;
        switch(op) {
            case '!': {
                std::cout << S1 << std::endl << S2 << std::endl;
            }
            break;

            case '+': {
                std::cout << S1 + S2 << std::endl;
            }
            break;

            case '-': {
                if (S1 < S2) {
                    std::cout << "Error" << std::endl;
                } else {
                    std::cout << S1 - S2 << std::endl;
                }
            }
            break;

            case '*': {
                std::cout << S1 * S2 << std::endl;
            }
            break;

            case '/': {
                if (S2 != TBigInt(0))
                    std::cout << S1 / S2 << std::endl;
                else 
                    std::cout << "Error" << std::endl;
            }
            break;

            case '^': {
                if (S1 == TBigInt(0))
                    if (S2 != TBigInt(0))
                        std::cout << S1.power(S2) << std::endl;
                    else 
                        std::cout << "Error" << std::endl;
                else 
                    std::cout << S1.power(S2) << std::endl;
            }
            break;
            case '<': {
                std::cout << ((S1 < S2) ? "true" : "false") << std::endl;
            }
            break;
            case '>': {
                std::cout << ((S1 > S2) ? "true" : "false") << std::endl;
            }
            break;
            case '=': {
                std::cout << ((S1 == S2) ? "true" : "false") << std::endl;
            }
            break;

            
        }
    }

    return 0;
}