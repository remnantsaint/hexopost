//树的双亲表示法
/*用一组连续空间存储树的结点，
并附设一个指示器指示其父结点的位置*/
//优点：容易找到父结点及其所有的祖先
//      能找到结点的子女和兄弟
//缺点：找结点的子女和兄弟比较费事。可能要遍历整个数组
typedef struct Ptnode
{
    int info;   //节点中元素
    int parent; //节点的父节点位置
} Ptnode;
typedef struct
{
    Ptnode nodes[MAX_NODE]; //存放树中的节点
    int n;                  //树中节点个数
} Ptree;

//树的孩子表示法
/*结点表中的每一元素又包含一个子表，
存放该结点的所有子结点。结点表顺序存放，子表用链接表示*/
//优点：求某个结点的子女运算很容易实现
//     找到结点的全部子女也很容易
//缺点:求某个结点的父母实现起来比较费事
typedef struct Ctnode
{
    int child;
    struct Ctnode *next;
} * childlink;
typedef struct
{
    int info;
    childlink children;
} CTBox;
CTBox nodes[MAX_NODE];

//树的孩子-兄弟表示法
/*在树的每个结点中，除信息域外，
增加指向其第一个子女和下一个兄弟的指针*/
typedef struct CSNode
{
    int info;
    struct CSNode *firstchild, *nextsibling;
} CSNode, *CSTree;
//优点：求根、判断树空、求长子、求节点右兄弟很容易
//缺点：求父节点较困难，需遍历

//将树转换成二叉树
/*步骤：连线：在兄弟之间加一连线
切线：对每个结点，除了其左孩子外，去除其与其余孩子之间的关系
旋转：以树的根结点为轴心，将整树顺时针转45°*/
//其右子树一定为空！
/*左指针指向它的第一个孩子
右指针指向它的右兄弟*/

//将二叉树转换成树
/*加线：若p结点是双亲结点的左孩子，则将p的右孩子，右孩子的右孩子，……沿分支找到的所有右孩子，都与p的双亲用线连起来
抹线：抹掉原二叉树中双亲与右孩子之间的连线
调整：将结点按层次排列，形成树结构*/

//森林转换成二叉树
/*将各棵树分别转换成二叉树
将每棵树的根结点用线相连
以第一棵树根结点为二叉树的根，再以根结点为轴心，顺时针旋转，构成二叉树型结构*/

//二叉树转换成树、树林
/*抹线：将二叉树中根结点与其右孩子的连线，及沿右分支搜索到的所有右孩子间连线全部抹掉，使之变成孤立的二叉树
还原：将孤立的二叉树还原成树
  或者
左子树转换为它的子树
如果是根节点,右子树转换为另一颗树,如果不是，右子树转换为该节点的兄弟*/

//树和森林的遍历：
/*树的遍历{
    先根遍历：先根访问树的根结点，然后依次先根遍历根的每棵子树
    后根遍历：先依次后根遍历每棵子树，然后访问根结点
    
    先根遍历规则：若森林F为空, 返回；否则		
     访问F的第一棵树的根结点；
     先根次序遍历第一棵树的子树森林；
     先根次序遍历其它树组成的森林。

    中根遍历规则：若森林F为空，返回；否则
     中根次序遍历第一棵树的子树森林；
     访问F的第一棵树的根结点。
     中根次序遍历其它树组成的森林
}