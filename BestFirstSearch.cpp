#include <iostream>
#include <fstream>
#include <sys/time.h>
#include <string>
#include <vector>
#include <sstream>
#include <queue>
using namespace std;

struct Node{
  Node * yeschild;
  Node * nochild;
  int level;
  int profit;
  int weight;
  int bound;
};

int bound(Node * n, vector<int> p, vector<int> w, int weightLimit, int numItems){
  int retval = n->profit;
  int currWeight = n->weight;
  bool broke = false;
  for(int i=n->level+1; i<numItems;i++){
    if(!broke && currWeight + w.at(i) <= weightLimit){
      retval += p.at(i);
    } else if(!broke && currWeight + w.at(i) > weightLimit){
      retval += p.at(i) * ((w.at(i)-((currWeight + w.at(i)) - weightLimit))/w.at(i));
      broke = true;
    }
  }

  return retval;
}
int main(int argc, char * argv[]){
  if(argc != 3){
    perror("Error: must be run like \n  ./BestFirstSearch <input.txt> <output.txt>");
  }

  int numItems = 0;
  vector<int> p;
  vector<int> w;
  int weightLimit = 0;

  string temp;
  ifstream input(argv[1]);
  ofstream output;


  //Get items from input
  int currLine = 0;
  if(input.is_open()){
    while(input.good()){
      getline(input,temp);
      if(!temp.empty() && currLine == 0){
        vector<int> vect;
        stringstream ss(temp);
        while(ss.good()){
          string substr;
          getline(ss,substr,',');
          vect.push_back(stoi(substr,nullptr,10));
        }
        numItems = vect.at(0);
        weightLimit = vect.at(1);
        currLine++;
      }else if(!temp.empty() && currLine > 0){
        vector<int> vecttemp;
        stringstream sstemp(temp);
        while(sstemp.good()){
          string substrtemp;
          getline(sstemp,substrtemp,',');
          vecttemp.push_back(stoi(substrtemp,nullptr,10));
        }
        w.push_back(vecttemp.at(0));
        p.push_back(vecttemp.at(1));

        currLine++;
      }
    }
  }
  //sort items
  int temp_price;
  int temp_weight;
  for(int l=0; l < numItems; l++){
    for(int x=1; x < (numItems-l); x++){
      if(p.at(x-1)/w.at(x-1) < p.at(x)/w.at(x)){
        temp_price = p.at(x-1);
        temp_weight = w.at(x-1);
        p.at(x-1) = p.at(x);
        w.at(x-1) = w.at(x);
        p.at(x) = temp_price;
        w.at(x) = temp_weight;
      }
    }
  }
  Node *v = new Node;
  priority_queue<Node *> PQ;
  v->level = 0;
  v->profit = 0;
  v->weight = 0;
  v->bound = bound(v, p, w, weightLimit,numItems);

}
