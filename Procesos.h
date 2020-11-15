void PlanillaDatosPersonal(ListaTrabajador &listaTrab){
    int i=0;
    char LDNI[listaTrab.numTrabaj][LIM];
    char Lnombre[listaTrab.numTrabaj][LIM];
    char LCodigo[listaTrab.numTrabaj][LIM];
    int LFP[listaTrab.numTrabaj];
    int LnroH[listaTrab.numTrabaj];
    int Lgrado[listaTrab.numTrabaj];

    iniciaTabla(LDNI,listaTrab.numTrabaj);
    iniciaTabla(Lnombre,listaTrab.numTrabaj);
    iniciaTabla(LCodigo,listaTrab.numTrabaj);
    iniciaVE(LFP,listaTrab.numTrabaj);
    iniciaVE(LnroH,listaTrab.numTrabaj);
    iniciaVE(Lgrado,listaTrab.numTrabaj);

    cout << "\nPLANILLA DE DATOS DEL PERSONAL DE LA MUNICIPALIDAD DISTRITAL DE CHICLAYO" << endl << endl <<endl;

    cout <<"\tDNI \t\tNOMBRES \tF. PENSIONES \tNRO. HIJOS \tGR. INSTRUCCION \t\tCODIGO";

    for(NodoTrabajador *Aux = listaTrab.cab; Aux != NULL; Aux = Aux->sgte){
        strcpy(LDNI[i],Aux->trab.dni);
        strcpy(Lnombre[i],Aux->trab.nombre);
        strcpy(LCodigo[i],Aux->trab.codigo);
        LFP[i] = Aux->trab.fondoPensiones;
        LnroH[i] = Aux->trab.nroHijos;
        Lgrado[i] = Aux->trab.gradoInstruccion;

        cout << endl << "\t" << LDNI[i] << "\t" << Lnombre[i] << "\t\t" << TablaFomdoPensiones[LFP[i]-1] << "\t\t" << LnroH[i] << "\t\t" << TablaGradoInstruccion[Lgrado[i]-1] << "\t\t" << LCodigo[i] <<endl;
        i++;

    }
    getch();
}

void PlanillaModuloAsistencia(ListaTrabajador &listaTrab){
    int auxAnio, auxMes, i=0;
    auxAnio = leeEntero("\nAnio: ",ANIOACTUAL,2045);
    auxMes = validaTabla("\Mes: ",TablaMeses,MAXTABLAMES);

    char LCodigo[listaTrab.numTrabaj][LIM];
    char Lnombre[listaTrab.numTrabaj][LIM];
    int LAsistencias[listaTrab.numTrabaj];
    int LFaltas[listaTrab.numTrabaj];
    int LTardanzas[listaTrab.numTrabaj];
    int LJustificaciones[listaTrab.numTrabaj];

    iniciaTabla(LCodigo,listaTrab.numTrabaj);
    iniciaTabla(Lnombre,listaTrab.numTrabaj);
    iniciaVE(LAsistencias,listaTrab.numTrabaj);
    iniciaVE(LFaltas,listaTrab.numTrabaj);
    iniciaVE(LTardanzas,listaTrab.numTrabaj);
    iniciaVE(LJustificaciones,listaTrab.numTrabaj);

    cout << "\nPLANILLA DEL MODULO DE ASISTENCIAS TOTAL DEL PERSONAL DE LA MUNICIPALIDAD DISTRITAL DE CHICLAYO" << endl;
    cout << "\t\t" << TablaMeses[auxMes-1] << " - " << auxAnio << endl <<endl;
    cout <<"\tCODIGO \t\tNOMBRES \tASISTENCIAS \tFALTAS \tTARDANZAS \tJUSTIFICACIONES";

    for(NodoTrabajador *Aux = listaTrab.cab; Aux != NULL; Aux = Aux->sgte){
        strcpy(LCodigo[i],Aux->trab.codigo);
        strcpy(Lnombre[i],Aux->trab.nombre);

        for(int j = 0; j < MAXTABLAMES ; j++){
            if(Aux->trab.pagos.listaAsistencia.datos[j].anio==auxAnio && Aux->trab.pagos.listaAsistencia.datos[j].mes==auxMes && Aux->trab.pagos.listaAsistencia.num!=0){
                LAsistencias[i] += Aux->trab.pagos.listaAsistencia.datos[j].asistencia;
                LFaltas[i] += Aux->trab.pagos.listaAsistencia.datos[j].falta;
                LTardanzas[i] += Aux->trab.pagos.listaAsistencia.datos[j].tardanza;
                LJustificaciones[i] += Aux->trab.pagos.listaAsistencia.datos[j].justificacion;
            }
        }

        cout << endl << "\t" << LCodigo[i] << "\t" << Lnombre[i] << "\t\t" << LAsistencias[i] << "\t\t" << LFaltas[i] << "\t\t" << LTardanzas[i] << "\t\t" << LJustificaciones[i] <<endl;
        i++;
    }

    getch();
}

void PlanillaInformacionInterbancaria(ListaTrabajador &listaTrab){
    char LDNI[listaTrab.numTrabaj][LIM];
    char Lnombre[listaTrab.numTrabaj][LIM];
    int i=0, Lbanco[listaTrab.numTrabaj];

    iniciaTabla(LDNI,listaTrab.numTrabaj);
    iniciaTabla(Lnombre,listaTrab.numTrabaj);
    iniciaVE(Lbanco,listaTrab.numTrabaj);

    cout << "\nPLANILLA DE INFORMACION INTERBANCARIA DEL PERSONAL DE LA MUNICIPALIDAD DISTRITAL DE CHICLAYO" << endl;
    cout <<"\tDNI \t\tNOMBRES \tBANCO ";

    for(NodoTrabajador *Aux = listaTrab.cab; Aux != NULL; Aux = Aux->sgte){
        strcpy(LDNI[i],Aux->trab.dni);
        strcpy(Lnombre[i],Aux->trab.nombre);
        Lbanco[i] = Aux->trab.contrato.banco;

        cout << endl << "\t" << LDNI[i] << "\t" << Lnombre[i] << "\t\t" << TablaBanco[Lbanco[i]-1] <<endl;
        i++;
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

                break;
            case 5:
                gotoxy(27,23);
                cout << "VOLVIENDO AL MENU PROCESOS";
                getch();
                break;
        }
    } while (!(opc == 5));
}

void menuVacantes(){
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
        cout << "2. VACANTES OCUPADAS";
        gotoxy(23,11);
        cout << "3. VACANTES DESOCUPADAS";
        gotoxy(23,12);
        cout << "4. IR AL MENU PROCESOS";
        cout << "\n\n\n";
        opc = leeEntero("\t\t\tSeleccione: ", 1,5);

        switch (opc) {
            case 1:

                break;
            case 2:

                break;
            case 3:

                break;
            case 4:
                gotoxy(27,23);
                cout << "VOLVIENDO AL MENU PROCESOS";
                getch();
                break;
        }
    } while (!(opc == 4));

}

void menuModificarSueldo(){
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
        cout << "MENU MODIFICAR SUELDO";
        gotoxy(29,9);
        cout << "1. REGISTRAR ADELANTO";
        gotoxy(29,10);
        cout << "2. REGISTRAR DESCUENTO";
        gotoxy(29,11);
        cout << "3. REGISTRAR BONIFICACION";
        gotoxy(29,12);
        cout << "4. IR AL MENU PROCESOS";
        cout << "\n\n\n";
        opc = leeEntero("\t\t\tSeleccione: ", 1,5);

        switch (opc) {
            case 1:

                break;
            case 2:

                break;
            case 3:

                break;
            case 4:
                gotoxy(27,23);
                cout << "VOLVIENDO AL MENU PROCESOS";
                getch();
                break;
        }
    } while (!(opc == 4));
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
        cout << "4. ADELANTO-DESCUENTO-BONIFICACION";
        gotoxy(27,13);
        cout << "5. IR AL MENU PRINCIPAL";
        cout << "\n\n\n";
        opc = leeEntero("\t\t\tSeleccione: ", 1,5);

        switch (opc) {
            case 1:

                break;
            case 2:
                menuPlanillas(listaTrab);
                break;
            case 3:
                menuVacantes();
                break;
            case 4:
                menuModificarSueldo();
                break;
            case 5:
                gotoxy(27,23);
                cout << "VOLVIENDO AL MENU PRINCIPAL";
                getch();
                break;
        }
    } while (!(opc == 5));

}
