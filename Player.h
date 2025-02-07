// Player.h ************

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

class Player
{
public:
    string name;
    int score;
};

class Team
{
public:
    string name;
    int score;
    Player players[3];
    void playerPlay(int index, int runs);
    
};

class CricketMatch
{
private:
    Team humanTeam;
    Team computerTeam;
    bool humanFirst;
    int runsToWin;
public:
    CricketMatch(string humanTeamName, string computerTeamName);
    void play();
    void playInnings(Team& battingTeam, Team& bowlingTeam);
    
};