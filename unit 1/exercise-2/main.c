#include <stdio.h>

int main(){

  // dimensoes da imagem
  int width = 256;
  int height = 256;

  // Configurando o header do formato PPM
  printf("P3\n %d \t %d\n 255\n", width, height);

  int x, y;

  scanf("%d %d", &x, &y);

  for (int i = 0; i < height; i++){ // Altura
    for (int j = 0; j < width; j++){ // Largura
      if(i == x && j == y){
        printf("255 \t 0 \t 0\n"); // vermelho
      } else {
        printf("0 \t 0 \t 0\n"); // preto
      }
    }
  }

  return 0;
}