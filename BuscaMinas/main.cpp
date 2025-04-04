#include <iostream>
#include <unistd.h>
#include "Juego.h"
#include "Config.h"
#include "Tablero.h"

using namespace std;

int main()
{
    // Configuración inicial con valores por defecto
    Config configuracion(5, 5, 3, false, 3);
    srand(getpid());

    int opcion;
    do {
        system("cls");
        cout << "\n\tBUSCAMINAS\n\t----------\n";
        cout << "\t1. Configuración\n\t2. Jugar\n\t3. Salir\n\tOpción: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                configuracion.menuConfiguracion();
                break;

            case 2: {
                system("cls");
                cout << "\nCONFIGURACIÓN DE LA PARTIDA:" << endl;
                cout << "---------------------------" << endl;
                cout << "Vidas: " << configuracion.getvidasTablero() << endl;
                cout << "Tablero: " << configuracion.getfilasTablero() << "x"
                     << configuracion.getcolumnasTablero() << endl;
                cout << "Minas: " << configuracion.getminasTablero() << endl;
                cout << "\nPreparando nueva partida..." << endl;
                system("pause");

                // Crear nuevo juego con configuración actual
                Tablero tableroActual(
                    configuracion.getfilasTablero(),
                    configuracion.getcolumnasTablero(),
                    configuracion.getmodoDesarrolladorTablero()
                );

                Juego juegoActual(
                    tableroActual,
                    configuracion.getminasTablero(),
                    configuracion.getvidasTablero() // Valor actual garantizado
                );

                juegoActual.iniciar();
                break;
            }
        }
    } while (opcion != 3);

    return 0;
}
