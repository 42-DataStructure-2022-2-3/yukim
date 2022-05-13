#include "bintree.h"

int main(void)
{
    BinTreeNode pNode;
    BinTreeNode *pFirstLeftNode;
    BinTreeNode *pFirstRightNode;
    
    BinTreeNode *pSecondLeftNode;
    BinTreeNode *pSecondRightNode;

    BinTreeNode *pSecondLeftNode2;
    BinTreeNode *pSecondRightNode2;

    pNode.data = 'A';
    pNode.visited = 0;
    pNode.pLeftChild = NULL;
    pNode.pRightChild = NULL;
    BinTree *pBinTree = makeBinTree(pNode);

    pNode.data++;
    pFirstLeftNode = insertLeftChildNodeBT(pBinTree->pRootNode, pNode); // B
    
    pNode.data++;
    pFirstRightNode = insertRightChildNodeBT(pBinTree->pRootNode, pNode); // C

     // Level 2
    pNode.data++;
    pSecondLeftNode = insertLeftChildNodeBT(pFirstLeftNode, pNode);  // D
    
    pNode.data++;
    pSecondRightNode = insertRightChildNodeBT(pFirstLeftNode, pNode); // E

    pNode.data++;
    pSecondLeftNode2 = insertLeftChildNodeBT(pFirstRightNode, pNode);  // F
    
    pNode.data++;
    pSecondRightNode2 = insertRightChildNodeBT(pFirstRightNode, pNode); // G
    
    // Level 3
    pNode.data++;
    insertLeftChildNodeBT(pSecondLeftNode, pNode);  // H
    
    pNode.data++;
    insertRightChildNodeBT(pSecondLeftNode, pNode); // I
    
    pNode.data++;
    insertLeftChildNodeBT(pSecondRightNode, pNode);  // J

    pNode.data++;
    insertRightChildNodeBT(pSecondLeftNode2, pNode); // K
    
    pNode.data++;
    insertLeftChildNodeBT(pSecondRightNode2, pNode);  // L
    
    BinTreeNode *pTerminalNode;
    pNode.data++;
    pTerminalNode = insertRightChildNodeBT(pSecondRightNode2, pNode); // M

    // printf(" %c \n", getLeftChildNodeBT(pBinTree->pRootNode)->data);
    // printf(" %c \n", getRightChildNodeBT(pBinTree->pRootNode)->data);
    deleteBinTreeNode(&pBinTree->pRootNode);
    deleteBinTree(pBinTree);
    preOrder(pBinTree->pRootNode);
    printf("\n=======================\n");
    inOrder(pBinTree->pRootNode);
    printf("\n=======================\n");
    postOrder(pBinTree->pRootNode);
    
    system("leaks a.out");
}
