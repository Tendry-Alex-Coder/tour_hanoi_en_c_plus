/* Let's try to create the game with 5 disk first */

#include <iostream>
#include <vector>

using namespace std;

int sizeBar = 5; // Nombre de disques

bool checkBarAligned(vector<int>);
int findmostRecentZero(vector<int>);
int findmostLastInValue(vector<int>);
void moveDisk(vector<int>*, vector<int>*, vector<int>*, char[3]);
void renderGame(vector<int>, vector<int>, vector<int>, int);

int main()
{
    cout << "Hello world!" << endl;

    vector<int> bar1;
    vector<int> bar2;
    vector<int> bar3;

    /* INIT bars*/
    for (int i = sizeBar; i > 0; i--){
        bar1.push_back(i);
        bar2.push_back(0);
        bar3.push_back(0);
    }

    char nextMove[4];
    try {
        while (true) {
            // Render game first
            renderGame(bar1, bar2, bar3, sizeBar);
            // Check if win on bar 2 and 3
            if (checkBarAligned(bar2) || checkBarAligned(bar3)) {
                cout << "GAME FINISHED ! YOU WON" << endl;
                break;
            }
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

// Inspiration from TRI algorithm
bool checkBarAligned(vector<int> vect) {
    bool result = true;
    for (int i = 0; i < vect.size(); i++) {
        if (vect[0] < vect[i] || vect[i] == '0' || vect[i] == 0) return false;
    }
    return result;
}

int findmostRecentZero(vector<int> vect) {
    for (int i = 0;i < vect.size(); i++) {
        if (vect[i] == 0) return i;
    }
    return -1;
}

int findmostLastInValue(vector<int> vect) {
    if (vect.back() > 0) return vect.size() - 1;

    int indexMax = vect.size() - 1;
    for (int i = vect.size() - 1; i >= 0; i--) {
        if (vect[i] > 0) {
            return i;
        };
        indexMax = i;
    }
    return indexMax;
}

void moveDisk(vector<int>* bar1, vector<int>* bar2, vector<int>* bar3, char nextMove[3]) {
    // MOVE FROM BAR 1
    if (nextMove[0] == '1') {
        int topVector = findmostLastInValue(bar1[0]);
        int topValueVector = bar1[0][topVector];
        if (nextMove[2] == '2') {
            int firstZero = findmostRecentZero(bar2[0]);
            bar2[0][firstZero] = topValueVector;
            bar1[0][topVector] = 0;
        }
        if (nextMove[2] == '3') {
            int firstZero = findmostRecentZero(bar3[0]);
            bar3[0][firstZero] = topValueVector;
            bar1[0][topVector] = 0;
        }
    }
    // MOVE FROM BAR 2
    if (nextMove[0] == '2') {
        int topVector = findmostLastInValue(bar2[0]);
        int topValueVector = bar2[0][topVector];
        if (nextMove[2] == '1') {
            int firstZero = findmostRecentZero(bar1[0]);
            bar1[0][firstZero] = topValueVector;
            bar2[0][topVector] = 0;
        }
        if (nextMove[2] == '3') {
            int firstZero = findmostRecentZero(bar3[0]);
            bar3[0][firstZero] = topValueVector;
            bar2[0][topVector] = 0;
        }
    }
    // MOVE FROM BAR 3
    if (nextMove[0] == '3') {
        int topVector = findmostLastInValue(bar3[0]);
        int topValueVector = bar3[0][topVector];
        if (nextMove[2] == '1') {
            int firstZero = findmostRecentZero(bar1[0]);
            bar1[0][firstZero] = topValueVector;
            bar3[0][topVector] = 0;
        }
        if (nextMove[2] == '2') {
            int firstZero = findmostRecentZero(bar2[0]);
            bar2[0][firstZero] = topValueVector;
            bar3[0][topVector] = 0;
        }
    }
}

void renderGame(vector<int> bar1, vector<int> bar2, vector<int> bar3, int barSize) {
    cout << "Welcome to The Game: \"Tour d'Hanoi\" " << endl;

    for(int i = barSize - 1; i >= 0; i--) {
        cout << " || " << bar1[i] << " || " << bar2[i] << " || " << bar3[i] << " || " << endl;
    }
}
