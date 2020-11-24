/*
    Programa elaborado por:
            Gonzales Bocanegra Jose David
            Romero Olivera Jose Luis
*/

#include "sqlite3.h"
#include "constantes.h"
#include "tablas.h"
#include "estructuras.h"
#include "BaseDeDatos.h"
#include "Login.h"
#include "Mantenimiento.h"
#include "Procesos.h"
#include "Reportes.h"


void menuPrincipal(ListaTrabajador &listaTrab, sqlite3 *db) {
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

        cout << endl << endl;
        opc = leeEntero("\t\t\t\t\t\tSeleccione: ", 1,4);

        switch (opc) {
            case 1:
                menuMantenimiento(listaTrab, db);
                break;
            case 2:
                menuProcesos(listaTrab, db);
                break;
            case 3:
                menuReportes(listaTrab);
                break;
            case 4:
                PintarCuadrado(35,29,85,34);//Cuadro de los autores
                gotoxy(44,30);
                cout << "GRACIAS POR USAR NUESTRO PROGRAMA";
                gotoxy(45,32);
                cout << "Elaborado por joisRomero & Rodo" << endl << endl;
                break;
        }
    } while (!(opc == 4));
}



int main(){
    sqlite3 *db;
    sqlite3_stmt *query01, *query02, *query03, *query04, *query05, *query06;

    //mainLogin();
    ListaTrabajador listaTrab;
    iniciaListaTrabajador(listaTrab);

    // Abrir base de datos
    if(sqlite3_open("baseDeDatos.db", &db) != SQLITE_OK) {
        return gestionaError(db);
    }
    // llena la lista con los datos
    llenarLista(listaTrab, db, query01, query02, query03, query04, query05, query06);
    menuPrincipal(listaTrab, db);
    getch();

    //cierra las sentencias SQL
    sqlite3_finalize(query01);
    sqlite3_finalize(query02);
    sqlite3_finalize(query03);
    sqlite3_finalize(query04);
    sqlite3_finalize(query05);
    sqlite3_finalize(query06);
    //cierra la base de datos
    sqlite3_close(db);

    cout << "\n\n\n";
    return 0;
}
