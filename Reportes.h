void menuReportes(){
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
        cout << "MENU REPORTES";
        gotoxy(48,10);
        cout << "1. GONZALES BOCANEGRA";
        gotoxy(48,11);
        cout << "2. ROMERO OLIVERA";
        gotoxy(48,12);
        cout << "3. IR AL MENU PRINCIPAL";
        cout << endl << endl;
        opc = leeEntero("\t\t\t\t\t\tSeleccione: ", 1,3);

        switch (opc) {
            case 1:
               //reporte Rodo;
                break;
            case 2:
                //reporte JoisRomero;
                break;
            case 3:
                gotoxy(47,23);
                cout << "VOLVIENDO AL MENU PRINCIPAL";
                getch();
                break;
        }
    } while (!(opc == 3));
}
