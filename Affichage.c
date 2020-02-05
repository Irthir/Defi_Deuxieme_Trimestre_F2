#include "Affichage.h"

#define NOIR 0
#define BLANC 15
#define GRISCLAIR 7
#define ROUGE 12
#define BLEU 11
#define JAUNE 14
#define VERT 2


void AfficheSalleJ1()
{
	color(GRISCLAIR, NOIR);
	printf("Vous etes desormais enferme dans une salle, on trouve differentes choses de chaque cote de la salle:\n-un ");

	color(BLANC, NOIR);
	printf("Tableau\n");//On affiche "Tableau" en blanc sur fond noir pour le mettre en valeur, ça sera ce que le joueur doit entrer avec le mot-clé inspecter

	color (GRISCLAIR, NOIR);//On reviens à la couleur de base
	printf("-une ");

	color(BLANC, NOIR);
	printf("Cage\n");

	color(GRISCLAIR, NOIR);
	printf("-une ");

	color (ROUGE, NOIR);	//On affiche Pile en rouge
	printf("Pile ");

	color(GRISCLAIR, NOIR);
	printf("de cubes.\n");
}

void descTableau()
{
	color(BLANC, NOIR);
	printf("Sur le mur à votre droite se trouve un tableau qui semble dater de la renaissance.\nEnfin c’est ce que vous pensez, vous n'avez jamais rien compris a l'art.");
	color(GRISCLAIR, NOIR);
}

void descCage()
{
	color(BLANC, NOIR);
	printf("Sur la table devant vous se trouve une cage a oiseau vide et sinistre.");
	color(GRISCLAIR, NOIR);
}

void affPile()
{
    color(ROUGE,NOIR);

	FILE * pFile;

    char * mot = malloc(sizeof(*mot));
    char nvMot[2];
    int nbChar = 0;
    int nbMots = 0;
    pFile = fopen("cube.txt", "r");
    if (pFile != NULL)
    {
        char a;
        while(a != EOF)
        {
            a = fgetc(pFile);
            nvMot[0] = a;
            if(a != EOF && a != '\n')
            {
                nbChar++;
                mot = realloc(mot, nbChar*sizeof(*mot));
                strcat(mot, nvMot);
            }
            if(a == '\n')
            {
                nbMots++;
                strcat(mot, " ");
                printf("%s(%i)(%i)\n",mot, nbChar, nbMots);
                nbChar = 0;
                mot = realloc(mot, nbChar*sizeof(*mot));
            }
        }
        free(mot);
        fclose(pFile);
    }

	color(GRISCLAIR, NOIR);
}

void enigmeJ1()
{
	color(GRISCLAIR, NOIR);
	printf("Une voix resonne dans la piece:\n");
	color(BLEU, NOIR);
	printf("Si je cours un marathon et que je depasse le deuxieme, quelle place ai-je ?\n");
	color(GRISCLAIR, NOIR);
}


void AfficheSalleJ2()
{
	color(GRISCLAIR, NOIR);
	printf("Vous etes desormais enferme dans une salle, on trouve differentes choses de chaque cote de la salle:\n-une ");

	color(BLANC, NOIR);
	printf("Television\n");

	color(GRISCLAIR, NOIR);
	printf("-une ");

	color (JAUNE, NOIR);
	printf("Gravure\n");

	color(GRISCLAIR, NOIR);
	printf("-une ");

	color(BLANC, NOIR);
	printf("Bougie");

	color(GRISCLAIR, NOIR);
	printf(".\n");
}

void descTelevision ()
{
	color(BLANC, NOIR);
	printf("Une television se trouve a votre gauche, elle n'affiche que de la neige peu importe ce que vous faites.");
	color(GRISCLAIR, NOIR);
}

void descGravure ()
{
	//on affiche le carré magique au dessus
	color (JAUNE, NOIR);
	printf("Devant vous, une etrange tablette de bois jaune s'illumine.\n Une question s'affiche en dessous: <<Quel est le nombre manquant ?>>");
	color(GRISCLAIR, NOIR);
}

void descBougie ()
{
	color(BLANC, NOIR);
	printf("La flamme d'une bougie danse a votre droite … et … c'est juste une bougie.");
	color(GRISCLAIR, NOIR);
}

void enigmeJ2 ()
{
	color(GRISCLAIR, NOIR);
	printf("Une voix resonne dans la piece:\n");
	color(VERT, NOIR);
	printf("Si 1 est egal a 5, 2 est egal a 25, 3 a 605, 4 a 10855, 5 est egal a quoi?\n");
	color(GRISCLAIR, NOIR);
}

void Code1()
{
    color(GRISCLAIR, NOIR);
    printf("Vous trouvez un morceau de code il y est note : ");
    color(ROUGE,NOIR);
    printf("C\n");
    color(GRISCLAIR, NOIR);
}

void Code2()
{
    color(GRISCLAIR, NOIR);
    printf("Vous trouvez un morceau de code il y est note : ");
    color(JAUNE,NOIR);
    printf("H\n");
    color(GRISCLAIR, NOIR);
}

void Code3()
{
    color(GRISCLAIR, NOIR);
    printf("Vous trouvez un morceau de code il y est note : ");
    color(BLEU,NOIR);
    printf("A\n");
    color(GRISCLAIR, NOIR);
}

void Code4()
{
    color(GRISCLAIR, NOIR);
    printf("Vous trouvez un morceau de code il y est note : ");
    color(VERT,NOIR);
    printf("T\n");
    color(GRISCLAIR, NOIR);
}
