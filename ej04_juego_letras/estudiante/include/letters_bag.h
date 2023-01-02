#ifndef __LETTERS_BAG_H__
#define __LETTERS_BAG_H__

/**
 * @brief TDA LettersBag
 *
 * Este TDA almacena un conjunto de chars utilizado en el juego de letras.
 * La estructura de datos subyacente es una lista de chars.
 */

#include "bag.h"
#include "letter_set.h"
#include <stdlib.h>
#include <time.h>
#include <vector>

class LettersBag {
    private:
        Bag <char> letters;
    
    public:
        
        /**
         * @brief Constructor sin argumento para inicializar instancias
         * de la clase Bag
        */

        LettersBag();

        
        /**
         * @brief Constructor dado un LetterSet, este constructor debe rellenar
         * la LettersBag con las letras contenidas en LettersSet, introduciendo 
         * cada letra el número de veces indicando por el campo LetterInfo::repetitions
         * @param const LetterSet & letterSet
        */

        LettersBag(const LetterSet & letterSet);
        
        /**
         * @brief Introduce una letra en la bolsa
         * @param l letra a añadir a la LettersBag 
        */

        void insertLetter(const char & l);

        
        /**
         * @brief Extrae una letra aleatoria de la bolsa, eliminándola del conjunto
         * @return char representa la letra 
        */

        char extractLetter();

        
        /**
         * @brief Extrae un conjunto de letras, eliminándolas del conjunto
         * @param num Número de letras a extraer
         * @return Lista con las letras extraídas   
        */

        vector<char> extractLetters(int num);

        /**
         * @brief Elimina todo el contenido de la LettersBag
        */

        void clear();

        /**
         * @brief Tamaño de la bolsa
         * @return entero con el tamaño de la bolsa
        */
        unsigned int size();

        /**
         * @brief Sobrecarga del operador de asignación
         * @return Referencia a this de esta forma el operador puede ser
         * encadenado
        */

        LettersBag & operator=(const LettersBag & other);
};


#endif