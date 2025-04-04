#include "Config.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

Config::Config(int filas, int columnas, int minas, bool modoDev, int vidas) :
    filasTablero(filas), columnasTablero(columnas), minasTablero(minas),
    modoDesarrolladorTablero(modoDev), vidasTablero(vidas) {}

void Config::menuConfiguracion()
{
    int opcion;
    do {
        system("cls");
        cout << "\n\tCONFIGURACIÓN ACTUAL\n";
        cout << "\t--------------------\n";
        cout << "\t1. Filas: " << filasTablero << endl;
        cout << "\t2. Columnas: " << columnasTablero << endl;
        cout << "\t3. Minas: " << minasTablero << endl;
        cout << "\t4. Modo Dev: " << (modoDesarrolladorTablero ? "ON" : "OFF") << endl;
        cout << "\t5. Vidas: " << vidasTablero << endl;
        cout << "\t6. Volver\n";
        cout << "\n\tSeleccione opción: ";
        cin >> opcion;

        if (opcion >= 1 && opcion <= 5) {
            int valor;
            bool boolValor;
            bool cambioExitoso = false;

            if (opcion != 4) {
                cout << "\tNuevo valor: ";
                cin >> valor;
            }

            switch(opcion) {
                case 1: cambioExitoso = setfilasTablero(valor); break;
                case 2: cambioExitoso = setcolumnasTablero(valor); break;
                case 3: cambioExitoso = setminasTablero(valor); break;
                case 4:
                    cout << "\t0. OFF\n\t1. ON\n\tOpción: ";
                    cin >> boolValor;
                    cambioExitoso = setmodoDesarrolladorTablero(boolValor);
                    break;
                case 5:
                    cambioExitoso = setvidasTablero(valor);
                    if (cambioExitoso) {
                        cout << "\n\t¡Vidas actualizadas a " << getvidasTablero() << " con éxito!\n";
                    }
                    system("pause");
                    break;
            }

            if (cambioExitoso && opcion != 5) {
                cout << "\t¡Cambio realizado!\n";
                system("pause");
            }
        }
    } while (opcion != 6);
}

// Implementación de getters
int Config::getfilasTablero() const { return filasTablero; }
int Config::getcolumnasTablero() const { return columnasTablero; }
int Config::getminasTablero() const { return minasTablero; }
bool Config::getmodoDesarrolladorTablero() const { return modoDesarrolladorTablero; }
int Config::getvidasTablero() const { return vidasTablero; }

// Implementación de setters con validación
bool Config::setfilasTablero(int filas) {
    if (filas >= 5 && filas <= 20) {
        filasTablero = filas;
        return true;
    }
    cout << "\tError: Filas debe ser entre 5-20\n";
    return false;
}

bool Config::setcolumnasTablero(int columnas) {
    if (columnas >= 5 && columnas <= 20) {
        columnasTablero = columnas;
        return true;
    }
    cout << "\tError: Columnas debe ser entre 5-20\n";
    return false;
}

bool Config::setminasTablero(int minas) {
    int maxMinas = (filasTablero * columnasTablero) / 2;
    if (minas >= 1 && minas <= maxMinas) {
        minasTablero = minas;
        return true;
    }
    cout << "\tError: Minas debe ser entre 1-" << maxMinas << endl;
    return false;
}

bool Config::setmodoDesarrolladorTablero(bool modo) {
    modoDesarrolladorTablero = modo;
    return true;
}

bool Config::setvidasTablero(int vidas) {
    if (vidas >= 1 && vidas <= 10) {
        vidasTablero = vidas;
        return true;
    }
    cout << "\tError: Vidas debe ser entre 1-10\n";
    return false;
}
