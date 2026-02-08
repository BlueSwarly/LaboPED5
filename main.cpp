#include <iostream>
using namespace std;

struct Estudiante
{
    int carnet;
    char nombre[50];
    float nota;
    Estudiante *izquierdo;
    Estudiante *derecho;
};
// Función para crear un nuevo estudiante
Estudiante *crearEstudiante(int carnet, char nom[], float nota)
{
    Estudiante *nuevo = new Estudiante();
    nuevo->carnet = carnet;
    nuevo->nota = nota;
    nuevo->izquierdo = nullptr;
    nuevo->derecho = nullptr;

    // Copiar el nombre
    int i = 0;
    while (nom[i] != '\0' && i < 49)
    {
        nuevo->nombre[i] = nom[i];
        i++;
    }
    nuevo->nombre[i] = '\0';

    return nuevo;
}
// TODO: Implementar estas funciones
// 1. Insertar un estudiante en el árbol (ordenado por carnet)
Estudiante *insertar(Estudiante *raiz, int carnet, char nombre[], float nota)
{
   if (raiz == nullptr)
        return crearEstudiante(carnet, nombre, nota);

    if (carnet < raiz->carnet)
        raiz->izquierdo = insertar(raiz->izquierdo, carnet, nombre, nota);
    else if (carnet > raiz->carnet)
        raiz->derecho = insertar(raiz->derecho, carnet, nombre, nota);
    else
        cout << "El carnet ya existe.\n";

    return raiz;
}
// 2. Mostrar todos los estudiantes en orden de carnet
void mostrarEstudiantes(Estudiante *raiz)
{
    if (raiz != nullptr)
    {
        mostrarEstudiantes(raiz->izquierdo);
        cout << "Carnet: " << raiz->carnet << endl;
        cout << "Nombre: " << raiz->nombre << endl;
        cout << "Nota: " << raiz->nota << endl << endl;
        mostrarEstudiantes(raiz->derecho);
    }
}
// 3. Buscar un estudiante por carnet y mostrar sus datos
void buscarEstudiante(Estudiante *raiz, int carnet)
{
    if (raiz == nullptr)
    {
        cout << "Estudiante no encontrado\n";
        return;
    }

    if (carnet == raiz->carnet)
    {
        cout << "Carnet: " << raiz->carnet
             << " | Nombre: " << raiz->nombre
             << " | Nota: " << raiz->nota << endl;
    }
    else if (carnet < raiz->carnet)
        buscarEstudiante(raiz->izquierdo, carnet);
    else
        buscarEstudiante(raiz->derecho, carnet);
}
// 4. Mostrar estudiantes aprobados (nota >= 6.0)
void mostrarAprobados(Estudiante *raiz)
{
    if (raiz == nullptr) return;

    mostrarAprobados(raiz->izquierdo);

    if (raiz->nota >= 6.0)
        cout << raiz->nombre << " - " << raiz->nota << endl;

    mostrarAprobados(raiz->derecho);
}
// 5. Mostrar estudiantes reprobados (nota < 6.0)
void mostrarReprobados(Estudiante *raiz)
{
   if (raiz == nullptr) return;

    mostrarReprobados(raiz->izquierdo);

    if (raiz->nota < 6.0)
        cout << raiz->nombre << " - " << raiz->nota << endl;

    mostrarReprobados(raiz->derecho);
}
// 6. Calcular el promedio de todas las notas
float calcularPromedio(Estudiante *raiz, int *contador)
{
  if (raiz == nullptr)
        return 0;

    float suma = 0;

    suma += calcularPromedio(raiz->izquierdo, contador);
    suma += raiz->nota;
    (*contador)++;
    suma += calcularPromedio(raiz->derecho, contador);

    return suma;
}
// 7. Encontrar al estudiante con la nota más alta
Estudiante *encontrarMejorNota(Estudiante *raiz)
{
    if (raiz == nullptr)
        return nullptr;

    Estudiante *mejor = raiz;

    Estudiante *izq = encontrarMejorNota(raiz->izquierdo);
    Estudiante *der = encontrarMejorNota(raiz->derecho);

    if (izq != nullptr && izq->nota > mejor->nota)
        mejor = izq;

    if (der != nullptr && der->nota > mejor->nota)
        mejor = der;

    return mejor;
}
int main()
{
    Estudiante *sistema = nullptr;
    int opcion;

    do
    {
        cout << "\n===== SISTEMA DE GESTION DE ESTUDIANTES=====\n";
        cout << "1. Agregar estudiante\n";
        cout << "2. Mostrar todos los estudiantes\n";
        cout << "3. Buscar estudiante por carnet\n";
        cout << "4. Mostrar estudiantes aprobados\n";
        cout << "5. Mostrar estudiantes reprobados\n";
        cout << "6. Calcular promedio general\n";
        cout << "7. Mostrar estudiante con mejor nota\n";
        cout << "8. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        // Implementa el switch con las opciones
        switch (opcion)
        {
        switch (opcion)
        {
            case 1: {
                int carnet;
                char nombre[50];
                float nota;

                cout << "Ingrese carnet: ";
                cin >> carnet;
                cout << "Ingrese nombre: ";
                cin.ignore();
                cin.getline(nombre, 50);
                cout << "Ingrese nota: ";
                cin >> nota;

                sistema = insertar(sistema, carnet, nombre, nota);
                break;
            }

            case 2:
                mostrarEstudiantes(sistema);
                break;

            case 3: {
                int carnet;
                cout << "Ingrese carnet a buscar: ";
                cin >> carnet;
                buscarEstudiante(sistema, carnet);
                break;
            }

            case 4:
                mostrarAprobados(sistema);
                break;

            case 5:
                mostrarReprobados(sistema);
                break;

            case 6: {
                int contador = 0;
                float suma = calcularPromedio(sistema, &contador);

                if (contador > 0)
                    cout << "Promedio general: " << suma / contador << endl;
                else
                    cout << "No hay estudiantes registrados.\n";
                break;
            }

            case 7: {
                Estudiante *mejor = encontrarMejorNota(sistema);

                if (mejor != nullptr)
                    cout << "Mejor nota: " << mejor->nombre << " - " << mejor->nota << endl;
                else
                    cout << "No hay estudiantes registrados.\n";
                break;
            }
        default:
            cout << "La opcion marcada no es valida, vuelva a intentar. " << endl;
            break;
        }

    } while (opcion != 8);

    return 0;
}
