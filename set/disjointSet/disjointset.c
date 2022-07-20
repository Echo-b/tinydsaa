#include "define.h"

/**
 * @brief 
 * init all the node as a single tree
 * @param S size
 * @return true 
 * @return false 
 */
bool makeset(int S[], int size){
  for(int i = 0; i < size; ++i)
    S[i] = -1;
}

/**
 * @brief 
 * find the tree root
 * @param S 
 * @param x 
 * @return int 
 */
int find(int S[],int x){
  while(S[x] > 0)
    x = S[x];
  return x;
}


/**
 * @brief 
 * merge two trees
 * @param S 
 * @param root1 
 * @param root2 
 * @return true 
 * @return false 
 */
bool Union(int S[],int root1, int root2){
  S[root2] = root1;
}
