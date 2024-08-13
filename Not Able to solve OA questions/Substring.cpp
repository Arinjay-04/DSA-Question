#include <bits/stdc++.h>
using namespace std;

int helper (string s, int k, int l){
      int i=0;
      int j = l;
      int n = s.length();
      vector<string> v;
      while(j<n){
         string str = s.substr(i, l+1);
         v.push_back(str);
         j++;
         i++;
      }
      
    //   for(int a=0 ; a<v.size(); a++){
    //       cout<<v[a]<<endl;
    //   }
      int count = 0;

      for(int p=0; p<v.size()-1; p++){
         for(int q = p+1; q < v.size(); q++){
            string s1 = v[p];
            string s2 = v[q];
            int flag = 0;
            for(int it = 0; it<s1.length(); it++){
                 if(s1[it] != s2[it] && it != k){
                    flag = 1;
                    break;
                 }
                     
                
            }

            if(flag == 0 && s1 != s2){
                 cout<<s1<<" "<<s2<<endl;
                count++;
            }
         }
      }

      return count;
}
int solution(string s, int k){
    int n = s.length();
     int ans = 0;
    for(int i=k; i<n; i++){
        ans += helper(s, k, i);
    }

    return ans*2;
}

int main(){
 

    string s = "abacaba";

    cout<<solution(s, 1)<<endl;

    return 0;
}