#ifndef PARTICIPANTS_H
#define PARTICIPANTS_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Participants {
private:
    vector<string> names;
    vector<int> fishCaughts;

public:
    void addParticipant();
    void addCatch();
    void removeParticipant();
    void editParticipant();
    void determineWinner() const;
    void saveToFile() const;
    void loadFromFile();
    void displayStatistics() const;
};

#endif // PARTICIPANTS_H
