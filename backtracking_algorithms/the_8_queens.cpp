#include <iostream>
#include <cmath>

using namespace std;

void simulation(int result[], const int& len)
{
    for(int i = 0; i < len; i++)
    {
        for(int j = 0; j < len; j++)
        {
            if(j == result[i]) cout << "* ";
            else cout << "- ";
        }
        cout << endl;
    }
    cout << endl << endl << endl;
}

void output(int result[], int len)
{
    for(int i = 0; i < len; i++) cout << result[i] << " "; 
    cout << endl;
}

bool isValid(int result[], const int& x, const int& y)
{
    for(int i = 0; i < x-1; i++)
    {
        if(result[i] == y || abs(i-x+1) == abs(result[i]-y+1))
            return false;
    }
    return true;
}

void backTracking(int result[], const int& len, const int& i)
{
    for(int j = 0; j < len; j++)
    {
        if(isValid(result, i, j))
        {
            result[i] = j;
            if(i == len-1) output(result, len);
            backTracking(result, len, i+1);
        }
    }
}

int main()
{
    cout << "Input n of matrix n*n: ";
    int len; cin >> len;
    int result[len];
    backTracking(result, 0, len);

    return 0;
}