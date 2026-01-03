#include <iostream>
using namespace std;
/*
Bài 3:
Hãy cài đặt cấu trúc dữ liệu cây nhị phân tìm kiếm theo khung chương trình cho bên dưới. 
Mỗi nút trên cây chứa một số nguyên. Cấu trúc dữ liệu này cho phép chèn thêm nút mới và tìm
kiếm nút theo một giá trị cho trước
Yêu cầu bổ sung: Cài đặt thêm các hàm duyệt cây theo thứ tự trước, giữa và sau
*/
struct Node
{
	int value;      // gia tri nut
	Node* left;  // Con tro toi nut con trai
	Node* right; // Con tro toi nut con phai

	// Ham tao.
	Node(int v, Node* l, Node* r)
	{
		value = v;
		left = l;
		right = r;
	}
};

// Lop cay nhi phan tim kiem.
class BSTree
{
private:
	Node* root;
public:
	// Ham tao (ban dau cay rong).
	BSTree()
	{
		root = NULL;
	}

	// Ham huy (xoa het cac nut tren cay).
	~BSTree() { 
		makeEmpty();
	}

	// Kiem tra cay co rong hay khong.
	bool isEmpty() { 
		return root == NULL;
	}

	// Xoa het cac nut tren cay.
	void makeEmpty() { 
		makeEmpty(root);
	}

	// Chen mot nut val1 moi vao cay.
	void insert(int val1)
	{
		return insert(val1, root);
	}

	// Tim nut val2
	Node* search(int val2)
	{
		return search(val2, root);
	}

	// Xoa rong cay (viet theo kieu de quy).
	void makeEmpty(Node*& t) { 
		if (t == nullptr) return;
		makeEmpty(t->left);
		makeEmpty(t->right);
		delete t;
	}

	// Chen mot nut val1 moi vao cay (viet theo kieu de quy).
	void insert(int val1, Node*& t) { 
		Node* newNode = new Node(val1, nullptr, nullptr);
		if (t == nullptr) {
			t = newNode;
			return;
		}
		if (val1 < t->value) {
			insert(val1, t->left);
		}
		else if (val1 > t->value) {
			insert(val1, t->right);
		}
	}

	// Tim kiem nut co gia tri cho truoc  (viet theo kieu de quy).
	Node* search(int val2, Node* t) { 
		if (val2 == t->value) {
			return t;
		}
		else if (val2 < t->value) {
			if (t->left != nullptr) {
				return search(val2, t->left);
			}
			else {
				return nullptr;
			}
		}
		else {
			if (t->right != nullptr) {
				return search(val2, t->right);
			}
			else {
				return nullptr;
			}
		}
	}
};
// Duyet cay theo thu tu truoc (PREORDER)
void PREORDER_travl(Node* t) { 
	if (t == nullptr) return;
	cout << t->value << ' ';
	PREORDER_travl(t->left);
	PREORDER_travl(t->right);
}
// Duyet cay theo thu tu giua (INORDER)
void inorder(Node* node) {
	if (node == nullptr) return;
	inorder(node->left);
	cout << node->value << ' ';
	inorder(node->right);
}
// Duyet cay theo thu tu sau (POSTORDER)
void postorder(Node* node) {
	if (node == nullptr) return;
	postorder(node->left);
	postorder(node->right);
	cout << node->value << ' ';
}

int main()
{
	BSTree bst;

	// Chen cac node co gia tri duoi day .
	bst.insert(5);
	bst.insert(6);
	bst.insert(3);
	bst.insert(8);
	bst.insert(7);
	bst.insert(4);
	bst.insert(2);
	Node* root = bst.search(5);
	cout << "duyet cay thu tu truoc" << endl;
	PREORDER_travl(root);
	cout << endl;
	// Tim hai node co gia tri 4 va 9.
	Node* n1 = bst.search(4);
	Node* n2 = bst.search(9);

	// In ket qua tim kiem
	if (n1 != NULL)
		cout << "Node có gia tri = 4 la " << n1->value << endl;
	if (n2 == NULL)
		cout << "Khong tim thay node co gia tri =9" << endl;

	// Lam rong cay.
	bst.makeEmpty();
	if (bst.isEmpty())
		cout << "Cay da bi xoa rong" << endl;

	return 0;
}
