#include <stdio.h>


int main(){

  // dimensoes da imagem
  int width = 256;
  int height = 256;

  // Configurando o header do formato PPM
  

  int x, y;

  scanf("%d %d", &x, &y);

  FILE* fptr;

  fptr = fopen("img.ppm", "rw+");
  if (fptr == NULL) {
    printf("Error opening file, please check if the file exists and if has the name 'img.ppm'\n");
    return 1;
  }
  fprintf(fptr, "P3\n %d \t %d\n 255\n", width, height);
  for (int i = 0; i < height; i++){ // Altura
    for (int j = 0; j < width; j++){ // Largura
      if(i == x && j == y){
        fprintf(fptr, "255 \t 0 \t 0\n"); // vermelho
      } else {
        fprintf(fptr, "0 \t 0 \t 0\n"); // preto
      }
    }
  }
  fclose(fptr);
  return 0;
}
