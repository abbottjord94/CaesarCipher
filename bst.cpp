#include <iostream>
#include <cstdlib>

using namespace std;

struct TreeNode {
	TreeNode* left = NULL;
	TreeNode* right = NULL;
	int data;
};

void insert(TreeNode* head, int value) {
	if(value > head->data) {
		if(head->right == NULL) {
			head->right = new TreeNode;
			head->right->data = value;
			return;
		} else {
			insert(head->right, value);
		}
	}
	else if(value <= head->data) {
		if(head->left == NULL) {
			head->left = new TreeNode;
			head->left->data = value;
			return;
		} else {
			insert(head->left, value);
		}
	}
	return;
}

int main(int argc, char* argv[]) {
	int choice=0;
	int key = 11;
	TreeNode* head = new TreeNode;
	TreeNode* root = head;
	head->data = 8;
	int values[9] = {5,7,10,4,6,13,1,3,9};
	for(int i=0; i<9; i++) {
		insert(head, values[i]);
	}
	insert(head, key);
	while(choice != 4) {
		cout << "Current Node Value: " << head->data << endl;
		cout << "Enter a choice: \n";
		cout << "\t1: Move to the left node\n";
		cout << "\t2: Move to the right node\n";
		cout << "\t3: Reset to the top node\n";
		cout << "\t4: Quit\n";
		cin >> choice;
		switch(choice) {
			case 1:
				if(head->left == NULL) {
					cout << "ERROR: INVALID NODE. RESETTING TO TOP NODE\n";
					head = root;
				} else {
					head = head->left;
					cout << "NODE FOUND: " << head->data << endl;
				}
				break;
			case 2:
				if(head->right == NULL) {
					cout << "ERROR: INVALID NODE. RESETTING TO TOP NODE\n";
					head = root;
				} else {
					head = head->right;
					cout << "NODE FOUND: " << head->data << endl;
				}
				break;
			case 3:
				cout << "RESETTING TO TOP NODE\n";
				head = root;
				break;
			case 4:
				exit(1);
				break;
			default:
				cout << "INVALID CHOICE\n";
				break;
		}
		if(head->data == key) {
			cout << "KEY FOUND: " << key << endl;
			exit(1);
		}
	}
	return 0;
}
