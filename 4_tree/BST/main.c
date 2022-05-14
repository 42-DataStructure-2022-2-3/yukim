#include "bintree.h"

static BinTree *InitTree(void);

static void    preOrder(BinTreeNode *pTreeNode)
{
    if (!pTreeNode)
        return ;
    printf("%d ", pTreeNode->data);
    pTreeNode->visited = 1;
    preOrder(pTreeNode->pLeftChild);
    preOrder(pTreeNode->pRightChild);
}


int main(void)
{
    BinTreeNode key;
    BinTreeNode *pSearchRetNode;
    BinTree *pBinTree = InitTree();

    key.visited = 0;
    key.pLeftChild = NULL;
    key.pRightChild = NULL;

    printf("Init pBinTree => \n\t[ ");
    preOrder(pBinTree->pRootNode);
    printf("]\n");

    // // search BST
    // key.data = 24;
    // pSearchRetNode = searchBST(pBinTree, key);
    // printf ("pSearchRetNode = %d\n", pSearchRetNode->data);
    // key.data = 40;
    // pSearchRetNode = searchBST(pBinTree, key);
    // printf ("pSearchRetNode = %d\n", pSearchRetNode->data);
    // key.data = 0;
    // pSearchRetNode = searchBST(pBinTree, key);

    // // insertBSTNode
    // key.data = 21;
    // insertBSTNode(pBinTree, key);
    // key.data = 23;
    // insertBSTNode(pBinTree, key);
    // key.data = 24;
    // insertBSTNode(pBinTree, key);
    // printf("After Insert 21, 23 pBinTree => \n\t[ ");
    // preOrder(pBinTree->pRootNode);
    // printf("]\n");

    // // Delete LeafNode
    // key.data = 22;
    // deleteBSTNode(pBinTree, key);
    // printf("After Delete LeafNode pBinTree => \n\t[ ");
    // preOrder(pBinTree->pRootNode);
    // printf("]\n");

    // // Delete have only Child Node
    // key.data = 24;
    // deleteBSTNode(pBinTree, key);
    // printf("After Delete have only Child Node pBinTree => \n\t[ ");
    // preOrder(pBinTree->pRootNode);
    // printf("]\n");

    // // Delete have two Child Node
    // key.data = 20;
    // deleteBSTNode(pBinTree, key);
    // printf("After Delete Left Node which have two Child pBinTree => \n\t[ ");
    // preOrder(pBinTree->pRootNode);
    // printf("]\n");
    // key.data = 40;
    // deleteBSTNode(pBinTree, key);
    // printf("After Delete Rignt Node which have two Child pBinTree => \n\t[ ");
    // preOrder(pBinTree->pRootNode);
    // printf("]\n");
    // key.data = 30;
    // deleteBSTNode(pBinTree, key);
    // printf("After Delete Root Node which have two Child pBinTree => \n\t[ ");
    // preOrder(pBinTree->pRootNode);
    // printf("]\n");
}   

static BinTree *InitTree(void)
{
    BinTreeNode element;
    BinTreeNode *pFirstLeftNode;
    BinTreeNode *pFirstRightNode;
    
    BinTreeNode *pSecondLeftNode;
    BinTreeNode *pSecondRightNode;

    BinTreeNode *pSecondLeftNode2;
    BinTreeNode *pSecondRightNode2;

    element.data = 30;
    element.visited = 0;
    element.pLeftChild = NULL;
    element.pRightChild = NULL;
    BinTree *pBinTree = makeBinTree(element);

    element.data = 20;
    pFirstLeftNode = insertLeftChildNodeBT(pBinTree->pRootNode, element); // 20
    
    element.data = 40;
    pFirstRightNode = insertRightChildNodeBT(pBinTree->pRootNode, element); // 40

     // Level 2
    element.data = 10;
    pSecondLeftNode = insertLeftChildNodeBT(pFirstLeftNode, element);  // 10
    
    element.data = 24;
    pSecondRightNode = insertRightChildNodeBT(pFirstLeftNode, element); // 24

    element.data = 34;
    pSecondLeftNode2 = insertLeftChildNodeBT(pFirstRightNode, element);  // 34
    
    element.data = 46;
    pSecondRightNode2 = insertRightChildNodeBT(pFirstRightNode, element); // 46
    
    // Level 3
    element.data = 6;
    insertLeftChildNodeBT(pSecondLeftNode, element);  // 6
    
    element.data = 14;
    insertRightChildNodeBT(pSecondLeftNode, element); // 14
    
    element.data = 22;
    insertLeftChildNodeBT(pSecondRightNode, element);  // 22

    return (pBinTree);
}