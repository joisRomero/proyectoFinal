//----------------------------------------------  PLANILLAS  --------------------------------------/

void PlanillaDatosPersonal(ListaTrabajador &listaTrab) {
    int i = 12;
    interfazmenu(":: PLANILLA DE DATOS DEL PERSONAL DE LA MDCH ::");
    cout << endl << endl;
    gotoxy(8,11);
    cout << "DNI";
    gotoxy(20,11);
    cout << "NOMBRE";
    gotoxy(52,11);
    cout << "PENSIONES";
    gotoxy(69,11);
    cout << "NRO. HIJOS";
    gotoxy(85,11);
    cout << "GR. INSTRUCCION";
    gotoxy(110,11);
    cout << "CODIGO";

    for(NodoTrabajador *Aux = listaTrab.cab; Aux != NULL; Aux = Aux->sgte) {
        gotoxy(8,i);
        cout << Aux->trab.dni;
        gotoxy(20,i);
        cout << Aux->trab.nombre;
        gotoxy(52,i);
        cout << TablaFomdoPensiones[Aux->trab.fondoPensiones-1];
        gotoxy(69,i);
        cout << Aux->trab.nroHijos;
        gotoxy(85,i);
        cout << TablaGradoInstruccion[Aux->trab.gradoInstruccion-1] ;
        gotoxy(110,i);
        cout << Aux->trab.codigo;
        i++;
    }
    getch();
}

void PlanillaModuloAsistencia(ListaTrabajador &listaTrab) {
    int auxAnio;
    int i = 12;
    int AcumAsistencias, AcumFaltas, AcumTardanzas, AcumJustificaciones;

    interfazmenu(":: PLANILLA DEL MODULO ASISTENCIAS DE LA MDCH ::");
    cout << endl << endl;
    auxAnio = leeEntero("\n\tIngrese anio: ",ANIOACTUAL,2045);

    system("cls");
    interfazmenu(":: PLANILLA DEL MODULO ASISTENCIAS DE LA MDCH ::");
    cout << endl << endl;
    cout << "\t\t\t\t\t\t\tAnio: " << auxAnio << endl <<endl;

    gotoxy(8,11);
    cout << "CODIGO";
    gotoxy(24,11);
    cout << "NOMBRES";
    gotoxy(56,11);
    cout << "ASISTENCIAS";
    gotoxy(73,11);
    cout << "FALTAS";
    gotoxy(85,11);
    cout << "TARDANZAS";
    gotoxy(99,11);
    cout << "JUSTIFICACIONES";

    for(NodoTrabajador *Aux = listaTrab.cab; Aux != NULL; Aux = Aux->sgte) {
        AcumAsistencias = 0;
        AcumFaltas = 0;
        AcumTardanzas = 0;
        AcumJustificaciones = 0;
        for(int i = 0; i < Aux->trab.pagos.listaAsistencia.num ; i++) {
            if(Aux->trab.pagos.listaAsistencia.datos[i].anio==auxAnio && Aux->trab.pagos.listaAsistencia.num!=0) {
                AcumAsistencias += Aux->trab.pagos.listaAsistencia.datos[i].asistencia;
                AcumFaltas += Aux->trab.pagos.listaAsistencia.datos[i].falta;
                AcumTardanzas += Aux->trab.pagos.listaAsistencia.datos[i].tardanza;
                AcumJustificaciones += Aux->trab.pagos.listaAsistencia.datos[i].justificacion;
            }
        }
        gotoxy(8,i);
        cout << Aux->trab.codigo;
        gotoxy(24,i);
        cout << Aux->trab.nombre;
        gotoxy(56,i);
        cout << AcumAsistencias;
        gotoxy(73,i);
        cout << AcumFaltas;
        gotoxy(85,i);
        cout << AcumTardanzas;
        gotoxy(99,i);
        cout << AcumJustificaciones;
        i++;
    }
    getch();
}

void PlanillaInformacionInterbancaria(ListaTrabajador &listaTrab) {
    int i = 12;
    interfazmenu(":: PLANILLA INFORMACION INTERBANCARIA DE LA MDCH ::");
    cout << endl << endl;
    gotoxy(35,11);
    cout << "DNI";
    gotoxy(51,11);
    cout << "NOMBRES";
    gotoxy(83,11);
    cout << "BANCO";

    for(NodoTrabajador *Aux = listaTrab.cab; Aux != NULL; Aux = Aux->sgte) {
        gotoxy(35,i);
        cout << Aux->trab.dni;
        gotoxy(51,i);
        cout << Aux->trab.nombre;
        gotoxy(83,i);
        cout << TablaBanco[Aux->trab.contrato.banco-1];
        i++;
    }
    getch();
}

void PlanillaPagos(ListaTrabajador &listaTrab) {
    int auxAnio, i = 12;
    int AcumAsignacion, AcumDcto, AcumBoni, AcumSueldoNeto;

    interfazmenu("::  PLANILLA DEL TOTAL DE PAGOS DE LA MDCH  ::");
    cout << endl << endl;
    auxAnio = leeEntero("\n\tIngrese anio: ",ANIOACTUAL,2045);

    system("cls");
    interfazmenu("::  PLANILLA DEL TOTAL DE PAGOS DE LA MDCH  ::");
    cout << endl << endl;
    cout << "\t\t\t\t\t\t\tAnio: " << auxAnio << endl <<endl;

    gotoxy(8,11);
    cout << "CODIGO";
    gotoxy(24,11);
    cout << "NOMBRES";
    gotoxy(56,11);
    cout << "ASG.FAMILIAR";
    gotoxy(74,11);
    cout << "DESCUENTO";
    gotoxy(88,11);
    cout << "BONIFICACION";
    gotoxy(106,11);
    cout << "SUELDO NETO";

    for(NodoTrabajador *Aux = listaTrab.cab; Aux != NULL; Aux = Aux->sgte) {
        AcumAsignacion = 0;
        AcumDcto = 0;
        AcumBoni = 0;
        AcumSueldoNeto = 0;
        for(int i = 0; i < Aux->trab.pagos.listaSueldo.num; i++) {
            if(Aux->trab.pagos.listaSueldo.datos[i].anio==auxAnio && Aux->trab.pagos.listaSueldo.num!=0) {
                AcumAsignacion += Aux->trab.pagos.listaSueldo.datos[i].asignacionFamiliar;
                AcumDcto += Aux->trab.pagos.listaSueldo.datos[i].descuento;
                AcumBoni += Aux->trab.pagos.listaSueldo.datos[i].bonificacion;
                AcumSueldoNeto += Aux->trab.pagos.listaSueldo.datos[i].sueldoNeto;
            }
        }
        gotoxy(8,i);
        cout << Aux->trab.codigo;
        gotoxy(24,i);
        cout << Aux->trab.nombre;
        gotoxy(56,i);
        cout << AcumAsignacion;
        gotoxy(74,i);
        cout << AcumDcto;
        gotoxy(88,i);
        cout << AcumBoni;
        gotoxy(106,i);
        cout << AcumSueldoNeto;
        i++;
    }
    getch();
}

void menuPlanillas(ListaTrabajador &listaTrab) {
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
        cout << "MENU PLANILLAS";
        gotoxy(48,10);
        cout << "1. DATOS DEL PERSONAL";
        gotoxy(48,11);
        cout << "2. MODULO ASISTENCIA";
        gotoxy(48,12);
        cout << "3. INFORMACION INTERBANCARIA";
        gotoxy(48,13);
        cout << "4. PAGO DE PERSONAL";
        gotoxy(48,14);
        cout << "5. IR AL MENU PROCESOS";

        cout << endl << endl;
        opc = leeEntero("\t\t\t\t\t\tSeleccione: ", 1,5);

        switch (opc) {
        case 1:
            system("cls");
            PlanillaDatosPersonal(listaTrab);
            break;
        case 2:
            system("cls");
            PlanillaModuloAsistencia(listaTrab);
            break;
        case 3:
            system("cls");
            PlanillaInformacionInterbancaria(listaTrab);
            break;
        case 4:
            system("cls");
            PlanillaPagos(listaTrab);
            break;
        case 5:
            gotoxy(47,23);
            cout << "VOLVIENDO AL MENU PROCESOS";
            getch();
            break;
        }
    } while (!(opc == 5));
}

//----------------------------------------------------------- VACANTES ------------------------------------------//

void vacantesDisponiblesDentroMes(ListaTrabajador &listaTrab) {
    int i=0;
    system("cls");
    interfazmenu(":: VACANTES DISPONIBLES DENTRO DE UN MES ::");
    cout << endl << endl;
    for(NodoTrabajador *Aux = listaTrab.cab; Aux != NULL; Aux = Aux->sgte) {
        if(Aux->trab.contrato.finContrato.Anio == ANIOACTUAL &&  Aux->trab.contrato.finContrato.Mes == MESACTUAL +2) {
            cout << "\tCargo Vacante "<< i+1 <<": ";
            if (Aux->trab.contrato.cargo.grupoOcupacional == 1) {
                cout << TablaDirectorSuperior[Aux->trab.contrato.cargo.claseDeCargo -1] << endl ;
            } else if (Aux->trab.contrato.cargo.grupoOcupacional == 2) {
                cout << TablaEjecutivo[Aux->trab.contrato.cargo.claseDeCargo -1] << endl;
            } else if (Aux->trab.contrato.cargo.grupoOcupacional == 3) {
                cout << TablaEspecialista[Aux->trab.contrato.cargo.claseDeCargo -1] << endl;
            } else {
                cout << TablaApoyo[Aux->trab.contrato.cargo.claseDeCargo -1] << endl;
            }
            i++;
        }
    }

    getch();
}

void numeroDeVacantesPorCargo(ListaTrabajador &listaTrab) {
    int AcumClaseDeCargo[MAXCLASEDECARGO], y=0;
    iniciaVE(AcumClaseDeCargo,MAXCLASEDECARGO);
    system("cls");
    interfazmenu("\t\t:: CARGO / VACANTES ::");
    cout << endl << endl;
    for(NodoTrabajador *Aux = listaTrab.cab ; Aux != NULL; Aux = Aux->sgte) {
        if(Aux->trab.contrato.cargo.grupoOcupacional == 1) {
            AcumClaseDeCargo[Aux->trab.contrato.cargo.claseDeCargo]++;
        } else if(Aux->trab.contrato.cargo.grupoOcupacional == 2) {
            AcumClaseDeCargo[Aux->trab.contrato.cargo.claseDeCargo+(2)-1]++;
        } else if(Aux->trab.contrato.cargo.grupoOcupacional == 3) {
            AcumClaseDeCargo[Aux->trab.contrato.cargo.claseDeCargo+(2+3)-1]++;
        } else if(Aux->trab.contrato.cargo.grupoOcupacional == 4) {
            AcumClaseDeCargo[Aux->trab.contrato.cargo.claseDeCargo+(2+3+10)-1]++;
        }
    }

    for(int i = 0; i < MAXCLASEDECARGO; i++) {
        cout << "\t\t\t-" << TablaTotalCargos[i] << ": " << AcumClaseDeCargo[i] << endl;
    }
    getch();
}

void menuVacantes(ListaTrabajador &listaTrab) {
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
        cout << "MENU VACANTES";
        gotoxy(45,10);
        cout << "1. VACANTES DISPONIBLES DENTRO DE UN MES";
        gotoxy(45,11);
        cout << "2. NUMERO DE VACANTES POR CARGO";
        gotoxy(45,12);
        cout << "3. IR AL MENU PROCESOS";
        cout << endl << endl;
        opc = leeEntero("\t\t\t\t\t\tSeleccione: ", 1,3);

        switch (opc) {
        case 1:
            vacantesDisponiblesDentroMes(listaTrab);
            break;
        case 2:
            numeroDeVacantesPorCargo(listaTrab);
            break;
        case 3:
            gotoxy(47,23);
            cout << "VOLVIENDO AL MENU PROCESOS";
            getch();
            break;
        }
    } while (!(opc == 3));
}

void actualizarInformacion(ListaTrabajador &listaTrab, sqlite3 *db) {
    bool band = 0;
    char auxDni[MAXDNI], auxChar[LIM];

    char sql[300] = "UPDATE Trabajador set Nombre = '";
    char sql0[300] = "UPDATE Trabajador set DNI = '";
    char sql1[300] = "UPDATE Trabajador set Calle = '";
    char sql2[300] = "UPDATE Trabajador set Distrito = '";
    char sql3[300] = "UPDATE Trabajador set FondoPensiones = ";
    char sql4[300] = "UPDATE Trabajador set NunHijos = ";
    char sql5[300] = "UPDATE Trabajador set EstadoCivil = ";
    char sql6[300] = "UPDATE Trabajador set GradoInstruccion = ";
    char sql7[300] = "UPDATE Trabajador set Provincia = ";
    char sql8[300] = "UPDATE Trabajador set GrupoOcupacional = ";
    char sql9[300] = "UPDATE Trabajador set ClaseDeCargo = ";
    char sql10[300] = "UPDATE Trabajador set Horario = ";
    char sql11[300] = "UPDATE Trabajador set Banco = ";
    char sql12[300] = "UPDATE Trabajador set TipoTrabajador = ";
    char sql13[300] = "UPDATE Trabajador set FinContAnio = ";
    char sql14[300] = "UPDATE Trabajador set FinContMes = ";
    char sql15[300] = "UPDATE Trabajador set FindContDia = ";
    char sql16[300] = "UPDATE Trabajador set Edad = ";
    char auxSql[300] = "' WHERE Codigo = ";
    char auxSql1[300] = " WHERE Codigo = ";

    system("cls");
    interfazmenu("ACTUALIZAR INFORMACION");
    cout << endl << endl;

    leeTextoComoNumero("\tIngrese DNI del trabajador", auxDni, MAXDNI);

    for (NodoTrabajador *Aux = listaTrab.cab; Aux != NULL; Aux = Aux->sgte) {
        if (strcmp(Aux->trab.dni, auxDni) == 0) {
            band = 1;
            int opcion;
            cout << "\n\n\tQue opcion desea modificar: " << endl;
            opcion = validaTabla("seleccione: ", tablaopciones, MAXOPCIONES);
            cout << endl << endl;
            switch (opcion) {
            case 1:
                leeTextoComoNumero("\tDNI",Aux->trab.dni, MAXDNI);
                strcat(sql0,Aux->trab.dni);
                strcat(auxSql,Aux->trab.codigo);
                strcat(sql0,auxSql);
                if (sqlite3_exec(db, sql0, NULL, NULL, NULL) != SQLITE_OK) {
                    gestionaError(db);
                    return;
                }
                break;
            case 2:
                cout << "\tNombre Completo: ";
                fflush(stdin);
                cin.getline(Aux->trab.nombre,LIM);
                strcat(sql,Aux->trab.nombre);
                strcat(auxSql,Aux->trab.codigo);
                strcat(sql,auxSql);
                if (sqlite3_exec(db, sql, NULL, NULL, NULL) != SQLITE_OK) {
                    gestionaError(db);
                    return;
                }

                break;
            case 3:
                Aux->trab.edad = leeEntero("\tEdad: ",18,65);
                itoa(Aux->trab.edad,auxChar,10);
                strcat(sql16,auxChar);
                strcat(auxSql1,Aux->trab.codigo);
                strcat(sql16,auxSql1);
                if (sqlite3_exec(db, sql16, NULL, NULL, NULL) != SQLITE_OK) {
                    gestionaError(db);
                    getch();
                    return;
                }

                break;
            case 4:
                cout << "\tSistemas de Fondo de Pensiones: " << endl;
                Aux->trab.fondoPensiones = validaTabla("Seleccione: ",TablaFomdoPensiones,MAXTABLAFONDOPENSIONES);
                itoa(Aux->trab.fondoPensiones,auxChar,10);
                strcat(sql3,auxChar);
                strcat(auxSql1,Aux->trab.codigo);
                strcat(sql3,auxSql1);
                if (sqlite3_exec(db, sql3, NULL, NULL, NULL) != SQLITE_OK) {
                    gestionaError(db);
                    return;
                }
                break;
            case 5:
                Aux->trab.nroHijos = leeEntero("\tNumero de hijos: ", 0, 15);
                itoa(Aux->trab.nroHijos,auxChar,10);
                strcat(sql4,auxChar);
                strcat(auxSql1,Aux->trab.codigo);
                strcat(sql4,auxSql1);
                if (sqlite3_exec(db, sql4, NULL, NULL, NULL) != SQLITE_OK) {
                    gestionaError(db);
                    return;
                }
                break;
            case 6:
                cout << "\tEstado Civil: " << endl;
                Aux->trab.estadoCivil = validaTabla("Seleccione: ",TablaEstadoCivil, MAXTABLAESTADOCIVIL);
                itoa(Aux->trab.estadoCivil,auxChar,10);
                strcat(sql5,auxChar);
                strcat(auxSql1,Aux->trab.codigo);
                strcat(sql5,auxSql1);
                if (sqlite3_exec(db, sql5, NULL, NULL, NULL) != SQLITE_OK) {
                    gestionaError(db);
                    return;
                }
                break;
            case 7:
                cout << "\tGrados de Instruccion: " << endl;
                Aux->trab.gradoInstruccion = validaTabla("Seleccione: ", TablaGradoInstruccion, MAXTABLAGRADOINSTRUCCION);
                itoa(Aux->trab.gradoInstruccion,auxChar,10);
                strcat(sql6,auxChar);
                strcat(auxSql1,Aux->trab.codigo);
                strcat(sql6,auxSql1);
                if (sqlite3_exec(db, sql6, NULL, NULL, NULL) != SQLITE_OK) {
                    gestionaError(db);
                    return;
                }
                break;
            case 8:
                cout << "\tCalle: ";
                fflush(stdin);
                cin.getline(Aux->trab.direccion.calle, LIM);
                strcat(sql1,Aux->trab.direccion.calle);
                strcat(auxSql,Aux->trab.codigo);
                strcat(sql1,auxSql);
                if (sqlite3_exec(db, sql1, NULL, NULL, NULL) != SQLITE_OK) {
                    gestionaError(db);
                    return;
                }
                break;
            case 9:
                cout << "\tDistrito: ";
                fflush(stdin);
                cin.getline(Aux->trab.direccion.distrito, LIM);
                strcat(sql2,Aux->trab.direccion.distrito);
                strcat(auxSql,Aux->trab.codigo);
                strcat(sql2,auxSql);
                if (sqlite3_exec(db, sql2, NULL, NULL, NULL) != SQLITE_OK) {
                    gestionaError(db);
                    return;
                }
                break;
            case 10:
                cout << "\tProvincia: " << endl;
                Aux->trab.direccion.provincia = validaTabla("Seleccione: ", TablaProvincia, MAXTABLAPROVINCIA);
                fflush(stdin);
                itoa(Aux->trab.direccion.provincia,auxChar,10);
                strcat(sql7,auxChar);
                strcat(auxSql1,Aux->trab.codigo);
                strcat(sql7,auxSql1);
                if (sqlite3_exec(db, sql7, NULL, NULL, NULL) != SQLITE_OK) {
                    gestionaError(db);
                    return;
                }
                break;
            case 11:
                cout << "\tGrupos Ocupacionales: " << endl;
                Aux->trab.contrato.cargo.grupoOcupacional = validaTabla("Seleccione: ", TablaGrupoOcupacional, MAXTABLAGRUPOOCUPACIONAL);

                cout << "\tClase de cargo: " << endl;
                if (Aux->trab.contrato.cargo.grupoOcupacional == 1) {
                    Aux->trab.contrato.cargo.claseDeCargo = validaTabla("Seleccione: ", TablaDirectorSuperior, MAXTABLADIRECTORSUPERIOR);
                } else if (Aux->trab.contrato.cargo.grupoOcupacional == 2) {
                    Aux->trab.contrato.cargo.claseDeCargo = validaTabla("Seleccione: ", TablaEjecutivo, MAXTABLAEJECUTIVO);
                } else if (Aux->trab.contrato.cargo.grupoOcupacional == 3) {
                    Aux->trab.contrato.cargo.claseDeCargo = validaTabla("Seleccione: ", TablaEspecialista, MAXTABLAESPECIALISTA);
                } else {
                    Aux->trab.contrato.cargo.claseDeCargo = validaTabla("Seleccione: ", TablaApoyo, MAXTABLAAPOYO);
                }
                itoa(Aux->trab.contrato.cargo.grupoOcupacional,auxChar,10);
                strcat(sql8,auxChar);
                strcat(auxSql1,Aux->trab.codigo);
                strcat(sql8,auxSql1);
                if (sqlite3_exec(db, sql8, NULL, NULL, NULL) != SQLITE_OK) {
                    gestionaError(db);
                    return;
                }
                itoa(Aux->trab.contrato.cargo.claseDeCargo,auxChar,10);
                strcat(sql9,auxChar);
                strcat(auxSql1,Aux->trab.codigo);
                strcat(sql9,auxSql1);
                if (sqlite3_exec(db, sql9, NULL, NULL, NULL) != SQLITE_OK) {
                    gestionaError(db);
                    return;
                }
                break;
            case 12:
                cout << "\tHorario: " << endl;
                Aux->trab.contrato.horario = validaTabla("Seleccione: ", TablaHorario, MAXTABLAHORARIO);
                itoa(Aux->trab.contrato.horario,auxChar,10);
                strcat(sql10,auxChar);
                strcat(auxSql1,Aux->trab.codigo);
                strcat(sql10,auxSql1);
                if (sqlite3_exec(db, sql10, NULL, NULL, NULL) != SQLITE_OK) {
                    gestionaError(db);
                    return;
                }
                break;
            case 13:
                cout << "\tBancos: " << endl;
                Aux->trab.contrato.banco = validaTabla("Seleccione: ", TablaBanco, MAXTABLABANCO);
                itoa(Aux->trab.contrato.banco,auxChar,10);
                strcat(sql11,auxChar);
                strcat(auxSql1,Aux->trab.codigo);
                strcat(sql11,auxSql1);
                if (sqlite3_exec(db, sql11, NULL, NULL, NULL) != SQLITE_OK) {
                    gestionaError(db);
                    return;
                }
                break;
            case 14:
                cout << "\tTipos de trabajador: " << endl;
                Aux->trab.contrato.tipoTrabajador = validaTabla("Seleccione: ", TablaTipoTrabajador, MAXTABLATIPOTRABAJADOR);
                itoa( Aux->trab.contrato.tipoTrabajador,auxChar,10);
                strcat(sql12,auxChar);
                strcat(auxSql1,Aux->trab.codigo);
                strcat(sql12,auxSql1);
                if (sqlite3_exec(db, sql12, NULL, NULL, NULL) != SQLITE_OK) {
                    gestionaError(db);
                    return;
                }
                break;
            case 15:
                do {
                    cout << "\tFin de contrato: ";
                    leeFecha(Aux->trab.contrato.finContrato);
                } while (!(ComparaFechas(Aux->trab.contrato.finContrato,Aux->trab.contrato.inicioContrato) != -1 ||
                           ComparaFechas(Aux->trab.contrato.finContrato,Aux->trab.contrato.inicioContrato) == 0));

                itoa( Aux->trab.contrato.finContrato.Anio,auxChar,10);
                strcat(sql12,auxChar);
                strcat(auxSql1,Aux->trab.codigo);
                strcat(sql13,auxSql1);
                if (sqlite3_exec(db, sql13, NULL, NULL, NULL) != SQLITE_OK) {
                    gestionaError(db);
                    return;
                }
                itoa( Aux->trab.contrato.finContrato.Mes,auxChar,10);
                strcat(sql12,auxChar);
                strcat(auxSql1,Aux->trab.codigo);
                strcat(sql14,auxSql1);
                if (sqlite3_exec(db, sql14, NULL, NULL, NULL) != SQLITE_OK) {
                    gestionaError(db);
                    return;
                }
                itoa( Aux->trab.contrato.finContrato.Dia,auxChar,10);
                strcat(sql12,auxChar);
                strcat(auxSql1,Aux->trab.codigo);
                strcat(sql15,auxSql1);
                if (sqlite3_exec(db, sql15, NULL, NULL, NULL) != SQLITE_OK) {
                    gestionaError(db);
                    return;
                }
                break;
            }
            cout << "\n\tInformacion actualizada con exito";
        }
    }
    if (band == 0) {
        cout << "\n\n\tNo existe un trabajador con ese DNI";
    }

    getch();
}


void menuProcesos(ListaTrabajador &listaTrab, sqlite3 *db) {
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
        cout << "MENU PROCESOS";
        gotoxy(47,10);
        cout << "1. ACTUALIZAR INFORMACION";
        gotoxy(47,11);
        cout << "2. PLANILLAS";
        gotoxy(47,12);
        cout << "3. VACANTES";
        gotoxy(47,13);
        cout << "4. IR AL MENU PRINCIPAL";

        cout << endl << endl;
        opc = leeEntero("\t\t\t\t\t\tSeleccione: ", 1,4);

        switch (opc) {
        case 1:
            actualizarInformacion(listaTrab,db);
            break;
        case 2:
            menuPlanillas(listaTrab);
            break;
        case 3:
            menuVacantes(listaTrab);
            break;
        case 4:
            gotoxy(47,23);
            cout << "VOLVIENDO AL MENU PRINCIPAL";
            getch();
            break;
        }
    } while (!(opc == 4));

}
