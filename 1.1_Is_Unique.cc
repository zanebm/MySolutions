//AUTHOR: Zaneb Mazeh
//IS UNIQUE: Implement an algorithm to determine if a string has all unique chars. What if you cannot use additional data structures?
#include <string>
#include <iostream>

using namespace std;

void sortStr(string &str, int left, int right){
  int i = left;
  int j = right;
  char tmp;
  char pivot = str.at((left + right) / 2);

  while(i <= j){
    while(str.at(i) < pivot){
      i++;
    }
    while(str.at(j) > pivot)
      j--;
    if( i <= j){
      tmp = str.at(i);
      str.at(i) = str.at(j);
      str.at(j) = tmp;
      i++;
      j--;
    }
  }

  if(left < j)
    sortStr(str, left, j);
  if(i < right)
    sortStr(str, i, right);
}

bool isUnique(string str){
  string start = str;
  sortStr(str, 0, str.length()-1);
  //cout << "here is my sorted str: " << str << endl;
  for(int i = 0; i < str.length()-1; i++){
      if(str.at(i) == str.at(i+1)){
        cout << start << " does NOT have all unique characters" << endl;
        return false;
      }
  }
  cout << start << " has all unique characters" << endl;
  return true;
}
int main(){
  string myStr = "zaqxswcdevfrbgtnhymjukilop"; //TRUE
  string myStr2 = "zzaaqqxxsswwccddeevvffrrbbggttnnhhyymmjjuukkiilloopp"; //FALSE


  isUnique(myStr);
  isUnique(myStr2);

  return 0;
}
