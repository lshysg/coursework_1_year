#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

// Структура для хранения информации об участнике
struct Participant {
    string name;
    int fishCaught;
};

// Функция для добавления участника
void addParticipant(vector<Participant>& participants) {
    Participant newParticipant;
    cout << "\nВведите имя участника: ";
    cin >> newParticipant.name;
    newParticipant.fishCaught = 0;
    participants.push_back(newParticipant);
}

// Функция для внесения улова участника
void addCatch(vector<Participant>& participants) {
    string name;
    int numFish;
    cout << "\nВведите имя участника: ";
    cin >> name;
    cout << "Введите количество пойманных рыб: ";
    cin >> numFish;

    for (auto& participant : participants) {
        if (participant.name == name) {
            participant.fishCaught += numFish;
            cout << "Данные успешно добавлены!" << endl;
            return;
        }
    }
    cout << "Участник с таким именем не найден." << endl;
}

// Функция для удаления участника
void removeParticipant(vector<Participant>& participants) {
    string name;
    cout << "\nВведите имя участника для удаления: ";
    cin >> name;

    for (auto it = participants.begin(); it != participants.end(); ++it) {
        if (it->name == name) {
            participants.erase(it);
            cout << "Участник успешно удален!" << endl;
            return;
        }
    }
    cout << "Участник с таким именем не найден." << endl;
}

// Функция для редактирования информации об участнике
void editParticipant(vector<Participant>& participants) {
    string name;
    cout << "\nВведите имя участника для редактирования: ";
    cin >> name;

    for (auto& participant : participants) {
        if (participant.name == name) {
            cout << "Введите новое имя участника: ";
            cin >> participant.name;
            cout << "Имя участника успешно отредактировано!" << endl;
            return;
        }
    }
    cout << "Участник с таким именем не найден." << endl;
}

// Функция для определения победителя
void determineWinner(const vector<Participant>& participants) {
    if (participants.empty()) {
        cout << "Нет участников для определения победителя." << endl;
        return;
    }

    const Participant* winner = &participants[0];
    for (const auto& participant : participants) {
        if (participant.fishCaught > winner->fishCaught) {
            winner = &participant;
        }
    }

    cout << "\nПобедитель: " << winner->name << " с " << winner->fishCaught << " пойманными рыбами!" << endl;
}

// Функция для сохранения данных в файл
void saveToFile(const vector<Participant>& participants) {
    ofstream file("participants.txt");
    if (!file) {
        cout << "Ошибка открытия файла для записи." << endl;
        return;
    }

    for (const auto& participant : participants) {
        file << participant.name << " " << participant.fishCaught << endl;
    }

    file.close();
    cout << "Данные успешно сохранены." << endl;
}

// Функция для загрузки данных из файла
void loadFromFile(vector<Participant>& participants) {
    ifstream file("participants.txt");
    if (!file) {
        cout << "Ошибка открытия файла для чтения." << endl;
        return;
    }

    participants.clear();
    Participant participant;
    while (file >> participant.name >> participant.fishCaught) {
        participants.push_back(participant);
    }

    file.close();
    cout << "Данные успешно загружены." << endl;
}

// Функция для вывода общей статистики
void displayStatistics(const vector<Participant>& participants) {
    cout << "=== Общая статистика ===" << endl;
    for (const auto& participant : participants) {
        cout << "Участник: " << participant.name << ", Количество пойманных рыб: " << participant.fishCaught << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Russian"); 
    system("chcp 1251"); 
    vector<Participant> participants;
    int choice;

    loadFromFile(participants);

    do {
        cout << "\nМеню:" << endl;
        cout << "1. Добавить участника" << endl;
        cout << "2. Внести улов участника" << endl;
        cout << "3. Удалить участника" << endl;
        cout << "4. Редактировать имя участника" << endl;
        cout << "5. Определить победителя" << endl;
        cout << "6. Вывести общую статистику" << endl;
        cout << "7. Сохранить данные" << endl;
        cout << "8. Загрузить данные" << endl;
        cout << "9. Выйти из программы" << endl;
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addParticipant(participants);
            break;
        case 2:
            addCatch(participants);
            break;
        case 3:
            removeParticipant(participants);
            break;
        case 4:
            editParticipant(participants);
            break;
        case 5:
            determineWinner(participants);
            break;
        case 6:
            displayStatistics(participants);
            break;
        case 7:
            saveToFile(participants);
            break;
        case 8:
            loadFromFile(participants);
            break;
        case 9:
            cout << "До свидания!" << endl;
            break;
        default:
            cout << "Неверный выбор. Попробуйте еще раз." << endl;
            break;
        }
    } while (choice != 9);

    return 0;
}
