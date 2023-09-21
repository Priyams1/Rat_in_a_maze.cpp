#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool isSafe(int **arr, int x, int y, int n)
{
    if (x >= 0 && y >= 0 && x < n && y < n && arr[x][y] == 1)
    {
        return true;
    }
    return false;
}

bool ratMaze(int **arr, int x, int y, int n, int **solnarr)
{
    if (x == n - 1 && y == n - 1)
    {
        solnarr[x][y] = 1;
        return true;
    }
    if (isSafe(arr, x, y, n))
    {
        solnarr[x][y] = 1;
        if (ratMaze(arr, x + 1, y, n, solnarr))
        {
            return true;
        }
        if (ratMaze(arr, x, y + 1, n, solnarr))
        {
            return true;
        }
        else
        {
            solnarr[x][y] = 0; // backtracking
            return false;
        }
    }
    return false;
}

int main()
{
    int n;
    cin >> n;

    int **arr = new int *[n]; // dynamic memory allocation

    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    int **solnarr = new int *[n]; // dynamic memory allocation

    for (int i = 0; i < n; i++)
    {
        solnarr[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            solnarr[i][j] = 0;
        }
    }

    cout << endl
         << endl;

    if (ratMaze(arr, 0, 0, n, solnarr))
    {

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << solnarr[i][j] << " ";
            }
            cout << endl;
        }
    }
    for (int i = 0; i < n; i++)
    {
        delete[] arr[i];
        delete[] solnarr[i];
    }
    delete[] arr;
    delete[] solnarr;

    return 0;
}