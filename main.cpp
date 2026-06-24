#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

// For alphabetical order
string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

// Bots that populate world
class Agent
{
    public:

};

// Subset of a region
class Area
{
    public:
        int food = 0;
        vector<int> agents;
        bool hasBeenSelected = false;
};

// Subset of a board
class Region
{
    private:
        void clean_up_areas()
        {
            for (int i = 0; i < AREA_Y; i++)
            {
                for (int j = 0; j < AREA_X; j++)
                {
                    areas[i][j].hasBeenSelected = false;
                }
            }
        }
    public:
        const int AREA_X = 4;
        const int AREA_Y = 4;
        const double DROUGHT_RATIO = .5;
        vector<vector<Area>> areas;

        // Initialize Board
        Region() : areas(AREA_X, vector<Area>(AREA_Y)) {}

        // Spawns food at start of day
        void display_food_condition()
        {
            for (int i = 0; i < AREA_Y; i++)
            {
                for (int j = 0; j < AREA_X; j++)
                {
                    cout << areas[i][j].food;
                    if (j != AREA_X-1) cout << "--";
                }
                if (i != AREA_Y-1)
                {
                    cout << endl;
                    for (int j = 0; j < AREA_X; j++)
                    {
                        cout << "|";
                        if (j != AREA_X-1) cout << "  ";
                    }
                    cout << endl;
                }
            }
            cout << endl;
        }
        void delete_food()
        {
            for (int i = 0; i < AREA_Y; i++)
            {
                for (int j = 0; j < AREA_X; j++)
                {
                    areas[i][j].food = 0;
                }
            }
        }
        void spawn_food()
        {
            for (int i = 0; i < (AREA_X*AREA_Y)*DROUGHT_RATIO; i++)
            {
                int randomCord[2] = {rand() % AREA_X, rand() % AREA_Y};
                if (areas[randomCord[0]][randomCord[1]].hasBeenSelected)
                {
                    i--;
                    continue;
                }
                else
                {
                    areas[randomCord[0]][randomCord[1]].hasBeenSelected = true;
                }
            }
            for (int i = 0; i < AREA_X*AREA_Y; i++)
            {
                int randomCord[2] = {rand() % AREA_X, rand() % AREA_Y};
                if (areas[randomCord[0]][randomCord[1]].hasBeenSelected) i--;
                else
                {
                    areas[randomCord[0]][randomCord[1]].food++;
                }
            }
            clean_up_areas();
        }
};

class Sim
{
    public:
        const int REGION_X = 4;
        const int REGION_Y = 4;
        vector<vector<Region>> regions;

        // Initialize Board
        Sim() : regions(REGION_X, vector<Region>(REGION_Y)) {}

        // Output board
        void output()
        {
            for (int i = 0; i < REGION_Y; i++)
            {
                for (int j = 0; j < REGION_X; j++)
                {
                    cout << alphabet[i*REGION_X+j];
                    if (j != REGION_X-1) cout << "--";
                }
                if (i != REGION_Y-1)
                {
                    cout << endl;
                    for (int j = 0; j < REGION_X; j++)
                    {
                        cout << "|";
                        if (j != REGION_X-1) cout << "  ";
                    }
                    cout << endl;
                }
            }
            cout << endl;
        }

        void day()
        {
            for (int i = 0; i < REGION_Y; i++)
            {
                for (int j = 0; j < REGION_X; j++)
                {
                    regions[i][j].delete_food();
                    regions[i][j].spawn_food();
                    regions[i][j].display_food_condition();
                }
            }
        }
};

int main()
{
    srand(time(NULL));
    // Make simulation
    Sim simulation;
    simulation.output();
    simulation.day();
    return 0;
}