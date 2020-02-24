#include "automate.h"

Automate::Automate(Lexer * lexer)
{
    this->l = lexer;
    statestack.push(new E0);
}

void Automate:: decalage (Symbole * s, Etat * e) {
    symbolstack.push(s);
    statestack.push(e);
    if(s->getTerminal()) {
        l->Avancer();
    }
}

void Automate::reduction(int n,Symbole * s) {
    //on dépile n états
    for(int i=0;i<n;i++){
        delete(statestack.top());
        statestack.pop();
    }
    statestack.top()->transition(*this,s);
}

//pop le stack et renvoi le pointeur de l'élément
Symbole * Automate::popSymbol(){     
    Symbole * s = this->symbolstack.top();
    this->symbolstack.pop();
    return (Expr*)s;
}

//pop le stack et oublie la valeur (on sait deja que c'est plus ou Mult)
void Automate::popAndDestroySymbol() {
    this->symbolstack.pop();
}

void Automate::lecture(){
    bool terminer = false;
    Symbole * s;
    Etat * e;

    while(!terminer) {
        s = this->l->Consulter();
        e = statestack.top();
        terminer = e->transition(*this,s);
   }
}
