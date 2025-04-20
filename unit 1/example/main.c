#include <stdio.h>

int main(){

  // dimensoes da imagem
  int width = 256;
  int height = 256;

  // Configurando o header do formato PPM
  printf("P3\n %d \t %d\n 255\n", width, height);

  for (int i = 0; i < height; i++){ // Altura
    for (int j = 0; j < width; j++){ // Largura
      printf("%d \t %d \t %d \n", i, j, 63);
    }
  }

  return 0;
}