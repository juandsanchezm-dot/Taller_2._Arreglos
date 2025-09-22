#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

// ======================= UTILIDADES GENERALES =======================
bool entradaValida(int& valor, const string& mensaje, int min, int max) {
    cout << mensaje;
    cin >> valor;
    if (cin.fail() || valor < min || valor > max) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Entrada inválida. Intente de nuevo.\n";
        return false;
    }
    return true;
}

void imprimirArray(const int arr[], int size) {
    cout << "[";
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i < size - 1) cout << ", ";
    }
    cout << "]";
}

template <size_t FILAS, size_t COLUMNAS>
void imprimirMatriz(int (&matriz)[FILAS][COLUMNAS]) {
    for (size_t i = 0; i < FILAS; i++) {
        for (size_t j = 0; j < COLUMNAS; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

// ======================= EJERCICIO 1: MEDIANA =======================
void ejercicioMediana() {
    cout << "1. Crea un programa que encuentre la mediana de un array\n";
    int array[] = {1, 6, 5, 8, 7, 3, 4, 2, 10, 9};
    const int n = sizeof(array) / sizeof(array[0]);
    int copia[n];
    copy(array, array + n, copia);
    sort(copia, copia + n);
    double mediana = (n % 2 == 0)
        ? (copia[n / 2 - 1] + copia[n / 2]) / 2.0
        : copia[n / 2];
    cout << "La mediana del array ";
    imprimirArray(array, n);
    cout << " es: " << mediana << "\n\n";
}

// ======================= EJERCICIO 2: BÚSQUEDA BINARIA =======================
void ejercicioBusquedaBinaria() {
    cout << "2. Implementa la búsqueda binaria en un array ordenado\n";
    int array[] = {1,2,3,4,5,6,7,8,9,10};
    int buscar = 7;
    int inicio = 0, fin = 9, pos = -1;
    while (inicio <= fin) {
        int medio = inicio + (fin - inicio) / 2;
        if (array[medio] == buscar) {
            pos = medio;
            break;
        } else if (array[medio] < buscar) {
            inicio = medio + 1;
        } else {
            fin = medio - 1;
        }
    }
    if (pos != -1)
        cout << "El elemento " << buscar << " se encuentra en la posición: " << pos + 1 << "\n\n";
    else
        cout << "El elemento no se encontró en el arreglo\n\n";
}

// ======================= EJERCICIO 3: TRANSPUESTA =======================
void ejercicioTranspuesta() {
    cout << "3. Desarrolla un programa que calcule la transpuesta de una matriz\n";
    int matriz[3][2] = {{1,2},{3,4},{5,6}};
    int transpuesta[2][3];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 2; j++)
            transpuesta[j][i] = matriz[i][j];
    cout << "Matriz original:\n"; imprimirMatriz(matriz);
    cout << "Matriz transpuesta:\n"; imprimirMatriz(transpuesta);
    cout << "\n";
}

// ======================= EJERCICIO 4: INVENTARIO =======================
void ejercicioInventario() {
    cout << "4. Crea un sistema de inventario simple con arrays\n";
    const int maxProductos = 5;
    string productos[maxProductos];
    int cantidades[maxProductos] = {0};
    int numProductos = 0, opcion;
    do {
        cout << "\nMenu de Inventario:\n";
        cout << "1. Agregar producto\n";
        cout << "2. Mostrar inventario\n";
        cout << "3. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada inválida. Intente de nuevo.\n";
            continue;
        }
        switch (opcion) {
            case 1:
                if (numProductos < maxProductos) {
                    cout << "Ingrese el nombre del producto: ";
                    cin >> productos[numProductos];
                    cout << "Ingrese la cantidad: ";
                    cin >> cantidades[numProductos];
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Cantidad inválida. Intente de nuevo.\n";
                        continue;
                    }
                    numProductos++;
                } else {
                    cout << "¡Inventario lleno!\n";
                }
                break;
            case 2:
                cout << "Inventario actual:\n";
                for (int i = 0; i < numProductos; i++)
                    cout << productos[i] << ": " << cantidades[i] << endl;
                break;
            case 3:
                cout << "Saliendo del sistema de inventario.\n";
                break;
            default:
                cout << "Opción inválida. Intente de nuevo.\n";
        }
    } while (opcion != 3);
    cout << "\n";
}

// ======================= EJERCICIO 5: SELECCIÓN =======================
void ejercicioSeleccion() {
    cout << "5. Implementa el algoritmo de ordenamiento por selección\n";
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx]) min_idx = j;
        swap(arr[min_idx], arr[i]);
    }
    cout << "Array ordenado: "; imprimirArray(arr, n); cout << "\n\n";
}

// ======================= EJERCICIO 6: DUPLICADOS =======================
void ejercicioDuplicados() {
    cout << "6. Desarrolla un programa que encuentre elementos duplicados\n";
    int arr[] = {1, 2, 3, 4, 5, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Elementos duplicados: ";
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                cout << arr[i] << " ";
                break;
            }
        }
    }
    cout << "\n\n";
}

// ======================= EJERCICIO 7: TRES EN RAYA =======================
const int SIZE = 3;

void inicializarTablero(char tablero[][SIZE]) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            tablero[i][j] = ' ';
}

void imprimirTablero(char tablero[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << tablero[i][j];
            if (j < SIZE - 1) cout << " | ";
        }
        cout << endl;
        if (i < SIZE - 1) cout << "----------\n";
    }
}

bool verificarVictoria(char tablero[][SIZE], char jugador) {
    for (int i = 0; i < SIZE; i++) {
        if ((tablero[i][0] == jugador && tablero[i][1] == jugador && tablero[i][2] == jugador) ||
            (tablero[0][i] == jugador && tablero[1][i] == jugador && tablero[2][i] == jugador))
            return true;
    }
    return (tablero[0][0] == jugador && tablero[1][1] == jugador && tablero[2][2] == jugador) ||
           (tablero[0][2] == jugador && tablero[1][1] == jugador && tablero[2][0] == jugador);
}

void turnoJugador(char tablero[][SIZE], char jugador) {
    int fila, columna;
    bool filaOk = false, colOk = false;
    while (!filaOk) filaOk = entradaValida(fila, "Jugador " + string(1, jugador) + " - Fila (1-3): ", 1, 3);
    while (!colOk) colOk = entradaValida(columna, "Columna (1-3): ", 1, 3);
    int r = fila - 1;
    int c = columna - 1;
    if (tablero[r][c] == ' ') {
        tablero[r][c] = jugador;
    } else {
        cout << "Movimiento inválido. Casilla ocupada. Intente de nuevo.\n";
        turnoJugador(tablero, jugador); // Reintenta el turno
    }
}

void ejercicioTresEnRaya() {
    cout << "7. Crea un juego de tres en raya usando arrays bidimensionales\n\n";
    char tablero[SIZE][SIZE];
    char jugadorActual = 'X';
    int movimientos = 0;
    bool gameWon = false;

    inicializarTablero(tablero);

    while (!gameWon && movimientos < SIZE * SIZE) {
        turnoJugador(tablero, jugadorActual);
        movimientos++;
        imprimirTablero(tablero);
        gameWon = verificarVictoria(tablero, jugadorActual);
        if (!gameWon) {
            jugadorActual = (jugadorActual == 'X') ? 'O' : 'X';
        }
    }

    cout << "Tablero final:\n";
    imprimirTablero(tablero);
    if (gameWon) {
        cout << "Jugador " << jugadorActual << " gana!\n";
    } else {
        cout << "Empate!\n";
    }
}

// ======================= MAIN =======================
int main() {
    cout << "=== EJERCICIOS PARA PRACTICAR ===\n\n";
    ejercicioMediana();
    ejercicioBusquedaBinaria();
    ejercicioTranspuesta();
    ejercicioInventario();
    ejercicioSeleccion();
    ejercicioDuplicados();
    ejercicioTresEnRaya();
    return 0;
}