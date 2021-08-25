#include "automaton.hpp"
#include <cstdio>

Automaton::Automaton(int* _states, char* _alphabet, int _init_state, int* _final_states){

    states = _states;
    alphabet  = _alphabet;
    init_state = _init_state;
    final_states = _final_states;

}


int Automaton::delta(int q, char sigma){

    switch(q){

    case 0:
        if(sigma == '0') return 1;
        if(sigma == '\0') return 0;
        else return -1;
    break;

    case 1:
        if(sigma == 'x' || sigma == 'X') return 2;
        if(sigma == '\0') return 1;
        else return -1;
    break;

    case 2:
        for(int i = 0; i < 8; i++){
            if(sigma == alphabet[i + 2]) return 3;
        }
        if(sigma == '\0') return 2;
        return -1;
    break;

    case 3:
        for(int i = 0; i < 8; i++){
            if(sigma == alphabet[i + 2]) return 2;
        }
        if(sigma == '\0') return 3;
        return -1;
    break;

    default:
        return -1;
    }
}

int Automaton::process(int q, char* w){

    int estado = delta(q, '\0');
    int i = 0;

    while(w[i] != '\0'){

        printf("[%i, %c]: ", estado, w[i]);
        if(estado == 2) printf("Acceptance\n");
        else printf("Rejection\n");

        estado = delta(estado, w[i]);
        i++;
    }

    printf("[%i, -]: ", estado);
    if(estado == 2) printf("Acceptance\n");
    else printf("Rejection\n");


    return estado;
}

bool Automaton::test(char* w){
    if(process(0, w) == 2) return true;
    else return false;
}
