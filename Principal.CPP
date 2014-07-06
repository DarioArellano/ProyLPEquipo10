// un poco mas de correciones 
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

      int Num;//contador del vector
		char Codigo[5]; //codigo del evento
      char Nombre[15];//nombre del evento
      char Descripcion[30];// descripcion del evento
      char FechaInicio [10];
      char HoraInicio[6];
      char FechaFin[10];
      char HoraFin[6];
      Evento * Vec[30];//vector de eventos

   public:
   	Evento();
   	void setNum(int D){Num=D;}
  		void setCodigo(char *C){strcpy(Codigo,C);}
      void setNombre(char *A){strcpy(Nombre,A);}
      void setDescripcion(char *B){strcpy(Descripcion,B);}
      void setFechaInicio(char *E){strcpy(FechaInicio,E);}
      void setFechaFin(char *F){strcpy(FechaFin,F);}
      void setHoraInicio(char *G){strcpy(HoraInicio,G);}
      void setHoraFin(char *H){strcpy(HoraFin,H);}
      char *getCodigo(){return Codigo;}
      int getNum(){return Num;}
      char *getNombre(){return Nombre;}
      char *getDescripcion(){return Descripcion;}
      char *getFechaInicio(){return FechaInicio;}
      char *getHoraInicio(){return HoraInicio;}
      char *getFechaFin(){return FechaFin;}
      char *getHoraFin(){return HoraFin;}
      //FUNCIONES
      int Opcion(); //menu de opciones
      void LeerEvento(); //lee un nuevo evento
      void MostrarEvento(); //muestra un evento
      void MostrarEventos(); //muestra todos los eventos
      void EventosHoy(); //funcion para ver eventos de hoy
      int ValidacionFecha(int day,int month,int year);
      int ValidacionHora(int hora,int min);
      void Menu();
};

/********************************************************
***********************COSNTRUCTOR***********************/

Evento::Evento(){
setNum(0);
setCodigo("");
setNombre("");
setDescripcion("");
setFechaInicio("");
setHoraInicio("");
setFechaFin("");
setHoraFin("");
};

/********************************************************
***********************VALIDACION DE FECHAS**************/
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
{cout<<"Fecha ingresada: 0"<<day<<"/0"<<month<<"/"<<year;
return (1);}
//Si el día es menor a 10 y el mes es mayor o igual a 10, se antepone un cero al día
else if(day < 10 && month >= 10)
{cout<<"Fecha ingresada: 0"<<day<<"/"<<month<<"/"<<year;
return (1);}
//Si el mes es menor a 10 y el día es mayor o igual a 10, se antepone un cero al mes
else if(day >= 10 && month < 10)
{cout<<"Fecha ingresada: "<<day<<"/0"<<month<<"/"<<year;
return (1);}
//Si el día y el mes son mayor o iguales a 10, no se anteponen ceros
else{
//Si el día es menor a 10 y el mes es mayor o igual a 10, se antepone un cero al día
cout<<"Fecha ingresada: "<<day<<"/"<<month<<"/"<<year;
return (1);}
}
}
/********************************************************
***********************VALIDACION DE HORAS**************/
int Evento::ValidacionHora(hora,min){
if ((hora<0)||(hora>23)||(min<0)||(min>59))
{
	cout<<"Hora incorrecta!!! Hora: 0-23  min: 00-59";
	return (0);
}
else
{
	if(min<10)
	{
	cout<<"Hora Ingresada: "<<hora<<"H0"<<min;
	}
	else
	{
   cout<<"Hora Ingresada: "<<hora<<"H"<<min;
	}
}
return (1); //si devuelve 1 es hora valida
}


/********************************************************
**********************FUNCION LEER NUEVO EVENTO**********/
void Evento::LeerEvento(){
int day, month, year, hora, min;
char cod[5];
char nom[15];
char des[30];
char FechaI [10];
char HoraI [5];
char FechaF [10];
char HoraF [5];
cout<<"\n*** INGRESAR NUEVO EVENTO ***"<<endl;
cout<<"\nCodigo: "; gets(cod);
cout<<"Nombre: "; gets(nom);
cout<<"Descripcion: "; gets(des);
setCodigo(cod);
setNombre(nom);
setDescripcion(des);
/*********************************************/
cout<<"\nDATOS DE INICIO DEL EVENTO >>> ";
do{
cout<<"\nIngrese el d\241a: ";cin>>day; //Día
cout<<"Ingrese el mes: ";cin>>month; //Mes
cout<<"Ingrese el a\244o: ";cin>>year; //Año
}while(ValidacionFecha(day,month,year)!=1);

if((day<10)&&(month<10))
{
sprintf(FechaI, "0%d/0%d/%d",day,month,year);
}
else
{
	if (day<10)
	{
		 sprintf(FechaI, "0%d/%d/%d",day,month,year);
	}
	else
	{
		if(month<10)
		{
      sprintf(FechaI, "%d/0%d/%d",day,month,year);
		}
      else
      sprintf(FechaI, "%d/%d/%d",day,month,year);
	}
}

setFechaInicio(FechaI);
do{
cout<<"\nIngrese Hora: ";cin>>hora; //Hora
cout<<"Ingrese min: ";cin>>min; //Min
}while(ValidacionHora(hora,min)!=1);
sprintf(HoraI, "%dH%d",hora,min);
setHoraInicio(HoraI);

/*****************************************/
cout<<"\n\nDATOS DE FIN DEL EVENTO >>> ";
do{
cout<<"\nIngrese el d\241a: ";cin>>day; //Día
cout<<"Ingrese el mes: ";cin>>month; //Mes
cout<<"Ingrese el a\244o: ";cin>>year; //Año
}while(ValidacionFecha(day,month,year)!=1);

if((day<10)&&(month<10))
{
sprintf(FechaF, "0%d/0%d/%d",day,month,year);
}
else
{
	if (day<10)
	{
		 sprintf(FechaF, "0%d/%d/%d",day,month,year);
	}
	else
	{
		if(month<10)
		{
      sprintf(FechaF, "%d/0%d/%d",day,month,year);
		}
      else
      sprintf(FechaF, "%d/%d/%d",day,month,year);
	}
}
setFechaFin(FechaF);
do{
cout<<"\nIngrese Hora: ";cin>>hora; //Hora
cout<<"Ingrese min: ";cin>>min; //Min
}while(ValidacionHora(hora,min)!=1);
sprintf(HoraF, "%dH%d",hora,min);
/***************************************/
setHoraFin(HoraF);
};

/*******************************************************
*********************FUNCION MOSTRAR EVENTO***********/
void Evento::MostrarEvento()
{
 cout<<"\nCodigo: "<<getCodigo();
 cout<<"\nNombre: "<<getNombre();
 cout<<"\nDescripcion: "<<getDescripcion();
 cout<<"\nFecha inicio: "<<getFechaInicio();
 cout<<"\nHora inicio: "<<getHoraInicio();
 cout<<"\nFecha Fin: "<<getFechaFin();
 cout<<"\nHora Fin: "<<getHoraFin()<<endl;
};

/****************************************************************
*********************FUNCION MOSTRAR TODOS LOS EVENTOS***********/
void Evento::MostrarEventos()
{
	if (getNum()!=0)
	{
		cout<<"\n Existen :"<<getNum()<<" Eventos..."<<endl;
		for (int i=0;i<getNum();i++)
			Vec[i]->MostrarEvento();
	}
	else
	{
		clrscr();
		cout<<"\nNo hay Eventos Ingresados!!!";
   }
getch();
};

/*********************************************************
**********************EVENTOS DE HOY**********************/
void Evento::EventosHoy()
{
if (getNum()!=0)
{
//funcion obtener la fecha de hoy
char fecha[10]; //fecha de hoy para buscar
time_t tiempo = time(0);
struct tm *tlocal = localtime(&tiempo);
char output[128];
strftime(output,128,"%d/%m/%Y",tlocal);
printf("%s\n",output);

strcpy(fecha,output);

for(int i=0;i<getNum();i++)
   {
    	if (strcmp(Vec[i]->getFechaInicio(),fecha)==0)
      	Vec[i]->MostrarEvento();
   }
}
else
{
	cout<<"\nNo hay eventos hoy!!!";
}

getch();
};

/*********************************************************

/*********************************************************
**********************MENU*******************************/

int Evento::Opcion()
{
clrscr();
int a;
//grafica de la interfaz
//eje y
for (int j=3;j<21;j++)
{
gotoxy(21,j);cout<<"*";
gotoxy(58,j);cout<<"*";
}
//eje x
for (int i=21;i<59;i++)
{
gotoxy(i,3);cout<<"*";
gotoxy(i,21);cout<<"*";
}
gotoxy(36,3);cout<<"<<<MENU>>>";
gotoxy(29,5);cout<<"<<CALENDARIO DE EVENTOS>>";
gotoxy(25,7);cout<<"1. Nuevo Evento";
gotoxy(25,9);cout<<"2. Ver Eventos de Hoy";
gotoxy(25,11);cout<<"3. Ver Eventos de toda la Semana";
gotoxy(25,13);cout<<"4. Buscar un Evento";
gotoxy(25,15);cout<<"5. Mostrar Todos Los Eventos";
gotoxy(25,17);cout<<"6. Salir";
gotoxy(25,19);cout<<"Elija una opcion: ";
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
      break;
   case 2:
   				clrscr();
               cout<<"\n EVENTOS DE HOY ";
               EventosHoy();
               getch();
      break;
   case 3:
   				clrscr();
               cout<<"\n EVENTOS ESTA SEMANA";
               getch();
      break;
   case 4:
   				clrscr();
               cout<<"\n BUSCAR EVENTO";
               getch();
      break;
    case 5:
   				clrscr();
               cout<<"    <<<MOSTRAR TODOS LOS EVENTOS>>>";
               MostrarEventos();
      break;
      }
   }while (op!=6);
};


/*********************************************************
***************PROGRAMA PRINCIPAL************************/
void main()
{
  clrscr();
  Evento Obj;
  Obj.Menu();
}
