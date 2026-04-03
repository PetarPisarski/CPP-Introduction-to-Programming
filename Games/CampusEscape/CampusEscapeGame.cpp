#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

#define HEIGHT_CONST 20
#define WIDTHT_CONST 35
#define MAX_INV 6
#define MAX_ENEMIES 7
#define HP_CAP 20
#define START_HP 14
#define START_ATK 3

char** createMap(int height, int widtht);
void destroyMap(char** map, int height);
bool inBounds(int r, int c, int height, int widtht);
bool isWalkable(char ch);
void fillRooms(char** map, int height, int widtht);
void randomEmptyCell(char** map, int height, int widtht, int* rr, int* cc);
void placeRandom(char** map, int height, int widtht, char ch);
void render(char** map, int height, int widtht, int pr, int pc, int php, int patk, int buffHits, int moves, const char* inv, int invSize, int enemiesAlive);
char readInput();
bool movePlayer(char** map, int height, int widtht, int* pr, int* pc, char dir, char* inventory, int* invSize, int* php, int patk, int* buffHits, int* enemiesR, int* enemiesC, int* enemiesHP, int* enemiesATK, bool* enemiesAlive, int enemyCount, bool* reachedExit);
void tryPickupItem(char** map, int r, int c, char* inventory, int* invSize);
void useItem(char* inventory, int* invSize, int slot, int* php, int* buffHits);
bool hasKey(const char* inventory, int invSize);
int enemyAt(int r, int c, int* enemiesR, int* enemiesC, bool* enemiesAlive, int n);
void resolveCombat(int* php, int patk, int* buffHits, int* ehp, int eatk);
void moveEnemies(char** map, int height, int widtht, int pr, int pc, int* enemiesR, int* enemiesC, int* enemiesHP, int* enemiesATK, bool* enemiesAlive, int enemyCount, int* php, int patk, int* buffHits);

int main() {
    srand(time(0));
    char** map = createMap(HEIGHT_CONST, WIDTHT_CONST);
    fillRooms(map, HEIGHT_CONST, WIDTHT_CONST);

    int pr, pc, php = START_HP, patk = START_ATK, buffHits = 0, moves = 0;
    char inventory[MAX_INV];
    int invSize = 0;

    randomEmptyCell(map, HEIGHT_CONST, WIDTHT_CONST, &pr, &pc);
    placeRandom(map, HEIGHT_CONST, WIDTHT_CONST, 'C');
    placeRandom(map, HEIGHT_CONST, WIDTHT_CONST, 'S');
    placeRandom(map, HEIGHT_CONST, WIDTHT_CONST, 'K');
    placeRandom(map, HEIGHT_CONST, WIDTHT_CONST, 'X');

    int er[MAX_ENEMIES], ec[MAX_ENEMIES], ehp[MAX_ENEMIES], eatk[MAX_ENEMIES];
    bool ealive[MAX_ENEMIES];

    // puskame gadovete
    for (int i = 0; i < MAX_ENEMIES; i++) {
        randomEmptyCell(map, HEIGHT_CONST, WIDTHT_CONST, &er[i], &ec[i]);
        ealive[i] = true;
        if (i % 2 == 0) {
            ehp[i] = 7;
            eatk[i] = 2;
        } else {
            ehp[i] = 10;
            eatk[i] = 3;
        }
    }

    bool win = false;

    while (php > 0) {
        int aliveCount = 0;
        for (int i = 0; i < MAX_ENEMIES; i++) {
            if (ealive[i]) {
                if (i % 2 == 0) {
                    map[er[i]][ec[i]] = 'D';
                } else {
                    map[er[i]][ec[i]] = 'E';
                }
                aliveCount++;
            }
        }

        render(map, HEIGHT_CONST, WIDTHT_CONST, pr, pc, php, patk, buffHits, moves, inventory, invSize, aliveCount);

        // triem vrragovete za da nqma smearing
        for (int i = 0; i < MAX_ENEMIES; i++) {
            if (ealive[i]) {
                map[er[i]][ec[i]] = '.';
            }
        }

        char input = readInput();
        if (input == 'q') {
            break;
        }

        if (input == 'u') {
            int slot;
            if (cin >> slot) {
                useItem(inventory, &invSize, slot - 1, &php, &buffHits);
            }
        } else {
            if (movePlayer(map, HEIGHT_CONST, WIDTHT_CONST, &pr, &pc, input, inventory, &invSize, &php, patk, &buffHits, er, ec, ehp, eatk, ealive, MAX_ENEMIES, &win)) {
                if (win) {
                    break;
                }
                moves++;
                // tuka gadovete murdat
                moveEnemies(map, HEIGHT_CONST, WIDTHT_CONST, pr, pc, er, ec, ehp, eatk, ealive, MAX_ENEMIES, &php, patk, &buffHits);
            }
        }
    }

    if (win) {
        cout << "WIN!" << endl;
    } else if (php <= 0) {
        cout << "GAME OVER!" << endl;
    }

    // chistim pametta
    destroyMap(map, HEIGHT_CONST);
    return 0;
}

char** createMap(int height, int widtht) {
    char** map = new char*[height];
    if (map == nullptr) {
        exit(1);
    }

    for (int i = 0; i < height; i++) {
        map[i] = new char[widtht];
        if (map[i] == nullptr) {
            for (int j = 0; j < i; j++) {
                delete[] map[j];
            }
            delete[] map;
            exit(1);
        }
        for (int j = 0; j < widtht; j++) {
            map[i][j] = '#';
        }
    }
    return map;
}

void destroyMap(char** map, int height) {
    if (map != nullptr) {
        for (int i = 0; i < height; i++) {
            if (map[i] != nullptr) {
                delete[] map[i];
            }
        }
        delete[] map;
    }
}

bool inBounds(int r, int c, int height, int widtht) {
    return (r >= 0 && r < height && c >= 0 && c < widtht);
}

bool isWalkable(char ch) {
    return (ch == '.' || ch == 'C' || ch == 'S' || ch == 'K' || ch == 'X');
}

void fillRooms(char** map, int height, int widtht) {
    for (int i = 1; i < height - 1; i++) {
        for (int j = 1; j < widtht - 1; j++) {
            if (rand() % 10 < 2) {
                map[i][j] = '#';
            } else {
                map[i][j] = '.';
            }
        }
    }
}

void randomEmptyCell(char** map, int height, int widtht, int* rr, int* cc) {
    do {
        *rr = rand() % height;
        *cc = rand() % widtht;
    } while (map[*rr][*cc] != '.');
}

void placeRandom(char** map, int height, int widtht, char ch) {
    int r, c;
    randomEmptyCell(map, height, widtht, &r, &c);
    map[r][c] = ch;
}

void render(char** map, int height, int widtht, int pr, int pc, int php, int patk, int buffHits, int moves, const char* inv, int invSize, int enemiesAlive) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < widtht; j++) {
            if (i == pr && j == pc) {
                cout << 'P';
            } else {
                cout << map[i][j];
            }
        }
        cout << endl;
    }
    cout << "HP: " << php << "/" << HP_CAP << " | ATK: " << patk << " | Buff: " << buffHits << endl;
    cout << "Moves: " << moves << " | Enemies: " << enemiesAlive << endl;
    cout << "Inv: ";
    for (int i = 0; i < invSize; i++) {
        cout << i + 1 << ":" << inv[i] << " ";
    }
    cout << endl;
}

char readInput() {
    char ch;
    cin >> ch;
    return ch;
}

bool movePlayer(char** map, int height, int widtht, int* pr, int* pc, char dir, char* inventory, int* invSize, int* php, int patk, int* buffHits, int* enemiesR, int* enemiesC, int* enemiesHP, int* enemiesATK, bool* enemiesAlive, int enemyCount, bool* reachedExit) {
    int nr = *pr;
    int nc = *pc;

    if (dir == 'w') nr--;
    else if (dir == 's') nr++;
    else if (dir == 'a') nc--;
    else if (dir == 'd') nc++;
    else return false;

    if (!inBounds(nr, nc, height, widtht)) return false;

    // proverka za boj
    int eIdx = enemyAt(nr, nc, enemiesR, enemiesC, enemiesAlive, enemyCount);
    if (eIdx != -1) {
        resolveCombat(php, patk, buffHits, &enemiesHP[eIdx], enemiesATK[eIdx]);
        if (enemiesHP[eIdx] <= 0) {
            enemiesAlive[eIdx] = false;
        }
        return true;
    }

    if (map[nr][nc] == 'X') {
        if (hasKey(inventory, *invSize)) {
            *reachedExit = true;
            return true;
        }
    }

    if (isWalkable(map[nr][nc])) {
        *pr = nr;
        *pc = nc;
        tryPickupItem(map, *pr, *pc, inventory, invSize);
        return true;
    }
    return false;
}

void tryPickupItem(char** map, int r, int c, char* inventory, int* invSize) {
    char ch = map[r][c];
    if (ch == 'C' || ch == 'S' || ch == 'K') {
        if (*invSize < MAX_INV) {
            inventory[*invSize] = ch;
            (*invSize)++;
            map[r][c] = '.';
        }
    }
}

void useItem(char* inventory, int* invSize, int slot, int* php, int* buffHits) {
    if (slot < 0 || slot >= *invSize) return;

    char item = inventory[slot];
    if (item == 'C') {
        *php = *php + 5;
        if (*php > HP_CAP) *php = HP_CAP;
    } else if (item == 'S') {
        *buffHits = *buffHits + 3;
    }

    if (item != 'K') {
        for (int i = slot; i < *invSize - 1; i++) {
            inventory[i] = inventory[i + 1];
        }
        (*invSize)--;
    }
}

bool hasKey(const char* inventory, int invSize) {
    for (int i = 0; i < invSize; i++) {
        if (inventory[i] == 'K') return true;
    }
    return false;
}

int enemyAt(int r, int c, int* enemiesR, int* enemiesC, bool* enemiesAlive, int n) {
    for (int i = 0; i < n; i++) {
        if (enemiesAlive[i] && enemiesR[i] == r && enemiesC[i] == c) {
            return i;
        }
    }
    return -1;
}

void resolveCombat(int* php, int patk, int* buffHits, int* ehp, int eatk) {
    while (*php > 0 && *ehp > 0) {
        int curAtk = patk;
        if (*buffHits > 0) {
            curAtk += 2;
            (*buffHits)--;
        }
        *ehp -= curAtk;
        if (*ehp <= 0) break;
        *php -= eatk;
    }
}

void moveEnemies(char** map, int height, int widtht, int pr, int pc, int* enemiesR, int* enemiesC, int* enemiesHP, int* enemiesATK, bool* enemiesAlive, int enemyCount, int* php, int patk, int* buffHits) {
    for (int i = 0; i < enemyCount; i++) {
        if (enemiesAlive[i]) {
            int dr = pr - enemiesR[i];
            int dc = pc - enemiesC[i];
            int adr = (dr < 0) ? -dr : dr;
            int adc = (dc < 0) ? -dc : dc;
            int nr = enemiesR[i];
            int nc = enemiesC[i];

            if (adr + adc <= 5) {
                if (adr >= adc) {
                    if (dr > 0) nr++; else nr--;
                } else {
                    if (dc > 0) nc++; else nc--;
                }
            } else {
                int dir = rand() % 4;
                if (dir == 0) nr--;
                else if (dir == 1) nr++;
                else if (dir == 2) nc--;
                else nc++;
            }

            if (nr == pr && nc == pc) {
                resolveCombat(php, patk, buffHits, &enemiesHP[i], enemiesATK[i]);
                if (enemiesHP[i] <= 0) enemiesAlive[i] = false;
            } else if (inBounds(nr, nc, height, widtht) && map[nr][nc] == '.' && enemyAt(nr, nc, enemiesR, enemiesC, enemiesAlive, enemyCount) == -1) {
                enemiesR[i] = nr;
                enemiesC[i] = nc;
            }
        }
    }
}
