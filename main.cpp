/* Let's try to create the game with 5 disk first */

#include <iostream>
#include <stack>

using namespace std;

void renderGame();

int main()
{
    cout << "Hello world!" << endl;

    stack<int> bar1;
    stack<int> bar2;
    stack<int> bar3;

    /* INIT bar 1*/
    for (int i = 5; i > 0; i--){
        bar1.push(i);
    }

    char nextMove;
    while (true) {
        cout << "Your next move: " << endl;
        cin >> nextMove;
        renderGame();
        // Check if you wanna stop the game
        if (nextMove == 'x') {
            break;
        }
    }

    return 0;
}

void renderGame() {
    cout << "Welcome to The Game: \"Tour d'Hanoi\" " << endl;
}
