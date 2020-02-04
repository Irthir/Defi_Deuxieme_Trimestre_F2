#include "Commande.h"

void Commande()
{
    printf("Les commandes possibles sont :\n-Tchat afin de communiquer avec votre compagnon.\n-Quitter pour fermer le jeu.\n-Indice pour afficher la liste de vos indices.\n-Inspecter puis le nom de l'objet que vous voulez inspecter.\n-Reponse suivi de votre reponse pour donner votre reponse a une enigme.\n-Code suivi du code secret si vous l'avez trouve.\n");
}


void Avertissement()
{
    printf("Commande non reconnue, vous pouvez taper : Commande pour avoir la liste des commandes.\n");
}

void Introduction()
{
    printf("Bienvenue a vous deux !\nPour sortir, vous allez devoir cooperer et resoudre des enigmes pour trouver le code à 4 caracteres, afin de vous aider, voici le seul indice dont vous disposez: \"RJBV\".\nBon courage !\n");
}

void Indice()
{
     printf("Le seul indice dont vous disposez est \"RJBV\".\n");
}

void nonReconnu()
{
    printf("Objet non reconnu.\n");
}
