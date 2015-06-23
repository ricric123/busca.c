#include <stdio.h>
#include <stdlib.h>
#define TAM 50
#include <locale.h>
#include <time.h>

//prototipos
void preencheRandomico();
void preencheOrdenado();
int buscaSequencial(int n);
int buscaBinaria(int n);
void mostraVetor();
//variavel global

int vet[TAM];

void preencheOrdenado(){
	int i;
	
	for(i=0;i<TAM;i++){
		vet[i]=i;
	}
}

void mostraVetor(){
	int i;
	
	for(i=0;i<TAM;i++){
		if(i%10==0){
			printf("\n");
		}
		if(vet[i]<10){
			printf("0");
		}
		printf("%d", vet[i]);
	}
	printf("\n");
	system("pause");
}

void preencheRandomico(){
	int i, j;
	//controlar a posição onde será posionado o número randomico
	for(i=0;i<TAM;i++){
		vet[i]=rand()% TAM;
		
		//buscar o elemento no vetor
		for(j=0;j<i;j++){
			if(vet[j]==vet[j]){
				i--;
				break;
			}
		}
	}
}


int buscaSequencial(int n){
	int i;
	
	for(i=0;i<TAM;i++){
		if(n==vet[i]){
			return i;
		}
	}
	return -1;
}

int buscaBinaria(int n){
	int e, d, m;
	e=0;
	d=TAM-1;
	while(e<=d){
		m=(e+d)/2;
		if(n==vet[m]){
			return m;
		}else if(n>vet[m]){
			e=m+1;
		}else{
			d=m-1;
		}
	}
	return -1;
}

main(){
	srand(time(NULL));
	setlocale(LC_ALL, "");
	
	int op, num, pos;

	do{
		printf("# MÉTODOS DE BUSCA #\n\n");
		printf("1. Gerar vetor randomico\n");
		printf("2. Gerar vetor ordenado\n");
		printf("3. Busca sequencial\n");
		printf("4. Busca binária\n");
		printf("5. Sair\n\n");
		printf("Opção: ");
		scanf("%d", &op);
	
		switch(op){
			case 1:	
				preencheOrdenado();
				break;
			case 2:
				preencheRandomico();
				break;
			case 3:
				mostraVetor();
				break;
			case 4:
				printf("Informe um numero: ");
				scanf("%d", &num);
				pos=buscaSequencial(num);
				if(pos==-1){
					printf("Numero %d nao encontrado.\n", num);
				}else{
					printf("Numero %d encontrado na posição %d\n", num, pos);
				}
				break;
			case 5:
				printf("Informe um numero: ");
				scanf("%d", &num);
				if(pos==-1){
					printf("Numero não encontrado\n");	
				}else{
					printf("Posição: %d Numero: %d\n", pos, vet[pos]);
				}
				break;
			default:
				printf("Opção invalida. Tente novamente.\n\n");							
		}
		
	}while(op!=6);
}
