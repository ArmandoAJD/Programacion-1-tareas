#include "Juego.h"
#include <iostream>
#include <cstdlib>
#include <limits>
#include <iomanip>
#include <chrono>

using namespace std;
using namespace std::chrono;

Juego::Juego(Tablero tablero, int cantidadMinas, int vidas) :
    tablero(tablero), cantidadMinas(cantidadMinas), vidas(vidas), puntos(0)
{
    cout << "\nIngrese su nombre: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, nombreJugador);
    cout << "\nINICIANDO PARTIDA DE " << nombreJugador << " CON " << this->vidas << " VIDAS\n";
    tiempoInicio = steady_clock::now();
}

int Juego::aleatorio_en_rango(int minimo, int maximo) {
    return minimo + rand() % (maximo - minimo + 1);
}

int Juego::filaAleatoria() {
    return aleatorio_en_rango(0, tablero.getAlturaTablero() - 1);
}

int Juego::columnaAleatoria() {
    return aleatorio_en_rango(0, tablero.getAnchoTablero() - 1);
}

void Juego::colocarMinasAleatoriamente() {
    int minasColocadas = 0;
    while (minasColocadas < cantidadMinas) {
        int x = columnaAleatoria();
        int y = filaAleatoria();
        if (tablero.colocarMina(x, y)) {
            minasColocadas++;
        }
    }
}

int Juego::solicitarFilaUsuario() {
    int fila;
    while (true) {
        cout << nombreJugador << ", ingrese fila (1-" << tablero.getAlturaTablero() << "): ";
        if (cin >> fila) {
            if (fila >= 1 && fila <= tablero.getAlturaTablero()) {
                break;
            } else {
                cout << "Error: El valor debe estar entre 1 y " << tablero.getAlturaTablero() << endl;
            }
        } else {
            cout << "Error: Entrada invalida. Por favor ingrese un numero." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return fila - 1;
}

int Juego::solicitarColumnaUsuario() {
    int columna;
    while (true) {
        cout << nombreJugador << ", ingrese columna (1-" << tablero.getAnchoTablero() << "): ";
        if (cin >> columna) {
            if (columna >= 1 && columna <= tablero.getAnchoTablero()) {
                break;
            } else {
                cout << "Error: El valor debe estar entre 1 y " << tablero.getAnchoTablero() << endl;
            }
        } else {
            cout << "Error: Entrada invalida. Por favor ingrese un numero." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return columna - 1;
}

bool Juego::jugadorGana() {
    return tablero.contarCeldasSinMinasYSinDescubrir() == 0;
}

void Juego::restarVida() {
    vidas--;
    cout << "\n¡" << nombreJugador << " PERDISTE UNA VIDA! Vidas restantes: " << vidas << "\n";
    system("pause");
}

bool Juego::tieneVidas() const {
    return vidas > 0;
}

int Juego::getVidas() const {
    return vidas;
}

void Juego::calcularPuntos() {
    int celdasDescubiertas = (tablero.getAnchoTablero() * tablero.getAlturaTablero()) -
                            cantidadMinas - tablero.contarCeldasSinMinasYSinDescubrir();

    puntos = celdasDescubiertas * 10;

    if (jugadorGana()) {
        puntos += vidas * 100;
    }
}

void Juego::mostrarMarcadorFinal() {
    auto tiempoFin = steady_clock::now();
    auto duracion = duration_cast<seconds>(tiempoFin - tiempoInicio);
    int segundosTotales = duracion.count();

    int minutos = segundosTotales / 60;
    int segundos = segundosTotales % 60;

    calcularPuntos();

    cout << "\n\n====================================\n";
    cout << "          RESULTADO FINAL\n";
    cout << "====================================\n";
    cout << "Jugador: " << nombreJugador << "\n";
    cout << "Tiempo de juego: " << minutos << " minutos y " << segundos << " segundos\n";
    cout << "Puntos obtenidos: " << puntos << "\n";
    cout << "Vidas restantes: " << vidas << "\n";
    cout << "Celdas descubiertas: " << (tablero.getAnchoTablero() * tablero.getAlturaTablero()) -
            cantidadMinas - tablero.contarCeldasSinMinasYSinDescubrir() << "/" <<
            (tablero.getAnchoTablero() * tablero.getAlturaTablero() - cantidadMinas) << "\n";

    if (jugadorGana()) {
        cout << "¡HAS GANADO!\n";
    } else {
        cout << "¡GAME OVER!\n";
    }
    cout << "====================================\n\n";
}

void Juego::iniciar() {
    colocarMinasAleatoriamente();

    while (tieneVidas()) {
        system("cls");
        tablero.imprimir();
        cout << "\nJUGADOR: " << nombreJugador << " - VIDAS RESTANTES: " << vidas << endl;

        int fila = solicitarFilaUsuario();
        int columna = solicitarColumnaUsuario();

        if (!tablero.descubrirMina(columna, fila)) {
            restarVida();

            if (!tieneVidas()) {
                system("cls");
                cout << "\n\n==========================================\n";
                cout << "   ¡PERDISTE! Mala suerte\n";
                cout << "==========================================\n";
                mostrarMarcadorFinal();
                tablero.setModoDesarrollador(true);
                tablero.imprimir();
                system("pause");
                break;
            }
        }

        if (jugadorGana()) {
            system("cls");
            cout << "\n\n==========================================\n";
            cout << "   ¡FELICIDADES " << nombreJugador << "! HAS GANADO\n";
            cout << "==========================================\n";
            mostrarMarcadorFinal();
            tablero.setModoDesarrollador(true);
            tablero.imprimir();
            system("pause");
            break;
        }
    }
}
