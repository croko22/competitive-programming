#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, c{0};
    string road;
    cin >> t;

    while (t--)
    {
        cin >> road;
        int n = 0;
        for (int i = 0; i < road.size(); i++)
        {
            bool valid = 0;
            if (road[i] == '-')
            {
                valid = 1;
                if (road[i + 1] == 'B' || road[i + 2] == 'B' || road[i - 1] == 'S' || road[i + 1] == 'S')
                    valid = 0;
            }
            if (valid)
                n++;
        }
        cout << "Case " << ++c << ": " << n << "\n";
    }

    return 0;
}

//? Input
/*
2
---B--S-D--S--
DDBDDBDDBDD
*/