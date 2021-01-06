//#include <conio.h>
#include <stdlib.h>     /* srand, rand */
#include <iostream>
#include <cmath>
#include <time.h>
#define PI 3.141592653589793

//AUTORES: Catalina Bustos Z, Jorge Tobar Q, Nicolas Arenas M, Matias Silva E.
//Asignatura: Simulacion de Sistemas
// GRUPO 2
// FECHA: 01 DE OCTUBRE DE 2020
using namespace std;

struct Montecarlo
{
    double distancia, pi;
    double adentro, afuera = 0;
    double total;
}montecarlo[100];

//coordenadas x e y aleatorias (constructor)
void Aleatorios(double& x, double& y);


void MetodoMontecarlo(){
	system("cls");
    double veces, n;
    double x=0,y=0;
	cout<<"\n\t\t\t +++++ METODO MONTECARLO +++++\n\n";
    cout<<" Cuantas veces desea ejecutar el metodo MONTECARLO? : ";cin>>veces;

    for (int i=0; i<veces; i++){
        cout<<"\n Ingrese el numero de dardos a simular["<<i+1<<"] : " ;cin>>n;
        fflush(stdin);
        for (int j = 0; j< n; j ++){

            Aleatorios(x,y);
            //calcular la distancia de ese punto aleatorio y guardarla en el vector
            montecarlo[i].distancia=sqrt(pow(x,2) + pow(y,2));
            //si la distancia es menor o igual a uno el dardo esta adentro, sino esta afuera
            if (montecarlo[i].distancia<=1)
                montecarlo[i].adentro++;
            else
                montecarlo[i].afuera++;
            //suma al total de dardos afuera+adentro
            montecarlo[i].total=montecarlo[i].adentro+montecarlo[i].afuera;
            //generar numero pi aproximado por el metodo de montecarlo
            montecarlo[i].pi = (4*montecarlo[i].adentro)/montecarlo[i].total;

        }
    }
               cout<<"\n\n--METODO MONTECARLO--"<<endl<<endl;
        cout <<"\t |Aciertos | \t";
        cout <<"\t |Afuera |  \t";
        cout <<"\t |Numero pi |\n";
        for (int i= 0; i< veces; i++){
            cout <<"["<<i+1<<"]";
            cout <<"\t   "<< montecarlo[i].adentro<<"\t\t\t "<< montecarlo[i].afuera<<"\t\t\t  "<<montecarlo[i].pi<< "\n";
        }

}


void MetodoBuffon(){
	system("cls");
        srand(time(NULL));
    double l = 5;
    double x, o;
    double rad;
    double cantidadAgujas= 0;
    double valor = 0;
    double N = 0;
    cout<<" ------!  METODO DE BUFFON ! ------";
    cout<<"\n * Ingrese cantidad de intentos: ";cin>>N;
    for (int i = 0 ; i<N; i++){
        valor = 0;
        x = ((float)rand()/(float)(RAND_MAX)) * 2.5;
        o = ((float)rand()/(float)(RAND_MAX)) * PI/2;
        rad = o*0.0174533;
        valor = (l/2)*sin(o);

       // cout<<"\nx = "<<x<<" \nangulo: "<<o<<" \nradianes: "<<rad<<"\n valor: "<<valor;
        if (x<=valor)
            cantidadAgujas++;
            //cout<<"\nagujas: "<<cantidadAgujas;
    }
    double total = 0;
    total += (2*N*l)/(cantidadAgujas*l);
    cout<<"\n Se ha lanzado un total de "<<N<<" agujas y han intersectado solo "<<cantidadAgujas;
    cout<<"\n **El valor PI aproximado por el Metodo de Buffon es = "<<total<<"\n";
    cout<<"----------------------------------------------------------";
}

void menu(){
	int error=0;
	int reinicio=1;
    while(reinicio==1){
    system("cls");
     fflush(stdin);

    cout<<"\n\t\t\t------- METODOS PARA APROXIMAR EL VALOR DE PI -------";
    cout<<"\n\n    Metodo 	         Numero ";
    cout<<"\n\n  * Montecarlo 	       <-- [1]";
    cout<<"\n  * Aguja de Buffon    <-- [2] ";
    char seleccion='0';
 	if(error==1)
     		cout<<"\n\n X [ERROR] La opcion ingresada no es valida!, intentalo denuevo.\n";
    cout<<"\n\n * Ingrese el numero del metodo que desea ejecutar: ";cin>>seleccion;
    if (seleccion != NULL) {
    if (seleccion == '1'){
        MetodoMontecarlo();
        reinicio=0;}
    else if(seleccion=='2'){
        MetodoBuffon();
        reinicio=0;}
    else{
        error=1;
        reinicio=1;
        }
    }
    }
}
int main()
{
	int respuesta=1;
	while(respuesta==1){
	menu();
	cout << "\n\n\t\tVOLVER Al MENU?"<<"\n +++Digite 1 si quiere volver al menu, para terminar digite cualquier otro+++\n";cin>>respuesta;
}
    return 0;
}

void Aleatorios(double& x,double& y) {

    x=0+rand()%(1001)/1001.0;
    y=0+rand()%(1001)/1001.0;
}
