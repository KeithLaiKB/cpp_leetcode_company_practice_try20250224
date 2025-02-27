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
 * Given an array of intervals where intervals[i] = [starti, endi],
 * merge all overlapping intervals,
 * and return an array of the non-overlapping intervals that cover all the intervals in the input.
 *
 * Example 1:
 * Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
 * Output: [[1,6],[8,10],[15,18]]
 * Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
 *
 * Example 2:
 * Input: intervals = [[1,4],[4,5]]
 * Output: [[1,5]]
 * Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 *
 *
 *
 *
 * 暂时不做 因为  跟2580有点像
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


     */
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        return{};
    }

};

/**
 * @return
 */
int main() {
    Solution* solut1 = new Solution();

    vector<vector<int>> vec_vecBintB1={{1,3},{2,6},{8,10},{15,18}};

    //vector<int> vec1={7,1,5,3,6,4};
    vec_vecBintB1.reserve(100);



    //int rs1 = solut1->maxProfit_greedy(vec1);
    vector<vector<int>> rs1 = solut1->merge(vec_vecBintB1);

    cout<<"result:"<<endl;
    solut1->myOutput_VectorBVectorBintBB(rs1);
    return 0;
}