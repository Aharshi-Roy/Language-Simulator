#include <iostream>
#include <vector>
using namespace std;

class Area
{

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
};

int main()
{
    Sim simulation;
    cout << simulation.regions[0][0].areas.size();
}