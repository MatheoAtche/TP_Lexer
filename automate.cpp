#include "automate.h"

automate::automate()
{
void automate:: decalage (Symbole * s, Etat * e) {
    symbolstack.push_back(s);
    statestack.push_back(e);
    if(s.getTerminal()) {
        lexer->Avancer();
    }
}

void automate::reduction(int n,Symbole * s) {
    for(inti=0;i<n;i++){
        delete(statestack.back());
        statestack.pop_back();
    }
    statestack.back()->transition(*this,s);
}


}
