//Problem: Determine if a king can reach a target position while avoiding a queen's attack lines
//escription: A king needs to move from one position to another on a chessboard without crossing any lines attacked by a queen.

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int ax, ay, bx, by, cx, cy;
    cin >> ax >> ay;  // Queen's position
    cin >> bx >> by;  // King's position
    cin >> cx >> cy;  // Target position
    
    // Check if king and target are in the same quadrant relative to the queen
    bool possible = ((bx > ax && cx > ax) || (bx < ax && cx < ax)) &&
                    ((by > ay && cy > ay) || (by < ay && cy < ay));
    
    cout << (possible ? "YES" : "NO") << endl;
    
    return 0;
}
