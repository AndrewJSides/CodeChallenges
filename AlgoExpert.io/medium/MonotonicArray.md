
# Monotonic Array
This function takes an array of ints and returns a bool representing whether or not the array is monotonic.
An array is monotonic if it's elements, from left to right, are entirely non-increasing or non-decreasing.

### Solution (c++)

```cpp
using namespace std;

bool isMonotonic(vector<int> array) {
	if (array.size() < 2) return true;
	int difference = 0;
	int index = 1;

	// Starting at index 0, increase our pointer until it increases or decreases
	while(array[index] - array[index-1] == 0) {
		++index;
	}
	
	// If it increased, we only need to check that it always increases
	if(array[index] - array[index-1] > 0) {
		for(index; index < array.size(); ++index) {
			if(array[index] - array[index-1] < 0) return false;
		}		
	}

	// Opposite if it decreased
	else {
		for(index; index < array.size(); ++index) {
			if(array[index] - array[index-1] > 0) return false;
		}				
	}
		
  return true;
}
```