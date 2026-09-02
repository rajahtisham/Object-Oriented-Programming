#include<iostream>
#include<string>
using namespace std;
class Distance
{
private:
    int feet;
    int inches;
public:`	

    Distance(int f, int i)
    {
    feet = f;
    inches = i;
    }

    bool operator == (Distance d)
    {
    if(feet == d.feet && inches == d.inches)
    {
            return true;
        }
        return false;
    }
};

int main()
{
    Distance d1(5, 8);
    Distance d2(5, 8);

    if(d1 == d2)
    {
    cout << "Distances are Equal";
    }
    else
    {
    cout<<"Distances are Not Equal";
    }
   return 0;
}
