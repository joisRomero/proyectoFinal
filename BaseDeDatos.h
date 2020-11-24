
void llenarLista(ListaTrabajador &listaTrab, sqlite3 *db, sqlite3_stmt *query01, sqlite3_stmt *query02,
                 sqlite3_stmt *query03, sqlite3_stmt *query04, sqlite3_stmt *query05, sqlite3_stmt *query06) {

    Trabajador auxTbj;
    NodoTrabajador *nNodo = listaTrab.cab;
    ModuloAsistencia auxAsistencia;
    Sueldo auxSueldo;

    iniciaTrabajador(auxTbj);
    iniciaModuloAsistencia(auxAsistencia);
    iniciaSueldo(auxSueldo);


    string texto;
    string codigo;

    sqlite3_prepare_v2(db, "SELECT * FROM Trabajador", -1, &query01, NULL);
    sqlite3_prepare_v2(db, "SELECT * FROM Contrato", -1, &query02, NULL);
    sqlite3_prepare_v2(db, "SELECT * FROM Cargo", -1, &query03, NULL);
    sqlite3_prepare_v2(db, "SELECT * FROM Direccion", -1, &query04, NULL);


    while ((sqlite3_step(query01) != SQLITE_DONE) && (sqlite3_step(query02) != SQLITE_DONE) &&
           (sqlite3_step(query03) != SQLITE_DONE) && (sqlite3_step(query04) != SQLITE_DONE)) {

        int numColumnas = sqlite3_column_count(query01);
        for (int i = 0; i < numColumnas; i++) {
            switch (sqlite3_column_type(query01,i)) {
            case (SQLITE3_TEXT):
                texto = (const char*) (sqlite3_column_text(query01, 0));
                codigo = (const char*) (sqlite3_column_text(query01, 0));
                strcpy(auxTbj.codigo,texto.c_str());

                texto = (const char*) (sqlite3_column_text(query01, 1));
                strcpy(auxTbj.dni,texto.c_str());

                texto = (const char*) (sqlite3_column_text(query01, 2));
                strcpy(auxTbj.nombre,texto.c_str());

                break;
            case (SQLITE_INTEGER):
                auxTbj.fondoPensiones =  sqlite3_column_int(query01, 3);
                auxTbj.nroHijos = sqlite3_column_int(query01, 4);
                auxTbj.estadoCivil = sqlite3_column_int(query01, 5);
                auxTbj.gradoInstruccion = sqlite3_column_int(query01, 6);
                auxTbj.sexo = sqlite3_column_int(query01, 7);
                auxTbj.edad = sqlite3_column_int(query01, 8);
                break;
            default:
                break;
            }
        }

        int numColumnasContrato = sqlite3_column_count(query02);
        for (int i = 0; i < numColumnasContrato; i++) {
            switch (sqlite3_column_type(query02,i)) {
            case (SQLITE_INTEGER):
                auxTbj.contrato.horario = sqlite3_column_int(query02,1);
                auxTbj.contrato.banco = sqlite3_column_int(query02,2);
                auxTbj.contrato.tipoTrabajador = sqlite3_column_int(query02,3);
                auxTbj.contrato.inicioContrato.Anio = sqlite3_column_int(query02,5);
                auxTbj.contrato.inicioContrato.Mes = sqlite3_column_int(query02,6);
                auxTbj.contrato.inicioContrato.Dia = sqlite3_column_int(query02,7);
                auxTbj.contrato.finContrato.Anio = sqlite3_column_int(query02,8);
                auxTbj.contrato.finContrato.Mes = sqlite3_column_int(query02,9);
                auxTbj.contrato.finContrato.Dia = sqlite3_column_int(query02,10);
                break;
            case (SQLITE_FLOAT):
                auxTbj.contrato.sueldoBase = sqlite3_column_double(query02, 4);
                break;
            default:
                break;
            }
        }

        int numColumnasCargo = sqlite3_column_count(query03);
        for (int i = 0; i < numColumnasCargo; i++) {
            switch (sqlite3_column_type(query03,i)) {
            case(SQLITE_INTEGER):
                auxTbj.contrato.cargo.grupoOcupacional = sqlite3_column_int(query03,1);
                auxTbj.contrato.cargo.claseDeCargo = sqlite3_column_int(query03,2);
                break;
            default:
                break;
            }
        }

        int numColumnasDireccion = sqlite3_column_count(query04);
        for (int i = 0; i < numColumnasDireccion; i++) {
            switch (sqlite3_column_type(query04,i)) {
            case (SQLITE_TEXT):
                texto = (const char*) (sqlite3_column_text(query04, 1));
                strcpy(auxTbj.direccion.calle,texto.c_str());
                texto = (const char*) (sqlite3_column_text(query04, 2));
                strcpy(auxTbj.direccion.distrito,texto.c_str());
                break;
            case (SQLITE_INTEGER):
                auxTbj.direccion.provincia = sqlite3_column_int(query04,3);
                break;
            default:
                break;
            }
        }

        insertaListaTrabajador(listaTrab, auxTbj, nNodo);
    }

    int j = 0;
    ListaModuloAsistencia auxLista;
    ListaSueldo auxListaSueldo;
    iniciaListaModuloAsistencia(auxLista);
    iniciaListaSueldo(auxListaSueldo);
    char codigos[100][LIM];
    iniciaTabla(codigos, 100);
    sqlite3_prepare_v2(db, "SELECT * FROM Asistencia", -1, &query05, NULL);
    sqlite3_prepare_v2(db, "SELECT * FROM Sueldo", -1, &query06, NULL);

    while ((sqlite3_step(query05) != SQLITE_DONE) && (sqlite3_step(query06) != SQLITE_DONE)) {
        int numColumnasAsistencia = sqlite3_column_count(query05);
        for (int i = 0; i < numColumnasAsistencia; i++) {
            switch (sqlite3_column_type(query05,i)) {
            case (SQLITE_TEXT):
                texto = (const char*) (sqlite3_column_text(query05, 0));
                strcpy(codigos[j],texto.c_str());
                break;
            case (SQLITE_INTEGER):
                auxAsistencia.anio = sqlite3_column_int(query05,1);
                auxAsistencia.mes = sqlite3_column_int(query05,2);
                auxAsistencia.asistencia = sqlite3_column_int(query05,3);
                auxAsistencia.falta = sqlite3_column_int(query05,4);
                auxAsistencia.tardanza = sqlite3_column_int(query05,5);
                auxAsistencia.justificacion = sqlite3_column_int(query05,6);
                break;
            default:
                break;
            }
        }

        int numColumnasSueldo = sqlite3_column_count(query06);
        for (int i = 0; i < numColumnasSueldo; i++) {
            switch (sqlite3_column_type(query06,i)) {
            case (SQLITE_INTEGER):
                auxSueldo.anio = sqlite3_column_int(query06,1);
                auxSueldo.mes = sqlite3_column_int(query06,2);
                break;
            case (SQLITE_FLOAT):
                auxSueldo.asignacionFamiliar = sqlite3_column_double(query06, 3);
                auxSueldo.descuento = sqlite3_column_double(query06, 4);
                auxSueldo.bonificacion = sqlite3_column_double(query06, 5);
                auxSueldo.adelanto = sqlite3_column_double(query06, 6);
                auxSueldo.sueldoNeto = sqlite3_column_double(query06, 7);
                break;
            default:
                break;
            }
        }

        insertaModuloAsistencia(auxLista,auxAsistencia);
        insertaSueldo(auxListaSueldo, auxSueldo);
        j++;
    }

    for(NodoTrabajador *auxNodo = listaTrab.cab; auxNodo != NULL; auxNodo = auxNodo->sgte){
        for(int i = 0; i < auxLista.num; i++) {
            if(strcmpi(auxNodo->trab.codigo, codigos[i])==0){
                insertaModuloAsistencia(auxNodo->trab.pagos.listaAsistencia,auxLista.datos[i]);
                insertaSueldo(auxNodo->trab.pagos.listaSueldo, auxListaSueldo.datos[i]);
            }
        }
    }
}





