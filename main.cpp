#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>
using namespace std;

const int H = 15, W = 25;
char lab[H][W+1];
int rx = 1, ry = 1;
int gx, gy;
int steps = 0;

void makeLab() {
    srand(time(0));
    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
            if (y == 0 || y == H-1 || x == 0 || x == W-1)
                lab[y][x] = '#';
            else
                lab[y][x] = (rand() % 4 == 0 ? '#' : '.');
        }
        lab[y][W] = '\0';
    }
    lab[ry][rx] = 'R';
    gx = W - 2;
    gy = H - 2;
    lab[gy][gx] = 'X';
}

void showLab() {
    system("cls");
    for (int i = 0; i < H; i++) cout << lab[i] << "\n";
    cout << "Steps: " << steps << "\n";
}

void moveR(int dx, int dy) {
    int nx = rx + dx, ny = ry + dy;
    if (lab[ny][nx] == '#') return;
    steps++;
    lab[ry][rx] = '.';
    rx = nx; ry = ny;
    if (rx == gx && ry == gy) {
        lab[ry][rx] = 'R';
        showLab();
        cout << "You win in " << steps << " steps!\n";
        system("pause");
        exit(0);
    }
    lab[ry][rx] = 'R';
}

int main() {
    makeLab();
    while (true) {
        showLab();
        char k = _getch();
        if (k == 'w') moveR(0, -1);
        if (k == 's') moveR(0, 1);
        if (k == 'a') moveR(-1, 0);
        if (k == 'd') moveR(1, 0);
    }
}
