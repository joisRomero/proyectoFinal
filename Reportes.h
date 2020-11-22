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
    listaTrab ListaFiltradaFINAL;
    iniciaListaTrabajador(ListaFiltradaFINAL);

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
        }while(strcmpi(auxCodigo,Aux->trab.codigo)==0);

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
            cout << "3. Desea volver atras? ";
            opcion1 = leeEntero("\tSeleccione: ",1,2);

            switch (opcion1) {
            case 1:
                system("cls");
                ListaTrabajador ListaFiltrada;
                iniciaListaTrabajador(ListaFiltrada);

                cout << "De que clase de cargo necesita asistencia? ";
                for(int i = 0; i < MAXTABLAESPECIALISTA; i++){
                    cout << i+1 << ". " << TablaEspecialista[i] << endl;
                }
                opcionClaseCargo = leeEntero("\tSeleccione: ",1,MAXTABLAESPECIALISTA);

                cout << "Lista de Trabajadores del cargo " << TablaEspecialista[opcion2-1];
                cout << endl << endl;
                cout << "Nombre\t\t\t\t\tEstudios";

                for(NodoTrabajador *AuxParaCargo = listaTrab.cab; AuxParaCargo != NULL; AuxParaCargo = AuxParaCargo->sgte){
                    if(AuxParaCargo->trab.contrato.cargo.claseDeCargo==opcionClaseCargo && strcmpi(Aux->trab.codigo,AuxParaCargo->trab.codigo)!=0){
                        insertaListaTrabajador(ListaFiltrada,AuxParaCargo->trab);
                    }
                }
                int j=0;
                for(NodoTrabajador *AuxParaCargo = ListaFiltrada.cab; AuxParaCargo != NULL; AuxParaCargo = AuxParaCargo->sgte){
                    cout << j+1 << ". " << AuxParaCargo->trab.nombre << "\t\t" << TablaGradoInstruccion[AuxParaCargo->trab.gradoInstruccion-1];
                    j++;
                }

                opcionTrabajador = leeEntero("\n\tSeleccione un trabajador: ");
                if(opcionTrabajador == j){

                }


                break;
            case 2:
                system("cls");
                break;
            case 3:
                cout << "Volviendo al menu Reportes";
                getch();
                break;

            }

        }while(continuar("\n\tDesea seleccionar otro grupo? (S/N): ") == 'S');
    }
}

void menuReportes(){
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
               //reporte Rodo;
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
