/* Let's try to create the game with 5 disk first */

#include <iostream>
#include <vector>

using namespace std;

int findmostRecentZero(vector<int>);
void moveDisk(vector<int>*, vector<int>*, vector<int>*, char[3]);
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

    char nextMove[3];
    try {
        while (true) {
            // Render game first
            renderGame(bar1, bar2, bar3, sizeBar);
            // Then ask for action
            cout << "What is you next move ? " << endl;
            cin >> nextMove;
            cout << "Your next move: (" << nextMove << ") " << endl;
            // Play action
            moveDisk(&bar1, &bar2, &bar3, nextMove);
            // Check if you wanna stop the game
            if (nextMove[0] == 'x') {
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

int findmostRecentZero(vector<int> vect) {
    for (int i = 0;i < vect.size(); i++) {
        if (vect[i] == 0) return i;
    }
    return -1;
}

void moveDisk(vector<int>* bar1, vector<int>* bar2, vector<int>* bar3, char nextMove[3]) {
    if (nextMove[0] == '1') {
        cout << "TEST 1" << endl;
        int topVector = bar1[0].at(bar1[0].size() - 1);
        if (nextMove[2] == '2') {
            int firstZero = findmostRecentZero(bar2[0]);
            cout << "INDEX FOUND: " << firstZero << endl;
            bar2[0].insert(bar2[0].begin() + firstZero - 1, topVector);
        }
    }
}

void renderGame(vector<int> bar1, vector<int> bar2, vector<int> bar3, int barSize) {
    cout << "Welcome to The Game: \"Tour d'Hanoi\" " << endl;

    for(int i = 0; i < barSize; i++) {
        cout << " || " << bar1[i] << " || " << bar2[i] << " || " << bar3[i] << " || " << endl;
    }
}
