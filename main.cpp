#include <iostream>// Libreria de entrada y de salida
#include<stdlib.h>

using namespace std;
struct nodo{ //crear una estructura para generar un nodo
    int dato; //dato de entrada
    struct nodo *izq;//estructura de dato nodo para los datos por Izquierda
    struct nodo *der;//estructura de dato nodo para los datos por Derecha
};
typedef struct nodo *lista_doble; //Refenenciar y llamar de forma simpla lista



void menu(){//metodo para generar un menu de funcionalidades
    cout << "\n\t\tDouble Linked List\n\n";
          cout << "1. Insert from Left" << endl;
          cout << "2. Insert from Right" << endl;
          cout << "3. Print Left" << endl;
          cout << "4. Print by Right" << endl;
          cout << "5. Search Left" << endl;
          cout << "6. Search by Right" << endl;
          cout << "7. Exit" << endl;
          cout << "\n Enter an option:";


}
void insertarizq(lista_doble &cabeza,lista_doble &ultimo,int valor){//Metodo inesertar por izquierda
    lista_doble nodo1;//creacion del nodo
    nodo1=new(struct nodo);//creacion de una estructura apartir del nodo anteriormente creado
    nodo1->dato=valor;//nodo1 apundo a dato guarda el valor ingresado por el usuario
    nodo1->izq=NULL;//nodo1 apuntando por referencia por izquierda al comenzar se genera con null
    nodo1->der=NULL;//nodo1 apuntando por referencia por derecha al comenzar se genera con null
    if(cabeza==NULL){// condicion para cabeza si es igual a igual a null entra
        nodo1->izq=cabeza; //nodo1 por izquierda es igaul a cabeza
        cabeza=nodo1; //cabeza toma el valor del nodo1
        if(ultimo==NULL) //si ultimo es igual igual a null genera la siguiente condicion
            ultimo=cabeza;  //ultimo vuelve a ser la cabeza

    }else { //caso contrario  se realiza la siguinete codicion
        cabeza->der=nodo1; //cabeza apuntando por derecha toma el valor del nodo1
        nodo1->izq=cabeza;//nodo1 apuntando por izquierda toma el valor de cabeza
        cabeza=nodo1; //luego cabeza toma el valor del nodo1
    }

}
void imprimirizq(lista_doble &cabeza){//Funcion para imprimir por izquierda
    lista_doble lista_imprimir;//apartir de la lista_doble  crea una lista para imprimir los valores
    lista_imprimir=cabeza; //lista_imprimir es igual a cabeza

    while (lista_imprimir!=NULL) {//mientras lista_imprimir sea diferente de null entra a la siguiente condicion
        cout<<"-"<<lista_imprimir->dato; //imprime por pantalla los datos
        lista_imprimir=lista_imprimir->izq; //referencia las listas apartir del lado izquierdo para asi ser impresas las listas
    }
}

void insertarder(lista_doble &cabeza,lista_doble &ultimo,int valor){//Metodo inesertar por derecha
    lista_doble nodo1;//creacion del nodo
    nodo1=new(struct nodo);//creacion de una estructura apartir del nodo anteriormente creado
    nodo1->dato=valor;//nodo1 apundo a dato guarda el valor ingresado por el usuario
    nodo1->izq=NULL;//nodo1 apuntando por referencia por izquierda al comenzar se genera con null
    nodo1->der=NULL;//nodo1 apuntando por referencia por derecha al comenzar se genera con null
    if(ultimo==NULL){// condicion para ultimo si es igual a igual a null entra
        //nodo1 por derecha es igaul a ultimo
        nodo1->der=ultimo;
        //nodo1 apuntando por derecha toma el valor de ultimo
        ultimo=nodo1;
        //ultimo toma el valor de nodo1
        if(cabeza==NULL)//si cabeza es igual igual a null
            //cabeza toma el valor de ultimo valor ingreasado
            cabeza=ultimo;
        //caso contario
    }else{

        ultimo->der=nodo1; //ultimo por derecha toma el valor de nodo1
        nodo1->izq=ultimo;//nodo1 por izquierda toma el valor de ultimo
        ultimo=nodo1;//ultimo es igual a nodo1
    }
}
void imprimirder(lista_doble &ultimo){//Funcion para imprimir por derecha
    lista_doble lista_imprimir;//apartir de la lista_doble  crea una lista para imprimir los valores
    lista_imprimir=ultimo;//lista_imprimir es igual a ultimo
    while (lista_imprimir!=NULL) {//mientras lista_imprimir sea diferente de null entra a la siguiente condicion
        cout<<"-"<<lista_imprimir->dato;//imprime por pantalla los datos
        lista_imprimir=lista_imprimir->der;//referencia las listas apartir del lado izquierdo para asi ser impresas las listas
    }
}
void buscarizq(lista_doble &cabeza ,int valor){//Metodo para buscar ,recibe la lista con el valor en la cabeza y el valor que se va a buscar
    lista_doble lista_buscar;//crea una lista buscar apartir de una lista doble para buscar dentro de la lista el numero que se desea buscar
    lista_buscar=cabeza;//Lista_buscar toma el valor de la cabeza
    int contador=1; //contador que se genera apartir de 1
    while (lista_buscar!=NULL) { //Mientras Lista_buscar se diferente de null realiza la siguiente condicion
        if(lista_buscar->dato==valor){//lista_buscar apuntando a los datos si un numero en esa lista es igual igual al numero ingresado

            cout<<"Valor encontrado en la posicion"<<contador<<endl;//Mensaje de la busqueda y en que posicion se encuentra
        }
        contador++;//contador aumenta mas 1

        lista_buscar=lista_buscar->izq;//lista_buscar recibe el valor buscado por referencia por izquierda

    }

}

void buscarder(lista_doble &ultimo,int valor){//Metodo para buscar ,recibe la lista con el valorultimo y el valor que se va a buscar
    lista_doble lista_buscar;//crea una lista buscar apartir de una lista doble para buscar dentro de la lista el numero que se desea buscar
    lista_buscar=ultimo;//Lista_buscar toma el valor de ultimo
    int contador=0;//contador que se genera apartir de 0
    while (lista_buscar!=NULL) {//Mientras Lista_buscar se diferente de null realiza la siguiente condicion
        if(lista_buscar->dato==valor){
            cout<<"Valor encontrado en la posicion"<<contador<<endl;//Mensaje de la busqueda y en que posicion se encuentra
        }
        contador++;//contador aumenta mas 1
        lista_buscar=lista_buscar->der;//lista_buscar recibe el valor buscado por referencia por derecha
    }
}
int main()

{

    lista_doble listaizq=NULL;//se crean apartir de las lista_doble  se crea una lista por izquierda que inicia con valor null
    lista_doble listader=NULL;//se crean apartir de las lista_doble  se crea una lista por derecha que inicia con valor null
    //Variables
    int opcion;
    int valor;
    do{
        menu();
        cin>>opcion;
        //lectura de la opcion
        switch (opcion) {
        case 1:
           cout << "\n Left Insert:";cin>>valor;//Recibiendo el valor para ingresar por izquierda
            insertarizq(listaizq,listader,valor);
            break;
        case 2:
            cout << "\n Insert from Right:";cin>>valor;//Recibiendo el valor para ingresar por derecha
            insertarder(listaizq,listader,valor);
            break;
        case 3:
           cout << "\n list on the left:";//Recibiendo la lista por izquierda para realizar la funcion
            imprimirizq(listaizq);
            break;
        case 4:
            cout << "\n list by Right:";//Recibiendo la lista por derecha para realizar la funcion
            imprimirder(listader);
            break;
        case 5:
            cout << "\n\n SEARCH LEFT ELEMENTS \n\n";
                        cout << "\n Number to search for Left:";cin>>valor;
            buscarizq(listaizq,valor);//recibe la lista izquierda y el valor que desea buscar
            break;
        case 6:
            cout<<"\n\n BUSCAR ELEMENTOS POR DERECHA \n\n";
            cout<<"\n Numero a buscar por Derecha: ";
            buscarder(listader,valor);//recibe la lista por derecha y el valor que desea buscar
            break;
        default:
            cout<<" Error: seleccione una opcion valida "<<endl;
            break;
        }
    }while (opcion!=7);
    return 0;

}

