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
    fflush(stdin);
    cout << "Calle: ";
    cin.getline(Dir.calle, LIM);
    fflush(stdin);
    cout << "Distrito: ";
    cin.getline(Dir.distrito, LIM);
    fflush(stdin);
    cout << "Provincias: ";
    //Dir.provincia = validaTabla("\nSeleccione: ",  , MAXTABLAPROVINCIA);
    fflush(stdin);
}

void mostrarDireccion(Direccion &Dir) {
    cout << "Calle: " << Dir.calle;
    cout << "Distrito: " << Dir.distrito;
    cout << "Provincia: " << endl;//tablaprovincia-1;
}

//------------------------  MODULO ASISTENCIA  --------------------//

struct ModuloAsistencia {
    int asistencia;
    int falta;
    int tardanza;
    int justificacion;
};

void iniciaModuloAsistencia(ModuloAsistencia &ModAsis) {
    ModAsis.asistencia = 0;
    ModAsis.falta = 0;
    ModAsis.tardanza = 0;
    ModAsis.justificacion = 0;
}

void leeAsistencia(ModuloAsistencia &ModAsis) {
    fflush(stdin);
    cout << "Asistencia: ";
    ModAsis.asistencia = leeEntero(0, 31);
    cout << "Falta(s): ";
    ModAsis.falta = leeEntero(0, 31);
    cout << "Tardanza(s): ";
    ModAsis.tardanza = leeEntero(0, 31);
    cout << "Justificacion(es): ";
    ModAsis.justificacion = leeEntero(0, 31);
    fflush(stdin);
}

void mostrarModuloAsistencia(ModuloAsistencia &ModAsis) {
    cout << "Asistencia: " << ModAsis.asistencia;
    cout << "Falta(s): " << ModAsis.falta;
    cout << "Tardanza(s): " << ModAsis.tardanza;
    cout << "Justificacion(es): " << ModAsis.justificacion;
}

//-----------------------------  SUELDO  --------------------------//

struct Sueldo {
    float sueldoBase;
    float asignacionFamiliar;
    float descuento;
    float sueldoNeto;
};

void iniciaSueldo(Sueldo &Sue) {
    Sue.sueldoBase = 0.0;
    Sue.asignacionFamiliar = 0.0;
    Sue.descuento = 0.0;
    Sue.sueldoNeto = 0.0;
}
//solo llamar a esta funcion cuando ya ha cumplido 1 mes como mínimo
float leeSueldo(Sueldo &Sue) {
    fflush(stdin);
    cout << "Sueldo Base: ";
    Sue.sueldoBase = leeReal(SUELDOMINIMO, MAXSUELDOBASE);

    Sue.sueldoNeto = Sue.sueldoBase+Sue.asignacionFamiliar-Sue.descuento;
    return Sue.sueldoNeto;
}


void mostrarSueldo(Sueldo &Sue) {
    cout << "Sueldo Base: " << Sue.sueldoBase;
    cout << "Asignacion Familiar: " << Sue.asignacionFamiliar;
    cout << "Descuento: " << Sue.descuento;
    cout << "Sueldo Neto: " << Sue.sueldoNeto;
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
    cout << "Grupos Ocupacionales: ";
//    Carg.grupoOcupacional = validaTabla("\nSeleccione: ", , MAXTABLAGRUPOOCUPACIONAL);

    cout << "Clase de cargo: ";
    Carg.claseDeCargo = leeEntero(1, MAXCLASEDECARGO);
}

void mostrarCargo(Cargo &Carg) {
    cout << "Grupo Ocupacional: " << endl;//tablagrupoocupacional;
    cout << "Clase de cargo: " << Carg.claseDeCargo;
}

//-----------------------------  CONTRATO  ------------------------//

struct Contrato {
    int horario;
    char nroCuenta[MAXNROCUENTA];
    char cci[MAXCCI];
    int banco;
    int tipoTrabajador;
    Fecha inicioContrato;
    Fecha finContrato;
    Cargo cargo;
    Sueldo sueldo;
};

void iniciaContrato(Contrato &Contr) {
    Contr.horario = 0;
    Contr.nroCuenta[0] = NULL;
    Contr.cci[0] = NULL;
    Contr.banco = 0;
    Contr.tipoTrabajador = 0;
    iniciaFecha(Contr.inicioContrato);
    iniciaFecha(Contr.finContrato);
    iniciaCargo(Contr.cargo);
    iniciaSueldo(Contr.sueldo);
}

void leeContrato(Contrato &Contr) {
    fflush(stdin);
    cout << "Horario: ";
//    Contr.horario = validaTabla("\nSeleccione: ", , MAXTABLAHORARIO);

    cout << "Numero de Cuenta: ";
    leeTextoComoNumero("NUMERO DE CUENTA", Contr.nroCuenta, MAXNROCUENTA+1);

    cout << "Codigo de Cuenta Interbancario (CCI): ";
    leeTextoComoNumero("CCI", Contr.cci,MAXCCI);

    cout << "Bancos: ";
//    Contr.banco = validaTabla("\nSeleccione: ", , MAXTABLABANCO);

    cout << "Tipos de trabajadores: ";
//    Contr.tipoTrabajador = validaTabla("\nSeleccione: ", , MAXTABLATIPOTRABAJADOR);

    cout << "Inicio de contrato: ";
    leeFecha(Contr.inicioContrato);

    cout << "Fin de contrato: ";
    leeFecha(Contr.finContrato);

    leeCargo(Contr.cargo);
    leeSueldo(Contr.sueldo);

}

void mostrarContrato(Contrato &Contr) {
    cout << "Horario: " << endl;//tablahorario;
    cout << "Numero de Cuenta: " << Contr.nroCuenta;
    cout << "CCI: " << Contr.cci;
    cout << "Banco: " << endl;//tablabanco-1;
    cout << "Tipo de trabajador: " << endl; //tablatipodetrabajador-1;
    cout << "Inicio de contrato: "; MostrarFecha(Contr.inicioContrato);
    cout << "Fin del contrato: "; MostrarFecha(Contr.finContrato);
    mostrarCargo(Contr.cargo);
    mostrarSueldo(Contr.sueldo);
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
    ModuloAsistencia asistencia;
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
    iniciaModuloAsistencia(Trab.asistencia);
}

void leeTrabajador(Contrato &Contr, Trabajador &Trab) {
    cout << "DNI: ";
    leeTextoComoNumero("DNI",Trab.dni, MAXDNI);
    fflush(stdin);
    cout << "Nombre Completo: ";
    cin.getline(Trab.nombre,LIM);
    fflush(stdin);
    cout << "RUC: ";
    leeTextoComoNumero("RUC", Trab.ruc, MAXRUC);

    cout << "Telefono: ";
    leeTextoComoNumero("TELEFONO", Trab.telefono,MAXTELEFONO);

    cout << "Sistemas de Fondo de Pensiones: " << endl;
//    Trab.fondoPensiones = validaTabla("\nSeleccione: ",,MAXTABLAFONDOPENSIONES);

    cout << "Numero de hijos: "<<endl;
    Trab.nroHijos = leeEntero(0, 15);

    cout << "Estado Civil: " << endl;
//    Trab.estadoCivil = validaTabla("\nSeleccione: ",, MAXTABLAESTADOCIVIL);

    cout << "Grados de Instruccion: ";
//    Trab.gradoInstruccion = validaTabla("\nSeleccione: ",, MAXTABLAGRADOINSTRUCCION);
    fflush(stdin);
    cout << "Correo: ";
    cin.getline(Trab.correo, LIM);
    fflush(stdin);

    int anio = Contr.inicioContrato.Anio;
    char codigoFK[MAXCODIGO];
    itoa(anio, codigoFK, 10);

    char b[MAXDNI];
    strcpy(b,Trab.dni);

    strcat (codigoFK, b);


    leeDireccion(Trab.direccion);
    leeContrato(Trab.contrato);
    leeAsistencia(Trab.asistencia);
}

void mostrarTrabajador(Trabajador &Trab) {
    cout << "DNI: " << Trab.dni;
    cout << "Nombre Completo: " << Trab.nombre;
    cout << "RUC: " << Trab.ruc;
    cout << "Telefono: " << Trab.telefono;
    cout << "Sitema de Fondo de Pension: " << endl;//tablafondopensiones;
    cout << "Numero de hijos: " << Trab.nroHijos;
    cout << "Estado Civil: " << endl;//tablaestadocivil;
    cout << "Grado de Instruccion: " << endl;//tablagradodeinstruccion;
    cout << "Correo: " << Trab.correo;
    cout << "Codigo: " << Trab.codigo;

    mostrarDireccion(Trab.direccion);
    mostrarContrato(Trab.contrato);
    mostrarModuloAsistencia(Trab.asistencia);
}
