
//Lista trabajador
struct NodoTrabajador{
    Trabajador trab;
    NodoTrabajador *sgte;
};

struct ListaTrabajador{
    NodoTrabajador *cab;
    int numTrabaj;
};

void iniciaListaTrabajador(ListaTrabajador &lstTrab){
    lstTrab.cab = NULL;
    lstTrab.numTrabaj = 0;
}

void insertaListaTrabajador(ListaTrabajador &lstTrab, Trabajador &trab, NodoTrabajador *&Aux) {
    NodoTrabajador *p = new NodoTrabajador;
    p->trab = trab;

    if (Aux == NULL) {
        p->sgte = lstTrab.cab;
        lstTrab.cab = p;
    } else {
        p->sgte = Aux->sgte;
        Aux->sgte = p;
    }
    lstTrab.numTrabaj++;
    Aux = p;
}

void leeListaTrabajador(ListaTrabajador &lstTrab) {
    Trabajador trab;
    NodoTrabajador *Aux = lstTrab.cab;
    do {
        system("cls");
        cout << "\n\n Lectura de Datos:";
        iniciaTrabajador(trab);
        leeTrabajador(trab);
        insertaListaTrabajador(lstTrab, trab, Aux);
    } while (continuar("\nDesea registrar otro empleado? (S/N): ") == 'S');
    fflush(stdin);
}

void mostrarListaTrabajador(ListaTrabajador &lstTrab){
    int i = 1;
    system("cls");
    cout << "\nLISTA DE TRABAJADORES: \n";
    for(NodoTrabajador *Aux = lstTrab.cab; Aux != NULL; Aux = Aux->sgte) {
        cout << "\n\n\t::TRABAJADOR "<< i++ << ":: ";
        mostrarTrabajador(Aux->trab);
    }
}


//void mostrarTrabajador(){
//}
//
//void eliminarTrabajador(){
//}

//Lista ModuloAsistencia

struct ListaModuloAsistencia{
    ModuloAsistencia *datos;
    int num, max;
};

void iniciaListaModuloAsistencia(ListaModuloAsistencia &lstModAsis){
    lstModAsis.datos = NULL;
    lstModAsis.num = 0;
    lstModAsis.max = 0;
}

void creceListaModuloAsistencia(ListaModuloAsistencia &lstModAsis){
    ModuloAsistencia *temp;
    temp = new ModuloAsistencia[lstModAsis.max+DELTA];
    for (int i = 0; i < lstModAsis.num; i++){
        temp[i] = lstModAsis.datos[i];
    }
    delete []lstModAsis.datos;
    lstModAsis.datos = temp;
    lstModAsis.max += DELTA;
}

void insertaModuloAsistencia(ListaModuloAsistencia &lstModAsis, ModuloAsistencia &ModAsis){
    if(lstModAsis.num == lstModAsis.max){
        creceListaModuloAsistencia(lstModAsis);
    }
    lstModAsis.datos[lstModAsis.num] = ModAsis;
    lstModAsis.num++;
}

void leeListaModuloAsistencia(ListaModuloAsistencia &lstModAsis){
    ModuloAsistencia ModAsis;
    system("cls");
    cout << "\nLectura de Datos: ";
    do{
        iniciaModuloAsistencia(ModAsis);
        leeModuloAsistencia(ModAsis);
        insertaModuloAsistencia(lstModAsis, ModAsis);
    }while(continuar("\nDesea agregar otro Modulo de Asistencia? (S/N): ")=='S');
}

void mostrarListaModuloAsistencia(ListaModuloAsistencia &lstModAsis){
    system("cls");
    cout << "\nLISTA DE MODULOS DE ASISTENCIA: \n";
    for(int i = 0; i < lstModAsis.num; i++) {
        cout << "\n\n\t::MODULO DE ASISTENCIA "<< i+1 << ":: "; //tabladelmes
        mostrarModuloAsistencia(lstModAsis.datos[i]);
    }
}

void liberarListaModuloAsistencia(ListaModuloAsistencia &lstModAsis){
    delete []lstModAsis.datos;
}


//Lista Sueldo

struct ListaSueldo{
    Sueldo *datos;
    int num, max;
};

void iniciaListaSueldo(ListaSueldo &lstSueldo){
    lstSueldo.datos = NULL;
    lstSueldo.max = 0;
    lstSueldo.num = 0;
}

void creceListaSueldo(ListaSueldo &lstSueldo){
    Sueldo *temp;
    temp = new Sueldo[lstSueldo.max+DELTA];
    for (int i = 0; i < lstSueldo.num; i++){
        temp[i] = lstSueldo.datos[i];
    }
    delete []lstSueldo.datos;
    lstSueldo.datos = temp;
    lstSueldo.max += DELTA;
}

void insertaSueldo(ListaSueldo &lstSueldo, Sueldo &Sue){
    if(lstSueldo.num == lstSueldo.max){
        creceListaSueldo(lstSueldo);
    }
    lstSueldo.datos[lstSueldo.num] = Sue;
    lstSueldo.num++;
}

void leeListaSueldo(ListaSueldo &lstSueldo){
    Sueldo Sue;
    system("cls");
    cout << "\nLectura de Datos: ";
    do{
        iniciaSueldo(Sue);
        leeSueldo(Sue);
        insertaSueldo(lstSueldo, Sue);
    }while(continuar("\nDesea agregar otro Sueldo? (S/N): ")=='S');
}

void mostrarListaSueldo(ListaSueldo &lstSueldo){
    system("cls");
    cout << "\nLISTA DE SUELDOS: \n";
    for(int i = 0; i < lstSueldo.num; i++) {
        cout << "\n\n\t::SUELDO "<< i+1 << ":: "; //tabladelmes
        mostrarSueldo(lstSueldo.datos[i]);
    }
}

void liberarListaSueldo(ListaSueldo &lstSueldo){
    delete []lstSueldo.datos;
}

// ----------------  MENU MANTENIMIENTO  --------------------

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

