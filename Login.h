
void login();
void leerContrasenia(char contrasenia[]);

void mainLogin() {
    system("mode con: cols=80 lines=25");
    system("COLOR B0");
    PintarCuadrado(0,0,78,24);//Cuadro grande
    PintarCuadrado(1,1,77,4);//Cuadro del titulo
    CursorOff();
    gotoxy(25,2);
    cout << "SISTEMA DE RECURSOS HUMANOS";
    gotoxy(21,3);
    cout << "MUNICIPALIDAD DISTRITAL DE CHICLAYO";

    login();
}

void login() {
    CursorOn(1,10);
    char usuario[] = "Admin";
    char contrasenia[] = "Admin123";
    char auxUsuario[LIM], auxContrasenia[LIM];
    int f = 41;

    gotoxy(35,6);
    cout << "LOGIN";
    PintarCuadrado(18,9,60,15);
    gotoxy(23,11);
    cout << "Usuario: ";
    cin.getline(auxUsuario, LIM);

    gotoxy(23,13);
    printf("Clave:   ");
    leerContrasenia(auxContrasenia);
    CursorOff();

    for(int i = 0; i < 3; i++ ) {
        gotoxy(33,19);
        cout << "Cargando";
        gotoxy(f,19);
        cout << ".";
        f+=1;
        Sleep(700);
    }
    f=51;

    if ((strcmp(auxUsuario, usuario)) == 0 && (strcmp(auxContrasenia, contrasenia)) == 0) {
        gotoxy(30,19);
        cout << "                                     ";
        for(int i = 0; i < 3; i++ ) {
            gotoxy(30,19);
            cout << "Accediendo al Sistema";
            gotoxy(f,19);
            cout << ".";
            f+=1;
            Sleep(700);
        }
        limpia();
        //debe ir la de retorno
    } else {
        gotoxy(35,19);
        cout << "                                     ";
        gotoxy(30,19);
        cout << "Datos incorrectos";
        gotoxy(18,20);
        cout << "Presione una tecla para volver a ingresar..";
        getch();
        limpia();
        login();
    }
}

void leerContrasenia(char contrasenia[]) {
    int i=0;
    cout.flush();
    int aux=0;

    do {
        contrasenia[i] = (unsigned char)getch();
        if(contrasenia[i]!=8) { // no es retroceso
            cout << '*';  // muestra por pantalla
            i++;
            if (contrasenia[i-1]==13) {
                printf("\b \b");
            }
        }

        else if(i>0) {  // es retroceso y hay caracteres
            cout << (char)8 << (char)32 << (char)8;
            i--;  //el caracter a borrar e el backspace
        }
        cout.flush();
    } while(contrasenia[i-1]!=13);  // si presiona ENTER

    contrasenia[i-1] = 0;
}
