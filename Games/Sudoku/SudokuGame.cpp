#include <iostream>
#include <ctime>

using std::cin, std::cout, std::endl;

int board[9][9];
int initialBoard[9][9];
int solvedBoard[9][9];

bool isValid(int rows, int cols, int num);
bool fillBoard();
void printBoard(const int grid[9][9]);
bool isSudokuWon();
void setDifficulty();

int main() {
    srand(time(0));

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            board[i][j] = 0;
        }
    }

    fillBoard();

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            solvedBoard[i][j] = board[i][j];
        }
    }

    //DIFICULTY

    setDifficulty();

    //save initialBoard

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            initialBoard[i][j] = board[i][j];
        }
    }

    int rows,cols,number;

    bool flag = true;
    while (flag) {
        printBoard(board);
        cout << "Please enter your Input like: ROW(1-9) COL(1-9) NUM(1-9) or 0 0 0 to solve and exit\n";

        if (!(cin >> rows >> cols >> number)) {
            cout << "Invalid input\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        cin.ignore(10000, '\n');

        if (rows == 0 && cols == 0 && number == 0) {
            printBoard(solvedBoard);
            flag = false;
            break;
        }
        if (rows < 1 || rows > 9 || cols < 1 || cols > 9 || number < 1 || number > 9) {
            cout << "Invalid input\n";
            continue;
        }
        if (initialBoard[rows - 1][cols - 1] != 0) {
            cout << "Can't change initial numbers!!!\n";
            continue;
        }


        board[rows - 1][cols - 1] = number;

        if (isSudokuWon()) {
            printBoard(board);
            cout << "GG WP smart boi!\n";
            flag = false;
        }
    }

    return 0;
}

bool isValid(int rows, int cols, int num) {
    // checks rows and cols if the number is already there
    for (int i = 0; i < 9; i++) {
        if (board[rows][i] == num || board[i][cols] == num) {
            return false;
        }
    }
    // checks small squares 3x3
    int startRow = rows - rows %3;
    int startCol = cols - cols % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i + startRow][j + startCol] == num) {
                return false;
            }
        }

    }
    return true;
}

bool fillBoard() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == 0) { //find open square
                for (int n = 1; n <= 9; n++) {
                    int number = (rand() % 9) +1; //"random" number
                    if (isValid(i, j, number)) {
                        board[i][j] = number;
                        if (fillBoard()) { //continue if not filled
                            return true;
                        }
                        board[i][j] = 0; // if something fucked up leave it at 0
                    }
                }
                return false; // flag to stop the recursion if filled
            }
        }
    }
    return true; //gg
}

void printBoard(const int grid[9][9]) {
    cout << "    1 2 3   4 5 6   7 8 9\n";
    cout << "  -------------------------\n";

    for (int i = 0; i < 9; i++) {
        if (i > 0 && i % 3 == 0) {
            cout << "  |-------+-------+-------|\n";
        }

        cout << i + 1 << " | ";

        for (int j = 0; j < 9; j++) {
            if (j > 0 && j % 3 == 0) {
                cout << "| ";
            }

            if (grid[i][j] == 0) {
                cout << ". ";
            }
            else {
                cout << grid[i][j] << " ";
            }
        }
        cout << "|\n";
    }
    cout << "  -------------------------\n";
}

bool isSudokuWon() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            int currentNumber = board[i][j];

            if (currentNumber == 0) {
                return false;
            }
            board[i][j] = 0; // temporaly remove the number to check for the others
            if (!isValid(i, j, currentNumber)) {
                board[i][j] = currentNumber; // restore before failing
                return false;
            }
            board[i][j] = currentNumber; // comes back
        }
    }
    return true;
}

void setDifficulty() {
    int emptyCells = 0;
    cout << "=============================\n";
    cout << "      SUDOKU SETUP       \n";
    cout << "=============================\n";
    cout << "Please set the dificulty of your game: (how many squares to fill)";
    cin >> emptyCells;

    if (emptyCells < 1) {
        emptyCells = 1;
    }
    if (emptyCells > 64) {
        emptyCells = 64;
    }

    int removed = 0;
    while (removed < emptyCells) {
        int rows = rand() % 9;
        int cols = rand() % 9;

        if (board[rows][cols] != 0) {
            board[rows][cols] = 0;
            removed++;
        }
    }
}