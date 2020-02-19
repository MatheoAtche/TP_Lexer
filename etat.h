#ifndef ETAT_H
#define ETAT_H

#include "automate.h"

class E0;
class E1;
class E2;
class E3;
class E4;
class E5;
class E6;
class E7;
class E8;
class E9;


class etat
{
public:
    etat(string name);
    virtual ~etat();
    void print () const;
    virtual bool transition(Automate & automate,Symbole*s) = 0;
protected: string name;
};

class E0: public etat{
    E0();
    bool transition(Automate &automate, Symbole *s);
};

class E1: public etat{
    E1();
    bool transition(Automate &automate, Symbole *s);
};

class E2: public etat{
    E2();
    bool transition(Automate &automate, Symbole *s);
};

class E3: public etat{
    E3();
    bool transition(Automate &automate, Symbole *s);
};


class E4: public etat{
    E4();
    bool transition(Automate &automate, Symbole *s);
};

class E5: public etat{
    E5();
    bool transition(Automate &automate, Symbole *s);
};

class E6: public etat{
    E6();
    bool transition(Automate &automate, Symbole *s);
};

class E7: public etat{
    E7();
    bool transition(Automate &automate, Symbole *s);
};

class E8: public etat{
    E8();
    bool transition(Automate &automate, Symbole *s);
};

class E9: public etat{
    E9();
    bool transition(Automate &automate, Symbole *s);
};



#endif // ETAT_H
