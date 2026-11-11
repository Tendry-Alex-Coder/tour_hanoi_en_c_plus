/* Let's try to create the game with 5 disk first */

#include <iostream>
#include <vector>

using namespace std;

void renderGame(vector<int>, vector<int>, vector<int>, int);

int main()
{
    cout << "Hello world!" << endl;

    int sizeBar = 5;

    vector<int> bar1;
    vector<int> bar2;
    vector<int> bar3;

    /* INIT bars*/
    for (int i = sizeBar; i > 0; i--){
        bar1.push_back(i);
        bar2.push_back(0);
        bar3.push_back(0);
    }

    char nextMove;
    try {
        while (true) {
            cout << "Your next move: " << endl;
            cin >> nextMove;
            renderGame(bar1, bar2, bar3, sizeBar);
            // Check if you wanna stop the game
            if (nextMove == 'x') {
                cout << endl << " -- GAME TERMINATED --" << endl;
                break;
            }
        }
    }
    catch (const char* mess) {
        cout << " ERREUR " << mess;
    }

    return 0;
}

void renderGame(vector<int> bar1, vector<int> bar2, vector<int> bar3, int barSize) {
    cout << "Welcome to The Game: \"Tour d'Hanoi\" " << endl;

    for(int i = 0; i < barSize; i++) {
        cout << " || " << bar1[i] << " || " << bar2[i] << " || " << bar3[i] << " || " << endl;
    }
}
