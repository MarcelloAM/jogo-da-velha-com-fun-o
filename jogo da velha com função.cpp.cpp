#include <stdlib.h>
#include <stdio.h>

char jogo[3][3];
int i, j;

void iniciarMatriz(){
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			jogo[i][j] = ' ';
		}
	}
}

void imprimir(){
	printf("\n\n\t 0   1   2\n\n");
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			if(j == 0){
				printf("\t");
			}
			printf(" %c ", jogo[i][j]);
			if(j < 2){
				printf("|");
			}
			if(j == 2){
				printf("  %d", i);
			}
		}
		printf("\n");
		if(i < 2){
			printf("\t-----------\n");
		}
	
	}
}
/*
	função para verificar vitoria da linha
	1 para ganhar
	0 para se não ganhou ainda
*/
int ganharPorLinha(int i, char c){
	if(jogo[i][0] == c && jogo[i][1] == c && jogo[i][2] == c){
		return 1;
	}else{
		return 0;
	}
}

/*
	função para verificar vitoria por linhas
	1 se ganhou
	0 se nao ganhou ainda

*/

int ganharPorLinhas(char c){
	int ganhar = 0;
	for(i = 0; i < 3; i++){
		ganhar += ganharPorLinha(i, c);
	}
	return ganhar;
}

/*
	função para verificar vitoria em coluna
	1 se ganhou
	0 se não ganhou ainda

*/

int ganharPorColuna(int j, char p){
	if(jogo[0][j] == p && jogo[1][j] == p && jogo[2][j] == p){
		return 1;
	}else{
		return 0;
	}
}

/*
	função para verificar vitoria por colunas
	1 se ganhou
	0 se nao ganhou ainda
*/

int ganharPorColunas(char p){
	int ganhar = 0;
	for(j = 0; j < 3; j++){
		ganhar += ganharPorColuna(j, p);
	}
	return ganhar;
}

/*
	função para verificar vitoria por diagonal
	1 se ganhou
	0 se nao ganhou ainda
*/
int ganharPorDiagonalPrincipal(char c){
	if(jogo[0][0] == c && jogo [1][1] == c && jogo[2][2]){
		return 1;
	}else{
		return 0;
	}
}

/*
	função para verificar vitoria por diagonal
	1 se ganhou
	0 se nao ganhou ainda
*/
int ganharPorDiagonalSecundaria(char c){
	if(jogo[0][2] == c && jogo [1][1] == c && jogo[2][0]){
		return 1;
	}else{
		return 0;
	}
}

/*
	função para dizer se uma coordenada é valida ou não
	1 se é valida
	0 se nao é valida
*/

int eValida(int i, int j){
	if(i >= 0 && i < 3 && j >= 0 && j < 3 && jogo[i][j] == ' '){
		return 1;
	}else{
		return 0;
	}
}

/*
	processo para ler as coordenada
*/

void lerCoordenada(char p){
	int linha, coluna; 
	
	printf("Digite linha e coluna: ");
	scanf("%d %d", &linha, &coluna);
	
	while(eValida(linha, coluna) == 0){
		printf("Coordenada Invalida, Informe uma coordenada Valida.");
		scanf("%d %d", &linha, &coluna);
	}
	jogo[linha][coluna] = p; 
}

// função para saber a qunatidad de posições vazias

int qtdVazias(){
	int quantidade = 0;
	
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			if(jogo[i][j] == ' '){
				quantidade++;
			}
		}
	}
	return quantidade;
}

void jogar(){
	int jogador = 1, vitoriaX = 0, vitoriaO = 0;
	char jogador1 = 'X', jogador2 = 'O';
	
	do{
		imprimir();
		if(jogador == 1){
			lerCoordenada(jogador1);
			jogador++;
			vitoriaX += ganharPorLinhas(jogador1);
			vitoriaX += ganharPorColunas(jogador1);
			vitoriaX += ganharPorDiagonalPrincipal(jogador1);
			vitoriaX += ganharPorDiagonalSecundaria(jogador1);
		}else{
			lerCoordenada(jogador2);
			jogador = 1;
			vitoriaO += ganharPorLinhas(jogador2);
			vitoriaO += ganharPorColunas(jogador2);
			vitoriaO += ganharPorDiagonalPrincipal(jogador2);
			vitoriaO += ganharPorDiagonalSecundaria(jogador2);
		}
	}while(vitoriaX == 0 && vitoriaO == 0 && qtdVazias() > 0);
	
	if(vitoriaO = 1){
		printf("\nJogador 2 venceu a partida.");
	}else 
	if(vitoriaX = 1){
		printf("\nJogador 1 venceu a partida.");
	}else{
		printf("\nNenhum Ganhou.");
	}
}



int main(){
	int opcao;
	
	do{
		iniciarMatriz();
		jogar();
		
		printf("Digite um para jogar novamente.\n");
		scanf("%d", &opcao);
	}while(opcao == 1);
	
	return 0;
}
