#include <string>
#include <vector>
#include <utility>
#include <set>
#include "dictionary.h"
#include <cmath>
#include "letter_set.h"
#include "solver.h"

using namespace std;

    Solver::Solver(const Dictionary & dict, const LetterSet & letters_set){
        diccionario=dict;
        conjunto_letras=letters_set;
    }

    pair<vector<string>,int> Solver::getSolutions(const vector<char> & available_letters, bool score_game){

        pair<vector<string>, int> result;

        Dictionary::iterator iter = diccionario.begin();

        
        ++iter;
        while(iter != diccionario.end()){
            vector<char> aux = available_letters;
            string palabra = "";
            string pal = iter.operator*();

            for(int i=0;i<pal.size();i++){
                bool encontrado = false;
                for(int j=0; j<aux.size() && !encontrado; j++){

                    if(pal[i] == aux[j]){
                        palabra.push_back(aux[j]);
                        aux.erase(aux.begin() + j);
                        encontrado = true;
                
                    }
                }
            }

            bool controlador = false;

            

            if(palabra == pal){
                controlador = true;
            }

            if(score_game && controlador){
                
                int puntuacion = conjunto_letras.getScore(palabra);
                
                if(result.second == puntuacion){
                    
                    result.first.push_back(palabra);
                }   
                
                else if(result.second < puntuacion){

                    result.first.clear();
                    
                    result.second = puntuacion;
                    
                    result.first.push_back(palabra);

                }
            }
            else if(!score_game && controlador){
                
                int longitud = palabra.length();
                
                if(result.second == longitud){

                    result.first.push_back(palabra);
                }   
                
                else if(result.second < longitud){
                
                    result.first.clear();
                    
                    result.second = longitud;
                    
                    result.first.push_back(palabra);
                }
                
            }
            
            ++iter;
        }

        
        return result;
    }