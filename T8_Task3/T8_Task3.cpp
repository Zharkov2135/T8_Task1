#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <limits>

struct Train {
    std::string destination;
    int number{};
    std::string time; // HH:MM як рядок
};

int main() {
    const int N = 5;
    std::vector<Train> trains(N);

    for (int i = 0; i < N; i++) {
        std::cout << "\nTrain " << (i + 1) << "\n";

        std::cout << "Destination: ";
        std::getline(std::cin, trains[i].destination);
        while (trains[i].destination.empty()) {
            // якщо раптом прилетів порожній рядок (після попереднього вводу)
            std::getline(std::cin, trains[i].destination);
        }

        std::cout << "Number: ";
        std::cin >> trains[i].number;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "Departure time (HH:MM): ";
        std::getline(std::cin, trains[i].time);
        while (trains[i].time.empty()) {
            std::getline(std::cin, trains[i].time);
        }
    }

    // 1) сортування за номером
    std::sort(trains.begin(), trains.end(),
        [](const Train& a, const Train& b) {
            return a.number < b.number;
        });

    std::cout << "\nSorted by train number:\n";
    for (const auto& t : trains) {
        std::cout << t.number << " | " << t.destination << " | " << t.time << "\n";
    }

    // 2) пошук потяга за номером
    int search;
    std::cout << "\nEnter train number to search: ";
    std::cin >> search;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    bool found = false;
    for (const auto& t : trains) {
        if (t.number == search) {
            std::cout << "Found: " << t.number << " | " << t.destination << " | " << t.time << "\n";
            found = true;
        }
    }
    if (!found) std::cout << "Train not found.\n";

    return 0;
}
