#include <bits/stdc++.h>
#define TxtIO                         \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
using namespace std;

int inv{0};
void merge(int A[], int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
    {
        L[i] = A[p + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = A[q + j + 1];
    }
    int i = 0, j = 0, k = p;
    while (i < n1 && j < n2 && k < 100000)
    {
        if (L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
            inv += n1 - i;
        }
        k++;
    }
    while (i < n1)
    {
        A[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        A[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int A[], int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        mergeSort(A, p, q);
        mergeSort(A, q + 1, r);
        merge(A, p, q, r);
    }
}

int main()
{
    // TxtIO;
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int A[100000];

    while (cin >> n, n > 0)
    {
        inv = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        mergeSort(A, 0, n - 1);
        cout << inv << "\n";
    }

    return 0;
}