#include <iostream>
#include <vector>
using namespace std;

string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
class Agent
{

};

class Area
{
    int food = 0;
    vector<int> agents;
};

class Region
{
    public:
        const int AREA_X = 4;
        const int AREA_Y = 4;
        vector<vector<Area>> areas;

        Region() : areas(AREA_X, vector<Area>(AREA_Y)) {}
};

class Sim
{
    public:
        const int REGION_X = 4;
        const int REGION_Y = 4;
        vector<vector<Region>> regions;

        Sim() : regions(REGION_X, vector<Region>(REGION_Y)) {}

        void output()
        {
            for (int i = 0; i < REGION_Y; i++)
            {
                for (int j = 0; j < REGION_X; j++)
                {
                    cout << alphabet[i*REGION_X+j];
                    if (j != REGION_X-1) cout << "-";
                }
                if (i != REGION_Y-1)
                {
                    cout << endl;
                    for (int j = 0; j < REGION_X; j++)
                    {
                        cout << "|";
                        if (j != REGION_X-1) cout << " ";
                    }
                    cout << endl;
                }
            }
        }
};

int main()
{
    Sim simulation;
   simulation.output();
}