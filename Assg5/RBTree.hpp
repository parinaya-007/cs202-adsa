#ifndef RBTree_HPP_
#define RBTree_HPP_ 1
#include "BSTree.hpp"
/* The color enumeration.
 * Please use this and not integers or characters to store the color of the node
 * in your red black tree.
 * Also create a class BinaryNode which should inherit from BinaryNode and has the attribute color in it. 
 */


/*template <class Key, class Value>
class BinaryNode : public BinaryNode<Key, Value> {

	public:
	Color color;
	BinaryNode(); 
	BinaryNode(Key key, Value value);
};
template <class Key,class Value>
BinaryNode<Key,Value>::BinaryNode()
{
this->key=(Key)0;
this->val=(Value)0;
this->left=NULL;
this->right=NULL;
this->parent=NULL;
}


template <class Key,class Value>
BinaryNode<Key,Value>::BinaryNode(Key key, Value value)
{
this->key=key;
this->val=value;
this->left=NULL;
this->right=NULL;
this->parent=NULL;
}
*/

template <class Key, class Value>
class RBTree : public BSTree<Key, Value> {

	
	/*It applies fixing mechanisms to make sure that the tree remains a valid red black tree after an insertion.
	 */
	public:
	RBTree()
	{
		this->root=NULL;
	}
	void insertRBFixup(BinaryNode<Key,Value>* root);

	void insert(Key k,Value v);

/* It applies fixing mechanisms to make sure that the tree remains a valid red black tree after a deletion.
	 */
	void deleteRBFixup(BinaryNode<Key,Value>* root);

	void deletek(Key k);

	BinaryNode<Key,Value>* rightRotate(BinaryNode<Key,Value> *z);

	BinaryNode<Key,Value>* leftRotate(BinaryNode<Key,Value> *z);

	/* the black height of the red black tree which begins at node_ptr root
	 */
	int blackh();

	void findk(BinaryNode<Key,Value> *root,Key& key,BinaryNode<Key,Value> **ret);

	int blackHeight(BinaryNode<Key,Value>* root);

	BinaryNode<Key,Value>* uncle(BinaryNode<Key,Value> *root);

};

template <class Key, class Value>
void RBTree<Key,Value>::findk(BinaryNode<Key,Value> *root,Key& key,BinaryNode<Key,Value> **ret)
   {
    if(root==NULL) *ret=NULL;
     if(key==root->key) 
     {
		 *ret=root;
		 return;
	 }
     else if(key<root->key) findk(root->left,key,ret);
     else findk(root->right,key,ret);
   }

template <class Key, class Value>
void RBTree<Key,Value>::insert(Key k,Value v)
{
	pututil(&(this->root),k,v,this->root);
	BinaryNode<Key,Value> *ptr;
	findk(this->root,k,&ptr);
	//cout<<ptr->val;
	ptr->color=RED;
	insertRBFixup(ptr);
}

template <class Key, class Value>
BinaryNode<Key,Value>* RBTree<Key,Value>::uncle(BinaryNode<Key,Value> *root)
   {
    if(root==NULL) 
	return NULL;

	else if(root->parent==NULL) 
	return NULL;

	else if(root->parent->parent==NULL) 
	return NULL;
	
	else
	{
		if(root->parent->parent->left==root->parent)
			return root->parent->parent->right;
		else
			return root->parent->parent->left;
	}
   }

template <class Key, class Value>
void RBTree<Key,Value>::insertRBFixup(BinaryNode<Key,Value>* root)
{
	//if(root==NULL) cout<<"hi";
	if(root==this->root)
		root->color=BLACK;
	else if(root->parent->color!=BLACK)
	{
	//cout<<root->val;
	BinaryNode<Key,Value> *unc=uncle(root);
	Color col;
	if(unc)
	{
	
		if(unc->color==RED)
		{
			unc->color=BLACK;
			root->parent->color=BLACK;
			root->parent->parent->color=RED;
			insertRBFixup(root->parent->parent);
		}
			else if(unc->color==BLACK)
		{	
			BinaryNode<Key,Value>* x=root;
			BinaryNode<Key,Value>* p=root->parent;
			BinaryNode<Key,Value>* g=root->parent->parent;
			if(p==g->left && x==p->left)
			{
				rightRotate(g);
				col=g->color;
				g->color=p->color;
				p->color=col;
			}
			else if(p==g->left && x==p->right)
			{	
				leftRotate(p);

				rightRotate(g);
				col=g->color;
				g->color=p->color;
				p->color=col;
			}
			else if(p==g->right && x==p->right)
			{
				leftRotate(g);
				col=g->color;
				g->color=p->color;
				p->color=col;
			}
			else if(p==g->right && x==p->left)
			{
				rightRotate(p);
				
				leftRotate(g);
				col=g->color;
				g->color=p->color;
				p->color=col;
			}

		}

	}
	else
	{
		BinaryNode<Key,Value>* x=root;
			BinaryNode<Key,Value>* p=root->parent;
			BinaryNode<Key,Value>* g=root->parent->parent;
			if(p==g->left && x==p->left)
			{
				rightRotate(g);
				col=g->color;
				g->color=p->color;
				p->color=col;
			}
			else if(p==g->left && x==p->right)
			{	
				leftRotate(p);

				rightRotate(g);
				col=g->color;
				g->color=p->color;
				p->color=col;
			}
			else if(p==g->right && x==p->right)
			{
				leftRotate(g);
				col=g->color;
				g->color=p->color;
				p->color=col;
			}
			else if(p==g->right && x==p->left)
			{
				rightRotate(p);
				
				leftRotate(g);
				col=g->color;
				g->color=p->color;
				p->color=col;
			}
		}
	}	
}

template <class Key, class Value>
void RBTree<Key,Value>::deletek(Key k)
{

}

template <class Key, class Value>
void RBTree<Key,Value>::deleteRBFixup(BinaryNode<Key,Value>* root)
{

}

template <class Key, class Value>
	int RBTree<Key,Value>::blackh()
		{
			return blackHeight(this->root);
		}

	template <class Key, class Value>
	int RBTree<Key,Value>::blackHeight(BinaryNode<Key,Value> * current)
		{
			if(current==NULL)
				return 0;
			else if(current->left == NULL || current->right ==NULL)
				return 1;
			else if(current->left->color == BLACK)
				return (1+blackHeight(current->left));
			else
				return blackHeight(current->left);
		}

template <class Key,class Value>
BinaryNode<Key,Value>* RBTree<Key,Value>::rightRotate(BinaryNode<Key,Value> *z)
{
    BinaryNode<Key,Value> *y = z->left;
    BinaryNode<Key,Value> *T2 = y->right;
    y->parent = z->parent;

    if(z->parent==NULL) {this->root=y;}
    else if(z->parent->left==z) {z->parent->left=y;}
    else if(z->parent->right==z) {z->parent->right=y;}
    
    
    if(T2) T2->parent=z;

    z->parent= y;
    z->left = T2;
    y->right = z;

	return y;
}

    template <class Key,class Value>
    BinaryNode<Key,Value>* RBTree<Key,Value>::leftRotate(BinaryNode<Key,Value> *z)
    {
    BinaryNode<Key,Value> *y = z->right;
    BinaryNode<Key,Value> *T2 = y->left;
    y->parent = z->parent;
    
    if(z->parent==NULL) {this->root=y;}
    else if(z->parent->left==z) {z->parent->left=y;}
    else if(z->parent->right==z) {z->parent->right=y;}
    
    
    
    if(T2) T2->parent=z;

    z->parent= y;
    z->right = T2;
    y->left = z;

	return y;
    }

#endif /* ifndef RBTree_HPP_ */