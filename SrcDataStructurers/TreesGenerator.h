#pragma once
#include "Node.h"
#include <string>

class TreeGenerator
{
public:
	static PtrNode<int> CreateTree();

	static PtrNode<int> CreateUndirectedTree();

	static PtrBinaryNode<std::string> CreateStrBinaryTree();

	static PtrNode<int> CreateUndirectedTree1();
};

