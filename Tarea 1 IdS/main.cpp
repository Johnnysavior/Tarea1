/*
Tarea 1 Ingenier�a de Software Primer Semestre 2014
Integrates: Jonathan Le�n Sepulveda. rut :17.771.116-0
            Francisca Sapiains Carrasco. rut: 17707063-7
            Cristian Mondaca Ruiz. rut: 15610050-1
           Profesor: Sebastian Salazar Molina
*/

#include <iostream>
#include <time.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#define _TIME_   //Macros para mostrar la fecha de compilaci�n


 //                          FUNCIONES/PROCEDIMIENTOS
//*********************************************************************************************************

//devuelve true si el a�o es bisiesto
bool EsBisiesto(int anio)
{
	if((anio%4==0)&&!(anio%100==0))
		return true;
	else if(anio%400==0)
		return true;

	return false;
}

//Comprueba que los valores del a�o, mes y dia sea correctos
bool ValidarDatos(int anio,int mes,int dia)
{
	if(anio<0||mes<0||dia<0)
	return false;
	else if(mes>12)return false;
	else if((dia>31)&&(mes==1||3||5||7||8||10||12))return false;
	else if((dia>30)&&(mes==4||5||9||11))return false;
	else if((dia>28)&&(mes==2)&&!EsBisiesto(anio))return false;
	else if((dia>29)&&(mes==2))return false;
	else return true;


}

//Notas personales para ver la cantidad de dias de cada mes.
// enero:31 dias
// febrero:28 (29 en bisiesto)
//marzo:31
//abril:30
//mayo:31
//junio:30
//julio:31
//agosto:31
//septiembre:30
//octubre:31
//noviembre:30
//diciembre:31

//Calcula el numero de la semana para cierta fecha
void NumSemana(int anio,int mes, int dia)

{

	int dias=dia; //contando los dias del mes actual
	int mesactual=1; //partire contando desde 1, es decir el mes de enero
	while(mesactual<mes)
	{
	    mesactual++;
		if(mesactual==1||3||5||7||8||10||12)dias=dias+31; //si el mes actual es cualquiera de los que tiene 31 dias, se suma esa cantidad al contador de dias.
		else if(mesactual==4||6||9||11)dias=dias+30;//si el mes actual es cualquiera de los que tiene 30 dias, se suma esa cantidad al contador de dias.
		else if((mesactual==2)&&(EsBisiesto(anio)))dias=dias+29;//si el a�o es bisiesto y el mes actual es febrero, se acumulan 29 dias
		else if((mesactual==2)&&(!EsBisiesto(anio))) dias=dias+28;  //si no es bisiesto, entonces solo se suman 28
	}
	cout<<"Numero de semana : "<<(dias/7)+1<<endl;// le sume 1 al resultado final porque este solo cuenta las semanas completas, y se pide el numero de la semana de esa fecha
}


//Obtiene el tiempo transcurrido desde la fecha puesta en la linea de comando y la fecha de la ejecucci�n del programa.
void ObtenerTiempo(int anio,int mes, int dia)
{
	int dia_actual,mes_actual,anio_actual;
	int anios,meses,dias;
	time_t ahora;
    struct tm *presente;
    time(&ahora);
	presente = localtime(&ahora);

	dia_actual=presente->tm_mday;
	mes_actual=presente->tm_mon+1;
	anio_actual=presente->tm_year+1900;
	cout<<"Fecha actual : "<<anio_actual<<"-"<<mes_actual<<"-"<<dia_actual<<endl;

	//Para ello se resta la fecha actual con la fecha de la linea de comando.

	anios=anio_actual-anio;
	meses=mes_actual-mes;
	dias=dia_actual-dia;

	//Si la diferencia de dias es negativa, le sumo la cantidad de dias del mes anterior de la fecha actual y le resto 1 a la diferencia de meses.
	if(dias<0)
	{
	  if(mes_actual-1==1||3||5||7||8||10||12)dias=dias+31;
	  else if(mes_actual-1==4||6||9||11)dias=dias+30;
	  else if((mes_actual-1==2)&&(EsBisiesto(anio_actual)))dias=dias+29;
	  else if((mes_actual-1==2)&&(!EsBisiesto(anio_actual)))dias=dias+28;
	  meses--;
    }

	//Si la diferencia de meses es negativa , le sumo 12 meses a esta y resto 1 a la catidad de a�os.
	if(meses<0)
	{
	   meses=meses+12;
	   anios=anios-1;
	}
	//Muestra resultado.
	cout<<"Difiere en "<<anios<<" anios, "<<meses<<" meses y "<<dias<<" la fecha ingresada con la de sistema."<<endl;
}

//                                 FIN/ FUNCIONES PORCEDIMIENTOS
//**********************************************************************************************************************************
int main(int argc,char **argv)
{

	//Si el primer parametro es -f...
	if(strcmp(*(argv+1),"-f")==0)
	{
	 if(*(argv+2)!=NULL) //Chequear que el segundo parametro no sea nulo.
	 {
	     string fecha,anio,mes,dia;   //Declaro algunas variables para guardar dichos parametros.
		 int aaaa,mm,dd;
		 fecha=(*(argv+2));
		 anio=fecha.substr(0,4);
		 mes=fecha.substr(5,2);
		 dia=fecha.substr(8,2);

		 mm=atoi(mes.c_str());   //Convertir los strings separados en valores enteros
		 dd=atoi(dia.c_str());
		 aaaa=atoi(anio.c_str());

		 if(!ValidarDatos(aaaa,mm,dd))  // Valido los datos
		 {
		         cout<<"La fecha ingresada no es Valida."<<endl;
				 exit(0);
		 }

		 NumSemana(aaaa,mm,dd);  // Mostrar numero de la semana de la fecha puesta
		 ObtenerTiempo(aaaa,mm,dd); //Obtener al diferencia de tiempo.

		 if(EsBisiesto(aaaa))   //Comporbar si el a�o ingresado es Bisiesto
		 {
		    cout<<aaaa<<" es un a�o bisiesto."<<endl;  //Manda mensaje en caso de ser asi.
		 }
	 }

	}

	// O si el primer parametro es -v...
	else if(strcmp(*(argv+1),"-v")==0)
	{
		 //Imprimo informaci�n de interes...
		    cout<<"Integrantes del grupo de trabajo : "<<endl;
			cout<<"1.Jonathan Leon S , rut:17.771.116-0"<<endl;
			cout<<"2.Francisca Sapiains Carrasco , rut:17707063-7"<<endl;
			cout<<"3.Cristian Mondaca Ruiz , rut:15610050-1"<<endl;
			cout<<"4.NO DISPONIBLE"<<endl;
			cout<<"Fecha de compilacion: ";
			puts(__DATE__);  //Fecha de compilacion.

	}
	//O cualquier otra cosa...
	else
	{
	      cout<<"Error: comando no reconocido."<<endl;
	}


}
