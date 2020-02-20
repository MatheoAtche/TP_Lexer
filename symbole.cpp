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

int Entier::getValeur(){
    return this->valeur;
}

void Expr::Affiche() {
   Symbole::Affiche();
   cout<<"("<<eval()<<")";
}

void ExprConst::Affiche() {
   Expr::Affiche();
}
void ExprMult::Affiche() {
   Expr::Affiche();
}
void ExprPlus::Affiche() {
   Expr::Affiche();
}

int ExprConst::eval(){
    return value;
}

int ExprPlus::eval(){
    return exprDroite->eval() + exprGauche->eval();
}

int ExprMult::eval(){
    return exprDroite->eval() * exprGauche->eval();
}
