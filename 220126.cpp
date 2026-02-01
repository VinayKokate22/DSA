// kind of brute forces 
// sorry aboout 23 01 
// sorry aboout 26 01 
// could not solve 280126
// simple problem using graph logic

// giving oly tle

#include <bits/stdc++.h>
using namespace std;

int main() {
    // const long long MAX_POINTS = (1LL << 25); // 2^20
    long long capital =(1LL << 20);   // start with 1 point
    cout<<capital<<endl;
    long long bet = 1;
    long long round = 0;
    long long maxv=0;
    srand(time(0));
    
    while (capital > 0 ) {
        round++;
        int random_number = rand() % 100 + 1; // 1 to 100

        // cout << "Round " << round
        //      << " | Bet: " << bet
        //      << " | Capital before: " << capital
        //      << " | Random: " << random_number;

        if (random_number > 50) {
            // Win
            capital += bet;
            // cout << " -> WIN";
            bet = 1; // reset after win
        } else {
            // Loss
            capital -= bet;
            // cout << " -> LOSS";
            bet *= 2; // double after loss
            maxv=max(bet,maxv);
            if (bet > capital) {
                cout << "\nCannot double further. Game Over.";
                break;
            }
        }

        // cout << " | Capital after: " << capital << "\n";
        if(round>20*1e5)break;
    }

    cout<<maxv<<endl;
    if (capital)
    // cout << "Reached maximum limit (2^20).\n";
    cout << "\nFinal Capital: " << capital << endl;
    else
        cout << "Lost all points.\n";

    return 0;
}
// you will lose 