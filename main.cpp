#include <iostream>

using namespace std;

void renderGame();

int main()
{
    cout << "Hello world!" << endl;

    char nextMove;
    while (true) {
        cout << "Your next move: " << endl;
        cin >> nextMove;
        renderGame();
        if (nextMove == 'x') {
            break;
        }
    }

    return 0;
}

void renderGame() {
    cout << "Welcome to The Game: \"Tour d'Hanoi\" " << endl;
}
