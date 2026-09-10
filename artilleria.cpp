#include <iostream>
#include <conio.h>
#include <cmath>
#include <ctime>
#include <cstdlib> 
#include <windows.h>
#include <string>

using namespace std;
using namespace System;

//art ascci

void titulo(int ancho, int alto) {
    int y_inicio = (alto / 2) - 6;
    int x_titulo = (ancho - 105) / 2;
    if (x_titulo < 0) x_titulo = 0;

    string lineas1[] = {
        "  __   ____  ____  __  __    __    ____  ____  __   __     _  _  _  _  __   ____  __  ____  __    ____ ",
        " / _\\ (  _ \\(_  _)(  )(  )  (  )  (  __)(  _ \\(  ) / _\\   ( \\/ )/ )( \\(  ) (_  _)(  )(  _ \\(  )  (  __)",
        "/    \\ )   /  )(   )( / (_/\\/ (_/\\ ) _)  )   / )( /    \\  / \\/ \\) \\/ (/ (_/\\ )(   )(  ) __// (_/\\ ) _) ",
        "\\_/\\_/(__\\_) (__) (__)\\____/\\____/(____)(__\\_)(__)\\_/\\_/  \\_)(_/\\____/\\____/(__) (__)(__)  \\____/(____)"
    };
    for (int i = 0; i < 4; i++) {
        Console::SetCursorPosition(x_titulo, y_inicio + i);
        cout << lineas1[i];
    }

    int ydeltitulo = y_inicio + 6;

    Console::SetCursorPosition((ancho - 46) / 2, ydeltitulo);
    cout << "Rivales, tendreis que enfrentarse entre si con";
    Console::SetCursorPosition((ancho - 50) / 2, ydeltitulo + 1);
    cout << "sus canones disparando al castillo del adversario.";
    Console::SetCursorPosition((ancho - 46) / 2, ydeltitulo + 2);
    cout << "Su dano dependera de cuando crean que sea buen";
    Console::SetCursorPosition((ancho - 51) / 2, ydeltitulo + 3);
    cout << "momento detener su dado de tiro... tendran dos y el";
    Console::SetCursorPosition((ancho - 36) / 2, ydeltitulo + 4);
    cout << "resultado sera el dano a infligir...";
    Console::SetCursorPosition((ancho - 20) / 2, ydeltitulo + 7);
    cout << "Generales, Suerte :)";

    Console::SetCursorPosition((ancho - 32) / 2, ydeltitulo + 9);
    cout << "[ PRESIONA CUALQUIER TECLA PARA EMPEZAR ]";
}

void canon_peq_der(int x, int y) {
    string lineas[] = {
        "   __       ",
        "  /  \\====* ",
        " /____\\     "
    };
    for (int i = 0; i < 3; i++) {
        Console::SetCursorPosition(x, y + i);
        cout << lineas[i];
    }
}

void canon_peq_izq(int x, int y) {
    string lineas[] = {
        "       __   ",
        " *====/  \\  ",
        "     /____\\ "
    };
    for (int i = 0; i < 3; i++) {
        Console::SetCursorPosition(x, y + i);
        cout << lineas[i];
    }
}

void castillo_peq(int x, int y) {
    string lineas[] = {
        "   |>        |>   ",
        "   |         |    ",
        " _|_|_     _|_|_  ",
        "|     |___|     | ",
        "| [ ]       [ ] | ",
        "|_______________| "
    };
    for (int i = 0; i < 6; i++) {
        Console::SetCursorPosition(x, y + i);
        cout << lineas[i];
    }
}

void explosion(int x, int y) {
    string lineas[] = {
        "                  ",
        "    \\||/   \\||/   ",
        "   -BOOM- -BOOM-  ",
        "    /||\\   /||\\   ",
        "                  ",
        "                  "
    };
    for (int i = 0; i < 6; i++) {
        Console::SetCursorPosition(x, y + i);
        cout << lineas[i];
    }
}

void arbol(int x, int y) {
    string lineas[] = {
        "  /\\  ",
        " /  \\ ",
        "  ||  ",
    };
    for (int i = 0; i < 3; i++) {
        Console::SetCursorPosition(x, y + i);
        cout << lineas[i];
    }
}

//recicle la funcion del game jam, funciona muy similar
int dibujarSuelo(int ancho, int alto) {
    int alturaSuelo = 5;
    int inicioSueloY = alto - alturaSuelo;

    for (int y = inicioSueloY; y < alto; y++) {
        for (int x = 0; x < ancho; x++) {
            Console::SetCursorPosition(x, y);
            if (rand() % 100 < 20) {
                int tipoFlor = rand() % 3;
                if (tipoFlor == 0) Console::ForegroundColor = ConsoleColor::Yellow;
                else if (tipoFlor == 1) Console::ForegroundColor = ConsoleColor::White;
                else Console::ForegroundColor = ConsoleColor::Magenta;

                Console::BackgroundColor = ConsoleColor::DarkGreen;
                cout << "*";
            }
            else {
                Console::BackgroundColor = ConsoleColor::Green;
                cout << " ";
            }
        }
    }
    Console::ResetColor();
    return inicioSueloY;
}

void pantallaMultiplicacion(int ancho, int alto, int dado1, int dado2) {
    system("cls");
    int total = dado1 * dado2;

    int digitosTotal = (total < 10) ? 1 : 2;
    int anchoM1 = 36 + digitosTotal;
    int anchoM2 = 15 + digitosTotal;


    //no hay Ñ :(
    Console::SetCursorPosition((ancho - anchoM1) / 2, alto / 2);
    cout << "El dano que se va a infligir sera '" << total << "'";

    Console::SetCursorPosition((ancho - anchoM2) / 2, (alto / 2) + 1);
    cout << "porque " << dado1 << " * " << dado2 << " = " << total;

    Console::SetCursorPosition((ancho - 36) / 2, (alto / 2) + 3);
    cout << "Presiona una tecla para el ataque...";
    _getch();
}
//cubo

void dibujarCuboRotando(int x, int y, int numeroCentro) {
    // tipo tragamonedas
    // condicion, entonces , sino
    int n1 = (numeroCentro - 3 <= 0) ? (numeroCentro - 2 + 6) : (numeroCentro - 2);
    int n2 = (numeroCentro - 2 <= 0) ? (numeroCentro - 2 + 6) : (numeroCentro - 2);
    int n3 = (numeroCentro - 1 <= 0) ? (numeroCentro - 1 + 6) : (numeroCentro - 1);
    int n5 = (numeroCentro + 1 > 6) ? (numeroCentro + 1 - 6) : (numeroCentro + 1);
    int n6 = (numeroCentro + 2 > 6) ? (numeroCentro + 2 - 6) : (numeroCentro + 2);
    int n7 = (numeroCentro + 3 > 6) ? (numeroCentro + 3 - 6) : (numeroCentro + 3);

    Console::SetCursorPosition(x, y);     cout << "   +---------------+";
    Console::SetCursorPosition(x, y + 1); cout << "   |       " << n1 << "       |";
    Console::SetCursorPosition(x, y + 2); cout << "   |       " << n2 << "       |";
    Console::SetCursorPosition(x, y + 3); cout << "   |       " << n3 << "       |";
    Console::ForegroundColor = ConsoleColor::Cyan;
    Console::SetCursorPosition(x, y + 4); cout << "   |  <<<  " << numeroCentro << "  >>>  |";
    Console::ResetColor();
    Console::SetCursorPosition(x, y + 5); cout << "   |       " << n5 << "       |";
    Console::SetCursorPosition(x, y + 6); cout << "   |       " << n6 << "       |";
    Console::SetCursorPosition(x, y + 7); cout << "   |       " << n7 << "       |";
    Console::SetCursorPosition(x, y + 8); cout << "   +---------------+";
}

//se dibuja pero creo que deberia crear una funcion donde se borre el trazo del stickman para q deje de aparecer un 
//bug visual cuando este saltando
void dibujarStickmanFrame(int x, int y_suelo, int frame) {
    if (frame == 1) {
        Console::SetCursorPosition(x, y_suelo - 3); cout << "  O  ";
        Console::SetCursorPosition(x, y_suelo - 2); cout << " /|\\ ";
        Console::SetCursorPosition(x, y_suelo - 1); cout << " / \\ ";
    }
    else if (frame == 2) {
        Console::SetCursorPosition(x, y_suelo - 5); cout << "  O  ";
        Console::SetCursorPosition(x, y_suelo - 4); cout << " \\|/ ";
        Console::SetCursorPosition(x, y_suelo - 3); cout << " / \\ ";
        Console::SetCursorPosition(x, y_suelo - 2); cout << "     ";
        Console::SetCursorPosition(x, y_suelo - 1); cout << "     ";
    }
    else if (frame == 3) {
        Console::ForegroundColor = ConsoleColor::Red;
        Console::SetCursorPosition(x, y_suelo - 5); cout << "  O  ";
        //le pega
        Console::ResetColor();
        Console::SetCursorPosition(x, y_suelo - 4); cout << " /|\\ ";
        Console::SetCursorPosition(x, y_suelo - 3); cout << " / \\ ";
        Console::SetCursorPosition(x, y_suelo - 2); cout << "     ";
        Console::SetCursorPosition(x, y_suelo - 1); cout << "     ";
    }
    else if (frame == 4) {
        Console::SetCursorPosition(x, y_suelo - 4); cout << "  O  ";
        Console::SetCursorPosition(x, y_suelo - 3); cout << " /|\\ ";
        Console::SetCursorPosition(x, y_suelo - 2); cout << " / \\ ";
        Console::SetCursorPosition(x, y_suelo - 1); cout << "     ";
    }
    Console::SetCursorPosition(x - 1, y_suelo); cout << "=======";
}

int ejecutarTurnoMaximizado(int ancho, int alto, int jugador) {
    //si '-' , condicion, sino '|'
    char teclaObjetivo = (jugador == 1) ? 'a' : 'l';
    char teclaObjetivoMayus = (jugador == 1) ? 'A' : 'L';
    int dado1 = 0;
    int dado2 = 0;

    for (int tiro = 1; tiro <= 2; tiro++) {
        system("cls");

        // guia
        Console::SetCursorPosition((ancho - 44) / 2, 2);
        cout << "=== RONDA DE TIRO: Jugador " << jugador << " ===";
        Console::SetCursorPosition((ancho - 22) / 2, 3);
        cout << "TIRO DE DADO " << tiro << " DE 2";
        Console::SetCursorPosition((ancho - 52) / 2, 4);
        cout << "Presiona [" << teclaObjetivoMayus << "] en el momento justo para saltar!";

        if (tiro == 2) {
            //NO HAY Ñ
            Console::SetCursorPosition((ancho - 24) / 2, 5);
            cout << "Dano Acumulado: " << dado1;
        }



        int y_suelo = alto - 6;
        int y_cubo = y_suelo - 13;
        int x_centro = (ancho - 20) / 2;

        //1
        int numCentro = 1;

        // Vel, aun no defino cual es la mejor
        //opc 1, 25 + rand 40
        //opc 1, 40 + rand 200
        //opc 1, 15 + rand 400
        int velocidadGiro = 40 + (rand() % 200);

        //sale
        while (_kbhit()) _getch();

        bool haSaltado = false;
        // ciclo 1 - recoge el valor q "elige" el jugadore
        while (!haSaltado) {
            dibujarCuboRotando(x_centro, y_cubo, numCentro);
            dibujarStickmanFrame(x_centro + 7, y_suelo, 1);

            _sleep(velocidadGiro);
            numCentro = (numCentro % 6) + 1;

            if (_kbhit()) {
                char presionada = _getch();
                if (presionada == teclaObjetivo || presionada == teclaObjetivoMayus) {
                    haSaltado = true;
                }
            }
        }

        // ciclo 2 - animacion
        // frame 2
        numCentro = (numCentro % 6) + 1;
        dibujarCuboRotando(x_centro, y_cubo, numCentro);
        dibujarStickmanFrame(x_centro + 7, y_suelo, 2);
        _sleep(70);

        // frame 3, "golpe"
        int valorFinaldado = numCentro;
        dibujarCuboRotando(x_centro, y_cubo, valorFinaldado);
        dibujarStickmanFrame(x_centro + 7, y_suelo, 3);
        Console::SetCursorPosition(x_centro + 6, y_cubo + 9);
        cout << " *!BOOM!* ";
        _sleep(350);

        // frame 4, cae
        dibujarStickmanFrame(x_centro + 7, y_suelo, 4);
        _sleep(70);

        // frame 5 (1) - llega
        dibujarStickmanFrame(x_centro + 7, y_suelo, 1);
        _sleep(70);

        if (tiro == 1) dado1 = valorFinaldado;
        else dado2 = valorFinaldado;


        Console::SetCursorPosition((ancho - 24) / 2, y_suelo + 2);
        cout << "Puntaje obtenido: " << valorFinaldado << "!";
        Console::SetCursorPosition((ancho - 36) / 2, y_suelo + 3);
        cout << "Presiona una tecla para continuar...";
        _getch();
    }
    pantallaMultiplicacion(ancho, alto, dado1, dado2);
    return dado1 * dado2;
}

//campo / pantalla

void dibujarBarraVida(int x, int y, string etiqueta, int vida) {
    Console::SetCursorPosition(x, y);
    cout << etiqueta << ": [";
    int barras = vida / 10;

    // cambia el colo depndiendo de cuanta vida haya
    if (vida > 50) Console::ForegroundColor = ConsoleColor::Green;
    else if (vida > 25) Console::ForegroundColor = ConsoleColor::Yellow;
    else Console::ForegroundColor = ConsoleColor::Red;

    for (int i = 0; i < 10; i++) {
        if (i < barras) cout << "I";
        else cout << ".";
    }
    Console::ResetColor();
    cout << "] " << vida << " HP";
}

void dibujarCampoBatalla(int ancho, int alto, int vida1, int vida2) {
    system("cls");

    // barras de vida
    dibujarBarraVida(4, 2, "CASTILLO J1", vida1);
    dibujarBarraVida(ancho - 32, 2, "CASTILLO J2", vida2);

    int y_suelo = dibujarSuelo(ancho, alto);

    //castillos
    int x_castillo_izq = 2;
    int x_castillo_der = ancho - 20;

    int x_arbol_izq = 24;
    int x_canon_izq = 40;

    int x_canon_der = ancho - 52;
    int x_arbol_der = ancho - 30;

    //cañones
    canon_peq_der(x_canon_izq, y_suelo - 3);
    canon_peq_izq(x_canon_der, y_suelo - 3);

    arbol(x_arbol_izq, y_suelo - 3);
    arbol(x_arbol_izq + 8, y_suelo - 3);
    arbol(x_arbol_der - 8, y_suelo - 3);
    arbol(x_arbol_der, y_suelo - 3);

    int y_castillo = y_suelo - 6;
    castillo_peq(x_castillo_izq, y_castillo);
    castillo_peq(x_castillo_der, y_castillo);
}

//--------------------------------------------------------------------------------------------------------------------------------------------

void animarProyectilYExplosion(int ancho, int alto, int atacante, int v1, int v2) {
    int y_suelo = alto - 5;
    int y_castillo = y_suelo - 6;
    int x_origen, x_destino;

    if (atacante == 1) {
        x_origen = 40 + 11; // punta del cañón izquierdo
        x_destino = ancho - 14; // blanco en el castillo derecho
    }
    else {
        x_origen = (ancho - 52) + 1; // Punta del cañón derecho
        x_destino = 10; // Blanco en el castillo izquierdo
    }

    int y_origen = y_suelo - 2;
    int y_destino = y_castillo + 3;

    // Ecuación balística parabólica en base al tiempo
    double framesMax = 25.0;
    for (int f = 0; f <= framesMax; f++) {
        double t = f / framesMax;
        int px = x_origen + (x_destino - x_origen) * t;
        // Curva parabólica simulada con una altura máxima de arco de 9 líneas
        double arcoAltura = 9.0 * 4.0 * t * (1.0 - t);
        int py = y_origen + (y_destino - y_origen) * t - arcoAltura;

        if (px >= 0 && px < ancho && py >= 0 && py < alto) {
            Console::SetCursorPosition(px, py); cout << "O";
        }
        _sleep(35);
        if (px >= 0 && px < ancho && py >= 0 && py < alto) {
            Console::SetCursorPosition(px, py); cout << " ";
        }
    }

    // Impacto y reconstrucción automática limpia
    int x_impacto = (atacante == 1) ? (ancho - 20) : 2;
    explosion(x_impacto, y_castillo);
    _sleep(800);

    dibujarCampoBatalla(ancho, alto, v1, v2);
}

//
//--------------------------------------------------------------------------------------------------------------------------------------------
//menu + animacion

void menu(int ancho, int alto) {
    system("cls");
    titulo(ancho, alto);

    int y_suelo = dibujarSuelo(ancho, alto);
    int x_castillo_izq = 2, x_castillo_der = ancho - 20;
    int x_arbol_izq = 24, x_canon_izq = 40;
    int x_canon_der = ancho - 52, x_arbol_der = ancho - 30;

    canon_peq_izq(x_canon_izq, y_suelo - 3);
    canon_peq_der(x_canon_der, y_suelo - 3);
    arbol(x_arbol_izq, y_suelo - 3); arbol(x_arbol_izq + 8, y_suelo - 3);
    arbol(x_arbol_der - 8, y_suelo - 3); arbol(x_arbol_der, y_suelo - 3);

    int y_castillo = y_suelo - 6;
    castillo_peq(x_castillo_izq, y_castillo);
    castillo_peq(x_castillo_der, y_castillo);

    int proy_y_inicio = 12;
    int p_izq1 = x_castillo_izq + 4, p_izq2 = x_castillo_izq + 13;
    int p_der1 = x_castillo_der + 4, p_der2 = x_castillo_der + 13;
    int anim_y = proy_y_inicio;

    while (!_kbhit()) {
        //cm uso string aqui?
        if (anim_y > proy_y_inicio) {
            Console::SetCursorPosition(p_izq1, anim_y - 1); cout << " ";
            Console::SetCursorPosition(p_izq2, anim_y - 1); cout << " ";
            Console::SetCursorPosition(p_der1, anim_y - 1); cout << " ";
            Console::SetCursorPosition(p_der2, anim_y - 1); cout << " ";
        }
        Console::SetCursorPosition(p_izq1, anim_y); cout << "O";
        Console::SetCursorPosition(p_izq2, anim_y); cout << "O";
        Console::SetCursorPosition(p_der1, anim_y); cout << "O";
        Console::SetCursorPosition(p_der2, anim_y); cout << "O";

        _sleep(70);
        anim_y++;

        if (anim_y >= y_castillo + 2) {
            //ya fue ya
            Console::SetCursorPosition(p_izq1, anim_y - 1); cout << " ";
            Console::SetCursorPosition(p_izq2, anim_y - 1); cout << " ";
            Console::SetCursorPosition(p_der1, anim_y - 1); cout << " ";
            Console::SetCursorPosition(p_der2, anim_y - 1); cout << " ";
            explosion(x_castillo_izq, y_castillo);
            explosion(x_castillo_der, y_castillo);
            _sleep(800);
            castillo_peq(x_castillo_izq, y_castillo);
            castillo_peq(x_castillo_der, y_castillo);
            _sleep(300);
            anim_y = proy_y_inicio;
        }
    }
    _getch();
}

void juego_artilleria() {
    srand(time(NULL));
    Console::CursorVisible = false;

    int alto = Console::WindowHeight;
    int ancho = Console::WindowWidth;


    menu(ancho, alto);

    //VIDA DE LOS BICHOS
    int saludJ1 = 100;
    int saludJ2 = 100;
    int turno = 1; // 1 = Jugador Izquierda, 2 = Jugador Derecha

    //juego principal
    while (saludJ1 > 0 && saludJ2 > 0) {
        if (kbhit()) {
            char tecla = getch();
            if (tecla == 27) break;
            if (tecla == -32 || tecla == 224) {
                tecla = getch();
            }
        }
        dibujarCampoBatalla(ancho, alto, saludJ1, saludJ2);

        Console::SetCursorPosition((ancho - 32) / 2, 5);
        cout << ">>> TURNO ACTUAL: JUGADOR " << turno << " <<<";
        Console::SetCursorPosition((ancho - 40) / 2, 6);
        cout << "Presiona cualquier tecla para ir a tu cubo...";
        _getch();

        //"maximiza" la perspectiva del palitos
        int danoTotalTurno = ejecutarTurnoMaximizado(ancho, alto, turno);

        //regresa al mapa principal
        if (turno == 1) {
            saludJ2 -= danoTotalTurno;
            if (saludJ2 < 0) saludJ2 = 0;
            dibujarCampoBatalla(ancho, alto, saludJ1, saludJ2);

            Console::SetCursorPosition((ancho - 42) / 2, 5);
            cout << "Fuego! Proyectil de J1 causa " << danoTotalTurno << " de dano.";
            animarProyectilYExplosion(ancho, alto, 1, saludJ1, saludJ2);
            turno = 2; // cede el turno
        }
        else {
            saludJ1 -= danoTotalTurno;
            if (saludJ1 < 0) saludJ1 = 0;
            dibujarCampoBatalla(ancho, alto, saludJ1, saludJ2);

            Console::SetCursorPosition((ancho - 42) / 2, 5);
            cout << "Fuego! Proyectil de J2 causa " << danoTotalTurno << " de dano.";
            animarProyectilYExplosion(ancho, alto, 2, saludJ1, saludJ2);
            turno = 1; // cede el turno
        }
    }

    //"pantalla de ganador", puede mejorar... :(
    system("cls");
    Console::SetCursorPosition((ancho - 30) / 2, alto / 2 - 1);
    cout << "==============================";
    Console::SetCursorPosition((ancho - 22) / 2, alto / 2);

    //no deberian haber empates vaya
    if (saludJ1 <= 0 && saludJ2 <= 0) {
        cout << "EMPATE CATACLISMICO (Como paso eso?)!";

    }
    //PERO ME DA IGUAL 🤑
    else if (saludJ1 <= 0) {
        cout << "VICTORIA DEL JUGADOR 2!";


    }
    else {
        cout << "VICTORIA DEL JUGADOR 1!";

    }
    Console::SetCursorPosition((ancho - 30) / 2, alto / 2 + 1);
    cout << "==============================";

    Console::SetCursorPosition((ancho - 38) / 2, alto / 2 + 3);
    cout << "Presiona cualquier tecla para finalizar...";
    _getch();
}

