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
    interfazmenu("DATOS DE LA DIRECCION");
    cout << endl;
    fflush(stdin);
    cout << "\tCalle: ";
    fflush(stdin);
    cin.getline(Dir.calle, LIM);
    cout << "\tDistrito: ";
    fflush(stdin);
    cin.getline(Dir.distrito, LIM);
    cout << "\tProvincia: " << endl;
    Dir.provincia = validaTabla("Seleccione: ", TablaProvincia, MAXTABLAPROVINCIA);
    fflush(stdin);
}

void mostrarDireccion(Direccion &Dir) {
    cout << "\n\tDIRECCION" << endl;
    cout << "\tCalle: " << Dir.calle << endl;
    cout << "\tDistrito: " << Dir.distrito << endl;
    cout << "\tProvincia: " << TablaProvincia[Dir.provincia-1] << endl;
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
    interfazmenu("DATOS DE ASISTENCIA");
    cout << endl;
    fflush(stdin);
    ModAsis.anio = ANIOACTUAL;
    ModAsis.mes = MESACTUAL;
    cout << endl;
    ModAsis.falta = leeEntero("\tFalta(s): ", 0, 31);
    ModAsis.tardanza = leeEntero("\tTardanza(s): ", 0, 31);
    do {
        ModAsis.justificacion = leeEntero("\tJustificacion(es): ", 0, 31);
    } while (!(ModAsis.justificacion <= ModAsis.falta));
    ModAsis.asistencia = 25 - ModAsis.falta;
    fflush(stdin);
}

void mostrarModuloAsistencia(ModuloAsistencia &ModAsis) {
    cout << "\t----------------------------------" << endl;
    cout << "\tFecha: " << TablaMeses[ModAsis.mes - 1] << " - " << ModAsis.anio << endl;
    cout << "\tAsistencia: " << ModAsis.asistencia << endl;
    cout << "\tFalta(s): " << ModAsis.falta << endl;
    cout << "\tTardanza(s): " << ModAsis.tardanza << endl;
    cout << "\tJustificacion(es): " << ModAsis.justificacion << endl;
    cout << "\t----------------------------------" << endl;
}

struct ListaModuloAsistencia {
    ModuloAsistencia *datos;
    int num, maximo;
};

void iniciaListaModuloAsistencia(ListaModuloAsistencia &lstModAsis) {
    lstModAsis.datos = NULL;
    lstModAsis.num = 0;
    lstModAsis.maximo = 0;
}

void creceListaModuloAsistencia(ListaModuloAsistencia &lstModAsis) {
    ModuloAsistencia *temp;
    temp = new ModuloAsistencia[lstModAsis.maximo+DELTA];
    for (int i = 0; i < lstModAsis.num; i++) {
        temp[i] = lstModAsis.datos[i];
    }
    delete []lstModAsis.datos;
    lstModAsis.datos = temp;
    lstModAsis.maximo += DELTA;
}

void insertaModuloAsistencia(ListaModuloAsistencia &lstModAsis, ModuloAsistencia &ModAsis) {
    if(lstModAsis.num == lstModAsis.maximo) {
        creceListaModuloAsistencia(lstModAsis);
    }
    lstModAsis.datos[lstModAsis.num] = ModAsis;
    lstModAsis.num++;
}

void leeListaModuloAsistencia(ListaModuloAsistencia &lstModAsis) {
    ModuloAsistencia ModAsis;
    iniciaModuloAsistencia(ModAsis);
    leeModuloAsistencia(ModAsis);
    insertaModuloAsistencia(lstModAsis, ModAsis);
}

void mostrarListaModuloAsistencia(ListaModuloAsistencia &lstModAsis) {
    cout << "\n\tLISTA DE ASISTENCIA: \n";
    for(int i = 0; i < lstModAsis.num; i++) {
        mostrarModuloAsistencia(lstModAsis.datos[i]);
    }
}

void liberarListaModuloAsistencia(ListaModuloAsistencia &lstModAsis) {
    delete []lstModAsis.datos;
}

//-----------------------------  SUELDO  --------------------------//

struct Sueldo {
    int anio;
    int mes;
    float asignacionFamiliar;
    float descuento;
    float sueldoNeto;
    float bonificacion;
};

void iniciaSueldo(Sueldo &Sue) {
    Sue.anio = 0;
    Sue.mes = 0;
    Sue.asignacionFamiliar = 0.0;
    Sue.descuento = 0.0;
    Sue.sueldoNeto = 0.0;
    Sue.bonificacion = 0.0;
}

void leeSueldo(Sueldo &Sue) {
    interfazmenu("DATOS DEl SUELDO");
    cout << endl;
    fflush(stdin);
    Sue.anio = ANIOACTUAL;
    Sue.mes = MESACTUAL;
    cout << endl;
    Sue.bonificacion = leeReal("\tIngrese bonificacion del mes: ",0,1000);
}


void mostrarSueldo(Sueldo &Sue) {
    cout << "\t----------------------------------" << endl;
    cout << "\tFecha: " << TablaMeses[Sue.mes - 1] << " - " << Sue.anio << endl;
    cout << "\tAsignacion Familiar: " << Sue.asignacionFamiliar << endl;
    cout << "\tBonificacion: " << Sue.bonificacion << endl;
    cout << "\tDescuento: " << Sue.descuento << endl;
    cout << "\tSueldo Neto: " << Sue.sueldoNeto << endl;
    cout << "\t----------------------------------" << endl;
}

struct ListaSueldo {
    Sueldo *datos;
    int num, maximo;
};

void iniciaListaSueldo(ListaSueldo &lstSueldo) {
    lstSueldo.datos = NULL;
    lstSueldo.maximo = 0;
    lstSueldo.num = 0;
}

void creceListaSueldo(ListaSueldo &lstSueldo) {
    Sueldo *temp;
    temp = new Sueldo[lstSueldo.maximo+DELTA];
    for (int i = 0; i < lstSueldo.num; i++) {
        temp[i] = lstSueldo.datos[i];
    }
    delete []lstSueldo.datos;
    lstSueldo.datos = temp;
    lstSueldo.maximo += DELTA;
}

void insertaSueldo(ListaSueldo &lstSueldo, Sueldo &Sue) {
    if(lstSueldo.num == lstSueldo.maximo) {
        creceListaSueldo(lstSueldo);
    }
    lstSueldo.datos[lstSueldo.num] = Sue;
    lstSueldo.num++;
}

void leeListaSueldo(ListaSueldo &lstSueldo) {
    Sueldo Sue;
    iniciaSueldo(Sue);
    leeSueldo(Sue);
    insertaSueldo(lstSueldo, Sue);
}

void mostrarListaSueldo(ListaSueldo &lstSueldo) {
    cout << "\n\tLISTA DE SUELDOS: \n";
    for(int i = 0; i < lstSueldo.num; i++) {
        mostrarSueldo(lstSueldo.datos[i]);
    }
}

void liberarListaSueldo(ListaSueldo &lstSueldo) {
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
    system("cls");
    interfazmenu("DATOS DEL CARGO");
    cout << endl;
    cout << "\tGrupos Ocupacionales: " << endl;
    Carg.grupoOcupacional = validaTabla("Seleccione: ", TablaGrupoOcupacional, MAXTABLAGRUPOOCUPACIONAL);

    cout << "\tClase de cargo: " << endl;
    if (Carg.grupoOcupacional == 1) {
        Carg.claseDeCargo = validaTabla("Seleccione: ", TablaDirectorSuperior, MAXTABLADIRECTORSUPERIOR);
    } else if (Carg.grupoOcupacional == 2) {
        Carg.claseDeCargo = validaTabla("Seleccione: ", TablaEjecutivo, MAXTABLAEJECUTIVO);
    } else if (Carg.grupoOcupacional == 3) {
        Carg.claseDeCargo = validaTabla("Seleccione: ", TablaEspecialista, MAXTABLAESPECIALISTA);
    } else {
        Carg.claseDeCargo = validaTabla("Seleccione: ", TablaApoyo, MAXTABLAAPOYO);
    }
}

void mostrarCargo(Cargo &Carg) {
    cout << "\n\tCARGO" << endl;
    cout << "\tGrupo Ocupacional: " << TablaGrupoOcupacional[Carg.grupoOcupacional-1]<< endl;
    if (Carg.grupoOcupacional == 1) {
        cout << "\tCargo: " << TablaDirectorSuperior[Carg.claseDeCargo -1] << endl ;
    } else if (Carg.grupoOcupacional == 2) {
        cout << "\tCargo: " << TablaEjecutivo[Carg.claseDeCargo -1] << endl;
    } else if (Carg.grupoOcupacional == 3) {
        cout << "\tCargo: " << TablaEspecialista[Carg.claseDeCargo -1] << endl;
    } else {
        cout << "\tCargo: " << TablaApoyo[Carg.claseDeCargo -1] << endl;
    }
}


//-----------------------------  CONTRATO  ------------------------//

struct Contrato {
    int horario;
    int banco;
    int tipoTrabajador;
    float sueldoBase;
    Fecha inicioContrato;
    Fecha finContrato;
    Cargo cargo;
};

void iniciaContrato(Contrato &Contr) {
    Contr.horario = 0;
    Contr.banco = 0;
    Contr.tipoTrabajador = 0;
    Contr.sueldoBase = 0.0;
    iniciaFecha(Contr.inicioContrato);
    iniciaFecha(Contr.finContrato);
    iniciaCargo(Contr.cargo);
}

void leeContrato(Contrato &Contr) {
    Fecha auxFechaActual;
    auxFechaActual.Anio = ANIOACTUAL;
    auxFechaActual.Mes = MESACTUAL;
    auxFechaActual.Dia = DIAACTUAL;
    fflush(stdin);
    system("cls");
    interfazmenu("DATOS DEL CONTRATO");
    cout << endl;
    cout << "\tHorario: " << endl;
    Contr.horario = validaTabla("Seleccione: ", TablaHorario, MAXTABLAHORARIO);
    Contr.sueldoBase = leeReal("\tSalario base: ",930,8000);

    cout << "\tBancos: " << endl;
    Contr.banco = validaTabla("Seleccione: ", TablaBanco, MAXTABLABANCO);

    cout << "\tTipos de trabajadores: " << endl;
    Contr.tipoTrabajador = validaTabla("Seleccione: ", TablaTipoTrabajador, MAXTABLATIPOTRABAJADOR);

    do {
        cout << "\tInicio de contrato: ";
        leeFecha(Contr.inicioContrato);
    } while (!(ComparaFechas(Contr.inicioContrato,auxFechaActual) != -1));

    do {
        cout << "\tFin de contrato: ";
        leeFecha(Contr.finContrato);
        } while (!(ComparaFechas(Contr.finContrato,Contr.inicioContrato) != -1 || ComparaFechas(Contr.finContrato,Contr.inicioContrato) == -1));

        leeCargo(Contr.cargo);
    }

void mostrarContrato(Contrato &Contr) {
    cout << "\n\tCONTRATO" << endl;
    cout << "\tHorario: " << TablaHorario [Contr.horario - 1] << endl;
    cout << "\tSalario Base: " << Contr.sueldoBase << endl;
    cout << "\tBanco: " << TablaBanco[Contr.banco - 1] <<endl;
    cout << "\tTipo de trabajador: " << TablaTipoTrabajador[Contr.tipoTrabajador - 1] << endl;
    cout << "\tInicio de contrato: ";
    MostrarFecha(Contr.inicioContrato);
    cout << endl;
    cout << "\tFin del contrato: ";
    MostrarFecha(Contr.finContrato);
    cout << endl;
    mostrarCargo(Contr.cargo);
}

// ------------------------- PAGOS -------------------------------//

struct Pagos {
    ListaModuloAsistencia listaAsistencia;
    ListaSueldo listaSueldo;
};

void iniciaPagos(Pagos &pagos) {
    iniciaListaModuloAsistencia(pagos.listaAsistencia);
    iniciaListaSueldo(pagos.listaSueldo);
}

void mostrarPagos(Pagos &pagos) {
    mostrarListaModuloAsistencia(pagos.listaAsistencia);
    mostrarListaSueldo(pagos.listaSueldo);
}

//-------------------------  TRABAJADOR  --------------------------//

struct Trabajador {
    char dni[MAXDNI];
    char nombre[LIM];
    int fondoPensiones;
    int nroHijos;
    int estadoCivil;
    int gradoInstruccion;
    char codigo[MAXCODIGO];

    Direccion direccion;
    Contrato contrato;
    Pagos pagos;
};

void iniciaTrabajador(Trabajador &Trab) {
    Trab.dni[0] = NULL;
    Trab.nombre[0] = NULL;
    Trab.fondoPensiones = 0;
    Trab.nroHijos = 0;
    Trab.estadoCivil = 0;
    Trab.gradoInstruccion = 0;
    Trab.codigo[0] = NULL;

    iniciaDireccion(Trab.direccion);
    iniciaContrato(Trab.contrato);
    iniciaPagos(Trab.pagos);
}

void leeTrabajador(Trabajador &Trab) {
    system("cls");
    interfazmenu("DATOS GENERALES");
    cout << endl;
    fflush(stdin);
    leeTextoComoNumero("\tDNI",Trab.dni, MAXDNI);
    fflush(stdin);
    cout << "\tNombre Completo: ";
    cin.getline(Trab.nombre,LIM);
    fflush(stdin);

    cout << "\tSistemas de Fondo de Pensiones: " << endl;
    Trab.fondoPensiones = validaTabla("Seleccione: ",TablaFomdoPensiones,MAXTABLAFONDOPENSIONES);

    Trab.nroHijos = leeEntero("\tNumero de hijos: ", 0, 15);

    cout << "\tEstado Civil: " << endl;
    Trab.estadoCivil = validaTabla("Seleccione: ",TablaEstadoCivil, MAXTABLAESTADOCIVIL);

    cout << "\tGrados de Instruccion: " << endl;
    Trab.gradoInstruccion = validaTabla("Seleccione: ", TablaGradoInstruccion, MAXTABLAGRADOINSTRUCCION);
    fflush(stdin);

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
    fflush(stdin);
    cout << "\n\tDATOS GENERALES" << endl;
    cout << "\tDNI: " << Trab.dni << endl;
    cout << "\tNombre Completo: " << Trab.nombre << endl;
    cout << "\tSitema de Fondo de Pension: " << TablaFomdoPensiones[Trab.fondoPensiones - 1] << endl;
    cout << "\tNumero de hijos: " << Trab.nroHijos << endl;
    cout << "\tEstado Civil: " << TablaEstadoCivil[Trab.estadoCivil - 1] << endl;
    cout << "\tGrado de Instruccion: " <<  TablaGradoInstruccion[Trab.gradoInstruccion - 1] << endl;
    cout << "\tCodigo: " << Trab.codigo << endl;
    mostrarDireccion(Trab.direccion);
    mostrarContrato(Trab.contrato);
    if (Trab.pagos.listaAsistencia.num != 0)
        mostrarPagos(Trab.pagos);
    else
        cout << "\tEl trabajador aun no resgistra asistencia ni pagos";

}

struct NodoTrabajador {
    Trabajador trab;
    NodoTrabajador *sgte;
};

struct ListaTrabajador {
    NodoTrabajador *cab;
    int numTrabaj;
};

void iniciaListaTrabajador(ListaTrabajador &lstTrab) {
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
    } while (continuar("\n\tDesea registrar otro empleado? (S/N): ") == 'S');
    fflush(stdin);
}

void mostrarListaTrabajador(ListaTrabajador &lstTrab) {
    int i = 1;
    system("cls");
    interfazmenu("LISTA DE TRABAJADORES");
    for(NodoTrabajador *Aux = lstTrab.cab; Aux != NULL; Aux = Aux->sgte) {
        cout << "\n\n\t\t::TRABAJADOR "<< i++ << ":: \n";
        mostrarTrabajador(Aux->trab);
    }
}

void liberarTrabajador(ListaTrabajador &lstTrab) {
    NodoTrabajador *Aux = lstTrab.cab;
    while (Aux != NULL) {
        lstTrab.cab = Aux->sgte;
        liberarListaSueldo(Aux->trab.pagos.listaSueldo);
        liberarListaModuloAsistencia(Aux->trab.pagos.listaAsistencia);
        delete [] Aux;
        Aux = lstTrab.cab;
    }
}
