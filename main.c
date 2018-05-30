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
void combate(struct inimigo *enemy, char *nome_jogador);
void acao_a (int *VP, int *VI, int *AM);
void acao_b (int *VP, int *VI, int *MM);
void acao_c (int *VP);
void efetividade_acao(int v1, int vm);
void *funcao_thread1 ();



int main(int argc, char const *argv[])
{
	pthread_t thread1;
	pthread_create(&thread1, NULL, funcao_thread1, NULL);
	
	char nome[20];
	struct inimigo inimigo01;
	struct inimigo inimigo02;
	struct inimigo inimigo03;

	strcpy (inimigo01.nome, "Cavaleiro Dourado");
	strcpy (inimigo01.frasederrota, "Cavaleiro Dourado: Não é possível! Eu, o grande Cavaleiro Dourado, Fui derrotado por este mísero aprendiz de feiticeiro!!");
	strcpy (inimigo01.frasevitoria, "Cavaleiro Dourado: Ha ha ha ha! Resistir é impossível! Você nunca derrotará um cavaleiro tão poderoso quanto eu!");
	inimigo01.vida = 250;
	inimigo01.ataque_maximo = 50;
	inimigo01.magia_maxima = 70;

	strcpy (inimigo02.nome, "Elfo Estrelar");
	strcpy (inimigo02.frasederrota, "Elfo Estrelar: Você pode ter me vencido, mero feiticeiro. Mas garanto que do grande Chronos não vencerá!!");
	strcpy (inimigo02.frasevitoria, "Elfo Estrelar: Você é fraco! Para me vencer, terá de abandonar todas as suas esperanças!");
	inimigo02.vida = 265;
	inimigo02.ataque_maximo = 65;
	inimigo02.magia_maxima = 75;

	strcpy (inimigo03.nome, "Chronos");
	strcpy (inimigo03.frasederrota, "Chronos: Você superou todos os limites dos feiticeiros, este é o fim de todas as coisas...");
	strcpy (inimigo03.frasevitoria, "Chronos: Este é o castigo dos que se vão contra a mim! Sofra, mero feiticeiro! Este é o seu fim!");
	inimigo03.vida = 275;
	inimigo03.ataque_maximo = 68;
	inimigo03.magia_maxima = 80;

	setlocale(LC_ALL, "Portuguese");
	srand(time(NULL));
	printf("Digite o seu nome, jovem feiticeiro!\t");
	setbuf (stdin, NULL);
	scanf("%[^\n]", nome);
	combate(&inimigo01, nome);
	printf("Elfo Estrelar: Você pode ter vencido um fracote como o Caveliro Dourado, mas de mim você não passará!\n");
	sleep(3);
	combate(&inimigo02, nome);
	("Chronos: Eu, o grade rei do Caos que envolve este mundo, seu grande criador, jamais permitirei uma mera cópia impura de um feiticeiro me vencer!\n");
	sleep(3);
	combate(&inimigo03, nome);
	return 0;
}

void combate(struct inimigo *enemy, char *nome_jogador)
{
	int vidaP = 200;
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
	printf("c = curar\n");
	setbuf (stdin, NULL);
	scanf("%c", &opcao);

		switch(opcao)
		{
			case 'a': acao_a(&vidaP, &enemy->vida, &enemy->ataque_maximo); break;
			case 'b': acao_b(&vidaP, &enemy->vida, &enemy->magia_maxima); break;
			case 'c': acao_c(&vidaP); break;	
		}
	}while(vidaP>0 && enemy->vida > 0);
	if (vidaP <= 0)
	{
		printf("%s\n", enemy->frasevitoria);
		sleep(3);
		exit(0);
	}
	if (enemy->vida <=0)
	{
		printf("%s\n", enemy->frasederrota);
		sleep(3);
	}
}

void acao_a (int *VP, int *VI, int *AM)
{
	int valor_max = 55;
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
void acao_b (int *VP, int *VI, int *MM)
{
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
void acao_c (int *VP)
{
	int valor_max = 70;
	int aux = 10 + (rand() % 61);
	int auxII = rand() % 31;
	*VP = *VP + aux;
	efetividade_acao(aux, valor_max);
	printf("Você se curou! Recebeu mais %d de vida\n", aux);
	sleep(1);
	printf("Agora é a vez do inimigo!\n");
	sleep(1);
	*VP = *VP - auxII;
	efetividade_acao(auxII, valor_max);
	printf("O inimigo tirou %d pontos de vida de você\n", auxII);
	sleep(1);
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
void *funcao_thread1 ()
{
PlaySound("som.wav", NULL, SND_FILENAME);
}
