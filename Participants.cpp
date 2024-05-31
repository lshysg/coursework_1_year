#include "Participants.h"

void Participants::addParticipant() {
    string name;
    cout << "\n������� ��� ���������: ";
    cin >> name;
    names.push_back(name);
    fishCaughts.push_back(0);
}

void Participants::addCatch() {
    string name;
    int numFish;
    cout << "\n������� ��� ���������: ";
    cin >> name;
    cout << "������� ���������� ��������� ���: ";
    cin >> numFish;

    for (size_t i = 0; i < names.size(); ++i) {
        if (names[i] == name) {
            fishCaughts[i] += numFish;
            cout << "���� ������� ���������!" << endl;
            return;
        }
    }
    cout << "�������� � ����� ������ �� ������." << endl;
}

void Participants::removeParticipant() {
    string name;
    cout << "\n������� ��� ��������� ��� ��������: ";
    cin >> name;

    for (size_t i = 0; i < names.size(); ++i) {
        if (names[i] == name) {
            names.erase(names.begin() + i);
            fishCaughts.erase(fishCaughts.begin() + i);
            cout << "�������� ������� ������!" << endl;
            return;
        }
    }
    cout << "�������� � ����� ������ �� ������." << endl;
}

void Participants::editParticipant() {
    string name;
    cout << "\n������� ��� ��������� ��� ��������������: ";
    cin >> name;

    for (size_t i = 0; i < names.size(); ++i) {
        if (names[i] == name) {
            cout << "������� ����� ��� ���������: ";
            cin >> names[i];
            cout << "��� ��������� ������� ���������������!" << endl;
            return;
        }
    }
    cout << "�������� � ����� ������ �� ������." << endl;
}

void Participants::determineWinner() const {
    if (names.empty()) {
        cout << "��� ���������� ��� ����������� ����������." << endl;
        return;
    }

    size_t winnerIndex = 0;
    for (size_t i = 1; i < names.size(); ++i) {
        if (fishCaughts[i] > fishCaughts[winnerIndex]) {
            winnerIndex = i;
        }
    }

    cout << "\n����������: " << names[winnerIndex] << " � " << fishCaughts[winnerIndex] << " ���������� ������!" << endl;
}

void Participants::saveToFile() const {
    ofstream file("participants.txt");
    if (!file) {
        cout << "������ �������� ����� ��� ������." << endl;
        return;
    }

    for (size_t i = 0; i < names.size(); ++i) {
        file << names[i] << " " << fishCaughts[i] << endl;
    }

    file.close();
    cout << "������ ������� ���������." << endl;
}

void Participants::loadFromFile() {
    ifstream file("participants.txt");
    if (!file) {
        cout << "������ �������� ����� ��� ������." << endl;
        return;
    }

    names.clear();
    fishCaughts.clear();
    string name;
    int fishCaught;
    while (file >> name >> fishCaught) {
        names.push_back(name);
        fishCaughts.push_back(fishCaught);
    }

    file.close();
    cout << "������ ������� ���������." << endl;
}

void Participants::displayStatistics() const {
    cout << "=== ����� ���������� ===" << endl;
    for (size_t i = 0; i < names.size(); ++i) {
        cout << "��������: " << names[i] << ", ���������� ��������� ���: " << fishCaughts[i] << endl;
    }
}
