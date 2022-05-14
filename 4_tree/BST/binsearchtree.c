#include "bintree.h"

static BinTreeNode *searchRecursive(BinTreeNode *pNode, BinTreeNode key)
{
    if (!pNode)
    {
        printf("It doesn't exist.\n");
        return (NULL);
    }
    if (key.data == pNode->data)
        return (pNode);
    else if ( key.data < pNode->data)
        searchRecursive(pNode->pLeftChild, key);
    else if (pNode->data < key.data)
        searchRecursive(pNode->pRightChild, key);
}

BinTreeNode* searchBST(BinTree *pBinTree, BinTreeNode key)
{
    if (!pBinTree)
        return NULL;
    return (searchRecursive(pBinTree->pRootNode, key));
}

static BinTreeNode *insertBSTNodeRecur(BinTreeNode *pNode, BinTreeNode key)
{
    if (key.data == pNode->data)
    {
        printf("It already exists.\n");
        return (NULL);
    }
    else if ( key.data < pNode->data)
    {
        if (pNode->pLeftChild)
            insertBSTNodeRecur(pNode->pLeftChild, key);
        else
            return (pNode);    
    }
    else if (pNode->data < key.data)
    {
        if (pNode->pRightChild)
            insertBSTNodeRecur(pNode->pRightChild, key);
        else
            return (pNode);       
    }
}

BinTreeNode *insertBSTNode(BinTree *pBinTree, BinTreeNode key)
{
    BinTreeNode *parentNode;

    parentNode = insertBSTNodeRecur(pBinTree->pRootNode, key);
    if (!parentNode)
        return (NULL);
    if (parentNode->data < key.data)
        return (insertLeftChildNodeBT(parentNode, key));
    else
        return (insertRightChildNodeBT(parentNode, key));
}

static BinTreeNode *deleteBSTNodeRecur(BinTreeNode *parentNode, BinTreeNode key)
{
    if (!parentNode)
        return (NULL);
    if (key.data == parentNode->pLeftChild->data || key.data == parentNode->pRightChild->data )
        return (parentNode);
    else if ( key.data < parentNode->data)
        deleteBSTNodeRecur(parentNode->pLeftChild, key);  
    else if (parentNode->data < key.data)
        deleteBSTNodeRecur(parentNode->pRightChild, key);  
}

//만약 14 를 삭제하는경우 tree 41page
static BinTreeNode* deleteLeafNode(BinTree *pBinTree, BinTreeNode key)
{
    BinTreeNode *pDeleteNode;
    BinTreeNode *parentNode;

    if (pBinTree->pRootNode->data == key.data)
    {
        pDeleteNode = pBinTree->pRootNode;
        pBinTree->pRootNode = NULL;
        return pDeleteNode;
    }
    parentNode = deleteBSTNodeRecur(pBinTree->pRootNode, key);
    if (parentNode->pLeftChild->data == key.data)
    {
        pDeleteNode = parentNode->pLeftChild;
        parentNode->pLeftChild = NULL;
    }
    else
    {
        pDeleteNode = parentNode->pRightChild;
        parentNode->pRightChild = NULL;
    }
    return pDeleteNode;
}
static BinTreeNode *deleteOnlyChildNode(BinTree *pBinTree, BinTreeNode *pDeleteNode)
{
    BinTreeNode *parentNode;

    if (pDeleteNode->data == pBinTree->pRootNode->data)
    {
        pBinTree->pRootNode = pDeleteNode->pLeftChild;
        return (pDeleteNode);
    }
    parentNode = deleteBSTNodeRecur(pBinTree->pRootNode, *pDeleteNode);
    if (pDeleteNode->pLeftChild)
    {
        if (parentNode->pLeftChild->data == pDeleteNode->data)
            parentNode->pLeftChild = pDeleteNode->pLeftChild;
        else 
            parentNode->pRightChild = pDeleteNode->pLeftChild;
    }
    else
    {
        if (parentNode->pLeftChild->data == pDeleteNode->data)
            parentNode->pLeftChild = pDeleteNode->pRightChild;
        else 
            parentNode->pRightChild = pDeleteNode->pRightChild;
    }
    return pDeleteNode;
}


BinTreeNode* deleteBSTNode(BinTree *pBinTree, BinTreeNode key)
{
    BinTreeNode *pDeleteNode;
    BinTreeNode *parentNode;
    
    pDeleteNode = searchBST(pBinTree, key);
    if (!pDeleteNode)
        return (NULL);
    else if (!pDeleteNode->pLeftChild && !pDeleteNode->pRightChild) // 단말 노드인 경우
        pDeleteNode = deleteLeafNode(pBinTree, key);
     // 자식이 2개인 경우
    else if (pDeleteNode->pLeftChild && pDeleteNode->pRightChild)
    {
        BinTreeNode *pCandidate = pDeleteNode->pLeftChild;
        BinTreeNode *pParentCandidate = pDeleteNode;
        while (pCandidate->pRightChild)
        {
            pParentCandidate = pCandidate;
            pCandidate = pCandidate->pRightChild;
        }
        if (pDeleteNode->data != pBinTree->pRootNode->data)//지울노드가 루트노드가 아닌경우
        {
            parentNode = deleteBSTNodeRecur(pBinTree->pRootNode, key);
            if (parentNode->pLeftChild->data == pDeleteNode->data) // 지울노드가 왼쪽에있다
                parentNode->pLeftChild = pCandidate;
            else// 지울 노드가 오른쪽에있다
                parentNode->pRightChild = pCandidate;
        }
        pParentCandidate->pRightChild = pCandidate->pLeftChild;
        pCandidate->pLeftChild = pDeleteNode->pLeftChild;
        pCandidate->pRightChild = pDeleteNode->pRightChild;            
    }
    else// 자식이 1개인 경우
        pDeleteNode = deleteOnlyChildNode(pBinTree, pDeleteNode);

    pDeleteNode->pLeftChild = NULL;
    pDeleteNode->pRightChild = NULL;
    return pDeleteNode;
}