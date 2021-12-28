


'''cpp
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
	vector<int> solution;
	if(root->left) {
		for(auto i : branchSums(root->left, sum+root->value)) {
				solution.push_back(i);
		}
	}
	if(root->right) {
			for(auto i : branchSums(root->right, sum+root->value)) {
				solution.push_back(i);
		}
	}
	else if(!root->left && !root->right) {
		solution.push_back(sum+root->value);
	  return solution;
	}
	return solution;
}
'''