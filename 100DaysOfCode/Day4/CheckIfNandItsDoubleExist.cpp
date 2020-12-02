#include "cc.h"

class Solution
{
public:
    bool checkIfExist(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        // printVector(arr);
        bool found = false;

        for (int i = 0; i < arr.size(); i++)
        {
            if (binary_search(arr.begin(), arr.end(), arr[i] * 2))
            {
                // cout << arr[i] << " ";

                // auto it = lower_bound(arr.begin(), arr.end(), arr[i] * 2);
                auto it1 = lower_bound(arr.begin(), arr.begin()+ i , arr[i] * 2);
                auto it2 = lower_bound(arr.begin()+i , arr.end(), arr[i] * 2);


                if (it1 != it2){

                found = true;
                }

            }
        }

        return found;
    }
};

int main()
{
    setup();
    Solution a;
    vector<int> vec{-10, 12, -20, -8, 15};
    cout << a.checkIfExist(vec) << endl;
    return 0;
}