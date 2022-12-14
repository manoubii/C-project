
#include"obs.h"

#include <gtk/gtk.h>
#include <string.h>
#include <stdlib.h>


enum 
 {
	ECIN,
	ENOM,
	EPRENOM,
	ENATIONALITE,
	EGENRE,
	EBUREAU,
	EJOUR,
	EMOIS,
	EANNEE,
	COLUMNS

};



////////////////////////////////////////////////

void ajouter(observateur o){


	FILE *f;
	f=fopen("obs.txt","a+");
	
	if(f!=NULL)
		{
				
		  fprintf(f,"%s ,%s ,%s ,%s ,%s ,%d ,%d,%d,%d \n",o.cin,o.nom,o.prenom,o.nationalite,o.genre,o.bureau,o.date.jour,o.date.mois,o.date.annee);
		 fclose(f);

		}

		

}



int  chercher(char cin[])

{
	FILE *f ;
observateur o;
int x=0;
    f=fopen("obs.txt","r");
 if(f!=NULL)
    {
	while(fscanf(f,"%s ,%s ,%s ,%s ,%s ,%d ,%d,%d,%d \n",o.cin,o.nom,o.prenom,o.nationalite,o.genre,&o.bureau,&o.date.jour,&o.date.mois,&o.date.annee)!=EOF)
	{ 
 	 if(strcmp(cin,o.cin)==0)
{
	    
	     x=1;
}

}

}
fclose(f);
return x;
}


void afficher()
{
    observateur o;
	FILE *f;
	f=fopen("obs.txt","r");
	if( f!=NULL )
	{
	while(fscanf(f,"%s ,%s ,%s ,%s ,%s ,%d ,%d/%d/ %d\n",o.cin,o.nom,o.prenom,o.nationalite,&o.genre,&o.bureau,&o.date.jour,&o.date.mois,&o.date.annee)!=EOF)
	{
	 printf("%s ,%s ,%s ,%s ,%s ,%d ,%d/%d/%d\n",o.cin,o.nom,o.prenom,o.nationalite,o.genre,o.bureau,o.date.jour,o.date.mois,o.date.annee);
	}
	fclose(f);
}
	else {
	printf("impossible \n");
}}


void supprimer(char cin[]){
	FILE *f ;
FILE *g;
observateur o;
    f=fopen("obs.txt","r");
    g=fopen("obs2.txt","w+");
 if(f!=NULL)
    {
	while(fscanf(f,"%s ,%s ,%s ,%s ,%s ,%d ,%d,%d,%d \n",o.cin,o.nom,o.prenom,o.nationalite,o.genre,&o.bureau,&o.date.jour,&o.date.mois,&o.date.annee)!=EOF)
	{ 
 	 if(strcmp(cin,o.cin)!=0)
{
	     fprintf(g,"%s ,%s ,%s ,%s ,%s ,%d ,%d,%d,%d \n",o.cin,o.nom,o.prenom,o.nationalite,o.genre,o.bureau,o.date.jour,o.date.mois,o.date.annee);
	     
}

}
}
fclose(f);
fclose(g);
remove("obs.txt");
rename("obs2.txt","obs.txt");
}
/*
void modifier(char cin []) {
/* FILE *f;
FILE *g;
observateur o ;
int trouve;
char nom1[20];
char prenom1[20];
char cin1[9];
char nationalite1[40];
char genre1;
Dateaj date1;
int bureau1;
trouve=chercher(cin);
if (trouve==0) {
printf("ce candidat nexiste pas \n");
}
else {
f=fopen("obs.txt","r");
if(f!=NULL) {
while(fscanf(f,"%s ,%s ,%s ,%s ,%c ,%d ,%d/%d/ %d\n",o.cin,o.nom,o.prenom,o.nationalite,&o.genre,&o.bureau,&o.date.jour,&o.date.mois,&o.date.annee)!=EOF) {
if(strcmp(cin,o.cin)!=0) {
g=fopen("nouv.txt","a+");
if(g!=NULL) {
fprintf(g,"%s ,%s ,%s ,%s ,%c ,%d ,%d/%d/ %d\n",o.cin,o.nom,o.prenom,o.nationalite,o.genre,o.bureau,o.date.jour,o.date.mois,o.date.annee);
}
}
else {
printf("donner le nouvel cin : \n");
scanf("%s",cin1);
printf("donner le nouvel nom : \n");
scanf("%s",nom1);
printf("donner le nouvel prenom: \n");
scanf("%s",prenom1);
printf("donner la nouvelle nationalité: \n");
scanf("%s",nationalite1);
printf("donner le nouvel genre : \n");
scanf("%c",&genre1);
printf("donner le num de bureau : \n");
scanf("%d",&bureau1);
printf("donner date : \n");
scanf("%d/%d/%d",&o.date.jour,&o.date.mois,&o.date.annee);



g=fopen("exemple.txt","a+");
if(g!=NULL) {
fprintf(g,"%s ,%s ,%s ,%s ,%c ,%d ,%d/%d/ %d\n",o.cin,o.nom,o.prenom,o.nationalite,o.genre,o.bureau,o.date.jour,o.date.mois,o.date.annee);
fclose(g);
}
}
fclose(f);
}
}
else {
printf("impossible \n");
}

remove("obs.txt");
rename("exemple.txt","obs.txt");
}
} */
///////////////
void modifier( observateur o)
{
	observateur h;
	FILE *f, *g;
	f=fopen("obs.txt","r");
	g=fopen("obs2.txt","a+");
	if (f!=NULL ) {
		while(fscanf(f,"%s ,%s ,%s ,%s ,%s ,%d ,%d,%d,%d \n",h.cin,h.nom,h.prenom,h.nationalite,h.genre,&h.bureau,&h.date.jour,&h.date.mois,&h.date.annee)!=EOF)
			{ if(strcmp(o.cin,h.cin)==0){
				fprintf(g,"%s ,%s ,%s ,%s ,%s ,%d ,%d,%d,%d \n",o.cin,o.nom,o.prenom,o.nationalite,o.genre,o.bureau,o.date.jour,o.date.mois,o.date.annee);}
			else{
				fprintf(g,"%s ,%s ,%s ,%s ,%s ,%d ,%d,%d,%d \n",h.cin,h.nom,h.prenom,h.nationalite,h.genre,h.bureau,h.date.jour,h.date.mois,h.date.annee);}
			}
		}
	fclose(f);
	fclose(g);
	remove("obs.txt");
	rename("obs2.txt","obs.txt");
}
//////////////////////////////////////////

void afficherobs(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

	char nom[20];
char prenom[20];
char cin[9];
char nationalite[40];
char genre[9];

int bureau;
	
	int jour;
	int mois;
	int annee;
	observateur o;	

	store=NULL;
	FILE *f;
	store=gtk_tree_view_get_model(liste);

if (store==NULL)
{
	
	
	

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("cin",renderer,"text",ECIN, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("nom",renderer,"text",ENOM, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",EPRENOM, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("nationalite",renderer,"text",ENATIONALITE, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("genre",renderer,"text",EGENRE, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("bureau",renderer,"text",EBUREAU, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("jour",renderer,"text",EJOUR, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("mois",renderer,"text",EMOIS, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("annee",renderer,"text",EANNEE, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


}

store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT);
f=fopen("obs.txt","r");



while (fscanf(f,"%s ,%s ,%s ,%s ,%s ,%d ,%d,%d,%d \n",cin,nom,prenom,nationalite,genre,bureau,jour,mois,annee)!=EOF)
{
	
	gtk_list_store_append(store,&iter);
	gtk_list_store_set(store,&iter,ECIN,cin,ENOM,nom,EPRENOM, prenom,ENATIONALITE,nationalite,EGENRE,genre,EBUREAU,bureau,EJOUR,jour,EMOIS,mois,EANNEE,annee,-1);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);




}
////////////////////////////////////////

observateur find(char cin[])
{
    observateur o;
observateur a;
    FILE *f;
    f = fopen("obs.txt","r");
    if(f != NULL){
    	while(fscanf(f,"%s ,%s ,%s ,%s ,%s ,%d ,%d,%d,%d \n",o.cin,o.nom,o.prenom,o.nationalite,o.genre,&o.bureau,&o.date.jour,&o.date.mois,&o.date.annee) != EOF){
        	if(strcmp(o.cin,cin) == 0){
       		     return o;
        	}
    	}
}

    fclose(f);
  return a;  
}

//////////////////////////////////////////////////////
float tauxHF()
{ observateur o;
    int female=0;

	int i=0;

   
    FILE *f=fopen("obs.txt","r");
    if(f!=NULL)
    {  
        while(fscanf(f,"%s ,%s ,%s ,%s ,%s ,%d ,%d,%d,%d \n",o.cin,o.nom,o.prenom,o.nationalite,o.genre,&o.bureau,&o.date.jour,&o.date.mois,&o.date.annee)!=EOF) 
        {
            
                if (strcmp(o.genre,"Femme")==0){
					i=i+1;
					female=female+1;
				}
				else{
					i=i+1;
				}
            
        
		}
		}
  fclose(f);
	float t=(float) female/i;
  return t;

          
    }

////////////////////////////////////////////////////////////
float tauFH()
{ observateur o;
    int male=0;

	int i=0;

   
    FILE *f=fopen("obs.txt","r");
    if(f!=NULL)
    {  
        while(fscanf(f,"%s ,%s ,%s ,%s ,%s ,%d ,%d,%d,%d \n",o.cin,o.nom,o.prenom,o.nationalite,o.genre,&o.bureau,&o.date.jour,&o.date.mois,&o.date.annee)!=EOF) 
        {
            
                if (strcmp(o.genre,"Homme")==0){
					i=i+1;
					male=male+1;
				}
				else{
					i=i+1;
				}
            
        
		}
		}
  fclose(f);
	float t=(float) male/i;
  return t;

          
    }

///////////////////////////
void afficher_etudiant(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
observateur o;
store=NULL;
FILE *f;
store=gtk_tree_view_get_model(liste);
if (store==NULL){

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("cin",renderer,"text",ECIN, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("nom",renderer,"text",ENOM, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",EPRENOM, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("nationalite",renderer,"text",ENATIONALITE, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("genre",renderer,"text",EGENRE, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("bureau",renderer,"text",EBUREAU, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("jour",renderer,"text",EJOUR, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("mois",renderer,"text",EMOIS, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("annee",renderer,"text",EANNEE, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


}

store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT);

f=fopen("obs.txt","r");
if (f!=NULL)
{
while(fscanf(f,"%s ,%s ,%s ,%s ,%s ,%d ,%d,%d,%d \n",o.cin,o.nom,o.prenom,o.nationalite,o.genre,&o.bureau,&o.date.jour,&o.date.mois,&o.date.annee)!=EOF)
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,ECIN,o.cin,ENOM,o.nom,EPRENOM,o.prenom,ENATIONALITE,o.nationalite,EGENRE,o.genre,EBUREAU,o.bureau,EJOUR,o.date.jour,EMOIS,o.date.mois,EANNEE,o.date.annee,-1);
}
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}


//////////////////////////////////
void afficherr(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter  iter;
	GtkListStore   *store;

	
	char cin[50];
	char nom[50];
	char prenom[50];
	char nationalite[50];
	int jour;
	int mois;
	int annee;
		int bureau;
	char genre[50];
	
	observateur o;
	store=NULL;
	FILE *f;
	store=gtk_tree_view_get_model(liste);
if (store==NULL)
{
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" cin", renderer, "text",ECIN, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" nom", renderer, "text",ENOM, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" prenom", renderer, "text",EPRENOM, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" nationalite", renderer, "text",ENATIONALITE, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

		renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" genre", renderer, "text",EGENRE, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" bureau", renderer, "text",EBUREAU, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" jour", renderer, "text",EJOUR, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" mois", renderer,"text",EMOIS, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" annee", renderer, "text",EANNEE, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	
	
	
}
	



store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT,G_TYPE_INT);


f=fopen("obs.txt","r");
if (f==NULL)
{
return;
}
else
{
f=fopen("obs.txt","a+");
while (fscanf(f,"%s ,%s ,%s ,%s ,%s ,%d ,%d,%d,%d \n",cin,nom,prenom,nationalite,genre,&bureau,&jour,&mois,&annee)!=EOF)
{
	
	gtk_list_store_append(store,&iter);
	gtk_list_store_set(store,&iter,ECIN,cin,ENOM,nom,EPRENOM, prenom,ENATIONALITE,nationalite,EGENRE,genre,EBUREAU,bureau,EJOUR,jour,EMOIS,mois,EANNEE,annee,-1);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);
}

}

///////////////////////////////////////////::
int nbrdate(int jour,int mois,int annee)
{
observateur o;
int nbr=0;

 FILE *f;
    f = fopen("obs.txt","r");
 if(f != NULL){
    	while(fscanf(f,"%s ,%s ,%s ,%s ,%s ,%d ,%d,%d,%d \n",o.cin,o.nom,o.prenom,o.nationalite,o.genre,&o.bureau,&o.date.jour,&o.date.mois,&o.date.annee)!= EOF){
	if (   (jour==o.date.jour) && (mois==o.date.mois) && (annee==o.date.annee) )
    	nbr++;
}}

fclose(f);
return nbr;
}

////////////////////////////////////////////////////
void afficherlocaux(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter  iter;
	GtkListStore   *store;

	
	char cin[50];
	char nom[50];
	char prenom[50];
	char nationalite[50];
	int jour;
	int mois;
	int annee;
		int bureau;
	char genre[50];
	
	observateur o;
	store=NULL;
	FILE *f;
	store=gtk_tree_view_get_model(liste);
if (store==NULL)
{
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" cin", renderer, "text",ECIN, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" nom", renderer, "text",ENOM, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" prenom", renderer, "text",EPRENOM, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" nationalite", renderer, "text",ENATIONALITE, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

		renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" genre", renderer, "text",EGENRE, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" bureau", renderer, "text",EBUREAU, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" jour", renderer, "text",EJOUR, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" mois", renderer,"text",EMOIS, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" annee", renderer, "text",EANNEE, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	
	
	
}
	



store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT,G_TYPE_INT);


f=fopen("obs2.txt","r");
if (f==NULL)
{
return;
}
else
{
f=fopen("obs2.txt","a+");
while (fscanf(f,"%s ,%s ,%s ,%s ,%s ,%d ,%d,%d,%d \n",cin,nom,prenom,nationalite,genre,&bureau,&jour,&mois,&annee)!=EOF)
{
	
	gtk_list_store_append(store,&iter);
	gtk_list_store_set(store,&iter,ECIN,cin,ENOM,nom,EPRENOM, prenom,ENATIONALITE,nationalite,EGENRE,genre,EBUREAU,bureau,EJOUR,jour,EMOIS,mois,EANNEE,annee,-1);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);
}

}

///////////////////////////////////////////////////////
void create(int a)
{
FILE *f ;
FILE *g;
observateur o;
     //remove("users2.txt");
    f=fopen("obs.txt","r");
    g=fopen("obs2.txt","w+");






 if(f!=NULL)
    {
	while(fscanf(f,"%s ,%s ,%s ,%s ,%s ,%d ,%d,%d,%d \n",o.cin,o.nom,o.prenom,o.nationalite,o.genre,&o.bureau,&o.date.jour,&o.date.mois,&o.date.annee)!=EOF)
	{ 

 
 
 
 if ((a==2)&& (strcmp(o.nationalite,"Tunis")==0) )
{

	     fprintf(g,"%s ,%s ,%s ,%s ,%s ,%d ,%d,%d,%d \n",o.cin,o.nom,o.prenom,o.nationalite,o.genre,o.bureau,o.date.jour,o.date.mois,o.date.annee);
	     
}

 if ((a==1)&& (strcmp(o.nationalite,"Autres")==0) )
{

	     fprintf(g,"%s ,%s ,%s ,%s ,%s ,%d ,%d,%d,%d \n",o.cin,o.nom,o.prenom,o.nationalite,o.genre,o.bureau,o.date.jour,o.date.mois,o.date.annee);
	     
}




}
}
fclose(f);
fclose(g);


}
//////////////////////////////////////////:::
void supprimer2(observateur p)
{

FILE *f, *g;
observateur o;
f=fopen("obs.txt","r");
g=fopen("obs20.txt","w+");

if (f==NULL || g==NULL)
{
return;
}

else 
{
		while(fscanf(f,"%s ,%s ,%s ,%s ,%s ,%d ,%d,%d,%d \n",o.cin,o.nom,o.prenom,o.nationalite,o.genre,&o.bureau,&o.date.jour,&o.date.mois,&o.date.annee)!=EOF)
{
						if  (  (strcmp(p.cin,o.cin)!=0 )|| (strcmp(p.nom,o.nom)!=0 )||( strcmp(p.prenom,o.prenom)!=0) || (strcmp(p.nationalite,o.nationalite)!=0) || (strcmp(p.genre,o.genre)!=0) || (p.bureau!=o.bureau) || (p.date.jour!=o.date.jour)  || (p.date.mois!=o.date.mois) || (p.date.annee!=o.date.annee) )

				fprintf(g,"%s ,%s ,%s ,%s ,%s ,%d ,%d,%d,%d \n",o.cin,o.nom,o.prenom,o.nationalite,o.genre,o.bureau,o.date.jour,o.date.mois,o.date.annee);

}


fclose(f);
fclose(g);
remove("obs.txt");
rename("obs20.txt","obs.txt");

}
}

////////////////////////////////////////////
void vider_admin (GtkWidget *liste)
{
GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter  iter;
	GtkListStore   *store;

	
	char cin[50];
	char nom[50];
	char prenom[50];
	char nationalite[50];
	int jour;
	int mois;
	int annee;
		int bureau;
	char genre[50];
	
	observateur o;
	store=NULL;
	FILE *f;
store=gtk_tree_view_get_model(liste);


if (store==NULL)
{
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" cin", renderer, "text",ECIN, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" nom", renderer, "text",ENOM, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" prenom", renderer, "text",EPRENOM, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" nationalite", renderer, "text",ENATIONALITE, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

		renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" genre", renderer, "text",EGENRE, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" bureau", renderer, "text",EBUREAU, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" jour", renderer, "text",EJOUR, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" mois", renderer,"text",EMOIS, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" annee", renderer, "text",EANNEE, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	

}
store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT);
gtk_list_store_append(store,&iter);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
}

