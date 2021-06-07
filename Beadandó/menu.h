#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "zsak.h"

class Menu
{
    public:
        Menu() {};
        void Run();
    private:
        int MenuPrint();
        void Zsakba();
        void Zsakbol();
		void Legnagyobb();
        void Urese();
        void KiirZsak();
        void TerhelesTeszt();
        Bag Q;

};

#endif