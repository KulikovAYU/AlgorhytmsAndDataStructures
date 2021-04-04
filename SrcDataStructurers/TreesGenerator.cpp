#include "pch.h"
#include "TreesGenerator.h"

PtrNode<int> TreeGenerator::CreateTree()
{
	PtrNode<int> ptrRoot = (std::make_shared<Node<int>>(5));


	PtrNode<int> newNode = std::make_shared<Node<int>>(4);
	//ptrRoot->m_pChilds.emplace_back(newNode);
	ptrRoot->m_pChilds.emplace_back(newNode);


	PtrNode<int> newRNode = std::make_shared<Node<int>>(3);
	ptrRoot->m_pChilds.emplace_back(newRNode);


	PtrNode<int> newNode1 = std::make_shared<Node<int>>(1);
	newNode1->m_pChilds.emplace_back(std::make_shared<Node<int>>(2));
	newNode1->m_pChilds.emplace_back(std::make_shared<Node<int>>(9));

	newNode->m_pChilds.emplace_back(newNode1);
	newNode->m_pChilds.emplace_back(std::make_shared<Node<int>>(-6));


	newRNode->m_pChilds.emplace_back(std::make_shared<Node<int>>(0));

	PtrNode<int> newNode3 = std::make_shared<Node<int>>(7);
	newNode3->m_pChilds.emplace_back(std::make_shared<Node<int>>(8));
	newRNode->m_pChilds.emplace_back(newNode3);

	newRNode->m_pChilds.emplace_back(std::make_shared<Node<int>>(-4));

	return ptrRoot;
}

PtrNode<int> TreeGenerator::CreateUndirectedTree()
{
	PtrNode<int> ptrRoot = (std::make_shared<Node<int>>(0));

	PtrNode<int> ptrNode1 = (std::make_shared<Node<int>>(1));
	PtrNode<int> ptrNode2 = (std::make_shared<Node<int>>(2));
	PtrNode<int> ptrNode3 = (std::make_shared<Node<int>>(3));
	PtrNode<int> ptrNode4 = (std::make_shared<Node<int>>(4));
	PtrNode<int> ptrNode5 = (std::make_shared<Node<int>>(5));
	PtrNode<int> ptrNode6 = (std::make_shared<Node<int>>(6));


	ptrNode1->setParent(ptrRoot);
	ptrNode2->setParent(ptrRoot);
	ptrNode3->setParent(ptrNode2);
	ptrNode4->setParent(ptrNode5);
	ptrNode5->setParent(ptrRoot);
	ptrNode6->setParent(ptrNode5);

	ptrRoot->m_pChilds.push_back(ptrNode1);
	ptrRoot->m_pChilds.push_back(ptrNode2);
	ptrRoot->m_pChilds.push_back(ptrNode5);

	ptrNode1->m_pChilds.push_back(ptrRoot);

	ptrNode2->m_pChilds.push_back(ptrRoot);
	ptrNode2->m_pChilds.push_back(ptrNode3);


	ptrNode5->m_pChilds.push_back(ptrRoot);
	ptrNode5->m_pChilds.push_back(ptrNode4);
	ptrNode5->m_pChilds.push_back(ptrNode6);

	ptrNode6->m_pChilds.push_back(ptrNode5);
	ptrNode4->m_pChilds.push_back(ptrNode5);

	return ptrRoot;
}

PtrBinaryNode<std::string> TreeGenerator::CreateStrBinaryTree()
{

	PtrBinaryNode<std::string> RootNode = (std::make_shared<BinaryNode<std::string>>("A"));


	PtrBinaryNode<std::string> FirstLvl = RootNode->addLNode(std::make_shared<BinaryNode<std::string>>("B"));
	FirstLvl->addRNode(std::make_shared<BinaryNode<std::string>>("E"));

	RootNode->addRNode(std::make_shared<BinaryNode<std::string>>("C"));

	PtrBinaryNode<std::string> SecondLvl = FirstLvl->addLNode(std::make_shared<BinaryNode<std::string>>("D"));
	SecondLvl->addRNode(std::make_shared<BinaryNode<std::string>>("N"));
	SecondLvl->addLNode(std::make_shared<BinaryNode<std::string>>("M"));

	return RootNode;
}
