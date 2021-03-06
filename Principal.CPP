//INTEGRANTES
//1.- Dar�o Arellano   789
//2.- Eder Naranjo     695
//PROYECTO FINAL LISTO
//CALENDARIO DE EVENTOS.
#include <stdio.h>
#include <dos.h>
#include <stdlib.h>
#include <iostream.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <fstream>

ofstream Archivo("C:\BC5\Eventos.txt");//se crea el archivo 
//clase evento
class Evento
{
private:

      int Num;//contador del vector
		char Codigo[5], Nombre[15], Descripcion[30];
      char FechaInicio [12], HoraInicio[7], FechaFin[12], HoraFin[7];
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
      int ValidacionFecha(int day,int month,int year);//fucnion validacion
      int ValidacionHora(int hora,int min);//funcion validacion
		void Buscar();//funcion buscar
void Semana();
      void Menu();
		void Recuadro(int x1,int y1,int x2,int y2,int z);//funcion grafica
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
***********************FUNCION RECUADRO**************/
void Evento::Recuadro(x1,y1,x2,y2,z)
{
clrscr();
//grafica de la interfaz
//eje y
for (int j=y1;j<y2;j++)
{
gotoxy(x1,j);printf("%c", z);
gotoxy(x2,j);printf("%c", z);
}
//eje x
for (int i=x1;i<(x2+1);i++)
{
gotoxy(i,y1);printf("%c", z);
gotoxy(i,y2);printf("%c", z);
}
}

/********************************************************
***********************VALIDACION DE FECHAS**************/
int Evento::ValidacionFecha(day,month,year){
//Si el mes ingresado es Febrero, el a�o no es bisiesto y el d�a es mayor a 28 o menor o igual a cero
if((month == 2) && !((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) && ((day > 28) || (day <= 0)))
{cout<<"\n\nFecha incorrecta: Este mes solo tiene 28 d\241as";
return (0); }
//Si el mes ingresado es Febrero, el a�o es bisiesto y el d�a es mayor a 29 o menor o igual a cero
else if((month == 2) && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) && ((day > 29) || (day <= 0)))
{cout<<"\n\nFecha incorrecta: Este mes solo tiene 29 d\241as";
return (0);}
//Si el mes es distinto a Febrero (cualquiera de los dem�s meses que tengan 31 d�as) y el d�a es mayor a 31 o menor o igual a cero
else if(((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) || (month == 10) || (month == 12)) && ((day > 31) || (day <= 0)))
{cout<<"\n\nFecha incorrecta: Este mes solo tiene 31 d\241as";
return (0);}
//Si el mes es distinto a Febrero (cualquiera de los dem�s meses que tengan 30 d�as) y el d�a es mayor a 30 o menor o igual a cero
else if(((month == 4) || (month == 6) || (month == 9) || (month == 11)) && ((day > 30) || (day <= 0)))
{cout<<"\n\nFecha incorrecta: Este mes solo tiene 30 d\241as";
return (0);}
//Si el mes es mayor a 12 o menor o igual a cero
else if((month > 12) || (month <= 0))
{cout<<"\n\nFecha incorrecta: El a\244o solo tiene 12 meses";
return (0);}
//Si la fecha es v�lida
else{
//Si el d�a y mes son menores a 10, se antepone un cero a cada dato
if(day < 10 && month < 10)
{cout<<"Fecha ingresada: 0"<<day<<"/0"<<month<<"/"<<year;
return (1);}
//Si el d�a es menor a 10 y el mes es mayor o igual a 10, se antepone un cero al d�a
else if(day < 10 && month >= 10)
{cout<<"Fecha ingresada: 0"<<day<<"/"<<month<<"/"<<year;
return (1);}
//Si el mes es menor a 10 y el d�a es mayor o igual a 10, se antepone un cero al mes
else if(day >= 10 && month < 10)
{cout<<"Fecha ingresada: "<<day<<"/0"<<month<<"/"<<year;
return (1);}
//Si el d�a y el mes son mayor o iguales a 10, no se anteponen ceros
else{
//Si el d�a es menor a 10 y el mes es mayor o igual a 10, se antepone un cero al d�a
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
	return (0); //devuelve cuando es incorrecta la hora
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
clrscr();
Recuadro(1,1,80,8,177);//se grafica el cuadro
int day, month, year, hora, min;
char cod[5], nom[15], des[30], FechaI [12], HoraI [7], FechaF [12], HoraF [7];
gotoxy(30,2);cout<<"RECOMENDACIONES";
gotoxy(3,4);cout<<"1. Los datos de las fechas si son menores a 10 anteponer el 0.";
gotoxy(3,5);cout<<"2. El Ingreso de Fechas es por separado 1ro dia, 2do mes, 3ro Anio.";
gotoxy(3,6);cout<<"3. Los formatos de hora son 0-23 y minutos de 0-59.";
gotoxy(1,10);cout<<"*** INGRESAR NUEVO EVENTO ***"<<endl;
cout<<"\nCodigo: "; gets(cod);
cout<<"Nombre: "; gets(nom);
cout<<"Descripcion: "; gets(des);
/*********************************************/
cout<<"\nDATOS DE INICIO DEL EVENTO >>> ";
do{
cout<<"\nIngrese el d\241a: ";cin>>day; //D�a
cout<<"Ingrese el mes: ";cin>>month; //Mes
cout<<"Ingrese el a\244o: ";cin>>year; //A�o
}while(ValidacionFecha(day,month,year)!=1);

if((day<10)&&(month<10))
{
sprintf(FechaI, "0%d/0%d/%d",day,month,year);
}
else
{
	if (day<10)
		 sprintf(FechaI, "0%d/%d/%d",day,month,year);
	else
	{
		if(month<10)
      sprintf(FechaI, "%d/0%d/%d",day,month,year);
      else
      sprintf(FechaI, "%d/%d/%d",day,month,year);
	}
}
do{
cout<<"\nIngrese Hora: ";cin>>hora; //Hora
cout<<"Ingrese min: ";cin>>min; //Min
}while(ValidacionHora(hora,min)!=1);
sprintf(HoraI, "%dH%d",hora,min);
/*****************************************/
cout<<"\n\nDATOS DE FIN DEL EVENTO >>> ";
do{
cout<<"\nIngrese el d\241a: ";cin>>day; //D�a
cout<<"Ingrese el mes: ";cin>>month; //Mes
cout<<"Ingrese el a\244o: ";cin>>year; //A�o
}while(ValidacionFecha(day,month,year)!=1);

if((day<10)&&(month<10))
{
sprintf(FechaF, "0%d/0%d/%d",day,month,year);
}
else
{
	if (day<10)
		 sprintf(FechaF, "0%d/%d/%d",day,month,year);
	else
	{
		if(month<10)
      sprintf(FechaF, "%d/0%d/%d",day,month,year);
      else
      sprintf(FechaF, "%d/%d/%d",day,month,year);
	}
}
do{
cout<<"\nIngrese Hora: ";cin>>hora; //Hora
cout<<"Ingrese min: ";cin>>min; //Min
}while(ValidacionHora(hora,min)!=1);
sprintf(HoraF, "%dH%d",hora,min);
/***************************************/
//se guardan los datos en las variables globales
setCodigo(cod);
setNombre(nom);
setDescripcion(des);
setFechaInicio(FechaI);
setHoraInicio(HoraI);
setFechaFin(FechaF);
setHoraFin(HoraF);
};

/*******************************************************
*********************FUNCION MOSTRAR EVENTO***********/
void Evento::MostrarEvento()
{
 cout<<"\nCodigo: "<<getCodigo();
 cout<<"\nNombre: "<<getNombre();
 if (getDescripcion()!="")//se omite descripcion si no hay nada
{cout<<"\nDescripcion: "<<getDescripcion();}
 cout<<"\nFecha inicio: "<<getFechaInicio();
 cout<<"\nHora inicio: "<<getHoraInicio();
 cout<<"\nFecha Fin: "<<getFechaFin();
 cout<<"\nHora Fin: "<<getHoraFin()<<endl;

//se agregan al texto Archivo
Archivo<<getCodigo()<< endl;
Archivo<<getNombre()<< endl;
Archivo<<getDescripcion()<< endl;
Archivo<<getFechaInicio()<< endl;
Archivo<<getHoraInicio()<< endl;
Archivo<<getFechaFin()<< endl;
Archivo<<getHoraFin()<< endl;
Archivo.close();
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
		cout<<"\n\n No hay Eventos Ingresados!!!";
   }
getch();
};

/*********************************************************
**********************EVENTOS DE HOY**********************/
void Evento::EventosHoy()
{
if (getNum()!=0)
{
int cont=0;
//funcion obtener la fecha de hoy
char fecha[10]; //fecha de hoy para buscar
time_t tiempo = time(0);
struct tm *tlocal = localtime(&tiempo);
char output[128];
strftime(output,128,"%d/%m/%Y",tlocal);
cout<<output;

strcpy(fecha,output);

for(int i=0;i<getNum();i++)
   {
    	if (strcmp(Vec[i]->getFechaInicio(),fecha)==0)
      {
      	Vec[i]->MostrarEvento();
         cont++;
      }
   }
   if (cont==0)
   cout<<"\n\n No hay eventos Hoy!!";
}
else
{
	cout<<"\n\n No hay Eventos Ingresados!!!!!";
}
getch();
};

/*******************************************************
**********************BUSCAR EVENTO*********************/
void Evento::Buscar(){
if (getNum()!=0)
{
	char cod [10];
	int cont=0;
	cout<<"\n Ingrese codigo del Evento: ";gets(cod);
	for(int i=0;i<getNum();i++)
	{
		if (strcmp(Vec[i]->getCodigo(),cod)==0)
		{
			Vec[i]->MostrarEvento();
			cont++;
		}
	}
if(cont!=0)
cout<<"\n Evento Encontrado!!";
else
cout<<"\n El Evento no existe!!";
}
else
{
	cout<<"\n\n No hay Eventos Ingresados!!!!!";
}
}

/*********************************************************
********************EVENTOS DE ESTA SEMANA****************/
void Evento::Semana(){
clrscr();
//funcion obtener la fecha de hoy
char fecha[10]; //fecha de hoy para buscar
time_t tiempo = time(0);
struct tm *tlocal = localtime(&tiempo);
char output[128];
char output2[128];
strftime(output,128,"%w",tlocal);
strftime(output2,128,"%W",tlocal);
if (strcmp(output,"0")==0)
cout<<"Hoy es Domingo!!!";
if (strcmp(output,"1")==0)
cout<<"Hoy es Lunes!!!";
if (strcmp(output,"2")==0)
cout<<"Hoy es Martes!!!";
if (strcmp(output,"3")==0)
cout<<"Hoy es Miercoles!!!";
if (strcmp(output,"4")==0)
cout<<"Hoy es Jueves!!!";
if (strcmp(output,"5")==0)
cout<<"Hoy es Viernes!!!";
if (strcmp(output,"6")==0)
cout<<"Hoy es Sabado!!!";
cout<<"\nSemana Numero: "<<output2;
getch();
}

/*********************************************************
**********************MENU*******************************/

int Evento::Opcion()
{
clrscr();
int a;
//grafica de la interfaz
//eje y
Recuadro(23,3,59,21,177);
gotoxy(38,3);cout<<"::MENU::";
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
               cout<<"\n      <<<EVENTOS DE HOY>>> ";
               EventosHoy();
      break;
   case 3:
   		clrscr();
               cout<<"\n    <<<EVENTOS ESTA SEMANA>>>";
		Semana();
               getch();
      break;
   case 4:
   		clrscr();
               cout<<"\n     <<<BUSCAR EVENTO>>>";
					Buscar();
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
