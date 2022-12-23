#include <fstream>
#include <iostream>

#include "solver.h"

using namespace std;

int main(int argc, char *argv[])
{
  if(argc != 3){
    cout << "Los parametros son: " << endl;
    cout << "1.- El fichero con el diccionario" << endl;
    cout << "2.- Contiene las letras y su puntuacion" << endl;
    cout << "3.- Modo de juego (L = longitud, P = puntuación)" << endl;
    cout << "4.- Cantidad de letras para la partida" << endl;
    return 1;
  }

  ifstream f_diccionario(argv[1]);
  ifstream f_conjuntoletras(argv[2]);
  
  if(!f_diccionario){
    cout << "No puedo abrir el fichero " << argv[1] << endl;
    return 0;
  }
  
  string cad="";
  Dictionary diccionario;
  LetterSet conjunto_letras;

  while(f_diccionario >> cad)
        diccionario.insert(cad);

    f_conjuntoletras >> conjunto_letras;



  Dictionary diccionario;
  f_diccionario >> diccionario;

  for (Dictionary::iterator it = diccionario.begin(); it != diccionario.end(); ++it){
    cout << *it << endl;
  }

  return 0;
}
