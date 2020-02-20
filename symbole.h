#pragma once

#include <string>
using namespace std;

enum Identificateurs { OPENPAR, CLOSEPAR, PLUS, MULT, INT, FIN, ERREUR, EXPR };

const string Etiquettes[] = { "OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "FIN", "ERREUR", "EXPR" };

class Symbole {
   public:
      Symbole(int i, bool b = false) : ident(i),terminal(b) {  }
      virtual ~Symbole() { }
      operator int() const { return ident; }
      virtual void Affiche();
      bool getTerminal();
   protected:
      int ident;
      bool terminal;
};

class Entier : public Symbole {
   public:
      Entier(int v) : Symbole(INT,true), valeur(v) { }
      ~Entier() { }
      virtual void Affiche();
      int getValeur();
   protected:
      int valeur;
};


class Expr : public Symbole {
    public:
        Expr(): Symbole(EXPR,false) {}
        virtual~Expr() {}
        void Affiche();
        virtual int eval() = 0;
};

class ExprConst : public Expr{
public:
    ExprConst(Entier * e): Expr(),value(e->getValeur()) {}
    virtual~ExprConst() {}
    void Affiche();
    operator int() const { return value; }
    int eval();
protected:
    int value;
};

class ExprPlus : public Expr {
    public:
        ExprPlus(Expr * e1,Expr * e2): Expr(),exprGauche(e1),exprDroite(e2) {}
        virtual~ExprPlus() {}
        void Affiche();
        int eval();
    protected:
        Expr * exprGauche;
        Expr * exprDroite;
};

class ExprMult : public Expr {
    public:
        ExprMult(Expr * e1,Expr * e2): Expr(),exprGauche(e1),exprDroite(e2) {}
        virtual~ExprMult() {}
        void Affiche();
        int eval();
    protected:
        Expr * exprGauche;
        Expr * exprDroite;
};

