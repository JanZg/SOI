#include <stdio.h>
#include <lib.h>
#include <math.h>


#define PRIO_OFF	 0	/* Priorytet dla nieuzwanego procesu*/
#define PRIO_NORMALNY	 1	/* Priorytet dla normalnego procesu*/
#define PRIO_TLO         2	/* Priorytet dla procesu w tle*/


void set_prior( int );
int fun_child(int);
void create_child(int);

int main (int argc, char* argv[])
{
	/* Ilosc procesow zwyklych */
	int zwykly = 1; 

	/* Ilosc procesow tla      */
	int tlo = 1; 

	/* Gdy mniej niz 2 argumenty */
	if(argc <= 2)
	{
		printf("Podaj 2 argumenty\n"); 
		return -1;
	}

	/* Postac ciag asci -> ints   */
	zwykly = atoi(argv[1]);
	tlo = atoi(argv[2]);

	/*Tworzenie child'ow o roznych priorytetach */
	printf(" Proces zwykly -> 1 Proces tla -> 2\n");
	printf("  %d : Procesow normalnych i %d : Procesow tla\n\n", zwykly, tlo);


	for(;zwykly>0; zwykly=zwykly-1)

		create_child(PRIO_NORMALNY);

	for(;tlo>0; tlo=tlo-1)

		create_child(PRIO_TLO);


	return 0;
} 

/* Petla procesu */

void delaay()
{
int i=0;
int j=0;
while(i<100000000){
j=sin(i)/2;
i=i+1;
}
}

/* Tworzenie procesu */

void create_child(int spriority)
{
	int res=1;
	if( fork()==0 )
	{
		set_prior(spriority); 
		exit(fun_child(spriority));
	}

	
}

/* Ustawienie priorytetu */

void set_prior( int spriority )
{
	message msg;
	int result;	
	msg.m1_i2 = spriority;

	/* ( nr serw, nr wyw sys, wskaznik na strukture message) */
	result = _syscall( MM, 80, &msg ); 
	
}

/* Funkcja wykonywana przez proces */

int fun_child(int spriority)
{
	
	int n=5;
	int rodzaj=0;
	if(spriority==1) 
		rodzaj = 1;
	else rodzaj = 2;

	for(n=0;n<10;++n) 
{
	printf("  %d : Proces o nr %d; \n", rodzaj, getpid());
	delaay();
}
printf("  %d :Koniec procesu o nr %d; \n", rodzaj, getpid());
	
return 0;
	

}

