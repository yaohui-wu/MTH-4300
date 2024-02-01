#include <iostream>
#include <string>

class TTTBoard
{
private:
    char board[3][3];

public:
    TTTBoard();
    void display() const;
    bool occupied(int, int) const;
    bool set(int, int, char);
    bool win_for(char) const;
};

/*
Initialize an empty tic-tac-toe game board.
*/
TTTBoard::TTTBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
}

/*
Print a visual display of the tic-tac-toe game.
*/
void TTTBoard::display() const
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            std::cout << " " << board[i][j] << " |";
        }
        
        std::cout << " " << board[i][2] << std::endl;

        for (int k = 0; k < 11; k++)
        {
            std::cout << "-";
        }
        
        std::cout << std::endl;
    }

    for (int i = 0; i < 2; i++)
    {
        std::cout << " " << board[2][i] << " |";
    }
    
    std::cout << " " << board[2][2] << " " << std::endl;
}

/*
Return true if the entry at row i and column j contains an x or an o,
return false otherwise.
*/
bool TTTBoard::occupied(int i, int j) const
{
    return board[i][j] == 'x' || board[i][j] == 'o';
}

/*
Return true if board[i][j] is empty and set p, which is either x or o,
to the entry. Return false if board[i][j] is not empty and do nothing.
*/
bool TTTBoard::set(int i, int j, char p)
{
    if (!occupied(i, j))
    {
        board[i][j] = p;

        return true;
    }
    
    return false;
}

/*
Return true if the player has won the game, else return false.The player who
succeeds in placing three of the same entries in a horizontal, vertical, or
diagonal row is the winner.
*/
bool TTTBoard::win_for(char p) const
{
    // Horizontal win.
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == p && board[i][1] == p && board[i][2] == p)
        {
            return true;
        }
    }

    // Vertical win.
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == p && board[1][i] == p && board[2][i] == p)
        {
            return true;
        }
    }
    
    // Diagonal win.
    if (board[0][0] == p && board[1][1] == p && board[2][2] == p
        || board[0][2] == p && board[1][1] && board[2][0] == p)
    {
        return true;
    }
    
    return false;
}

// Tests below
void test1()
{
    std::cout << "Test 1: " << std::endl;
    TTTBoard myboard;
    myboard.display();
    std::cout << "If the above looks like an empty board, then test 1 is passed" << std::endl;
}

void test2()
{
    std::cout << "Test 2: " << std::endl;
    TTTBoard myboard;
    myboard.set(0, 0, 'x');
    myboard.set(0, 1, 'x');
    myboard.set(0, 2, 'x');
    myboard.set(1, 0, 'o');
    myboard.set(1, 0, 'o');
    myboard.display();
    std::cout << "You should see a row of three x's followed by a row with one o." << std::endl;
}

void test3()
{
    std::cout << "Test 3: " << std::endl;
    TTTBoard myboard;
    myboard.set(0, 0, 'x');
    myboard.set(0, 1, 'x');
    myboard.set(0, 2, 'x');
    myboard.set(1, 0, 'o');
    myboard.set(1, 0, 'o');
    std::cout << "Test 3a: you should see 10: " << myboard.win_for('x') << myboard.win_for('o') << std::endl;
    TTTBoard myboard2;
    myboard2.set(2, 0, 'o');
    myboard2.set(1, 1, 'o');
    myboard2.set(0, 2, 'o');
    myboard2.set(1, 0, 'x');
    myboard2.set(2, 2, 'x');
    std::cout << "Test 3b: you should see 01: " << myboard2.win_for('x') << myboard2.win_for('o') << std::endl;
}
// End tests

/*
Run a tic-tac-toe game.
*/
void tic_tac_toe()
{
    TTTBoard ttk;

    for (int n = 1; n <= 9; n++)
    {
        char p; // Player x or player o.

        // Player x takes odd turns and player o takes even turns.
        if (n % 2 == 1)
        {
            p = 'x';
        }
        else
        {
            p = 'o';
        }
        
        int i, j;

        do
        {
        std::cout << "Enter the row: ";
        std::cin >> i;
        std::cout << "Enter the column: ";
        std::cin >> j;
        } while (ttk.occupied(i, j));

        ttk.set(i, j, p);
        ttk.display();

        if (ttk.win_for(p))
        {
            std::cout << "Player " << p << " won the game!" << std::endl;

            return;
        }
    }

    std::cout << "The game is tied!" << std::endl;
}

int main()
{
    test1();   // UNCOVER THIS TEST AFTER THE CONSTRUCTOR AND DISPLAY ARE IMPLEMENTED
    test2();  // UNCOVER THIS TEST AFTER OCCUPIED AND SET ARE IMPLEMENTED
    test3();  // UNCOVER THIS TEST AFTER WIN_FOR IS IMPLEMENTED.

    tic_tac_toe();

    return 0;
}