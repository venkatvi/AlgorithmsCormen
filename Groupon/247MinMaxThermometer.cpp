#include <iostream>
#include <vector>
#include <unistd.h>
#include <random>
#include <thread>
using namespace std;
struct TemperatureNode{
  double maxTemp;
  double minTemp;
  double curTemp;
};
class CircularQueue{
private:
  int qSize, head, tail;
  vector<TemperatureNode> elems;
  void updateMinMaxInfoForAllNodes(){
    double minX = INT_MAX, maxX = INT_MIN;
    for(auto& x : elems){
      if(x.curTemp < minX){
        x.minTemp = x.curTemp;
        minX = x.curTemp;
      }else{
        x.minTemp = minX;
      }
      if(x.curTemp > maxX){
        x.maxTemp = x.curTemp;
        maxX = x.curTemp;
      }else{
        x.maxTemp = maxX;
      }
    }
  }
public:
  CircularQueue():qSize(24), elems(24), head(0), tail(0){}
  void enQ(double temp){
    TemperatureNode t;
    t.curTemp = temp;

    if(elems.size() == qSize){
      deQ();
      elems[tail] = t;
      updateMinMaxInfoForAllNodes();
    }
    if(tail == elems.size()){
      tail = 0;
    }
    tail++;
  }
  void deQ(){
    head++;
    if(head == elems.size()){
      head = 0;
    }
  }
  TemperatureNode top(){
    return elems[head];
  }
  bool isEmpty(){
    return elems.size() == 0;
  }
};

class Solution{
private:
  static CircularQueue tempQ;
  thread first;
public:
  vector<double> getCurMinMax();
  static void senseTemperature();
  void endSensing();
  Solution(){
   thread second(Solution::senseTemperature);
   first.swap(second);
  }
};
CircularQueue Solution::tempQ;
void Solution::senseTemperature(){
  cout << "Starting to sense temperature" << endl;
  unsigned int microseconds=2000000;
  int i=0;
  double low = -50, high = 150;

  while(i<100000){
    usleep(microseconds);
    double temp = ((double)rand()/ (RAND_MAX));
    temp = low + temp*(high-low);
    cout << "----"<< temp << "-----"<< endl;
    CircularQueue& q = Solution::tempQ;
    q.enQ(temp);
  }
}
void Solution::endSensing(){
  first.join();
}
vector<double> Solution::getCurMinMax(){
  CircularQueue& q = Solution::tempQ;
  TemperatureNode t = q.top();
  vector<double> minMax = {t.minTemp, t.maxTemp};
  return minMax;
}
int main(int argc, char** argv){
  Solution s;
  for(int i=0; i<10; i++){
    usleep(3000000);
    vector<double> minMax = s.getCurMinMax();
    cout << "Current Min Max: " << minMax[0] << " " << minMax[1] << endl;
   }
   s.endSensing();
}
