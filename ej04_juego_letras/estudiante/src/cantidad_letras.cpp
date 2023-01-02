#include <fstream>
#include <iostream>

#include "dictionary.h"
#include "letter_set.h"

using namespace std;

int main(int argc, char *argv[])
{
    if(argc != 3){
        cerr << "Los parametros son: " << endl;
        cerr << "1.- El fichero con el diccionario" << endl;
        cerr << "2.- El fichero con letras" << endl;
        return EXIT_FAILURE;
    }

    ifstream fi1(argv[1]);

    ifstream fi2(argv[2]);

    string cad;

    LetterSet conjunto;
    Dictionary diccionario;

    while(fi1 >> cad)
        diccionario.insert(cad);

    fi2 >> conjunto;

    pair<int,int> solucion;

    char letra='a';

    cout << "Letra Usos Ocurrencias "<< endl;

    while(letra!='{'){

        solucion.second=diccionario.getTotalUsages(letra);
        solucion.first=diccionario.getOccurrences(letra);

        if(solucion.second!=0 || solucion.first!=0){
            char car=toupper(letra);
            cout << car << " " << solucion.second << " " << solucion.first << endl;
        }
        
        letra++;
    }

    
}



