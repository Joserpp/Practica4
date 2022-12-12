#include <fstream>
#include <iostream>

#include "dictionary.h"
#include "letters_set.h"

using namespace std;

int main(int argc, char *argv[])
{
    if(argc != 3){
        cerr << "Los parametros son: " << endl;
        cerr << "1.- El fichero con el diccionario" << endl;
        cerr << "2.- El fichero con letras" << endl;
        return EXIT_FAILURE;
    }

    LetterSet letterset;
    Dictionary
}
