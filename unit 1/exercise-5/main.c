#include <stdio.h>

void red_T_image(int width, int height, FILE* fptr);

int main(){

  // dimensoes da imagem
  int width = 100;
  int height = 100;

  FILE* fptr;

  fptr = fopen("img.ppm", "rw+");
  if (fptr == NULL) {
    printf("Error opening file, please check if the file exists and if has the name 'img.ppm'\n");
    return 1;
  }

  red_T_image(width, height, fptr);

  fclose(fptr);
  return 0;
}

void red_T_image(int width, int height, FILE* fptr){
    // Configurando o header do formato PPM
    fprintf(fptr, "P3\n %d \t %d\n 255\n", width, height);
    for (int i = 0; i < height; i++){ // Altura
      for (int j = 0; j < width; j++){ // Largura
        if (i == 0)
            fprintf(fptr, "255 \t 0 \t 0\n");
        if (j == 50)
            fprintf(fptr, "255 \t 0 \t 0\n");
        else
            fprintf(fptr, "0 \t 0 \t 0\n");
      }
    }
  }