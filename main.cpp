#include "constantes.h"
#include "tablas.h"
#include "estructuras.h"
#include "Login.h"
#include "Mantenimiento.h"
#include "Procesos.h"
#include "Reportes.h"



void menuPrincipal(ListaTrabajador &listaTrab) {
    int opc;
    do {
        system("cls");
        system("COLOR B0");
        PintarCuadrado(0,0,120,36);//Cuadro grande
        PintarCuadrado(35,2,85,5);//Cuadro del titulo
        gotoxy(47,3);
        cout << "SISTEMA DE RECURSOS HUMANOS";
        gotoxy(43,4);
        cout << "MUNICIPALIDAD DISTRITAL DE CHICLAYO";
        gotoxy(53,7);
        cout << "MENU PRINCIPAL";
        gotoxy(52,10);
        cout << "1. MANTENIMIENTO";
        gotoxy(52,11);
        cout << "2. PROCESOS";
        gotoxy(52,12);
        cout << "3. REPORTES";
        gotoxy(52,13);
        cout << "4. SALIR";

        gotoxy(47,15);
        opc = leeEntero("Seleccione: ", 1,4);

        switch (opc) {
            case 1:
                menuMantenimiento(listaTrab);
                break;
            case 2:
                menuProcesos(listaTrab);
                break;
            case 3:
                menuReportes();
                break;
            case 4:
                PintarCuadrado(35,29,85,34);//Cuadro de los autores
                gotoxy(44,30);
                cout << "GRACIAS POR USAR NUESTRO PROGRAMA";
                gotoxy(45,32);
                cout << "Elaborado por JoisRomero & Rodo" << endl << endl;
                break;
        }
    } while (!(opc == 4));
}

int main(){
    int opc;
    //mainLogin();
    ListaTrabajador listaTrab;
    iniciaListaTrabajador(listaTrab);
    menuPrincipal(listaTrab);
    getch();
    cout << "\n\n\n";
    return 0;
}
