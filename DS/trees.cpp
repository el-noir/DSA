#include <iostream>
using namespace std;

// Node class for binary tree
class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int d) {
        data = d;
        left = nullptr;
        right = nullptr;
    }
};

// Node class for the linked list used in Queue
class Node {
public:
    TreeNode* data;   // store pointer to TreeNode instead of int
    Node* next;

    Node(TreeNode* d) {
        data = d;
        next = nullptr;
    }
};

// Queue class to handle level order traversal
class Queue {
    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    void enqueue(TreeNode* d) {
        Node* temp = new Node(d);
        if (isEmpty()) {
            front = temp;
            rear = temp;
        }
        else {
            rear->next = temp;
            rear = temp;
        }
    }

    TreeNode* dequeue() {
        if (isEmpty()) {
            cout << "Underflow of Queue.";
            return nullptr;
        }
        Node* temp = front;
        TreeNode* result = temp->data;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
        return result;
    }

    bool isEmpty() {
        return (front == nullptr);
    }
};

//// Function to perform level order traversal of the binary tree
//void levelOrder(TreeNode* root) {
//
//    if (root == NULL) {
//        return;
//    }
//
//    Queue q;
//    q.enqueue(root);
//    q.enqueue(nullptr); // Mark the end of the first level
//
//    while (!q.isEmpty()) {
//        TreeNode* temp = q.dequeue();
//
//        if (temp == nullptr) { // End of the current level
//            cout << endl;
//            if (!q.isEmpty()) {
//                q.enqueue(nullptr); // Mark the end of the next level
//            }
//        }
//        else {
//            cout << temp->data << " ";
//            if (temp->left != nullptr) {
//                q.enqueue(temp->left);
//            }
//            if (temp->right != nullptr) {
//                q.enqueue(temp->right);
//            }
//        }
//    }
//}
//
//void inOrder(TreeNode* root) {
//    if (root == NULL) {
//        return;
//    }
//
//    inOrder(root->left);
//    cout << root->data << " ";
//    inOrder(root->right);
//}
//
//void preOrder(TreeNode* root) {
//    if (root == NULL) {
//        return;
//    }
//    cout << root->data << " ";
//    preOrder(root->left);
//    preOrder(root->right);
//}
//
//void postOrder(TreeNode* root) {
//    if (root == NULL) {
//        return;
//    }
//    postOrder(root->left);
//    postOrder(root->right);
//    cout << root->data << " ";
//}
//
//TreeNode* insert(TreeNode* root, int d) {
//    if (root == NULL) {
//        return new TreeNode(d);
//    }
//    if (d < root->data) {
//        root->left= insert(root->left, d);
//    }
//    else {
//        root->right = insert(root->right, d);
//    }
//    return root;
//}
//
////void createTree(TreeNode* root) {
////
////    int data;
////    cout << "Data for : "; 
////    cin >> data;
////
////
////
////    TreeNode* temp = new TreeNode(data);
////
////    if (data == -1) {
////        return;
////    }
////
////    cout << "Data after : " << data;
////    root->left = createTree(root->left);
////    cout << "Data after : " << data;
////    root->right = createTree(root->right);
////    
////
////
////}
//
//
//int main() {
//    // Create a simple binary tree
//    //TreeNode* root = new TreeNode(1);
//    //root->left = new TreeNode(2);
//    //root->right = new TreeNode(3);
//
//    //root->left->left = new TreeNode(4);
//    //root->left->right = new TreeNode(5);
//    //root->right->left = new TreeNode(6);
//    //root->right->right = new TreeNode(7); // Changed from 6 to 7 to make nodes unique
//
//    // Expanding the tree further
//    //root->left->left->left = new TreeNode(8);
//    //root->left->left->right = new TreeNode(9);
//    //root->left->right->left = new TreeNode(10);
//    //root->left->right->right = new TreeNode(11);
//
//    //root->right->left->left = new TreeNode(12);
//    //root->right->left->right = new TreeNode(13);
//    //root->right->right->left = new TreeNode(14);
//    //root->right->right->right = new TreeNode(15);
//
//    //cout << "Level Order Traversal:" << endl;
//    //levelOrder(root);
//    //cout << endl; // Ensure a newline after the traversal output
//    //cout << endl;
//
//    //inOrder(root);
//    //cout << "\n";
//    //preOrder(root);
//    //cout << "\n";
//    //postOrder(root);
//
//    //return 0;
//
//   
//
//    TreeNode* root = nullptr;
//    int values[] = { 50, 30, 20, 40, 70, 60, 80 };
//
//    // Insert values into the BST
//    for (int value : values) {
//        root = insert(root, value);
//    }
//
//    // Display the tree in sorted order
//    std::cout << "In-order traversal of BST: ";
//    inOrder(root);
//    std::cout << std::endl;
//
//    return 0;
//
//
//}








//#include <iostream>
//using namespace std;
//
//class Node {
//public:
//
//	int data;
//	Node* left;
//	Node* right;
//
//	Node(int data) {
//		this->data = data;
//		this->left = NULL;
//		this->right = NULL;
//	}
//};
//
//Node* BuildTree() {
//	int data;
//	cin >> data;
//
//	if (data == -1) {
//		return NULL;
//	}
//
//	Node* newNode = new Node(data);
//
//	cout << "Left of " << data << " : ";
//	newNode->left = BuildTree();
//
//	cout << "Right of " << data << " : ";
//	newNode->right = BuildTree();
//
//	return newNode;
//}
//
//void preOrder(Node* root) {
//	if (root == NULL) {
//		return;
//	}
//	cout << root->data << " ";
//	preOrder(root->left);
//	preOrder(root->right);
//}
//
//void postOrder(Node* root) {
//	if (root == NULL) {
//		return;
//	}
//	postOrder(root->left);
//	postOrder(root->right);
//	cout << root->data << " "; 
//}
//
//void inOrder(Node* root) {
//	if (root == NULL) {
//		return;
//	}
//	inOrder(root->left);
//	cout << root->data << " ";
//	inOrder(root->right);
//}
//
//int TreeHeight(Node* root) {
//	if (!root) return 0;
//
//	int leftHeight = TreeHeight(root->left);
//	int rightHeight = TreeHeight(root->right);
//
//	if (leftHeight > rightHeight) {
//		return leftHeight + 1;
//	}
//	else {
//		return rightHeight + 1;
//	}
//}
//
//void LevelOrderTraverse(Node* root) {
//	if (root == NULL) {
//		return;
//	}
//
//	int height = TreeHeight(root);
//
//	for (int i = 0; i < height; i++) {
//		cout << 
//	}
//
//	
//
// }
//
//int main() {
//	Node* root = BuildTree();
//
//	cout << "\nPre Order : ";
//	preOrder(root);
//	cout << "\nPostOrder : ";
//	postOrder(root);
//	cout << "\nInOrder : ";
//	inOrder(root);
//
//	cout << "\n\nTree Height : " << TreeHeight(root);
//	return 0;
//}
//


TreeNode* CreateTree(TreeNode* root) {

    int data;
    cin >> data;

    if (data == -1) {
        return;
    }

    TreeNode *newNode = new TreeNode(data);

    cout << "Left of " << data << " : ";
    root->left = CreateTree(root->left);
    cout << "Right of " << data << " : ";
    root->right = CreateTree(root->left);
    return newNode;
}


int main() {

    TreeNode* root = NULL;



}