#include <iostream>
#include <vector>
using namespace std;

class Sim
{
    public:
        const int BOARD_X = 4;
        const int BOARD_Y = 4;
        vector<vector<int>> board;

        Sim()
        {
            for (int i = 0; i < BOARD_X; i++)
            {
                vector<int> row;
                for (int j = 0; j < BOARD_Y; j++)
                {
                    row.push_back(0);
                }
                board.push_back(row);
            }
        }
};

int main()
{
    Sim simulation;
    cout << simulation.board[0].size();
}