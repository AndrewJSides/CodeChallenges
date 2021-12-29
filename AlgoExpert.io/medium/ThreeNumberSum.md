# Three Number Sum
This function accepts an array of ints and a single int, which represents a target sum.
The function finds all triplets in the array that sum up to the target int.



### Complexity
O(n<sup>2</sup>) time & O(n) space complexity, where n is the number of items in the array.


### Solution (C++)

Another solution is to sort the array first and then use left/right pointers.

```cpp
using namespace std;

vector<vector<int>> threeNumberSum(vector<int> array, int targetSum) {
	vector<vector<int>> solution;
  // Write your code here.
	for(int i{0}; i < array.size(); ++i) {
		// For each number a:
		map<int,int> bag;
		for(int j{i+1}; j < array.size(); ++j) {
			// For each number b in the subarray [j,n], the corresponding 3rd number c = target - a - b
			// We then add each unique number b and it's corresponding solution c to our map
			// If we come across c later on in the subarray, we'll add a and b and c to the solution vector 
			int t = targetSum - array[i] - array[j];
			if(bag.count(array[j])) {
				vector<int> tmp{array[i], array[j], t};
				sort(tmp.begin(), tmp.end());
				solution.push_back(tmp);
			}
			else {
				bag[t] = array[j];
			}
		}
	}

	// Sort our solution using a lambda function
	sort(solution.begin(), solution.end(),
					 [](const vector<int>& a, const vector<int>& b) -> bool {
				if(a[0] == b[0]) return a[1] < b[1];
				else return a[0] < b[0];
		});

  return solution;
}

```
