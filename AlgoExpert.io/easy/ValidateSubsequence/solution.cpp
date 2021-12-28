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
