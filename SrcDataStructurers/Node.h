#pragma once
#include <memory>
#include <vector>


class TreeGenerator;

template<typename T>
class Node;

template<typename T>
using PtrNode = std::shared_ptr<Node<T>>;


template<typename T>
class BinaryNode;

template<typename T>
using PtrBinaryNode = std::shared_ptr<BinaryNode<T>>;


template<typename T>
class BinaryNode
{
	friend class TreeGenerator;
public:
	BinaryNode()
	{
		++m_nId;
	}
	explicit BinaryNode(T value) : m_value(value)
	{

	}

	T getValue()const {
		return m_value;
	}


	PtrBinaryNode<T>& addLNode(PtrBinaryNode<T> lNode) {
		m_pLeft = lNode;
		return m_pLeft;
	}

	PtrBinaryNode<T>& addRNode(PtrBinaryNode<T> rNode) {
		m_pRight = rNode;
		return m_pRight;
	}


	PtrBinaryNode<T> getLNode() const {
		return m_pLeft;
	}

	PtrBinaryNode<T> getRNode() const {
		return m_pRight;
	}


private:
	PtrBinaryNode<T> m_pLeft;
	PtrBinaryNode<T> m_pRight;
	T m_value;
	static int m_nId;
};
template<typename T>
int BinaryNode<T>::m_nId = 0;

template<typename T>
class Node
{
	friend class TreeGenerator;
public:
	Node()
	{
		++m_nId;
	}
	explicit Node(T value) : m_value(value)
	{

	}

	T getValue()const {
		return m_value;
	}


	size_t getChildsCnt() const {
		return m_pChilds.size();
	}

	PtrNode<T>& getNode(size_t n) {
		return m_pChilds[n];
	}

	void addNode(const PtrNode<T>& newNode)
	{
		m_pChilds.push_back(newNode);
	}

	void setParent(const PtrNode<T>& parentNode) 
	{
		m_parentNode = parentNode;
	}

	PtrNode<T>& getParentNode() {
		return m_parentNode;
	}

	int getId() const { return m_nId; }

	bool operator ==(const PtrNode<T>& other) const 
	{
		return m_nId == other.m_nId;
	}

private:
	std::vector<PtrNode<T>> m_pChilds;
	T m_value;
	PtrNode<T> m_parentNode;
	static int m_nId;
};


template<typename T>
int Node<T>::m_nId = 0;

