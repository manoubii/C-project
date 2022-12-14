#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef struct
{
int jour;
int mois;
int annee;
}Dateaj;
typedef  struct
{
char nom[20];
char prenom[20];
char cin[9];
char nationalite[40];
char genre[9];
Dateaj date;
int bureau;
}observateur;
void ajouter(observateur o);
void modifier(observateur o);
void supprimer(char cin[]);
int  chercher(char cin[]);
void afficherobs(GtkWidget *liste);
void afficher_etudiant(GtkWidget *liste);
void affiobsparbureau(char *,int);
void create(int a);
observateur find(char cin[]);
float tauxHF() ;
float tauFH();

