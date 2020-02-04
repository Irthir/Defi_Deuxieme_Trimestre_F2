#include "Client.h"

int nFonctionnementClient=1;

void client(void)
{
    pthread_t threadRecept;

    WSADATA WSAData;
    int erreur = WSAStartup(MAKEWORD(2,2), &WSAData);

    SOCKET sock;
    SOCKADDR_IN sin;

    if(!erreur)
    {
        /* Création de la socket */
        sock = socket(AF_INET, SOCK_STREAM, 0);

        char cIP[15]={'\0'};
        printf("Veuillez rentrer l'adresse IP de l'hote.\n");
        fflush(stdin);
        fgets(cIP,sizeof(cIP),stdin);
        fflush(stdin);

        /* Configuration de la connexion */
        sin.sin_addr.s_addr = inet_addr(cIP);
        sin.sin_family = AF_INET;
        sin.sin_port = htons(PORT);

        /* Si l'on a réussi à se connecter */
        if(connect(sock, (SOCKADDR*)&sin, sizeof(sin)) != SOCKET_ERROR)
        {
            printf("Connection a %s sur le port %d\n", inet_ntoa(sin.sin_addr), htons(sin.sin_port));

            pthread_create(&threadRecept,NULL,ReceptionClient,(void*)sock);

            system("cls");
            printf("Le tchat est lance.\nLe jeu est lance.\n");

            char cBuffer[100];

            Introduction();
            while(nFonctionnementClient>0)
            {
                fgets(cBuffer,sizeof(cBuffer),stdin);
                char *cInput=cBuffer;
                char *cVerb=strtok(cInput," \n");
                char *cNoun=strtok(NULL,"");
                if (cVerb!=NULL)
                {
                    if (strcmp(strupr(cVerb),"TCHAT")==0)
                    {
                        EnvoieClient(cNoun,sock);
                    }
                    else if(strcmp(strupr(cVerb),"COMMANDE")==0)
                        Commande();
                    else if(strcmp(strupr(cVerb),"QUITTER")==0)
                    {
                        nFonctionnementClient=0;
                        cNoun="Sulta";
                        //Ca veut dire "Fin" en draconique de D&D pour éviter qu'un joueur rentre ça sans faire exprès.
                        EnvoieClient(cNoun,sock);
                    }
                    else
                        Avertissement();
                }
            }

            pthread_join(threadRecept,NULL);
        }
        /* sinon, on affiche "Impossible de se connecter" */
        else
        {
            printf("Impossible de se connecter\n");
        }

        /* On ferme la socket */
        closesocket(sock);
        printf("Fermeture de la connexion.\n");
    }
    WSACleanup();
    printf("Fermeture du jeu.\n");
    return EXIT_SUCCESS;
}


void* ReceptionClient(void* data)
{
    char cBufferReception[100];
    while (nFonctionnementClient>0)
    {
        /* Si l'on reçoit des informations : on les affiche à l'écran */
        if (recv((int)data, cBufferReception, 100, 0) != SOCKET_ERROR)
        {
            if (strcmp(cBufferReception,"Sulta")==0)
            {
                nFonctionnementClient=0;
            }
            else
            {
                printf("[Serveur]: %s\n", cBufferReception);
            }
        }
    }
    return 0;
}

void EnvoieClient(char *cBuffer, SOCKET cSock)
{
    int sock_err;

    sock_err = send(cSock, cBuffer, 100, 0);

    if(sock_err != SOCKET_ERROR)
    {
        if (strcmp(cBuffer,"Sulta")!=0)
            printf("[Client]: %s\n", cBuffer);
    }
    else
        printf("Erreur de transmission\n");

    fflush(stdin);
}
