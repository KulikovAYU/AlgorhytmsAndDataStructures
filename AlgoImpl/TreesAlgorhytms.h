#pragma once
#include <Node.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <map>
/// <summary>
/// Левосторонний обход дерева
/// http://khpi-iip.mipk.kharkiv.edu/library/datastr/book_sod/kgsu/din_0049.html
/// </summary>
class TreesAlgo_1
{
public:
	template <typename T>
	static void LeftSideGone(PtrBinaryNode<T> ptrCurrentNode)
	{
		if (!ptrCurrentNode)
			return;

		LeftSideGone(ptrCurrentNode->getLNode());
		LeftSideGone(ptrCurrentNode->getRNode());

		std::cout << ptrCurrentNode->getValue() << std::endl;
	}
};


/// <summary>
/// Сумма всех листьев дерева
/// https://www.youtube.com/watch?v=0qgaIMqOEVs&list=PLDV1Zeh2NRsDfGc8rbQ0_58oEZQVtvoIc&index=3
/// </summary>
class TreesAlgo_2
{
public:
	
	static int SummNodes(PtrNode<int> ptrCurrentNode)
	{
		if (!ptrCurrentNode)
			return 0;

		if (isLeaf(ptrCurrentNode))
			return ptrCurrentNode->getValue();
		
		int nSumm = 0;
		for (size_t i = 0; i < ptrCurrentNode->getChildsCnt(); ++i)
			nSumm += SummNodes(ptrCurrentNode->getNode(i));

		return nSumm;
	}

private:
	static bool isLeaf(PtrNode<int> ptrCurrentNode)
	{
		return ptrCurrentNode->getChildsCnt() == 0;
	}
};


/// <summary>
/// Высота дерева
/// </summary>
class TreesAlgo_3
{
public:

	template<typename T>
	static int GetHeight(PtrBinaryNode<T> ptrCurrentNode)
	{
		
		if (!ptrCurrentNode)
			return -1;

		int nLeft = GetHeight(ptrCurrentNode->getLNode());
		int nRight = GetHeight(ptrCurrentNode->getRNode());
		return std::max(nLeft, nRight) + 1;
	}
};

//построить дерево по любой вершине
class TreesAlgo_4
{
public:

	template<typename T>
	static PtrNode<T> BuildNewTreeByVertex(const PtrNode<T>& srcNode, const PtrNode<T>& ptrParentNode = nullptr)
	{

		static std::vector<PtrNode<T>> usedItems;

		if (!srcNode || std::find_if(usedItems.begin(), usedItems.end(), [&srcNode](const PtrNode<T>& val) {return srcNode->getValue() == val->getValue(); }) != usedItems.end())
			return nullptr;

		if (ptrParentNode && srcNode->getValue() == ptrParentNode->getValue())
			return nullptr;

		PtrNode<T> newNode = std::make_shared<Node<T>>(srcNode->getValue());
		usedItems.push_back(newNode);


		for (uint32_t i = 0; i < srcNode->getChildsCnt(); ++i)
		{
			const PtrNode<T>& childNode = srcNode->getNode(i);
		
			const PtrNode<T>& newChildNode = BuildNewTreeByVertex(childNode, srcNode);
			if (newChildNode)
			{
				newNode->addNode(newChildNode);
			}
		}

		return newNode;
	}

	template<typename T>
	static PtrNode<T> findReqNode(T val, const PtrNode<T>& currItem)
	{
		std::queue<PtrNode<T>> queue;
		queue.push(currItem);

		while (!queue.empty())
		{
			const PtrNode<T>& node = queue.front();
			queue.pop();
			if (node->getValue() == val)
				return node;

			for (size_t i = 0; i < node->getChildsCnt(); ++i)
				queue.push(node->getNode(i));
		}

		return nullptr;
	}
};


//найти центр дерева
//https://www.youtube.com/watch?v=nzF_9bjDzdc&list=PLDV1Zeh2NRsDfGc8rbQ0_58oEZQVtvoIc&index=4
class TreesAlgo_5 
{
public:
	template<typename T>
	static std::vector<PtrNode<T>> GetCenterOfTheTree(const PtrNode<T>& srcNode)
	{
		std::vector<PtrNode<T>> resNodes;
		std::map<PtrNode<T>, int> markers;
		std::vector<PtrNode<T>> markedNode;
		int nCounter = 3;
		do 
		{
			markedNode.clear();
			MarkTree(srcNode, markers, markedNode);
			markedNode.clear();
			ReduceNodeWeight(srcNode, markers, markedNode);
			resNodes.clear();
			markedNode.clear();
			GetCountOfNode(srcNode, markers, markedNode, resNodes);
		} while (resNodes.size() > 2);
	

		return resNodes;
	}

private:


	template<typename T>
	static void MarkTree(const PtrNode<T>& srcNode, std::map<PtrNode<T>,int>& markers, std::vector<PtrNode<T>>& markedNode)
	{
		if (!srcNode)
			return;

		if (std::find(markedNode.cbegin(), markedNode.cend(), srcNode) != markedNode.cend())
			return;
		markedNode.push_back(srcNode);

		auto it = std::find_if(markers.cbegin(), markers.cend(), [&srcNode](const std::pair<PtrNode<T>, int>& val) {return (val.first)->getId() == srcNode->getId(); });
		if (it != markers.cend() && (it->second) == 0)
			return;

		int nChildNodes = srcNode->getChildsCnt();
		bool bIsLeafNode = (nChildNodes == 0);
		if (bIsLeafNode)
		{
			markers[srcNode] = 1;
		}
		else
		{
			markers[srcNode] = nChildNodes;
		}

		for (int i = 0; i < nChildNodes; ++i)
		{
			const PtrNode<T>& childNode = srcNode->getNode(i);
			MarkTree(childNode , markers, markedNode);
		}
	}


	template<typename T>
	static void ReduceNodeWeight(const PtrNode<T>& srcNode, std::map<PtrNode<T>, int>& markers, std::vector<PtrNode<T>>& markedNode)
	{
		if (!srcNode)
			return;

		if (std::find(markedNode.cbegin(), markedNode.cend(), srcNode) != markedNode.cend())
			return;

		//auto it = std::find_if(markers.cbegin(), markers.cend(), [&srcNode](const std::pair<PtrNode<T>, int>& val) {return (val.first)->getId() == srcNode->getId(); });

		markedNode.push_back(srcNode);

		int nodeWeight = markers[srcNode];
		if (nodeWeight == 0)
			return;
		else if (nodeWeight == 1)
		{
			markers[srcNode] -= 1;
		}
		
		

		int nChildNodes = srcNode->getChildsCnt();
		for (int i = 0; i < nChildNodes; ++i)
		{
			const PtrNode<T>& childNode = srcNode->getNode(i);
			ReduceNodeWeight(childNode ,markers, markedNode);
		}
	}


	template<typename T>
	static void GetCountOfNode(const PtrNode<T>& srcNode, std::map<PtrNode<T>, int>& markers, std::vector<PtrNode<T>>& markedNode, std::vector<PtrNode<T>>& resNodes)
	{

		if (!srcNode)
			return;

		if (std::find(markedNode.cbegin(), markedNode.cend(), srcNode) != markedNode.cend())
			return;
		markedNode.push_back(srcNode);

		auto it = std::find_if(markers.cbegin(), markers.cend(), [&srcNode](const std::pair<PtrNode<T>, int>& val) {return (val.first)->getId() == srcNode->getId(); });
		
		if (it != markers.cend() && (it->second) == 0)
			return;
		
		resNodes.push_back(srcNode);
		for (int i = 0; i < srcNode->getChildsCnt(); ++i)
		{
			const PtrNode<T>& childNode = srcNode->getNode(i);
			GetCountOfNode(childNode , markers, markedNode, resNodes);
		}


	}


};



