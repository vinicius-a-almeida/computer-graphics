#include <stdio.h>

#define h 256
#define w 256

unsigned char img[h][w][3];

void setPixel(int x, int y, unsigned char r, unsigned char g, unsigned char b) {
    img[x][y][0] = r;
    img[x][y][1] = g;
    img[x][y][2] = b;
}

void clear(){
    for(int i = 0; i < h; i++)
        for(int j = 0; j < w; j++)
            for(int c = 0; c < 3; c++)
                img[i][j][c] = 0;
}

void saveimg() {
    //FILE *f = fopen("output.ppm", "w");
    printf("P3\n%d %d\n255\n", w, h);

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            printf("%d %d %d ", img[i][j][0], img[i][j][1], img[i][j][2]);
        }
        printf("\n");
    }

    //fclose(f);
}

void drawLine(int x1, int y1, int x2, int y2, unsigned char r, unsigned char g, unsigned char b){
    for(float t = 0.0; t < 1; t = t + 0.0001){
        setPixel( (int) (x2 - x1)*t + x1, (int) (y2 - y1)*t + y1, r, g, b );
    }
}

int main(){

    clear();
    // setPixel(230, 120, 30, 200, 110);
    drawLine(128,   64,     250,    64,     220, 0, 0); 
    //       y      x       y       x       R   G   B
    drawLine(128,   192,    250,    192,    220, 0, 0);
    //       y      x       y       x       R   G   B
    drawLine(250,   64,    250,    193,    220, 0, 0);
    drawLine(128,   44,    128,    64,    220, 0, 0);
    drawLine(128,   192,    128,    212,    220, 0, 0);
    drawLine(128,   44,    64,    128,    220, 0, 0);
    drawLine(64,   128,    128,    212,    220, 0, 0);
    drawLine(128,   44,    128,    192,    220, 0, 0);


    saveimg();

    return 0;
}