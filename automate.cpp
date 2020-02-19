#include "automate.h"

Automate::automate()
{

}

void Automate:: decalage (Symbole * s, Etat * e) {
    symbolstack.push_back(s);
    statestack.push_back(e);
    if(s.getTerminal()) {
        lexer->Avancer();
    }
}

void Automate::reduction(int n,Symbole * s) {
    //on dépile n états
    for(inti=0;i<n;i++){
        delete(statestack.back());
        statestack.pop_back();
    }
    statestack.back()->transition(*this,s);
}
Etat * Automate::popSymbol(){     //pop le stack et renvoi le pointeur de l'élément
    Symbole * s = this->symbolstack.top();
    this->symbolstack.pop();
}
void Automate::popAndDestroySymbol() {//pop le stack et oublie la valeur (on sait deja que c'est plus ou Mult)
    this->symbolstack.pop();
}
