#include "etat.h"

etat::etat()
{
}


//{ OPENPAR, CLOSEPAR, PLUS, MULT, INT, FIN, ERREUR, EXPR}
bool E0::transition (Automate & automate,Symbole * s) {
    switch (*s) {
    case NOMBRE:
        automate.decalage(s,new E3);
        break;
    case EXPR:
        automate.decalage(s,new E1);
        break;
    case OUVREPAR:
        automate.decalage(s,new E2);
        break;
    }
    return false;
}

bool E1::transition (Automate & automate,Symbole * s) {
    switch (*s) {
    case PLUS:
        automate.decalage(s,new E3);
        break;
    case EXPR:
        automate.decalage(s,new E1);
        break;
    case OUVREPAR:
        automate.decalage(s,new E2);
        break;
    }
    return false;
}

