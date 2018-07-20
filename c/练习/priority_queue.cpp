#include <iostream>
#include <queue>


using namespace std;


struct node{
  int idx;
  int key;
  node(int a=0, int b=0):idx(a), key(b){}
};

struct cmp{
  bool operator()(node a, node b){
    return a.key > b.key;
  }
};
int main(){
  
  priority_queue<node, vector<node>, cmp> q;
  
  int i;
  for(i=0;i<10;++i){
    q.push(node(i, i));
  }

  while(!q.empty()){
    cout<<q.top().key<<endl;
    q.pop();
  }
  return 0;
}