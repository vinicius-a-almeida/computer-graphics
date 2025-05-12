/**
 * \file model.c
 *
 * \brief Implementação das funções de manipulação do modelo 3D.
 *
 * \author
 * Petrucio Ricardo Tavares de Medeiros \n
 * Universidade Federal Rural do Semi-Árido \n
 * Departamento de Engenharias e Tecnologia \n
 * petrucio at ufersa (dot) edu (dot) br
 *
 * \version 1.0
 * \date May 2025
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <math.h>
 #include "model.h"
 
 unsigned char image[HEIGHT][WIDTH][3];  // Definition moved here
 
 void set_pixel(int x, int y, unsigned char r, unsigned char g, unsigned char b) {
   if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
     image[y][x][0] = r;
     image[y][x][1] = g;
     image[y][x][2] = b;
   }
 }
 
 void draw_line(int x0, int y0, int x1, int y1) {
   for (float t = 0.0; t < 1.0; t = t + 0.0001)
     set_pixel((int)x0+(x1-x0)*t, (int)y0+(y1-y0)*t, 0, 0, 0);
 }
 
 void clr() {
   for (int y = 0; y < HEIGHT; y++) {
     for (int x = 0; x < WIDTH; x++) {
       for (int c = 0; c < 3; c++) {
         image[y][x][c] = 255;
       }
     }
   }
 }
 
 void save() {
   printf("P3\n %d \t %d\n 255\n", WIDTH, HEIGHT);
   for (int y = 0; y < HEIGHT; y++) {
     for (int x = 0; x < WIDTH; x++) {
       for (int c = 0; c < 3; c++) {
         printf("%d \t", image[y][x][c]);
       }
       printf("\n");
     }
   }
 }
 
 /* Rest of the file remains unchanged */
 int load_obj(const char *filename, Vertex *vertices, int *vcount, Face *faces,
              int *fcount) {
     FILE *file = fopen(filename, "r");
     if (!file) {
         perror("Erro ao abrir o arquivo");
         return 0;
     }
 
     char line[512];
     *vcount = 0;
     *fcount = 0;
 
     while (fgets(line, sizeof(line), file)) {
         if (strncmp(line, "v ", 2) == 0) {
             if (sscanf(line + 2, "%f %f %f", &vertices[*vcount].x,
                        &vertices[*vcount].y, &vertices[*vcount].z) == 3) {
                 (*vcount)++;
             }
         } else if (strncmp(line, "f ", 2) == 0) {
             Face face = {.n = 0};
             char *token = strtok(line + 2, " \n");
             while (token && face.n < MAX_FACE_VERTS) {
                 int index;
                 if (sscanf(token, "%d", &index) == 1) {
                     face.verts[face.n++] = index;
                 }
                 token = strtok(NULL, " \n");
             }
             faces[(*fcount)++] = face;
         }
     }
 
     fclose(file);
     return 1;
 }
 
 void resizing(Vertex v0, Vertex v1) {
   int x0 = (int)((v0.x + 1.0f) * WIDTH / 2.0f);
   int y0 = (int)((1.0f - v0.y) * HEIGHT / 2.0f);
   int x1 = (int)((v1.x + 1.0f) * WIDTH / 2.0f);
   int y1 = (int)((1.0f - v1.y) * HEIGHT / 2.0f);
 
   draw_line(x0, y0, x1, y1);
 }
 
 void render_faces(Vertex *vertices, Face *faces, int vcount, int fcount) {
     for (int i = 0; i < fcount; i++) {
         Face face = faces[i];
         for (int j = 0; j < face.n; j++) {
             Vertex v0 = vertices[face.verts[j] - 1];
             Vertex v1 = vertices[face.verts[(j + 1) % face.n] - 1];
             resizing(v0, v1);
         }
     }
 }

 void reflect(Vertex *vertices, int vcount, int axis) {
  for (int i = 0; i < vcount; i++) {
      switch(axis) {
          case 'x': 
              vertices[i].x = -vertices[i].x;
              break;
          case 'y': 
              vertices[i].y = -vertices[i].y;
              break;
          case 'z': 
              vertices[i].z = -vertices[i].z;
              break;
          default: 
              break;
      }
  }
}

  void translation(Vertex *vertices, int vcount, float tx, float ty, float tz) {
    for (int i = 0; i < vcount; i++) {
      vertices[i].x += tx;
      vertices[i].y += ty;
      vertices[i].z += tz;
    }
  }

  void scale(Vertex *vertices, int vcount, float sx, float sy, float sz) {
    for (int i = 0; i < vcount; i++) {
      vertices[i].x *= sx;
      vertices[i].y *= sy;
      vertices[i].z *= sz;
    }
  }

  void rotation(Vertex *vertices, int vcount, float rx, float ry, float rz){
    float cosX = cosf(rx);
    float sinX = sinf(rx);
    float cosY = cosf(ry);
    float sinY = sinf(ry);
    float cosZ = cosf(rz);
    float sinZ = sinf(rz);
    
    for (int i = 0; i < vcount; i++) {
        float x = vertices[i].x;
        float y = vertices[i].y;
        float z = vertices[i].z;
        
        // Rotação em torno do eixo X
        float y1 = y * cosX - z * sinX;
        float z1 = y * sinX + z * cosX;
        
        // Rotação em torno do eixo Y
        float x2 = x * cosY + z1 * sinY;
        float z2 = -x * sinY + z1 * cosY;
        
        // Rotação em torno do eixo Z
        float x3 = x2 * cosZ - y1 * sinZ;
        float y3 = x2 * sinZ + y1 * cosZ;
        
        vertices[i].x = x3;
        vertices[i].y = y3;
        vertices[i].z = z2;
    }
  }


  void shear(Vertex *vertices, int vcount, float shx, float shy, float shz) {
    for (int i = 0; i < vcount; i++) {
        float x = vertices[i].x;
        float y = vertices[i].y;
        float z = vertices[i].z;
        
        vertices[i].x = x + shy * y + shz * z;
      
        vertices[i].y = y + shx * x + shz * z;

        vertices[i].z = z + shx * x + shy * y;
    }
}