#include "automate.h"

Automate::Automate(Lexer * l)
{
    this->l = l;
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

Etat * Automate::popSymbol(){     //pop le stack et renvoi le pointeur de l'élément
    Symbole * s = this->symbolstack.top();
    this->symbolstack.pop();
}
void Automate::popAndDestroySymbol() {//pop le stack et oublie la valeur (on sait deja que c'est plus ou Mult)
    this->symbolstack.pop();
}
