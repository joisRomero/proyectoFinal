
//Lista trabajador
struct NodoTrabajador{
    Trabajador trab;
    NodoTrabajador *sgte;
};

struct ListaTrabajador{
    NodoTrabajador *cab;
    int numTrabaj;
};

void iniciaListaTrabajador(ListaTrabajador &listaTrab){
    listaTrab.cab = NULL;
    listaTrab.numTrabaj = 0;
}

void insertaListaTrabajador(ListaTrabajador &listaTrab, Trabajador &trab, NodoTrabajador *&Aux) {
    NodoTrabajador *p = new NodoTrabajador;
    p->trab = trab;

    if (Aux == NULL) {
        p->sgte = listaTrab.cab;
        listaTrab.cab = p;
    } else {
        p->sgte = Aux->sgte;
        Aux->sgte = p;
    }
    listaTrab.numTrabaj++;
    Aux = p;
}

void leeListaTrabajador(ListaTrabajador &listaTrab) {
    Trabajador trab;
    NodoTrabajador *Aux = listaTrab.cab;
    do {
        system("cls");
        cout << "\n\n Lectura de Datos:";
        iniciaTrabajador(trab);
        leeTrabajador(trab);
        insertaListaTrabajador(listaTrab, trab, Aux);
    } while (continuar("\nDesea registrar otro empleado (S/N): ") == 'S');
    fflush(stdin);
}

void mostrarListaEmpleado(ListaTrabajador &listaTrab){
    int i = 1;
    system("cls");
    cout << "\nLISTA DE TRABAJADORES: \n";
    for(NodoTrabajador *Aux = listaTrab.cab; Aux != NULL; Aux = Aux->sgte) {
        cout << "\n\n\t::TRABAJADOR "<< i++ << ":: ";
        mostrarTrabajador(Aux->trab);
    }
}


//void mostrarTrabajador(){
//}
//
//void eliminarTrabajador(){
//}

void menuMantenimiento(){
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
        cout << "2. MOSTRAR TRABAJADOR";
        gotoxy(27,11);
        cout << "3. ELIMINAR TRABAJADOR";
        gotoxy(27,12);
        cout << "4. IR AL MENU PRINCIPAL";
        cout << "\n\n\n";
        opc = leeEntero("\t\t\tSeleccione: ", 1,4);

        switch (opc) {
            case 1:
//                registrarTrabajador();
                break;
            case 2:
//                mostrarTrabajador();
                break;
            case 3:
//                eliminarTrabajador();
                break;
            case 4:
                gotoxy(27,23);
                cout << "VOLVIENDO AL MENU PRINCIPAL";
                getch();
                break;
        }
    } while (!(opc == 4));
}

