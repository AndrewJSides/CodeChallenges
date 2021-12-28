# Validate Subsequence
Given two non-empty arrays of ints, this function determines whether the second array is a subsequence of the first.
A subsequence is a set that are in the same order as they appear in the array. They need not be adjacent.

For example, seq is a valid subsequence of array:
```Py
array = [5, 1, 22, 25, 6, -1, 8, 10]
seq = [6, 22, 6, 10]
```


### Recursive Solution (C++)

```cpp
using namespace std;

bool isValidSubsequence(vector<int> array, vector<int> sequence)
{
    // Recursive solution, so if we have eliminated the entire
    //      second sequence, then it is a subsequence of the first.
    if (sequence.size() == 0)
        return true;
    if (array.size() == 0)
        return false;

    // If first values are the same, delete them and repeat
    if (array[0] == sequence[0])
    {
        array.erase(array.begin());
        sequence.erase(sequence.begin());
        return isValidSubsequence(array, sequence);
    }
    // If they aren't the same, delete from the first sequence and continue
    else
    {
        array.erase(array.begin());
        return isValidSubsequence(array, sequence);
    }

    return false;
}
```

### Complexity
O(n) time & O(n) space complexity, where n is the number of items in the first array.