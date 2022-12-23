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

    pair<vector<string>,int> Solver::getSolutions(const vector<char> & available_letters, bool score_game){

        vector<char> aux = available_letters;
        vector<pair<string,int>> vector_sol;
        if(score_game){
            
            
            Dictionary::iterator iter = diccionario.begin();

            ++iter;
            bool encontrado=false;
            while((*iter) != ""){
                string palabra = "";
                for(int i=0;i<iter.operator*().size();i++){
                    for(int j=0; j<available_letters.size() && !encontrado; j++){

                        if((*iter)[i] == aux[j]){
                            palabra.push_back(aux[j]);
                            aux.erase(aux.begin() + j);
                            encontrado = true;
                        }
                    }
                }

                if(palabra == (*iter)){

                    int puntuacion = conjunto_letras.getScore(palabra);
                    
                    if(vector_sol[0].second == puntuacion){
                        
                        pair<string, int> pal_punt(palabra, puntuacion);

                        vector_sol.push_back(pal_punt);
                    }   
                    
                    else if(vector_sol[0].second < puntuacion){

                        vector_sol.clear();
                        
                        pair<string, int> pal_punt(palabra, puntuacion);
                        
                        vector_sol.push_back(pal_punt);
                    }
               }

                ++iter;
            }
            
        }
        else{}
    }