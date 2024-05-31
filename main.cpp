#include <iostream>
#include "Participants.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian"); // задаём русский текст
    system("chcp 1251"); // настраиваем кодировку консоли
    Participants participants;
    int choice;

    participants.loadFromFile();

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
            participants.addParticipant();
            break;
        case 2:
            participants.addCatch();
            break;
        case 3:
            participants.removeParticipant();
            break;
        case 4:
            participants.editParticipant();
            break;
        case 5:
            participants.determineWinner();
            break;
        case 6:
            participants.displayStatistics();
            break;
        case 7:
            participants.saveToFile();
            break;
        case 8:
            participants.loadFromFile();
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
