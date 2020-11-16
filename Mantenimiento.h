void registrarPagos(ListaTrabajador &lstTrab) {
    NodoTrabajador *Aux = lstTrab.cab;

    if (Aux != NULL) {
        int y = -1, z = 0;

        if (Aux->trab.pagos.listaAsistencia.num != 0)
            y = Aux->trab.pagos.listaAsistencia.num - 1;

        if (y != -1) {
            if(Aux->trab.pagos.listaAsistencia.datos[y].mes == MESACTUAL) {
                system("cls");
                interfazmenu("ADVERTENCIA");
                cout << "\n\n\t\t\tYA SE REGISTRARON LOS PAGOS DE ESTE MES";
            }
        } else {
            int i = 0;
            int auxFaltas;
            while (Aux != NULL) {
                system("cls");
                gotoxy(8,6);
                cout << ".::TRABAJADOR "<< i+1 << "::.";
                leeListaModuloAsistencia(Aux->trab.pagos.listaAsistencia);
                if(Aux->trab.pagos.listaAsistencia.num > 0) {
                    z = Aux->trab.pagos.listaAsistencia.num-1;
                }
                system("cls");
                gotoxy(8,6);
                cout << ".::TRABAJADOR "<< i+1 << "::.";
                leeListaSueldo(Aux->trab.pagos.listaSueldo);

                if (Aux->trab.nroHijos > 0) {
                    Aux->trab.pagos.listaSueldo.datos[z].asignacionFamiliar = 0.1 * Aux->trab.contrato.sueldoBase;
                }

                auxFaltas = Aux->trab.pagos.listaAsistencia.datos[z].falta - Aux->trab.pagos.listaAsistencia.datos[z].justificacion;

                Aux->trab.pagos.listaSueldo.datos[z].descuento = (27.5 * auxFaltas) + (7.5 * Aux->trab.pagos.listaAsistencia.datos[z].tardanza);
                Aux->trab.pagos.listaSueldo.datos[z].sueldoNeto = Aux->trab.contrato.sueldoBase + Aux->trab.pagos.listaSueldo.datos[z].bonificacion
                                            - Aux->trab.pagos.listaSueldo.datos[z].descuento + Aux->trab.pagos.listaSueldo.datos[z].asignacionFamiliar
                                            - Aux->trab.pagos.listaSueldo.datos[z].adelanto;
                i++;
                Aux = Aux->sgte;
            }
        }

    } else {
        system("cls");
        interfazmenu("ADVERTENCIA");
        cout << "\n\n\tAUN NO HAY TRABJADORES REGISTRADOS";
    }

    getch();
}

void mostrarTrabajadores(ListaTrabajador &lstTrab) {
    int opc;
    system("cls");
    interfazmenu("MOSTRAR TRABAJADORES");

    gotoxy(27,9);
    cout << "1. MOSTRAR TODOS LOS TRABAJADORES";
    gotoxy(27,10);
    cout << "2. MOSTRAR UN TRABAJADOR";

    opc = leeEntero("\n\t\t\tSeleccione: ", 1,2);

    switch(opc) {
    case 1:
        mostrarListaTrabajador(lstTrab);
        break;
    case 2:
        char auxDni[MAXDNI];
        bool band = 0;
        system("cls");
        interfazmenu("MOSTRAR TRABAJADORES");
        cout << endl << endl;
        leeTextoComoNumero("\tIngrese DNI del trabajador a mostrar", auxDni, MAXDNI);

        for (NodoTrabajador *Aux = lstTrab.cab; Aux != NULL; Aux = Aux->sgte){
            if (strcmp(Aux->trab.dni, auxDni) == 0){
                system("cls");
                interfazmenu("TRABAJADOR");
                band = 1;
                mostrarTrabajador(Aux->trab);
            }
        }

        if (band == 0){
            cout << "\n\n\tNo existe un trabajador con ese DNI";
        }

        getch();
        break;
    }

}

void eliminarTrabajador(ListaTrabajador &lstTrab) {

    if (lstTrab.cab != NULL) {
        char auxDni[MAXDNI];
        NodoTrabajador *auxBorrar = lstTrab.cab;
        NodoTrabajador *anterior = NULL;
        system("cls");
        interfazmenu("ELIMINAR");
        cout << endl << endl;
        leeTextoComoNumero("\tIngrese DNI del trabajador a eliminar", auxDni, MAXDNI);

        while((auxBorrar != NULL) && (strcmp(auxBorrar->trab.dni, auxDni) != 0)) {
            anterior = auxBorrar;
            auxBorrar = auxBorrar->sgte;
        }

        if (auxBorrar == NULL) {
            cout << "\n\tTrabajador no encontrado";
        } else if (anterior == NULL) {
            lstTrab.cab = auxBorrar->sgte;
            liberarListaModuloAsistencia(auxBorrar->trab.pagos.listaAsistencia);
            liberarListaSueldo(auxBorrar->trab.pagos.listaSueldo);
            delete auxBorrar;
            cout << "\n\tTrabajador eliminado con exito";
        } else {
            anterior->sgte = auxBorrar->sgte;
            liberarListaModuloAsistencia(auxBorrar->trab.pagos.listaAsistencia);
            liberarListaSueldo(auxBorrar->trab.pagos.listaSueldo);
            delete auxBorrar;
            cout << "\n\tTrabajador eliminado con exito";
        }
    } else {
        system("cls");
        interfazmenu("ADVERTENCIA");
        cout << "\n\n\tNO HAY TRABAJADOreS REGISTRADOS AUN";
    }
    getch();
}

// ----------------  MENU MANTENIMIENTO  --------------------

void menuMantenimiento(ListaTrabajador &listaTrab) {
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
        gotoxy(52,7);
        cout << "MENU MANTENIMIENTO";
        gotoxy(49,10);
        cout << "1. REGISTRAR TRABAJADOR";
        gotoxy(49,11);
        cout << "2. REGISTRAR PAGOS";
        gotoxy(49,12);
        cout << "3. MOSTRAR TRABAJADORES";
        gotoxy(49,13);
        cout << "4. ELIMINAR TRABAJADOR";
        gotoxy(49,14);
        cout << "5. IR AL MENU PRINCIPAL";

        gotoxy(47,16);
        opc = leeEntero("Seleccione: ", 1,5);

        switch (opc) {
        case 1:
            leeListaTrabajador(listaTrab);
            break;
        case 2:
            registrarPagos(listaTrab);
            break;
        case 3:
            mostrarTrabajadores(listaTrab);
            getch();
            break;
        case 4:
            eliminarTrabajador(listaTrab);
            break;
        case 5:
            gotoxy(46,23);
            cout << "VOLVIENDO AL MENU PRINCIPAL";
            getch();
            break;
        }
    } while (!(opc == 5));
}

