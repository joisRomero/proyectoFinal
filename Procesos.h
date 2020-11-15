void PlanillaDatosPersonal(ListaTrabajador &listaTrab){
    interfazmenu("PLANILLA DE DATOS DEL PERSONAL DE LA MUNICIPALIDAD DISTRITAL DE CHICLAYO");
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
    int LAsistencias, LFaltas, LTardanzas, LJustificaciones;
    system("cls");
    interfazmenu("PLANILLA DEL MODULO DE ASISTENCIAS TOTAL DEL PERSONAL DE LA MUNICIPALIDAD DISTRITAL DE CHICLAYO");
    cout << endl << endl;
    cout << "\t\t\tAnio: " << auxAnio << endl <<endl;
    cout <<"\tCODIGO \t\tNOMBRES \tASISTENCIAS \tFALTAS \tTARDANZAS \tJUSTIFICACIONES";

    for(NodoTrabajador *Aux = listaTrab.cab; Aux != NULL; Aux = Aux->sgte){
        LAsistencias = 0;
        LFaltas = 0;
        LTardanzas = 0;
        LJustificaciones = 0;
        for(int i = 0; i < Aux->trab.pagos.listaAsistencia.num ; i++){
                if(Aux->trab.pagos.listaAsistencia.datos[i].anio==auxAnio && Aux->trab.pagos.listaAsistencia.num!=0){
                LAsistencias += Aux->trab.pagos.listaAsistencia.datos[i].asistencia;
                LFaltas += Aux->trab.pagos.listaAsistencia.datos[i].falta;
                LTardanzas += Aux->trab.pagos.listaAsistencia.datos[i].tardanza;
                LJustificaciones += Aux->trab.pagos.listaAsistencia.datos[i].justificacion;
            }
        }
        cout << endl << "\t" << Aux->trab.codigo << "\t" << Aux->trab.nombre << "\t\t" << LAsistencias << "\t\t" << LFaltas
        << "\t\t" << LTardanzas << "\t\t" << LJustificaciones <<endl;
    }
    getch();
}

void PlanillaInformacionInterbancaria(ListaTrabajador &listaTrab){
    interfazmenu("PLANILLA DE INFORMACION INTERBANCARIA DEL PERSONAL DE LA MUNICIPALIDAD DISTRITAL DE CHICLAYO");
    cout << endl << endl;
    cout <<"\tDNI \t\tNOMBRES \tBANCO ";

    for(NodoTrabajador *Aux = listaTrab.cab; Aux != NULL; Aux = Aux->sgte){
        cout << endl << "\t" << Aux->trab.dni << "\t" << Aux->trab.nombre << "\t\t" << TablaBanco[Aux->trab.contrato.banco-1] <<endl;
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
