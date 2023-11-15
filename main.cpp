using namespace std;
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cstdlib>

// Floraburn: Grass Fire Shockfin: Water Electric Frostmoth: Ice Bug Shadowmind: Dark Physic Voltbrawler: Electric Fighting Terrafey: Rock Fairy Ironcladore Rock Steel
string Mons[10] = {"Floraburn", "Shockfin", "Frostmoth", "Shadowmind", "Voltbrawler", "Terrafey", "Ironcladore", "Spectrake", "Toxiwarrior", "Metatuff"};
int speed[] = {50,60,10,50,20,70,70,50,20};
int dealDamage(int move)
{
    int chance = 110 - move;
    int hit = rand() % 99+1;
    if (hit <= chance)
    {
        return move;
    }
    else
    {
        return 0; 
    }
}
string buildType(string mon , int x)
{
    string floraburn[] = {"Fire","Grass","80","20","50"};
    string shockfin[] = {"Electric", "Water","60","30","60"};
    string frostmoth[] = {"Ice","Bug","110","30","10"};
    string shadowmind[] = {"Dark","Psycic", "80", "20", "50"};
    string voltbrawler[] = {"Fighting","Electric","100","30","20"};
    string terrafey[] = {"Fairy" ,"Rock","30","50","70"};
    string metatuff[] = {"Metal" , "Fighting", "30","100","20"};
    string spectrake[] = {"Dragon" , "Ghost", "50", "50", "50"};
    string ironcladore[] = {"Rock" , "Steel", "80", "80" , "70"};
    string toxiwarrior[] = {"Poison" , "Fighting" , "140" , "20" , "20" };
    if (mon == "Floraburn")
    {
        return floraburn[x];
    }
    if (mon == "Shockfin")
    {
        return shockfin[x];
    }
    if (mon == "Frostmoth")
    {
        return frostmoth[x];
    }
    if (mon == "Shadowmind")
    {
        return shadowmind[x];
    }
    if (mon == "Voltbrawler")
    {
        return voltbrawler[x];
    }
    if (mon == "Terrafey")
    {
        return terrafey[x];
    }
    if (mon == "Metatuff")
    {
        return metatuff[x];
    }
    if (mon == "Spectrake")
    {
        return spectrake[x];
    }
    if (mon == "Ironcladore")
    {
        return ironcladore[x];
    }
    if (mon == "Toxiwarrior")
    {
        return toxiwarrior[x];
    }
    else 
    {
        return "";
    }
}
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
int chooseMove(int move[4])
{
    int choice;
    cout << "1. " << move[0] << " 2. " << move[1] << " 3. " << move[2] << " 4. " << move[3] << "\n"; 
    cin >> choice;
    return move[choice-1];
}
int chooseMon(string mon[3])
{
    int choice;
    cout << "1. " << mon[0] << " 2. "  << mon[1] << " 3. " << mon[2] << "\n";
    cin >> choice;
    return choice;
}
void makeHealth(string mon, int health)
{
    cout << mon << ": (";
    for (int i; health >= i;)
    {
        cout << "|";
        i += 10;
    }
    for (int i = 0; 100 - health > i;)
    {
        cout << " ";
        i+= 10;
    }
    cout << ")" << health << "/100 HP";
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
    cout << "\n";
    int x = 0;
    int m = 0;
    int m2 = 0;
    int choice;
    int health[3] = {100,100,100};
    int health2[3] = {100,100,100};
    while (true)
    {
        x += 1;
        cout << "Round " << x << "\n";
        cout << roster1[m];
        cout << " V.S ";
        cout << roster2[m2] <<"\n";
        cout << "What does " << roster1[m] << "(" << health[m] << " hp) want to do";
        cout << " 1 Moves 2 Pokemon: ";
        cin >> choice;
        int move1;
        int move2;
        int winner;
        if (choice == 1)
        {
            if (m == 0)
            {
                move1 = chooseMove(p11);
            }
            if (m == 1)
            {
                move1 = chooseMove(p12);
            }
            if (m == 2)
            {
                move1 = chooseMove(p13);
            }

        }
        else if (choice == 2)
        {
            while (true)
            {
                m = chooseMon(roster1) - 1;
                if (health[m] < 1)
                {
                    cout << "already knocked out try again";
                }
                else {break;}
            }
        }
        else 
        {
            cout << "Try again";
            
        }
        cout << "What does " << roster2[m2] << "(" << health2[m2] << " hp) want to do:";
        cout << " 1 Moves 2 Pokemon: ";
        int choice2;
        cin >> choice2;
        if (choice2 == 1)
        {
            if (m2 == 0)
            {
                move2 = chooseMove(p21);
            }
            if (m2 == 1)
            {
                move2 = chooseMove(p22);
            }
            if (m2 == 2)
            {
                move2 = chooseMove(p23);
            }
            
        }
        else if (choice2 == 2)
        {
            while (true)
            {
                m2 = chooseMon(roster2) - 1;
                if (health2[m2] < 1)
                {
                    cout << "already knocked out try again";
                }
                else {break;}
            }
        }
        else 
        {
            cout << "Try again";
        }
        if (choice == 1 && choice2 == 1)
        {
            string mon[5] = {};
            string mon2[5] = {};
            for (int x = 0; x < 5; x++)
            {
                mon[x] = buildType(roster1[m], x);
            }
            for (int x = 0; x < 5; x++)
            {
                mon2[x] = buildType(roster2[m2], x);
            }
            if (mon[4] > mon2[4])
            {
                health2[m2] = health2[m2] - dealDamage(move1);
                if (health2[m2] > 0)
                {
                    cout << roster2[m2] << " = " << health2[m2];
                } 
                else{ cout << roster1[m] << "has fainted";}
                if (health2[m2] > 0)
                {
                    health[m] = health[m] - dealDamage(move2);
                    if (health[m] > 0)
                    {
                        cout << roster1[m] << " = " << health[m];                          
                    }
                    else{ cout << roster1[m] << "has fainted";}                    
                }

            }
            else if (mon[4] < mon2[4])
            {
                health[m] = health[m] - dealDamage(move2);
                if (health[m] > 0)
                {
                    cout << roster1[m] << " = " << health[m];
                }
                else{ cout << roster1[m] << "has fainted";}
                if (health[m] > 0)
                {
                    health2[m2] = health2[m2] - dealDamage(move1);
                    if (health2[m2] > 0)
                    {
                        cout << roster2[m2] << " = " << health2[m2];                          
                    }
                    else{ cout << roster2[m2] << "has fainted";}  
                }
            }
        }
        else if (choice == 1)
        { 
            string mon[5] = {};
            for (int x = 0; x < 5; x++)
            {
                mon[x] = buildType(roster1[m], x);
                health2[m2] = health2[m2] - dealDamage(move1);   
                if (health[m] > 0)
                    makeHealth(roster1[m], health[m]);
                else{ cout << roster2[m2] << "has fainted";}           
            }
            
        }
        else
        {
            string mon2[5] = {};
            for (int x = 0; x < 5; x++)
            {
                mon2[x] = buildType(roster2[m2], x);
                health[m] = health[m] - dealDamage(move2);
                cout << roster1[m] << " = " << health[m] <<"hp";
            }
        }
        if (health[m] < 1)
        {
            while (true)
            {
                if (health[0] < 1 && health[2] < 1 && health[3] < 1)
                {
                    winner = 2;
                    break;
                }
                else
                {
                    cout << "player 1 choose new mon\n";
                    m = chooseMon(roster1) - 1;
                    if (health[m] < 1)
                        {
                            cout << "already knocked out try again\n";
                        }
                    else {break;}
                }   
            }
        }
        if (health2[m2] < 1)

        {
            while (true)
            {
                if (health2[0] < 1 && health2[2] < 1 && health2[3] < 1)
                {
                    winner = 1;
                    break;
                }
                else
                {
                    cout << "player 2 choose new mon\n";
                    m2 = chooseMon(roster2) - 1;
                    if (health2[m2] < 1)
                    {
                        cout << "already knocked out try again\n";
                    }
                    else {break;}
                }
            }
        }
        if (winner < 0)
        {
            if (winner == 1)
            {
                cout << "Player 1 has won the game";
            }
            else 
            {
                cout << "Plauer 2 has won the game";
            }
            break;
        }
    }
}