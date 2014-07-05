// Investigando mas del programa, buscando otras maneras de realizar
#include <stdio.h>
#include <dos.h>
#include <stdlib.h>
#include <iostream.h>
#include <conio.h>
#include <string.h>
#include <time.h>

//clase evento
class Evento
{
private:
		int day, month, year;
		int Num;//contador del vector
		int Codigo; //codigo del evento
      char Nombre[15];//nombre del evento
      char Descripcion[30];// descripcion del evento
      char FechaInicio [10];
      char HoraInicio[5];
      char FechaFin[10];
      char HoraFin[5];
      Evento * Vec[30];//vector de eventos

   public:
   	Evento();
   	void setNum(int D){Num=D;}
  		void setCodigo(int C){Codigo=C;}
      void setNombre(char *A){strcpy(Nombre,A);}
      void setDescripcion(char *B){strcpy(Descripcion,B);}
      int getCodigo(){return Codigo;}
      int getNum(){return Num;}
      char *getNombre(){return Nombre;}
      char *getDescripcion(){return Descripcion;}

      //FUNCIONES
      int Opcion(); //menu de opciones
      int LeerEvento(); //lee un nuevo evento
      void MostrarEvento(); //muestra un evento
      void MostrarEventos(); //muestra todos los eventos
      void EventosHoy(); //funcion para ver eventos de hoy
      int ValidacionFecha(int day,int month,int year);
      void Menu();

};

/********************************************************
***********************COSNTRUCTOR***********************/

Evento::Evento(){
setNum(0);
setCodigo(-1);
setNombre("");
setDescripcion("");
};

/********************************************************
***********************VALIDACION DE FECHAS***********************/
int Evento::ValidacionFecha(day,month,year){
//Si el mes ingresado es Febrero, el año no es bisiesto y el día es mayor a 28 o menor o igual a cero
if((month == 2) && !((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) && ((day > 28) || (day <= 0)))
{cout<<"\n\nFecha incorrecta: Este mes solo tiene 28 d\241as";
return (0); }
//Si el mes ingresado es Febrero, el año es bisiesto y el día es mayor a 29 o menor o igual a cero
else if((month == 2) && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) && ((day > 29) || (day <= 0)))
{cout<<"\n\nFecha incorrecta: Este mes solo tiene 29 d\241as";
return (0);}
//Si el mes es distinto a Febrero (cualquiera de los demás meses que tengan 31 días) y el día es mayor a 31 o menor o igual a cero 
else if(((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) || (month == 10) || (month == 12)) && ((day > 31) || (day <= 0)))
{cout<<"\n\nFecha incorrecta: Este mes solo tiene 31 d\241as";
return (0);}
//Si el mes es distinto a Febrero (cualquiera de los demás meses que tengan 30 días) y el día es mayor a 30 o menor o igual a cero
else if(((month == 4) || (month == 6) || (month == 9) || (month == 11)) && ((day > 30) || (day <= 0)))
{cout<<"\n\nFecha incorrecta: Este mes solo tiene 30 d\241as";
return (0);}
//Si el mes es mayor a 12 o menor o igual a cero
else if((month > 12) || (month <= 0)) 
{cout<<"\n\nFecha incorrecta: El a\244o solo tiene 12 meses";
return (0);}
//Si la fecha es válida 
else{ 
//Si el día y mes son menores a 10, se antepone un cero a cada dato
if(day < 10 && month < 10)
cout<<"\n\nFecha ingresada: 0"<<day<<"/0"<<month<<"/"<<year;

//Si el día es menor a 10 y el mes es mayor o igual a 10, se antepone un cero al día 
else if(day < 10 && month >= 10)
cout<<"\n\nFecha ingresada: 0"<<day<<"/"<<month<<"/"<<year;

//Si el mes es menor a 10 y el día es mayor o igual a 10, se antepone un cero al mes
else if(day >= 10 && month < 10)
cout<<"\n\nFecha ingresada: "<<day<<"/0"<<month<<"/"<<year; 

//Si el día y el mes son mayor o iguales a 10, no se anteponen ceros
else
//Si el día es menor a 10 y el mes es mayor o igual a 10, se antepone un cero al día
cout<<"\nFecha ingresada: "<<day<<"/"<<month<<"/"<<year;
return (1);
}
}

/********************************************************
**********************FUNCION LEER NUEVO EVENTO**********/
int Evento::LeerEvento(){
int cod;
char nom[15];
char des[30];
char fecha[10];
cout<<"\n*** INGRESAR NUEVO EVENTO ***"<<endl;
cout<<"\nCodigo: "; cin>>cod;
cout<<"Nombre: "; gets(nom);
cout<<"Descripcion: "; gets(des);
cout<<"Fecha Inicio......... ";

do{
cout<<"\nIngrese el d\241a: ";cin>>day; //Día
cout<<"Ingrese el mes: ";cin>>month; //Mes
cout<<"Ingrese el a\244o: ";cin>>year; //Año
}while(ValidacionFecha(day,month,year)!=1);
//fecha:=day+'/'+month+'/'+year;
cout<<"\nHora Inicio: ";
cout<<"Fecha Fin: ";
cout<<"Hora Fin: ";
setCodigo(cod);
setNombre(nom);
setDescripcion(des);
return (1);
getch();
};

/*******************************************************
*********************FUNCION MOSTRAR EVENTO***********/
void Evento::MostrarEvento()
{
 cout<<"\nCodigo: "<<getCodigo();
 cout<<"\nNombre: "<<getNombre();
 cout<<"\nDescripcion: "<<getDescripcion();
};

/****************************************************************
*********************FUNCION MOSTRAR TODOS LOS EVENTOS***********/
void Evento::MostrarEventos()
{
	if (getNum()>0)
	{
		cout<<"\n Existen :"<<getNum()<<" Eventos..."<<endl;
		for (int i=0;i<getNum();i++)
			{
			Vec[i]->MostrarEvento();cout<<endl;
			}
	}
	else
	{
		clrscr();
		cout<<"\nNo hay Eventos Ingresados!!!";
   }
getch();
};

/*********************************************************
**********************EVWENTOS DE HOY**********************/
void Evento::EventosHoy()
{
//funcion obtener la fecha de hoy
char fecha[10];
time_t tiempo = time(0);
struct tm *tlocal = localtime(&tiempo);
char output[128];
strftime(output,128,"%d/%m/%Y",tlocal);
printf("%s\n",output);

strcpy(fecha,output);
cout<<fecha;
getch();
};


/*********************************************************
**********************MENU*******************************/

int Evento::Opcion()
{
clrscr();
int a;
//grafica de la interfaz
//eje y
for (int j=3;j<23;j++)
{
gotoxy(23,j);cout<<"*";
gotoxy(58,j);cout<<"*";
}
//eje x
for (int i=23;i<59;i++)
{
gotoxy(i,3);cout<<"*";
gotoxy(i,23);cout<<"*";
}
gotoxy(37,3);cout<<"<<<MENU>>>";
gotoxy(29,5);cout<<"<<CALENDARIO DE EVENTOS>>";
gotoxy(25,7);cout<<"1. Nuevo Evento";
gotoxy(25,9);cout<<"2. Ver Eventos de Hoy";
gotoxy(25,11);cout<<"3. Ver Eventos de toda la Semana";
gotoxy(25,13);cout<<"4. Buscar un Evento";
gotoxy(25,15);cout<<"5. Eliminar Evento";
gotoxy(25,17);cout<<"6. Mostrar Todos Los Eventos";
gotoxy(25,19);cout<<"7. Salir";
gotoxy(25,21);cout<<"Elija una opcion: ";
cin>>a;
return a;
}

/*********************************************************
**********************OPCIONES****************************/

void Evento::Menu(){
int op;
do{
	op=Opcion(); //llama a la funcion opcion
   switch(op){
   case 1:
   				clrscr();
               cout<<"\n NUEVO EVENTO";
               Vec[getNum()] = new Evento;
	            Vec[getNum()]->LeerEvento();
               setNum(getNum()+1);
               getch();
      break;
   case 2:
   				clrscr();
               cout<<"\n EVENTOS DE HOY ";
               EventosHoy();
               getch();
      break;
   case 3:
   				clrscr();
               cout<<"\n EN CONSTRUCCION";
               getch();
      break;
   case 4:
   				clrscr();
               cout<<"\n EN CONSTRUCCION";
               getch();
      break;
   case 5:
   				clrscr();
               cout<<"\n EN CONSTRUCCION";
               getch();
      break;
    case 6:
   				clrscr();
               cout<<"    <<<MOSTRAR TODOS LOS EVENTOS>>>";
               MostrarEventos();
      break;
      }
   }while (op!=7);
};


/*********************************************************
***************PROGRAMA PRINCIPAL************************/
void main()
{
  clrscr();
  Evento Obj;
  Obj.Menu();
}
