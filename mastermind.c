#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 4

typedef int Code[MAX];

// Déclarations des fonctions
int menu(int choix);
void jeu(int choix);
void regles(int choix);

//Fonction de selection des nombre aleatoire allant de 1 a 6 
int nombre_aleatoire()
{	
    int aleatoire;
	aleatoire=rand()%6+1;
	return aleatoire;
}

//Fonction qui met le code secret de 4 lettre dans un tableau apres la selction aleatoire
int code_aleatoire(Code code_secret)
{
	int aleatoire;
	int i;
	
	for(i=0;i<MAX;i++)
	{
		aleatoire=nombre_aleatoire();
		code_secret[i]=aleatoire;
	}
}

//Fonction de verification de non doublons dans le tableau, Pour cela on se sert d'une boucle do while
int Comparaison (Code code_secret)
{
	do
	{
		code_aleatoire(code_secret);
	}
	while( (code_secret[0]==code_secret[1]) || (code_secret[0]==code_secret[2]) || (code_secret[0]==code_secret[3]) || (code_secret[1]==code_secret[2]) || (code_secret[1]==code_secret[3]) || (code_secret[2]==code_secret[3]) );
}

// Procedure qui fait la conversion du code secret qui est en nombre entier en lettre.

void conversion_secret_couleur(Code code_secret)
{
    char code_couleur[MAX];
	int i;
	
    for(i=0;i<MAX;i++)
    {
        if(code_secret[i]==1) code_couleur[i]='N'; // NOIR
        else if(code_secret[i]==2) code_couleur[i]='B'; //BLEU
        else if(code_secret[i]==3) code_couleur[i]='V'; //VERT
        else if(code_secret[i]==4) code_couleur[i]='W'; //BLANC
        else if(code_secret[i]==5) code_couleur[i]='R'; //ROUGE
        else if(code_secret[i]==6) code_couleur[i]='J'; //JAUNE
    }
    printf("%s \n",code_couleur);
}

// Procedure qui fait la conversion du code entree par l'utilisateur avec des lettres 
// par des chiffres de 1 � 6 correspondant a chaque letrre
void conversion_Proposition_couleur(Code code_Proposition, char code_couleur[4])
{
    int i;
    for(i=0;i<MAX;i++)
    {
        // Condition qui permet de verifier les caracteres sont bien ceux utile pour la combinaison

        if(code_couleur[i]=='N' || code_couleur[i]=='N' || code_couleur[i]=='B' || code_couleur[i]=='b' || code_couleur[i]=='V' || code_couleur[i]=='v' || code_couleur[i]=='W' || code_couleur[i]=='w' || code_couleur[i]=='R' || code_couleur[i]=='r' ||code_couleur[i]=='J' || code_couleur[i]=='j') 
        {  
            if( (code_couleur[i]=='N') || (code_couleur[i]=='n') ) code_Proposition[i]=1; // NOIR
            else if ( (code_couleur[i]=='B') || (code_couleur[i]=='b') ) code_Proposition[i]=2; //BLEU
            else if ( (code_couleur[i]=='V') || (code_couleur[i]=='v') ) code_Proposition[i]=3; //VERT
            else if ( (code_couleur[i]=='W') || (code_couleur[i]=='w') ) code_Proposition[i]=4; //BLANC
            else if ( (code_couleur[i]=='R') || (code_couleur[i]=='r') ) code_Proposition[i]=5; //ROUGE
            else if ( (code_couleur[i]=='J') || (code_couleur[i]=='j') ) code_Proposition[i]=6; //JAUNE
        }
        else
            code_Proposition[i]=0;
    }
}

// Reinisialise le tableau de code proposition a cas ou si l'utilisateur
int Reinisalisation_Proposition(Code code_Proposition)
{
    int i;
    for(i=0;i<MAX;i++)
    {
        code_Proposition[i]=0;
    }
    
}

// Cette fonction fait la comparaison du code secret choisi aleatoirement avec la proposition entree par l'utilisateur
int Noir(Code code_Proposition, Code code_secret)
{
    int noir=0;
    int i,j;
    for(i=0 ; i<MAX ; i++)
        for(j=0 ; j<MAX ; j++)
        {
            if(code_Proposition[j]==1 || code_Proposition[j]==2 || code_Proposition[j]==3 || code_Proposition[j]==4 || code_Proposition[j]==5 || code_Proposition[j]==6)
            {
                if(code_secret[i]==code_Proposition[j])
                    if(i==j)
                        noir=noir+1;            
            }
            else
                noir=0;
        }
    return noir;
}

// Cette fonction fait la comparaison du code secret choisi aleatoirement avec la proposition entree par l'utilisateur
int Blanche(Code code_Proposition, Code code_secret)
{
    int blanche=0;
    int i,j;
    for(i=0 ; i<MAX ; i++)
        for(j=0 ; j<MAX ; j++)
        {
            if(code_Proposition[j]==1 || code_Proposition[j]==2 || code_Proposition[j]==3 || code_Proposition[j]==4 || code_Proposition[j]==5 || code_Proposition[j]==6)
            {
                if(code_secret[i]==code_Proposition[j])
                    if(i!=j) 
                        blanche=blanche+1;
            }
            else
                blanche=0;
        }
    return blanche;
}

// Fait l'affichage des caractere entree par l'utilisateur
void Affichage_caractere(char caractere[MAX])
{
    int i;

	for(i=0;i<MAX;i++)
	    printf(" %c |",caractere[i]);
}

// Le Jeu
void jeu(int choix)
{
    // system("cls" );
    Code code_Proposition;
    Code code_secret;
    int i;
    int noir,blanche;
    int Essaie=0;
    int tous_bon=0;
    char code_couleur[MAX];
    
	srand(time(NULL)); //Initialisation du ramdom
	Comparaison(code_secret);
	
	// Interface Graphique
    printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
    printf("!!!                     !!!\n");
    printf("!!!  JEU du MASTERMIND  !!!\n");
    printf("!!!                     !!!\n");
    printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
    printf("\n\n"); 
	printf("Touche du clavier correspondante \n");
	printf(" N ou n : Noir \n B ou b : Bleu \n V ou v : Vert \n W ou w : Blanc \n R ou r : Rouge \n J ou j : Jaune \n\n");
	printf("Entrer les lettres les uns a la suite des autres et non en colonne !\n");
	printf("Par exemple : \n");
	printf(" BON : RJBN ou rjbn \n");
	printf(" PAS BON !!! : \n R \n J\n B\n N\n");
	printf("Pour Valider votre combinaison appuyer sur la touche ENTRER !\n");
	printf("------------------------------------------------------------------------------\n\n" );
	printf("|~~~~~~~|~~~~~~~~~~~~~~~|    |~~~~~~~~~~~~~~|  |~~~~~~~~~|\n");
    printf("| Essai | A | B | C | D |    |    Reponse   |  | Entrer  |\n");
    printf("|       |   |   |   |   |    | noir | blanc |  | Couleur |\n");
    printf("|~~~~~~~|~~~|~~~|~~~|~~~|    |~~~~~~|~~~~~~~|  |~~~~~~~~~|\n");
    
    // le do while est ici pour simuler les 10 chances possible qu'a l'utilisateur de marque une proposition  
    do
    {
        printf("|~~~~~~~|~~~|~~~|~~~|~~~|    |~~~~~~|~~~~~~~|  |   "); // Interface Graphique
        
        scanf("%s",&code_couleur);
        printf("|%4d   |",Essaie+1); // Interface Graphique
        Affichage_caractere(code_couleur);
        conversion_Proposition_couleur(code_Proposition, code_couleur);
    
        noir=Noir(code_Proposition,code_secret);
        blanche=Blanche(code_Proposition,code_secret);
        
        printf("    |   %d  |   %d   | ", noir,blanche); // Interface Graphique
        printf(" |~~~~~~~~~|\n"); // Interface Graphique
        
        Essaie=Essaie+1;
        for(i=0 ; i<MAX ; i++)
            if(code_secret[i]==code_Proposition[i]) 
                tous_bon += 1;
            if(tous_bon==4) 
                Essaie=10;
    }while(Essaie!=10);
    
    // Interface Graphique
    if(tous_bon==MAX)
    {
        printf("\n\n\n"); 
        printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
        printf("!!!                          !!!\n");
        printf("!!!  BRAVO VOUS AVEZ GAGNE   !!!\n");
        printf("!!!                          !!!\n");
        printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
        conversion_secret_couleur(code_secret);
    }
    else 
    {
        printf("\n\n\n"); 
        printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
        printf("!!!                         !!!\n");
        printf("!!!  BRAVO VOUS AVEZ PERDU  !!!\n");
        printf("!!!                         !!!\n");
        printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
        printf("\n\n Le code Secret etait :");
        conversion_secret_couleur(code_secret);
    }
    
    // Permet de retourner au menu ou de refaire une partie
    printf("------------------------------------------------------------------------------\n\n" );
    printf("Entrer (0) pour revenir au menu principale\n" );
    printf("Entrer (1) pour refaire une partie\n" );
    printf("Pour Valider votre choix appuyer sur la touche ENTRER !\n");
    scanf("%d", &choix);
   
    if (choix==0) 
        menu(choix);
    else if(choix==1)
        jeu(choix);
    
}

// Procedure qui permet de lire les regles du jeu du mastermind et de retourner au menu
void regles(int choix)
{
    system("cls" ); //Nettoyer la console
    //Affichage des r�gles du Mastermind
    printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
    printf("!!!                          !!!\n");
    printf("!!!   REGLES DU MASTERMIND   !!!\n");
    printf("!!!                          !!!\n");
    printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
    printf("\n\n\n");
    printf("Le programme choisit une combinaison de 4 pions de couleurs au hasard\n");
    printf("parmi 6 couleurs disponibles.\n");
    printf("Cette combinaison de pions ne contient qu\'une seul couleur de chaque pion.\n");
    printf("L\'utilisateur essaie de la deviner.\n");
    printf("Il a un maximum de 10 tentatives pour trouver la bonne.\n");
    printf("Pour chaque tentative le programme indique : \n");
    printf(" - le nombre de couleurs bien placees (a l\'aide de pion noir) \n");
    printf(" - le nombre de couleurs mal placees (a l\'aide de pion blanc) \n");
    printf("Si le nombre maximal d\'essais est atteint \n");
    printf("et qu'il n'a pas donne la bonne combinaison au dernier essai, \n");
    printf("alors le programme indique au joueur qu\'il a perdu et donne la combinaison.\n\n");
    printf("------------------------------------------------------------------------------\n\n" );
    printf("Entrez (0) pour revenir au menu principale\n" );
    printf("Pour Valider votre choix appuyer sur la touche ENTRER !\n");
    scanf("%d", &choix);
   
    if (choix==0) 
        menu(choix);        
}

// Menu du jeu master mind comprenant le jeu, les regles du jeu et quitter
int menu(int choix)
{
    int quitte;
     // Nettoyer la console
     system("cls");
     
    printf("==========================\n");
    printf("===                    ===\n");
    printf("===     MASTERMIND     ===\n");
    printf("===                    ===\n");
    printf("==========================\n\n");

    printf("========== MENU ==========\n");
    printf("===                    ===\n");
    printf("===  1 : Jouer         ===\n");
    printf("===  2 : Regles du jeu ===\n");
    printf("===  0 : Quitter       ===\n");
    printf("===                    ===\n");
    printf("==========================\n");
    printf("Pour Valider votre choix appuyer sur la touche ENTRER !\n\n\n");
    printf("Que voulez vous faire ? ");
    do
    {
        scanf("%d", &choix);
            switch(choix)
            {
                case 1 : 
                    {
                         jeu(choix); 
                         break;
                    }
                case 2 : 
                    {
                         regles(choix); 
                         break ;
                    }
                case 0 : 
                     {
                         printf("Vous avez quitte le jeu. \n"); 
                         quitte=1; 
                         break;
                     }    
                default :
                    {
                        menu(choix); 
                        break;
                    }
            }
    } while(quitte==0);
}

int main()
{
    int choix;
    menu(choix);
    
    system("pause");
    return 0;
}
