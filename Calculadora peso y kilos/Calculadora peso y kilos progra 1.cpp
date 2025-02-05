#include <iostream>
#include <cstdlib>
//Programa para calcular peso en libras y kilos Armando De Leon 9959-24-155
//5/02/2025
using namespace std;

int main()
{
    // Variables
    float peso, altura, imc;
    int opcionSeleccionada;
    char salidaMenu;
    // Inicia el ciclo
    do
    {
        system("cls");
        // Menú de opciones
        cout << "Calculadora de IMC" << endl;
        cout << "1. Calcular IMC en kilogramos y metros" << endl;
        cout << "2. Calcular IMC en libras y pulgadas" << endl;
        cout << "3. Salir" << endl;
        cout << "   Opción: ";
        cin >> opcionSeleccionada;

        switch (opcionSeleccionada)
        {
            case 1:
                cout << "Ingrese su peso en kilogramos: ";
                cin >> peso;
                cout << "Ingrese su altura en metros: ";
                cin >> altura;
                break;

            case 2:
                cout << "Ingrese su peso en libras: ";
                cin >> peso;
                peso *= 0.453592; // Convertir libras a kilogramos
                cout << "Ingrese su altura en pulgadas: ";
                cin >> altura;
                altura *= 0.0254; // Convertir pulgadas a metros
                break;

            case 3:
                cout << "Saliendo del programa..." << endl;
                return 0;

            default:
                cout << "Error: Opción seleccionada inválida." << endl;
                continue;
        }

        if (altura > 0) {
            imc = peso / (altura * altura);
            cout << "Su IMC es: " << imc << endl;

            // Clasificación del IMC
            if (imc < 18.5)
                cout << "Estado: Bajo peso" << endl;
            else if (imc >= 18.5 && imc < 24.9)
                cout << "Estado: Peso normal" << endl;
            else if (imc >= 25 && imc < 29.9)
                cout << "Estado: Sobrepeso" << endl;
            else
                cout << "Estado: Obesidad" << endl;
        } else {
            cout << "Error: La altura debe ser mayor que 0." << endl;
        }


        cout << "\nDesea realizar otra operación? (S/N): ";
        cin >> salidaMenu;
    } while (salidaMenu == 's' || salidaMenu == 'S');

    return 0;
}
