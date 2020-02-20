#include "automate.h"

Automate::Automate(Lexer * lexer)
{
    this->l = lexer;
    statestack.push(new E0);
}

void Automate:: decalage (Symbole * s, Etat * e) {
    cout<<"on rentre dans la fonction de décalage de l'automate"<<endl;    //debug
    symbolstack.push(s);
    statestack.push(e);
    if(s->getTerminal()) {
        l->Avancer();
    }
}

void Automate::reduction(int n,Symbole * s) {
    //on dépile n états
    cout<<"on rentre dans la fonction reduction de l'automate"<<endl;    //debug
    for(int i=0;i<n;i++){
        delete(statestack.top());
        statestack.pop();
    }
    statestack.top()->transition(*this,s);
}

Expr * Automate::popSymbol(){     //pop le stack et renvoi le pointeur de l'élément
    Symbole * s = this->symbolstack.top();
    this->symbolstack.pop();
    return (Expr*)s;
}
void Automate::popAndDestroySymbol() {//pop le stack et oublie la valeur (on sait deja que c'est plus ou Mult)
    this->symbolstack.pop();
}

void Automate::lecture(){
    bool terminer = false;
    Symbole * s;
    Etat * e;

    while(!terminer) {
        cout<<"passage dans la boucle"<<endl;   // debug
        s = this->l->Consulter();
        e = statestack.top();
        
        cout<<"parcour de la pile des symboles"<<endl;   // debug
       for (stack<Symbole *> newStack1 = symbolstack; !newStack1.empty(); newStack1.pop()){
            Symbole * item = newStack1.top();
            item->Affiche(); 
            cout<<endl;
        }


        cout<<"parcour de la pile d'états"<<endl;   // debug
       for (stack<Etat *> newStack2 = statestack; !newStack2.empty(); newStack2.pop()){
            Etat * item = newStack2.top();
            item->print(); 
        }

        terminer = e->transition(*this,s);
        //this->l->Avancer();
        cout<<"Fin du passage dans la boucle"<<endl;   // debug
   }
}
