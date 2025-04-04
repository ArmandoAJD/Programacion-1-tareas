#ifndef JUEGO_H
#define JUEGO_H
#include "Tablero.h"

class Juego
{
private:
    Tablero tablero;
    int cantidadMinas;
    int vidas;  // Atributo para el n�mero de vidas

    int aleatorio_en_rango(int minimo, int maximo);
    int filaAleatoria();
    int columnaAleatoria();
public:
    Juego(Tablero tablero, int cantidadMinas, int vidas = 3);  // Constructor con par�metro de vidas
    void colocarMinasAleatoriamente();
    int solicitarFilaUsuario();
    int solicitarColumnaUsuario();
    bool jugadorGana();
    void iniciar();
    void dibujarPortada(string nombreArchivo);
    void restarVida();  // M�todo para restar vidas
    bool tieneVidas();  // M�todo para verificar si el jugador tiene vidas
};

#endif // JUEGO_H
