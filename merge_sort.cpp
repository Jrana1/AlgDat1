#include "ab.h"
#include <vector>
int main()
{
    vector<A> a;
    a.push_back(A(3, "jewel"));
    a.push_back(A(9, "Rana"));
    for (auto it = a.begin(); it != a.end(); ++it)
    {

        it->display();
    }

    return 0;
}