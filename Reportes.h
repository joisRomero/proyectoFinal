/*
    Reporte de J. David Gonzales
*/
void reporteRodo(ListaTrabajador &listaTrab){
    char saludo[LIM], despido[LIM];
    char auxCodigo[MAXCODIGO];
    int opcion1 = 0, opcionClaseCargo = 0, opcionTrabajador = 0, band = 0, bandSalida = 0;
    ListaTrabajador ListaFiltradaFINAL;
    iniciaListaTrabajador(ListaFiltradaFINAL);
    NodoTrabajador *nodoListaFiltradaFinal = ListaFiltradaFINAL.cab;

    Trabajador auxTrabajador;
    iniciaTrabajador(auxTrabajador);

    interfazmenu(":: SISTEMA DE ASISTENCIA Y APOYO COMUNITARIO ::");
    cout << endl << endl;

    leeTextoComoNumero("\n\t\t\t\tIngrese su codigo",auxCodigo,MAXCODIGO);

    for(NodoTrabajador *Aux = listaTrab.cab; Aux != NULL; Aux = Aux -> sgte){
        if(strcmpi(auxCodigo,Aux->trab.codigo)==0){
            band = 1;
            //saludo
            if(Aux->trab.sexo==1){
                strcat(saludo,"Bienvenido Sr. ");
                strcat(saludo,Aux->trab.nombre);
                strcat(despido,"El trabajador ");
                strcat(despido,Aux->trab.nombre);
            }else if(Aux->trab.estadoCivil==1){
                strcat(saludo,"Bienvenida Srta. ");
                strcat(saludo,Aux->trab.nombre);
                strcat(despido,"La trabajadora ");
                strcat(despido,Aux->trab.nombre);
            }else{
                strcat(saludo,"Bienvenida Sra. ");
                strcat(saludo,Aux->trab.nombre);
                strcat(despido,"La trabajadora ");
                strcat(despido,Aux->trab.nombre);
            }

            do{
                system("cls");
                interfazmenu(":: SISTEMA DE ASISTENCIA Y APOYO COMUNITARIO ::");
                cout << endl << endl;
                PintarCuadrado(38,10,88,12);
                gotoxy(43,11);
                cout << saludo << endl << endl << endl;

                gotoxy(45,14);
                cout << "De que grupo necesita asistencia? ";
                gotoxy(45,15);
                cout << "1. Especialista";
                gotoxy(45,16);
                cout << "2. Apoyo";
                opcion1 = leeEntero("\n\t\t\t\t\tSeleccione: ",1,2);

                switch (opcion1) {
                        case 1:{
                            system("cls");
                            interfazmenu(":: SISTEMA DE ASISTENCIA Y APOYO COMUNITARIO ::");
                            cout << endl << endl;
                            PintarCuadrado(38,10,88,12);
                            gotoxy(43,11);
                            cout << saludo << endl << endl << endl;

                            do{
                                system("cls");
                                interfazmenu(":: SISTEMA DE ASISTENCIA Y APOYO COMUNITARIO ::");
                                cout << endl << endl;
                                PintarCuadrado(38,10,88,12);
                                gotoxy(43,11);
                                cout << saludo << endl << endl << endl;
                                gotoxy(45,14);
                                cout << "De que clase de cargo necesita asistencia? " << endl;
                                for(int i = 0; i < MAXTABLAESPECIALISTA; i++){
                                    cout << "\t\t\t\t" << i+1 << ". " << TablaEspecialista[i] << endl;
                                }
                                opcionClaseCargo = leeEntero("\n\t\t\t\tSeleccione: ",1,MAXTABLAESPECIALISTA);

                                system("cls");
                                interfazmenu(":: SISTEMA DE ASISTENCIA Y APOYO COMUNITARIO ::");
                                cout << endl << endl;
                                PintarCuadrado(38,10,88,12);
                                gotoxy(43,11);
                                cout << saludo << endl << endl << endl;
                                gotoxy(43,14);
                                cout << "Lista de Trabajadores del cargo " << TablaEspecialista[opcionClaseCargo-1];
                                cout << endl << endl;
                                gotoxy(15,16);
                                cout << "Codigo";
                                gotoxy(40,16);
                                cout << "Nombre";
                                gotoxy(80,16);
                                cout << "Estudios";

                                ListaTrabajador ListaFiltrada;
                                iniciaListaTrabajador(ListaFiltrada);
                                NodoTrabajador *nodoListaFiltrada = ListaFiltrada.cab;
                                for(NodoTrabajador *AuxParaCargo = listaTrab.cab; AuxParaCargo != NULL; AuxParaCargo = AuxParaCargo->sgte){
                                    if(AuxParaCargo->trab.contrato.cargo.grupoOcupacional == 3 && AuxParaCargo->trab.contrato.cargo.claseDeCargo==opcionClaseCargo && strcmpi(Aux->trab.codigo,AuxParaCargo->trab.codigo)!=0){
                                        insertaListaTrabajador(ListaFiltrada,AuxParaCargo->trab,nodoListaFiltrada);
                                    }
                                }
                                int j = 0;
                                for(NodoTrabajador *AuxParaCargo = ListaFiltrada.cab; AuxParaCargo != NULL; AuxParaCargo = AuxParaCargo->sgte){
                                    gotoxy(12,j+17);
                                    cout << j+1 << ". " << AuxParaCargo->trab.codigo;
                                    gotoxy(40,j+17);
                                    cout<< AuxParaCargo->trab.nombre;
                                    gotoxy(80,j+17);
                                    cout << TablaGradoInstruccion[AuxParaCargo->trab.gradoInstruccion-1];
                                    j++;
                                }
                                cout << endl << endl;
                                int arregloOpciones[j];
                                iniciaVE(arregloOpciones,j);
                                do{
                                    opcionTrabajador = leeEntero("\n\tElija un trabajador (caso contrario, presione ENTER): ",0,j);
                                    if(opcionTrabajador != 0){
                                        if(arregloOpciones[opcionTrabajador-1]==0){
                                            j = 1; //iterar
                                            for(NodoTrabajador *AuxParaCargo = ListaFiltrada.cab; AuxParaCargo != NULL; AuxParaCargo = AuxParaCargo->sgte){
                                                if(opcionTrabajador == j){
                                                    insertaListaTrabajador(ListaFiltradaFINAL,AuxParaCargo->trab,nodoListaFiltradaFinal);
                                                }
                                                j++;
                                            }
                                            arregloOpciones[opcionTrabajador-1]=1;
                                            cout << endl;
                                        }else{
                                            cout << "\n\tYa se selecciono este trabajador" << endl;
                                        }
                                    }

                                }while(continuar("\tDesea seleccionar otro trabajador?(S/N): ") == 'S');
                            }while(continuar("\tDesea seleccionar otra clase de cargo?(S/N): ")=='S');

                            break;
                            }
                        case 2:{
                        system("cls");
                            interfazmenu(":: SISTEMA DE ASISTENCIA Y APOYO COMUNITARIO ::");
                            cout << endl << endl;
                            PintarCuadrado(38,10,88,12);
                            gotoxy(43,11);
                            cout << saludo << endl << endl << endl;
                            do{
                                system("cls");
                                interfazmenu(":: SISTEMA DE ASISTENCIA Y APOYO COMUNITARIO ::");
                                cout << endl << endl;
                                PintarCuadrado(38,10,88,12);
                                gotoxy(43,11);
                                cout << saludo << endl << endl << endl;
                                gotoxy(45,14);
                                cout << "De que clase de cargo necesita asistencia? " << endl;
                                for(int i = 0; i < MAXTABLAAPOYO; i++){
                                    cout << "\t\t\t\t" << i+1 << ". " << TablaApoyo[i] << endl;
                                }
                                opcionClaseCargo = leeEntero("\n\t\t\t\tSeleccione: ",1,MAXTABLAAPOYO);

                                system("cls");
                                interfazmenu(":: SISTEMA DE ASISTENCIA Y APOYO COMUNITARIO ::");
                                cout << endl << endl;
                                PintarCuadrado(38,10,88,12);
                                gotoxy(43,11);
                                cout << saludo << endl << endl << endl;
                                gotoxy(43,14);
                                cout << "Lista de Trabajadores del cargo " << TablaApoyo[opcionClaseCargo-1];
                                cout << endl << endl;
                                gotoxy(15,16);
                                cout << "Codigo";
                                gotoxy(40,16);
                                cout << "Nombre";
                                gotoxy(80,16);
                                cout << "Estudios";

                                ListaTrabajador ListaFiltrada2;
                                iniciaListaTrabajador(ListaFiltrada2);
                                NodoTrabajador *nodoListaFiltrada2 = ListaFiltrada2.cab;

                                for(NodoTrabajador *AuxParaCargo = listaTrab.cab; AuxParaCargo != NULL; AuxParaCargo = AuxParaCargo->sgte){
                                    if(AuxParaCargo->trab.contrato.cargo.grupoOcupacional == 4 && AuxParaCargo->trab.contrato.cargo.claseDeCargo==opcionClaseCargo && strcmpi(Aux->trab.codigo,AuxParaCargo->trab.codigo)!=0){
                                        insertaListaTrabajador(ListaFiltrada2,AuxParaCargo->trab,nodoListaFiltrada2);
                                    }
                                }
                                int j = 0;
                                for(NodoTrabajador *AuxParaCargo = ListaFiltrada2.cab; AuxParaCargo != NULL; AuxParaCargo = AuxParaCargo->sgte){
                                    gotoxy(12,j+17);
                                    cout << j+1 << ". " << AuxParaCargo->trab.codigo;
                                    gotoxy(40,j+17);
                                    cout<< AuxParaCargo->trab.nombre;
                                    gotoxy(80,j+17);
                                    cout << TablaGradoInstruccion[AuxParaCargo->trab.gradoInstruccion-1];

                                    j++;
                                }
                                cout << endl << endl;
                                int arregloOpciones[j];
                                iniciaVE(arregloOpciones,j);
                                do{
                                    opcionTrabajador = leeEntero("\n\tElija un trabajador (si no elige, ingrese 0): ",0,j);
                                    if(arregloOpciones[opcionTrabajador-1]==0){
                                        j = 1; //iterar
                                        for(NodoTrabajador *AuxParaCargo = ListaFiltrada2.cab; AuxParaCargo != NULL; AuxParaCargo = AuxParaCargo->sgte){
                                            if(opcionTrabajador == j){
                                                insertaListaTrabajador(ListaFiltradaFINAL,AuxParaCargo->trab,nodoListaFiltradaFinal);
                                            }
                                            j++;
                                        }
                                    arregloOpciones[opcionTrabajador-1]=1;
                                    cout << endl;
                                    }else{
                                        cout << "\n\tYa se selecciono este trabajador" << endl;
                                    }
                                }while(continuar("\tDesea seleccionar otro trabajador?(S/N): ") == 'S');
                            }while(continuar("\tDesea seleccionar otra clase de cargo?(S/N): ")=='S');

                            break;
                        }
                   }

           }while(continuar("\tDesea seleccionar otro grupo? (S/N): ") == 'S');
        }
    }

    if(band == 0){
        cout << "\tNo lo encontro";
    }else if(ListaFiltradaFINAL.numTrabaj!=0){
        //Ordeno por nombre

        for(NodoTrabajador *Aux = ListaFiltradaFINAL.cab; Aux->sgte != NULL; Aux = Aux -> sgte){
            for(NodoTrabajador *Aux2 = Aux->sgte; Aux2 != NULL; Aux2 = Aux2->sgte){
                if(strcmpi(Aux->trab.nombre,Aux2->trab.nombre)>0){
                    auxTrabajador = Aux->trab;
                    Aux->trab = Aux2->trab;
                    Aux2->trab = auxTrabajador;
                }
            }
        }

        for(NodoTrabajador *Aux = listaTrab.cab; Aux != NULL; Aux = Aux -> sgte){
            if(strcmpi(auxCodigo, Aux->trab.codigo)==0){
                cout << endl << endl << "\t";
                cout << despido << " solicito la asistencia de: " << endl;
            }
        }

        for(NodoTrabajador *Aux = ListaFiltradaFINAL.cab; Aux != NULL; Aux = Aux -> sgte){
            cout << "\n\t\t- " << Aux->trab.dni << " :: " << Aux->trab.nombre;
        }
    }else{
        cout << "\n\n\t\tNo se ha seleccionado ningun trabajador";
    }

    fflush(stdin);
    getch();
}

/*
    Reporte de Romero Olivera Jose Luis
*/
void reporteJoseRomero(ListaTrabajador &listaTrab) {
    int cantPersonas;
    float maximo = (listaTrab.numTrabaj/2);
    system("cls");
    interfazmenu("          :: SISTEMA DE CALIFICACION ::");
    cout << endl << endl;

    cantPersonas = leeEntero("\tIngrese numero de trabjadores a mostrar: ", 2, maximo);

    float puntajeLista[listaTrab.numTrabaj];
    float puntajeLista2[listaTrab.numTrabaj];

    float puntajeBuenos[cantPersonas], puntajeMalos[cantPersonas];

    float listaPuntajeOr1[listaTrab.numTrabaj], auxNum;

    int acumAsistencias, acumFaltas, acumJusti, acumTardan, j = 0;
    float acumDescuentos = 0.0, acumBonificaciones = 0.0;
    float menor, mayor;

    iniciaVR(puntajeLista,listaTrab.numTrabaj);
    iniciaVR(puntajeLista2,listaTrab.numTrabaj);
    iniciaVR(listaPuntajeOr1,listaTrab.numTrabaj);

    Trabajador trabajadoresBuen[cantPersonas];
    Trabajador trabajadoresRegu[cantPersonas];
    Trabajador auxTrabajador;


    for (NodoTrabajador *Aux = listaTrab.cab; Aux != NULL; Aux = Aux->sgte) {
        acumAsistencias = 0;
        acumFaltas = 0;
        acumJusti = 0;
        acumTardan = 0;
        for (int i = 0; i < Aux->trab.pagos.listaAsistencia.num; i++) {
            acumAsistencias += Aux->trab.pagos.listaAsistencia.datos[i].asistencia;
            acumFaltas += Aux->trab.pagos.listaAsistencia.datos[i].falta;
            acumJusti += Aux->trab.pagos.listaAsistencia.datos[i].justificacion;
            acumTardan += Aux->trab.pagos.listaAsistencia.datos[i].tardanza;
        }
        puntajeLista[j] = acumAsistencias - acumFaltas + float(acumJusti/2) - float(acumTardan/2);
        listaPuntajeOr1[j] = puntajeLista[j];
        j++;
    }

    for (int i = 0; i < listaTrab.numTrabaj - 1; i++) {
        for (int k = i + 1; k < listaTrab.numTrabaj; k++) {
            if(listaPuntajeOr1[i] < listaPuntajeOr1[k]) {
                auxNum = listaPuntajeOr1[i];
                listaPuntajeOr1[i] = listaPuntajeOr1[k];
                listaPuntajeOr1[k] = auxNum;
            }
        }
    }

    int k = 0;
    int band;
    for (int i = 0; i < cantPersonas; i++) {
        j = 0;
        band = 0;
        for(NodoTrabajador *Aux = listaTrab.cab; Aux != NULL && band == 0; Aux = Aux->sgte) {
            if (listaPuntajeOr1[i] == puntajeLista[j]){
                band = 1;
                trabajadoresBuen[k] = Aux->trab;
                k++;
            }
            j++;
        }
    }

    k = 0;
    for (int i = listaTrab.numTrabaj-1; i > listaTrab.numTrabaj-(cantPersonas+1); i--) {
        j = 0;
        band = 0;
        for(NodoTrabajador *Aux = listaTrab.cab; Aux != NULL && band == 0; Aux = Aux->sgte) {
            if (listaPuntajeOr1[i] == puntajeLista[j]){
                band = 1;
                trabajadoresRegu[k] = Aux->trab;
                k++;
            }
            j++;
        }
    }
    system("cls");
    interfazmenu("          :: SISTEMA DE CALIFICACION ::");
    cout << endl << endl;
    cout << "\n\tLista de trabajadores eficientes: \n\n";
    gotoxy(25,11);
    cout << "DNI";
    gotoxy(44,11);
    cout << "NOMBRE";
    gotoxy(85,11);
    cout << "GR. INSTRUCCION";
    int x = 12;
    for (int i = 0; i < cantPersonas; i++) {
        gotoxy(25,x);
        cout << trabajadoresBuen[i].dni;
        gotoxy(44,x);
        cout << trabajadoresBuen[i].nombre;
        gotoxy(85,x);
        cout << TablaGradoInstruccion[trabajadoresBuen[i].gradoInstruccion-1];
        x++;
    }
    x+=2;
    cout << "\n\n\tLista de trabajadores deficientes: ";
    gotoxy(25,x);
    cout << "DNI";
    gotoxy(44,x);
    cout << "NOMBRE";
    gotoxy(85,x);
    cout << "GR. INSTRUCCION";
    x++;
    for (int i = 0; i < cantPersonas; i++) {
        gotoxy(25,x);
        cout << trabajadoresRegu[i].dni;
        gotoxy(44,x);
        cout << trabajadoresRegu[i].nombre;
        gotoxy(85,x);
        cout << TablaGradoInstruccion[trabajadoresRegu[i].gradoInstruccion-1];
        x++;
    }



    for (int i = 0; i < cantPersonas; i++) {
        acumBonificaciones = 0;
        acumDescuentos = 0;
        for(int k = 0; k < trabajadoresBuen->pagos.listaSueldo.num ; k++){
            acumBonificaciones += trabajadoresBuen[i].pagos.listaSueldo.datos[k].bonificacion;
            acumDescuentos += trabajadoresBuen[i].pagos.listaSueldo.datos[k].descuento;
        }
        puntajeBuenos[i] = acumBonificaciones - acumDescuentos;

        if( i == 0){
            mayor = puntajeBuenos[i];
        } else {
            if (mayor <puntajeBuenos[i]){
                mayor = puntajeBuenos[i];
            }
        }
        acumBonificaciones = 0;
        acumDescuentos = 0;
        for(int k = 0; k < trabajadoresRegu[i].pagos.listaSueldo.num ; k++){
            acumBonificaciones = trabajadoresRegu[i].pagos.listaSueldo.datos[k].bonificacion;
            acumDescuentos = trabajadoresRegu[i].pagos.listaSueldo.datos[k].descuento;
        }
        puntajeMalos[i] = acumBonificaciones - acumDescuentos;

        if( i == 0){
            menor =  puntajeMalos[i];
        } else {
            if (menor >  puntajeMalos[i]){
                menor =  puntajeMalos[i];
            }
        }
    }

    x+=3;
    gotoxy(10,x);
    cout << "Trabajador mas eficiente: ";
    x++;
    for (int i = 0; i < cantPersonas; i++) {
        if (mayor == puntajeBuenos[i]){
            gotoxy(20,x);
            cout << "Nombre: "<< trabajadoresBuen[i].nombre;
            x++;
            gotoxy(20,x);
            cout << "Puntaje: " << puntajeBuenos[i];
            x+=2;
        }
    }

    for (int i = 0; i < cantPersonas; i++) {
        if (menor == puntajeMalos[i]){
            gotoxy(10,x);
            cout << "Trabajador mas deficiente: ";
            x++;
            gotoxy(20,x);
            cout << "Nombre: "<< trabajadoresRegu[i].nombre;
            x++;
            gotoxy(20,x);
            cout << "Puntaje: " << puntajeMalos[i]<< endl;
        }
    }
    getch();
}

void menuReportes(ListaTrabajador &lstTrab){
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
        cout << "MENU REPORTES";
        gotoxy(48,10);
        cout << "1. GONZALES BOCANEGRA";
        gotoxy(48,11);
        cout << "2. ROMERO OLIVERA";
        gotoxy(48,12);
        cout << "3. IR AL MENU PRINCIPAL";
        cout << endl << endl;
        fflush(stdin);
        opc = leeEntero("\t\t\t\t\t\tSeleccione: ", 1,3);

        switch (opc) {
            case 1:
                system("cls");
                reporteRodo(lstTrab);
                fflush(stdin);
                break;
            case 2:
                reporteJoseRomero(listaTrab);
                break;
            case 3:
                gotoxy(47,23);
                cout << "VOLVIENDO AL MENU PRINCIPAL";
                getch();
                break;
        }
    } while (!(opc == 3));
}
