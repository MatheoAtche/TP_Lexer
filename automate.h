#ifndef AUTOMATE_H
#define AUTOMATE_H

#include "symbole.h"
#include "lexer.h"
#include <stack>

class Automate
{
public:
    Automate(lexer * l);
    void reduction (int n, Symbole * s);
    void decalage (Symbole * s, Etat * e);
    etat * popSymbol(); //pop le stack et renvoi le pointeur de l'élément
    void popAndDestroySymbol();//pop le stack et oublie la valeur (on sait deja que c'est plus ou Mult)

protected:
    stack <symbole> symbolstack;
    stack <etat> statestack;
};

#endif // AUTOMATE_H
