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

class Plus : public Symbole {
   public:
      Plus() : Symbole(PLUS) { }
      ~Plus() { }
      virtual void Affiche();
};

class Mult : public Symbole {
   public:
      Mult() : Symbole(MULT) { }
      ~Mult() { }
      virtual void Affiche();
};

class Openpar : public Symbole {
   public:
      Openpar() : Symbole(OPENPAR) { }
      ~Openpar() { }
      virtual void Affiche();
};

class Closepar : public Symbole {
   public:
      Closepar() : Symbole(CLOSEPAR) { }
      ~Closepar() { }
      virtual void Affiche();
};

class Closepar : public Symbole {
   public:
      Closepar() : Symbole(CLOSEPAR) { }
      ~Closepar() { }
      virtual void Affiche();
};

class Expr : public Symbole {
    public:
        Expr(): Symbole(EXPR,false) {}
        virtual~Expr() {}
        virtual double eval(const map<string,double>& valeurs) = 0;};


