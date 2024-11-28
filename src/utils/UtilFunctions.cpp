#include <iostream>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include<array> 

#include "UtilFunctions.h"

#define KEY_UP 65    
#define KEY_DOWN 66  
#define KEY_ENTER 10   

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

char getch() {
    char buf = 0;
    struct termios old = {0};
    if (tcgetattr(0, &old) < 0)
        perror("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if (tcsetattr(0, TCSANOW, &old) < 0)
        perror("tcsetattr ICANON");
    if (read(0, &buf, 1) < 0)
        perror("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if (tcsetattr(0, TCSADRAIN, &old) < 0)
        perror("tcsetattr ~ICANON");
    return buf;
}

std::string selectionMenu(std::string prompt, char* options[], int numChoices) {
    int selected = 0;
    bool selecting = true;

    while (selecting) {
        clearScreen();
        std::cout << prompt << std::endl;
        for (int i = 0; i < numChoices; ++i) {
            if (i == selected) {
                std::cout << "> " << options[i] << std::endl;
            } else {
                std::cout << "  " << options[i] << std::endl;
            }
        }

        char c = getch();
        if (c == '\033') { // if the first value is esc
            getch(); // skip the [
            switch (getch()) { // the real value
                case KEY_UP:
                    if (selected > 0) {
                        --selected;
                    }
                    break;
                case KEY_DOWN:
                    if (selected < numChoices - 1) {
                        ++selected;
                    }
                    break;
            }
        } else if (c == KEY_ENTER) {
            selecting = false;
        }
    }

    std::cout << "Selected: " << options[selected] << std::endl;
    return options[selected];
}