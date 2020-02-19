#pragma once

#include <string>
using namespace std;

enum Identificateurs { OPENPAR, CLOSEPAR, PLUS, MULT, INT, FIN, ERREUR, EXPR};

const string Etiquettes[] = { "OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "FIN", "ERREUR", "EXPR" };

class Symbole {
   public:
      Symbole(int i, bool b = true) : ident(i),terminal(b) {  }
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
      Entier(int v) : Symbole(INT), valeur(v) { }
      ~Entier() { }
      virtual void Affiche();
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
    ExprConst(): Expr() {}
    virtual~ExprConst() {}
    operator int() const { return value; }
    int eval();
protected:
    int value;
};

class ExprPlus : public Expr {
    public:
        ExprPlus(): Expr() {}
        virtual~ExprPlus() {}
        int eval();
    protected:
        ExprConst exprDroite;
        ExprConst exprGauche;
};

class ExprMult : public Expr {
    public:
        ExprMult(): Expr() {}
        virtual~ExprMult() {}
        int eval();
    protected:
        ExprConst exprDroite;
        ExprConst exprGauche;
};

