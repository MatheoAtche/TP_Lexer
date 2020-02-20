#pragma once

#ifndef AUTOMATE_H
#define AUTOMATE_H

#include <iostream> // debug
#include <string>
using namespace std;

#include "symbole.h"
#include "lexer.h"
#include "etat.h"
#include <stack>

class Etat;

class Automate
{
public:
    Automate(Lexer * l);
    void reduction (int n, Symbole * s);
    void decalage (Symbole * s, Etat * e);
    Expr * popSymbol(); //pop le stack et renvoi le pointeur de l'élément
    void popAndDestroySymbol();//pop le stack et oublie la valeur (on sait deja que c'est plus ou Mult)
    void lecture();

protected:
    stack <Symbole *> symbolstack;
    stack <Etat *> statestack;
    Lexer * l;
};

#endif // AUTOMATE_H
