#include "Commande.h"

void Commande()
{
    printf("Les commandes possibles sont :\n-Tchat afin de communiquer avec votre compagnon.\n-Quitter pour fermer le jeu.\n");
}


void Avertissement()
{
    printf("Commande non reconnue, vous pouvez taper : Commande pour avoir la liste des commandes.\n");
}

void Introduction()
{
    printf("Bienvenue a vous deux !\n Pour sortir, vous allez devoir cooperer et resoudre des enigmes pour trouver le code à 4 caracteres, afin de vous aider, voici le seul indice dont vous disposez: “RJBV”.");
}
