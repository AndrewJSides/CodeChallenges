
# Move Element To End
Given an array of integers and a single integer, this function moves all instance of that integer in the array to the end.
This should be performed in place.

### Solution (c++)

```cpp
#include <vector>

using namespace std;

vector<int> moveElementToEnd(vector<int> array, int toMove) {
	if(array.size() < 2) return array;
	int left = 0;
	int right = array.size()-1;
	while(left < right) {
		// Decrement the right pointer until it is a non-target int
		while(array[right] == toMove && right > left) --right;

		// If the left pointer is on a target, swap it with the int at the right pointer and increment the left pointer
		if(array[left] == toMove) {
			int tmp = array[right];
			array[right] = array[left];
			array[left] = tmp;
			--right;
		}
		++left;
	}

	return array;
}
```