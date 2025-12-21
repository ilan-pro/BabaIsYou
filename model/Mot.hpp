#ifndef _MOT
#define _MOT
#include "Agent.hpp"
#include "Word.hpp"

class Mot : public Agent
{

private:
    Word word;

public:
    Mot(Case *c, Word w, const Regles &rules);

    Word getWord() const;

    WordCategory category() const;

    bool isNoun() const;
    bool isOperator() const;
    bool isProperty() const;
};

#endif
