//
// Created by kt on 24/02/25.
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <queue>
#include <optional>
using namespace std;

/**
 * You are given two strings word1 and word2.
 * Merge the strings by adding letters in alternating order,
 * starting with word1. If a string is longer than the other,
 * append the additional letters onto the end of the merged string.
 *
 * Return the merged string.
 *
 * Example1:
 * Input: word1 = "abc", word2 = "pqr"
 * Output: "apbqcr"
 * Explanation: The merged string will be merged as so:
 * word1:  a   b   c
 * word2:    p   q   r
 * merged: a p b q c r
 *
 * Example2:
 * Input: word1 = "ab", word2 = "pqrs"
 * Output: "apbqrs"
 * Explanation: Notice that as word2 is longer, "rs" is appended to the end.
 * word1:  a   b
 * word2:    p   q   r   s
 * merged: a p b q   r   s
 *
 * Example3:
 * Input: word1 = "abcd", word2 = "pq"
 * Output: "apbqcd"
 * Explanation: Notice that as word1 is longer, "cd" is appended to the end.
 * word1:  a   b   c   d
 * word2:    p   q
 * merged: a p b q c   d
 */

class Solution {
private:

public:
    Solution(){

    }
    ~Solution(){

    }
    void myOutput_string(string str1, int st_indx, int ed_indx){
        int len = ed_indx - st_indx +1;
        string str_rs1(str1.substr(st_indx,len));
        cout<<str_rs1<<endl;
    }

    string mergeAlternately(string word1, string word2) {

        string rs1="";
        rs1.reserve(word1.size()+word2.size());


        int i=0;
        int j=0;
        for(; i<=word1.size()-1 || i<=word2.size()-1;i++,j++){
            if(i<=word1.size()-1){
                rs1.append(1,word1[i]);
            }
            if(i<=word2.size()-1){
                rs1.append(1,word2[i]);
            }
        }



        return rs1;
    }

};

/**
 * @return
 */
int main() {
    Solution* solut1 = new Solution();


    string str1 = "abcd";
    string str2 = "pq";



    string  rs1 = solut1->mergeAlternately(str1,str2);
    solut1->myOutput_string(rs1,0,rs1.size()-1);
    return 0;
}