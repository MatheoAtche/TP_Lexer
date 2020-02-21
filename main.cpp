#include <iostream>
#include "lexer.h"
#include "automate.h"

int main(void) {
   //pas besoin de new car pas d'allocation dynamique
   cout << "Entrez votre formule (seulement à base d'entiers, multiplication, addition et parenthèses" << endl;
   string chaine;
   cin >> chaine;
   Lexer l(chaine);
   Automate a(&l);
   //deroulement de l'algo de bottom up
   a.lecture();
   cout<<"sorti de la lecture de l'automate"<<endl;   // debug
   Expr * resultat  =  a.popSymbol();
   cout << "Le résultat est :" << endl;
   cout << resultat->eval() << endl;
   return 0;
}

