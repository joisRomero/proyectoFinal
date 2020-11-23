/*
    Reporte de J. David Gonzales:
        El área de recursos humanos proveerá al trabajador que desee
        un apoyo de otros trabajadores, ingresando primero su código,
        se le muestra una lista de las clases de cargo y él escoge,
        después se le mostrará una lista de trabajadores de ese cargo
        y seleccionará tantos como quiera solicitar (si es que desea),
        después regresar a la parte de lista de clases de cargo si es
        que desea solicitar otros trabajadores de otros cargos, al
        final mostrar el trabajador solicitó a tales trabajadores.
        Tener en cuenta que si un informático solicita otros
        informáticos su propio nombre no debe aparecer ahí, así como
        tampoco deben aparecer los ya seleccionados
*/
void reporteRodo(ListaTrabajador &listaTrab){
    char saludo[LIM];
    char auxCodigo[MAXCODIGO];
    int opcion1, opcionClaseCargo, opcionTrabajador;
    ListaTrabajador ListaFiltradaFINAL;
    iniciaListaTrabajador(ListaFiltradaFINAL);
    NodoTrabajador *nodoListaFiltradaFinal;

    Trabajador auxTrabajador;
    iniciaTrabajador(auxTrabajador);

    for(NodoTrabajador *Aux = listaTrab.cab; Aux != NULL; Aux = Aux -> sgte){
        do{
            cout << "Ingrese su codigo: " << endl;
            fflush(stdin);
            cin.getline(auxCodigo,MAXCODIGO);
            fflush(stdin);
            if(strcmpi(auxCodigo,Aux->trab.codigo)!=0){
                cout << "Este codigo no se encuentra en nuestra base de datos" << endl;
                cout << "Intentelo nuevamente..." << endl;
            }
        }while(strcmpi(auxCodigo,Aux->trab.codigo)!=0);

        //saludo
        if(Aux->trab.sexo==1){
            strcat(saludo,"Bienvenido Sr. ");
            strcat(saludo,Aux->trab.nombre);
        }else if(Aux->trab.estadoCivil==1){
            strcat(saludo,"Bienvenida Srta. ");
            strcat(saludo,Aux->trab.nombre);
        }else{
            strcat(saludo,"Bienvenida Sra. ");
            strcat(saludo,Aux->trab.nombre);
        }


        do{
            cout << "De que grupo necesita asistencia? ";
            cout << "1. Especialista";
            cout << "2. Apoyo";
            opcion1 = leeEntero("\tSeleccione: ",1,2);

            switch (opcion1) {
                case 1:{
                    system("cls");
                    ListaTrabajador ListaFiltrada;
                    iniciaListaTrabajador(ListaFiltrada);
                    NodoTrabajador *nodoListaFiltrada = ListaFiltrada.cab;

                    do{
                        cout << "De que clase de cargo necesita asistencia? ";
                        for(int i = 0; i < MAXTABLAESPECIALISTA; i++){
                            cout << i+1 << ". " << TablaEspecialista[i] << endl;
                        }
                        opcionClaseCargo = leeEntero("\tSeleccione: ",1,MAXTABLAESPECIALISTA);
                        //limpiar pantalla
                        cout << "Lista de Trabajadores del cargo " << TablaEspecialista[opcionClaseCargo-1];
                        cout << endl << endl;
                        cout << "Codigo\t\t\tNombre\t\t\t\t\tEstudios";

                        for(NodoTrabajador *AuxParaCargo = listaTrab.cab; AuxParaCargo != NULL; AuxParaCargo = AuxParaCargo->sgte){
                            if(AuxParaCargo->trab.contrato.cargo.claseDeCargo==opcionClaseCargo && strcmpi(Aux->trab.codigo,AuxParaCargo->trab.codigo)!=0){
                                insertaListaTrabajador(ListaFiltrada,AuxParaCargo->trab,nodoListaFiltrada);
                            }
                        }
                        int j = 0;
                        for(NodoTrabajador *AuxParaCargo = ListaFiltrada.cab; AuxParaCargo != NULL; AuxParaCargo = AuxParaCargo->sgte){
                            cout << j+1 << ". " << AuxParaCargo->trab.codigo << AuxParaCargo->trab.nombre << "\t\t" << TablaGradoInstruccion[AuxParaCargo->trab.gradoInstruccion-1];
                            j++;
                        }
                        cout << endl << endl;
                        int arregloOpciones[j];
                        iniciaVE(arregloOpciones,j);
                        do{
                            opcionTrabajador = leeEntero("\n\tElija un trabajador: ",1,j);
                            if(arregloOpciones[opcionTrabajador-1]==0){
                                j = 1; //iterar
                                for(NodoTrabajador *AuxParaCargo = ListaFiltrada.cab; AuxParaCargo != NULL; AuxParaCargo = AuxParaCargo->sgte){
                                    if(opcionTrabajador == j){
                                        insertaListaTrabajador(ListaFiltradaFINAL,AuxParaCargo->trab,nodoListaFiltradaFinal);
                                    }
                                    j++;
                                }
                            arregloOpciones[opcionTrabajador-1]=1;
                            }else{
                                cout << "Ya se selecciono este trabajador";
                            }
                        }while(continuar("Desea seleccionar otro trabajador?(S/N): ") == 'S');
                    }while(continuar("Desea seleccionar otra clase de cargo?(S/N): ")=='S');

                    break;
                    }
                case 2:
                    system("cls");
                    ListaTrabajador ListaFiltrada2;
                    iniciaListaTrabajador(ListaFiltrada2);
                    NodoTrabajador *nodoListaFiltrada2 = ListaFiltrada2.cab;

                    do{
                        cout << "De que clase de cargo necesita asistencia? ";
                        for(int i = 0; i < MAXTABLAAPOYO; i++){
                            cout << i+1 << ". " << TablaApoyo[i] << endl;
                        }
                        opcionClaseCargo = leeEntero("\tSeleccione: ",1,MAXTABLAAPOYO);
                        //limpiar pantalla
                        cout << "Lista de Trabajadores del cargo " << TablaApoyo[opcionClaseCargo-1];
                        cout << endl << endl;
                        cout << "Codigo\t\t\tNombre\t\t\t\t\tEstudios";

                        for(NodoTrabajador *AuxParaCargo = listaTrab.cab; AuxParaCargo != NULL; AuxParaCargo = AuxParaCargo->sgte){
                            if(AuxParaCargo->trab.contrato.cargo.claseDeCargo==opcionClaseCargo && strcmpi(Aux->trab.codigo,AuxParaCargo->trab.codigo)!=0){
                                insertaListaTrabajador(ListaFiltrada2,AuxParaCargo->trab,nodoListaFiltrada2);
                            }
                        }
                        int j = 0;
                        for(NodoTrabajador *AuxParaCargo = ListaFiltrada2.cab; AuxParaCargo != NULL; AuxParaCargo = AuxParaCargo->sgte){
                            cout << j+1 << ". " << AuxParaCargo->trab.codigo << AuxParaCargo->trab.nombre << "\t\t" << TablaGradoInstruccion[AuxParaCargo->trab.gradoInstruccion-1];
                            j++;
                        }
                        cout << endl << endl;
                        int arregloOpciones[j];
                        iniciaVE(arregloOpciones,j);
                        do{
                            opcionTrabajador = leeEntero("\n\tElija un trabajador: ",1,j);
                            if(arregloOpciones[opcionTrabajador-1]==0){
                                j = 1; //iterar
                                for(NodoTrabajador *AuxParaCargo = ListaFiltrada2.cab; AuxParaCargo != NULL; AuxParaCargo = AuxParaCargo->sgte){
                                    if(opcionTrabajador == j){
                                        insertaListaTrabajador(ListaFiltradaFINAL,AuxParaCargo->trab,nodoListaFiltradaFinal);
                                    }
                                    j++;
                                }
                            arregloOpciones[opcionTrabajador-1]=1;
                            }else{
                                cout << "Ya se selecciono este trabajador";
                            }
                        }while(continuar("Desea seleccionar otro trabajador?(S/N): ") == 'S');
                    }while(continuar("Desea seleccionar otra clase de cargo?(S/N): ")=='S');

                    break;

            }
        }while(continuar("\n\tDesea seleccionar otro grupo? (S/N): ") == 'S');
    }

    //Ordeno por codigo

    for(NodoTrabajador *Aux = ListaFiltradaFINAL.cab; Aux->sgte != NULL; Aux = Aux -> sgte){
        for(NodoTrabajador *Aux2 = Aux->sgte; Aux2 != NULL; Aux2 = Aux2->sgte){
            if(strcmpi(Aux->trab.codigo,Aux2->trab.codigo)>0){
                auxTrabajador = Aux->trab;
                Aux->trab = Aux2->trab;
                Aux2->trab = auxTrabajador;
            }
        }
    }

    for(NodoTrabajador *Aux = listaTrab.cab; Aux != NULL; Aux = Aux -> sgte){
        if(auxCodigo, Aux->trab.codigo)
            cout << "El Trabajador " << Aux->trab.nombre << ". Solicito la asistencia de: ";
    }

    for(NodoTrabajador *Aux = ListaFiltradaFINAL.cab; Aux != NULL; Aux = Aux -> sgte){
        cout << "\n\t- " << Aux->trab.codigo << " :: " << Aux->trab.nombre;
    }

    getch();
    liberarTrabajador(ListaFiltradaFINAL);
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
        opc = leeEntero("\t\t\t\t\t\tSeleccione: ", 1,3);

        switch (opc) {
            case 1:
                reporteRodo(lstTrab);
                break;
            case 2:
                //reporte JoisRomero;
                break;
            case 3:
                gotoxy(47,23);
                cout << "VOLVIENDO AL MENU PRINCIPAL";
                getch();
                break;
        }
    } while (!(opc == 3));
}
