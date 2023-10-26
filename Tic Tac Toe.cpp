#include <iostream>
using namespace std;

// Global variables
char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char turn = 'X'; // Initialize to 'X'
int row, column;
char choice;

// Function to display the Tic-Tac-Toe board
void display_board() {
    system("clear"); // For Linux/macOS. Use "cls" for Windows
    cout << "  " << board[0][0] << " |  " << board[0][1] << "  |  " << board[0][2] << "\n";
    cout << "___|_____|___\n";
    cout << "  " << board[1][0] << " |  " << board[1][1] << "  |  " << board[1][2] << "\n";
    cout << "___|_____|___\n";
    cout << "  " << board[2][0] << " |  " << board[2][1] << "  |  " << board[2][2] << "\n";
    cout << "   |     |   \n";
}

// Function to check the game's status
bool check_win() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return true; // Check rows
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return true; // Check columns
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return true; // Check diagonal (top-left to bottom-right)
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return true; // Check diagonal (top-right to bottom-left)
    }
    return false;
}

// Function to check if the game ends in a draw
bool check_draw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false; // The game is still ongoing
            }
        }
    }
    return true; // All positions are filled, indicating a draw
}

// Function for a player's turn
void player_turn() {
    int digit;

    cout << "Player " << turn << ", please enter a position (1-9): ";
    cin >> choice;

    // Check if the input is a digit
    if (isdigit(choice)) {
        digit = choice - '0'; // Convert char to integer
    } else {
        cout << "Invalid input. Please enter a digit between 1 and 9." << endl;
        return; // Restart the player's turn
    }

    if (digit >= 1 && digit <= 9) {
        // Map the choice to row and column
        row = (digit - 1) / 3;
        column = (digit - 1) % 3;

        if (board[row][column] == 'X' || board[row][column] == 'O') {
            cout << "Box already filled! Please choose another position." << endl;
        } else {
            board[row][column] = turn;
            turn = (turn == 'X') ? 'O' : 'X'; // Switch turns
        }
    } else {
        cout << "Invalid input. Please enter a digit between 1 and 9." << endl;
    }
}

int main() {
    display_board();

    while (true) {
        player_turn();
        display_board();

        if (check_win()) {
            cout << "Player " << ((turn == 'X') ? 'O' : 'X') << " wins!" << endl;
            break;
        } else if (check_draw()) {
            cout << "It's a draw!" << endl;
            break;
        }
    }

    return 0;
}
 
 
 