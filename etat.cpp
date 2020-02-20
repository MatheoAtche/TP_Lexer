#include "etat.h"


void Etat::print () const{
    cout<<this->name<<endl;
}

//{ OPENPAR, CLOSEPAR, PLUS, MULT, INT, FIN, ERREUR,EXPR}
bool E0::transition (Automate & automate,Symbole * s) {
    switch (*s) {
    case INT:
        automate.decalage(s,new E3);
        break;
    case EXPR:
        automate.decalage(s,new E1);
        break;
    case OPENPAR:
        automate.decalage(s,new E2);
        break;
    default:
       automate.decalage(new Symbole(ERREUR),NULL);
       return true;
    }
    return false;
}

bool E1::transition (Automate & automate,Symbole * s) {
    switch (*s) {
    case PLUS:
        automate.decalage(s,new E4);
        break;
    case MULT:
        automate.decalage(s,new E5);
        break;
    case FIN:
        return true;
        break;
    default:
       automate.decalage(new Symbole(ERREUR),NULL);
       return true;
    }
    return false;
}

bool E2::transition (Automate & automate,Symbole * s) {
    switch (*s) {
    case INT:
        automate.decalage(s,new E3);
        break;
    case EXPR:
        automate.decalage(s,new E6);
        break;
    case OPENPAR:
        automate.decalage(s,new E2);
        break;
    default:
       automate.decalage(new Symbole(ERREUR),NULL);
       return true;
    }
    return false;
}

/*

 ___pour Plus___
Expr * s1 = (Expr*) automate.popSymbol();
automate.popAndDestroySymbol();
Expr * s2 = (Expr*) automate.popSymbol();
automate.reduction(3,new ExprPlus(s2,s1));

 ___pour Mult___
Expr * s1 = (Expr*) automate.popSymbol();
automate.popAndDestroySymbol();
Expr * s2 = (Expr*) automate.popSymbol();
automate.reduction(3,new ExprMult(s2,s1));

 ___pour Const___
Entier * e = (Entier*) automate.popSymbol();
automate.reduction(1,new ExprConst(e));

 ___pour Parenthèses___
automate.popAndDestroySymbol();
Expr * e = (Expr*) automate.popSymbol();
automate.popAndDestroySymbol();
automate.reduction(3,e);

*/
bool E3::transition (Automate & automate,Symbole * s) {
    cout<<"dans la transition E3"<<endl;         //debug
    switch (*s) {
    case PLUS:
        {Entier * e = (Entier*) automate.popSymbol();

        cout<<"reduction presque faite"<<endl;    //debug   
        automate.reduction(1,new ExprConst(e));
        cout<<"reduction faite"<<endl;    //debug
        }
        break;
    case MULT:
        {Entier * e = (Entier*) automate.popSymbol();
        automate.reduction(1,new ExprConst(e));}
        break;
    case CLOSEPAR:
        {Entier * e = (Entier*) automate.popSymbol();
        automate.reduction(1,new ExprConst(e));}
        break;
    case FIN:
        {Entier * e = (Entier*) automate.popSymbol();
        automate.reduction(1,new ExprConst(e));}
        break;
    default:
       automate.decalage(new Symbole(ERREUR),NULL);
       return true;
    }
    return false;
}

bool E4::transition (Automate & automate,Symbole * s) {
    switch (*s) {
    case INT:
        automate.decalage(s,new E3);
        break;
    case EXPR:
        automate.decalage(s,new E7);
        break;
    case OPENPAR:
        automate.decalage(s,new E2);
        break;
    default:
       automate.decalage(new Symbole(ERREUR),NULL);
       return true;
    }
    return false;
}

bool E5::transition (Automate & automate,Symbole * s) {
    switch (*s) {
    case INT:
        automate.decalage(s,new E3);
        break;
    case EXPR:
        automate.decalage(s,new E8);
        break;
    case OPENPAR:
        automate.decalage(s,new E2);
        break;
    default:
       automate.decalage(new Symbole(ERREUR),NULL);
       return true;
    }
    return false;
}

bool E6::transition (Automate & automate,Symbole * s) {
    cout<<"dans la transition E6"<<endl;         //debug
    switch (*s) {
    case PLUS:
        {
        cout<<"on reconnait un PLUS dans l'étape E6"<<endl;   // debug
        automate.decalage(s,new E4);
        }
        break;
    case MULT:
        automate.decalage(s,new E5);
        break;
    case CLOSEPAR:
        automate.decalage(s,new E9);
        break;
    default:
       automate.decalage(new Symbole(ERREUR),NULL);
       return true;
    }
    return false;
}

bool E7::transition (Automate & automate,Symbole * s) {
    switch (*s) {
    case PLUS:
        {Expr * s1 = (Expr*) automate.popSymbol();
        automate.popAndDestroySymbol();
        Expr * s2 = (Expr*) automate.popSymbol();
        automate.reduction(3,new ExprPlus(s2,s1));}

        break;
    case MULT:
        automate.decalage(s,new E5);
        break;
    case CLOSEPAR:
        {Expr * s1 = (Expr*) automate.popSymbol();
        automate.popAndDestroySymbol();
        Expr * s2 = (Expr*) automate.popSymbol();
        automate.reduction(3,new ExprPlus(s2,s1));}

        break;
    case FIN:
        {Expr * s1 = (Expr*) automate.popSymbol();
        automate.popAndDestroySymbol();
        Expr * s2 = (Expr*) automate.popSymbol();
        automate.reduction(3,new ExprPlus(s2,s1));}

        break;

    default:
       automate.decalage(new Symbole(ERREUR),NULL);
       return true;
    }
    return false;
}

bool E8::transition (Automate & automate,Symbole * s) {
    switch (*s) {
    case PLUS:
        {Expr * s1 = (Expr*) automate.popSymbol();
        automate.popAndDestroySymbol();
        Expr * s2 = (Expr*) automate.popSymbol();
        automate.reduction(3,new ExprMult(s2,s1));}

        break;
    case MULT:
        {Expr * s1 = (Expr*) automate.popSymbol();
        automate.popAndDestroySymbol();
        Expr * s2 = (Expr*) automate.popSymbol();
        automate.reduction(3,new ExprMult(s2,s1));}

        break;
    case CLOSEPAR:
        {Expr * s1 = (Expr*) automate.popSymbol();
        automate.popAndDestroySymbol();
        Expr * s2 = (Expr*) automate.popSymbol();
        automate.reduction(3,new ExprMult(s2,s1));}

        break;
    case FIN:
        {Expr * s1 = (Expr*) automate.popSymbol();
        automate.popAndDestroySymbol();
        Expr * s2 = (Expr*) automate.popSymbol();
        automate.reduction(3,new ExprMult(s2,s1));}

        break;
    default:
       automate.decalage(new Symbole(ERREUR),NULL);
       return true;
    }
    return false;
}

bool E9::transition (Automate & automate,Symbole * s) {
    switch (*s) {
    case PLUS:
        {automate.popAndDestroySymbol();
        Expr * e = (Expr*) automate.popSymbol();
        automate.popAndDestroySymbol();
        automate.reduction(3,e);}
        break;
    case MULT:
        {automate.popAndDestroySymbol();
        Expr * e = (Expr*) automate.popSymbol();
        automate.popAndDestroySymbol();
        automate.reduction(3,e);}
        break;
    case CLOSEPAR:
        {automate.popAndDestroySymbol();
        Expr * e = (Expr*) automate.popSymbol();
        automate.popAndDestroySymbol();
        automate.reduction(3,e);}
        break;
    case FIN:
        {automate.popAndDestroySymbol();
        Expr * e = (Expr*) automate.popSymbol();
        automate.popAndDestroySymbol();
        automate.reduction(3,e);}
        break;
    default:
       automate.decalage(new Symbole(ERREUR),NULL);
       return true;
    }
    return false;
}



