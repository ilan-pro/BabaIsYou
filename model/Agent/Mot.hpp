#ifndef _MOT
#define _MOT

#include "../Agent.hpp"
#include "../Word.hpp"

class Mot : public Agent
{
private:
    Word word;
public:
    Mot(Case *c, Word w, const Regles &regles);

    Word getWord() const;

    WordCategory category() const;

    Agent *clone() const;

    bool isNoun() const;
    bool isOperator() const;
    bool isProperty() const;
};

#endif
