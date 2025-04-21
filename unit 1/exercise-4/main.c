#include <stdio.h>

void white_image(int width, int height, FILE* fptr);

int main(){

  // dimensoes da imagem
  int width = 256;
  int height = 256;

  FILE* fptr;

  fptr = fopen("img.ppm", "rw+");
  if (fptr == NULL) {
    printf("Error opening file, please check if the file exists\n");
    return 1;
  }

  white_image(width, height, fptr);

  fclose(fptr);
  return 0;
}

void white_image(int width, int height, FILE* fptr){
    // Configurando o header do formato PPM
    fprintf(fptr, "P3\n %d \t %d\n 255\n", width, height);
    for (int i = 0; i < height; i++){ // Altura
      for (int j = 0; j < width; j++){ // Largura
        fprintf(fptr, "255 \t 255 \t 255\n"); // branco
      }
    }
  }