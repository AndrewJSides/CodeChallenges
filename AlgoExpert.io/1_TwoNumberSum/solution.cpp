
#include <vector>
#include <map>
using namespace std;

vector<int> twoNumberSum(vector<int> array, int targetSum)
{
    // Create hash map for unique numbers we've already seen
    map<int, int> uniqueNums;
    // for each number num in array:
    for (auto i : array)
    {
        // if we've seen it, return the number and the second number
        if (uniqueNums.find(targetSum - i) != uniqueNums.end())
            return {i, targetSum - i};
        // otherwise add the number to our list
        uniqueNums[i] = i;
    }
    return {};
}
