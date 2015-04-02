#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <string.h>
#include <algorithm>
#include <assert.h>
#include "key.h"
using namespace std;


vector<vector<char> >arry; //global variable 

map<Key, int>dynamic; //dynamic program check

  int games_size;
  int row_first;
  int col_second;
  
void print_vect(const vector<vector<char> >&A, int r, int c){

  //map<Key, int>::iterator it;
  for(unsigned int i = 0; i < r; ++i)
  {
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    for(unsigned int j = 0; j < c; ++j)
    {
      Key t1(i, j);
      //it = A.find(t1);
      cout << "(" << i << ":" << j << ")" << A[i][j] << "       ";
    }
    cout << endl;
  }
  cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

}
void print_vect_int(const vector<vector<int> >&A, int r, int c){

  //map<Key, int>::iterator it;
  for(unsigned int i = 0; i < r; ++i)
  {
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    for(unsigned int j = 0; j < c; ++j)
    {
      cout << "(" << i << ":" << j << ")" << A[i][j] << "       ";
    }
    cout << endl;
  }
  cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

}

/*
 * input: 2d vector, row size, col size
 */



int min_value(int a, int b){
  if(a >= b) return b;
  return a;
}

int find_max(const vector<vector<int> >&A, int r, int c)
{
  int max = 0;
  for(unsigned int i = 0; i < r; ++i){
    for(unsigned int j = 0; j < c; ++j){
      if(A[i][j] > max) max = A[i][j];
    }
  }
  return max;
  
}
int r_row(const vector<vector<int> >&A, int r, int c)
{
  int max = 0;
  int x = 0;
  for(unsigned int i = 0; i < r; ++i){
    for(unsigned int j = 0; j < c; ++j){
      if(A[i][j] > max) {
        max = A[i][j];
        x = i;
      }
    }
  }
  return x;
  
}
int r_col(const vector<vector<int> >&A, int r, int c)
{
  int max = 0;
  int y = 0;
  for(unsigned int i = 0; i < r; ++i){
    for(unsigned int j = 0; j < c; ++j){
      if(A[i][j] > max){
        y = j;
        max = j;
      }
    }
  }
  return y;
  
}
int s_max(const vector<vector<int> >&A, int r, int c, int max, int r_r, int r_c){
  int sec_max = 0;
  for(unsigned int i = 0; i < r; ++i){
    for(unsigned int j = 0; j < c; ++j){
      if(A[i][j] > sec_max){
        if(A[i][j] < max || (i!=r_r && j!=r_c)){
          sec_max = A[i][j];
        }
      }
    }
  }
  return sec_max;
}
void write_txt(char* file_open, char* file_write){
  ifstream ifs;
  ofstream ofs;
  vector<char>tmp;
  char input_tmp;
  int run = 1;
  
  ifs.open(file_open);
  ofs.open(file_write);
  int new_row;
  int new_col;
  int tmp_int;
  assert(!ifs.fail());
 
  
  ifs >> games_size;
  
  do
  {
    ifs >> row_first;
    ifs >> col_second;
    for(int i = 0; i < row_first; ++i)
    {
      for(int j = 0; j < col_second; ++j)
      {
        ifs >> input_tmp;
        
        tmp.push_back(input_tmp);
      }
      
      arry.push_back(tmp);
      tmp.clear();
    }
    //print_vect(arry, row_first, col_second);
   
    int weight[row_first+1][col_second+1];
    
    for(unsigned int a = 0; a < row_first; ++a){
      for(unsigned int b = 0; b < col_second; ++b){
        weight[a][b] = 0;
      }
    }
    for(unsigned int b = 0; b < row_first; ++b){
      if(arry[b][col_second-1] == 'F') weight[b][col_second-1] = 1;
      else weight[b][col_second-1] = 0;
    }
    for(unsigned int c = 0; c < col_second-1; ++c){
      if(arry[row_first-1][c] == 'F') weight[row_first-1][c] = 1;
      else weight[row_first-1][c] = 0;
    }
    
    
    
    new_row = row_first-2;
    new_col = col_second-2;
   
    for(int i = new_row; i > -1; --i){
      for(int j = new_col; j > -1; --j){
        if(arry[i][j] == 'F'){
          tmp_int = min_value(weight[i+1][j], weight[i][j+1]);
          tmp_int = min_value(tmp_int, weight[i+1][j+1]);
          weight[i][j] = tmp_int+1;
        }
        else weight[i][j] = 0;
      }
    }
    
    vector<vector<int> >weight_vec;
    vector<int> tmp_weight;
    for(unsigned int i = 0; i < row_first; ++i){
      for(unsigned int j = 0; j < col_second; ++j){
        tmp_weight.push_back(weight[i][j]);
        //cout << '(' << i << ':' << j << ')' << weight[i][j] << ' ';
      }
      weight_vec.push_back(tmp_weight);
      tmp_weight.clear();
      //cout << endl;
    }
    //print_vect_int(weight_vec, row_first, col_second);
    
    int max = find_max(weight_vec, row_first, col_second);/*        first max     */
    
    cout << max*max << ' ';
    int k =r_row(weight_vec, row_first, col_second);
    int j =r_col(weight_vec, row_first, col_second);
    //cout << k << ' ' << j-1 << endl;
    int second_max = s_max(weight_vec, row_first, col_second, max, k, j-1);
    cout << second_max*second_max << endl;
    ofs << max*max << ' ' << second_max*second_max << endl;
    weight_vec.clear();
    tmp_weight.clear();
    //tmp.clear();
    arry.clear();
    ++run;
  }while(run <= games_size);
  
  
  ofs.close();
  ifs.close();  
}
int main(int argc, char* argv[]){
  /*  enter argc input  */

  
  if(argc < 3 || argc > 3)
  {
    cout << "Enter Input file and Output file" << endl;
    return 0;
  }
  write_txt(argv[1], argv[2]);
  return 0;
}