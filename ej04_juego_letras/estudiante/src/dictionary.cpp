//
// Created by fluque1995 on 8/9/21.
//

#include <string>
#include <vector>
#include <utility>
#include <set>
#include <cmath>
#include "dictionary.h"

///////////////////////////////////////////////////////////////////////////////
//                             Private functions                             //
///////////////////////////////////////////////////////////////////////////////

Dictionary::node Dictionary::findLowerBoundChildNode(char character, Dictionary::node current)
{
  node prev_child, curr_child = current.left_child();

  for (; !curr_child.is_null() && (*curr_child).character <= character; curr_child = curr_child.right_sibling())
  {
    prev_child = curr_child;
    if ((*curr_child).character == character)
    {
      return curr_child;
    }
  }
  if (!prev_child.is_null())
  {
    return prev_child;
  }
  return current;
}

Dictionary::node Dictionary::insertCharacter(char character, Dictionary::node current)
{
  node insertion_position = findLowerBoundChildNode(character, current);
  if (insertion_position == current)
  {
    this->words.insert_left_child(current, char_info(character));
    return insertion_position.left_child();
  }
  else if ((*insertion_position).character != character)
  {
    this->words.insert_right_sibling(insertion_position, char_info(character));
    return insertion_position.right_sibling();
  }
  else
  {
    return insertion_position;
  }
}

int Dictionary::getOccurrences(node curr_node, char c)
{
  int contador=0;

  if (curr_node.operator*().character==c)
    contador++;
  if(!curr_node.left_child().is_null())
    contador+=getOccurrences(curr_node.left_child(),c);

  if(!curr_node.right_sibling().is_null())
    contador+=getOccurrences(curr_node.right_sibling(),c);
  
  return contador;
}


std::pair<int, int> Dictionary::getTotalUsages(node curr_node, char c){
  pair<int,int> pareja(0,0);

//hay que recorrer los nodos

//Llamamos de forma recursiva a la funcion sobre el hermano de la derecha y el hijo a la izqueirda
  pair<int,int> total_izquierda(0,0);
  pair<int,int> total_derecha(0,0); 

  if(!curr_node.right_sibling().is_null())
    total_derecha=getTotalUsages(curr_node.right_sibling(),c);

  if(!curr_node.left_child().is_null())
    total_izquierda=getTotalUsages(curr_node.left_child(),c);


  pareja.first=total_izquierda.first + total_derecha.first;
  pareja.second=total_izquierda.second + total_derecha.second;
  
  if (curr_node.operator*().character==c)
    pareja.first+=total_izquierda.second;

    if(curr_node.operator*().valid_word){
      pareja.second+=1;
      if(curr_node.operator*().character == c)
        pareja.first+=1;
    }

  return pareja;
}

///////////////////////////////////////////////////////////////////////////////
//                              Public functions                             //
///////////////////////////////////////////////////////////////////////////////


Dictionary::Dictionary()
{
  this->words.set_root(char_info());
  this->total_words = 0;
}

Dictionary::Dictionary(const Dictionary &other)
{
  this->words = other.words;
  this->total_words = other.total_words;
}

Dictionary::~Dictionary()
{
  this->words.clear();
}

bool Dictionary::exists(const std::string &word)
{
  node current = this->words.get_root();
  for (int i = 0; i < word.size(); ++i)
  {
    current = this->findLowerBoundChildNode(word[i], current);
    if ((*current).character != word[i])
    {
      return false;
    }
  }

  return (*current).valid_word;
}

bool Dictionary::insert(const std::string &word)
{
  node current = this->words.get_root();
  for (int i = 0; i < word.size(); ++i)
  {
    current = this->insertCharacter(word[i], current);
  }

  if (!(*current).valid_word)
  {
    (*current).valid_word = true;
    this->total_words++;
    return true;
  }

  return false;
}

bool Dictionary::erase(const std::string &val)
{
  node current = this->words.get_root();
  for (int i = 0; i < val.size(); ++i)
  {
    current = this->findLowerBoundChildNode(val[i], current);
    if ((*current).character != val[i])
    {
      return false;
    }
  }
  if ((*current).valid_word)
  {
    (*current).valid_word = false;
    this->total_words--;
    return true;
  }
  return false;
}

Dictionary &Dictionary::operator=(const Dictionary &dic)
{
  if (this != &dic)
  {
    this->words.clear();
    this->words = dic.words;
    this->total_words = dic.total_words;
  }
  return *this;
}

///////////////////////////////////////////////////////////////////////////////
//                               I/O overload                                //
///////////////////////////////////////////////////////////////////////////////

std::ostream& operator<<(std::ostream &os, const Dictionary &dict){
  for(Dictionary::iterator it = dict.begin();it != dict.end(); ++it){
    os << *it << std::endl;
  }
  return os;
}

std::istream &operator>>(std::istream &is, Dictionary &dict)
{
  std::string curr_word;
  while (getline(is, curr_word))
  {
    dict.insert(curr_word);
  }
  return is;
}

///////////////////////////////////////////////////////////////////////////////
//                            Recursive counters                             //
///////////////////////////////////////////////////////////////////////////////

int Dictionary::getOccurrences(const char c){

  int contador=0;
  contador=this->getOccurrences(words.get_root(),c);
  return contador;
}

int Dictionary::getTotalUsages(const char c){
  pair<int,int> contador;
  contador=this->getTotalUsages(words.get_root(),c);
  return contador.first;
}

///////////////////////////////////////////////////////////////////////////////
//                                 Iterator                                  //
///////////////////////////////////////////////////////////////////////////////

Dictionary::iterator::iterator() : iter() {
  curr_word="";
}

Dictionary::iterator::iterator(tree<char_info>::const_preorder_iterator otro) : iter(otro){}

std::string Dictionary::iterator::operator*()
{
  return curr_word;
}

Dictionary::iterator &Dictionary::iterator::operator++()
{

  int nivel_ant, nivel_post;

  do
  {
    nivel_ant = iter.get_level();

    ++iter;
    
    nivel_post = iter.get_level();
    

    if(nivel_post==0)
      break;

    if (nivel_ant < nivel_post)
    {
  
      char car = iter.operator*().character;
      curr_word.push_back(car);
    }
    else if (nivel_ant == nivel_post)
    {
      curr_word.pop_back();
      char car = iter.operator*().character;
      curr_word.push_back(car);
    }
    else if(nivel_ant > nivel_post){
      int var = nivel_ant - nivel_post;
      
      for(int i=0;i<=var;i++)
        curr_word.pop_back();
      
      char car = iter.operator*().character;
      curr_word.push_back(car);
    }
    
    
  } while(!iter.operator*().valid_word );

  
  return *this;
}
bool Dictionary::iterator::operator==(const iterator &other)
{

  return (iter == other.iter);
}

bool Dictionary::iterator::operator!=(const iterator &other)
{
  return (iter != other.iter);
}

Dictionary::iterator Dictionary::begin() const
{
  iterator i(words.cbegin_preorder());
  //++i;
  return i;
}

Dictionary::iterator Dictionary::end() const
{
  iterator i(words.cend_preorder());

  return i;
}

///////////////////////////////////////////////////////////////////////////////
//                            Letters Iterator                               //
///////////////////////////////////////////////////////////////////////////////

/*

//Dictionary::possible_words_iterator Dictionary::possible_words_begin(vector<char> available_characters) const{}

//Dictionary::possible_words_iterator Dictionary::possible_words_end() const{}

Dictionary::possible_words_iterator::possible_words_iterator(){}

Dictionary::possible_words_iterator::possible_words_iterator(node current_node, vector<char> available_letters){

	this->current_node = current_node;
	for(int i=0;i<available_letters.size();i++){
    	this->available_letters.emplace(available_letters[i]);
  	}

  
}

Dictionary::possible_words_iterator::possible_words_iterator(const possible_words_iterator &other){
	this->current_node = other.current_node;
	this->available_letters=other.available_letters;
	this->level = other.level;
	this->current_word = other.current_word;
}

Dictionary::possible_words_iterator &Dictionary::possible_words_iterator::operator=(const Dictionary::possible_words_iterator &other) {
	possible_words_iterator iter(other);

	return iter;
}

bool Dictionary::possible_words_iterator::operator==(const Dictionary::possible_words_iterator &other) const {

}

bool Dictionary::possible_words_iterator::operator!=(const Dictionary::possible_words_iterator &other) const {

}

Dictionary::possible_words_iterator &Dictionary::possible_words_iterator::operator++() {

	char caracter_actual = *(*current_node);
std::multiset<char>::iterator it;
	if(it=available_letters.find(caracter_actual); it!= available_letters.end()){

		
	}
	}

	// no est??  

	// current_node.right_sibling

	// si est?? 
	// current_node.lefth


std::string Dictionary::possible_words_iterator::operator*() const {

}

*/
