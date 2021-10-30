#include<iostream>

using namespace std;

struct Node {
    int data;
    struct Node* left, * right;
};

class BST {
public:
    Node* insertData(int, Node* root);	    //Insert a new value into the tree
    Node* deleteData(int, Node* root);	    //Delete a given value from the tree
    void printPreOrder(Node* root);		    //Print the values in the tree using Pre-order
    void printInOrder(Node* root);		    //Print the values in the tree using In-order
    void printPostOrder(Node* root);	    //Print the values in the tree using Post-order
    Node* search(Node* root, int );		    //Search a given value in the tree
    unsigned int countNodes(Node* root);    //Count the number of nodes in the current tree
    int getHeight(Node* root);			    //Get the height of the tree
    int searchMin(Node* root);			    //Find the smallest value in the tree
    int searchMax(Node* root);			    //Find the largest value in the tree
    void deleteTree(Node* root);		    //Delete the entire tree
    Node* findMin(Node* root);			    //Find the minimum value
};

//Insert a new value into the tree
Node* BST::insertData(int value, Node* root) {
    //If the tree is empty
    if (root == NULL) {
        root = new Node;
        root->data = value;
        root->left = root->right = NULL;
    }
        //If the value is less than root node, then it should be in left side
    else if (value < root->data) {
        root->left = insertData(value, root->left);
    }
        //If the value is equal or grater than root node, then it should be in right side
    else {
        root->right = insertData(value, root->right);
    }
    return root;
}

//Delete a given value from the tree
struct Node* BST::deleteData(int value, Node* root) {
    if (root == NULL){
        printf("Tree is Empty\n");
    }
        //If the value is less than root node, then it should be in left side
    else if (value < root->data) {
        root->left = deleteData(value, root->left);
    }
        //If the value is grater than root node, then it should be in right side
    else if (value > root->data) {
        root->right = deleteData(value, root->right);
    }
    else{
        //If No child element exist
        if (root->left == NULL && root->right == NULL) {
            free(root);
            root = NULL;
        }
            //If only one child element exist
        else if (root->left == NULL) {
            Node* temp = root;
            root = root->right;
            free(temp);
        }
        else if (root->right == NULL) {
            Node* temp = root;
            root = root->left;
            free(temp);
        }
            //If two child element exist
        else {
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteData(temp->data, root->right);
        }
    }
    return root;
}

//Print the values in the tree using Pre-order
void BST::printPreOrder(Node* root) {
    Node* temp = root;
    if (root != NULL) {
        cout << temp->data << " ";
        printPreOrder(temp->left);
        printPreOrder(temp->right);
    }
}

//Print the values in the tree using In-order
void BST::printInOrder(Node* root) {
    //If the tree is empty
    if (root == NULL)
        return;
    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);

}

//Print the values in the tree using Post-order
void BST::printPostOrder(Node* root) {
    //If the tree is empty
    if (root == NULL)
        return;
    if (root) {
        printPostOrder(root->left);
        printPostOrder(root->right);
        cout << root->data << " ";
    }
}

//Search a given value in the tree
Node* BST::search( Node* root, int value) {
    //If the tree is empty or the value is present at root
    if (root == NULL || root->data == value)
        return root;

    //If the value is greater than root value
    if (root->data < value)
        return search(root->right, value);

    //If the value is smaller than root value
    return search(root->left, value);
}

//Count the number of nodes in the current tree
unsigned int BST::countNodes(Node* root) {
    unsigned int count = 1;
    if (root->left != NULL) {
        //Get left Element
        count += countNodes(root->left);
    }
    if (root->right != NULL) {
        //Get Right Element
        count += countNodes(root->right);
    }
    return count;
}

//Get height of the tree
int BST::getHeight(Node* root) {
    //If the tree is empty
    if (root == NULL)
        return 0;
    else {
        //Get the height of the left sub tree
        int left = getHeight(root->left);
        //Get the height of the Right sub tree
        int right = getHeight(root->right);
        //Larger one
        if (left >= right)
            return left + 1;
        else
            return right + 1;
    }
}

//Find the Smallest value in the tree
int BST::searchMin(Node* root) {
    //Find the leftmost leaf
    while (root->left != NULL)
        root = root->left;
    return root->data;
}

//Find the Largest value in the tree
int BST::searchMax(Node* root) {
    //Find the rightmost leaf
    while (root->right != NULL)
        root = root->right;
    return root->data;
}

//Delete the entire tree
void BST::deleteTree(Node* root) {
    struct Node* temp = root;
    if (temp == NULL)
        return;
    deleteTree(temp->left);
    deleteTree(temp->right);
    free(temp);
}

//Function to find the minimum value
Node* BST::findMin(Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

int main() {
    BST tree;
    Node* root = NULL;
    int nodes, value, choice;

    cout << "Enter Number of nodes in the Tree : ";
    cin >> nodes;

    //Initializing the tree
    cout << "Enter Elements: \n";
    for (int i = 0; i < nodes; i++) {
        cin >> value;
        root = tree.insertData(value, root);
    }

    while (true) {
        cout << endl;
        cout << " 1 - Insert Node\n";
        cout << " 2 - Delete Node\n";
        cout << " 3 - Print Pre-order\n";
        cout << " 4 - Print In-Order\n";
        cout << " 5 - Print Post-Order\n";
        cout << " 6 - Search a  value\n";
        cout << " 7 - Count no.of Nodes\n";
        cout << " 8 - BST Height\n";
        cout << " 9 - Search Min Value\n";
        cout << " 10- Search Max Value\n";
        cout << " 11- Delete tree\n";
        cout << " 0 - Exit\n";

        cout << "Enter Your Choice : ";
        cin >> choice;
        cout << endl;

        switch (choice) {
            case 1:
                //Insert a new value into the tree
                cout << "Enter the Element to Insert : ";
                cin >> value;
                tree.insertData(value, root);
                break;

            case 2:
                //Delete a given value from the tree
                cout << "Enter Element to Delete : ";
                cin >> value;
                tree.deleteData(value, root);
                break;

            case 3:
                //Print the values in the tree using Pre-order
                cout << "Print Pre-order : ";
                tree.printPreOrder(root);
                break;

            case 4:
                //Print the values in the tree using In-order
                cout << "Print In-order : ";
                tree.printInOrder(root);
                break;

            case 5:
                //Print the values in the tree using Post-order
                cout << "Print Post-Order : ";
                tree.printPostOrder(root);
                break;

            case 6:
                //Search a given value in the tree
                cout << "Enter Element to search : ";
                cin >> value;
                if (tree.search(root, value) != NULL)
                    cout << "Element Found" << endl;
                else
                    cout << "Element Not Found" << endl;
                break;


            case 7://Count the number of nodes in the current tree
                cout << "Number of Nodes : ";
                cout << tree.countNodes(root);
                cout << endl;
                break;

            case 8://Get the height of the tree
                cout << "Height is : ";
                cout << tree.getHeight(root);
                break;

            case 9://Find the smallest value in the tree
                cout << "Minimum Value is : ";
                cout << tree.searchMin(root);
                break;

            case 10://Find the largest value in the tree
                cout << "Maximum Value is :  ";
                cout << tree.searchMax(root);
                break;

            case 11:
                //Delete the entire tree
                cout << "Tree deleted successfully\n";
                tree.deleteTree(root);
                root = NULL;
                break;

            case 0:
                system("pause");
                return 0;

            default:
                cout << "\nInvalid input \n\n";
        }
        cout << endl;
        system("pause");
    }
}