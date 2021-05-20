
#include <iostream>


using namespace std;

template <class TYPE> 
class BinaryTree {
    public:
        BinaryTree();
        ~BinaryTree();
        void RemoveAll();
        void PreOrderTraverse(Node* pNode);

    protected:
        struct Node {
            TYPE data;
            Node* pLeft;
            Node* pRight;
        };

        Node* m_pNodeHead;
        Node* m_pNodeTail;
        void RemoveSubtree(Node* pNode);
        void InOrderTraverse(Node* pNode);
        void PreOrderTraverse_Stack(Node* pNode)
        void LevelOrderTraverse(Node* pNode);
};

template<class TYPE> 
BinaryTree<TYPE>::BinaryTree() {
    m_pNodeHead= new Node;
    m_pNodeTail=new Node;

    m_pNodeHead->pLeft=m_pNodeTail;
    m_pNodeHead->pRight=m_pNodeTail;

    m_pNodeTail->pLeft=m_pNodeTail;
    m_pNodeTail->pRight=m_pNodeTail;
}

template<class TYPE> 
BinaryTree<TYPE>::~BinaryTree() {
    RemoveAll();
    if (m_pNodeHead)
        delete m_pNodeHead;
    if (m_pNodeTail)
        delete m_pNodeTail;
}


void BinaryTree::PreOrderTraverse(Node* pNode) {
    if (pNode != m_pNodeTail)
    {
        Visit(pNode);
        PreOrderTraverse(pNode->pLeft);
        PreOrderTraverse(pNode->pRight);
    }
}

void BinaryTree::InOrderTraverse(Node* pNode) {
    if (pNode != m_pNodeTail)
    {
        InOrderTraverse(pNode->pLeft);
        Visit(pNode);
        InOrderTraverse(pNode->pRight);
    }
}

void BinaryTree::PreOrderTraverse_Stack(Node* pNode) {
    ListStack<Node*> stack;
    stack.Push(pNode);
    while (!stack.IsEmpty()) {
        pNode=stack.Pop();
        if (pNode != m_pNodeTail) {
            Visit(pNode);
            PreOrderTraverse(pNode->pLeft);
            PreOrderTraverse(pNode->pRight);
        }
    }

}

void BinaryTree::LevelOrderTraverse(Node* pNode) {
    ListQueue<Node*> Queue;
    Queue.Put(pNode);
    while (!Queue.IsEmpty()) {
        pNode = Queue.Pop();
        if (pNode != m_pNodeTail) {
            Visit(pNode);
            PreOrderTraverse(pNode->pLeft);
            PreOrderTraverse(pNode->pRight);
        }
    }

}

template <class TYPE>
void BinaryTree<TYPE>::RemoveAll() {
    RemoveSubTree(m_pNodeHead->pLeft);
    m_pNodeHead->pLeft=m_pNodeTail;
}

template <class TYPE>
void BinaryTree<TYPE>::RemoveSubtree(Node * pNode) {
    if (pNode != m_pNodeTail) {
        RemoveSubtree(pNode->pLeft);
        RemoveSubtree(pNode->pRight);
        delete pNode;
    }

}
