#ifndef AUTOMATE_H
#define AUTOMATE_H

#include "symbole.h"
#include "lexer.h"
#include <stack>

class automate
{
public:
    automate();

    void decalage (Symbole * s, Etat * e);

};

#endif // AUTOMATE_H
