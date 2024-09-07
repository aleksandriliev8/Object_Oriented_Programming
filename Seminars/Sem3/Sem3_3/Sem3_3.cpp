#include <iostream>
#include <fstream>

void replaceSymbol(std::fstream& file, char oldCh, char newCh) {

    while (!file.eof()) {
        char currentCh = file.get();

        if (currentCh == oldCh) {
            file.seekp(-1, std::ios::cur);
            file.put(newCh);
            file.flush();
        }
    }
}

int main()
{
    std::fstream textMassage("textMessage.txt", std::ios::in | std::ios::out);

    if (!textMassage.is_open()) {
        std::cout << "Couldn't open the file!" << std::endl;
        return -1;
    }

    replaceSymbol(textMassage, 'a', 'x');

    textMassage.close();

    return 0;
}
