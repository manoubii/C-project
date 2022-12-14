#include <gtk/gtk.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>




void
on_button2_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_AJobs_clicked                       (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_Suppobs_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button4_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button5_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_statobs_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_ajtobs_clicked                      (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_treeviewobs_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_findobs_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data);
void
on_deleteobs_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_affdataobs_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button12_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_rdobs_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_rdobs2_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_difer_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_actliste_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data);









///////////////////////////////////

/*
void
on_AJobs_clicked                       (GtkButton       *button,
                                        gpointer         user_data);

void
on_button2_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_Suppobs_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_button4_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_button5_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_statobs_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_rdobs_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_rdobs2_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_ajtobs_clicked                      (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeviewobs_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_difer_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_actliste_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_findobs_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_deleteobs_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_affdataobs_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_button12_clicked                    (GtkButton       *button,
                                        gpointer         user_data);
*/

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_retour_choix_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_retour_list_choix_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_retour_supp_choix_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_retour_modif_choix_clicked         (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button17_Mchercher_clicked          (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_retour_choix_chercher_ob_clicked     (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_calcul_homme_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_calcul_femme_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_retour_stat_choix_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_treeview_observateur_row_activated  (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_get_cal_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_etran_filter_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_local_filter_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_treeview_filter_row_activated       (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_filter_filter_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data);
