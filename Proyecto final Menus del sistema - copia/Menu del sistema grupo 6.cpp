#include <iostream>       // Para entrada/salida (cin, cout)
#include <vector>         // Para usar arrays dinámicos (vector)
#include <iomanip>        // Para formatear salida (decimales, columnas)
#include <limits>         // Para validar límites de entrada
#include <algorithm>      // Para operaciones con colecciones (no usado aún)

using namespace std;      // Evita escribir std:: antes de cada función estándar

// Estructura que representa un producto comprado
struct Producto {
    string nombre;        // Ej: "Laptop HP 15"
    string proveedor;     // Ej: "TecnoImport S.A."
    double precioCompra;  // Precio unitario en quetzales (Q)
    int cantidad;         // Unidades compradas
    string fechaCompra;   // Formato DD/MM/AAAA
};

vector<Producto> listaCompras;  // Base de datos de todas las compras

// Muestra el menú principal con las opciones disponibles
void mostrarMenu() {
    cout << "\n=== SISTEMA DE COMPRAS A PROVEEDORES ===" << endl;
    cout << "1. Registrar nueva compra" << endl;
    cout << "2. Mostrar historial de compras" << endl;
    cout << "3. Buscar compras por proveedor" << endl;
    cout << "4. Calcular total gastado" << endl;
    cout << "5. Salir" << endl;
    cout << "Seleccione una opcion: ";
}

// Registra una nueva compra con validación de datos
void registrarCompra() {
    Producto nuevaCompra;

    cout << "\n--- REGISTRAR NUEVA COMPRA ---" << endl;

    // Captura nombre (permite espacios)
    cout << "Nombre del producto: ";
    cin.ignore();  // Limpia el buffer
    getline(cin, nuevaCompra.nombre);

    // Captura proveedor
    cout << "Proveedor: ";
    getline(cin, nuevaCompra.proveedor);

    // Valida precio (debe ser número positivo)
    cout << "Precio de compra por unidad (Q): ";
    while (!(cin >> nuevaCompra.precioCompra) || nuevaCompra.precioCompra <= 0) {
        cout << "Valor inválido. Ingrese el precio en quetzales (Q): ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Valida cantidad (entero positivo)
    cout << "Cantidad comprada: ";
    while (!(cin >> nuevaCompra.cantidad) || nuevaCompra.cantidad <= 0) {
        cout << "Cantidad inválida. Ingrese un número positivo: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Captura fecha
    cout << "Fecha de compra (DD/MM/AAAA): ";
    cin.ignore();
    getline(cin, nuevaCompra.fechaCompra);

    // Guarda en la lista
    listaCompras.push_back(nuevaCompra);
    cout << "\n✅ Compra registrada exitosamente" << endl;
}

// Muestra todas las compras en formato de tabla
void mostrarHistorial() {
    if (listaCompras.empty()) {
        cout << "\n⚠ No hay compras registradas." << endl;
        return;
    }

    // Encabezado de tabla
    cout << "\n--- HISTORIAL DE COMPRAS ---" << endl;
    cout << left << setw(25) << "PRODUCTO" << setw(20) << "PROVEEDOR"
         << setw(15) << "PRECIO (Q)" << setw(10) << "CANTIDAD"
         << setw(15) << "TOTAL (Q)" << setw(12) << "FECHA" << endl;
    cout << string(97, '-') << endl;

    // Datos formateados
    for (const auto& compra : listaCompras) {
        double total = compra.precioCompra * compra.cantidad;
        cout << left << setw(25) << compra.nombre
             << setw(20) << compra.proveedor
             << "Q" << setw(14) << fixed << setprecision(2) << compra.precioCompra
             << setw(10) << compra.cantidad
             << "Q" << setw(14) << total
             << setw(12) << compra.fechaCompra << endl;
    }
}

// Busca compras por nombre de proveedor
void buscarPorProveedor() {
    if (listaCompras.empty()) {
        cout << "\n⚠ No hay compras registradas." << endl;
        return;
    }

    string proveedorBuscado;
    cout << "\n🔍 Ingrese el nombre del proveedor: ";
    cin.ignore();
    getline(cin, proveedorBuscado);

    bool encontrado = false;
    cout << "\n--- COMPRAS A " << proveedorBuscado << " ---" << endl;

    // Filtra por proveedor
    for (const auto& compra : listaCompras) {
        if (compra.proveedor == proveedorBuscado) {
            encontrado = true;
            cout << "📦 Producto: " << compra.nombre
                 << " | Cantidad: " << compra.cantidad
                 << " | Total: Q" << fixed << setprecision(2) << (compra.precioCompra * compra.cantidad)
                 << " | Fecha: " << compra.fechaCompra << endl;
        }
    }

    if (!encontrado) {
        cout << "❌ No se encontraron compras a este proveedor." << endl;
    }
}

// Calcula el gasto total en todas las compras
double calcularTotalGastado() {
    double total = 0;
    for (const auto& compra : listaCompras) {
        total += compra.precioCompra * compra.cantidad;
    }
    return total;
}

// Función principal (menú interactivo)
int main() {
    int opcion;

    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
            case 1: registrarCompra(); break;
            case 2: mostrarHistorial(); break;
            case 3: buscarPorProveedor(); break;
            case 4:
                if (listaCompras.empty()) {
                    cout << "\n⚠ No hay compras registradas." << endl;
                } else {
                    cout << "\n💰 Total gastado: Q" << fixed << setprecision(2)
                         << calcularTotalGastado() << endl;
                }
                break;
            case 5: cout << "\n👋 Saliendo del sistema...\n"; break;
            default:
                cout << "\n❌ Opción inválida. Intente nuevamente." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (opcion != 5);

    return 0;
}
