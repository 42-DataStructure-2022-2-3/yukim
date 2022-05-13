#include "bintree.h"

BinTree* makeBinTree(BinTreeNode rootNode)
{
    BinTree *pBinTree;
    BinTreeNode *pRootNode;

    pBinTree = calloc(1, sizeof(BinTree));
    pRootNode = calloc(1, sizeof(BinTreeNode));
    pBinTree->pRootNode = pRootNode;
    *pRootNode = rootNode;

    return pBinTree;
}
BinTreeNode* getRootNodeBT(BinTree* pBinTree)
{
    return (pBinTree->pRootNode);
}

BinTreeNode* insertLeftChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element)
{
    BinTreeNode *pChild;
    
    if (pParentNode->pLeftChild)
    {
        printf ("LeftChild Node already exist \n");
        return (NULL);
    }
    pChild = calloc(1, sizeof(BinTreeNode));
    *pChild = element;
    pParentNode->pLeftChild = pChild;
    return pChild;
}
BinTreeNode* insertRightChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element)
{
    BinTreeNode *pChild;
    
    if (pParentNode->pRightChild)
    {
        printf ("RightChild Node already exist \n");
        return (NULL);
    }
    pChild = calloc(1, sizeof(BinTreeNode));
    *pChild = element;
    pParentNode->pRightChild = pChild;
    return pChild;
}
BinTreeNode* getLeftChildNodeBT(BinTreeNode* pNode)
{
    return (pNode->pLeftChild);
}
BinTreeNode* getRightChildNodeBT(BinTreeNode* pNode)
{
    return (pNode->pRightChild);
}
void deleteBinTree(BinTree* pBinTree)
{
    if (pBinTree)
    {
        deleteBinTreeNode(&pBinTree->pRootNode);
        free(pBinTree);
        memset(pBinTree, 0, sizeof(BinTree));
    }
}

void deleteBinTreeNode(BinTreeNode** pNode)
{
    if (*pNode)
    {
        deleteBinTreeNode(&(*pNode)->pLeftChild);
        deleteBinTreeNode(&(*pNode)->pRightChild);
        free(*pNode);
        *pNode = NULL;
    }
}
