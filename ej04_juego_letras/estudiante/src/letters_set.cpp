#include "letters_set.h"
#include <iostream>
#include "string.h"
#include <map>

using namespace std;

LetterSet::LetterSet(){}

LetterSet::LetterSet(const LetterSet & other){

    letters=other.letters;
}


bool LetterSet::insert(const pair<char,LetterInfo> & val){
    bool condicion=true;
    for(map<char, LetterInfo>::iterator pos = letters.begin(); pos != letters.end() && condicion; pos++)

        if(pos->first==val.first)
            condicion=false;

    if(condicion)
        letters.insert(val);

    return condicion;
}

bool LetterSet::erase(const char & key){

    return letters.erase(key);
}

bool LetterSet::empty(){

    return (letters.empty());
      
}



void LetterSet::clear(){

    letters.clear();
}

unsigned int LetterSet::size(){
   return letters.size();
}

int LetterSet::getScore(string word){

    int puntuacion=0;
    int longitud = word.length();
    
    //Recorremos cada letra
    for(int i=0;i<longitud;i++){
        
        for(map<char, LetterInfo>::const_iterator pos=letters.cbegin();pos!=letters.cend();++pos)

            if(pos->first == toupper(word[i]))
                puntuacion+=pos->second.score;      
    }

    return puntuacion;
}


LetterSet & LetterSet::operator=(const LetterSet & cl){

    if (this != &cl)
        letters = cl.letters;

    return *this;
}

LetterInfo & LetterSet::operator[](const char & val){
    for (map<char, LetterInfo>::iterator pos = letters.begin(); pos != letters.end() && val >= 0 && val < letters.size(); ++pos)
        if (pos->first == val) {
            return pos->second;
        }
}

ostream & operator<<(ostream & os, const LetterSet & cl){

    os << "Letra Cantidad Puntos" << endl;

    for (map<char, LetterInfo>::const_iterator pos = cl.letters.cbegin(); pos != cl.letters.cend(); ++pos)
        os << pos->first << " " << pos->second.repetitions << " " << pos->second.score << endl;

    return os;
}

istream & operator>>(istream & is, LetterSet & cl){
    
    string cad;

    is >> cad;
    
    is >> cad;
    
    is >> cad;
    
    char cadena;
    
    while (is >> cadena){
        LetterInfo info;
        
        is >> info.repetitions;
        
        is >> info.score;
        
        pair<char, LetterInfo> valor;
        
        valor.first = cadena;
        
        valor.second = info;
        
        cl.insert(valor);
    }

    return is;
}

map <char,LetterInfo> LetterSet::getLetter()const{
    
    return letters;
}