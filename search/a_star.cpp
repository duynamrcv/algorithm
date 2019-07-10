#include <iostream>
#include <stack>
#include <cmath>
#include <cstring>
#include <cfloat>
#include <set>

#define ROW 9
#define COL 10

using namespace std;

// create a shortcut for int, int pair type
typedef pair<int, int> Pair;

// create a shortcut for pair<float, pair<int, int>> type
typedef pair<float, pair<int, int>> pPair;

// struct to hold the neccesary params
struct cell
{
    // row and column index of its parent
    // 0 <= i < ROL & 0 <= j < COL
    int parent_i, parent_j;

    // f = g + h
    float f, g, h;
};

// check whether given cell(row, col) is valid
bool isValid(int row, int col)
{
    return row >= 0 && row < ROW && col >= 0 && col < COL;
}

// check whether given cell is blocked
bool isUnBlocked(int grid[][COL], int row, int col)
{
    if(grid[row][col] == 1) return true;
    else return false;
}

// check whether destination cell has been reached
bool isDestination(int row, int col, Pair dest)
{
    if(row == dest.first && col == dest.second) return true;
    else return false;
}

// calcultate 'h' heuristics
float calculateHValue(int row, int col, Pair dest)
{
    // distance
    return sqrt(pow(row-dest.first, 2) + pow(col-dest.second, 2));
}

// trace the path from source to destination
void tracePath(cell cellDetails[][COL], Pair dest)
{
    cout << "the path is ";
    int row = dest.first;
    int col = dest.second;

    stack<Pair> Path;

    while(!(cellDetails[row][col].parent_i == row && cellDetails[row][col].parent_j == col))
    {
        Path.push(make_pair(row, col));
        int temp_row = cellDetails[row][col].parent_i;
        int temp_col = cellDetails[row][col].parent_j;

        row = temp_row;
        col = temp_col;
    }

    Path.push(make_pair(row, col));
    while(!Path.empty())
    {
        pair<int, int> p = Path.top();
        Path.pop();
        cout << "-> (" << p.first << " " << p.second << ") ";
    }
    return;
}

// find the shortest path
void aStarSearch(int grid[][COL], Pair src, Pair dest)
{
    // if the source is out of range
    if(!isValid(src.first, src.second))
    {
        cout << "source is invalid\n";
        return;
    }

    //if the destination is out of range
    if(!isValid(dest.first, dest.second))
    {
        cout << "destination is invalid\n";
        return;
    }

    // either the source or the destination is blocked
    if(!isUnBlocked(grid, src.first, src.second) || !isUnBlocked(grid, dest.first, dest.second))
    {
        cout << "source or destination is blocked\n";
        return;
    }

    // if the destination cell is the same as source cell
    if(isDestination(src.first, src.second, dest))
    {
        cout << "realdy at the destination\n";
        return;
    }

    // create a closed boolean 2D list and initialise it to false
    // which means that mo cell has been included yet    
    bool closedList[ROW][COL];
    memset(closedList, false, sizeof(closedList));

    // declare a 2D array to hold the details of that cell
    cell cellDetails[ROW][COL];

    int i, j;

    for(i = 0; i < ROW; i++)
    {
        for(j = 0; j < COL; j++)
        {
            cellDetails[i][j].f = FLT_MAX;
            cellDetails[i][j].g = FLT_MAX;
            cellDetails[i][j].h = FLT_MAX;
            cellDetails[i][j].parent_i = -1;
            cellDetails[i][j].parent_j = -1;
        }
    }

    // initialising the params of the start node
    i = src.first, j = src.second;
    cellDetails[i][j].f = 0;
    cellDetails[i][j].g = 0;
    cellDetails[i][j].h = 0;
    cellDetails[i][j].parent_i = i;
    cellDetails[i][j].parent_j = j;

    // create list <f, <i, j>> where f = g + h;
    set<pPair> openList;

    // put the starting sell on the open list and its 'f'  as 0
    openList.insert(make_pair(0.0, make_pair(i, j)));

    // set this boolean value as false as initially the destination is not reach
    bool foundDest = false;

    while (!openList.empty())
    {
        pPair p = *openList.begin();

        //remove this vertex from the open list
        openList.erase(openList.begin());

        // add this vertex to the closed list
        i = p.second.first;
        j = p.second.second;
        closedList[i][j] = true;

        // generating all the 8 successor of this cell
        // NW     N     NE
        // W    Cell    E
        // SW     S     SE

        // (i-1, j-1)  (i-1, j)     (i-1, j+1)
        // (i, j-1)     (i, j)      (i, j+1)
        // (i+1, j-1)   (i+1, j)    (i+1, j+1)

        // to store the 'g', 'h'. 'f' of 8 successors
        double g_new, h_new, f_new;

        
    }
    
}

int main()
{
    return 0;
}