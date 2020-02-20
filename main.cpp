#include <iostream>
#include "lexer.h"
#include "automate.h"

int main(void) {
   //pas besoin de new car pas d'allocation dynamique
   string chaine("(1+34)*123");
   Lexer l(chaine);
   Automate a(&l);
   //deroulement de l'algo de bottom up
   a.lecture();
   cout<<"sorti de la lecture de l'automate"<<endl;   // debug
   Expr * resultat  =  a.popSymbol();
   cout<<resultat->eval()<<endl;
   cout<<"coucou c'est fini"<<endl;
   return 0;
}

