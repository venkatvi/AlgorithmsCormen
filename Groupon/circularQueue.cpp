#include <iostream>
#include <random>
#include <vector>
using namespace std;
class CQ{
public:
  CQ(size_t n):elems(n), qSize(n), head(0), tail(0), itemsCnt(0){}
  void enQ(int elem){
    if(tail == elems.size()){
      deQ();
      tail = 0;
    }
    cout << "Head:" << head << " Tail:" << tail << endl;
    elems[tail] = elem;
    itemsCnt++;
    tail++;
  }
  void deQ(){
    if(itemsCnt){
      head++;
      if(head == elems.size()){
        head = 0;
      }
      itemsCnt--;
    }
  }
  int top(){
    if(itemsCnt){
      return elems[head];
    }else{
      return -1;
    }
  }
private:
  size_t qSize, head=0, tail=0, itemsCnt=0;
  vector<int> elems;
};
int main(int argc, char** argv){
  size_t n = 1 + (rand()%5) ;
  CQ Q(n);
  for(int  i=0; i<15; i++){
    int op = 1 + (rand()%3);
    switch(op){
      case 1:
        {
          int elem = 1 + (rand()%100);
          cout << "Enqing..." << elem << endl;
          Q.enQ(elem);
          break;
        }
      case 2:
        {
          cout << "Dqing.. " << endl;
          Q.deQ();
          break;
        }
     case 3:
        cout << "Top: " << Q.top() << endl;
        break;
     default:
        cout << "Noop" << endl;
    }
  }
}
