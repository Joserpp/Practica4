#include "letters_bag.h"


LettersBag::LettersBag(){}

LettersBag::LettersBag(const LetterSet & letterSet){

   map<char, LetterInfo> mapa = letterSet.getLetter();

    for (map<char, LetterInfo>::const_iterator pos = mapa.cbegin(); pos != mapa.cend(); ++pos) {
        for (int j = 0; j < pos->second.repetitions; j++)
            letters.add(pos->first);
    }
}
    
void LettersBag::insertLetter(const char & l){

    letters.add(l);

}

char LettersBag::extractLetter(){

  return letters.get();
}

vector<char> LettersBag::extractLetters(int num){

    vector<char> extraidos;
    
    for(int i=0;i<num;i++)
        extraidos.push_back(letters.get());

    return extraidos;
}


void LettersBag::clear(){

    letters.clear();
}

unsigned int LettersBag::size(){
   return letters.size();
}

LettersBag & LettersBag::operator= (const LettersBag & other){
    
    if (this != &other)
        letters = other.letters;
    
    return *this;
}


