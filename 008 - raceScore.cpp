/* Wenbin Wu
Lab 21D
Assignment #8 Score the Race
*/

#include <iostream>
using namespace std;

bool isUppercase(string s) {
    for (int i = 0; i < s.length(); i++) {
        if ((int) s[i] < 65 || (int) s[i] > 90)
            return false;
    }
    return true;
}

int main() {
    string raceOutcome = "";  // race outcome

    while (raceOutcome != "done") {
        int teams[26][2] = {0};  // 2d array to put infromation from score input
        int numTeams = 0;
        int numRunners = 0;
        bool numRunnerMatch = true;
        int index;

        cout << "Enter race outcome: ";
        cin >> raceOutcome;  // input race outcome
        
        if (! isUppercase(raceOutcome))  // if input is not uppercase continue to next loop
            continue;

        for (int i = 0; i < raceOutcome.length(); i++) {
            index = (int) raceOutcome[i] % 65;
            teams[index][0] += 1;  // count the number of runners in a team
            teams[index][1] += i + 1;  // add up all the race scores for a team
        }

        for (int i = 0; i < 26; i++) {  // find out the number of teams
            if (teams[i][0] != 0)
                numTeams++;
        }

        index = (int) raceOutcome[0] % 65;
        numRunners = teams[index][0];  // get number of runners from the first team in raceOutcome input

        for (int i = 0; i < 26; i++) {  // check every team for number of runners
            if (teams[i][0] != 0 && teams[i][0] != numRunners)  // if different number is found, this race outcome is invalid input
                numRunnerMatch = false;
        }

        if (numRunnerMatch == false) { // invalid input
            cout << "Number of runners do not match!" << endl;
            continue;
        }
        
        cout << "There are " << numTeams << " teams." << endl;
        cout << "Each team has  " << numRunners << " runners."<< endl;
        
        int winningTeam = index;  // temporarily set winningTeam to first team in raceOutcome input
        int teamScore = teams[index][1];  //  temporarily set winning teamScore to first team's score

        cout << "Team\tScore" << endl;
        for (int i = 0; i < 26; i++) {  // loop through the teams array to find the lowest score
            if (teams[i][1] != 0 && teams[i][1] < teamScore) {
                winningTeam = i;
                teamScore = teams[i][1];
            }
            if (teams[i][1] != 0)  // print out team and team score
                cout << (char) (i + 65)  <<  "\t" << (double) teams[i][1] / numRunners << endl;
        }
        
        cout << "The winning team is team " << (char) (winningTeam + 65) << " with a score of " << (double) teams[winningTeam][1] / numRunners << endl;
    }

    return 0;
}