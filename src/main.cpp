#include <iostream>

#include "../include/menu.h"
#include "../include/math.h"
#include "../utils/reader.h"

int main()
{
    std::cout << "Hello world! It's a simple calculator application." << std::endl;

    Menu menu;
    menu.getMenu();

    while (menu.isRunning())
    {
        IoReader reader;
        float menuChoice = reader.readLine("menu choice");
        std::cout << "Your choice: " << menuChoice << std::endl;
        menu.handleMenuChoice(menuChoice);
    }
}
