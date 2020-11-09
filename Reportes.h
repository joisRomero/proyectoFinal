void menuReportes(){
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
        cout << "MENU REPORTES";
        gotoxy(27,9);
        cout << "1. GONZALES BOCANEGRA";
        gotoxy(27,10);
        cout << "2. ROMERO OLIVERA";
        gotoxy(27,11);
        cout << "3. IR AL MENU PRINCIPAL";
        cout << "\n\n\n";
        opc = leeEntero("\t\t\tSeleccione: ", 1,3);

        switch (opc) {
            case 1:
               //menuMantenimiento();
                break;
            case 2:
                //menuProcesos();
                break;
            case 3:
                gotoxy(27,23);
                cout << "VOLVIENDO AL MENU PRINCIPAL";
                getch();
                break;
        }
    } while (!(opc == 3));
}
