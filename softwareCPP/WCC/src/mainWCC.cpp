#include <iostream>
#include <set>
#include <vector>
#include <iterator>
#include <string>
#include <cmath>

struct Legs {
    std::string squats = "> Do 5 sets of squats for 5 reps";
    std::string legpress = "> Do 3 sets of leg press for 15 reps";
    std::string lunges = "> Do 3 sets of lunges for 30 reps";
};

struct Arms {
    std::string benchpress = "> Do 5 sets of bench press for 5 reps";
    std::string biceps = "> Do 3 sets of any type of biceps exersize for 15 reps";
    std::string triceps = "> Do 3 sets of any type of triceps exersize for 15 reps";
};

void MaleWilks(double sum, double bodyweight) {
    const double a = -216.0475144;
    const double b = 16.2606339;
    const double c = -0.002388645;
    const double d = -0.00113732;;
    const double e = 7.01863 * pow(10, -6);
    const long double f = -1.291 * pow(10, -8);
    const long double result1 = (a + b * bodyweight + c * pow(bodyweight, 2) + d * pow(bodyweight, 3) + e * pow(bodyweight, 4) + f * pow(bodyweight, 5));
    const long double result2 = 500 / result1;
    std::cout << result2 << std::endl;
    std::cout << sum * result2 << std::endl;
}
void FemaleWilks(double sum, double bodyweight) {
    const double a = 594.31747775582;
    const double b = -27.23842536447;
    const double c = 0.82112226871;
    const double d = -0.00930733913;
    const double f = -0.00000009054;
    const long double e = 0.00004731582;
    const long double result1 = (a + b * bodyweight + c * pow(bodyweight, 2) + d * pow(bodyweight, 3) + e * pow(bodyweight, 4) + f * pow(bodyweight, 5));
    const long double result2 = 500 / result1;
    std::cout << result2 << std::endl;
    std::cout << sum * result2 << std::endl;
}

int main() {
    // Объявление наборов данных
    std::multiset<std::string> NamesPeople;
    std::vector<double> WeightPeople;

    // Объявление строковых переменных
    std::string training;
    std::string answer;
    std::string answer2;
    std::string sex;
    std::string names;

    // Объявление рук и ног
    Legs l;
    Arms a;

    // Объявление числовых переменных
    double bodyweight;
    int age;
    double sum;

    std::cout << "> Enter your sex (Male of Female): ";
    std::cin >> sex;
    std::cout << "> Enter your weight in KG: ";
    std::cin >> bodyweight;
    std::cout << "> Enter your age: ";
    std::cin >> age;

    if (age < 16) {
        std::cout << std::endl;
        std::cout << "> TOTAL: is not recomended to go to the gym!" << std::endl;
        return 0;
    }

    std::cout << "> Do you want to calculate Wilks coefficient ?" << std::endl;
    std::cout << "> Chose (Yes or No): ";
    std::cin >> answer;

    if (answer == "Yes" && sex == "Male") {
        std::cout << std::endl;
        std::cout << "> Please, write your sum of weights";
        std::cin >> sum;
        MaleWilks(sum, bodyweight);

    }
    else if (answer == "Yes" && sex == "Female") {
        std::cin >> sum;
        FemaleWilks(sum, bodyweight);
    }

    std::cout << "> What training do you want. Chose Arms or Legs: ";
    std::cin >> training;

    if (training == "Legs") {
        std::cout << l.squats << std::endl;
        std::cout << l.legpress << std::endl;
        std::cout << l.lunges << std::endl;
        std::cout << std::endl;
    }
    else  if (training == "Arms") {
        std::cout << a.benchpress << std::endl;
        std::cout << a.biceps << std::endl;
        std::cout << a.triceps << std::endl;
        std::cout << std::endl;
    }

    std::cout << "> Do you want to create a group ?" << std::endl;
    std::cout << "> Chose Create or Not create: ";
    std::cin >> answer2;

    if (answer2 == "Create") {
        std::cout << "> Chose number of people" << std::endl;
        int n = 0;
        std::cin >> n;
        std::cout << "> Write names: " << std::endl;
        for (int i = 0; i < n; ++i) {
            std::cin >> names; // Вводим имена
            NamesPeople.insert(names); // Вставляем имена в мультинабор
        }
   
        std::multiset<std::string>::iterator Sword = NamesPeople.end(); // Итератор указывает на конец мультинабора
        std::cout << "> A group of people: " << std::endl; // Выводим группу людей
        copy(NamesPeople.begin(), NamesPeople.end(), // Копируем данные с начала и до конца мультинабора
            std::ostream_iterator<std::string>(std::cout, "\n")); // Выводим скопированные данные
        
        /*
        * Оставлено для обратной совместимости, если все таки код приведенный выше не будет работать
        * Из двух вариантов самый легкий это первый, а самый легкий для компьютера это второй
        * ДА ПРИБУДЕТ С ТОБОЙ СИЛА!
        * УДАЧИ НА ЗАЩИТЕ ЭТОГО КОДА!
        * ЕСЛИ ЧТО, ПИШИ СРАЗУ МНЕ!
        *  for (int i = 1; Sword != NamesPeople.end(); i++, Sword++) {
            cout << *Sword << " ";
            }

            for (multiset<string>::const_iterator Sword(NamesPeople.begin()), end(NamesPeople.end());
            Sword != end; ++Sword)
            std::cout << *Sword << "\n";
        */
    }
    else {
        std::cout << "> The program has completed its work!" << std::endl;
        system("pause");
    }
}