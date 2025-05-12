#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define ALTURA 256
#define LARGURA 256
#define PI 3.14159265f

// Primeiro definimos a estrutura Vertex
typedef struct {
    float x;
    float y;
    float z;
} Vertex;

// Depois declaramos os protótipos que usam Vertex
void reflect(Vertex *vertices, int vcount, char axis);
void translation(Vertex *vertices, int vcount, float tx, float ty, float tz);
void scale(Vertex *vertices, int vcount, float sx, float sy, float sz);
void rotation(Vertex *vertices, int vcount, float rx, float ry, float rz);
void shear(Vertex *vertices, int vcount, float shx, float shy, float shz);

typedef struct {
    unsigned char r, g, b;
} Pixel;

Pixel imagem[ALTURA][LARGURA];

void inicializar_imagem() {
    printf("P3\n%d %d\n255\n", LARGURA, ALTURA);
    for (int y = 0; y < ALTURA; y++) {
        for (int x = 0; x < LARGURA; x++) {
            imagem[y][x] = (Pixel){0, 0, 0};
        }
    }
}

void alterar_pixel(int x, int y, unsigned char r, unsigned char g, unsigned char b) {
    if (x >= 0 && x < LARGURA && y >= 0 && y < ALTURA) {
        imagem[y][x] = (Pixel){r, g, b};
    }
}

void imprimir_imagem() {
    for (int y = 0; y < ALTURA; y++) {
        for (int x = 0; x < LARGURA; x++) {
            printf("%d %d %d\n", imagem[y][x].r, imagem[y][x].g, imagem[y][x].b);
        }
    }
}

void desenhar_linha(int x1, int y1, int x2, int y2, Pixel cor) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (1) {
        alterar_pixel(x1, y1, cor.r, cor.g, cor.b);
        
        if (x1 == x2 && y1 == y2) break;
        
        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}

void desenhar_casa() {
    Pixel cor_casa = {200, 200, 0};
    Pixel cor_porta = {139, 69, 19};
    Pixel cor_telhado = {150, 0, 0};

    Vertex pontos[] = {
        {64, 128, 0}, {128, 64, 0}, {192, 128, 0},
        {64, 128, 0}, {64, 200, 0}, {192, 200, 0},
        {192, 128, 0}, {100, 200, 0}, {100, 150, 0},
        {156, 150, 0}, {156, 200, 0}
    };
    
    rotation(pontos, 10, 0, 0, PI/6);
    scale(pontos, 10, 0.8, 0.8, 1);
    
    desenhar_linha(pontos[0].x, pontos[0].y, pontos[1].x, pontos[1].y, cor_telhado);
    desenhar_linha(pontos[1].x, pontos[1].y, pontos[2].x, pontos[2].y, cor_telhado);
    
    desenhar_linha(pontos[3].x, pontos[3].y, pontos[4].x, pontos[4].y, cor_casa);
    desenhar_linha(pontos[4].x, pontos[4].y, pontos[5].x, pontos[5].y, cor_casa);
    desenhar_linha(pontos[5].x, pontos[5].y, pontos[6].x, pontos[6].y, cor_casa);
   
    desenhar_linha(pontos[7].x, pontos[7].y, pontos[8].x, pontos[8].y, cor_porta);
    desenhar_linha(pontos[8].x, pontos[8].y, pontos[9].x, pontos[9].y, cor_porta);
    desenhar_linha(pontos[9].x, pontos[9].y, pontos[10].x, pontos[10].y, cor_porta);
    desenhar_linha(pontos[10].x, pontos[10].y, pontos[7].x, pontos[7].y, cor_porta);
    
    alterar_pixel(150, 175, 255, 0, 0);
}

void reflect(Vertex *vertices, int vcount, char axis) {
    for (int i = 0; i < vcount; i++) {
        switch(axis) {
            case 'x': vertices[i].x = -vertices[i].x; break;
            case 'y': vertices[i].y = -vertices[i].y; break;
            case 'z': vertices[i].z = -vertices[i].z; break;
            default: break;
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

void rotation(Vertex *vertices, int vcount, float rx, float ry, float rz) {
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
        
        // Rotação em X
        float y1 = y * cosX - z * sinX;
        float z1 = y * sinX + z * cosX;
        
        // Rotação em Y
        float x2 = x * cosY + z1 * sinY;
        float z2 = -x * sinY + z1 * cosY;
        
        // Rotação em Z
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

int main() {
    inicializar_imagem();
    desenhar_casa();
    imprimir_imagem();
    return 0;
}