#include <windows.h>
#include <cstdio>
#include <iostream>

#define GAME_WINDOW_SIZE_X 500  // In chars.
#define GAME_WINDOW_SIZE_Y 500  // In chars.

#define GAME_WINDOW_BLOCK_SIZE_X 10  // In chars.
#define GAME_WINDOW_BLOCK_SIZE_Y 10  // In chars.


using namespace std;

class Game
{
public:
    Game()
    {
        set_console();

    }
    void set_console()
    {
        // Create console of size GAME_WINDOW_SIZE_X x GAME_WINDOW_SIZE_Y.
        MoveWindow(GetConsoleWindow(), 0, 0, GAME_WINDOW_SIZE_X, GAME_WINDOW_SIZE_Y, true);
        CONSOLE_FONT_INFOEX cfi;
        cfi.cbSize = sizeof(cfi);
        cfi.nFont = 0;
        cfi.dwFontSize.X = GAME_WINDOW_BLOCK_SIZE_X;  // Width of each character in the font
        cfi.dwFontSize.Y = GAME_WINDOW_BLOCK_SIZE_Y;  // Height
        SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
    }
};