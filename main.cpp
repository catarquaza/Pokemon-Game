using namespace std;
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cstdlib>

// Floraburn: Grass Fire Shockfin: Water Electric Frostmoth: Ice Bug Shadowmind: Dark Physic Voltbrawler: Electric Fighting Terrafey: Rock Fairy Ironcladore Rock Steel
string Mons[10] = {"Floraburn", "Shockfin", "Frostmoth", "Shadowmind", "Voltbrawler", "Terrafey", "Ironcladore", "Spectrake", "Toxiwarrior", "Metatuff"};
void makeTeam(int *team)
{
    int mon[3];
    int Mon1 = rand() % 9;
    int Mon2 = rand() % 9;
    int Mon3 = rand() % 9;
    while (true)
    {
        bool same = false;
        if (Mon1 == Mon2)
        {
            Mon2 = rand() % 9;
            cout << Mon2;
            same = true;
        }
        if (Mon1 == Mon3)
        {
            Mon3 = rand() % 9;
            same = true;
        }
        if (Mon2 == Mon3)
        {
            Mon3 = rand() % 9;
            same = true;
        }
        if (same == false)
        {
            break;
        }
    }
    team[0] = Mon1;
    team[1] = Mon2;
    team[2] = Mon3;
}

int main()
{
    srand(time(0));
    int team1[3];
    int team2[3];
    makeTeam(team1);
    makeTeam(team2);
    string roster1[3] = {Mons[team1[0]], Mons[team1[1]], Mons[team1[2]]};
    string roster2[3] = {Mons[team2[0]], Mons[team2[1]], Mons[team2[2]]};
    cout << "Team 1: \n";
    for (int i = 0; i < 3; i++)
    {
        cout << roster1[i] << "\n";
    }
    cout << "Team 2: \n";
    for (int i = 0; i < 3; i++)
    {
        cout << roster2[i] << "\n";
    }
}