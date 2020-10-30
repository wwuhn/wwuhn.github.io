// insert简单版 单独的旋转函数
// 259 旋转函数在insert中实现，insert实现动态平衡
// 468 完整版
// https://visualgo.net/zh/bst
#if 0 //insert简单版 单独的旋转函数 https://www.bilibili.com/video/av75227504?p=29
#include <iostream>
#include <string>
using namespace std;

template <class Comparable>
class RedBlackTree;

template <class Comparable>
class RedBlackNode;

template <class Comparable>
class RedBlackTree
{
public:
	RedBlackTree(const Comparable& negInf);
	enum{RED,BLACK};
	~RedBlackTree();
	void insert(const Comparable& x);
	typedef RedBlackNode<Comparable> Node;
//private:  // for test
	Node* header;
	Node* nullNode;
	
	Node* current;
	Node* parent;
	Node* grand;
	Node* great;
	void rotateWithLeftChild(Node* &k2) const;
	void rotateWithRightChild(Node* &k1) const;
	void doubleRotateWithLeftChild(Node* &k3) const;
	void doubleRotateWithrightChild(Node* &k4) const;
};

template <class Comparable>
class RedBlackNode
{
public: // for test
	Comparable    element;
	RedBlackNode* left;
	RedBlackNode* right;
	int           color;
	
	RedBlackNode(const Comparable& theElement = Comparable(),
				RedBlackNode* lt=NULL,
				RedBlackNode* rt=NULL,
				int c=RedBlackTree<Comparable>::BLACK)
				:element(theElement),left(lt),right(rt),color(c){}
	friend class RedBlackTree<Comparable>;
};

template <class Comparable>
RedBlackTree<Comparable>:: RedBlackTree(const Comparable& negInf)
{
	nullNode = new Node();
	nullNode->left = nullNode->right=nullNode;
	header=new Node(negInf);
	header->left=header->right=nullNode;
}

template <class comparable>
RedBlackTree<comparable>::~RedBlackTree()
{
	delete nullNode;
	delete header; 
}

class DSException
{
public:
	DSException(const string & msg = ""):message(msg){}
	virtual ~DSException(){}
	virtual string toString() const
	{
		return "Exception " + string(": ") + what();
	}
	virtual string what() const
	{
		return message;
	}
private:
	string message;
};

class DuplicateItemException: public DSException
{
public:
	DuplicateItemException(const string& msg = "") : DSException(msg){}
};					

template <class Comparable>
void RedBlackTree<Comparable>::insert(const Comparable& x)
{
	current=parent=grand=header;
	nullNode->element = x;
	while(current->element != x)
	{
		great = grand, grand = parent; parent = current;
		current = x < current->element ? current->left : current->right;
	}
	if(current != nullNode)
		throw DuplicateItemException();

	current = new Node(x,nullNode,nullNode);
	if(x < parent->element)
		parent->left = current;
	else
		parent->right = current;
	// 需要自动动态平衡才是红黑树
	// 新插入的节点是红色的
	// 新插入的是外部孙子（左），做单旋转，如果是内部孙子（右），做双旋转
}

template <class Comparable>
void RedBlackTree<Comparable>::rotateWithLeftChild(Node* &k2) const
{
	Node* k1=k2->left;
	k2->left=k1->right;
	k1->right=k2;
	k2=k1; //k1现在是根
}

template <class Comparable>
void RedBlackTree<Comparable>::rotateWithRightChild(Node* &k1) const
{
	Node* k2=k1->right;
	k1->right = k2->left;
	k2->left=k1;
	k1=k2;
}

template <class Comparable>  // 如果内侧子孙节点过深, 则将其单向移动是不会解决问题的，于是就有了双旋转
// 首先以k1为轴, k1与k2向左旋转;
// 然后以k3为轴, k3与旋转之后的k1向右旋转;
void RedBlackTree<Comparable>::doubleRotateWithLeftChild(Node* &k3) const
{
	rotateWithRightChild(k3->left);
	rotateWithLeftChild(k3);
}

template <class Comparable>
void RedBlackTree<Comparable>::doubleRotateWithrightChild(Node* &k4) const
{
	rotateWithLeftChild(k4->right);
	rotateWithRightChild(k4);
}
/*
-∞
  \
  30
  / \
  15  70
   \
    20
*/

int main()
{
	const int NEG_INF = -99999;
	RedBlackTree<int> t(NEG_INF);
#if 0
	t.insert(30);
	t.insert(15);
	t.insert(70);
	t.insert(20);
	cout<< t.header->right->element<<endl;
	cout<< t.header->right->left->element<<endl;
	cout<< t.header->right->right->element<<endl;
	cout<< t.header->right->left->right->element<<endl;
	cout<<"向右转"<<endl;
	t.rotateWithLeftChild(t.header->right);
/*
-∞
  \
  30
  / \
  15  70
   \
    20
*/
	
/*
-∞
  \
  15
    \
     30
	/  \
   20   70
*/

	cout<<t.header->right->element<<endl;
	cout<<t.header->right->right->left->element<<endl;

	cout<<"向左转"<<endl;
	t.rotateWithRightChild(t.header->right);
	cout<< t.header->right->element<<endl;
	cout<< t.header->right->left->element<<endl;
	cout<< t.header->right->right->element<<endl;
	cout<< t.header->right->left->right->element<<endl;
#else
	t.insert(12);
	t.insert(16);
	t.insert(8);
	t.insert(10);
	t.insert(4);
	t.insert(14);
	t.insert(2);
	t.insert(6);
	t.insert(5);
/*
	   12
	  /  \
	8     16
	/\    /
   4  10 14
  / \
  2  6
     /
	 5
*/
	cout<<t.header->right->left->element<<endl;
	t.doubleRotateWithLeftChild(t.header->right->left);
	cout<<t.header->right->left->element<<endl;
/*
	   12
	  /  \
	6     16
	/\    /
   4  8  14
  / \  \
  2  5  10
*/
#endif
	cout<<"OK"<<endl;
    system("pause");
	return 0;
}
/*
30
15
70
20
向右转
15
20
向左转
30
15
70
20
OK
*/
#endif


# if 0 // -----------------------------------------------旋转函数在insert中实现，insert实现动态平衡
#include <iostream>
#include <string>
using namespace std;

template <class Comparable>
class RedBlackTree;

template <class Comparable>
class RedBlackNode;

template <class Comparable>
class RedBlackTree
{
public:
	RedBlackTree(const Comparable& negInf);
	enum{RED,BLACK};
	~RedBlackTree();
	void insert(const Comparable& x);
	typedef RedBlackNode<Comparable> Node;
//private: // for test
	Node* header;
	Node* nullNode;
	
	Node* current;
	Node* parent;
	Node* grand;
	Node* great;
	void rotateWithLeftChild(Node* &k2) const;
	void rotateWithRightChild(Node* &k1) const;
	void doubleRotateWithLeftChild(Node* &k3) const;
	void doubleRotateWithrightChild(Node* &k4) const;
	void handleReorient(const Comparable& item);
	
	RedBlackNode<Comparable>* rotate(const Comparable& item, Node* parent) const;
};

template <class Comparable>
class RedBlackNode
{
public: // for test
	Comparable element;
	RedBlackNode* left;
	RedBlackNode* right;
	int color;
	
	RedBlackNode(const Comparable& theElement = Comparable(),
				RedBlackNode* lt=NULL,
				RedBlackNode* rt=NULL,
				int c=RedBlackTree<Comparable>::BLACK)
				:element(theElement),left(lt),right(rt),color(c){}
	friend class RedBlackTree<Comparable>;
};

template <class Comparable>
RedBlackTree<Comparable>:: RedBlackTree(const Comparable& negInf)
{
	nullNode = new Node();
	nullNode->left = nullNode->right=nullNode;
	header=new Node(negInf);
	header->left=header->right=nullNode;
}

template <class comparable>
RedBlackTree<comparable>::~RedBlackTree()
{
	delete nullNode;
	delete header; 
}

class DSException
{
public:
	DSException(const string & msg = ""):message(msg){}
	virtual ~DSException(){}
	virtual string toString() const
	{
		return "Exception " + string(": ") + what();
	}
	virtual string what() const
	{
		return message;
	}
private:
	string message;
};

class DuplicateItemException: public DSException
{
public:
	DuplicateItemException(const string& msg = "") : DSException(msg){}
};
						

template <class Comparable>
void RedBlackTree<Comparable>::insert(const Comparable& x)
{
	current=parent=grand=header;
	nullNode->element = x;
	while(current->element != x)
	{
		great = grand, grand = parent; parent = current;
		current = x < current->element ? current->left : current->right;

		if(current->left->color == RED && current->right->color == RED)
			handleReorient(x);

	}
	if(current != nullNode)
		throw DuplicateItemException();

	current = new Node(x,nullNode,nullNode);
	if(x < parent->element)
		parent->left = current;
	else
		parent->right = current;
	// 需要自动动态平衡才是红黑树
	// 新插入的节点是红色的
	// 新插入的是外部孙子（左），做单旋转，如果是内部孙子（右），做双旋转
	handleReorient(x);
}
template <class Comparable>
void RedBlackTree<Comparable>:: handleReorient(const Comparable& item)
{
	// 变色
	current->color=RED;
	current->left->color=BLACK;
	current->right->color=BLACK;

	if(parent->color == RED)
	{
		grand->color=RED;
		if(item < grand->element != item < parent->element) // 内部孙子（右）
			parent = rotate(item,grand); // 多一次旋转
		current = rotate(item,great);
		current->color = BLACK;		
	}
	header->right->color = BLACK;

}

template <class Comparable>
RedBlackNode<Comparable>* void RedBlackTree<Comparable>::rotate(const Comparable& item, Node* parent) const
{
	if(item < parent->element)
	{
		item < parent->left->element ?
			rotateWithLeftChild(parent->left):
			rotateWithRightChild(parent->left);
		return parent->left;
	}
	else
	{
		item < parent->right->element ?
			rotateWithLeftChild(parent->right) :
			rotateWithRightChild(parent->right);
		return parent->right;
	}
	
}

template <class Comparable>
void RedBlackTree<Comparable>::rotateWithLeftChild(Node* &k2) const
{
	Node* k1=k2->left;
	k2->left=k1->right;
	k1->right=k2;
	k2=k1; //k1现在是根
}
template <class Comparable>
void RedBlackTree<Comparable>::rotateWithRightChild(Node* &k1) const
{
	Node* k2=k1->right;
	k1->right = k2->left;
	k2->left=k1;
	k1=k2;
}

template <class Comparable>
void RedBlackTree<Comparable>::doubleRotateWithLeftChild(Node* &k3) const
{
	rotateWithRightChild(k3->left);
	rotateWithLeftChild(k3);
}

template <class Comparable>
void RedBlackTree<Comparable>::doubleRotateWithrightChild(Node* &k4) const
{
	rotateWithLeftChild(k4->right);
	rotateWithRightChild(k4);
}

int main()
{
	const int NEG_INF = -99999;
	RedBlackTree<int> t(NEG_INF);

	t.insert(50);
	t.insert(40);
	t.insert(30);
	cout<<t.header->right->element<<endl; // 40

 system("pause");
	return 0;
}


#endif

#if 1   // -----------------------------－－－－－－－－－－－－－－--------------完整版

#include <iostream>
#include <string>
using namespace std;

template <class Comparable>
class RedBlackTree;

template <class Comparable>
class RedBlackNode;

template <typename Object>
class Cref;

template <class Comparable>
class RedBlackTree										// ReadBlackTree类
{
public:
	RedBlackTree(const Comparable& negInf);
	enum{RED,BLACK};
	~RedBlackTree();
	void insert(const Comparable& x);

    bool isEmpty() const;
    void makeEmpty();

    Cref<Comparable> find(const Comparable & x) const; // 返回一个用指针封装的引用，因为引用不能为空
    Cref<Comparable> findMin() const;
    Cref<Comparable> findMax() const;
	typedef RedBlackNode<Comparable> Node;
private:
	Node* header;			//指向红黑树的头(伪根节点)
	Node* nullNode;
	//在insert时使用以下四个指针
    Node *current;  // 当前节点
    Node *parent;   // 父节点
    Node *grand;    // 祖父节点
    Node *great;    // 曾祖父节点
	void rotateWithLeftChild(Node* &k2) const;	// 向右转(带着右孩子)
	void rotateWithRightChild(Node* &k1) const;	// 向左转(带着左孩子)
	void doubleRotateWithLeftChild(Node* &k3) const;
	void doubleRotateWithrightChild(Node* &k4) const;
	// 自动处理: [1]重新染色; [2]:自动旋转
	void handleReorient(const Comparable& item);
	// 自动旋转函数(返回旋转以后的theParent子树的根)
	RedBlackNode<Comparable>* rotate(const Comparable& item, Node* parent) const;
    
    void reclainMemory(Node *t) const;			// 递归删除所有节点
};

template <class Comparable>
class RedBlackNode												// RedBlackNode类
{
public:
	Comparable    element;
	RedBlackNode* left;
	RedBlackNode* right;
	int           color;
	
	RedBlackNode(const Comparable& theElement = Comparable(),
				RedBlackNode* lt=NULL,
				RedBlackNode* rt=NULL,
				int c=RedBlackTree<Comparable>::BLACK)
				:element(theElement),left(lt),right(rt),color(c){}
	friend class RedBlackTree<Comparable>;
};

template <class Comparable>
RedBlackTree<Comparable>:: RedBlackTree(const Comparable& negInf)		// RedBlackTree构造函数
{
	nullNode = new Node();
	//nullNode 的左右子节点都指向自己
	nullNode->left = nullNode->right=nullNode;
	header=new Node(negInf);
	header->left=header->right=nullNode;
}

template <class comparable>
RedBlackTree<comparable>::~RedBlackTree()								// RedBlackTree析构函数
{
    if (!isEmpty())
        makeEmpty();
	delete nullNode;
	delete header; 
}

class DSException														// DSException类
{
public:
	DSException(const string & msg = ""):message(msg){}
	virtual ~DSException(){}
	virtual string toString() const
	{
		return "Exception " + string(": ") + what();
	}
	virtual string what() const
	{
		return message;
	}
private:
	string message;
};

class DuplicateItemException: public DSException
{
public:
	DuplicateItemException(const string& msg = "") : DSException(msg){}
};					
class NullPointerException : public DSException
{
public:
    NullPointerException(const string &_msg = string())
        : DSException(_msg) {}
};

template <class Comparable>
void RedBlackTree<Comparable>::insert(const Comparable& x)				// insert()
{
	current=parent=grand=header;
	nullNode->element = x;
	while(current->element != x)
	{
		// 让祖父成为曾祖父, 父亲成为祖父, 自己成为父亲
        // 每个节点都成长一辈
		great = grand, grand = parent; parent = current;
		current = x < current->element ? current->left : current->right;
		//处理1. 如果current节点有两个红色孩子
		if(current->left->color == RED && current->right->color == RED)
			handleReorient(x);
	}

	if(current != nullNode) // 如果树中包含相同的元素
		throw DuplicateItemException();

	current = new Node(x,nullNode,nullNode);
	if(x < parent->element)
		parent->left = current;
	else
		parent->right = current;
	// 需要自动动态平衡才是红黑树
	// 新插入的节点是红色的
	// 新插入的是外部孙子（左），做单旋转，如果是内部孙子（右），做双旋转
	// 处理2. 如果新插入的节点破坏了红黑规则
	handleReorient(x);
}

// 自动平衡函数:[1]重新染色；[2]自动旋转
template <class Comparable>
void RedBlackTree<Comparable>:: handleReorient(const Comparable& item)  // handleReorient()
{
	current->color=RED;					// 将current节点染成红色
	current->left->color=BLACK;			// 将current的left和right节点染成黑色
	current->right->color=BLACK;
	// 如果current节点的父节点也是红的 -> 单旋转 or 双旋转
	if(parent->color == RED)
	{
		grand->color=RED;		// 则将其祖父(爷爷)的颜色染成红色
		// 然后判断新插入的节点是否是内部孙子(右节点)?
        // 如果是, 则增加一次旋转->构成双旋转
        // if注释: 如果该节点小于爷爷, 小于爸爸, 这两种情况不同时满足
        // 则说明其是爷爷的内孙子
		if(item < grand->element != item < parent->element) 
			parent = rotate(item,grand); // 依grand(祖父)节点进行旋转
		current = rotate(item,great);	 // 依great(曾祖父)节点进行旋转
		current->color = BLACK;			 // 令当前节点为黑色
	}
	header->right->color = BLACK;		// 根节点必须是黑色的
}

template <class Comparable>										//自动判断并进行旋转函数
RedBlackNode<Comparable>* RedBlackTree<Comparable>::
	rotate(const Comparable& item, Node* parent) const			// rotate()
{
    if(item < parent->element) //位于parent的左子树
    {
        //如果为真, 则说明parent->left有左孩子,否则, 有右孩子
        item < parent->left->element ?
        //如果parent左边有一棵子树, 则以parent->left为轴, 向右转
        rotateWithLeftChild( parent->left )  :  // LL
        //如果parent右边有一棵子树, 则以parent->left为轴, 向左转
        rotateWithRightChild( parent->left ) ;  // LR

        return parent->left;     //返回左子树
    }
    else    //位于右子树
    {
        //如果为真, 则说明parent->right有左孩子,往右转，否则, 有右孩子, 往左转
        item < parent->right->element ?
        rotateWithLeftChild( parent->right ) :  // RL
        rotateWithRightChild( parent->right );  // RR

        return parent->right;    // 返回右子树
    }
	
}

template <class Comparable>
void RedBlackTree<Comparable>::rotateWithLeftChild(Node* &k2) const  // 右(单)旋转
{
	Node* k1=k2->left;
	k2->left=k1->right;
	k1->right=k2;
	k2=k1; //k1现在是根
}

template <class Comparable>
void RedBlackTree<Comparable>::rotateWithRightChild(Node* &k1) const // 左(单)旋转
{
	Node* k2=k1->right;
	k1->right = k2->left;
	k2->left=k1;
	k1=k2;
}

template <class Comparable>
void RedBlackTree<Comparable>::doubleRotateWithLeftChild(Node* &k3) const
{
	rotateWithRightChild(k3->left);
	rotateWithLeftChild(k3);
}

template <class Comparable>
void RedBlackTree<Comparable>::doubleRotateWithrightChild(Node* &k4) const
{
	rotateWithLeftChild(k4->right);
	rotateWithRightChild(k4);
}

template <typename Comparable>
Cref<Comparable> RedBlackTree<Comparable>::find(const Comparable &x) const  // find()
{
    if (isEmpty())
        return Cref<Comparable>();

    nullNode->element = x;
    Node *iter = header->right;

    while (true)
    {
        if (x < iter->element)
            iter = iter->left;
        else if (x > iter->element)
            iter = iter->right;

        else if (iter != nullNode)
            return Cref<Comparable>(iter->element) ;
        else
            return Cref<Comparable>();
    }
}
template <typename Comparable>
Cref<Comparable> RedBlackTree<Comparable>::findMax() const			// findMax()
{
    if (isEmpty())
        return Cref<Comparable>();

    Node *iter = header->right;
    while (iter->right != nullNode)
    {
        iter = iter->right;		// 一直向右走
    }

    return Cref<Comparable>(iter->element);
}
template <typename Comparable>
Cref<Comparable> RedBlackTree<Comparable>::findMin() const			// findMin()
{
    if (isEmpty())
        return Cref<Comparable>();

    Node *iter = header->right;
    while (iter->left != nullNode)
    {
        // 一直向左走
        iter = iter->left;
    }

    return Cref<Comparable>(iter->element);
}

template <typename Comparable>
bool RedBlackTree<Comparable>::isEmpty() const						// isEmpty()
{
    if (header->right == nullNode)
        return true;
    return false;
}

template <typename Comparable>
void RedBlackTree<Comparable>::makeEmpty()							// makeEmpty()
{
    reclainMemory(header->right);
    header->right = nullNode;
}

template <typename Comparable>
void RedBlackTree<Comparable>::reclainMemory(Node *t) const			// reclainMemory()
{
    //t == t->left的时候, 是当t==nullNode时
    if (t != t->left)
    {
        reclainMemory(t->left);
        reclainMemory(t->right);
        delete t;
    }

}

// 一个用指针封装的引用，因为查找时可能返回空，但引用是不能为空的
template <typename Object>											// Cref类
class Cref
{
public:
    Cref():obj(NULL) {}
    explicit Cref(const Object &x)
        : obj(& x) {}

    const Object &get() const
    {
        if (isNull())
            throw NullPointerException();
        else
            return * obj;
    }

    bool isNull() const
    {
        if (obj == NULL)
            return true;
        return false;
    }

private:
    const Object * obj;
};

int main()
{
    const int NEG_INF = -999999;
    RedBlackTree<int> tree(NEG_INF);

    tree.insert(50);
    tree.insert(40);
    tree.insert(30);
    tree.insert(10);
    tree.insert(55);
    tree.insert(88);
    tree.insert(200);
    tree.insert(100);
    tree.insert(70);
    tree.insert(80);
    tree.insert(650);

    Cref<int> g = tree.findMin();
    cout << "Min = " << g.get() << endl;
    g = tree.findMax();
    cout << "Max = " << g.get() << endl;

    int searchVal;
	cout<<"请输入需要查找的数字(输入null则清空树)：";
    while (cin >> searchVal)
    {
        g = tree.find(searchVal);
        if (g.isNull())
            cout << "not found" << endl;
        else
            cout << g.get() << " founded" << endl;
    }

    tree.makeEmpty();
    if (tree.isEmpty())
    {
        cout << "is Empty" << endl;
    }
    else
    {
        cout << "not Empty" << endl;
    }
	system("pause");
    return 0;
}
/*
Min = 10
Max = 650
请输入需要查找的数字(输入null则清空树)：10
10 founded
200
200 founded
234
not found
null
is Empty
*/
#endif