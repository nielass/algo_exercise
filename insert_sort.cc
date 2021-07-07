#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void insert_sort(T &v)
{
    for (int i = 1; i < v.size(); ++i)
    {
        auto key = v[i];
        auto j = i - 1;
        while (j > -1 && key > v[j])
        {
            v[j + 1] = v[j];
            j -= 1;
        }
        v[j + 1] = key;
    }
}

int main()
{
    vector<double> vd{1, 2, 3, 213, 321.231, 312, 2.32, 5};
    insert_sort(vd);
    for (auto a : vd)
    {
        cout << a << " ";
    }
    cout << endl;
    return 0;
}