#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <stdlib.h>
#include <ctype.h>
#include <string>
#include <time.h>
#include <windows.h>

using namespace std;
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

char TSexo[MAXSEXO][LIM]= {"Masculino","Femenino"};

// operacions basicas de datos simples

int leeEntero(string msje, int min, int max) {
    char numero[50];
    int longitudNumero, i, numeroValidado;
    bool band = 0;

    do {
        band = 0;
        i = 0;

        cout << msje;
        cin.getline(numero,50);

        longitudNumero = strlen(numero);
        while ( i< longitudNumero && band==0) {
            if (isdigit(numero[i]) != 0) {
                i++;
            } else {
                band = 1;
                cout << "\nERROR SOLO INGRESE NUMEROS";
            }
        }

        if (band == 0) {
            numeroValidado = atoi(numero);
            if(numeroValidado<min || numeroValidado>max) {
                cout<<"\nERROR INGRESE NUMERO NUEVAMENTE\n";
            }
        }

    } while (!(band == 0 && (numeroValidado>=min && numeroValidado<=max)));

    return numeroValidado;
}

int leeEnteroExacto(int exacto) {
    char numero[50];
    int longitudNumero, i, numeroValidado;
    bool band = 0;

    do {
        band = 0;
        i = 0;

        cin.getline(numero,50);

        longitudNumero = strlen(numero);
        while ( i< longitudNumero && band==0) {
            if (isdigit(numero[i]) != 0) {
                i++;
            } else {
                band = 1;
                cout << "\nERROR SOLO INGRESE NUMEROS";
            }
        }

        if (band == 0) {
            numeroValidado = atoi(numero);
            if(strlen(numeroValidado)!=exacto) {
                cout<<"\nERROR INGRESE NUMERO NUEVAMENTE\n";
            }
        }

    } while (!(band == 0 && (strlen(numeroValidado)==exacto)));

    return numeroValidado;

}

float leeReal(string msje, int min, int max) {
    char numero[50];
    int longitudNumero, i;
    bool band = 0;
    float numeroValidado;

    do {
        band = 0;
        i = 0;

        cout << msje;
        cin.getline(numero,50);

        longitudNumero = strlen(numero);

        while ( i< longitudNumero && band==0) {
            if (isdigit(numero[i]) != 0) {
                i++;
            } else {
                band = 1;
                cout << "\nERROR SOLO INGRESE NUMEROS";
            }
        }

        if (band == 0) {
            numeroValidado = atof(numero);
            if(numeroValidado<min || numeroValidado>max) {
                cout<<"\nERROR INGRESE NUMERO NUEVAMENTE\n";
            }
        }

    } while (!(band == 0 && (numeroValidado>=min && numeroValidado<=max)));

    return numeroValidado;
}


char leeDNI(string msje, char dniValidado[]) {
    char dni[50];
    int longitudDni,i;
    bool band = 0;

    do {
        band = 0;
        i = 0;

        cout << endl << msje;
        cin.getline(dni,50);

        longitudDni = strlen(dni);

        if (longitudDni != 8) {
            cout << "ERROR EL DNI TIENE OCHO CARACTERES";
            band = 1;
        }

        while ( i < longitudDni && band==0) {
            if (isdigit(dni[i]) != 0) {
                i++;
            } else {
                band = 1;
                cout << "ERROR SOLO INGRESE NUMEROS";
            }
        }
    } while (!(band == 0));

    strcpy(dniValidado, dni);
}

//operaciones de vector enteros

void iniciaVE(int V[], int m) {
    for(int i=0; i<m; i++)
        V[i]=0;
}

//operaciones de vector reales
void iniciaVR(float V[], int m) {
    for(int i=0; i<m; i++)
        V[i]=0.0;
}

//operaciones de Tablas

void iniciaTabla(char T[][LIM], int m) {
    for(int i=0; i<m; i++)
        T[i][0]=NULL;
}

int validaTabla(string msje, char T[][LIM], int tam) {
    int opc;

    for(int i=0; i<tam; i++) {
        cout<<i+1<<": "<<T[i]<<endl;
    }
    opc=leeEntero(msje, 1, tam);
    return opc;
}

char continuar (string msje[]) {
    char rpta;
    do {
        cout<<msje;
        fflush(stdin);
        cin>>rpta;
        rpta= toupper(rpta);
    } while(!(rpta=='S' || rpta== 'N'));
    return rpta;
}

// FUNCIONES DE FECHA
time_t fecha = time(0);
tm *fechaActual = localtime(&fecha);
int ANIOACTUAL = 1900 + fechaActual->tm_year;
int MESACTUAL = fechaActual->tm_mon;
int DIAACTUAL = fechaActual->tm_mday;

struct Fecha {
    int Dia = DIAACTUAL;
    int Mes = MESACTUAL;
    int Anio = ANIOACTUAL;
};

void MostrarFecha(Fecha &FV) {
    cout << endl << FV.Dia << "/" << FV.Mes << "/" << FV.Anio;
}

/*La función Comparafechas, permite compara 2 fechas dadas: F y FP, retornando lo siguiente:
= 0, si las 2 fechas son iguales
= 1, si F es mayor que FP
= -1, si F es menor que FP
 */
int ComparaFechas(Fecha &F, Fecha &FP) {
    if(F.Anio > FP.Anio)
        return 1;
    else if(F.Anio < FP.Anio)
        return -1;
    else if(F.Mes > FP.Mes)
        return 1;
    else if(F.Mes < FP.Mes)
        return -1;
    else if(F.Dia > FP.Dia)
        return 1;
    else if(F.Dia < FP.Dia)
        return -1;
    else
        return 0;
}

//FUNCIONES PARA DIBUJAR
void gotoxy(int x, int y) {
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hCon,dwPos);
}

void PintarCuadrado(int x1,int y1,int x2,int y2) {

    int i;
    for (i=x1; i<x2; i++) {
        gotoxy(i,y1);
        printf("%c",205);//linea horizontal superior
        gotoxy(i,y2);
        printf("%c",205);//linea horizontal inferior
    }

    for (i=y1; i<y2; i++) {
        gotoxy(x1,i);
        printf("%c",186);//linea vertical izquierda
        gotoxy(x2,i);
        printf("%c",186);//linea vertical derecha
    }
    gotoxy(x1,y1); printf("%c",201);//Esquina Superior Izquierda
    gotoxy(x1,y2); printf("%c",200);//Esquina inferior Izquierda
    gotoxy(x2,y1); printf("%c",187);//Esquiza Superior Derecha
    gotoxy(x2,y2); printf("%c",188);//Esquina Inferior Derecha
}

//FUNCION LIMPIAR PANTALLA
void limpia() {
    int i,j;
    for(i=5; i<=23; i++) {
        for(j=3; j<=76; j++) {
            gotoxy(j,i);
            printf(" ");
        }
    }
}

// FUNCION PARA OCULTAR EL CURSOR
void CursorOff() {
    CONSOLE_CURSOR_INFO cursor = {1, FALSE};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}

//FUNCION PARA APARECER EL CURSOR
void CursorOn(bool visible, DWORD size) { // set bool visible = 0 - invisible, bool visible = 1 - visible
    if(size == 0) {
        size = 20;	// default cursor size Changing to numbers from 1 to 20, decreases cursor width
    }
    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = visible;
    lpCursor.dwSize = size;
    SetConsoleCursorInfo(console,&lpCursor);
}