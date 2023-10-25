using namespace std;
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cstdlib>

// Floraburn: Grass Fire Shockfin: Water Electric Frostmoth: Ice Bug Shadowmind: Dark Physic Voltbrawler: Electric Fighting Terrafey: Rock Fairy Ironcladore Rock Steel
string Mons[10] = {"Floraburn", "Shockfin", "Frostmoth", "Shadowmind", "Voltbrawler", "Terrafey", "Ironcladore", "Spectrake", "Toxiwarrior", "Metatuff"};
string floraburn[] = {"Fire","Grass","80","20","50"};
string shockfin[] = {"Electric", "Water","60","30","60"};
string frostmoth[] = {"Ice","Bug","110","30","10"};
string shadowmind[] = {"Dark","Psycic", "80", "20", "50"};
string voltbrawler[] = {"Electric","Fighting","100","30","20"};
string terrafey[] = {"Rock","Fairy","30","50","70"};
string metatuff[] = {"Metal", "Fighting", "30","100","20"};
string spectrake[] = {"Dragon", "Ghost", "50", "50", "50"};
string ironcladore[] = {"Rock", "Steel", "80", "80" , "20"};
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
    bool same;
    while (true)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int x = 0; x < 3; x++)
            {
                if (team1[i] == team2[x])
                {
                    makeTeam(team2);
                    same = true;
                }
            }
        }
        if (same == false)
        {
            break;
        }
    };
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