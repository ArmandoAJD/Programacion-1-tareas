#include <iostream>
using namespace std;

int main() {
    double num1, num2;
    char operacion;

    cout << "Ingrese una operaci�n (+, -, *, /): ";
    cin >> operacion;
    cout << "Ingrese dos n�meros: ";
    cin >> num1 >> num2;

    switch (operacion) {
        case '+':
            cout << "Resultado: " << num1 + num2 << endl;
            break;
        case '-':
            cout << "Resultado: " << num1 - num2 << endl;
            break;
        case '*':
            cout << "Resultado: " << num1 * num2 << endl;
            break;
        case '/':
            if (num2 != 0)
                cout << "Resultado: " << num1 / num2 << endl;
            else
                cout << "Error: Divisi�n por cero." << endl;
            break;
        default:
            cout << "Operaci�n no v�lida." << endl;
    }

    return 0;
}
