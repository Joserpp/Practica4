#include <fstream>
#include <iostream>

#include "letter_set.h"
#include "solver.h"
#include "dictionary.h"
#include "vector"
#include "letters_bag.h"

using namespace std;

int main(int argc, char *argv[])
{
  if(argc != 5){
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

  LettersBag bolsa_letras(conjunto_letras);

  vector<char> letras_partida = bolsa_letras.extractLetters(atoi(argv[4]));

  cout<<"LETRAS DISPONIBLES:"<<endl;

  for(int i=0;i<letras_partida.size();i++){
    char let = toupper(letras_partida[i]);
    cout<<let<<" ";
  }

  cout << endl;

  char modo_juego=*argv[3];

  bool modo;
  if(modo_juego=='L'){
    modo=false;
  }
  else if(modo_juego == 'P')
    modo=true;

  pair<vector<string>,int> soluciones;

  Solver solver(diccionario,conjunto_letras);

  soluciones = solver.getSolutions(letras_partida,modo);

  cout << endl;
  cout<<"SOLUCIONES: "<<endl;

  for(int i=0;i<soluciones.first.size();i++){
    cout<<soluciones.first[i]<<endl;
  }

  cout<<"PUNTUACION: ";
  cout<<soluciones.second;

  return 0;
}
