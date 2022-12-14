#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif


#include <gtk/gtk.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "obs.h"

int filter=0;
int filter1=0;

int x;
int t[2]={0,0};
void
on_button2_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *choix,*Modif;
choix=lookup_widget(objet_graphique,"choix");
gtk_widget_destroy(choix);
Modif=create_Modif();
gtk_widget_show(Modif);
}


void
on_AJobs_clicked                       (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Ajoutobs,*choix;
choix=lookup_widget(objet_graphique,"choix");
gtk_widget_destroy(choix);
Ajoutobs=create_Ajoutobs();
gtk_widget_show(Ajoutobs);
}


void
on_Suppobs_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *choix,*Supp;
choix=lookup_widget(objet_graphique,"choix");
gtk_widget_destroy(choix);
Supp=create_Supp();
gtk_widget_show(Supp);
}


void
on_button4_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *choix,*Liste,*treeview;
choix=lookup_widget(objet_graphique,"choix");
gtk_widget_destroy(choix);
Liste=create_Liste();
gtk_widget_show(Liste);

treeview=lookup_widget(Liste,"treeview_observateur");

afficherr(treeview);
}


void
on_button5_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *choix,*chercher_obser,*treeview1;
choix=lookup_widget(objet_graphique,"choix");
gtk_widget_destroy(choix);
chercher_obser=create_chercher_obser();
gtk_widget_show(chercher_obser);

treeview1=lookup_widget(chercher_obser,"treeview_filter");

afficherr(treeview1);

}


void
on_statobs_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *choix,*stat_HF;
choix=lookup_widget(objet_graphique,"choix");
gtk_widget_destroy(choix);
stat_HF=create_stat_HF();
gtk_widget_show(stat_HF);
}


void
on_ajtobs_clicked                      (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	observateur o;
GtkWidget *nom_M;
GtkWidget *prenom_M;
GtkWidget *cin_M;
GtkWidget *jour_M;
GtkWidget *mois_M;
GtkWidget *annee_M;
GtkWidget *nationalite_M;
GtkWidget *bureau_M,*pInfo;

   
//associer les objets a des variables

nom_M=lookup_widget(objet_graphique,"ajnomobs");
prenom_M=lookup_widget(objet_graphique,"ajprenomobs");
cin_M=lookup_widget(objet_graphique,"ajcinobs");

strcpy(o.nom,gtk_entry_get_text(GTK_ENTRY(nom_M)));
strcpy(o.prenom,gtk_entry_get_text(GTK_ENTRY(prenom_M)));
strcpy(o.cin,gtk_entry_get_text(GTK_ENTRY(cin_M)));

jour_M=lookup_widget(objet_graphique,"spjour");
mois_M=lookup_widget(objet_graphique,"spmois");
annee_M=lookup_widget(objet_graphique,"spanne");
bureau_M=lookup_widget(objet_graphique,"bureau_M");
                         
o.date.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour_M));
o.date.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois_M));
o.date.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee_M));
o.bureau=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(bureau_M));


nationalite_M=lookup_widget(objet_graphique,"cbnatio");

if(strcmp("Tunis",gtk_combo_box_get_active_text(GTK_COMBO_BOX(nationalite_M)))==0)
    {strcpy(o.nationalite,"Tunis");}
 else if (strcmp("Autres",gtk_combo_box_get_active_text(GTK_COMBO_BOX(nationalite_M)))==0)
    {strcpy(o.nationalite,"Autres");}


if(x==1)
{
	strcpy(o.genre,"Homme");
}
if(x==2)
{
	strcpy(o.genre,"Femme");
}
if(chercher(o.cin)==1)
{
pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"cin déja existe!");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break; }

}

else if (strlen(o.cin)!=8){
	pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"cin est de 8 chiffre! ");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break; }
}



else{
ajouter(o);
}

}

////////////////////////////////////////////////////////////////////////
/*void
on_treeviewobs_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{




GtkTreeIter iter;
gchar* cin;
gchar* nom;
gchar* prenom;

gchar* nationalite;
gchar* genre;

int bureau;
int jour;

int mois;
int annee;
observateur o;


GtkTreeModel *model =gtk_tree_view_get_model(treeview);
if (gtk_tree_model_get_iter(model, &iter,path))
{
gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0, &cin,1, &nom,2,&prenom,3,&nationalite,4,&genre,5,&bureau,6,&jour,7,&mois,8,&annee,-1);

strcpy(o.cin,cin);
strcpy(o.nom,nom);
strcpy(o.prenom,prenom);
strcpy(o.nationalite,nationalite);
strcpy(o.genre,genre);

o.bureau=bureau;
o.date.jour=jour;
o.date.mois=mois;
o.date.annee=annee;







afficherobs(treeview);


}


}*/

//////////////////////////////////////////////////////////////////
void
on_findobs_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

}


void
on_deleteobs_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *cin,*output,*pInfo;
observateur a;
char cin1[9];
cin=lookup_widget(objet_graphique,"supobscin");
output=lookup_widget(objet_graphique,"chercher_M");
strcpy(cin1,gtk_entry_get_text(GTK_ENTRY(cin)));

int S;
S=chercher(cin1);
a=find(cin1);
if(S==1){
	pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Observateur supprimée!");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	supprimer(cin1);

}
}
else{
		pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Observateur non trouvée!");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);

}


}
}

void
on_affdataobs_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *cin,*output,*Modif,*output1,*output2,*output3,*output4,*output5,*output6,*verif_M,*output7;
observateur a;
char cin1[500];
int q;
Modif=lookup_widget(objet_graphique,"Modif");
cin=lookup_widget(objet_graphique,"modifcinobs");
strcpy(cin1,gtk_entry_get_text(GTK_ENTRY(cin)));
verif_M=lookup_widget(objet_graphique,"verif_M");
	q=chercher(cin1);
	if(q==1){
	a=find(cin1);
output=lookup_widget(objet_graphique,"modnom");
output1=lookup_widget(objet_graphique,"modprenom");
output2=lookup_widget(objet_graphique,"natio_M");
output7=lookup_widget(objet_graphique,"GENRE_MO");
gtk_entry_set_text(GTK_ENTRY(output),a.nom);
gtk_entry_set_text(GTK_ENTRY(output1),a.prenom);
gtk_entry_set_text(GTK_ENTRY(output2),a.nationalite);
gtk_entry_set_text(GTK_ENTRY(output7),a.genre);

output3=lookup_widget(objet_graphique,"jour_modifier");	
output4=lookup_widget(objet_graphique,"mois_modifier");
output5=lookup_widget(objet_graphique,"annee_modifier");
output6=lookup_widget(objet_graphique,"num_bureau");




gtk_spin_button_set_value(GTK_SPIN_BUTTON(output3),a.date.jour);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(output4),a.date.mois);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(output5),a.date.annee);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(output6),a.bureau);

gtk_label_set_text(GTK_LABEL(verif_M),"utilisateur trouvé");	

}
else{

gtk_label_set_text(GTK_LABEL(verif_M),"utilisateur non trouvé");	
}


}


void
on_button12_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
observateur o;
GtkWidget *cin,*output,*Modif,*output1,*output2,*output3,*output4,*output5,*output6,*verif_M,*output7,*pInfo;

cin=lookup_widget(objet_graphique,"modifcinobs");

output=lookup_widget(objet_graphique,"modnom");
output1=lookup_widget(objet_graphique,"modprenom");
output2=lookup_widget(objet_graphique,"natio_M");

output3=lookup_widget(objet_graphique,"jour_modifier");	
output4=lookup_widget(objet_graphique,"mois_modifier");
output5=lookup_widget(objet_graphique,"annee_modifier");
output6=lookup_widget(objet_graphique,"num_bureau");
output7=lookup_widget(objet_graphique,"GENRE_MO");

strcpy(o.cin,gtk_entry_get_text(GTK_ENTRY(cin)));
strcpy(o.nom,gtk_entry_get_text(GTK_ENTRY(output)));
strcpy(o.prenom,gtk_entry_get_text(GTK_ENTRY(output1)));
strcpy(o.nationalite,gtk_entry_get_text(GTK_ENTRY(output2)));
strcpy(o.genre,gtk_entry_get_text(GTK_ENTRY(output7)));


o.date.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(output3));
o.date.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(output4));
o.date.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(output5));
o.bureau=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(output6));

if((strcmp(o.genre,"Femme")!=0 && ( strcmp(o.genre,"Homme")!=0))){

pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Genre non valide!");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);

}
}
else if((strcmp(o.nationalite,"Tunis")!=0 && ( strcmp(o.nationalite,"Autres")!=0))){

pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Nationalite non valide!");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);

}
}
else{
modifier(o);

}



}


void
on_rdobs_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{x=1;}
}


void
on_rdobs2_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{x=2;}
}


void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_difer_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_actliste_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{







GtkWidget *Liste,*w1;
GtkWidget *treeview2;
w1=lookup_widget(objet_graphique,"Liste");
Liste=create_Liste();
gtk_widget_show(Liste);
gtk_widget_hide(w1);
treeview2=lookup_widget(Liste,"treeview_observateur");
vider_admin(treeview2);
afficherr(treeview2);
}




























/*
////////////////////////////////////////

void
on_AJobs_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button2_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_Suppobs_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button4_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button5_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_statobs_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_rdobs_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_rdobs2_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_ajtobs_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{

}

*/
void
on_treeviewobs_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* cin;
gchar* nom;
gchar* prenom;

gchar* nationalite;
gchar* genre;

int bureau;
int jour;

int mois;
int annee;
observateur o;
observateur p;


GtkTreeModel *model =gtk_tree_view_get_model(treeview);
if (gtk_tree_model_get_iter(model, &iter,path))
{
gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0, &cin,1, &nom,2,&prenom,3,&nationalite,4,&genre,5,&bureau,6,&jour,7,&mois,8,&annee,-1);

strcpy(o.cin,cin);
strcpy(o.nom,nom);
strcpy(o.prenom,prenom);
strcpy(o.nationalite,nationalite);
strcpy(o.genre,genre);

o.bureau=bureau;
o.date.jour=jour;
o.date.mois=mois;
o.date.annee=annee;



supprimer2(p);



afficherr(treeview);


}
}
/*

void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_difer_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_actliste_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_findobs_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_deleteobs_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_affdataobs_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button12_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}
*/

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* cin;
gchar* nom;
gchar* prenom;
gchar* nationalite;
gchar* genre;
gint* bureau;
gint* jour;
gint* mois;
gint* annee;
observateur o;


GtkTreeModel *model =gtk_tree_view_get_model(treeview);
if (gtk_tree_model_get_iter(model, &iter,path))
{
gtk_tree_model_get (GTK_LIST_STORE(model),&iter,0,&cin,1,&nom,2,&prenom,3,&nationalite,4,&genre,5,&bureau,6,&jour,7,&mois,8,&annee,-1);

strcpy(o.cin,cin);
strcpy(o.nom,nom);
strcpy(o.prenom,prenom);
strcpy(o.nationalite,nationalite);
strcpy(o.genre,genre);

o.bureau=bureau;
o.date.jour=jour;
o.date.mois=mois;
o.date.annee=annee;



afficher_etudiant(treeview);
afficherobs(treeview);


}
}


void
on_retour_choix_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *choix,*Ajoutobs;
Ajoutobs=lookup_widget(objet_graphique,"Ajoutobs");
gtk_widget_destroy(Ajoutobs);
choix=create_choix();
gtk_widget_show(choix);
}


void
on_retour_list_choix_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *choix,*Liste;
Liste=lookup_widget(objet_graphique,"Liste");
gtk_widget_destroy(Liste);
choix=create_choix();
gtk_widget_show(choix);
}


void
on_retour_supp_choix_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *choix,*Supp;
Supp=lookup_widget(objet_graphique,"Supp");
gtk_widget_destroy(Supp);
choix=create_choix();
gtk_widget_show(choix);
}


void
on_retour_modif_choix_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *choix,*Modif;
Modif=lookup_widget(objet_graphique,"Modif");
gtk_widget_destroy(Modif);
choix=create_choix();
gtk_widget_show(choix);
}


void
on_button17_Mchercher_clicked          (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
char cin[9];
char texte5[30];
char texte6[30];
observateur a;
GtkWidget *chercher_input,*output2,*output3,*output4,*output5,*output6,*output7,*output8;
chercher_input=lookup_widget(objet_graphique,"chercher_input");

strcpy(cin,gtk_entry_get_text(GTK_ENTRY(chercher_input)));
output2=lookup_widget(objet_graphique,"output_C1");

output3=lookup_widget(objet_graphique,"output_C2");
output4=lookup_widget(objet_graphique,"output_C3");
output5=lookup_widget(objet_graphique,"output_C4");
output6=lookup_widget(objet_graphique,"output_C5");
output7=lookup_widget(objet_graphique,"output_C6");
output8=lookup_widget(objet_graphique,"output_C7");

if (chercher(cin)==1){
	a=find(cin);
gtk_label_set_text(GTK_LABEL(output2),a.nom);
gtk_label_set_text(GTK_LABEL(output3),a.prenom);
gtk_label_set_text(GTK_LABEL(output4),a.nationalite);
gtk_label_set_text(GTK_LABEL(output5),a.genre);

sprintf(texte5,"%d/%d/%d",a.date.jour,a.date.mois,a.date.annee);
gtk_label_set_text(GTK_LABEL(output6),texte5);
sprintf(texte6,"%d",a.bureau);
gtk_label_set_text(GTK_LABEL(output7),texte6);

gtk_label_set_text(GTK_LABEL(output8),"observateur trouvée");

}

else{
gtk_label_set_text(GTK_LABEL(output8),"observateur non trouvée");
}

}


void
on_retour_choix_chercher_ob_clicked    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *choix,*chercher_obser;
chercher_obser=lookup_widget(objet_graphique,"chercher_obser");
gtk_widget_destroy(chercher_obser);
choix=create_choix();
gtk_widget_show(choix);

}

//calcul des femmes;
void
on_calcul_homme_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *output;
float fem;
char texte11[30];
output=lookup_widget(objet_graphique,"output_calucul");
fem=tauxHF();
fem=fem*100;
sprintf(texte11,"taux des femmes :%.2f %%",fem);
gtk_label_set_text(GTK_LABEL(output),texte11);
}

//calcul des hommes;
void
on_calcul_femme_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *output;
float hom;
char texte22[30];
output=lookup_widget(objet_graphique,"output_fff");
hom=tauFH();
hom=hom*100;
sprintf(texte22,"taux des hommes : %.2f %%",hom);
gtk_label_set_text(GTK_LABEL(output),texte22);
}


void
on_retour_stat_choix_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *choix,*stat_HF;
stat_HF=lookup_widget(objet_graphique,"stat_HF");
gtk_widget_destroy(stat_HF);
choix=create_choix();
gtk_widget_show(choix);
}


void
on_treeview_observateur_row_activated  (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
	gint* jour;
	gint* mois;
	gint* annee;
	gint* bureau;
	gchar* cin;
	gchar* nom;
	gchar* prenom;
	gchar* nationalite;
	gchar* genre;
	
	observateur a;


	GtkTreeModel *model = gtk_tree_view_get_model(treeview);
 	
	if (gtk_tree_model_get_iter(model, &iter, path))
	{
	//obtention des valeurs de la ligne soulignéé
	
		gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0, &cin, 1, &nom, 2, &prenom, 3, &nationalite, 4, &genre, 5, &bureau, 6, &jour, 7,&mois,8,&annee ,-1);
		//copie des valeurs dans la variable m de type menu pour le passer à la fonction de suppression
		strcpy(a.cin,cin);
		strcpy(a.nom,nom);
		strcpy(a.prenom,prenom);
		strcpy(a.nationalite,nationalite);
		strcpy(a.genre,genre);

		a.bureau=bureau;
		a.date.jour=jour;
		a.date.mois=mois;
		a.date.annee=annee;

		//appel de la fonction de suppression
		supprimer2(a);
		//mise à jour de l'affichage de la treeview
		afficherr(treeview);
	}
}


void
on_get_cal_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
int kaa;char texte[500];char texte2[500];char texte3[500];
GtkCalendar *ajc,*output999;
int mois, jour , annee;
guint* day, month, year;
ajc=lookup_widget(objet_graphique,"calendar1");
output999=lookup_widget(objet_graphique,"cal_output");
gtk_calendar_get_date(GTK_CALENDAR(ajc), &day, &month, &year);
jour=year;
mois=month+1;
annee=day;

kaa=nbrdate(jour,mois,annee);
sprintf(texte,"le nombre d'observataurs \n qui on été ajouté a : %d/%d/%d sont :\n %d",jour,mois,annee,kaa);
//strcpy(texte3,nbrdatee(jour,mois,annee));
//strcpy(texte2,texte3);
gtk_label_set_text(GTK_LABEL(output999),texte);
}


void
on_etran_filter_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
{filter1=1;}
else{filter1=0;}
}


void
on_local_filter_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
{filter=1;}
else{filter1=0;}

}

void
on_treeview_filter_row_activated       (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
	gint* jour;
	gint* mois;
	gint* annee;
	gint* bureau;
	gchar* cin;
	gchar* nom;
	gchar* prenom;
	gchar* nationalite;
	gchar* genre;
	
	observateur a;


	GtkTreeModel *model = gtk_tree_view_get_model(treeview);
 	
	if (gtk_tree_model_get_iter(model, &iter, path))
	{
	//obtention des valeurs de la ligne soulignéé
	
		gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0, &cin, 1, &nom, 2, &prenom, 3, &nationalite, 4, &genre, 5, &bureau, 6, &jour, 7,&mois,8,&annee -1);
		//copie des valeurs dans la variable m de type menu pour le passer à la fonction de suppression
		strcpy(a.cin,cin);
		strcpy(a.nom,nom);
		strcpy(a.prenom,prenom);
		strcpy(a.nationalite,nationalite);
		strcpy(a.genre,genre);

		a.bureau=bureau;
		a.date.jour=jour;
		a.date.mois=mois;
		a.date.annee=annee;

		//appel de la fonction de suppression
		
		//mise à jour de l'affichage de la treeview
		afficherlocaux(treeview);
	}
}


void
on_filter_filter_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *choix,*chercher_obser,*treeview2;
chercher_obser=lookup_widget(objet_graphique,"chercher_obser");
gtk_widget_destroy(chercher_obser);
chercher_obser=create_chercher_obser();
gtk_widget_show(chercher_obser);

treeview2=lookup_widget(chercher_obser,"treeview_filter");
if(filter==1 && filter1==0){
create(2);
afficherlocaux(treeview2);
}
else if(filter==0 && filter1==1)
{
create(1);
afficherlocaux(treeview2);
}
else {
afficherr(treeview2);}


}

