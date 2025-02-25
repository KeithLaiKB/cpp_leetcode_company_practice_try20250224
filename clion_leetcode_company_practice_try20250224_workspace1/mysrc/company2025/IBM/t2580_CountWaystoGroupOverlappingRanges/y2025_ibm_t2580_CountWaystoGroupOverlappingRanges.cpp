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
 * You are given a 2D integer array ranges where ranges[i] = [starti, endi]
 * denotes that all integers between starti and endi (both inclusive) are contained in the ith range.
 * You are to split ranges into two (possibly empty) groups such that:
 * Each range belongs to exactly one group.
 * Any two overlapping ranges must belong to the same group.!!!!!这是重点只要overlap必须合并
 * Two ranges are said to be overlapping if there exists at least one integer that is present in both ranges.

 * Example1:
 * Input: ranges = [[6,10],[5,15]]
 * Output: 2
 * Explanation:
 * The two ranges are overlapping, so they must be in the same group.
 * Thus, there are two possible ways:
 * - Put both the ranges together in group 1.
 * - Put both the ranges together in group 2.
 *
 *
 * Example2:
 * Input: ranges = [[1,3],[10,20],[2,5],[4,8]]
 * Output: 4
 * Explanation:
 * Ranges [1,3], and [2,5] are overlapping. So, they must be in the same group.
 * Again, ranges [2,5] and [4,8] are also overlapping. So, they must also be in the same group.
 * Thus, there are four possible ways to group them:
 * - All the ranges in group 1.
 * - All the ranges in group 2.
 * - Ranges [1,3], [2,5], and [4,8] in group 1 and [10,20] in group 2.
 * - Ranges [1,3], [2,5], and [4,8] in group 2 and [10,20] in group 1.
 *
 *
 * 先不管内容相关 假设都可以的情况下
 * vector里面的每个vector 都是互相不overlap, 都可以有两种情况 去group1 或去group2
 * 假设vector 里面一共有k个 vector
 * 那么 一共有 2^k个可能性
 *
 * 一旦有Overlap必须放在同一组
 * 但是一个group里面 可以有多个不overlap的区间
 *
 * 简单的说一下流程
 * 1. 先把overlap的区间合并, 因为Overlap的必须合并成一个team 然后
 * 2. 计算 这些team 可以放在group1 和group2的方法数量
 *
 * 假设ranges那个vector里一共有n个vector
 * 进行Overlap以后 分成了 k个team
 * 这k个team可以选择放进group1 或者group2
 *
 * 所以 1个team, 一共2个可能性
 * k个team, 一共有2*2*2....也就是2^k个可能性
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

    int countWays(vector<vector<int>>& ranges) {
        int MOD = 1e9 + 7;
        //
        int team_num= 1;        //因为ranges里的vector中至少为一个 所以team至少是一个

        //-----------------------前期准备---------------------------------
        //sort vector<vector<int>>的排序规则:
        //按 start 升序（第一列递增）
        //如果 start 相同，则按 end 升序（第二列递增)
        // 例如 {{6, 10}, {5, 15}, {1, 3}, {10, 20}, {2, 5}}
        // 排序后为: {{1, 3}, {2, 5}, {5, 15}, {6, 10}, {10, 20}}
        // sort(ranges.begin(), ranges.end());
        //
        // 我也可以自定义一个制定方法 这样更明显
        auto comp = [](vector<int>& a, vector<int>& b){
            if(a[0] == b[0]) return a[1] < b[1];
            return a[0] < b[0];
        };
        sort(ranges.begin(), ranges.end(), comp);
        //
        myOutput_VectorBVectorBintBB(ranges,0,ranges.size()-1);

        //-----------------------开始合并---------------------------------
        // 因为题目说了 vector的length一定是大于等于1的
        // 所以最大值先取第一个vector的最后一个元素
        int veci_nxt_first=INT32_MIN;              //下一个vector的第一个的元素
        int veci_nxt_second=INT32_MIN;             //下一个vector的第二个(最后一个)的元素
        int team_max = ranges[0][1];    //区间内最大的数字
        

        // 一旦有Overlap必须放在同一组
        // 但是一个group里面 可以有多个不overlap的区间

        for(int i=1;i<=ranges.size()-1;i++){
            veci_nxt_first=ranges[i][0];
            veci_nxt_second=ranges[i][1];

            // 如果 当前这个i+1的vector的最小值 <= 比当前作对比的区间的最大值
            // 也就是说overlap 则合并
            if(team_max >= veci_nxt_first){
                // 并且 重置 最大值
                // 因为有可能存在i+1的vector的最后一个元素比之前的max还要大的情况
                // 例如 {{1,10} {5,7}}已合并, 当前是{2,11}的情况,
                // 10<11 则 max就要变成11了
                team_max = max(team_max,veci_nxt_second);
            }
            //他们不overlap 则当前成为一个新team
            //和 计算team的个数
            else if(team_max < veci_nxt_first){
                ++team_num;
                //新的team 需要 重置max
                team_max = veci_nxt_second;
            }

        }
        //-----------------------计算---------------------------------

        // 快速幂运算
        // Exponentiation by Squaring
        long long rs = 1;
        long long exp=team_num;
        long long base=2;

        long long base_changable = base;
        for(;exp>0;){
            //如果exp是奇数, 例如2^11 那就当前result只乘以一个base_changable
            if(exp%2==1){
                rs = (rs * base_changable) %MOD;
            }
            //就算是奇数经过上面的处理, 接下来的就是偶数了
            base_changable = (base_changable * base_changable)%MOD;
            exp=exp/2;
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

    vector<vector<int>> vec_vecBintB1={{1,3}};



    int rs1 = solut1->countWays(vec_vecBintB1);
    cout<<"result:"<<endl;
    cout << rs1<<endl;
    return 0;
}