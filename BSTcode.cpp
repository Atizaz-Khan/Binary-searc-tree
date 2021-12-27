#include<iostream>
#define SPACE 10
using namespace std;

class TreeNode{
	public:
		int value;
		TreeNode* left;
		TreeNode* right;
		
		TreeNode()
		{
			value = 0;
			left =  NULL;
			right = NULL;
		}
		TreeNode(int v)
		{
			value = v;
			left =  NULL;
			right = NULL;
		}
};
class BST{
	public:
		TreeNode* root;
		BST() {
    		root = NULL;
		  }
		bool isEmpty()
		{
			if(root == NULL)
				return true;
			
			else 
				return false;
		}
	void insertNode(TreeNode* new_node) {
		if (root == NULL) {
			root = new_node;
			cout << "Value Inserted as root node!" << endl;
		}
		else {
			TreeNode* temp = root;
			while (temp != NULL) {
				if (new_node->value == temp->value) {
					cout << "Value Already exist," <<
						"Insert another value!" << endl;
					return;
				}
				else if ((new_node->value < temp->value) && (temp->left == NULL)) {
					temp->left = new_node;
					cout << "Value Inserted to the left!" << endl;
					break;
				}
				else if (new_node->value < temp->value) {
					temp = temp->left;
				}
				else if ((new_node->value > temp->value) && (temp->right == NULL)) {
					temp->right = new_node;
					cout << "Value Inserted to the right!" << endl;
					break;
				}
				else {
					temp = temp->right;
				}
			}
		}
	}
	TreeNode * iterativeSearch(int v) {
    if (root == NULL) {
      return root;
    } else {
      TreeNode * temp = root;
      while (temp != NULL) {
        if (v == temp -> value) {
          return temp;
        } else if (v < temp -> value) {
          temp = temp -> left;
        } else {
          temp = temp -> right;
        }
      }
      return NULL;
    }
  }
			
	void print2D(TreeNode * r, int space) 
	{
    	if (r == NULL) 
      	return;
    	space += SPACE; 
    	print2D(r -> right, space);  
    	cout << endl;
    	for (int i = SPACE; i < space; i++) // 5 
    	  cout << " ";  
    	cout << r -> value << "\n"; 
    	print2D(r -> left, space); 
  }
  void printPreorder(TreeNode * r) 
  {
    if (r == NULL)
      return;
    cout << r -> value << " ";
    printPreorder(r -> left);
    printPreorder(r -> right);
  }

  void printInorder(TreeNode * r) 
  {
    if (r == NULL)
      return;
    printInorder(r -> left);
    cout << r -> value << " ";
    printInorder(r -> right);
  }
  void printPostorder(TreeNode * r) 
  {
    if (r == NULL)
      return; 
    printPostorder(r -> left);
    printPostorder(r -> right);
    cout << r -> value << " ";
  }
};
int main()
{
	BST obj;
	int option, val;

  do {
    cout << "What operation do you want to perform? " <<
      " Select Option number. Enter 0 to exit." << endl;
    cout << "1. Insert Node" << endl;
    cout << "2. Search Node" << endl;
    cout << "3. Print/Traversal BST values" << endl;
    cout << "0. Exit Program" << endl;

    cin >> option;
    TreeNode* new_node = new TreeNode();
    switch (option){
    case 0:
      break;
    case 1:
    	cout << "Insert" << endl;
    	cout << "Enter the value of tree node to insert in BST: ";
    	cin >> val;
    	new_node->value = val;
    	obj.insertNode(new_node);
    	cout<<endl;
    	break;
    case 2:
      cout << "SEARCH" << endl;
      cout << "Enter VALUE of TREE NODE to SEARCH in BST: ";
      cin >> val;
      new_node = obj.iterativeSearch(val);
      if (new_node != NULL) {
        cout << "Value found" << endl;
      } else {
        cout << "Value NOT found" << endl;
      }
      break;
	case 3:
		cout << "Print" <<endl;
		obj.print2D(obj.root,5);
		cout << endl;
      	cout <<"PRE-ORDER: ";
        obj.printPreorder(obj.root);
      	cout<<endl;
      	cout <<"IN-ORDER: ";
      	obj.printInorder(obj.root);
      	cout<<endl;
      	cout <<"POST-ORDER: ";
      	obj.printPostorder(obj.root);
		break;
		default:
     	 cout << "Enter Proper Option number " << endl;
		}
		
	}while (option != 0);
	
	return 0;	
}
