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

    void myOutput_VectorBVectorBintBB(vector<vector<int>>& nums, int st_indx, int ed_indx){
        for(int i=st_indx;i<=ed_indx;i++){
            for(int j=0;j<=nums[i].size()-1;j++){

                cout<<nums[i][j]<<"\t";
                if(j==nums[i].size()-1){
                    cout<<endl;
                }

            }
        }
    }


    /*
     * 1. 确立dp的 意义
     * 先假设一个意义(不一定对的意义)
     *  假设 意义 :
     *      定义dp[i][j]装 i~j这个串中含有的回文子串的最长的长度
     *
     *  2. 确立推导顺序
     *      如果 s[i]==s[j]
     *          如果 j-i==1 : bb
     *              dp[i][j]=2
     *          如果 j-i>=2 : bab or baab
     *              如果里面的子串本身是回文, 也就是dp[i+1][j-1]的值就是 长度:     (j-1)-(i+1)+1==dp[i+1][j-1]
     *                  dp[i][j]=dp[i+1][j-1]+2
     *              如果里面的子串本身不是回文:                                  (j-1)-(i+1)+1==dp[i+1][j-1]
     *                  dp[i][j]=dp[i+1][j-1]
     *      如果 s[i]!=s[j]
     *          如果 j-i==1 : bc
     *              dp[i][j]=1
     *          如果 j-i>=1 : bac or babc
     *              dp[i][j]=max [ dp[i][j-1], dp[i+1][j] ]
     *
     *  3. 初始化dp数组
     *          b		    a		    a		    b		    c
     *  b	    1		[0,1]		[0,2]		[0,3]		[0,4]
     *  a	[1,0]		    1		[1,2]		[1,3] 	    [1,4]
     *  a	[2,0]		[2,1]		1		    [2,3] 	    [2,4]
     *  b	[3,0]		[3,1]		[3,2]		1 		    [3,4]
     *  c	[4,0]		[4,1]		[4,2]		[4,3] 	        1

     *
     *  4. 确立遍历顺序
     *
     *  5. 推导dp数组, 自己要写出来
     *
     * 注意一下 我这个方法是基础思想, 填表完全没问题 是对的!!!!!!!!!!!!!!!!!!!!!!!
     * 只是题目要求我 要拿到 字符串, 所以我需要 在这基础上填一点变量什么的记录就好了
     */
    string longestPalindrome_fillform(string s) {
        // s.size * s.size 的dp数组
        vector<vector<int>> dp(s.size(), vector<int>(s.size()));
        //
        //
        //初始化
        for(int i=0;i<=s.size()-1;i++){
            dp[i][i]=1;
        }

        for(int i =s.size()-1;i>=0;i--){
            for(int j =i+1;j<=s.size()-1;j++){
                //b[.....]b
                if(s[i]==s[j]){

                    //bb
                    if(j-i==1){
                        dp[i][j]=2;
                    }
                    //bab or baab
                    else if(j-i>=2){
                        //如果里面的子串本身是回文, 这个子串的dp值就是 这个子串的长度
                        if((j-1)-(i+1)+1==dp[i+1][j-1]){
                            dp[i][j]=dp[i+1][j-1]+2;
                        }
                        //如果里面的子串本身不是回文
                        else if((j-1)-(i+1)+1!=dp[i+1][j-1]){
                            dp[i][j]=dp[i+1][j-1];
                        }
                    }

                }
                //b[.....]c
                else if(s[i]!=s[j]){

                    //bc
                    if(j-i==1){
                        dp[i][j]=1;
                    }
                    //bac or babc
                    else if(j-i>=2){
                        dp[i][j]=max ( dp[i][j-1], dp[i+1][j] );
                    }
                }


            }
        }

        myOutput_VectorBVectorBintBB(dp,0, dp.size()-1);


        return "";
    }

    // 我这个完全是抄了上面的填表, 然后在这个基础上加点变量罢了
    string longestPalindrome(string s) {
        // s.size * s.size 的dp数组
        vector<vector<int>> dp(s.size(), vector<int>(s.size()));
        //
        //-------------与填表 相比增加了--------------------
        //
        int rs_st_idx=-1;
        int rs_ed_idx=-1;
        int rs_max_len=1;
        //
        //-----------------------------------------------
        //
        //
        //初始化
        for(int i=0;i<=s.size()-1;i++){
            dp[i][i]=1;
        }

        for(int i =s.size()-1;i>=0;i--){
            for(int j =i+1;j<=s.size()-1;j++){
                //b[.....]b
                if(s[i]==s[j]){

                    //bb
                    if(j-i==1){
                        dp[i][j]=2;
                    }
                        //bab or baab
                    else if(j-i>=2){
                        //如果里面的子串本身是回文, 这个子串的dp值就是 这个子串的长度
                        if((j-1)-(i+1)+1==dp[i+1][j-1]){
                            dp[i][j]=dp[i+1][j-1]+2;
                        }
                            //如果里面的子串本身不是回文
                        else if((j-1)-(i+1)+1!=dp[i+1][j-1]){
                            dp[i][j]=dp[i+1][j-1];
                        }
                    }

                }
                //b[.....]c
                else if(s[i]!=s[j]){

                    //bc
                    if(j-i==1){
                        dp[i][j]=1;
                    }
                    //bac or babc
                    else if(j-i>=2){
                        dp[i][j]=max ( dp[i][j-1], dp[i+1][j] );
                    }
                }
                //
                //-------------与填表 相比增加了--------------------
                if(dp[i][j]>rs_max_len){
                    rs_st_idx=i;
                    rs_ed_idx=j;
                    rs_max_len= rs_ed_idx-rs_st_idx+1;
                    cout<<dp[i][j]<<endl;
                    cout<<s.substr(rs_st_idx,rs_max_len)<<endl;
                }

            }
        }

        myOutput_VectorBVectorBintBB(dp,0, dp.size()-1);

        //如果指针没动过, 导致rs_st_idx=rs_max_len=-1
        //  从而使得substr会出现问题, 所以我们这里就直接给第一个字符就好
        //
        // 情况可能      :s只有一个字符 所以导致第二层循环 都进不去
        // 情况也可能    :bc,导致 他根本不会经过 if(dp[i][j]>rs_max_len)
        //                  从而获得修改后的 rs_st_idx 和 rs_ed_idx
        if(rs_st_idx==-1&&rs_ed_idx==-1&&rs_max_len){
            return string(1,s[0]);
        }
        else{
            return s.substr(rs_st_idx,rs_max_len);
        }

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
    string str1 = "ac";

    //int rs1 = solut1->maxProfit_greedy(vec1);
    string rs1 = solut1->longestPalindrome(str1);

    cout<<"result:"<<endl;
    cout << rs1<<endl;
    return 0;
}