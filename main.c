#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#include "maBIB.h"
void main() {
    system("color F0");
    bool quitter = false;
    int idCherche,idprodsupprimer,nbProd,nbService,idServmodifier,idServchercher,idServsupprimer;
    int nbRendezvous,idrendezmodifier,idrendezrechercher,idrendezsupprimer;
    int nbAvis,cinRecherche;
    int annee_fin,annee_debut;
    float totalSalaires,pourcentage;
    FILE*fs;
    FILE*fss;
    FILE*fr;
    FILE*fa;
    creerFichierDeStock(&fs);
    creerFichierDeService(&fss);
    creerFichierDeRendezvous(&fr);
    creerFichierAvis(&fa);
    while (!quitter){
        int choix;
        choix = menu_principal();
        switch (choix){
        case 1:
            bool quitterrendezvous = false;
            int choix1;
            while(!quitterrendezvous){
                choix1 = menu_rendezvous();
                switch(choix1){
                    case 1:
                        remplirFichierRendezvous(fr, nbRendezvous);
                        break;
                    case 2:
                        modifierRendezVous( fr, idrendezmodifier);
                        break;
                    case 3:
                        supprimerRendezVous(fr, idrendezsupprimer);
                        break;
                    case 4:
                        rechercherRendezVous(fr, idrendezrechercher);
                        break;
                    case 5:
                        afficherFichierRendezvous(fr);
                        break;
                    case 6:
                        quitterrendezvous = true;
                        break;

                    default:
                        printf("Option invalide\n");
                        break;
                }
            }
            break;
        case 2:
            bool quitterservices = false;
            int choix2;
            while (!quitterservices){
                choix2 = menu_services();
                switch (choix2)
                {
                case 1:
                    remplirFichierService(fss, nbService);
                    break;
                case 2:
                    modifierService(fss , idServmodifier );
                    break;
                case 3:
                    supprimerService(fss , idServsupprimer );
                    break;
                case 4:
                    rechercherService(fss, idServchercher);
                    break;
                case 5:
                    afficherFichierService(fss);
                    break;
                case 6:
                    totalSalaires = calculerSalaireTotal(fss);
                    printf("\nLe salaire total de tous les employes est : %.2f\n", totalSalaires);
                    break;
                case 7:
                    rechercherServiceLePlusCher(fss);
                    break;
                case 8:
                    quitterservices = true;
                    break;
                default:
                    printf("Option invalide\n");
                    break;
                }
            }
            break;
        case 3:
            bool quitterStock = false;
            int choix3;
            while (!quitterStock){
                choix3 = menu_stock();
                switch (choix3){
                case 1:
                        remplirFichierStock(fs, nbProd);
                        break;
                    case 2:
                        afficherFichierStock(fs);
                        break;
                    case 3:
                        modifierProduit(fs, idprodsupprimer);
                        break;
                    case 4:
                        chercherProduitParID(fs, idCherche);
                        break;
                    case 5:
                        chercherProduitsEpuise(fs);
                        break;
                    case 6:
                        supprimerProduit(fs, idprodsupprimer);
                        break;
                    case 7:
                        quitterStock = true;
                        break;
                default:
                    printf("Option invalide\n");
                    break;
                }
            }
        break;
        case 4:
            bool quitteravis = false;
            int choix4;
            while (!quitteravis){
                choix4 = menu_avis();
                switch (choix4){
                    case 1:
                        remplirFichierAvis(fa,fr,nbAvis);
                        break;
                    case 2:
                        chercherAvisParCIN(fa, cinRecherche);
                        break;
                    case 3:
                        pourcentage = calculerPourcentageNotes(fa);
                        printf("Pourcentage des notes >= 3 : %.2f%%\n", pourcentage);
                        break;
                    case 4:
                        afficherFichierAvis(fa);
                        break;
                    case 5:
                        quitteravis = true;
                        break;
                    default:
                        printf("Option invalide\n");
                        break;
                }
            }
            break;
        case 5:
            bool quitterRES = false;
            int choix5;
            while(!quitterRES){
                choix5 = menu_RES();
                switch (choix5){
                case 1:
                    printf("Entrer l'annee debut : ");
                    scanf("%d", &annee_debut);
                    printf("Entrer l'annee fin : ");
                    scanf("%d", &annee_fin);
                    RESULTAT** tableau = creerTableauTop3ParAnnee(fr, annee_debut, annee_fin);
                    afficherTableauTop3ParAnnee(tableau, annee_debut, annee_fin);
                    libererTableauTop3ParAnnee(tableau, annee_debut, annee_fin);
                    break;
                case 2:
                    quitterRES = true;
                    break;

                default:
                    printf("Option invalide\n");
                    break;
                }
            }
            break;
        case 6:
            bool quitter_clients = false;
            int choix6, CIN_client, CIN;
            while (!quitter_clients){
                choix6 = menu_clients();
                switch (choix6){
                case 1:
                    afficherAnimauxClient(fr, CIN_client);
                    break;
                case 2:
                    calculerNombreDeTraitements(fr,CIN);
                    afficherNombreDeTraitements(fr);
                    break;
                case 3:
                    quitter_clients = true;
                    break;
                default:
                    printf("Option invalide\n");
                    break;
                }
            }
            break;
        case 7:
            quitter=true;
            break;
        default:
            printf("Option invalide\n");
            break;
        }
    }
    if (fs != NULL, fss != NULL, fr != NULL, fa != NULL){ {
        fclose(fss);
        fclose(fs);
        fclose(fr);
        fclose(fa);
    }
    }
}

