#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int NUM_VOTANTES = 50;
const int NUM_RONDAS = 5;
const int MAX_CANDIDATOS = 10;

void ingresarCandidatos(string candidatos[], string partidos[], int &numCandidatos) {
    cout << "Ingrese el número de candidatos (máximo " << MAX_CANDIDATOS << "): ";
    cin >> numCandidatos;
    cin.ignore();
    for (int i = 0; i < numCandidatos; i++) {
        cout << "Ingrese el nombre del candidato " << i + 1 << ": ";
        getline(cin, candidatos[i]);
        cout << "Ingrese el nombre del partido político de " << candidatos[i] << ": ";
        getline(cin, partidos[i]);
    }
}

void generarVotacion(int votos[][NUM_RONDAS], int numCandidatos) {
    srand(time(0));
    for (int ronda = 0; ronda < NUM_RONDAS; ronda++) {
        for (int i = 0; i < numCandidatos; i++) {
            votos[i][ronda] = rand() % (NUM_VOTANTES + 1);
        }
    }
}

void mostrarResultados(string candidatos[], string partidos[], int votos[][NUM_RONDAS], int numCandidatos) {
    cout << "\nResultados de la elección:\n";
    cout << "---------------------------------------------------\n";
    cout << "Candidato\tPartido\t";
    for (int ronda = 0; ronda < NUM_RONDAS; ronda++) {
        cout << "Ronda " << ronda + 1 << "\t";
    }
    cout << "Total\n";
    cout << "---------------------------------------------------\n";

    int totalVotos[MAX_CANDIDATOS] = {0};
    for (int i = 0; i < numCandidatos; i++) {
        cout << candidatos[i] << "\t" << partidos[i] << "\t";
        for (int ronda = 0; ronda < NUM_RONDAS; ronda++) {
            cout << votos[i][ronda] << "\t";
            totalVotos[i] += votos[i][ronda];
        }
        cout << totalVotos[i] << "\n";
    }

    int maxVotos = totalVotos[0], minVotos = totalVotos[0];
    string ganador = candidatos[0], perdedor = candidatos[0];
    for (int i = 1; i < numCandidatos; i++) {
        if (totalVotos[i] > maxVotos) {
            maxVotos = totalVotos[i];
            ganador = candidatos[i];
        }
        if (totalVotos[i] < minVotos) {
            minVotos = totalVotos[i];
            perdedor = candidatos[i];
        }
    }

    cout << "\nGanador de la elección: " << ganador << " del partido " << partidos[distance(candidatos, find(candidatos, candidatos + numCandidatos, ganador))] << " con " << maxVotos << " votos.\n";
    cout << "Candidato con menos votos: " << perdedor << " del partido " << partidos[distance(candidatos, find(candidatos, candidatos + numCandidatos, perdedor))] << " con " << minVotos << " votos.\n";
}

int main() {
    string candidatos[MAX_CANDIDATOS];
    string partidos[MAX_CANDIDATOS];
    int votos[MAX_CANDIDATOS][NUM_RONDAS];
    int numCandidatos;
    char opcion;

    do {
        ingresarCandidatos(candidatos, partidos, numCandidatos);
        generarVotacion(votos, numCandidatos);
        mostrarResultados(candidatos, partidos, votos, numCandidatos);

        cout << "\n¿Desea realizar otra elección? (s/n): ";
        cin >> opcion;
    } while (opcion == 's' || opcion == 'S');

    return 0;
}
h
