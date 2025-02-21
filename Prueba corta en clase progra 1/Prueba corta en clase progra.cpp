//Desarrolle el siguiente Programa en C++:
//Se le solicita un programa que utilizando arreglos y funciones ingrese las notas de 5 partidos políticos en 4 rondas, calcule las votos finales y calcule en otro arreglo los porcentajes respectivos de cada partido político.  Entregables:  Link folder repositorio en Github personal, imagen de la ejecuciòn.
//Armando Jose De Leòn Ovando carnet 9959-24-155 Programacion 1 Ing Esduardo Del Aguila

#include <iostream>
using namespace std;

const int NUM_PARTIDOS = 5;
const int NUM_RONDAS = 4;

void ingresarNotas(int notas[NUM_PARTIDOS][NUM_RONDAS]) {
    for (int i = 0; i < NUM_PARTIDOS; i++) {
        cout << "Ingrese las notas para el partidó " << i + 1 << ":\n";
        for (int j = 0; j < NUM_RONDAS; j++) {
            cout << "Ronda " << j + 1 << ": ";
            cin >> notas[i][j];
        }
    }
}

void calcularVotosFinales(int notas[NUM_PARTIDOS][NUM_RONDAS], int votosFinales[NUM_PARTIDOS]) {
    for (int i = 0; i < NUM_PARTIDOS; i++) {
        votosFinales[i] = 0;
        for (int j = 0; j < NUM_RONDAS; j++) {
            votosFinales[i] += notas[i][j];
        }
    }
}

void calcularPorcentajes(int votosFinales[NUM_PARTIDOS], float porcentajes[NUM_PARTIDOS]) {
    int totalVotos = 0;
    for (int i = 0; i < NUM_PARTIDOS; i++) {
        totalVotos += votosFinales[i];
    }
    for (int i = 0; i < NUM_PARTIDOS; i++) {
        porcentajes[i] = (static_cast<float>(votosFinales[i]) / totalVotos) * 100;
    }
}

void mostrarResultados(int votosFinales[NUM_PARTIDOS], float porcentajes[NUM_PARTIDOS]) {
    cout << "\nResultados finales:\n";
    for (int i = 0; i < NUM_PARTIDOS; i++) {
        cout << "Partido " << i + 1 << ": " << votosFinales[i] << " votos (" << porcentajes[i] << "%)\n";
    }
}

int main() {
    int notas[NUM_PARTIDOS][NUM_RONDAS];
    int votosFinales[NUM_PARTIDOS];
    float porcentajes[NUM_PARTIDOS];

    ingresarNotas(notas);

    calcularVotosFinales(notas, votosFinales);

    calcularPorcentajes(votosFinales, porcentajes);

    mostrarResultados(votosFinales, porcentajes);

    return 0;
}
