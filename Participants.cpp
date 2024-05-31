#include "Participants.h"

void Participants::addParticipant() {
    string name;
    cout << "\nВведите имя участника: ";
    cin >> name;
    names.push_back(name);
    fishCaughts.push_back(0);
}

void Participants::addCatch() {
    string name;
    int numFish;
    cout << "\nВведите имя участника: ";
    cin >> name;
    cout << "Введите количество пойманных рыб: ";
    cin >> numFish;

    for (size_t i = 0; i < names.size(); ++i) {
        if (names[i] == name) {
            fishCaughts[i] += numFish;
            cout << "Рыба успешно добавлена!" << endl;
            return;
        }
    }
    cout << "Участник с таким именем не найден." << endl;
}

void Participants::removeParticipant() {
    string name;
    cout << "\nВведите имя участника для удаления: ";
    cin >> name;

    for (size_t i = 0; i < names.size(); ++i) {
        if (names[i] == name) {
            names.erase(names.begin() + i);
            fishCaughts.erase(fishCaughts.begin() + i);
            cout << "Участник успешно удален!" << endl;
            return;
        }
    }
    cout << "Участник с таким именем не найден." << endl;
}

void Participants::editParticipant() {
    string name;
    cout << "\nВведите имя участника для редактирования: ";
    cin >> name;

    for (size_t i = 0; i < names.size(); ++i) {
        if (names[i] == name) {
            cout << "Введите новое имя участника: ";
            cin >> names[i];
            cout << "Имя участника успешно отредактировано!" << endl;
            return;
        }
    }
    cout << "Участник с таким именем не найден." << endl;
}

void Participants::determineWinner() const {
    if (names.empty()) {
        cout << "Нет участников для определения победителя." << endl;
        return;
    }

    size_t winnerIndex = 0;
    for (size_t i = 1; i < names.size(); ++i) {
        if (fishCaughts[i] > fishCaughts[winnerIndex]) {
            winnerIndex = i;
        }
    }

    cout << "\nПобедитель: " << names[winnerIndex] << " с " << fishCaughts[winnerIndex] << " пойманными рыбами!" << endl;
}

void Participants::saveToFile() const {
    ofstream file("participants.txt");
    if (!file) {
        cout << "Ошибка открытия файла для записи." << endl;
        return;
    }

    for (size_t i = 0; i < names.size(); ++i) {
        file << names[i] << " " << fishCaughts[i] << endl;
    }

    file.close();
    cout << "Данные успешно сохранены." << endl;
}

void Participants::loadFromFile() {
    ifstream file("participants.txt");
    if (!file) {
        cout << "Ошибка открытия файла для чтения." << endl;
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
    cout << "Данные успешно загружены." << endl;
}

void Participants::displayStatistics() const {
    cout << "=== Общая статистика ===" << endl;
    for (size_t i = 0; i < names.size(); ++i) {
        cout << "Участник: " << names[i] << ", Количество пойманных рыб: " << fishCaughts[i] << endl;
    }
}
