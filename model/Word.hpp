#ifndef _WORD_HPP
#define _WORD_HPP

#include <map>

/*
Tous les mots qui existe dans l'enum class Word
*/

enum class Word {
    BABA, ROCK, WALL, FLAG, WATER,
    IS,
    YOU, PUSH, STOP, WIN
};

/* 
Avoir l'information de quelles catégories de mots il s'agit 
*/

enum class WordCategory {
    NOUN,
    OPERATOR,
    PROPERTY
};

enum class ObjectType;
enum class Property;


/*
on creer cette structure pour avoir l'information de quelle mots il s'agit, a quelle catégorie il appartient 
et on lui associe le bon ObjectYpe ou Property pour pouvoir l'ajouter dans les regles 
*/


struct WordInfo {
    WordCategory category;
    ObjectType object;    
    Property property;    
};

const WordInfo& getWordInfo(Word w);
const bool isNom(WordInfo& w);
const bool isOperator(WordInfo& w);
const bool isProperty(WordInfo& w);

#endif
