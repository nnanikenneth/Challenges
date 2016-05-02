#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <iostream>
#include <string.h>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <fstream>

using namespace std;

///MODULARIZE THE PROGRAM
///MAKE MORE READABLE

void getSample(string word, std::vector<string> &sample){ ///passed by reference
    sample[word.length()] = word;
}

bool exist(string word, std::vector<bool> &flag){ ///passed by value
    if(flag[word.length()] == false)return true; //if not exist make existent
    return false;
}

void makeExist(string word, std::vector<bool> &flag){
  flag[word.length()] = true;
}

int main(){
   ifstream in("/Users/tech8/Desktop/challenge_dictionary.txt");
   ofstream out("/Users/tech8/Desktop/cnt.txt"); ///deprecated for now
   int maxx = 0;
   int cnt = 0;
   std::vector<int> wdcnt(100, 0);

   //sample and flags
   std::vector<bool> flag(100, false);
   std::vector<string> sample(100); ///push back

   string word = "";
   while(word != "last_word_npos"){
      in >> word;
      int temp_len = word.length();
      wdcnt[temp_len]++;
      if(temp_len > maxx)maxx = temp_len;

      //added to prune a simple prune model
      if(exist(word, flag)){  ///using bfs model
          getSample(word, sample);
          makeExist(word, flag);
      }
      //end prune

      cnt++;
   }
   out << "TOTAL TEXT PARSED: " << cnt << endl;
   ///text nzer
   out << "(SIZE) " << " " << "(COUNTER OF NUMBER OF WORDS OF SIZE)" << " ==>> " << "(SAMPLE_SHOWING_EXISTENCE)" << endl;

   for(int i = 0; i < wdcnt.size(); i++){
      if(wdcnt[i] != 0){
        out << i << " " << wdcnt[i] << " ==>> " << sample[i] << endl;
      }
   }out << endl;
}
