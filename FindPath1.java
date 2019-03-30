void FindPath(BinaryTreeNode* pRoot,int expectedSum)
{
 if(pRoot==NULL)
 return;
 std::vector<int> path;
 int currentSum=0;
 FindPath(pRoot,expectedSum,path,currentSum);
 }

void FindPath
(
 BinaryTreeNode* pRoot,
 int expectedSum,
 std::vector<int>& path,
 int currentSum
 )
{
 currentSum +=pRoot->value;
 path.push_back(pRoot->value);
 //??????,???????????????,???????
 bool isLeaf =(pRoot->lchild==NULL&&pRoot->rchild==NULL);
 if(currentSum==expectedSum&&isLeaf)
 {
  printf("A path is found:");
  std::vector<int>::iterator iter=path.begin();
  for(;iter!=path.end();++iter)
  printf("%d\t",*iter);
  printf("\n");
 }
 //???????,????????
 if(pRoot->lchild!=NULL)
 FindPath(pRoot->lchild,exception,path,currentSum);
 if(pRoot->rchild!=NULL)
 FindPath(pRoot->rchild,expection,path,currentSum);

 //????????,??????????
path.pop_back();
}