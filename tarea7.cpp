#include <iostream>
#include <string>
//BRANDON RENE MORENO CONTRERAS 
//CARNE: 9941-21-7965
using namespace std;
struct Nodo {
    int carne;
    string nombre;
    string apellido;
    string carrera;
    Nodo* siguiente;
};
Nodo* head = NULL;
void insertarAlInicio() {
    Nodo* nuevo = new Nodo;
    cout << "\n--- Insertar estudiante al inicio ---" << endl;
    cout << "Ingrese carne: ";
    cin >> nuevo->carne;
    cout << "Ingrese nombre: ";
    cin >> nuevo->nombre;
    cout << "Ingrese apellido: ";
    cin >> nuevo->apellido;
    cout << "Ingrese carrera: ";
    cin.ignore();
    getline(cin, nuevo->carrera);
    nuevo->siguiente = head;
    head = nuevo;
    cout << "Estudiante insertado al inicio correctamente." << endl;
}
void insertarAlFinal() {
    Nodo* nuevo = new Nodo;
    cout << "\n--- Insertar estudiante al final ---" << endl;
    cout << "Ingrese carne: ";
    cin >> nuevo->carne;
    cout << "Ingrese nombre: ";
    cin >> nuevo->nombre;
    cout << "Ingrese apellido: ";
    cin >> nuevo->apellido;
    cout << "Ingrese carrera: ";
    cin.ignore();
    getline(cin, nuevo->carrera);
    nuevo->siguiente = NULL;
    if (head == NULL) {
        head = nuevo;
    } else {
        Nodo* temp = head;
        while (temp->siguiente != NULL) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevo;
    }
    cout << "Estudiante insertado al final correctamente." << endl;
}
void mostrarEstudiantes() {
    cout << "\n--- Lista de estudiantes ---" << endl;
    if (head == NULL) {
        cout << "No hay estudiantes registrados." << endl;
        return;
    }
    Nodo* temp = head;
    while (temp != NULL) {
        cout << "Carne: "    << temp->carne    << endl;
        cout << "Nombre: "   << temp->nombre   << endl;
        cout << "Apellido: " << temp->apellido << endl;
        cout << "Carrera: "  << temp->carrera  << endl;
        cout << "------------------------------" << endl;
        temp = temp->siguiente;
    }
}
void buscarEstudiante() {
    int carneBuscado;
    cout << "\n--- Buscar estudiante ---" << endl;
    cout << "Ingrese carne a buscar: ";
    cin >> carneBuscado;
    Nodo* temp = head;
    while (temp != NULL) {
        if (temp->carne == carneBuscado) {
            cout << "\nEstudiante encontrado:" << endl;
            cout << "Nombre: "   << temp->nombre   << endl;
            cout << "Apellido: " << temp->apellido << endl;
            cout << "Carrera: "  << temp->carrera  << endl;
            return;
        }
        temp = temp->siguiente;
    }
    cout << "Estudiante no encontrado." << endl;
}
void eliminarEstudiante() {
    int carneEliminar;
    cout << "\n--- Eliminar estudiante ---" << endl;
    cout << "Ingrese carne a eliminar: ";
    cin >> carneEliminar;
    if (head == NULL) {
        cout << "La lista esta vacia." << endl;
        return;
    }
    if (head->carne == carneEliminar) {
        Nodo* temp = head;
        head = head->siguiente; // head ahora apunta al segundo
        delete temp;            // liberar memoria
        cout << "Estudiante eliminado correctamente." << endl;
        return;
    }
    Nodo* anterior = head;
    Nodo* actual   = head->siguiente;
    while (actual != NULL) {
        if (actual->carne == carneEliminar) {
            // Saltar el nodo a eliminar
            anterior->siguiente = actual->siguiente;
            delete actual; // liberar memoria
            cout << "Estudiante eliminado correctamente." << endl;
            return;
        }
        anterior = actual;
        actual   = actual->siguiente;
    }
    cout << "Estudiante no encontrado." << endl;
}
int main() {
    int opcion;
    do {
        cout << "\n=============================" << endl;
        cout << "  SISTEMA DE ESTUDIANTES     " << endl;
        cout << "=============================" << endl;
        cout << "1. Insertar estudiante al inicio" << endl;
        cout << "2. Insertar estudiante al final"  << endl;
        cout << "3. Mostrar estudiantes"           << endl;
        cout << "4. Buscar estudiante"             << endl;
        cout << "5. Eliminar estudiante"           << endl;
        cout << "6. Salir"                         << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        switch (opcion) {
            case 1: insertarAlInicio();   break;
            case 2: insertarAlFinal();    break;
            case 3: mostrarEstudiantes(); break;
            case 4: buscarEstudiante();   break;
            case 5: eliminarEstudiante(); break;
            case 6: cout << "Saliendo del programa..." << endl; break;
            default: cout << "Opcion invalida." << endl;
        }
    } while (opcion != 6);

    return 0;
}




