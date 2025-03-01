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
 *
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

    template <typename T>
    void myOutput_VectorBtB(vector<T>& nums, int st_indx, int ed_indx){
        for(int i=st_indx;i<=ed_indx;i++){
            cout<<nums[i]<<"\t";
            if(i==ed_indx){
                cout<<endl;
            }
        }
    }



    /*
     */
    /*
     */
    string longestPalindrome_fillform(string s) {
        return "";
    }

    // 我这个完全是抄了上面的填表, 然后在这个基础上加点变量罢了
    string longestPalindrome(string s) {
        return "hello";
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