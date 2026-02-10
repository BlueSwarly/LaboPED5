#include <iostream>

using namespace std;

struct nodo{
    int dato;
    nodo *sig;
    nodo *ant;
};

class ListaLinealDoble{
    private:
        nodo *pInicio;

    public:
        ListaLinealDoble();
        void insInicio(void);
        void promedio(void);
        void mostrarTodos(void);
        void menuAdmin(void);
};

ListaLinealDoble::ListaLinealDoble(){
    pInicio = NULL;
}

void ListaLinealDoble::insInicio(void)
{
    int dato;
    char resp;
    nodo *nuevo;

    do{
        cout << "Desea ingresar un dato (s/n? ";
        cin >> resp;
        if(resp == 's'){
            cout << "Digite el dato: ";
            cin >> dato;
            nuevo = new nodo;
            nuevo->dato = dato;
            nuevo->sig = pInicio;
            nuevo->ant = NULL;
            if(pInicio != NULL)
                pInicio->ant = nuevo;
            pInicio = nuevo;

        }
    }while(resp == 's');
}

void ListaLinealDoble::mostrarTodos(void)
{
    nodo *s1 = pInicio;
    nodo *s2 = NULL;

    s1 = pInicio;
    while(s1 != NULL){
        cout << s1->dato << " ";
        s2 = s1;
        s1 = s1->sig;
    }
    cout << endl;
    while(s2 != NULL){
        cout << s2->dato << " ";
        s2 = s2->ant;
    }
}

void ListaLinealDoble::promedio(void)
{
    nodo *aux =pInicio;   
    int suma = 0;
    int almacemango = 0;
    string promedio;

    while(aux != nullptr){
        suma = suma + aux->dato;
        almacemango++;
       aux = aux->sig;
    }
    if(almacemango != 0){
        promedio = suma / almacemango;
        cout << "El promedio de datos es: " << promedio << endl;
    }else{
        cout << "No hay datos para sacar promedio" << endl;
    }
    cout << endl;
}


void ListaLinealDoble::menuAdmin(void)
{
    int opcion;

    do{
        cout << "\n\nMENU PARA ADMINISTRAR LA LISTA" <<endl << endl
            << "1. Insertar al inicio." << endl
            << "2. Mostrar todos los elementos." << endl
            << "3. Mostrar promedio de datos. "<<endl
            << "4. Salir." << endl;
        cout << "Digite su opcion: ";
        cin >> opcion;
        switch(opcion){
            case 1:
                insInicio();
                break;
            case 2:
                mostrarTodos();
                break;
            case 3:
                promedio();
                break;
        }
    }while(opcion != 4);
}


int main(void)
{
    cout << endl;
    cout << "ADMINISTRACION DE UNA LISTA LINEAL DOBLEMANTE ENLAZADA" << endl << endl;

    ListaLinealDoble miLista;
    miLista.menuAdmin();

    cout << endl;
    return 0;
}

