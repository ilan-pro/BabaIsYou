#include "Mot.hpp"

Mot::Mot(Case *c, Word w, const Regles &rules) : Agent(c, ObjectType::TEXT, rules), word(w) {}

Word Mot::getWord() const { return word; }

WordCategory Mot::category() const
{
    return getWordInfo(word).category;
}

Agent *Mot::clone() const
{
    return new Mot(*this);
}

bool Mot::isNoun() const { return category() == WordCategory::NOUN; }
bool Mot::isOperator() const { return category() == WordCategory::OPERATOR; }
bool Mot::isProperty() const { return category() == WordCategory::PROPERTY; }
