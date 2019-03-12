#include <iostream>
#include <vector>
#include <map>

using namespace std;

template <typename T>
T Sqr(T &t)
{
    return t * t;
}

template <typename T>
vector<T> Sqr(vector<T> &v)
{
     for (unsigned int i = 0; i < v.size(); i++)
         v[i] *= v[i];
     return v;
}

template <typename T>
pair <T, T> Sqr(pair<T, T> &p)
{
    p.first *= p.first;
    p.second *= p.second;
    return p;
}

template <typename T, typename Container>
map<T, Container> Sqr(map<T, Container> &m)
{
    for(auto &i : m)
    {
        i.second = Sqr(i.second);
    }
    return m;
}


int main()
{
    vector<int> v = {1, 2, 3};
    cout << "vector:";
    for (int x : Sqr(v)) {
      cout << ' ' << x;
    }
    cout << endl;

    map<int, pair<int, int>> map_of_pairs = {
      {4, {2, 2}},
      {7, {4, 3}}
    };
    cout << "map of pairs:" << endl;
    for (const auto& x : Sqr(map_of_pairs)) {
      cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
    }
    return 0;
}
