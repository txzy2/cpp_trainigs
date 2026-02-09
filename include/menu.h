#include <functional>
#include <vector>
#include <string>
#include "../utils/reader.h"

class Menu
{
public:
    bool running = true;
    void getMenu();
    void handleMenuChoice(int choice);

    bool isRunning() const
    {
        return running;
    }

private:
    IoReader reader;

    void add();
    void mathMultiplication();
    void mathDivision();
    void mathSubtraction();

    void exit();

    struct MenuItem
    {
        std::string title;
        std::function<void()> action;
    };

    std::vector<MenuItem> menuItems;
    void initMenu();
    void arraysMenu();

    struct Params
    {
        float first;
        float second;
    };
    Params readLine();
};
