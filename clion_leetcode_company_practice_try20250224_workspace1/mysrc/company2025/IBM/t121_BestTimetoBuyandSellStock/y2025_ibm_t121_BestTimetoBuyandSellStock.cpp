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
 * 贪心算法
 *
 * You are given an array prices where prices[i] is the price of a given stock on the ith day.
 * You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

 * Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.



 * Example1:
 * Input: prices = [7,1,5,3,6,4]
 * Output: 5
 * Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
 * Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
 *
 * Example2:
 * Input: prices = [7,6,4,3,1]
 * Output: 0
 * Explanation: In this case, no transactions are done and the max profit = 0.
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

    //成功的
    //时间复杂度：O(n)
    //空间复杂度：O(1)
    int maxProfit_greedy(vector<int>& prices) {
        int lowest1=INT32_MAX;
        int best_profit=0;          //题目要求不能亏损

        for(int i=0;i<=prices.size()-1;i++){
            //如果比最小值小 那么记录当前最小值
            if(prices[i]<lowest1){
                lowest1=prices[i];
            }
            //如果比最小值大, 那么证明之前有一个最小值了, 此时可以获利
            // 但是要看是否能获利 最大
            else if(prices[i]>=lowest1){
                int now_profit = prices[i]-lowest1;
                if(now_profit>best_profit){
                    best_profit=now_profit;
                }
            }
        }

        return best_profit;
    }

    /*
     * 1. 确立dp的 意义
     * 先假设一个意义(不一定对的意义)
     *  假设 意义 :
     *      dp[0]=获利?(这是思考 这句话不一定对 这是我自己问自己的)
     *      dp[0]=无获利
     *      dp[1]= - daiyi前最便宜的 入场价格  + 当天价格 = 当天价格- dayi之前的最便宜的价格
     *           = price[i]  - price_lowest_bf_dayi
     *           这个时候我希望把 dayi之前的最便宜的价格 当作dp[i-1]
     *       所以有 这个时候 我要 重新塑造 dp的意义!!!!
     *  sub结果:
     *       dp[i]=dayi之前的最便宜的价格
     *
     *  2. 确立推导顺序
     *  dp[i]= min[dp[i-1], price[i]]
     *
     *  3. 初始化dp数组
     *  都是0
     *
     *  4. 确立遍历顺序
     *
     *  5. 推导dp数组, 自己要写出来
     *      为了 检查你的思路
     *      假设{7,1,5,3,6,4}
     *      则dp
     *      0 1 2 3 4 5
     *      7 1 5 3 6 4
     *
     *      1 8 3 4 5 6
     *
     * 但感觉这个操作 跟贪心很像 所以我没有继续下去了
     * 于是再想一个
    * 1. 确立dp的 意义
     * 先假设一个意义(不一定对的意义)
     *  假设 意义 :
     *      dp[0]=获利?(这是思考 这句话不一定对 这是我自己问自己的)
     *      负获利也是特殊的获利, 买入 就是负数
     *      dp[n][0] 这一列 代表的是 dayi 当天此时已经在股市当中 已付出的本金
     *          1.有可能是dayi之前就已经进入股市了
     *          2.当天dayi进入股市
     *
     *      dp[0][0]=-7, 代表买入时的价格, 但当天无法卖出所以 dp[0][1]=0
     *      dp[1][0]=-1, 代表买入时最低的价格, 因为我们要保证买入时得到最低位
     *      dp[2][0]=-1, 代表买入时最低的价格, 因为我们要保证买入时得到最低位,此时的买入位置应该是day1(注意i从0开始)
     *
     *
     *      dp[0][1]=0, 代表当天无法卖出
     *      dp[1][1]=0, 因为 price[1]-dp[0][0]<0
     *      dp[1][2]=4, 因为 price[2]-dp[1][0] > dp[1][1]
     *
     *      时间复杂度：O(n)
     *      空间复杂度：O(n)
     */
    int maxProfit_dp(vector<int>& prices) {
        int day_num = prices.size();
        vector<vector<int>> dp1(day_num,vector<int>(2));

        //
        dp1[0][0]=-prices[0];
        dp1[0][1]=0;


        for(int i=1;i<=prices.size()-1;i++){
            // min(当前买入,              之前最低价买入)
            dp1[i][0] = min(prices[i],abs(dp1[i-1][0]));
            // max(当前卖出 之前买入的最低价,           之前卖出的获利最大的方案金额 )
            dp1[i][1] = max(prices[i]-abs(dp1[i-1][0]), dp1[i-1][1]);
        }
        myOutput_VectorBVectorBintBB(dp1,0,dp1.size()-1);
        return dp1[day_num-1][1];
    }

};

/**
 * @return
 */
int main() {
    Solution* solut1 = new Solution();

    //vector<vector<int>> vec_vecBintB1={{1,3},{10,20},{2,5},{4,8}};

    vector<int> vec1={7,1,5,3,6,4};
    vec1.reserve(100);



    //int rs1 = solut1->maxProfit_greedy(vec1);
    int rs1 = solut1->maxProfit_dp(vec1);

    cout<<"result:"<<endl;
    cout << rs1<<endl;
    return 0;
}