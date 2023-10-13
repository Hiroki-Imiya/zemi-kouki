typedef char BSTTREE_K_TYPE;
typedef int BSTTREE_V_TYPE;

struct node{
    BSTTREE_K_TYPE *key;
    BSTTREE_V_TYPE value;
    BSTTREE_V_TYPE *lines;
    struct node *left;
    struct node *right;
};
typedef struct node BSTTREE_NODE;

int cntNode(BSTTREE_NODE *p,int cnt);

void destoryNode(BSTTREE_NODE *p);

void destoryBSTree(BSTTREE_NODE *p);

BSTTREE_NODE *findNode(BSTTREE_NODE *p,BSTTREE_K_TYPE *x);

BSTTREE_NODE *createNode(BSTTREE_K_TYPE *x,BSTTREE_V_TYPE line);

BSTTREE_NODE *insertNode(BSTTREE_NODE *p,BSTTREE_K_TYPE *x,BSTTREE_V_TYPE line);

int isLeafNode(BSTTREE_NODE *p);

void printBSTree(BSTTREE_NODE *p);