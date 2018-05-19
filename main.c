#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <locale.h>

void combate();
void acao_a(int *VP, int *VI);
void acao_b(int *VP, int *VI);
void acao_c(int *VP);
void efetividade_acao(int v1, int vm);


int main(int argc, char const *argv[])
{
	setlocale(LC_ALL, "Portuguese");
	srand(time(NULL));
	combate();
	return 0;
}

void combate()
{
	int vidaP = 200;
	int vidaI = 250;
	char opcao;
	do
	{
		system("cls");
		printf("Você         Inimigo\n");
		printf("Sua vida     vida inimigo\n");
		printf("%d           %d\n", vidaP, vidaI);
		printf("Escolha uma ação:\n");
		printf("a = ataque rápido\n");
		printf("b = magia\n");
		printf("c = curar\n");
		setbuf(stdin, NULL);
		scanf("%c", &opcao);

		switch (opcao)
		{
		case 'a': acao_a(&vidaP, &vidaI); break;
		case 'b': acao_b(&vidaP, &vidaI); break;
		case 'c': acao_c(&vidaP); break;
		}
	} while (vidaP>0 && vidaI>0);
	if (vidaP <= 0)
	{
		printf("Inimigo: Resistir é impossivel!\n");
		sleep(1);
		printf("Inimigo: Ha ha ha! Voce nunca poderá derrotar um cavaleiro tão poderoso quanto eu!\n");
	}
	if (vidaI <= 0)
	{
		printf("Inimigo: Não é possivel!!!\n");
		sleep(1);
		printf("Inimigo: Não é possivel! Logo eu, o tão glorioso cavaleiro imortal, perdi para um mísero aprendiz de feiticeiro!\n");
	}
}

void acao_a(int *VP, int *VI)
{
	int valor_max = 50;
	int aux = 10 + (rand() % 41);
	int auxII = 10 + (rand() % 41);
	*VI = *VI - aux;
	efetividade_acao(aux, valor_max);
	printf("você tirou %d pontos de vida do inimigo\n", aux);
	sleep(1);
	printf("Agora é a vez do inimigo\n");
	sleep(1);
	*VP = *VP - auxII;
	efetividade_acao(auxII, valor_max);
	printf("O inimigo tirou %d pontos de vida de você\n", auxII);
	sleep(1);

}
void acao_b(int *VP, int *VI)
{
	int valor_max = 70;
	int aux = rand() % 71;
	int auxII = rand() % 71;
	*VI = *VI - aux;
	efetividade_acao(aux, valor_max);
	printf("você tirou %d pontos de vida do inimigo\n", aux);
	sleep(1);
	printf("Agora é a vez do inimigo\n");
	sleep(1);
	efetividade_acao(auxII, valor_max);
	*VP = *VP - auxII;
	printf("O inimigo tirou %d pontos de vida de você\n", auxII);
	sleep(1);

}
void acao_c(int *VP)
{
	int valor_max = 70;
	int aux = 10 + (rand() % 61);
	int auxII = rand() % 45;
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
	if (v1 <= (25 * vm) / 100)
	{
		printf("...\n");
		sleep(1);
		printf("Não foi tao efetivo assim...\n");
		sleep(1);
	}
	else if ((v1 >= (26 * vm) / 100) && (v1 <= (65 * vm) / 100))
	{
		printf("...\n");
		sleep(1);
		printf("Foi bem efetivo!\n");
		sleep(1);
	}
	else if ((v1 >= (66 * vm) / 100) && (v1 <= (79 * vm) / 100))
	{
		printf("...\n");
		sleep(1);
		printf("Foi muito efetivo!\n");
		sleep(1);
	}
	else if (v1 >= (80 * vm) / 100)
	{
		printf("...\n");
		sleep(1);
		printf("Foi super efetivo!!!\n");
		sleep(1);
	}
}
