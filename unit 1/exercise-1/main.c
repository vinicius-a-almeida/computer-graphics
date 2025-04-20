#include <stdio.h>

int main(){

  // dimensoes da imagem
  int width = 100;
  int height = 100;

  // Configurando o header do formato PPM
  printf("P3\n %d \t %d\n 255\n", width, height);

  for (int i = 0; i < height; i++){ // Altura
    for (int j = 0; j < width; j++){ // Largura
      printf("%d \t %d \t %d \n", 0, 0, 0);
      if(i == 50 && j == 50){
        printf("%d \t %d \t %d \n", 255, 0, 0);
    }
    }
  }

  return 0;
}