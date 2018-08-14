#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <locale.h>
#include <string.h>
#include <pthread.h>
#include <windows.h>


struct inimigo
	{
		char nome[50];
		char frasederrota[150];
		char frasevitoria[150];
		int vida;
		int ataque_maximo;
		int magia_maxima;
	};
void combate(struct inimigo *enemy, char *nome_jogador, char *classe);
void acao_a (int *VP, int *VI, int *AM, char *classe);
void acao_b (int *VP, int *VI, int *MM, char *classe);
void acao_c (int *VP, int *CT, char *classe);
void acao_d (int *VP, int *VI, int *MM, char *classe);
void efetividade_acao(int v1, int vm);
void *thread ();
void *thread1 ();
void *thread2 ();

int main(int argc, char *argv[])
{
	pthread_t thread_boss1;
	pthread_t thread_boss2;
	pthread_t thread_boss3;
	pthread_create(&thread_boss1, NULL, thread, NULL);
	
	struct inimigo inimigo01;
	struct inimigo inimigo02;
	struct inimigo inimigo03;
	struct inimigo inimigo04;
	char *nome = argv[1];	
	char *classe = argv[2];

	strcpy (inimigo01.nome, "Cavaleiro Dourado");
	strcpy (inimigo01.frasederrota, "Cavaleiro Dourado: Não é possível! Eu, o grande Cavaleiro Dourado, Fui derrotado por este mísero aprendiz de feiticeiro!!");
	strcpy (inimigo01.frasevitoria, "Cavaleiro Dourado: Ha ha ha ha! Resistir é impossível! Você nunca derrotará um cavaleiro tão poderoso quanto eu!");
	inimigo01.vida = 50;
	inimigo01.ataque_maximo = 50;
	inimigo01.magia_maxima = 70;
	strcpy (inimigo02.nome, "Elfo Estrelar");
	strcpy (inimigo02.frasederrota, "Elfo Estrelar: Você pode ter me vencido, mero feiticeiro. Mas garanto que do grande Chronos não vencerá!!");
	strcpy (inimigo02.frasevitoria, "Elfo Estrelar: Você é fraco! Para me vencer, terá de abandonar todas as suas esperanças!");
	inimigo02.vida = 50;
	inimigo02.ataque_maximo = 65;
	inimigo02.magia_maxima = 75;
	strcpy (inimigo03.nome, "Chronos");
	strcpy (inimigo03.frasederrota, "Chronos: Você superou todos os limites dos feiticeiros, este é o fim de todas as coisas...");
	strcpy (inimigo03.frasevitoria, "Chronos: Este é o castigo dos que se vão contra a mim! Sofra, mero feiticeiro! Este é o seu fim!");
	inimigo03.vida = 50;
	inimigo03.ataque_maximo = 68;
	inimigo03.magia_maxima = 80;
	strcpy (inimigo04.nome, "Chronos O Imortal");
	strcpy (inimigo04.frasederrota, "Chronos: O que????...");
	strcpy (inimigo04.frasevitoria, "Chronos: ADEUS!!!!");
	inimigo04.vida = 9999999;
	inimigo04.ataque_maximo = 99999;
	inimigo04.magia_maxima = 99999;
	setlocale(LC_ALL, "");
	srand(time(NULL));
	combate(&inimigo01, nome, classe);
	printf("Elfo Estrelar: Você pode ter vencido um fracote como o Cavaleiro Dourado, mas de mim você não passará!\n");
	PlaySound(NULL, 0, 0);
	pthread_create(&thread_boss2, NULL, thread1, NULL);
	sleep(3);
	combate(&inimigo02, nome, classe);
	printf("Chronos: Eu, o grade rei do Caos que envolve este mundo, seu grande criador, jamais permitirei uma mera cópia impura de um feiticeiro me vencer!\n");
	PlaySound(NULL, 0, 0);
	pthread_create(&thread_boss3, NULL, thread2, NULL);
	sleep(3);
	combate(&inimigo03, nome, classe);
		int i;
	  for(i=0;i<4000;i++){
    printf("00101010101100110100110101010101101001");    
    }
  	system("cls");
  	printf("Chronos: HAHAHAHAHAHAHAHAHAHAH Boa tentativa!!!...");
    sleep(4);
   	combate(&inimigo04, nome, classe);
   	system("pause");
	return 0;
}

void combate(struct inimigo *enemy, char *nome_jogador, char *classe)
{
	// opcao guerreiro
	if (strcmp(classe, "Guerreiro") == 0)
{	
	char classe[] = "Guerreiro";
    int vidaP = 300, i = 0;
	char opcao;
	do
	{
		system("cls");	
		printf("%s         %s\n", nome_jogador, enemy->nome);
		printf("Sua vida     vida inimigo\n");
		printf("%d           %d\n", vidaP, enemy->vida);
		printf("Escolha uma ação:\n");
		printf("a = ataque rápido\n");
		printf("b = magia\n");
		printf("c = curar(%d)\n", 3 - i);
		setbuf (stdin, NULL);
		scanf("%c", &opcao);

	switch(opcao)
		{
			case 'a': acao_a(&vidaP, &enemy->vida, &enemy->ataque_maximo, &classe); break;
			case 'b': acao_b(&vidaP, &enemy->vida, &enemy->magia_maxima, &classe); break;
			case 'c': acao_c(&vidaP, &i, &classe); break;
			case '-':acao_d(&vidaP, &enemy->vida, &enemy->magia_maxima, &classe); break;	
		}
	}while(vidaP>0 && enemy->vida > 0);
	if (vidaP <= 0)
	{
		printf("%s\n", enemy->frasevitoria);
		sleep(3);
		
	}
	if (enemy->vida <=0)
	{
		printf("%s\n", enemy->frasederrota);
		sleep(3);
	}
	}

	// opcoes vida Mago
	
	if (strcmp(classe, "Mago") == 0)
	{
	char classe[] = "Mago";	
	int vidaP = 200, i = 0;
	char opcao;
	do
	{
		system("cls");	
		printf("%s         %s\n", nome_jogador, enemy->nome);
		printf("Sua vida     vida inimigo\n");
		printf("%d           %d\n", vidaP, enemy->vida);
		printf("Escolha uma ação:\n");
		printf("a = ataque rápido\n");
		printf("b = magia\n");
		printf("c = curar(%d)\n", 3 - i);
		setbuf (stdin, NULL);
		scanf("%c", &opcao);

	switch(opcao)
		{
			case 'a': acao_a(&vidaP, &enemy->vida, &enemy->ataque_maximo, &classe); break;
			case 'b': acao_b(&vidaP, &enemy->vida, &enemy->magia_maxima, &classe); break;
			case 'c': acao_c(&vidaP, &i, &classe); break;	
			case '-':acao_d(&vidaP, &enemy->vida, &enemy->magia_maxima, &classe); break;
		}
	}while(vidaP>0 && enemy->vida > 0);
	if (vidaP <= 0)
	{
		printf("%s\n", enemy->frasevitoria);
		sleep(3);
		
	}
	if (enemy->vida <=0)
	{
		printf("%s\n", enemy->frasederrota);
		sleep(3);
	}
}

// opcoes vida Monge
	
	if (strcmp(classe, "Monge") == 0)
	{
	char classe[] = "Monge";
	int vidaP = 230, i = 0;
	char opcao;
	do
	{
		system("cls");	
		printf("%s         %s\n", nome_jogador, enemy->nome);
		printf("Sua vida     vida inimigo\n");
		printf("%d           %d\n", vidaP, enemy->vida);
		printf("Escolha uma ação:\n");
		printf("a = ataque rápido\n");
		printf("b = magia\n");
		printf("c = curar(%d)\n", 3 - i);
		setbuf (stdin, NULL);
		scanf("%c", &opcao);

	switch(opcao)
		{
			case 'a': acao_a(&vidaP, &enemy->vida, &enemy->ataque_maximo, &classe); break;
			case 'b': acao_b(&vidaP, &enemy->vida, &enemy->magia_maxima, &classe); break;
			case 'c': acao_c(&vidaP, &i, &classe); break;
			case '-':acao_d(&vidaP, &enemy->vida, &enemy->magia_maxima, &classe); break;	
		}
	}while(vidaP>0 && enemy->vida > 0);
	if (vidaP <= 0)
	{
		printf("%s\n", enemy->frasevitoria);
		sleep(3);
		
	}
	if (enemy->vida <=0)
	{
		printf("%s\n", enemy->frasederrota);
		sleep(3);
	}
}

	// opcoes vida Feiticeiro
	
	if (strcmp(classe, "Feiticeiro") == 0)
	{
	char classe[] = "Feiticeiro";
	int vidaP = 250, i = 0;
	char opcao;
	do
	{
		system("cls");	
		printf("%s         %s\n", nome_jogador, enemy->nome);
		printf("Sua vida     vida inimigo\n");
		printf("%d           %d\n", vidaP, enemy->vida);
		printf("Escolha uma ação:\n");
		printf("a = ataque rápido\n");
		printf("b = magia\n");
		printf("c = curar(%d)\n", 3 - i);
		setbuf (stdin, NULL);
		scanf("%c", &opcao);

	switch(opcao)
		{
			case 'a': acao_a(&vidaP, &enemy->vida, &enemy->ataque_maximo, &classe); break;
			case 'b': acao_b(&vidaP, &enemy->vida, &enemy->magia_maxima, &classe); break;
			case 'c': acao_c(&vidaP, &i, &classe); break;	
			case '-':acao_d(&vidaP, &enemy->vida, &enemy->magia_maxima, &classe); break;
		}
	}while(vidaP>0 && enemy->vida > 0);
	if (vidaP <= 0)
	{
		printf("%s\n", enemy->frasevitoria);
		sleep(3);
		
	}
	if (enemy->vida <=0)
	{
		printf("%s\n", enemy->frasederrota);
		sleep(3);
	}
}
}

void acao_a (int *VP, int *VI, int *AM, char classe[40])
{	

if (strcmp(classe, "Guerreiro") == 0){
	int valor_max = 500;
	int aux = 10 + (rand() % 100);
	*VI = *VI - aux;
	efetividade_acao(aux, valor_max);
	printf("você tirou %d pontos de vida do inimigo\n", aux);
	sleep(1);
	if (*VI > 0)
	{
		int auxII = 10 + (rand() % (*AM - 9));
		printf("Agora é a vez do inimigo\n");
		sleep(1);
    	*VP = *VP - auxII;
    	efetividade_acao(auxII, *AM);
    	printf("O inimigo tirou %d pontos de vida de você\n", auxII);
    	sleep(1);
    	
    }
	}

if (strcmp(classe, "Mago") == 0){
	int valor_max = 35;
	int aux = 10 + (rand() % 46);
	*VI = *VI - aux;
	efetividade_acao(aux, valor_max);
	printf("você tirou %d pontos de vida do inimigo\n", aux);
	sleep(1);
	if (*VI > 0)
	{
		int auxII = 10 + (rand() % (*AM - 9));
		printf("Agora é a vez do inimigo\n");
		sleep(1);
    	*VP = *VP - auxII;
    	efetividade_acao(auxII, *AM);
    	printf("O inimigo tirou %d pontos de vida de você\n", auxII);
    	sleep(1);
    	
    }
	}

if (strcmp(classe, "Monge") == 0){
	int valor_max = 60;
	int aux = 10 + (rand() % 46);
	*VI = *VI - aux;
	efetividade_acao(aux, valor_max);
	printf("você tirou %d pontos de vida do inimigo\n", aux);
	sleep(1);
	if (*VI > 0)
	{
		int auxII = 10 + (rand() % (*AM - 9));
		printf("Agora é a vez do inimigo\n");
		sleep(1);
    	*VP = *VP - auxII;
    	efetividade_acao(auxII, *AM);
    	printf("O inimigo tirou %d pontos de vida de você\n", auxII);
    	sleep(1);
    	
    }
	}

if (strcmp(classe, "Feiticeiro") == 0){
	int valor_max = 25;
	int aux = 10 + (rand() % 46);
	*VI = *VI - aux;
	efetividade_acao(aux, valor_max);
	printf("você tirou %d pontos de vida do inimigo\n", aux);
	sleep(1);
	if (*VI > 0)
	{
		int auxII = 10 + (rand() % (*AM - 9));
		printf("Agora é a vez do inimigo\n");
		sleep(1);
    	*VP = *VP - auxII;
    	efetividade_acao(auxII, *AM);
    	printf("O inimigo tirou %d pontos de vida de você\n", auxII);
    	sleep(1);
    	
    }
	}

}

void acao_b (int *VP, int *VI, int *MM, char classe[40])
{

if (strcmp(classe, "Guerreiro") == 0){
	int valor_max = 70;
	int aux = rand() % 76;
	*VI = *VI - aux;
	efetividade_acao(aux, valor_max);
	printf("você tirou %d pontos de vida do inimigo\n", aux);
	sleep(1);
	if (*VI > 0)
	{
		int auxII = (rand() % (*MM + 1));
		printf("Agora é a vez do inimigo\n");
		sleep(1);
		efetividade_acao(auxII, *MM);
    	*VP = *VP - auxII;
    	printf("O inimigo tirou %d pontos de vida de você\n", auxII);
    	sleep(1);
	}
	}

if (strcmp(classe, "Mago") == 0){
	int valor_max = 70;
	int aux = rand() % 76;
	*VI = *VI - aux;
	efetividade_acao(aux, valor_max);
	printf("você tirou %d pontos de vida do inimigo\n", aux);
	sleep(1);
	if (*VI > 0)
	{
		int auxII = (rand() % (*MM + 1));
		printf("Agora é a vez do inimigo\n");
		sleep(1);
		efetividade_acao(auxII, *MM);
    	*VP = *VP - auxII;
    	printf("O inimigo tirou %d pontos de vida de você\n", auxII);
    	sleep(1);
	}
	}

if (strcmp(classe, "Monge") == 0){
	int valor_max = 70;
	int aux = rand() % 76;
	*VI = *VI - aux;
	efetividade_acao(aux, valor_max);
	printf("você tirou %d pontos de vida do inimigo\n", aux);
	sleep(1);
	if (*VI > 0)
	{
		int auxII = (rand() % (*MM + 1));
		printf("Agora é a vez do inimigo\n");
		sleep(1);
		efetividade_acao(auxII, *MM);
    	*VP = *VP - auxII;
    	printf("O inimigo tirou %d pontos de vida de você\n", auxII);
    	sleep(1);
	}
	}

if (strcmp(classe, "Feiticeiro") == 0){
	int valor_max = 70;
	int aux = rand() % 76;
	*VI = *VI - aux;
	efetividade_acao(aux, valor_max);
	printf("você tirou %d pontos de vida do inimigo\n", aux);
	sleep(1);
	if (*VI > 0)
	{
		int auxII = (rand() % (*MM + 1));
		printf("Agora é a vez do inimigo\n");
		sleep(1);
		efetividade_acao(auxII, *MM);
    	*VP = *VP - auxII;
    	printf("O inimigo tirou %d pontos de vida de você\n", auxII);
    	sleep(1);
	}
	}

}
void acao_c (int *VP, int *CT, char classe[40])
{
if (strcmp(classe, "Guerreiro") == 0){
		int valor_max = 70;
	int aux = 10 + (rand() % 61);
	int auxII = rand() % 31;
	if (*CT >= 3)
	{
		printf("Você atingiu o limite de uso da cura! Perdeu a vez!\n");
	}
	if (*CT < 3)
	{
		*VP = *VP + aux;
		efetividade_acao(aux, valor_max);
		printf("Você se curou! Recebeu mais %d de vida\n", aux);
		sleep(1);
		*CT = *CT + 1;
	}
		printf("Agora é a vez do inimigo!\n");
		sleep(1);
		*VP = *VP - auxII;
		efetividade_acao(auxII, valor_max);
		printf("O inimigo tirou %d pontos de vida de você\n", auxII);
		sleep(1);	
	}
	

if (strcmp(classe, "Mago") == 0){
	int valor_max = 70;
	int aux = 10 + (rand() % 61);
	int auxII = rand() % 31;
	if (*CT >= 3)
	{
		printf("Você atingiu o limite de uso da cura! Perdeu a vez!\n");
	}
	if (*CT < 3)
	{
		*VP = *VP + aux;
		efetividade_acao(aux, valor_max);
		printf("Você se curou! Recebeu mais %d de vida\n", aux);
		sleep(1);
		*CT = *CT + 1;
	}
		printf("Agora é a vez do inimigo!\n");
		sleep(1);
		*VP = *VP - auxII;
		efetividade_acao(auxII, valor_max);
		printf("O inimigo tirou %d pontos de vida de você\n", auxII);
		sleep(1);
	}


if (strcmp(classe, "Monge") == 0){
	int valor_max = 70;
	int aux = 10 + (rand() % 61);
	int auxII = rand() % 31;
	if (*CT >= 3)
	{
		printf("Você atingiu o limite de uso da cura! Perdeu a vez!\n");
	}
	if (*CT < 3)
	{
		*VP = *VP + aux;
		efetividade_acao(aux, valor_max);
		printf("Você se curou! Recebeu mais %d de vida\n", aux);
		sleep(1);
		*CT = *CT + 1;
	}
		printf("Agora é a vez do inimigo!\n");
		sleep(1);
		*VP = *VP - auxII;
		efetividade_acao(auxII, valor_max);
		printf("O inimigo tirou %d pontos de vida de você\n", auxII);
		sleep(1);
	}

if (strcmp(classe, "Feiticeiro") == 0){
	int valor_max = 70;
	int aux = 10 + (rand() % 61);
	int auxII = rand() % 31;
	if (*CT >= 3)
	{
		printf("Você atingiu o limite de uso da cura! Perdeu a vez!\n");
	}
	if (*CT < 3)
	{
		*VP = *VP + aux;
		efetividade_acao(aux, valor_max);
		printf("Você se curou! Recebeu mais %d de vida\n", aux);
		sleep(1);
		*CT = *CT + 1;
	}
		printf("Agora é a vez do inimigo!\n");
		sleep(1);
		*VP = *VP - auxII;
		efetividade_acao(auxII, valor_max);
		printf("O inimigo tirou %d pontos de vida de você\n", auxII);
		sleep(1);
	}
	}
void acao_d (int *VP, int *VI, int *MM, char classe[40]){
	
	int valor_max = 9999999;
	printf("você tirou %d pontos de vida do inimigo\n", valor_max);
	sleep(1);
	if (*VI > 0)
	{
		int auxII = 0;
		printf("Agora é a vez do inimigo\n");
		sleep(1);
    	*VI = 0;
    	printf("O inimigo tirou %d pontos de vida de você\n", auxII);
    	sleep(1);
	}
}	
void efetividade_acao(int v1, int vm)
{
	if (v1 <= (25*vm)/100)
	{
		printf("...\n");
		sleep(1);
		printf("Não foi tão efetivo assim...\n");
		sleep(1);
	}
	else if ((v1 >= (26*vm)/100) && (v1<= (65*vm)/100))
	{
		printf("...\n");
		sleep(1);
		printf("Foi bem efetivo!\n");
		sleep(1);
	}
	else if ((v1 >= (66*vm)/100) && (v1 <= (79*vm)/100))
	{
		printf("...\n");
		sleep(1);
		printf("Foi muito efetivo!\n");
		sleep(1);
	}
	else if (v1 >= (80*vm)/100)
	{
		printf("...\n");
		sleep(1);
		printf("Foi super efetivo!!!\n");
		sleep(1);
	}
}
void *thread ()
{
PlaySound("boss1.wav", NULL,  SND_ASYNC);
pthread_exit(0);
}
void *thread1 ()
{
PlaySound("boss2.wav", NULL, SND_ASYNC);
pthread_exit(0);
}
void *thread2 ()
{
PlaySound("boss3.wav", NULL, SND_ASYNC);
pthread_exit(0);

}
