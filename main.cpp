#include <iostream>
#include <cstdio>
#include "automaton.hpp"

using namespace std;


int main(){

    int estados[] = {0, 1, 2, 3, 4};
    char alfabeto[] = {'x', 'X', '0', '1', '2', '3', '4', '5', '6', '7'};
    int estados_finales[] = {estados[2]};
    char w[15];
    bool isAcepted = false;

    Automaton a(estados, alfabeto, estados[0], estados_finales);

    scanf("%s", &w);
    printf("\n");

    //isAcepted = a.test("0x123456");
    isAcepted = a.test(w);

    printf("\nEnd of the processing");
    printf("\nResult: ");

    //*/
    if(isAcepted){
        printf("The string is recognized");
    }else{
        printf("The string is not recognized");
    }

    printf("\n\n");
    //*/

    return 0;
}
