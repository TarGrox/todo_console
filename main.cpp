#include <iostream>
#include <string>
#include <vector>


int main()
{
    int amountOfSpacing = 20;
    int amountOfLine    = 30;

    /*
        ###TODO_LIST###
        1.
        2.
        3.
        4.
        5.

        > input string

    */

    // 2. clear window
    // 3. навигация по строкам, с input string прыгнуть на №5
    std::vector<std::string> screenVector
                (
                amountOfLine,
                std::string(amountOfSpacing, ' ')
                );
    screenVector[0] = "###TODO_LIST###";
    for ( auto i = 1; i < 6; i++ )
        screenVector[i] = std::to_string(i) + '.';

    for ( auto it : screenVector )
        std::cout << it << '\n';


    std::cout << "\033[7;31mbold red text\033[0m\n";

    std::string in; in.resize(20);
    std::cin >> in;
    std::cout << "readed: " << in << '\n';



    return 0;
}
