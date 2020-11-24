void insertarPagosBaseDatos(Trabajador &trab,ModuloAsistencia &asistencia, Sueldo &sueldo, sqlite3 *db) {
    char sql[500];

    sprintf(sql, "INSERT INTO Asistencia (Codigo, Anio, Mes, Asistencia, Faltas, Tardanzas, Justificacion) VALUES ('%s', %d, %d, %d, %d, %d, %d)",
            trab.codigo,asistencia.anio, asistencia.mes, asistencia.asistencia, asistencia.falta, asistencia.tardanza, asistencia.justificacion);
    if (sqlite3_exec(db, sql, NULL, NULL, NULL) != SQLITE_OK) {
        gestionaError(db);
        return;
    }
    sprintf(sql, "INSERT INTO Sueldo (Codigo, Anio, Mes, AsignacionFamiliar, Descuento, Bonificacion, Adelanto, SueldoNeto) VALUES ('%s', %d, %d, %f, %f, %f, %f, %f)",
            trab.codigo, sueldo.anio, sueldo.mes, sueldo.asignacionFamiliar, sueldo.descuento, sueldo.bonificacion, sueldo.adelanto, sueldo.sueldoNeto);
    if (sqlite3_exec(db, sql, NULL, NULL, NULL) != SQLITE_OK) {
        gestionaError(db);
        return;
    }
}

void registrarPagos(ListaTrabajador &lstTrab, sqlite3 *db) {
    NodoTrabajador *nAux = lstTrab.cab;

    if (nAux != NULL) {
        int i = 0, z, auxMes, auxAnio, auxFaltas;
        system("cls");
        interfazmenu("REGISTRAR PAGOS");
        cout << endl << endl;
        auxMes = leeEntero("\n\tIngrese Mes: ", 1, 12);
        auxAnio = leeEntero("\n\tIngrese Anio: ", 2020, 2050);
        for (NodoTrabajador *Aux = lstTrab.cab; Aux != NULL; Aux = Aux->sgte) {
            z = 0;
            auxFaltas = 0;
            system("cls");
            gotoxy(8,6);
            cout << ".::TRABAJADOR "<< i+1 << "::.";
            leeListaModuloAsistencia(Aux->trab.pagos.listaAsistencia);
            if(Aux->trab.pagos.listaAsistencia.num > 0) {
                z = Aux->trab.pagos.listaAsistencia.num-1;
            }
            Aux->trab.pagos.listaAsistencia.datos[z].anio = auxAnio;
            Aux->trab.pagos.listaAsistencia.datos[z].mes = auxMes;

            system("cls");
            gotoxy(8,6);
            cout << ".::TRABAJADOR "<< i+1 << "::.";
            leeListaSueldo(Aux->trab.pagos.listaSueldo);
            Aux->trab.pagos.listaSueldo.datos[z].anio = auxAnio;
            Aux->trab.pagos.listaSueldo.datos[z].mes = auxMes;
            if (Aux->trab.nroHijos > 0) {
                Aux->trab.pagos.listaSueldo.datos[z].asignacionFamiliar = 0.1 * Aux->trab.contrato.sueldoBase;
            }

            auxFaltas = Aux->trab.pagos.listaAsistencia.datos[z].falta - Aux->trab.pagos.listaAsistencia.datos[z].justificacion;

            Aux->trab.pagos.listaSueldo.datos[z].descuento = (27.5 * auxFaltas) + (7.5 * Aux->trab.pagos.listaAsistencia.datos[z].tardanza);
            Aux->trab.pagos.listaSueldo.datos[z].sueldoNeto = Aux->trab.contrato.sueldoBase + Aux->trab.pagos.listaSueldo.datos[z].bonificacion
                    - Aux->trab.pagos.listaSueldo.datos[z].descuento + Aux->trab.pagos.listaSueldo.datos[z].asignacionFamiliar
                    - Aux->trab.pagos.listaSueldo.datos[z].adelanto;
            insertarPagosBaseDatos(Aux->trab,Aux->trab.pagos.listaAsistencia.datos[z], Aux->trab.pagos.listaSueldo.datos[z], db);
            i++;
        }

        cout << "\n\n\n\t\t\tSE REGISTRARON LOS PAGOS CON EXITO!!";

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
    interfazmenu("\t\tMOSTRAR TRABAJADORES");

    gotoxy(48,9);
    cout << "1. MOSTRAR TODOS LOS TRABAJADORES";
    gotoxy(48,10);
    cout << "2. MOSTRAR UN TRABAJADOR" << endl;

    opc = leeEntero("\t\t\t\t\t\tSeleccione: ", 1,2);

    switch(opc) {
    case 1:
        mostrarListaTrabajador(lstTrab);
        break;
    case 2:
        char auxDni[MAXDNI];
        bool band = 0;
        system("cls");
        interfazmenu("\t\tMOSTRAR TRABAJADORES");
        cout << endl << endl;
        leeTextoComoNumero("\t\tIngrese DNI del trabajador a mostrar", auxDni, MAXDNI);

        for (NodoTrabajador *Aux = lstTrab.cab; Aux != NULL; Aux = Aux->sgte) {
            if (strcmp(Aux->trab.dni, auxDni) == 0) {
                system("cls");
                interfazmenu("TRABAJADOR");
                band = 1;
                mostrarTrabajador(Aux->trab);
            }
        }

        if (band == 0) {
            cout << "\n\n\tNo existe un trabajador con ese DNI";
        }

        getch();
        break;
    }

}

void eliminarTrabajador(ListaTrabajador &lstTrab, sqlite3 *db) {

    if (lstTrab.cab != NULL) {
        char auxCodigo[MAXCODIGO];
        char auxDni[MAXDNI];
        NodoTrabajador *auxBorrar = lstTrab.cab;
        NodoTrabajador *anterior = NULL;
        char sql1[300] = "DELETE FROM Asistencia WHERE Codigo = ";
        char sql2[300] = "DELETE FROM Sueldo WHERE Codigo = ";
        char sql3[300] = "DELETE FROM Cargo WHERE Codigo = ";
        char sql4[300] = "DELETE FROM Contrato WHERE Codigo = ";
        char sql5[300] = "DELETE FROM Direccion WHERE Codigo = ";
        char sql6[300] = "DELETE FROM Trabajador WHERE Codigo = ";


        system("cls");
        interfazmenu("\t\tELIMINAR");
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
            strcpy(auxCodigo,auxBorrar->trab.codigo);
            delete auxBorrar;
            cout << "\n\tTrabajador eliminado con exito";
        } else {
            anterior->sgte = auxBorrar->sgte;
            liberarListaModuloAsistencia(auxBorrar->trab.pagos.listaAsistencia);
            liberarListaSueldo(auxBorrar->trab.pagos.listaSueldo);
            strcpy(auxCodigo,auxBorrar->trab.codigo);
            delete auxBorrar;
            cout << "\n\tTrabajador eliminado con exito";
        }
        strcat(sql1,auxCodigo);
        if (sqlite3_exec(db, sql1, NULL, NULL, NULL) != SQLITE_OK) {
            gestionaError(db);
            return;
        }
        strcat(sql2,auxCodigo);
        if (sqlite3_exec(db, sql2, NULL, NULL, NULL) != SQLITE_OK) {
            gestionaError(db);
            return;
        }
        strcat(sql3,auxCodigo);
        if (sqlite3_exec(db, sql3, NULL, NULL, NULL) != SQLITE_OK) {
            gestionaError(db);
            return;
        }
        strcat(sql4,auxCodigo);
        if (sqlite3_exec(db, sql4, NULL, NULL, NULL) != SQLITE_OK) {
            gestionaError(db);
            return;
        }
        strcat(sql5,auxCodigo);
        if (sqlite3_exec(db, sql5, NULL, NULL, NULL) != SQLITE_OK) {
            gestionaError(db);
            return;
        }
        strcat(sql6,auxCodigo);
        if (sqlite3_exec(db, sql6, NULL, NULL, NULL) != SQLITE_OK) {
            gestionaError(db);
            return;
        }

    } else {
        system("cls");
        interfazmenu("ADVERTENCIA");
        cout << "\n\n\tNO HAY TRABAJADORESS REGISTRADOS AUN";
    }
    getch();
}

// ----------------  MENU MANTENIMIENTO  --------------------

void menuMantenimiento(ListaTrabajador &listaTrab, sqlite3 *db) {
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
        cout << endl << endl;
        opc = leeEntero("\t\t\t\t\t\tSeleccione: ", 1,5);

        switch (opc) {
        case 1:
            leeListaTrabajador(listaTrab, db);
            break;
        case 2:
            registrarPagos(listaTrab, db);
            break;
        case 3:
            mostrarTrabajadores(listaTrab);
            getch();
            break;
        case 4:
            eliminarTrabajador(listaTrab, db);
            break;
        case 5:
            gotoxy(46,23);
            cout << "VOLVIENDO AL MENU PRINCIPAL";
            getch();
            break;
        }
    } while (!(opc == 5));
}

