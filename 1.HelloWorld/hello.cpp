#include <iostream>
#include <string>

int main()
{
    setlocale(LC_ALL, "Russian");
    std::cout << "Как вас зовут?" << std::endl;
    std::string name;
    // Ввод одного слова до первого пробела
    std::cin >> name;
    std::cout << "Здравствуйте, " << name << "!" << std::endl << "Как настроение?" << std::endl;

    // Грустно, но на самом деле cin >> string и getline конфликтуют, нам также необходимо очистить поток перед вызовом getline
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string answer;
    std::getline(std::cin, answer);
    std::cout << "Отлично, " << name << "! Я рад, что у вас всё " << answer << std::endl;
    return 0;
}
