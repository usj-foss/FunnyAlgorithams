#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> &array, int lower_bound, int upper_bound, int key)
{
    if (upper_bound >= lower_bound)
    {
        int pos = (upper_bound - lower_bound)/2;
        int middle = lower_bound + pos;

        if (array[middle] == key)
            return middle;

        if (array[middle] > key)
            return binarySearch(array, lower_bound, middle - 1, key);

        return binarySearch(array, middle + 1, upper_bound, key);
    }
    return -1;
}

int main()
{
    vector<int> array = {2, 3, 4, 10, 40};
    int key = 10;
    int result = binarySearch(array, 0, array.size() - 1, key);
    cout<<((result == -1) ? "Element is not present in array" : "Element is present at index "+to_string(result))
    <<endl;
    return 0;
}
