#include <bits/stdc++.h>
#define TxtIO                         \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
using namespace std;
int N, M;

bool sortbyMod(int x, int y)
{
    if (x % M == y % M)
    {
        if (x % 2 == 0 && y % 2 != 0)
        {
            return false;
        }
        else if (x % 2 != 0 && y % 2 == 0)
        {
            return true;
        }
        else if (x % 2 != 0 && y % 2 != 0)
        {
            return x > y;
        }
        else
        {
            return x < y;
        }
    }
    else
        return x % M < y % M;
}

int main()
{
    TxtIO;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    vector<int> v;

    while (cin >> N >> M, N > 0)
    {
        v.clear();
        cout << N << " " << M << "\n";
        for (int i = 0; i < N; i++)
        {
            cin >> n;
            v.push_back(n);
        }

        sort(v.begin(), v.end(), sortbyMod);

        for (int i : v)
            cout << i << "\n";
    }
    cout << "0 0";
    return 0;
}