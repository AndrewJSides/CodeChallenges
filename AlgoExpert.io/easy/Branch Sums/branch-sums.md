# Branch Sums
This function accepts a binary tree as input and returns a list of its branch sums
ordered from the leftmost branch sum to the rightmost branch sum.

A branch sum is the sum of all values in that branch.

A branch is a path of nodes from the root node to a leaf node. 


### Recursive Approach (C++)
```cpp
using namespace std;

// This is the class of the input root. Do not edit it.
class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value) {
    this->value = value;
    left = nullptr;
    right = nullptr;
  }
};

vector<int> branchSums(BinaryTree* root, int sum=0) {
	// My code starts here
	vector<int> solution;

	// If the current node has a left node, we make a recursive call on the left node
	//	 and pass in the current sum + the current node's value.
	// If the current node has a right node, we make the same call on the right node.
	// When we reach a leaf node, the branch sum at that leaf will be returned by each
	//	 recursive call and passed down the stack to the root function call where
	//	 we will add it to the solution array.
	if(root->left) {
		for(int i : branchSums(root->left, sum + root->value)) {
				solution.push_back(i);
		}
	}
	if(root->right) {
			for(int i : branchSums(root->right, sum + root->value)) {
				solution.push_back(i);
		}
	}
	else if(!root->left && !root->right) {
		solution.push_back(sum + root->value);
	  return solution;
	}
	return solution;
}
```

### Complexity
O(n) time & O(n) space complexity, where n is the number of nodes in the input tree.