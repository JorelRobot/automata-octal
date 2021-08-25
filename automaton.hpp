#ifndef automaton_hpp
#define automaton_hpp

class Automaton{

private:

    int* states;
    char* alphabet;
    int init_state;
    int *final_states;

public:

    Automaton(int*, char*, int, int*); // (int*: States, char*: Alphabet, int: Initial State, int*: Final States)

    int delta(int, char);
    int process(int, char*);
    bool test(char*);
};

#endif // automaton.hpp
