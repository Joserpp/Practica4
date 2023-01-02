#include <string>
#include <vector>
#include <utility>
#include <set>
#include "dictionary.h"
#include <cmath>
#include "letter_set.h"

using namespace std;

class Solver{

    private:

     Dictionary diccionario;

     LetterSet conjunto_letras;
 

    public:

     Solver(const Dictionary & dict,const LetterSet & letters_set);

     pair<vector<string>,int>getSolutions(const vector<char> & available_letters,bool score_game);

    







};