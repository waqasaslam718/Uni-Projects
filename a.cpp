#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Score {
private:
    int value;

public:
  
    Score(int initialScore) : value(initialScore) {}

    Score& operator++() {
        ++value;
        return *this;
    }

  
    Score& operator--() {
        --value;
        return *this;
    }

 
    Score operator--(int) {
        Score temp = *this;
        value--;
        return temp;
    }

   
    int getValue() const {
        return value;
    }
};

class GuessingGame {
private:
    int targetNumber;   
    Score playerScore;  

    int generateRandomNumber(int min, int max) {
        return rand() % (max - min + 1) + min;
    }

public:
    GuessingGame() : playerScore(5) {
        targetNumber = generateRandomNumber(1, 10);
    }

    void play() {
        int attempt = 1;
        cout << "Virtual Guessing Game Starts!" << endl;
        cout << "The virtual player will guess a number between 1 and 10." << endl;
        cout << "Score decreases for incorrect guesses and increases for correct ones.\n" << endl;

        while (playerScore.getValue() > 0) {
            int guess = generateRandomNumber(1, 10); 
            cout << "Attempt " << attempt << ": Virtual player guesses " << guess << ". ";

            if (guess == targetNumber) {
                ++playerScore;  
                cout << "Correct! Score increases! Current score: " << playerScore.getValue() << endl;
                cout << "\nThe virtual player guessed the correct number: " << targetNumber << endl;
                cout << "Final score: " << playerScore.getValue() << endl;
                break;
            } else if (guess > targetNumber) {
                --playerScore;  
                cout << "Too high! Score decreases. Current score: " << playerScore.getValue() << endl;
            } else {
                playerScore--;
                cout << "Too low! Score decreases. Current score: " << playerScore.getValue() << endl;
            }

            if (playerScore.getValue() == 0) {
                cout << "\nGame Over! The virtual player ran out of score." << endl;
                cout << "The target number was: " << targetNumber << "." << endl;
                break;
            }

            ++attempt; 
        }
    }
};

int main() {
 
    srand(static_cast<unsigned>(time(0)));

   
    GuessingGame game;
    game.play();
    cout<<"------------------------------------------"<<endl;


    return 0;
}