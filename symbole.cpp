#include "symbole.h"
#include <iostream>


bool Symbole::getTerminal(){
    return (this->terminal);
}

void Symbole::Affiche() {
   cout<<Etiquettes[ident];
}

void Entier::Affiche() {
   Symbole::Affiche();
   cout<<"("<<valeur<<")";
}

void Expr::Affiche() {
   Symbole::Affiche();
   cout<<"("<<eval()<<")";
}

int ExprConst::eval(){
    return value;
}

int ExprPlus::eval(){
    return (int)exprDroite + (int)exprGauche;
}

int ExprMult::eval(){
    return (int)exprDroite * (int)exprGauche;
}
