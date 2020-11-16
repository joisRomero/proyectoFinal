//----------------------------------------------  PLANILLAS  --------------------------------------/

void PlanillaDatosPersonal(ListaTrabajador &listaTrab){
    interfazmenu(":: PLANILLA DE DATOS DEL PERSONAL DE LA MDCH ::");
    cout << endl << endl;

    cout <<"\tDNI \t\tNOMBRES \tF. PENSIONES \tNRO. HIJOS \tGR. INSTRUCCION \t\tCODIGO";

    for(NodoTrabajador *Aux = listaTrab.cab; Aux != NULL; Aux = Aux->sgte){
        cout << endl << "\t" << Aux->trab.dni << "\t" << Aux->trab.nombre << "\t\t" << TablaFomdoPensiones[Aux->trab.fondoPensiones-1]
        << "\t\t" << Aux->trab.nroHijos << "\t\t" << TablaGradoInstruccion[Aux->trab.gradoInstruccion-1] << "\t\t" << Aux->trab.codigo <<endl;
    }
    getch();
}

void PlanillaModuloAsistencia(ListaTrabajador &listaTrab){
    int auxAnio;
    auxAnio = leeEntero("\nAnio: ",ANIOACTUAL,2045);
    int AcumAsistencias, AcumFaltas, AcumTardanzas, AcumJustificaciones;
    system("cls");
    interfazmenu(":: PLANILLA DEL MODULO DE ASISTENCIAS TOTAL DEL PERSONAL DE LA MDCH ::");
    cout << endl << endl;
    cout << "\t\t\tAnio: " << auxAnio << endl <<endl;
    cout <<"\tCODIGO \t\tNOMBRES \tASISTENCIAS \tFALTAS \tTARDANZAS \tJUSTIFICACIONES";

    for(NodoTrabajador *Aux = listaTrab.cab; Aux != NULL; Aux = Aux->sgte){
        AcumAsistencias = 0;
        AcumFaltas = 0;
        AcumTardanzas = 0;
        AcumJustificaciones = 0;
        for(int i = 0; i < Aux->trab.pagos.listaAsistencia.num ; i++){
                if(Aux->trab.pagos.listaAsistencia.datos[i].anio==auxAnio && Aux->trab.pagos.listaAsistencia.num!=0){
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

void PlanillaInformacionInterbancaria(ListaTrabajador &listaTrab){
    interfazmenu("PLANILLA DE INFORMACION INTERBANCARIA DEL PERSONAL DE LA MDCH");
    cout << endl << endl;
    cout <<"\tDNI \t\tNOMBRES \tBANCO ";

    for(NodoTrabajador *Aux = listaTrab.cab; Aux != NULL; Aux = Aux->sgte){
        cout << endl << "\t" << Aux->trab.dni << "\t" << Aux->trab.nombre << "\t\t" << TablaBanco[Aux->trab.contrato.banco-1] <<endl;
    }
    getch();
}

void PlanillaPagos(ListaTrabajador &listaTrab){
    int auxAnio;
    auxAnio = leeEntero("\nAnio: ",ANIOACTUAL,2045);
    system("cls");
    int AcumAsignacion, AcumDcto, AcumBoni, AcumSueldoNeto;
    interfazmenu(":: PLANILLA DE PAGOS TOTAL DEL PERSONAL DE LA MDCH ::");
    cout << endl << endl;
    cout << "\t\t\tAnio: " << auxAnio << endl <<endl;
    cout <<"\tCODIGO \t\tNOMBRES \tASIGNACION FAMILIAR \tDESCUENTO \tBONIFICACION \tSUELDO NETO";
    for(NodoTrabajador *Aux = listaTrab.cab; Aux != NULL; Aux = Aux->sgte){
        AcumAsignacion = 0;
        AcumDcto = 0;
        AcumBoni = 0;
        AcumSueldoNeto = 0;
        for(int i = 0; i < Aux->trab.pagos.listaSueldo.num; i++){
            if(Aux->trab.pagos.listaSueldo.datos[i].anio==auxAnio && Aux->trab.pagos.listaSueldo.num!=0){
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

void menuPlanillas(ListaTrabajador &listaTrab){
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
        cout << "MENU PLANILLAS";
        gotoxy(30,9);
        cout << "1. DATOS DEL PERSONAL";
        gotoxy(30,10);
        cout << "2. MODULO ASISTENCIA";
        gotoxy(30,11);
        cout << "3. INFORMACION INTERBANCARIA";
        gotoxy(30,12);
        cout << "4. PAGO DE PERSONAL";
        gotoxy(30,13);
        cout << "5. IR AL MENU PROCESOS";
        cout << "\n\n\n";
        opc = leeEntero("\t\t\tSeleccione: ", 1,5);

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
                gotoxy(27,23);
                cout << "VOLVIENDO AL MENU PROCESOS";
                getch();
                break;
        }
    } while (!(opc == 5));
}

//----------------------------------------------------------- VACANTES ------------------------------------------//

void vacantesDisponiblesDentroMes(ListaTrabajador &listaTrab){
    int i=0;
    system("cls");
    interfazmenu(":: VACANTES DISPONIBLES DENTRO DE UN MES ::");
    cout << endl << endl;
    for(NodoTrabajador *Aux = listaTrab.cab; Aux != NULL; Aux = Aux->sgte){
        if(Aux->trab.contrato.finContrato.Anio == ANIOACTUAL &&  Aux->trab.contrato.finContrato.Mes == MESACTUAL +2){
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

void numeroDeVacantesPorCargo(ListaTrabajador &listaTrab){
    int AcumClaseDeCargo[MAXCLASEDECARGO], y=0;
    iniciaVE(AcumClaseDeCargo,MAXCLASEDECARGO);
    system("cls");
    interfazmenu(":: CARGO / VACANTES ::");
    cout << endl << endl;
    for(NodoTrabajador *Aux = listaTrab.cab ; Aux != NULL; Aux = Aux->sgte){
        if(Aux->trab.contrato.cargo.grupoOcupacional == 1){
            AcumClaseDeCargo[Aux->trab.contrato.cargo.claseDeCargo]++;
        }else if(Aux->trab.contrato.cargo.grupoOcupacional == 2){
            AcumClaseDeCargo[Aux->trab.contrato.cargo.claseDeCargo+(2)-1]++;
        }else if(Aux->trab.contrato.cargo.grupoOcupacional == 3){
            AcumClaseDeCargo[Aux->trab.contrato.cargo.claseDeCargo+(2+3)-1]++;
        }else if(Aux->trab.contrato.cargo.grupoOcupacional == 4){
            AcumClaseDeCargo[Aux->trab.contrato.cargo.claseDeCargo+(2+3+10)-1]++;
        }
    }

    for(int i = 0; i < MAXCLASEDECARGO; i++){
        cout << "\t-" << TablaTotalCargos[i] << ": " << AcumClaseDeCargo[i];
    }
    getch();
}

void menuVacantes(ListaTrabajador &listaTrab){
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
        cout << "MENU VACANTES";
        gotoxy(23,9);
        cout << "1. VACANTES DISPONIBLES DENTRO DE UN MES";
        gotoxy(23,10);
        cout << "2. NUMERO DE VACANTES POR CARGO";
        gotoxy(23,12);
        cout << "3. IR AL MENU PROCESOS";
        cout << "\n\n\n";
        opc = leeEntero("\t\t\tSeleccione: ", 1,3);

        switch (opc) {
            case 1:
                vacantesDisponiblesDentroMes(listaTrab);
                break;
            case 2:
                numeroDeVacantesPorCargo(listaTrab);
                break;
            case 3:
                gotoxy(27,23);
                cout << "VOLVIENDO AL MENU PROCESOS";
                getch();
                break;
        }
    } while (!(opc == 3));

}

void menuProcesos(ListaTrabajador &listaTrab){
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
        cout << "MENU PROCESOS";
        gotoxy(27,9);
        cout << "1. ACTUALIZAR INFORMACION";
        gotoxy(27,10);
        cout << "2. PLANILLAS";
        gotoxy(27,11);
        cout << "3. VACANTES";
        gotoxy(27,12);
        cout << "4. IR AL MENU PRINCIPAL";
        cout << "\n\n\n";
        opc = leeEntero("\t\t\tSeleccione: ", 1,4);

        switch (opc) {
            case 1:

                break;
            case 2:
                menuPlanillas(listaTrab);
                break;
            case 3:
                menuVacantes(listaTrab);
                break;
            case 4:
                gotoxy(27,23);
                cout << "VOLVIENDO AL MENU PRINCIPAL";
                getch();
                break;
        }
    } while (!(opc == 4));

}
