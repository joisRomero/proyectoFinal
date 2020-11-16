//----------------------------------------------  PLANILLAS  --------------------------------------/

void PlanillaDatosPersonal(ListaTrabajador &listaTrab) {
    interfazmenu(":: PLANILLA DE DATOS DEL PERSONAL DE LA MDCH ::");
    cout << endl << endl;

    cout <<"\tDNI \t\tNOMBRES \tF. PENSIONES \tNRO. HIJOS \tGR. INSTRUCCION \t\tCODIGO";

    for(NodoTrabajador *Aux = listaTrab.cab; Aux != NULL; Aux = Aux->sgte) {
        cout << endl << "\t" << Aux->trab.dni << "\t" << Aux->trab.nombre << "\t\t" << TablaFomdoPensiones[Aux->trab.fondoPensiones-1]
             << "\t\t" << Aux->trab.nroHijos << "\t\t" << TablaGradoInstruccion[Aux->trab.gradoInstruccion-1] << "\t\t" << Aux->trab.codigo <<endl;
    }
    getch();
}

void PlanillaModuloAsistencia(ListaTrabajador &listaTrab) {
    int auxAnio;
    auxAnio = leeEntero("\nAnio: ",ANIOACTUAL,2045);
    int AcumAsistencias, AcumFaltas, AcumTardanzas, AcumJustificaciones;
    system("cls");
    interfazmenu(":: PLANILLA DEL MODULO ASISTENCIAS DE LA MDCH ::");
    cout << endl << endl;
    cout << "\t\t\t\t\t\t\tAnio: " << auxAnio << endl <<endl;
    cout <<"\tCODIGO \t\tNOMBRES \tASISTENCIAS \tFALTAS \t\tTARDANZAS \tJUSTIFICACIONES";

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
        cout << endl << "\t" << Aux->trab.codigo << "\t" << Aux->trab.nombre << "\t\t" << AcumAsistencias << "\t\t" << AcumFaltas
             << "\t\t" << AcumTardanzas << "\t\t" << AcumJustificaciones <<endl;
    }
    getch();
}

void PlanillaInformacionInterbancaria(ListaTrabajador &listaTrab) {
    interfazmenu(":: PLANILLA INFORMACION INTERBANCARIA DE LA MDCH ::");
    cout << endl << endl;
    cout <<"\t\t\t\t\tDNI \t\tNOMBRES \t\tBANCO ";

    for(NodoTrabajador *Aux = listaTrab.cab; Aux != NULL; Aux = Aux->sgte) {
        cout << endl << "\t\t\t\t\t" << Aux->trab.dni << "\t" << Aux->trab.nombre << "\t\t\t" << TablaBanco[Aux->trab.contrato.banco-1] <<endl;
    }
    getch();
}

void PlanillaPagos(ListaTrabajador &listaTrab) {
    int auxAnio;
    auxAnio = leeEntero("\nAnio: ",ANIOACTUAL,2045);
    system("cls");
    int AcumAsignacion, AcumDcto, AcumBoni, AcumSueldoNeto;
    interfazmenu("::  PLANILLA DEL TOTAL DE PAGOS DE LA MDCH  ::");
    cout << endl << endl;
    cout << "\t\t\t\t\t\t\tAnio: " << auxAnio << endl <<endl;
    cout <<"\tCODIGO \t\tNOMBRES \tASIGNACION FAMILIAR \tDESCUENTO \tBONIFICACION \tSUELDO NETO";
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
        cout << endl << "\t" << Aux->trab.codigo << "\t" << Aux->trab.nombre << "\t\t" << AcumAsignacion<< "\t\t" << AcumDcto
             << "\t\t" << AcumBoni << "\t\t" << AcumSueldoNeto <<endl;
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
        cout << "\t\t\t-" << TablaTotalCargos[i] << ": " << AcumClaseDeCargo[i] << endl << endl;
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

void actualizarInformacion(ListaTrabajador &listaTrab) {
    bool band = 0;
    char auxDni[MAXDNI];

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
                break;
            case 2:
                cout << "\tNombre Completo: ";
                fflush(stdin);
                cin.getline(Aux->trab.nombre,LIM);
                break;
            case 3:
                cout << "\tSistemas de Fondo de Pensiones: " << endl;
                Aux->trab.fondoPensiones = validaTabla("Seleccione: ",TablaFomdoPensiones,MAXTABLAFONDOPENSIONES);
                break;
            case 4:
                Aux->trab.nroHijos = leeEntero("\tNumero de hijos: ", 0, 15);
                break;
            case 5:
                cout << "\tEstado Civil: " << endl;
                Aux->trab.estadoCivil = validaTabla("Seleccione: ",TablaEstadoCivil, MAXTABLAESTADOCIVIL);
                break;
            case 6:
                cout << "\tGrados de Instruccion: " << endl;
                Aux->trab.gradoInstruccion = validaTabla("Seleccione: ", TablaGradoInstruccion, MAXTABLAGRADOINSTRUCCION);
                break;
            case 7:
                cout << "\tCalle: ";
                fflush(stdin);
                cin.getline(Aux->trab.direccion.calle, LIM);
                break;
            case 8:
                cout << "\tDistrito: ";
                fflush(stdin);
                cin.getline(Aux->trab.direccion.distrito, LIM);
                break;
            case 9:
                cout << "\tProvincia: " << endl;
                Aux->trab.direccion.provincia = validaTabla("Seleccione: ", TablaProvincia, MAXTABLAPROVINCIA);
                fflush(stdin);
                break;
            case 10:
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
                break;
            case 11:
                cout << "\tHorario: " << endl;
                Aux->trab.contrato.horario = validaTabla("Seleccione: ", TablaHorario, MAXTABLAHORARIO);
                break;
            case 12:
                cout << "\tBancos: " << endl;
                Aux->trab.contrato.banco = validaTabla("Seleccione: ", TablaBanco, MAXTABLABANCO);
                break;
            case 13:
                cout << "\tTipos de trabajador: " << endl;
                Aux->trab.contrato.tipoTrabajador = validaTabla("Seleccione: ", TablaTipoTrabajador, MAXTABLATIPOTRABAJADOR);

                break;
            case 14:
                do {
                    cout << "\tFin de contrato: ";
                    leeFecha(Aux->trab.contrato.finContrato);
                } while (!(ComparaFechas(Aux->trab.contrato.finContrato,Aux->trab.contrato.inicioContrato) != -1 ||
                           ComparaFechas(Aux->trab.contrato.finContrato,Aux->trab.contrato.inicioContrato) == 0));

                break;
            }
            cout << "\nInformacion actualizada con exito";
        }
    }
    if (band == 0) {
        cout << "\n\n\tNo existe un trabajador con ese DNI";
    }

    getch();
}


void menuProcesos(ListaTrabajador &listaTrab) {
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
            actualizarInformacion(listaTrab);
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
