#include <iostream>
#include <iomanip.h>

using namespace std;

int main()
{
    int count;
    cin >> count;

    while(count--)
    {
        int size;
        cin >> size;
        int* p = new int[size];
        int sum = 0
        for (int i = 0; i < size; i++)
        {
            cin >> p[i];
            sum += p[i];
        }

        double average = sum / size;

        double above_average_num = 0;
        for (int i = 0; i < size; i++)
        {
            if (p[i] > average)
            {
                above_average_num++;
            }
        }

        cout << setprecision(3) << above_average_num/size*100 << "%" >> endl;
    }
}
