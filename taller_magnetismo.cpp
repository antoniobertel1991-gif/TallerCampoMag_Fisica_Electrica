#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Estructura para representar un vector 3D
struct Vector3D {
    double x, y, z;
};

// Función independiente para el producto cruz (v x B)
Vector3D productoCruz(Vector3D v, Vector3D B) {
    Vector3D resultado;
    resultado.x = (v.y * B.z) - (v.z * B.y);
    resultado.y = (v.z * B.x) - (v.x * B.z);
    resultado.z = (v.x * B.y) - (v.y * B.x);
    return resultado;
}

// Función independiente para multiplicar un vector por un escalar (la carga q)
Vector3D multiplicarEscalar(Vector3D v, double escalar) {
    Vector3D resultado;
    resultado.x = v.x * escalar;
    resultado.y = v.y * escalar;
    resultado.z = v.z * escalar;
    return resultado;
}

// Función independiente para calcular la magnitud del vector
double calcularMagnitud(Vector3D v) {
    return sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2));
}

// Función para imprimir un vector de forma bonita
void imprimirVector(Vector3D v, string nombre) {
    cout << nombre << ": (" << scientific << setprecision(2) 
         << v.x << ")i + (" << v.y << ")j + (" << v.z << ")k" << endl;
}

int main() {
    // --- Datos oficiales de la Página 2 ---
    double q_proton = 1.60e-19;
    double q_electron = -1.60e-19;

    // Velocidad (usando el exponente -5 tal como dice la guía)
    Vector3D velocidad = {3.00e-5, 4.00e-5, 0.0};
    Vector3D campo_B = {0.0, 0.0, 0.500};

    cout << "--- RESULTADOS DEL TALLER (C++) ---" << endl;

    // 1. Producto Cruz (v x B)
    Vector3D v_cruz_B = productoCruz(velocidad, campo_B);
    imprimirVector(v_cruz_B, "Producto Cruz (v x B)");

    // 2. Fuerza para el Protón
    Vector3D F_proton = multiplicarEscalar(v_cruz_B, q_proton);
    cout << "\n[PROTÓN]" << endl;
    imprimirVector(F_proton, "Vector Fuerza");
    cout << "Magnitud: " << scientific << setprecision(2) << calcularMagnitud(F_proton) << " N" << endl;

    // 3. Fuerza para el Electrón
    Vector3D F_electron = multiplicarEscalar(v_cruz_B, q_electron);
    cout << "\n[ELECTRÓN]" << endl;
    imprimirVector(F_electron, "Vector Fuerza");
    cout << "Magnitud: " << scientific << setprecision(2) << calcularMagnitud(F_electron) << " N" << endl;

    return 0;
}