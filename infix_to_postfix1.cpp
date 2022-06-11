#include <iostream>
using namespace std;
#include <vector>
class Pair
{
private:
    char ch;
    int key;

public:
    Pair(){};
    Pair(char ch, int key)
    {
        this->ch = ch;
        this->key = key;
    }
    void setCh(char ch) { this->ch = ch; }
    void setKey(char key) { this->key = key; }
    char getCh() { return this->ch; }
    int getKey() { return this->key; }
    void display()
    {
        cout << "( " << this->ch << "," << this->key << " )" << endl;
    }
};

int main()
{
    vector<Pair> pairs = {{'+', 1}, {'-', 1}, {'*', 4}, {'/', 4}, {'^', 6}, {'(', 1}, {')', 0}};
    for (int i = 0; i < pairs.size(); i++)
    {
        pairs[i].display();
    }

    return 0;
}