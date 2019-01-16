#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>





// exercice 1 partie a
void selection2(char *tab)
{
	int i = 0;
	char c;
	while ((c = getchar()) != '\n')
		*(tab + i++) = c;

	*(tab + i) = '\0';
}

void copie(char *s, char *d)
{
	int i = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		d[i] = s[i];
	}
	d[i] = '\0';
}

char* saisi()
{
	char *tmp, *res;
	int taille;

	tmp = (char *)malloc(1000 * sizeof(char));

	selection2(tmp);
	taille = strlen(tmp) + 1;

	res = (char*)malloc(taille * sizeof(char));
	copie(tmp, res);
	free(tmp);

	return res;
}

//exercice 1 partie a 3
//attention partie à revoir !!

char* saisi2()
{
	char *tab, *anc, c;
	int nb, i;

	nb = 1;
	anc = NULL, tab = NULL;

	do
	{
		c = getchar();

		tab = (char*)malloc(nb * sizeof(char));


		for (i = 0; i <= nb - 2; i++)
		{
			tab[i] = anc[i];
		}
		tab[i] = c;

		if (anc != NULL) free(anc);
		{
			anc = tab;
			nb++;
		}
	} while (c != '\n');

	tab[i + 1] = '\0';
	return tab;
}


//exercice 1 partie b version 1
char** saisitch()
{
	int nb;
	printf("Combien de chaines voulez-vous saisir : ");
	scanf("%d", &nb);
	//getchar car sinon il reste un \n après le nombre saisie, ce qui fait que la première saisie reste vide
	getchar();
	char** tch = (char**)malloc(nb * sizeof(char*));

	for (int i = 0; i < nb; i++)
	{
		printf("Vous saisissez la chaine %d sur %d : ", i + 1, nb);
		*(tch + i) = saisi();
	}

	return tch;
}


//exercice 1 partie b version 2
char** saisitch2()
{
	char **tch;
	char *tmp[1000];
	int i = 0, j, choix;

	do
	{
		printf("taper 1 pour saisir une chaine ou 0 pour arreter \n");
		scanf("%d", &choix);
		//getchar pareil que dans la fonction au dessus
		getchar();

		if (choix == 1)
		{
			printf("saisir 1 chaine \n");
			tmp[i++] = saisi();
		}
	} while (choix != 0);

	if (i == 0)
	{
		return NULL;
	}

	tch = (char **)malloc((i + 1) * sizeof(char*));

	for (j = 0; j < i; j++)
	{
		tch[j] = tmp[j];
	}
	tch[j] = NULL;

	return tch;
}






// erercice 1 partie d
void supression(char** source, char cara)
{
	char* cible;
	int size, cpt = 0, j;

	for (size = 0; *(*source + size) != '\0'; size++) {
		if (*(*source + size) == cara)
			cpt++;
	}

	if (size == cpt) {
		free(*source);
		*source = NULL;
	}
	else if (cpt > 0)
	{
		int new_size = size - cpt + 1;
		cible = (char*)malloc(new_size * sizeof(char));

		for (int i = 0, j = 0; *(*source + i) != '\0'; i++)
			if (*(*source + i) != cara)
				*(cible + j++) = *(*source + i);

		cible[new_size - 1] = '\0';

		free(*source);
		*source = cible;
	}
}

void suprime2(char*** tch, char car)
{
	char ** tmp, **res, *p;
	int size_list, nb_deleted = 0, taille;

	for (size_list = 0; *(*tch + size_list) != NULL; size_list++);

	for (int j = 0; j < size_list; j++) {
		supression(&*(*tch + j), car);

		if (*(*tch + j) == NULL)
			nb_deleted++;
	}

	//Si au moin  une chaîne a été supprimée
	if (nb_deleted != 0) {
		tmp = (char**)malloc(sizeof(char*) * (size_list - nb_deleted));

		//Copie toute les chaines non vide de tch dans tmp
		int tmp_i = 0;
		for (int i = 0; i < size_list; i++)
			if (*(*tch + i) != NULL) {
				*(tmp + tmp_i) = (char*)malloc(sizeof(char) * strlen(*(*tch + i) + 1));
				copie(*(*tch + i), *(tmp + tmp_i++));
			}

		//suppression de tout les éléments de tch y compris l'element NULL de fin
		for (int i = 0; i < size_list + 1; i++)
			free(*(*tch + i));
		free(*tch);

		*tch = (char**)malloc(sizeof(char*) * (size_list - nb_deleted + 1));

		//Passes les pointeurs contenant les chaines de tmp dans tch
		for (int i = 0; i < size_list - nb_deleted; i++)
			*(*tch + i) = *(tmp + i);

		//dernier élément à null
		*(*tch + size_list - nb_deleted) = NULL;

		free(tmp);
	}

}




void dedouble_str(char** str, char c) {
	int length = 0, cpt = 0;
	for (length = 0; *(*str + length) != '\0'; length++)
		if (*(*str + length) == c)
			cpt++;

	if (cpt != 0) {
		char* tmp = (char*)malloc(sizeof(char) * (length + 1 + cpt));

		int tmp_i = 0;
		for (int i = 0; i < length; i++) {
			*(tmp + tmp_i++) = *(*str + i);
			if (*(*str + i) == c)
				*(tmp + tmp_i++) = *(*str + i);
		}
		*(tmp + tmp_i) = '\0';

		free(*str);
		*str = tmp;
	}
}


void dedouble_tch(char** tab, char car)
{
	int i = 0;
	while (*(tab + i) != NULL)
		dedouble_str(&*(tab + i++), car);
}


//exercice 1 partie b attention 2 version differante selon la saisie
void affiche(char *t)
{
	while (*t != '\0')
	{
		printf("%2c ", *t);
		t++;
	}
	printf("\n");
}

void affichetch(char **tch, int nb)
{
	int i;
	for (i = 0; i <= nb; i++)
	{
		affiche(tch[i]);
	}
}

void affichetch2(char **tch)
{
	int i;
	for (i = 0; tch[i] != NULL; i++)
	{
		affiche(tch[i]);
	}
}