// Player.cpp ************

#include "Player.h"

void Team::playerPlay(int index, int runs)
{
    players[index].score += runs;
    score += runs;
}

CricketMatch::CricketMatch(string humanTeamName, string computerTeamName)
{
    humanTeam.name = humanTeamName;
    computerTeam.name = computerTeamName;
    humanTeam.score = 0;
    computerTeam.score = 0;
    humanFirst = rand() % 2 == 0;
    runsToWin = 0;
}

void CricketMatch::play()
{
    if (humanFirst) 
    {
        cout << humanTeam.name << " wins the toss and will bat first." << endl;
        playInnings(humanTeam, computerTeam);
        if (humanTeam.score > computerTeam.score) 
        {
            cout << humanTeam.name << " wins!" << endl;
        }
        else if (humanTeam.score < computerTeam.score)
        {
            cout << computerTeam.name << " wins!" << endl;
        }
        else
        {
            cout << "It's a tie!" << endl;
        }
    }
    else
    {
        cout << computerTeam.name << " wins the toss and will bat first." << endl;
        playInnings(computerTeam, humanTeam);
        runsToWin = computerTeam.score + 1;
        cout << humanTeam.name << " needs " << runsToWin << " runs to win." << endl;
        playInnings(humanTeam, computerTeam);
        if (humanTeam.score > computerTeam.score)
        {
            cout << humanTeam.name << " WIn...!" << endl;
        }
        else if (humanTeam.score < computerTeam.score)
        {
            cout << computerTeam.name << " Win...!" << endl;
        }
        else 
        {
            cout << "It is to be tie!" << endl;
        }
    }
}

void CricketMatch::playInnings(Team& battingTeam, Team& bowlingTeam)
{
    int ballsRemaining = 6;
    int wicketsRemaining = 3;
    int index = 0;
    while (ballsRemaining > 0 && wicketsRemaining > 0)
    {
        int runs = rand() % 8;
        if (runs == 7)
        {
            cout << battingTeam.players[index].name << " is out!" << endl;
            wicketsRemaining--;
            if (wicketsRemaining > 0)
            {
                cout << wicketsRemaining << " wickets remaining." << endl;
            }
        }
        else 
        {
            battingTeam.playerPlay(index, runs);
            cout << battingTeam.players[index].name << " scores " << runs << " runs." << endl;
        }
        ballsRemaining--;
        if (ballsRemaining == 0 || wicketsRemaining == 0)
        {
            cout << battingTeam.name << " has scored " << battingTeam.score << " runs with " << wicketsRemaining << " wickets remaining." << endl;
        }
        else
        {
            cout << ballsRemaining << " balls and " << wicketsRemaining << " wickets remaining." << endl;
        }
        index = (index + 1) % 3;
    }
}
