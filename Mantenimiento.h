void registrarPagos(ListaTrabajador &lstTrab) {
    NodoTrabajador *Aux = lstTrab.cab;

    if (Aux != NULL) {
        int y = -1;

        if (Aux->trab.pagos.listaAsistencia.num != 0)
            y = Aux->trab.pagos.listaAsistencia.num - 1;

        if (y != -1) {
            if(Aux->trab.pagos.listaAsistencia.datos[y].mes == MESACTUAL) {
                system("cls");
                interfazmenu("ADVERTENCIA");
                cout << "\n\n\t\t\tYA SE REGISTRARON LOS PAGOS DE ESTE MES";
            }
        } else {
            cout << "\n\nentre despues else";
            int i = 0;
            int auxFaltas;
            while (Aux != NULL) {
                system("cls");
                gotoxy(8,6);
                cout << ".::TRABAJADOR "<< i+1 << "::.";
                leeListaModuloAsistencia(Aux->trab.pagos.listaAsistencia);

                system("cls");
                gotoxy(8,6);
                cout << ".::TRABAJADOR "<< i+1 << "::.";
                leeListaSueldo(Aux->trab.pagos.listaSueldo);

                if (Aux->trab.nroHijos > 0) {
                    Aux->trab.pagos.listaSueldo.datos[i].asignacionFamiliar = 0.1 * Aux->trab.contrato.sueldoBase;
                }

                auxFaltas = Aux->trab.pagos.listaAsistencia.datos[i].falta - Aux->trab.pagos.listaAsistencia.datos[i].justificacion;

                Aux->trab.pagos.listaSueldo.datos[i].descuento = (27.5 * auxFaltas) + (7.5 * Aux->trab.pagos.listaAsistencia.datos[i].tardanza);
                Aux->trab.pagos.listaSueldo.datos[i].sueldoNeto = Aux->trab.contrato.sueldoBase + Aux->trab.pagos.listaSueldo.datos[i].bonificacion
                        - Aux->trab.pagos.listaSueldo.datos[i].descuento + Aux->trab.pagos.listaSueldo.datos[i].asignacionFamiliar;
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

void eliminarTrabajador(ListaTrabajador &lstTrab) {
    NodoTrabajador *Aux = lstTrab.cab;

    if (lstTrab != NULL) {

    } else {
        system("cls");
        interfazmenu("ADVERTENCIA");
        cout << "\n\n\t\t\tNO HAY TRABAJADOS REGISTRADOS AUN";
    }
}

// ----------------  MENU MANTENIMIENTO  --------------------

void menuMantenimiento(ListaTrabajador &listaTrab) {
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
        cout << "3. MOSTRAR TRABAJADORES";
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
            registrarPagos(listaTrab);
            break;
        case 3:
            mostrarListaTrabajador(listaTrab);
            getch();
            break;
        case 4:
            eliminarTrabajador(listaTrab);
            break;
        case 5:
            gotoxy(27,23);
            cout << "VOLVIENDO AL MENU PRINCIPAL";
            getch();
            break;
        }
    } while (!(opc == 5));
}

