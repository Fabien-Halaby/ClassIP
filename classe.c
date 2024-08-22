#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Addresse
{
	unsigned int a;
	unsigned int b;
	unsigned int c;
	unsigned int d;
};

struct Addresse saisir(struct Addresse identifiant);
char *classe(struct Addresse identifiant);

int main()
{
	struct Addresse identifiant;
	printf("Cette addresse 	a pour classe : %s",classe(identifiant));
	return 0;
}

struct Addresse saisir(struct Addresse identifiant)
{
	printf("Entrez l'addresse : ");
	
	if(scanf("%d.%d.%d.%d",&identifiant.a,&identifiant.b,&identifiant.c,&identifiant.d) != 4)
	{
		printf("Adresse non valable.");
		exit(EXIT_FAILURE);
	}
	
	return identifiant;
}

char *classe(struct Addresse identifiant)
{
	identifiant = saisir(identifiant);
	
	if(identifiant.a < 128  && identifiant.b <= 255 && identifiant.c <= 255 && identifiant.d <= 255)
	{
		return "CLASSE A";
	}
	else if(identifiant.a >= 128 && identifiant.a < 192 && identifiant.b <= 255 && identifiant.c <= 255 && identifiant.d <= 255)
	{
		return "CLASSE B";
	}
	else if(identifiant.a >= 192 && identifiant.a < 224 && identifiant.b <= 255 && identifiant.c <= 255 && identifiant.d <= 255)
	{
		return "CLASSE C";
	}
	else if(identifiant.a >= 224 && identifiant.a < 240 && identifiant.b <= 255 && identifiant.c <= 255 && identifiant.d <= 255)
	{
		return "CLASSE D";
	}
	else if(identifiant.a >= 240 && identifiant.a <= 255 && identifiant.b <= 255 && identifiant.c <= 255 && identifiant.d <= 255)
	{
		return "CLASSE E";
	}
	else
	{
		return "Adresse non valable";
	}
}
