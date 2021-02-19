/*
	Luis Antonio García	A01021865
	Mauricio Cassab	A01025475

	Actividad 1: Aritmética de apuntadores
	Programación avanzada

	18-Febrero-2021

    Códigos de referencia
    main.c de los ejemplos de la clase:

    Ejemplo 1-1. Estructuras y Uniones
    Ejemplo 1-3. Apuntadores
    Ejemplo 1-4. Personas
    Ejemplo 1-5. Biblioteca


*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//declaracion de funciones
void ejercicio1();
void ejercicio2();
void crear_preguntas();
void agregar_personas();
void contestar_encuesta();

void imprimir(int * , int *, int);
void imprimir2();


//definicion de estructuras a usar en el ejercicio 2
typedef struct {
    char* nombre;
    int edad;
    int* respuestas;
} persona;

typedef struct{
//los contadores en esta estructura sirven para almacenar cuantas personas responden de cada rango de edad
    int num;
    char* descripcion;
    char* res_1;
    int contador1;
    char* res_2;
    int contador2;
    char* res_3;
    int contador3;
    char* res_4;
    int contador4;
    char* res_5;
    int contador5;
    char* res_6;
}pregunta;


int main(int argc, const char * argv[]){
//variable que se usa para responder que ejercico se responde
int res;

printf("¿Qué ejercico se va a resolver?:\n1\no\n2\n\n");
scanf("%d", &res);
//si la respuesta es 1 se realiza el primer ejercicio de la actividad
if(res==1){
ejercicio1();
}
//con la respuesta 2 se realiza el segundo ejercicio de la actividad
else if(res==2){
ejercicio2();
}
//si la opción no es válida se hace un print indicando que no es válido y posterior se sale del programa
else{
fprintf(stderr,"\nOpción no válida\n");//mensaje de error
return 1;
}


return 0;
}



void ejercicio1(){
int n;//variable que servira para indicar el rango de cuantas personas van a responder la pregunta
int nreset;//variable para mantener el valor de n
int nres=6;//variable indicando el total de respuestas de cada pregunta
int total;//personas que realmente respondieron la pregunta


//ciclo for unicamente para saber en que número de pregunta nos encontramos    
for(int i =1;i<11;i++){
printf("\t\t Pregunta %d\n\n",i);
//memory allocation de el total de respuestas
int * respuesta = (int *) malloc(nres * sizeof(int));

printf("¿Cuántas personas van a responder la pregunta?: ");
    scanf("%d", &n);
    n=n+1;
    nreset=n;
//creacion aleaotoria de total de respuestas que tendrá cada opción de la pregunta  
srand((int) time(NULL));

//auxiliares para acceder a las posiciones del arreglo dinámico
int * aux;
int *fin = respuesta + nres;

//ciclo for que genera aleatoriamente el toal de respuestas de cada opción
for(aux=respuesta;aux<fin;aux++){
 *aux = (rand() % n);
 n= n- *aux;//diferencia de n y el aux para que el total de respuestas en la pregunta no exceda el n inicial
}

total = nreset - n;
imprimir(respuesta, fin,total);//llamada a función para imprimir los histogramas
free(respuesta);//liberación de memoria
}
}

void ejercicio2(){
    int np=0;//numero de preguntas que tendrá la encuesta
    int n=0;//número de personas que responderan la encuesta

    
    printf("¿Cuántas preguntas va a tener la encuesta? ");
    scanf("%d", &np);
    //memory allocation para el arreglo dinámico de preguntas
    pregunta* lista_preguntas = (pregunta*) malloc(sizeof(pregunta)* np);
    
    //auxiliares para acceder a los elementos del arreglo
    pregunta* aux_pregunta = lista_preguntas;
    pregunta* final_pregunta = lista_preguntas + np;
    
    //llamada para la función que crea las preguntas
    crear_preguntas(lista_preguntas,aux_pregunta,final_pregunta);
    
    printf("¿Cuántas personas vas a crear? ");
    scanf("%d",&n);
    //memory allocation para el arreglo dinámico de preguntas
    persona* lista_persona = (persona*) malloc(sizeof(persona) * n);

    //auxiliares para acceder a los elementos del arreglo
    persona* aux_persona = lista_persona;
    persona* final_persona = lista_persona + n;


    //llamada para la función que crea las personas
    agregar_personas(aux_persona,final_persona,lista_persona);
    
    
    //llamada a la función para contestar la encuesta
    contestar_encuesta(aux_persona,final_persona,lista_persona,aux_pregunta,final_pregunta,lista_preguntas);
    
    //función para imprimir el histograma con rango de edades
    imprimir2(aux_pregunta,final_pregunta,lista_preguntas,n);

    //liberación de memoria
    free(lista_preguntas);
    free(lista_persona);
    

        
    
}

void crear_preguntas(pregunta* lp, pregunta* auxp, pregunta* finalp){
	
	int nump=1;
	
	//ciclo for para llenar el arreglo de estructura de preguntas dependiendo de cuantas se crearon
	for(auxp=lp;auxp<finalp;auxp++){
	
	printf("Agregue la descripción de la pregunta %d \n",nump);
	
	auxp->descripcion = (char *) malloc(sizeof(char) * 50);
	scanf("%s",auxp->descripcion);
	
	auxp->res_1 =(char*)malloc(sizeof(char)*50);
        printf("Cual es la respuesta numero 1: \n");
        scanf("%s",auxp->res_1);

        auxp->res_2 =(char*)malloc(sizeof(char)*50);
        printf("Cual es la respuesta numero 2: \n");
        scanf("%s",auxp->res_2);

        auxp->res_3 =(char*)malloc(sizeof(char)*50);
        printf("Cual es la respuesta numero 3: \n");
        scanf("%s",auxp->res_3);

        auxp->res_4 =(char*)malloc(sizeof(char)*50);
        printf("Cual es la respuesta numero 4: \n");
        scanf("%s",auxp->res_4);

        auxp->res_5 =(char*)malloc(sizeof(char)*50);
        printf("Cual es la respuesta numero 5: \n");
        scanf("%s",auxp->res_5);

        auxp->res_6 =(char*)malloc(sizeof(char)*50);
        printf("Cual es la respuesta numero 6: \n");
        scanf("%s",auxp->res_6);
	nump++;
	}

}

void agregar_personas(persona* aux, persona* final, persona* lista_persona){
    //ciclo for para llenar el arreglo de personas dependiendo de cuantas se crearon
    for (aux=lista_persona; aux< final; aux++)
        {
            
            aux->nombre =(char*)malloc(sizeof(char)*30);
            printf("Cual es tu Nombre: \n");
            scanf("%s", aux->nombre);

            printf("Cual es tu edad \n");
            scanf("%d", &aux->edad);
            if(aux->edad >=17 && aux->edad <=121){
            aux->edad=aux->edad;
            }
            else{
            printf("Edad no válida\n");
            exit(0);
            } 
            
            aux->respuestas = (int*)malloc(sizeof(int)*10);
            
            

        }
}

void contestar_encuesta(persona* aux, persona* final,persona* lp, pregunta* auxp,pregunta* finalp,pregunta* lpr){
	int res;//variable para seleccionar la respuesta
	//ciclo for para contestar las preguntas con cada usuario registrado
	for(aux=lp;aux<final;aux++){
	        //ciclo for que despliega todas las preguntas
		for(auxp=lpr;auxp<finalp;auxp++){
		printf("Estimad@ %s responda la siguiente pregunta (seleccione el número del 1-6)\n%s\n\n",aux->nombre,auxp->descripcion);
		printf("\n 1.- %s",auxp->res_1);
		printf("\n 2.- %s",auxp->res_2);
		printf("\n 3.- %s",auxp->res_3);
		printf("\n 4.- %s",auxp->res_4);
		printf("\n 5.- %s",auxp->res_5);
		printf("\n 6.- %s",auxp->res_6);
		printf("\n");
		scanf("%d",&res);
		aux->respuestas++;
		if(aux->edad>=18 && aux->edad<=25){
		auxp->contador1++;//aumentar el contador si la edad del encuestado está en este rango
		}
		else if(aux->edad>25 && aux->edad<=35){
		auxp->contador2++;//aumentar el contador si la edad del encuestado está en este rango
		}
		else if(aux->edad>35 && aux->edad<=45){
		auxp->contador3++;//aumentar el contador si la edad del encuestado está en este rango
		}
		else if(aux->edad>45 && aux->edad<=65){
		auxp->contador4++;//aumentar el contador si la edad del encuestado está en este rango
		}
		else if(aux->edad>65 && aux->edad<120){
		auxp->contador5++;//aumentar el contador si la edad del encuestado está en este rango
		}
		
		
		}
	}
}

void imprimir(int * inicio, int * fin, int total)
{    
    int * aux;
    int i=1;//variable para imprimir el número de la respuesta
    printf("No.\tRespuesta\tFrecuencia\n");
    //ciclo for para imprimir la pregunta n con sus respuestas y total de respuestas de cada opción
    for (aux = inicio; aux < fin; ++aux) {
    	printf("\n%d",i);
    	i++;
        printf("\t%d\t", *aux);
        printf("\t");
        //ciclo for para imprimir el caracter * dependiendo del número de respuestas de la opción
    for(int j=0;j<*aux;j++){
    printf("*");
    }
        printf("\n");

    }
    
    printf("\nUn total de %d respondieron esta pregunta. \n\n", total);//imprime el total de personas que contestaron la pregunta
}

void imprimir2(pregunta* auxp,pregunta* finalp,pregunta* lpr, int n){

	printf("Histograma de la encuesta \n\n");
 	
 	//imprime el total de respuestas por rango de edad
	printf("Rango de edad\tTotal\n");
	printf("18-25\t\t%d\n",auxp->contador1);
	printf("26-35\t\t%d\n",auxp->contador2);
	printf("36-45\t\t%d\n",auxp->contador3);
	printf("46-65\t\t%d\n",auxp->contador4);
	printf("66-120\t\t%d\n\n",auxp->contador5);
	printf("Total de encuestados: %d\n",n);//total de personas que respondieron la encuesta

}




