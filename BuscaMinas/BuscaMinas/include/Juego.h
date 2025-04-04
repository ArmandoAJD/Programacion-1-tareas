#ifndef JUEGO_H
#define JUEGO_H
#include "Tablero.h"

class Juego
{
private:
    Tablero tablero;
    int cantidadMinas;
    int vidas;  // Atributo para el número de vidas

    int aleatorio_en_rango(int minimo, int maximo);
    int filaAleatoria();
    int columnaAleatoria();
public:
    Juego(Tablero tablero, int cantidadMinas, int vidas = 3);  // Constructor con parámetro de vidas
    void colocarMinasAleatoriamente();
    int solicitarFilaUsuario();
    int solicitarColumnaUsuario();
    bool jugadorGana();
    void iniciar();
    void dibujarPortada(string nombreArchivo);
    void restarVida();  // Método para restar vidas
    bool tieneVidas();  // Método para verificar si el jugador tiene vidas
};

#endif // JUEGO_H
