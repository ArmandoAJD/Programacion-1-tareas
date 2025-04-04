#include "Juego.h"
#include <fstream>
#include <unistd.h>
#include <iostream>

using namespace std;

int Juego::aleatorio_en_rango(int minimo, int maximo)
{
    return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}

int Juego::filaAleatoria()
{
    return this->aleatorio_en_rango(0, this->tablero.getAlturaTablero() - 1);
}

int Juego::columnaAleatoria()
{
    return this->aleatorio_en_rango(0, this->tablero.getAnchoTablero() - 1);
}

Juego::Juego(Tablero tablero, int cantidadMinas, int vidas)
{
    this->tablero = tablero;
    this->cantidadMinas = cantidadMinas;
    this->vidas = vidas;  // Inicializa el número de vidas
    this->colocarMinasAleatoriamente();
}

void Juego::colocarMinasAleatoriamente()
{
    int x, y, minasColocadas = 0;

    while (minasColocadas < this->cantidadMinas)
    {
        x = this->columnaAleatoria();
        y = this->filaAleatoria();
        if (this->tablero.colocarMina(x, y))
        {
            minasColocadas++;
        }
    }
}

int Juego::solicitarFilaUsuario()
{
    int fila = 0;
    cout << "Ingresa la FILA en la que desea jugar: ";
    cin >> fila;
    return fila - 1;
}

int Juego::solicitarColumnaUsuario()
{
    int columna = 0;
    cout << "Ingresa la COLUMNA en la que desea jugar: ";
    cin >> columna;
    return columna - 1;
}

bool Juego::jugadorGana()
{
    int conteo = this->tablero.contarCeldasSinMinasYSinDescubrir();
    return conteo == 0;
}

void Juego::restarVida()
{
    if (this->vidas > 0)
    {
        this->vidas--;
    }
}

bool Juego::tieneVidas()
{
    return this->vidas > 0;
}

void Juego::iniciar()
{
    int fila, columna;
    while (true)
    {
        this->tablero.imprimir();
        cout << "Vidas restantes: " << this->vidas << endl;  // Muestra las vidas restantes
        fila = this->solicitarFilaUsuario();
        columna = this->solicitarColumnaUsuario();

        // Intentar descubrir la mina en la posición seleccionada por el jugador
        bool respuestaAUsuario = this->tablero.descubrirMina(columna, fila);

        if (!respuestaAUsuario)  // Si se descubre una mina
        {
            cout << "¡Perdiste una vida! Has descubierto una mina.\n";
            this->restarVida();  // Restamos una vida

            if (!this->tieneVidas())  // Verificamos si se han agotado las vidas
            {
                cout << "¡Te has quedado sin vidas! Fin del juego.\n";
                this->tablero.setModoDesarrollador(true);
                this->tablero.imprimir();
                break;
            }
        }

        // Verificamos si el jugador ganó
        if (this->jugadorGana())
        {
            cout << "¡Ganaste el Juego!\n";
            this->tablero.setModoDesarrollador(true);
            this->tablero.imprimir();
            break;
        }
    }
}
