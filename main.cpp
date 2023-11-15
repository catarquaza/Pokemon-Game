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
string voltbrawler[] = {"Fighting","Electric","100","30","20"};
string terrafey[] = {"Fairy" ,"Rock","30","50","70"};
string metatuff[] = {"Metal" , "Fighting", "30","100","20"};
string spectrake[] = {"Dragon" , "Ghost", "50", "50", "50"};
string ironcladore[] = {"Rock" , "Steel", "80", "80" , "20"};
string toxiwarrior[] = {"Poison" , "Fighting" , "140" , "20" , "20" };
void makeMoves(int *mve)
{
    int move1 = rand() % 9+1;
    int move2 = rand() % 9+1;
    int move3 = rand() % 9+1;
    int move4 = rand() % 9+1;
    while (true)
    {
        bool same = false;
        if (move1 == move2)
        {
            move2 = rand() % 9;
            same = true;
        }
        if (move2 == move3)
        {
            move3 = rand() % 9;
            same = true;
        }
        if (move3 == move4)
        {
            move4 = rand() % 9;
            same = true;
        }
        if (move3 == move1)
        {
            move3 = rand() % 9;
            same = true;
        }
        if (move1 == move4)
        {
            move4 = rand() % 9;
            same = true;
        }
        if (move2 == move4)
        {
            move4 = rand() % 9;
            same = true;
        }
        if (same == false)
        {
            mve[0]= move1 * 10;
            mve[1]= move2 * 10;
            mve[2]= move3 * 10;
            mve[3]= move4 * 10;
            break;
        }
        else
        {
            same = false; 
        }

    }
} 
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
        else
        {
            same = false;
        }
    };
    string roster1[3] = {Mons[team1[0]], Mons[team1[1]], Mons[team1[2]]};
    string roster2[3] = {Mons[team2[0]], Mons[team2[1]], Mons[team2[2]]};
    int p11[4];
    int p12[4];
    int p13[4];
    int p21[4];
    int p22[4];
    int p23[4];
    makeMoves(p11);
    makeMoves(p12);
    makeMoves(p13);
    makeMoves(p21);
    makeMoves(p22);
    makeMoves(p23);
    cout << "Team 1: ";
    for (int i = 0; i < 3; i++)
    {
        cout << roster1[i] << " ";
    }
    cout << "\nTeam 2: ";
    for (int i = 0; i < 3; i++)
    {
        cout << roster2[i] << " ";
    }
    int x = 0;
    int m = 0;
    int m2 = 0;
    int choice;
    while (true)
    {
        x += 1;
        cout << "\nRound " << x << "!\n";
        cout << roster1[m];
        cout << " V.S ";
        cout << roster2[m2] <<"\n";
        cout << "What does " << roster1[m] << " want to do";
        cout << " 1 Moves 2 Pokemon: ";
        cin >> choice;
        if (choice == 1)
        {
            if (m == 0)
            {
                cout << "1 " << p11[0] <<" 2 " <<p11[1]<<" 3 "<<p11[2]<<" 4 "<<p11[3]<<"\n";
                cin >> choice;
                
            }
            if (m == 1)
            {
                cout << "1 " << p12[0] <<" 2 " <<p12[1]<<" 3 "<<p12[2]<<" 4 "<<p12[3]<<"\n";
                cin >> choice;
            }
            if (m == 2)
            {
                cout << "1 " << p13[0] <<" 2 " <<p13[1]<<" 3 "<<p13[2]<<" 4 "<<p13[3]<<"\n";
                cin >> choice;
            }

        }
        else if (choice == 2)
        {
            for (int i = 0; i < 3; i++)
            {
                
                cout << i+1 << ". "<< roster1[i] << " \n";
            }
        }
        else 
        {
            cout << "Try again"
        }
        cout << "What does " << roster2[m2] << " want to do:";
    }
}