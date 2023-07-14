#pragma once
#include<iostream>
#include <iostream>
template<class T>
class BSTNode {
public:
	BSTNode(T key)
	{
		val = key;
	}
	BSTNode* _left;
	BSTNode* _right;
	T val;
	

};

template<class K>
class BSTree
{
	typedef BSTNode<K> Node;
public:
	BSTree() :_root(nullptr)
	{

	}
	bool find(const K& key)
	{
		Node* cur = _root;
		while (cur && cur->val != key)
		{
			if (cur->val > key)
			{
				cur = cur->left;
			}
			else if (cur->val < key)
			{
				cur = cur->_right;
			}
			else
				return true;
		}
		return false;
	}
	bool insert( K& key)
	{
		if (this->_root == nullptr)
		{
			this->_root = new Node(key);
			return true;
		}
		
			Node* cur = _root;
			Node* prev = nullptr;
		while (cur)
		{
			
			if (key > cur->val)
			{
				prev = cur;
				cur = cur->_right;

			}
			else if (key < cur->val)
			{
				prev = cur;
				cur = cur->_left;

			}
			else
				return false;
		}
		cur = new Node(key);
		if (cur->val > prev->val)
		{
			prev -> _right = cur;
			return true;
		}
		else
		{
			prev->_left = cur;
			return true;
		}
		
	}
	bool Erase(const K& key)
	{
		Node* cur = _root;
		Node* prev = nullptr;
		while (cur)
		{
			if (key > cur->val)
			{
				prev = cur;
				cur = cur->_right;

			}
			else if (key < cur->val)
			{
				prev = cur;
				cur = cur->_left;

			}
			else
			{
				if (cur->_left == nullptr)
				{
					if (cur == _root)
						_root = cur->_right;
					if (prev->_left == cur)
					{
						prev->_left = cur->_right;
					}
					if (prev->_right == cur)
					{
						prev->_right = cur->_right;
					}
					delete cur;
					return true;
				}
				else if (cur->_right == nullptr)
				{
					if (cur == _root)
						_root = cur->_left;
					if (prev->_left = cur)
					{
						prev->_left = cur->_left;
					}
					if (prev->_right = cur)
					{
						prev->_right = cur->_left;
					}
					delete cur;
					return true;
				}
				//找到右子树的最小节点
				else
				{
					Node* parent = cur;
					Node* min = cur->_right;
					while (min->_left)
					{
						parent = min;
						min = min->_left;
					}
					cur->val = min->val;
					if (min = parent->_left)
					{
						parent->_left = min->_right;
					}
					if (min = parent->_right)
					{
						parent->_right = min->_left;
					}
					delete min;
					return true;

				}
				


			}

				
		}
		
		return false;

	}
	
	void inorder()
	{
		_inorder(_root);
	}
	void _inorder(Node* _root)
	{
		if (_root == nullptr)
			return;
		_inorder(_root->_left);
		std::cout << _root->val;
		_inorder(_root->_right);
	}
private:
	Node* _root;
};

void TestBSTree()
{
	BSTree<int > Tree;
	int a[] = { 5,3,4,1,7,8,2,6,0,9,5,5 };
	for (auto e : a)
	{
		Tree.insert(e);
	}
	Tree.inorder();
	Tree.Erase(5);
	std::cout << "   " << std::endl;
	Tree.inorder();
	Tree.Erase(7);

	Tree.inorder();
	std::cout << "   " << std::endl;

	Tree.Erase(0);
	Tree.inorder();
	std::cout << "   " << std::endl;

	Tree.Erase(1);
	Tree.inorder();
	std::cout << "   " << std::endl;



}