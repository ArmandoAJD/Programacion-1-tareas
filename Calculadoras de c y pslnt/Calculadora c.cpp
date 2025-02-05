#include <iostream>
using namespace std;

int main() {
    double num1, num2;
    char operacion;

    cout << "Ingrese una operación (+, -, *, /): ";
    cin >> operacion;
    cout << "Ingrese dos números: ";
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
                cout << "Error: División por cero." << endl;
            break;
        default:
            cout << "Operación no válida." << endl;
    }

    return 0;
}
