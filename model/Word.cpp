#include <stdexcept>
#include "Word.hpp"
#include "Enums.hpp" 

using namespace std;

/**
 * static ici pour que ce soit présent qu'a l'interieur de ce fichier .pp 
 * on ne souhaite pas que cette WORD_TABLE soit connue a l'exterieur 
 */
static const map<Word, WordInfo> WORD_TABLE = {
    { Word::BABA,  { WordCategory::NOUN, ObjectType::BABA,  {} } },
    { Word::ROCK,  { WordCategory::NOUN, ObjectType::ROCK,  {} } },
    { Word::WALL,  { WordCategory::NOUN, ObjectType::WALL,  {} } },
    { Word::FLAG,  { WordCategory::NOUN, ObjectType::FLAG,  {} } },
    { Word::WATER, { WordCategory::NOUN, ObjectType::WATER, {} } },

    { Word::IS,    { WordCategory::OPERATOR, {}, {} } },

    { Word::YOU,   { WordCategory::PROPERTY, {}, Property::YOU } },
    { Word::PUSH,  { WordCategory::PROPERTY, {}, Property::PUSH } },
    { Word::STOP,  { WordCategory::PROPERTY, {}, Property::STOP } },
    { Word::WIN,   { WordCategory::PROPERTY, {}, Property::WIN } }
};


/**
 * a voir entre référence et pointeur 
 */
const WordInfo& getWordInfo(Word w) {
    map<Word, WordInfo>::const_iterator it = WORD_TABLE.find(w);
    if (it == WORD_TABLE.end()) {
        throw logic_error("Unknown Word");
    }
    return it->second;
}

const bool isNoun(WordInfo& w) {
    return w.category == WordCategory::NOUN;
}

const bool isOperator(WordInfo& w) {
        return w.category == WordCategory::OPERATOR;
}

const bool isProperty(WordInfo& w) {
    return w.category == WordCategory::PROPERTY;
}
