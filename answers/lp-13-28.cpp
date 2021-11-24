// 18/03/04 = Sun

// Exercise 13.28: Given the following classes, implement a default constructor and the necessary copy-control members.

// class TreeNode {
// private:
// 	std::string value;
// 	int         count;
// 	TreeNode    *left;
// 	TreeNode    *right;
// };

// class BinStrTree {
// private:
// 	TreeNode *root;
// };

// Note:
// 1. Pointer-like copy for TreeNode
// 2. copy and assignment forbidden for BinStrTree
// 3. BinStrTree must have at least one node (root cannot be nullptr)

#include <iostream>
#include <string>

using namespace std;

class TreeNode
{
	size_t	 *	use;
	string 		value;
	int 		count;
	TreeNode * 	left;
	TreeNode * 	right;
public:
	TreeNode() : use(new size_t(1)), count(0),
				 left(nullptr), right(nullptr)
	{
		clog << "TreeNode()" << endl;
	}
	TreeNode(const TreeNode & o): use(o.use), value(o.value), count(o.count),
								  left(o.left), right(o.right)
	{
		++*use;
		clog << "TreeNode(const TreeNode & o)" << endl;
	}
	TreeNode & operator=(const TreeNode & o)
	{
		++*o.use;
		--*use;
		if (*use == 0) {
			if (left)			// cannot delete a nullptr
				delete left;
			if (right)			// cannot delete a nullptr
				delete right;
			delete use;
		}
		use = o.use;
		value = o.value;
		value = o.count;
		left = o.left;
		right = o.right;
		clog << "TreeNode & operator=(const TreeNode & o)" << endl;
		return *this;
	}
	~TreeNode()
	{
		clog << "~TreeNode()" << endl;
		--*use;
		if (*use == 0) {
			if (left)			// cannot delete a nullptr
				delete left;
			if (right)			// cannot delete a nullptr
				delete right;
			delete use;
			clog << "~TreeNode() real delete" << endl;
		}
	}
};

class BinStrTree
{
	TreeNode * 	root;
public:
	// provide a default argument: root cannot be nullptr
	BinStrTree(TreeNode * root = new TreeNode()) : root(root)
	{
		clog << "BinStrTree(TreeNode * root = new TreeNode())" << endl;
	}
	BinStrTree(const BinStrTree & o) = delete;				// no copy
	BinStrTree & operator=(const BinStrTree & o) = delete;	// no assign
	~BinStrTree()
	{
		clog << "~BinStrTree()" << endl;
		delete root;
	}
};

int main()
{
	{
		TreeNode n1;
		cout << string(50, '-') << endl;
		TreeNode n2 = n1;
		cout << string(50, '-') << endl;
	}
	cout << string(50, '-') << endl;
	BinStrTree tree;
	cout << string(50, '-') << endl;
	return 0;
}