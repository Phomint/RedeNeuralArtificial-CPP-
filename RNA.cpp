
//Author Patrick Amaral

#include <stdio.h>
#include <stdlib.h>

void UK (int mat[4][4], float w[3], float vetor[]){
 	float res = 0;
 	float *ponteiro;

 		for(int l=0; l<4; l++){
 	       float soma = 0;

           for(int c=0; c<3; c++){
 			         res = (mat[l][c] * w[c]);
               printf("x%d: %0.1f\n", c+1, res);
 			         soma = soma + res;
			      }
			 printf("SIGMA: %0.1f\n", soma);

			 ponteiro = &vetor[l];
			 *ponteiro = soma;
		   }
}

void Limiar(float vetor[]){
	float *ponteiro;

	for(int c=0; c<4; c++){
		ponteiro = &vetor[c];
		  if(vetor[c] >= 0)
	 	    *ponteiro = 1;
		  else
	 	    *ponteiro = 0;
	   }
     printf("\nYl [%0.1f %0.1f %0.1f %0.1f]\n", vetor[0],vetor[1],vetor[2],vetor[3]);
}

void Delta(int mat[4][4], float vetor[], float w[], float delta[4][3]){
	float erro;
	float n = 0.1;
	float *ponteiro;
  printf("W recebido [%0.1f %0.1f %0.1f]\n", w[0],w[1],w[2]);
	for(int l=0;l<4;l++){
    erro = mat[l][3]-vetor[l];
    printf("Erro %.2f\n", erro);

	  	for(int c=0;c<3;c++){
	  	    ponteiro = &delta[l][c];
		      *ponteiro = (erro * n * mat[l][c]);

		      ponteiro = &w[c];
		      *ponteiro = w[c] + delta[l][c];
      }
      printf("Delta [%0.1f %0.1f %0.1f]\n", delta[l][0],delta[l][1],delta[l][2]);
      printf("Novo W [%0.1f %0.1f %0.1f]\n", w[0],w[1],w[2]);
   }

}


int main () {
 	int mat[4][4];
 	float w[3]={0.2,0.2,0.2};
 	float vetor[4];
 	float delta[4][3];

 	mat[0][0] = -1;
 	mat[0][1] = 0;
 	mat[0][2] = 0;
 	mat[0][3] = 0;
 	mat[1][0] = -1;
 	mat[1][1] = 0;
 	mat[1][2] = 1;
 	mat[1][3] = 0;
 	mat[2][0] = -1;
 	mat[2][1] = 1;
 	mat[2][2] = 0;
 	mat[2][3] = 0;
 	mat[3][0] = -1;
 	mat[3][1] = 1;
 	mat[3][2] = 1;
 	mat[3][3] = 1;

for (int i = 1; i <= 10; i++) {
  printf("\n########## ÉPOCA %d ##########\n", i);
  UK(mat, w, vetor);
 	Limiar(vetor);
 	Delta(mat, vetor, w, delta);

}

 	return 0;
 	}
