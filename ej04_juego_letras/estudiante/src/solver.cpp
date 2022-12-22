#include <string>
#include <vector>
#include <utility>
#include <set>
#include "dictionary.h"
#include <cmath>
#include <letters_set.h>
#include <solver.h>

using namespace std;

    Solver::Solver(const Dictionary & dict, const LetterSet & letters_set){
        diccionario=dict;
        conjunto_letras=letters_set;
    }

    pair<vector<string>,int> Solver::getSolutions(const vector<char> & available_letters,bool score_game){

        diccionario.
    }