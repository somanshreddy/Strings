#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isall9s(string s){
  for (int i = 0; i < s.length(); ++i)
  {
    if(s[i] != 9)
      return false;
  }

  return true;
}

int main() {
  
  string s;
  cin >> s;

  int i = 0;
  int j = s.length() - 1;
  int n = s.length();

  if(n == 1){
    cout << "11" << endl;
    return 0;
  }

  if(isall9s(s)){
    cout << "1";

    for (int i = 0; i < s.length() - 1; ++i)
    {
      cout << "0";
    }

    cout << "1" << endl;

    return 0;
  }

  for (i = 0; i < s.length()/2; ++i)
  {
    if(s[i] < s[j]){
      
      s[j] = s[i];

      if(s[j - 1] < '9')
        s[j - 1]++;
      
      int k = 1;

      while(j < n && s[j - k] == '9' && (j - k) != 0){    //if j == k then it is the 0th element and carry propagation would have been taken care of by all9's case
        s[j - k] = '0';
        
        if(s[j - k - 1] == '9'){
          k++;
          continue;                 //if previous is also 9 then propagate carry to MSB
        }
      
        else{
          s[j - k - 1]++;
          k++;
        }
    }

      if(s[i] != s[j])
        s[j] = s[i];
  }

    else{                           //if s[i] > s[j]
      s[j] = s[i];
    }

    j--;
  }

  cout << s << endl;
}



