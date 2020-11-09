#include "estructuras.h"
#include "Login.h"
#include "Mantenimiento.h"
#include "Procesos.h"
#include "Reportes.h"

void menuPrincipal() {
    int opc;
    do {
        system("cls");
        system("COLOR B0");
        PintarCuadrado(0,0,78,24);//Cuadro grande
        PintarCuadrado(1,1,77,4);//Cuadro del titulo
        gotoxy(25,2);
        cout << "SISTEMA DE RECURSOS HUMANOS";
        gotoxy(21,3);
        cout << "MUNICIPALIDAD DISTRITAL DE CHICLAYO";
        gotoxy(33,6);
        cout << "MENU PRINCIPAL";
        gotoxy(32,9);
        cout << "1. MANTENIMIENTO";
        gotoxy(32,10);
        cout << "2. PROCESOS";
        gotoxy(32,11);
        cout << "3. REPORTES";
        gotoxy(32,12);
        cout << "4. SALIR";
        cout << "\n\n\n";
        opc = leeEntero("\t\t\tSeleccione: ", 1,4);

        switch (opc) {
            case 1:
                menuMantenimiento();
                break;
            case 2:
                menuProcesos();
                break;
            case 3:
                menuReportes();
                break;
            case 4:
                gotoxy(24,23);
                cout << "GRACIAS POR USAR NUETRO PROGRAMA";
                break;
        }
    } while (!(opc == 4));
}

int main(){
    int opc;
    //mainLogin();
    menuPrincipal();
    getch();
    cout << "\n\n\n";
    return 0;
}
