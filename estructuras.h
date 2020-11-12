#include "basicas.h"
//---------------------------  DIRECCIÓN  -------------------------//

struct Direccion {
    char calle[LIM];
    char distrito[LIM];
    int provincia;
};

void iniciaDireccion(Direccion &Dir) {
    Dir.calle[0] = NULL;
    Dir.distrito[0] = NULL;
    Dir.provincia = 0;
}

void leeDireccion(Direccion &Dir) {
    system("cls");
    cout << "------Direcion------" << endl;
    fflush(stdin);
    cout << "Calle: ";
    cin.getline(Dir.calle, LIM);
    fflush(stdin);
    cout << "Distrito: ";
    cin.getline(Dir.distrito, LIM);
    fflush(stdin);
    cout << "Provincia: " << endl;
    Dir.provincia = validaTabla("Seleccione: ",  TablaProvincia, MAXTABLAPROVINCIA);
    fflush(stdin);
}

void mostrarDireccion(Direccion &Dir) {
    cout << "Direcion: " << endl;
    cout << "Calle: " << Dir.calle << endl;
    cout << "Distrito: " << Dir.distrito << endl;
    cout << "Provincia: " << TablaProvincia[Dir.provincia-1] << endl;
}

//------------------------  MODULO ASISTENCIA  --------------------//

struct ModuloAsistencia {
    int anio;
    int mes;
    int asistencia;
    int falta;
    int tardanza;
    int justificacion;

};

void iniciaModuloAsistencia(ModuloAsistencia &ModAsis) {
    ModAsis.anio = 0;
    ModAsis.mes = 0;
    ModAsis.asistencia = 0;
    ModAsis.falta = 0;
    ModAsis.tardanza = 0;
    ModAsis.justificacion = 0;
}

void leeModuloAsistencia(ModuloAsistencia &ModAsis) {
    system("cls");
    cout << "------ Modulo Asistencia ------\n";
    fflush(stdin);
    ModAsis.anio = leeEntero ( "Anio: ", 2020, 2025);
    ModAsis.mes = leeEntero("Mes: ", 1, 12);
    ModAsis.asistencia = leeEntero( "Asistencia: ", 0, 31);
    ModAsis.falta = leeEntero("Falta(s): ", 0, 31);
    ModAsis.tardanza = leeEntero("Tardanza(s): ", 0, 31);
    ModAsis.justificacion = leeEntero("Justificacion(es): ", 0, 31);
    fflush(stdin);
}

void mostrarModuloAsistencia(ModuloAsistencia &ModAsis) {
    cout << "\tAnio: " << ModAsis.anio << endl;
    cout << "\tMes: " << TablaMeses[ModAsis.mes - 1] << endl;
    cout << "Asistencia: " << ModAsis.asistencia << endl;
    cout << "Falta(s): " << ModAsis.falta << endl;
    cout << "Tardanza(s): " << ModAsis.tardanza << endl;
    cout << "Justificacion(es): " << ModAsis.justificacion << endl;
}

struct ListaModuloAsistencia{
    ModuloAsistencia *datos;
    int num, maximo;
};

void iniciaListaModuloAsistencia(ListaModuloAsistencia &lstModAsis){
    lstModAsis.datos = NULL;
    lstModAsis.num = 0;
    lstModAsis.maximo = 0;
}

void creceListaModuloAsistencia(ListaModuloAsistencia &lstModAsis){
    ModuloAsistencia *temp;
    temp = new ModuloAsistencia[lstModAsis.maximo+DELTA];
    for (int i = 0; i < lstModAsis.num; i++){
        temp[i] = lstModAsis.datos[i];
    }
    delete []lstModAsis.datos;
    lstModAsis.datos = temp;
    lstModAsis.maximo += DELTA;
}

void insertaModuloAsistencia(ListaModuloAsistencia &lstModAsis, ModuloAsistencia &ModAsis){
    if(lstModAsis.num == lstModAsis.maximo){
        creceListaModuloAsistencia(lstModAsis);
    }
    lstModAsis.datos[lstModAsis.num] = ModAsis;
    lstModAsis.num++;
}

void leeListaModuloAsistencia(ListaModuloAsistencia &lstModAsis){
    ModuloAsistencia ModAsis;
    do{
        iniciaModuloAsistencia(ModAsis);
        leeModuloAsistencia(ModAsis);
        insertaModuloAsistencia(lstModAsis, ModAsis);
    }while(continuar("\nDesea agregar otro Modulo de Asistencia? (S/N): ")=='S');
}

void mostrarListaModuloAsistencia(ListaModuloAsistencia &lstModAsis){
    cout << "\nLISTA DE MODULOS DE ASISTENCIA: \n";
    for(int i = 0; i < lstModAsis.num; i++) {
        cout << "\n\n\t::MODULO DE ASISTENCIA "<< i+1 << ":: "; //tabladelmes
        mostrarModuloAsistencia(lstModAsis.datos[i]);
    }
}

void liberarListaModuloAsistencia(ListaModuloAsistencia &lstModAsis){
    delete []lstModAsis.datos;
}

//-----------------------------  SUELDO  --------------------------//

struct Sueldo {
    int anio;
    int mes;
    float asignacionFamiliar;
    float descuento;
    float sueldoNeto;
};

void iniciaSueldo(Sueldo &Sue) {
    Sue.anio = 0;
    Sue.mes = 0;
    Sue.asignacionFamiliar = 0.0;
    Sue.descuento = 0.0;
    Sue.sueldoNeto = 0.0;
}

void leeSueldo(Sueldo &Sue) {
    fflush(stdin);
    Sue.anio = leeEntero ( "Anio: ", 2020, 2025);
    cout << "Mes: ";
    Sue.mes = validaTabla ("\nSeleccione: ",  TablaMeses, MAXTABLAMES);
    //Por tardanza se descunta 10 soles
    //Por falta se descunta 40 soles

//    Sue.sueldoNeto = Sue.sueldoBase+Sue.asignacionFamiliar-Sue.descuento;

}


void mostrarSueldo(Sueldo &Sue) {
    cout << "\t\tAnio: " << Sue.anio << endl;
    cout << "\t\tMes: " << Sue.mes << endl;
    cout << "\t______________" << endl;
    cout << "Asignacion Familiar: " << Sue.asignacionFamiliar << endl;
    cout << "Descuento: " << Sue.descuento << endl;
    cout << "Sueldo Neto: " << Sue.sueldoNeto << endl;
}

struct ListaSueldo{
    Sueldo *datos;
    int num, maximo;
};

void iniciaListaSueldo(ListaSueldo &lstSueldo){
    lstSueldo.datos = NULL;
    lstSueldo.maximo = 0;
    lstSueldo.num = 0;
}

void creceListaSueldo(ListaSueldo &lstSueldo){
    Sueldo *temp;
    temp = new Sueldo[lstSueldo.maximo+DELTA];
    for (int i = 0; i < lstSueldo.num; i++){
        temp[i] = lstSueldo.datos[i];
    }
    delete []lstSueldo.datos;
    lstSueldo.datos = temp;
    lstSueldo.maximo += DELTA;
}

void insertaSueldo(ListaSueldo &lstSueldo, Sueldo &Sue){
    if(lstSueldo.num == lstSueldo.maximo){
        creceListaSueldo(lstSueldo);
    }
    lstSueldo.datos[lstSueldo.num] = Sue;
    lstSueldo.num++;
}

void leeListaSueldo(ListaSueldo &lstSueldo){
    Sueldo Sue;
    cout << "\nLectura de Datos: ";
    do{
        iniciaSueldo(Sue);
        leeSueldo(Sue);
        insertaSueldo(lstSueldo, Sue);
    }while(continuar("\nDesea agregar otro Sueldo? (S/N): ")=='S');
}

void mostrarListaSueldo(ListaSueldo &lstSueldo){
    cout << "\nLISTA DE SUELDOS: \n";
    for(int i = 0; i < lstSueldo.num; i++) {
        cout << "\n\n\t::SUELDO "<< i+1 << ":: "; //tabladelmes
        mostrarSueldo(lstSueldo.datos[i]);
    }
}

void liberarListaSueldo(ListaSueldo &lstSueldo){
    delete []lstSueldo.datos;
}

//-------------------------------  CARGO  -------------------------//

struct Cargo {
    int grupoOcupacional;
    int claseDeCargo;
};

void iniciaCargo(Cargo &Carg) {
    Carg.grupoOcupacional = 0;
    Carg.claseDeCargo = 0;
}

void leeCargo(Cargo &Carg) {
    fflush(stdin);
    cout << "Grupos Ocupacionales: " << endl;
    Carg.grupoOcupacional = validaTabla("Seleccione: ", TablaGrupoOcupacional, MAXTABLAGRUPOOCUPACIONAL);

    cout << "Clase de cargo: " << endl;
    if (Carg.grupoOcupacional == 1) {
        Carg.claseDeCargo = validaTabla("Seleccione: ", TablaDirectorSuperior, MAXTABLADIRECTORSUPERIOR);
    } else if (Carg.grupoOcupacional == 2){
        Carg.claseDeCargo = validaTabla("Seleccione: ", TablaEjecutivo, MAXTABLAEJECUTIVO);
    } else if (Carg.grupoOcupacional == 3){
        Carg.claseDeCargo = validaTabla("Seleccione: ", TablaEspecialista, MAXTABLAESPECIALISTA);
    } else {
        Carg.claseDeCargo = validaTabla("Seleccione: ", TablaApoyo, MAXTABLAAPOYO);
    }
}

void mostrarCargo(Cargo &Carg) {
    cout << "Grupo Ocupacional: " << TablaGrupoOcupacional[Carg.grupoOcupacional-1]<< endl;
    if (Carg.grupoOcupacional == 1) {
        cout << "Cargo: " << TablaDirectorSuperior[Carg.claseDeCargo -1] << endl ;
    } else if (Carg.grupoOcupacional == 2){
        cout << "Cargo: " << TablaEjecutivo[Carg.claseDeCargo -1] << endl;
    } else if (Carg.grupoOcupacional == 3){
        cout << "Cargo: " << TablaEspecialista[Carg.claseDeCargo -1] << endl;
    } else {
        cout << "Cargo: " << TablaApoyo[Carg.claseDeCargo -1] << endl;
    }
}



//-----------------------------  CONTRATO  ------------------------//

struct Contrato {
    int horario;
    char nroCuenta[MAXNROCUENTA];
    char cci[MAXCCI];
    int banco;
    int tipoTrabajador;
    float sueldoBase;
    Fecha inicioContrato;
    Fecha finContrato;
    Cargo cargo;
};

void iniciaContrato(Contrato &Contr) {
    Contr.horario = 0;
    Contr.nroCuenta[0] = NULL;
    Contr.cci[0] = NULL;
    Contr.banco = 0;
    Contr.tipoTrabajador = 0;
    Contr.sueldoBase = 0.0;
    iniciaFecha(Contr.inicioContrato);
    iniciaFecha(Contr.finContrato);
    iniciaCargo(Contr.cargo);
}

void leeContrato(Contrato &Contr) {
    fflush(stdin);
    cout << "Horario: " << endl;
    Contr.horario = validaTabla("Seleccione: ", TablaHorario, MAXTABLAHORARIO);
    Contr.sueldoBase = leeReal("Salario base: ",930,8000);

//    leeTextoComoNumero("Numero de Cuenta", Contr.nroCuenta, MAXNROCUENTA);

//    leeTextoComoNumero("Codigo de Cuenta Interbancario (CCI)", Contr.cci,MAXCCI);

    cout << "Bancos: " << endl;
    Contr.banco = validaTabla("Seleccione: ", TablaBanco, MAXTABLABANCO);

    cout << "Tipos de trabajadores: " << endl;
    Contr.tipoTrabajador = validaTabla("Seleccione: ", TablaTipoTrabajador, MAXTABLATIPOTRABAJADOR);

    cout << "Inicio de contrato: ";
    leeFecha(Contr.inicioContrato);

    cout << "Fin de contrato: ";
    leeFecha(Contr.finContrato);

    leeCargo(Contr.cargo);

}

void mostrarContrato(Contrato &Contr) {
    cout << "Horario: " << TablaHorario [Contr.horario - 1] << endl;
    cout << "Salario Base: " << Contr.sueldoBase << endl;
    cout << "Numero de Cuenta: " << Contr.nroCuenta << endl;
    cout << "CCI: " << Contr.cci << endl;
    cout << "Banco: " << TablaBanco[Contr.banco - 1] <<endl;
    cout << "Tipo de trabajador: " << TablaTipoTrabajador[Contr.tipoTrabajador - 1] << endl;
    cout << "Inicio de contrato: "; MostrarFecha(Contr.inicioContrato);
    cout << endl;
    cout << "Fin del contrato: "; MostrarFecha(Contr.finContrato);
    cout << endl;
    mostrarCargo(Contr.cargo);
}

// ------------------------- PAGOS -------------------------------//

struct Pagos {
    ListaModuloAsistencia listaASistencia;
    ListaSueldo listaSueldo;
};

void iniciaPagos(Pagos &pagos){
    iniciaListaModuloAsistencia(pagos.listaASistencia);
    iniciaListaSueldo(pagos.listaSueldo);
}

void mostrarPagos(Pagos &pagos){
    mostrarListaModuloAsistencia(pagos.listaASistencia);
    mostrarListaSueldo(pagos.listaSueldo);
}

//-------------------------  TRABAJADOR  --------------------------//

struct Trabajador {
    char dni[MAXDNI];
    char nombre[LIM];
    char ruc[MAXRUC];
    char telefono[MAXTELEFONO];
    int fondoPensiones;
    int nroHijos;
    int estadoCivil;
    int gradoInstruccion;
    char correo[LIM];
    char codigo[MAXCODIGO];

    Direccion direccion;
    Contrato contrato;
    Pagos pagos;

};

char generarCodigo(Contrato &Contr, Trabajador &Trab);

void iniciaTrabajador(Trabajador &Trab) {
    Trab.dni[0] = NULL;
    Trab.nombre[0] = NULL;
    Trab.ruc[0] = NULL;
    Trab.telefono[0] = NULL;
    Trab.fondoPensiones = 0;
    Trab.nroHijos = 0;
    Trab.estadoCivil = 0;
    Trab.gradoInstruccion = 0;
    Trab.correo[0] = 0;
    Trab.codigo[0] = NULL;

    iniciaDireccion(Trab.direccion);
    iniciaContrato(Trab.contrato);
    iniciaPagos(Trab.pagos);
}

void leeTrabajador(Trabajador &Trab) {
    leeTextoComoNumero("DNI",Trab.dni, MAXDNI);
    fflush(stdin);
    cout << "Nombre Completo: ";
    cin.getline(Trab.nombre,LIM);
    fflush(stdin);
//    leeTextoComoNumero("RUC", Trab.ruc, MAXRUC);

//    leeTextoComoNumero("Telefono", Trab.telefono,MAXTELEFONO);

    cout << "Sistemas de Fondo de Pensiones: " << endl;
    Trab.fondoPensiones = validaTabla("Seleccione: ",TablaFomdoPensiones,MAXTABLAFONDOPENSIONES);

    Trab.nroHijos = leeEntero("Numero de hijos: ", 0, 15);

    cout << "Estado Civil: " << endl;
    Trab.estadoCivil = validaTabla("Seleccione: ",TablaEstadoCivil, MAXTABLAESTADOCIVIL);

    cout << "Grados de Instruccion: " << endl;
    Trab.gradoInstruccion = validaTabla("Seleccione: ", TablaGradoInstruccion, MAXTABLAGRADOINSTRUCCION);
    fflush(stdin);
    cout << "Correo: ";
    cin.getline(Trab.correo, LIM);


    leeDireccion(Trab.direccion);
    leeContrato(Trab.contrato);

    fflush(stdin);
//  -------- GENERADOR DE CODIGO --------------
    int anio = Trab.contrato.inicioContrato.Anio;
    char codigoFK[MAXCODIGO];
    itoa(anio, codigoFK, 10);
    char b[MAXDNI];
    strcpy(b,Trab.dni);
    strcat (codigoFK, b);
    strcpy(Trab.codigo, codigoFK);
}

void mostrarTrabajador(Trabajador &Trab) {
    cout << "DNI: " << Trab.dni << endl;
    cout << "Nombre Completo: " << Trab.nombre << endl;
    cout << "RUC: " << Trab.ruc << endl;
    cout << "Telefono: " << Trab.telefono << endl;
    cout << "Sitema de Fondo de Pension: " << TablaFomdoPensiones[Trab.fondoPensiones - 1] << endl;
    cout << "Numero de hijos: " << Trab.nroHijos << endl;
    cout << "Estado Civil: " << TablaEstadoCivil[Trab.estadoCivil - 1] << endl;
    cout << "Grado de Instruccion: " <<  TablaGradoInstruccion[Trab.gradoInstruccion - 1] << endl;
    cout << "Correo: " << Trab.correo << endl;
    cout << "Codigo: " << Trab.codigo << endl;
    mostrarDireccion(Trab.direccion);
    mostrarContrato(Trab.contrato);
    mostrarPagos(Trab.pagos);
}

struct NodoTrabajador{
    Trabajador trab;
    NodoTrabajador *sgte;
};

struct ListaTrabajador{
    NodoTrabajador *cab;
    int numTrabaj;
};

void iniciaListaTrabajador(ListaTrabajador &lstTrab){
    lstTrab.cab = NULL;
    lstTrab.numTrabaj = 0;
}

void insertaListaTrabajador(ListaTrabajador &lstTrab, Trabajador &trab, NodoTrabajador *&Aux) {
    NodoTrabajador *p = new NodoTrabajador;
    p->trab = trab;

    if (Aux == NULL) {
        p->sgte = lstTrab.cab;
        lstTrab.cab = p;
    } else {
        p->sgte = Aux->sgte;
        Aux->sgte = p;
    }
    lstTrab.numTrabaj++;
    Aux = p;
}

void leeListaTrabajador(ListaTrabajador &lstTrab) {
    Trabajador trab;
    NodoTrabajador *Aux = lstTrab.cab;
    do {
        system("cls");
        cout << "\n\n Lectura de Datos:\n\n";
        iniciaTrabajador(trab);
        leeTrabajador(trab);
        insertaListaTrabajador(lstTrab, trab, Aux);
    } while (continuar("\nDesea registrar otro empleado? (S/N): ") == 'S');
    fflush(stdin);
}

void mostrarListaTrabajador(ListaTrabajador &lstTrab){
    int i = 1;
    system("cls");
    cout << "\nLISTA DE TRABAJADORES: \n";
    for(NodoTrabajador *Aux = lstTrab.cab; Aux != NULL; Aux = Aux->sgte) {
        cout << "\n\n\t::TRABAJADOR "<< i++ << ":: \n";
        mostrarTrabajador(Aux->trab);
    }
}

void liberarTrabajador(ListaTrabajador &lstTrab){
    NodoTrabajador *Aux = lstTrab.cab;
    while (Aux->sgte != NULL) {
        lstTrab.cab = Aux->sgte;
        liberarListaSueldo(Aux->trab.pagos.listaSueldo);
        liberarListaModuloAsistencia(Aux->trab.pagos.listaASistencia);
        delete [] Aux;
        Aux = lstTrab.cab;
    }
}
