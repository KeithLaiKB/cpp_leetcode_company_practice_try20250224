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
 * You are given a positive integer num.
 * You may swap any two digits of num that have the same parity (i.e. both odd digits or both even digits).
 * Return the largest possible value of num after any number of swaps.


 * Example1:
 * Input: num = 1234
 * Output: 3412
 * Explanation: Swap the digit 3 with the digit 1, this results in the number 3214.
 * Swap the digit 2 with the digit 4, this results in the number 3412.
 * Note that there may be other sequences of swaps but it can be shown that 3412 is the largest possible number.
 * Also note that we may not swap the digit 4 with the digit 1 since they are of different parities.
 *
 * Example2:
 * Input: num = 65875
 * Output: 87655
 * Explanation: Swap the digit 8 with the digit 6, this results in the number 85675.
 * Swap the first digit 5 with the digit 7, this results in the number 87655.
 * Note that there may be other sequences of swaps but it can be shown that 87655 is the largest possible number.
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

    int largestInteger(int num) {
        priority_queue<int> odd1 ={};
        priority_queue<int> even1 ={};

        deque<int> num_to_deque={};           //原始num弄成deque, 用deque可以从前面开始插,所以比较方便

        int rs=0;                      //装结果的

        int last_digit_tmp = INT32_MIN;
        for(;num>0;){
            last_digit_tmp = num %10;
            //
            //如果当前最后的这个数字是奇数
            if(last_digit_tmp%2!=0){
                odd1.push(last_digit_tmp);
            }
            //如果当前最后的这个数字是偶数
            else if(last_digit_tmp%2==0){
                even1.push(last_digit_tmp);
            }

            //比如65875
            //就可以5->75->875...这样子从前面开始插
            num_to_deque.push_front(last_digit_tmp);
            num = num /10;
        }
        for(int i=0;i<=num_to_deque.size()-1;i++){
            //如果当前这个数字是奇数
            if(num_to_deque[i]%2!=0){
                rs=rs*10+odd1.top();
                odd1.pop();
            }
            //如果当前这个数字是偶数
            else if(num_to_deque[i]%2==0){
                rs=rs*10+even1.top();
                even1.pop();
            }
        }

        return rs;
    }

};

/**
 * @return
 */
int main() {
    Solution* solut1 = new Solution();

    //vector<vector<int>> vec_vecBintB1={{1,3},{10,20},{2,5},{4,8}};

    //vector<vector<int>> vec_vecBintB1={{1,3}};

    int int1= 65875;

    int rs1 = solut1->largestInteger(int1);
    cout<<"result:"<<endl;
    cout << rs1<<endl;
    return 0;
}