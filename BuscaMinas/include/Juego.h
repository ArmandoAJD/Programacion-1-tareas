#ifndef JUEGO_H
#define JUEGO_H

#include "Tablero.h"
#include <string>
#include <chrono>

class Juego {
private:
    Tablero tablero;
    int cantidadMinas;
    int vidas;
    std::string nombreJugador;
    std::chrono::steady_clock::time_point tiempoInicio;
    int puntos;

    int aleatorio_en_rango(int minimo, int maximo);
    int filaAleatoria();
    int columnaAleatoria();
    void colocarMinasAleatoriamente();
    void calcularPuntos();

public:
    Juego(Tablero tablero, int cantidadMinas, int vidas);
    int solicitarFilaUsuario();
    int solicitarColumnaUsuario();
    bool jugadorGana();
    void iniciar();
    void restarVida();
    bool tieneVidas() const;
    int getVidas() const;
    void mostrarMarcadorFinal();
};

#endif
