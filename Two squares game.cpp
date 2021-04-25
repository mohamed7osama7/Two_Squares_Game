#include <iostream>
#include <random>
using namespace std;
const int N = 4;
int score[2] = { 0, 0 };
char grid[N][N];

void print_grid() {
    for (int i = 0; i < ((N + 4) * N + 1); cout << "-", i++);
    cout << "\n";
    for (int i = 0; i < N; i++) {
        cout << "|";
        for (int j = 0; j < N; j++) {
            string e = "";
            for (int t = 0; t < 3; e += " ", t++);
            e += (grid[i][j]);
            for (int t = 0; t < 3; e += " ", t++);
            cout << e << "|";
        }
        cout << "\n";
        for (int t = 0; t < ((N + 4) * N + 1); cout << "-", t++);
        cout << "\n";
    }
}


bool check_full_grid()
{
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N-1; j++)
        {
            if (grid[i][j] == '.' && grid[i][j + 1] == '.')
            return false;
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N-1; j++)
        {
            if (grid[j][i] == '.' && grid[j+1][i] == '.')
            return false;
        }
    }
    
    return true;


}


bool is_valid_position(int i, int j, int k, int l)
{
    if (0 > i || i > 3)
        return false;
    if (0 > j || j > 3)
        return false;
    if (0 > k || k > 3)
        return false;
    if (0 > l || l > 3)
        return false;
    if (grid[i][j] == 'X' || grid[k][l] == 'X')
        return false;
    if (k != i && k != i - 1 && k != i + 1)
        return false;
    if (l != j && l != j - 1 && l != j + 1)
        return false;
    if (i == k && j == l)
        return false;
    if (i != k && j != l)
        return false;
    return true;

}


void set_cell(int i, int j, int k, int l)
{
    grid[i][j] = 'X';
    grid[k][l] = 'X';
}


bool check_win()
{
    if (check_full_grid())
        return true;
    else
        return false;

}

void clear_grid()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            grid[i][j] = '.';
        }
    }
}

void play_game()
{
    cout << "memory Game!" << endl;
    cout << "Welcome..." << endl;
    cout << "============================" << endl;
    int player = 0;

    while (true)
    {
        cout << "player " << player << " turn" << endl;
        print_grid();
        int i = 0; int j = 0; int k = 0; int l = 0;

        cout << "Enter the row index and column index for the first cell: ";
        cin >> i >> j;
        cout << "Enter the row index and column index for the second cell: ";
        cin >> k >> l;
        cout << "\n";

        while (not is_valid_position(i, j, k, l))
        {
            cout << ("enter valid cells") << endl;
            cout << "Enter the row index and column index for the first cell: ";
            cin >> i >> j;
            cout << "Enter the row index and column index for the second cell: ";
            cin >> k >> l;
            cout << "\n";

        }
        set_cell(i, j, k, l);

        if (check_win())
        {
            cout << "player " << player << " won" << endl;
            print_grid();
            break;
        }

        player = 1 - player;
    }



}



int main()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            grid[i][j] = '.';

        }
    }

    while (true)
    {
        clear_grid();
        play_game();
        char c;
        cout << "Play Again ? [Y/N] ";
        cin >> c;
        if (c != 'y' && c != 'Y')
            break;
    }
}

