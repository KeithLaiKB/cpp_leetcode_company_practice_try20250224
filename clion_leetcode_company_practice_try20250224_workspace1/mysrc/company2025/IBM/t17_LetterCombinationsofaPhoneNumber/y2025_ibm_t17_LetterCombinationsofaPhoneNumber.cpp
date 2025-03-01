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
#include <cstdint>
#include <climits>

#include <algorithm>
using namespace std;

/**
 * 回溯
 *
 * Given a string containing digits from 2-9 inclusive,
 * return all possible letter combinations that the number could represent.
 * Return the answer in any order.
 *
 * A mapping of digits to letters (just like on the telephone buttons) is given below.
 * Note that 1 does not map to any letters.
 *
 * Example1:
 * Input: digits = "ab"
 * Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
 *
 * Example2:
 * Input: digits = ""
 * Output: []
 *
 * Example 3:
 * Input: digits = "2"
 * Output: ["a","b","c"]
 *
 *
 * 2: abc
 * 3: def
 * 4: ghi
 * 5: jkl
 * 6. mno
 * 7. pqrs
 * 8. tuv
 * 9. wxyz
 *
 * Constraints:
 * 0 <= digits.length <= 4
 * digits[i] is a digit in the range ['2', '9'].
 *

 */

class Solution {
private:

public:
    Solution(){

    }
    ~Solution(){

    }

    template <typename T>
    void myOutput_VectorBtB(vector<T>& nums, int st_indx, int ed_indx){
        for(int i=st_indx;i<=ed_indx;i++){
            cout<<nums[i]<<"\t";
            if(i==ed_indx){
                cout<<endl;
            }
        }
    }




    vector<string> pad1={"",         //0
                         "",         //1
                         "abc",      //2
                         "def",      //3
                         "ghi",      //4
                         "jkl",      //5
                         "mno",      //6
                         "pqrs",     //7
                         "tuv",      //8
                         "wxyz"      //9
    };
    //
    // 假设输入"23"
    //
    //                                                                                         digits[2]==> 集合{"def"}
    //                                      |                                                       |                                                       |
    //                                      |取d                                                    |取e                                                     |取f
    //   第一层的结果:                        "d"                                                    "e"                                                      "f"
    //                      |               |               |                       |               |               |                       |               |               |
    //                      |(取g)           |(取h)          |(取i)                  |(取g)           |(取h)          |(取i)                  |(取g)           |(取h)          |(取i)
    //   第一层的结果:       "dg"             "dh"            "di"                   "eg"            "eh"            "ei"                     "fg"            "fh"            "fi"
    //
    //
    void backtracking(string digits, int now_digit_idx, string rs_ele,vector<string> &vec_rs){

        //limit
        // 这题目很好的告诉了你 不是动不动就size-1的
        if(now_digit_idx==digits.size()){
            vec_rs.push_back(rs_ele);
            return;
        }
        // for最底层的对象, 所以不是for 那个digits  例如“23”
        // 而是 for 那个pad 中的每个key里的content, 例如"abc" "def" 那些
        int key_num = digits[now_digit_idx]-'0';
        string key_content = pad1[key_num];
        //
        for(int i=0;i<=key_content.size()-1;i++){
            //deal
            rs_ele.push_back(key_content[i]);

            //backtracking
            backtracking(digits, now_digit_idx+1 ,rs_ele, vec_rs);

            //pop
            // 例如 我们的"23"例子中,
            // 假设 当前的情况是 我们经过了d 现在深入到当前这个key_content[i]=g
            // 在上面的backtracking当中 我们已经把 “dg” 放进了rs
            // 此时我们要把 “dg”中的 "g"弹出, 准备装 下一个key_content[i+1]=h, 从而获得 "dh"
            rs_ele.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> rs={};
        rs.reserve(100);

        int st_digit_idx= 0;

        if(digits==""){
            return {};
        }
        string rs_ele("");

        backtracking(digits,st_digit_idx,rs_ele,rs);
        return rs;
    }

};

/**
 * @return
 */
int main() {
    Solution* solut1 = new Solution();

    //vector<vector<int>> vec_vecBintB1={{1,3},{10,20},{2,5},{4,8}};

    //vector<int> vec1={7,1,5,3,6,4};
    //vec1.reserve(100);

    //string str1 = "baabc";
    //string str1 = "cbbd";
    //string str1 = "a";
    string str1 = "23";

    //int rs1 = solut1->maxProfit_greedy(vec1);
    vector<string> rs1 = solut1->letterCombinations(str1);

    cout<<"result:"<<endl;
    //cout << rs1<<endl;
    solut1->myOutput_VectorBtB(rs1,0,rs1.size()-1);
    return 0;
}