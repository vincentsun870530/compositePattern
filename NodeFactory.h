#pragma once
#include <iostream>
#include "Component.h"
#include <string>
#include "CompositeNode.h"
#include "Leaf.h"
using namespace std;

class NodeFactory
{
public:
	virtual Component* buildBinary(char tempOperator, Component* left, Component* right) = 0;
	virtual Component* buildUnary(char tempOperator, Component* right) = 0;
	virtual Component* buildLeaf(int number) = 0;
	virtual void levelOrderPrint() = 0;
};


class IntNodeFactory : public NodeFactory
{
public:

	Component* buildBinary(char tempOperator, Component* left, Component* right)
	{
		if (tempOperator == '+')
		{
			tree.push_back('+');
			return new Adder(left, right);
		
		}
		else if (tempOperator == '-')
		{
			return new Substracter(left, right);
		}
		else if (tempOperator == '*')

		{
			tree.push_back('*');
			return new Multiplier(left, right);
		}
		else if (tempOperator == '/')
		{
			return new Divider(left, right);
		}

	};
	Component* buildUnary(char tempOperator, Component* right)
	{
		tree.push_back('-');
		return new Negate(right);
	};
	Component* buildLeaf(int number)
	{
		tree.push_back('0'+number);
		return new Leaf(number);
	};

	void levelOrderPrint()
	{
		for (vector<char>::iterator comIter = tree.begin(); comIter != tree.end(); ++comIter)
		{
			cout << *comIter << endl;
		}
	};

	vector<char> tree;
};

//
//class BinaryNodeFactory : public NodeFactory
//{
//public:
//	Component* getBinaryFactory (char tempOperator , Component* left, Component* right)
//	{
//		if(tempOperator == '+')
//		{
//			return new Adder(left, right);
//		}
//		else if(tempOperator == '-')
//		{
//			return new Substracter(left, right);
//		}
//		else if(tempOperator == '*')
//		{
//			return new Multiplier(left, right);
//		}
//		else if (tempOperator =='/')
//		{
//			return new Divider(left, right);
//		}
//
//	}
//};
//
//class UnaryNodeFactory : public NodeFactory
//{
//public:
//	Component * getUnaryFactory(char tempOperator, Component* right)
//	{
//		return new Negate(right);
//	}
//};
//
//class LeafFactory : public NodeFactory
//{
//public:
//	Component * getLeafFactory(int number)
//	{
//
//		return new Leaf(number);
//
//	}
//};
