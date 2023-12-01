#define TxtIO                         \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>

using namespace std;

struct DimSum
{
    int price;
    int favourIndex;
    vector<int> friendsFavourIndices;
};

int main()
{
    TxtIO;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, x, T, K;
    while (cin >> N >> x >> T >> K and (N or x or T or K))
    {
        int budget = x * (N + 1);

        vector<DimSum> dimSums(K);
        for (int i = 0; i < K; i++)
        {
            cin >> dimSums[i].price >> dimSums[i].favourIndex;
            dimSums[i].friendsFavourIndices.resize(N);
            for (int j = 0; j < N; j++)
            {
                cin >> dimSums[i].friendsFavourIndices[j];
            }
        }

        // Ordenar por favor
        sort(dimSums.begin(), dimSums.end(), [](const DimSum &a, const DimSum &b)
             { return a.favourIndex > b.favourIndex; });

        // Calcular el maximo favor
        int maxTotalFavourValue = 0;
        vector<bool> selected(K, false);
        for (int i = 0; i < K; i++)
        {
            if (selected[i])
                continue;

            int totalFavourValue = 0;
            int numSelected = 0;

            for (int j = i; j < K; j++)
            {
                if (selected[j])
                    continue;

                if (numSelected >= 2 * (N + 1))
                    break;

                int price = dimSums[j].price;
                int favourIndex = dimSums[j].favourIndex;
                int friendsFavourIndexSum = 0;

                for (int k = 0; k < N; k++)
                {
                    friendsFavourIndexSum += dimSums[j].friendsFavourIndices[k];
                }

                int totalFavour = favourIndex + friendsFavourIndexSum;

                if (totalFavour < 0)
                    continue;

                totalFavourValue += totalFavour;
                numSelected++;
                selected[j] = true;
            }

            maxTotalFavourValue = max(maxTotalFavourValue, totalFavourValue);
        }

        double meanFavourValue = (double)maxTotalFavourValue / (N + 1);

        double teaCharge = T;
        double serviceCharge = 0.1 * (maxTotalFavourValue + teaCharge);
        serviceCharge = ceil(serviceCharge);

        double totalPayment = maxTotalFavourValue + teaCharge + serviceCharge;

        std::cout << fixed << setprecision(2) << meanFavourValue << endl;
    }

    return 0;
}
