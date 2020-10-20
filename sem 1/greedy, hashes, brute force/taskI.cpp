#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
const int SIZE = 4;
bool found = false;
vector<int> bin;
 
bool areEqual(int** ar, int** arr)
{
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (ar[i][j] != arr[i][j])
            {
                return false;
            }
        }
    }
    return true;
}
 
void convert(int n)
{
    int cnt = 0, x = n;
    while (x > 0)
    {
        x /= 2;
        cnt++;
    }
    for (int& i : bin)
    {
        i = 0;
    }
    int ind = 0;
    while (n > 0)
    {
        bin[ind] = n % 2;
        n /= 2;
        ind++;
    }
    reverse(bin.begin(), bin.end());
}
 
void print(int** a)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            std::cout << a[i][j] << " ";
        }
        std::cout << '\n';
    }
}
 
void add(int** product, int** matrix, int i, int j)
{
    for (int k = 0; k < 4; ++k)
    {
        product[i][j] += matrix[i][k] * matrix[k][j];
    }
    product[i][j] %= 2;
}
 
int** multiply(int** matrix, int** product, int num)
{
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            product[i][j] = 0;
        }
    }
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            add(product, matrix, i, j);
        }
    }
    return product;
}
 
void find_sqrt(int** product, int** a, int** matrix, int num)
{
    int** ans = multiply(matrix, product, num);
//    cout << num << endl;
//    print(ans);
//    cout << endl;
    if (areEqual(ans, a))
    {
//        cout << num << '\n';
        print(matrix);
        found = true;
        return;
    }
    num += 1;
    if (num > 65535)
    {
        cout << "NO SOLUTION\n";
        return;
    }
    convert(num);
    int cnt = 0;
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            matrix[i][j] = bin[cnt];
            cnt++;
        }
    }
    find_sqrt(product, a, matrix, num);
}
 
/////////////////////////////
 
//////////////////////////////
 
int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    freopen("sqroot.in", "r", stdin);
    freopen("sqroot.out", "w", stdout);
#endif
    bin.resize(16);
    int** a = new int* [4];
    for (int i = 0; i < 4; ++i)
    {
        a[i] = new int[4];
    }
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            cin >> a[i][j];
        }
    }
    int num = 0;
    int** matrix = new int* [4];
    int** product = new int* [4];
    for (int i = 0; i < 4; ++i)
    {
        matrix[i] = new int[4];
        product[i] = new int[4];
        for (int j = 0; j < 4; ++j)
        {
            matrix[i][j] = 0;
        }
    }
 
    find_sqrt(product, a, matrix, num);
 
//    if (!found)
//    {
//        cout << "NO SOLUTION" << '\n';
//    }
    for (int i = 0; i < 4; ++i)
    {
        delete[] a[i];
        delete[] matrix[i];
        delete[] product[i];
    }
    delete[] a;
    delete[] matrix;
    delete[] product;
 
    return 0;
}