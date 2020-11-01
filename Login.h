
void login();
void leerContrasenia(char contrasenia);

void mainLogin(){
    system("mode con: cols=80 lines=25");
    system("COLOR B0");
    dibujarCuadro(0,0,78,24);//Cuadro grande
	dibujarCuadro(1,1,77,3);//Cuadro del titulo
	gotoxy(16,2); cout << "               T I T U L O";
	login();
}

void login(){
    char usuario[] = "Admin";
    char contrasenia[] = "Admin123";
    char auxUsuario[LIM], auxContrasenia[LIM];

    gotoxy(35,6); cout << "LOGIN";
	dibujarCuadro(18,9,60,15);
	gotoxy(23,11); cout << "Usuario: ";
	cin.getline(auxUsuario, LIM);

	gotoxy(23,13); printf("Clave:   ");
	leerContrasenia(auxContrasenia);

}
