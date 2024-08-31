/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

    //Инициализация поля
    void initializeBoard(char board[][3],int SIZE){
        for(int i = 0; i < SIZE; i++){
            for(int j = 0; j < SIZE; j++){
                board[i][j] = ' ';
            }
        }
    }
   void printBoard(char board[][3], int SIZE) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            std::cout << " " << board[i][j];
            if (j < SIZE - 1) std::cout << " |";
        }
        std::cout << std::endl;
        if (i < SIZE - 1) std::cout << "---|---|---" << std::endl;
    }
}
    
    bool checkWin(char board[][3],int SIZE,char player) {
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}
    
    bool checkDraw(char board[][3],int SIZE) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') return false;
        }
    }
    return true;
}

int main()
{
    const int SIZE = 3;
    char board[SIZE][SIZE];
    
    char currentPlayer = 'X';
    int row, col;
    bool gameWon = false;

    initializeBoard(board, SIZE);
    std::cout << "Добро пожаловать в игру Крестики-Нолики!" << std::endl;

    while (!gameWon && !checkDraw(board, SIZE)) {
        printBoard(board, SIZE);
        std::cout << "Игрок " << currentPlayer << ", введите номер строки и столбца (0, 1 или 2): ";
        std::cin >> row >> col;
        if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ') {
            board[row][col] = currentPlayer;
            if (checkWin(board, SIZE, currentPlayer)) {
                gameWon = true;
                printBoard(board, SIZE);
                std::cout << "Поздравляем! Игрок " << currentPlayer << " победил!" << std::endl;
            } else if (checkDraw(board, SIZE)) {
                printBoard(board, SIZE);
                std::cout << "Ничья!" << std::endl;
            } else {
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        } else {
            std::cout << "Неверный ход. Попробуйте снова." << std::endl;
        }
    }
    

    return 0;
}