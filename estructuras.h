
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

struct Cargo {
    int grupoOcupacional;
    int claseDeCargo;
};

void iniciaCargo(Cargo &Carg) {
    Carg.grupoOcupacional = 0;
    Carg.claseDeCargo = 0;
}

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
    //time inicioCobro;
    //time finContrato;


    Contr.ecargo = NULL;
    Contr.esueldo = NULL;
}

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

    Direccion *edireccion;
    Contrato *econtrato;
    ModuloAsistencia *easistencia;
};

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

    Trab.edireccion = NULL;
    Trab.econtrato = NULL;
    Trab.easistencia = NULL;
}














void leeTrabajador(Trabajador &Trab) {
    cout << "DNI: ";
    cin.getline(Trab.dni,MAXDNI);

    cout << "Nombre Completo: ";
    cin.getline(Trab.nombre,LIM);

    cout << "RUC: ";
    cin.getline(Trab.ruc, MAXRUC);

    cout << "Telefono: ";
    cin.getline(Trab.telefono, MAXTELEFONO);

    cout << "Sistemas de Fondo de Pensiones: " << endl;
    Trab.fondoPensiones = validaTabla("\nSeleccione: ",,MAXTABLAFONDOPENSIONES);

    cout << "Numero de hijos: "<<endl;
    Trab.nroHijos = leeEntero(" ", 0, 15);

    cout << "Estado Civil: " << endl;
    Trab.estadoCivil = validaTabla("\nSeleccione: ",, MAXTABLAESTADOCIVIL);

    cout << "Grados de Instruccion: ";
    Trab.gradoInstruccion = validaTabla("\nSeleccione: ",, MAXTABLAGRADOINSTRUCCION);

    cout << "Correo: ";
    cin.getline(Trab.correo, LIM);

    //faltan asignar Trab.codigo además de las funciones de leedireccion leecontrato y leeasistencia

    leeDireccion();
    leeContrato();
    leeAsistencia();


}

void leeDireccion(Direccion &Dir) {
    cout << "Calle: ";
    cin.getline(Dir.calle, LIM);

    cout << "Distrito: ";
    cin.getline(Dir.distrito, LIM);

    cout << "Provincias: ";
    Dir.provincia = validaTabla("\nSeleccione: ",, MAXTABLAPROVINCIA);
}

void leeContrato(Contrato &Contr) {
    cout << "Horario: ";
    Contr.horario = validaTabla("\nSeleccione: ",, MAXTABLAHORARIO);

    cout << "Numero de Cuenta: ";
    Contr.nroCuenta = leeEnteroExacto(MAXNROCUENTA);

    cout << "Codigo de Cuenta Interbancario (CCI): ";
    Contr.cci = leeEnteroExacto(MAXCCI);

    cout << "Bancos: ";
    Contr.banco = validaTabla("\nSeleccione: ",, MAXTABLABANCO);

    cout << "Tipos de trabajadores: ";
    Contr.tipoTrabajador = validaTabla("\nSeleccione: ",, MAXTABLATIPOTRABAJADOR);

    //time

    leeCargo();
    leeSueldo();

}

void leeCargo(Cargo &Carg) {
    cout << "Grupos Ocupacionales: ";
    Carg.grupoOcupacional = validaTabla("\nSeleccione: ",, MAXTABLAGRUPOOCUPACIONAL);

    cout << "Clase de cargo: ";
    Carg.claseDeCargo = leeEntero(" ", 1, MAXCLASEDECARGO);
}

float leeSueldo(Sueldo &Sue) {
    cout << "Sueldo Base: ";
    Sue.sueldoBase = leeReal(" ", SUELDOMINIMO, MAXSUELDOBASE);

    Sue.sueldoNeto = Sue.sueldoBase+Sue.asignacionFamiliar-Sue.descuento;
    return Sue.sueldoNeto;
}

//solo llamar a esta funcion cuando ya ha cumplido 1 mes como mínimo
void leeAsistencia(ModuloAsistencia &ModAsis) {
    cout << "Asistencia: ";
    ModAsis.asistencia = leeEntero(" ", 0, 31);
    cout << "Falta(s): ";
    ModAsis.falta = leeEntero(" ", 0, 31);
    cout << "Tardanza(s): ";
    ModAsis.tardanza = leeEntero(" ", 0, 31);
    cout << "Justificacion(es): ";
    ModAsis.justificacion = leeEntero(" ", 0, 31);
}

void mostrarTrabajador(Trabajador &Trab) {
    cout << "DNI: " << Trab.dni;
    cout << "Nombre Completo: " << Trab.nombre;
    cout << "RUC: " << Trab.ruc;
    cout << "Telefono: " << Trab.telefono;
    cout << "Sitema de Fondo de Pension: " << //tablafondopensiones;
         cout << "Numero de hijos: " << Trab.nroHijos;
    cout << "Estado Civil: " << //tablaestadocivil;
         cout << "Grado de Instruccion: " << //tablagradodeinstruccion;
         cout << "Correo: " << Trab.correo;
    cout << "Codigo: " << Trab.codigo;

    mostrarDireccion();
    mostrarContrato();
    mostrarModuloAsistencia();
}

void mostrarDireccion(Direccion &Dir) {
    cout << "Calle: " << Dir.calle;
    cout << "Distrito: " << Dir.distrito;
    cout << "Provincia: " << //tablaprovincia-1;
}

void mostrarContrato(Contrato &Contr) {
    cout << "Horario: " << //tablahorario;
         cout << "Numero de Cuenta: " << Contr.nroCuenta;
    cout << "CCI: " << Contr.cci;
    cout << "Banco: " << //tablabanco-1;
         cout << "Tipo de trabajador: " << //tablatipodetrabajador-1;
         cout << "Inicio de cobro: " << //time;
         cout << "Fin del contrato: " << //time;

         mostrarCargo();
    mostrarSueldo();
}

void mostrarCargo(Cargo &Carg) {
    cout << "Grupo Ocupacional: " << //tablagrupoocupacional;
         cout << "Clase de cargo: " << //tablaclasedecargo;
}

void mostrarSueldo(Sueldo &Sue) {
    cout << "Sueldo Base: " << Sue.sueldoBase;
    cout << "Asignacion Familiar: " << Sue.asignacionFamiliar;
    cout << "Descuento: " << Sue.descuento;
    cout << "Sueldo Neto: " << Sue.sueldoNeto;
}

void mostrarModuloAsistencia(ModuloAsistencia &ModAsis) {
    cout << "Asistencia: " << ModAsis.asistencia;
    cout << "Falta(s): " << ModAsis.falta;
    cout << "Tardanza(s): " << ModAsis.tardanza;
    cout << "Justificacion(es): " << ModAsis.justificacion;
}
