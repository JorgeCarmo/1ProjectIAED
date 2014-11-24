/* Grupo: al012
    Tomás Agostinho 73548
    Ricardo Ventura 79031
    Jorge Carmo 79702
      */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#define LIM 1400

int C, L, col, linhas, j, n, q, k;
unsigned int MAXcor, cor, ncaracteres;


struct pixel {
 unsigned char r,g,b; 
} ;

struct pixel vec[LIM];
struct pixel matriz[LIM][LIM];

void cabecalho(char comentario[], int M, int N);
void brancosecomentarios();
void espelho();
void negativo();
void padrao(int linhasfinais, int colunasfinais);


int main(int argc, char *argv[]){     /* funcao principal que recebe uma letra 'n', 'e' ou 'p' de maneira a escolher a funcao que define o novo formato da imagem */

	switch(argv[1][0]) {
		case 'n':{
			cabecalho("# negativo", 1, 1);
			negativo();
			break;
		}
		case 'e': {
			cabecalho("# espelho", 1, 1);
			espelho();
			break;
		}
		case 'p': {
			cabecalho("# padrao", atoi(argv[2]), atoi(argv[3])); 
			padrao(atoi(argv[2]), atoi(argv[3]));
		break; 
		} 
	default:
		return EXIT_FAILURE; /* Opção desconhecida (STDLIB)*/ 
	}
	return EXIT_SUCCESS; /* Termina o programa com sucesso (STDLIB) */
}


void cabecalho(char comentario[], int M, int N){  /* funcao que le e imprime o cabecalho da imagem original mantendo os comentarios originais */
	char c;
	
	brancosecomentarios();
	
	c=getchar(); putchar(c); /* Le e imprime numero magico */
	
	c=getchar(); putchar(c);
	
	if (strcmp(comentario,"# padrao")==0){
		printf("\n%s %dx%d\n", comentario, M, N); /* Insere novo comentario caso padrao*/
	}
	else{
			printf("\n%s\n", comentario); /* Insere novo comentario */
	}
	
	
	brancosecomentarios();
	
	scanf("%d",&C); printf("%d ",C*N); /* Le e imprime no. de colunas da img */
	
	col=C;
	
	brancosecomentarios();
	
	scanf("%d",&L); printf("%d\n",L*M); /* Le e imprime no. de linhas da img */
	
	linhas=L;
 
	brancosecomentarios();
 
	/* Le e imprime valor max RGB da img */
 
	scanf("%u", &MAXcor); 
 
	printf("%u\n",MAXcor);
	
	ncaracteres=(unsigned int)log10(MAXcor)+1;
 }


 
 void brancosecomentarios(){   /* funcao que copia todos os comentarios e todos os espacos da imagem original para a formatada */
	char c;
	c=getchar();
	while(isspace(c) || c=='#') {
		if(isspace(c)){ /* ignora todos os brancos */
			c=getchar();
		}else { /* preserva linhas comentadas */
			putchar(c);
			while ((c = getchar()) != '\n'){
				putchar(c);
			}
		putchar(c); 
		}
	}
	/* se nao e' branco nem comentario, devolve caracter e termina */
	ungetc(c, stdin); 
}

void negativo(){       /* funcao que percorre todos os pixeis e simultaneamente imprime o negativo de cada um */
	for(n=0; n<linhas; n++){
		for(k=0; k<col; k++){
			for (j=0; j<3; j++){
				if(j>0){	
					printf(" ");
				}
				scanf("%u", &cor);
				cor=MAXcor-cor;
				printf("%*u",ncaracteres ,cor);
			}
			if(k<(col-1)){
			printf("   ");
			}
		}
	printf("\n");
	}
}
 
 void espelho(){   /* funcao que percorre a imagem linha a linha e devolve-as espelhadas horizontalmente */
	if (col>1400){
		col=1400;
	}	
	for (n=0; n<linhas;n++){
		for (j=0; j<col; j++){
			scanf("%u", &cor);
			vec[j].r=(unsigned char)cor;
			scanf("%u", &cor);
			vec[j].g=(unsigned char)cor;
			scanf("%u", &cor);
			vec[j].b=(unsigned char)cor;
		}
		for (j=col-1; j>=0; j--){
			printf("%*u", ncaracteres, vec[j].r);
			printf(" %*u", ncaracteres, vec[j].g);
			printf(" %*u", ncaracteres, vec[j].b);
			if (j != 0){printf("   ");}
		}
		printf("\n");
	}
 }
  
  void padrao(int linhasfinais, int colunasfinais){   /* funcao que armazena a imagem original numa matriz e a imprime num padrao formando M linhas e N colunas de repeticoes de imagens, de acordo com os argumentos recebidos */
  	if (col>1400){
		col=1400;
	}	
  	if (linhas>1400){
		linhas=1400;
	}
	for (n=0; n<linhas;n++){ 
		for (j=0; j<col; j++){
			scanf("%u", &cor);
			matriz[n][j].r=(unsigned char)cor;
			scanf("%u", &cor);
			matriz[n][j].g=(unsigned char)cor;
			scanf("%u", &cor);
			matriz[n][j].b=(unsigned char)cor;
		}
	}
	
	for (q=0; q<linhasfinais; q++){
		for (n=0; n<linhas; n++){
			for (k=0; k<colunasfinais; k++){
				 
				for (j=0; j<col; j++){
					printf("%*u", ncaracteres, matriz[n][j].r);
					printf(" %*u", ncaracteres, matriz[n][j].g);
					printf(" %*u", ncaracteres, matriz[n][j].b);
					if (j < col-1){printf("   ");}
				}
				if (k < colunasfinais-1){printf("   ");}
			}
			printf("\n");
			
		}
	}
}











