#include <bits/stdc++.h>

using namespace std;

void rotate(vector<string> &cell)
{
    vector<string> temp(cell.size(), string(cell.size(), ' '));
    for (int i = 0; i < cell.size(); i++)
    {
        for (int j = 0; j < cell.size(); j++)
        {
            temp[j][cell.size() - i - 1] = cell[i][j];
        }
    }
    cell = temp;
}

void reflect(vector<string> &cell)
{
    vector<string> temp(cell.size(), string(cell.size(), ' '));
    for (int i = 0; i < cell.size(); i++)
    {
        for (int j = 0; j < cell.size(); j++)
        {
            temp[i][cell.size() - j - 1] = cell[i][j];
        }
    }
    cell = temp;
}

bool compare(vector<string> &cellA, vector<string> &cellB)
{
    for (int i = 0; i < cellA.size(); i++)
    {
        for (int j = 0; j < cellA.size(); j++)
        {
            if (cellA[i][j] != cellB[i][j])
                return false;
        }
    }
    return true;
}

void print(vector<string> &cell)
{
    for (auto &row : cell)
    {
        cout << row << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int s, c{1};
    string rowA, rowB, message;

    while (cin >> s)
    {
        vector<string> cellA, cellB;
        while (s--)
        {
            cin >> rowA >> rowB;
            cellA.push_back(rowA);
            cellB.push_back(rowB);
        }

        message = "improperly transformed";
        for (int i = 0; i <= 3; i++)
        {
            if (compare(cellA, cellB))
            {
                if (i == 0)
                    message = "preserved";
                else
                    message = "rotated " + to_string(i * 90) + " degrees";
                break;
            }
            rotate(cellA);
        }

        cout << "Pattern rotated." << endl;
        print(cellA);
        // print(cellB);

        if (message == "improperly transformed")
        {
            reflect(cellA);
            print(cellA);
            if (compare(cellA, cellB))
                message = "reflected vertically";
            else
            {
                for (int i = 0; i <= 3; i++)
                {
                    if (compare(cellA, cellB))
                    {
                        message = "reflected vertically and rotated " + to_string((i) * 90) + " degrees";
                        break;
                    }
                    rotate(cellA);
                }
            }
        }

        printf("Pattern %d was %s.\n", c++, message.c_str());
        printf("\n");
        print(cellA);
        print(cellB);
    }

    return 0;
}

/*
5
X...X ....X
.X... ...X.
...X. .X...
..X.X ..X..
....X XX..X
6
....XX X....X
...X.. X.X...
XX..X. .X..X.
..X... ...X.X
...X.. ..X...
..X..X ..X...
2
X. X.
.X .X
4
..X. ...X
XX.. ....
.... XX..
...X ..X.
5
X.... .X...
.X... ..X..
.X... ..X..
...X. ....X
....X X....
4
.X.. ..X.
.X.X X...
.... ..XX
..X. ....
2
.. XX
XX ..

Pattern 1 was rotated 90 degrees.
Pattern 2 was rotated 270 degrees.
Pattern 3 was preserved.
Pattern 4 was reflected vertically.
Pattern 5 was improperly transformed.
Pattern 6 was reflected vertically and rotated 270 degrees.
Pattern 7 was rotated 180 degrees.
*/