#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

const int MAX_BALLS = 50;

class Player {
private:
    string playerName;
    int totalScore;
    int ballsPlayed;
    int scores[MAX_BALLS];
    int scoresCount;

public:
    Player() : totalScore(0), ballsPlayed(0), scoresCount(0) {}

    void setName(const string &name) {
        playerName = name;
    }

    string getName() const {
        return playerName;
    }

    void addScore(int score) {
        if (scoresCount < MAX_BALLS) {
            scores[scoresCount++] = score;
            if (score != -1) {
                totalScore += score;
                ballsPlayed++;
            }
        }
    }

    int getTotalScore() const {
        return totalScore;
    }

    int getBallsPlayed() const {
        return ballsPlayed;
    }

    const int* getScores() const {
        return scores;
    }

    int getScoresCount() const {
        return scoresCount;
    }
};

void simulatePlayer(Player &player) {
    while (true) {
        int score = (rand() % 7) - 1;
        if (score == 5)
            continue;
        player.addScore(score);
        if (score == -1)
            break;
    }
}

void displayScoresPerBall(Player players[], int playerCount) {
    for (int i = 0; i < playerCount; ++i) {
        cout << players[i].getName() << " Scores per Ball: ";
        for (int j = 0; j < players[i].getScoresCount(); ++j) {
            int score = players[i].getScores()[j];
            if (score == -1) {
                cout << "OUT";
            } else {
                cout << score;
            }
            if (j < players[i].getScoresCount() - 1) {
                cout << ", ";
            }
        }
        cout << endl;
        cout << "Total Score: " << players[i].getTotalScore() << endl;
        cout << "Balls Played: " << players[i].getBallsPlayed() << endl;
        cout << "-----------------------------" << endl;
    }
}

void displayMatchSummary(Player players[], int playerCount) {
    cout << "<<<<<< Match Summary >>>>>>" << endl;
    cout << "Player Name         Score    Balls Played" << endl;
    Player manOfTheMatch = players[0];
    for (int i = 0; i < playerCount; ++i) {
        cout << players[i].getName();
        cout.width(20 - players[i].getName().length());
        cout << right << players[i].getTotalScore() << "        ";
        cout << players[i].getBallsPlayed() << endl;
        if (players[i].getTotalScore() > manOfTheMatch.getTotalScore()) {
            manOfTheMatch = players[i];
        }
    }
    cout << "-----------------------------" << endl;
    cout << "Man of the Match: " << manOfTheMatch.getName()
         << " with " << manOfTheMatch.getTotalScore() << " runs." << endl;
}

int main() {
    srand(time(0));

    string playerNames[] = {
        "Babar Azam", "Naseem Shah", "Agha Salman", "Mohammad Amir",
        "Shaheen Afridi", "Shadab Khan", "Imad Wasim", "Fakhar Zaman",
        "Haris Rauf", "Mohammad Rizwan", "Iftikhar Ahmed"};
    const int playerCount = sizeof(playerNames) / sizeof(playerNames[0]);

    Player players[playerCount];
    for (int i = 0; i < playerCount; ++i) {
        players[i].setName(playerNames[i]);
    }

    for (int i = 0; i < playerCount; ++i) {
        simulatePlayer(players[i]);
    }

    displayScoresPerBall(players, playerCount);
    displayMatchSummary(players, playerCount);

    return 0;
}
