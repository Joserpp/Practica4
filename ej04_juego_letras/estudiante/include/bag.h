#ifndef __BAG_H__
#define __BAG_H__
#include <iostream>

#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include <vector>

using namespace std;

/**
 *  @brief TDA Bag
 *
 *  Este TDA abstracto nos ofrece la capacidad de trabajar con
 *  una colección de elementos permitiendo la extracción de elementos de forma 
 *  aleatoria sin reemplazamiento
 */
template <class T>
class Bag {
    private:
        vector<T> v;
    public:
        
        Bag();
        
        Bag(const Bag<T> & other);

        void add (const T & element);

        T get();

        void clear();

        unsigned int size()const;

        bool empty();

        const Bag<T> & operator=(const Bag<T> & other);

};

#endif

/**
* @brief Constructor de copia. Crea una copia exacta de otro objeto de tipo Bag
*/

template<class T>
Bag<T>::Bag(){}


template<class T>
Bag<T>::Bag(const Bag<T> & other) : v(other.v){
}

/**
* @brief Método para añadir elementos a la bolsa
* @param  const T & element elemento a añadir
*/
template<class T>
void Bag<T>::add(const T & element){
    v.push_back(element);
}

/**
*@brief Método para extraer un elemento aleatorio de la bolsa. Devuelve un elemento
*@brief aleatorio de la bolsa y lo elimina de la misma.
*@return Elemento de tipo T extraído de la bolsa
*@pre La bolsa no está vacía
*@post El elemento devuelto se ha eliminado de la bolsa
*/
template<class T>
T Bag<T>::get(){

    srand(time(NULL));
    int num = rand()%v.size();
    T aux;
    aux = v[num];
    v[num] = v.back();
    v.pop_back();
    return aux;
}

/**
*@brief Elimina todos los elementos de la bolsa.
*/

template<class T>
void Bag<T>::clear(){

    v.clear();
}

/**
*@brief Devuelve el número de elementos contenido en el vector.
*@return Número de elementos que hay en la bolsa.
*/
template<class T>
unsigned int Bag<T>::size() const{

    return v.size();
}

/**
*@brief Comprueba si la bolsa está vacía.
*@return true si la bolsa está vacía, false en caso contrario.
*/
template<class T>
bool Bag<T>::empty(){

    return v.empty();
}

/**
*@brief Sobrecarga del operador de asignación.
*@param other Bag<T> a copiar.
*@return Referencia a this para poder encadenar el operador.
*/
template<class T>
const Bag<T> & Bag<T>::operator=(const Bag<T> & other){

    if (this != &other)
        this->v = other.v;
    return *this;
}
