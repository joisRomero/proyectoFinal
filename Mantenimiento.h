
// ----------------  MENU MANTENIMIENTO  --------------------

void menuMantenimiento(ListaTrabajador &listaTrab){
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
        gotoxy(30,6);
        cout << "MENU MANTENIMIENTO";
        gotoxy(27,9);
        cout << "1. REGISTRAR TRABAJADOR";
        gotoxy(27,10);
        cout << "2. REGISTRAR PAGOS";
        gotoxy(27,11);
        cout << "3. MOSTRAR TRABAJADOR";
        gotoxy(27,12);
        cout << "4. ELIMINAR TRABAJADOR";
        gotoxy(27,13);
        cout << "5. IR AL MENU PRINCIPAL";
        cout << "\n\n\n";
        opc = leeEntero("\t\t\tSeleccione: ", 1,5);

        switch (opc) {
            case 1:
                leeListaTrabajador(listaTrab);
                break;
            case 2:

                break;
            case 3:
                mostrarListaTrabajador(listaTrab);
                getch();
                break;
            case 4:
//                eliminarTrabajador();
                break;
            case 5:
                gotoxy(27,23);
                cout << "VOLVIENDO AL MENU PRINCIPAL";
                getch();
                break;
        }
    } while (!(opc == 5));
}

