/*
难度：简单
题目描述：
Alice 有 n 枚糖，其中第 i 枚糖的类型为 candyType[i] 。Alice 注意到她的体重正在增长，所以前去拜访了一位医生。
医生建议 Alice 要少摄入糖分，只吃掉她所有糖的 n / 2 即可（n 是一个偶数）。Alice 非常喜欢这些糖，她想要在遵循医生建议的情况下，尽可能吃到最多不同种类的糖。
给你一个长度为 n 的整数数组 candyType ，返回： Alice 在仅吃掉 n / 2 枚糖的情况下，可以吃到糖的最多种类数。
*/

/*
思路：如果糖的类型 >= n/2,那么最对能吃n/2种；如果糖的类型 < n/2,那么最多只能吃糖的类型数
使用散列计算糖的类型数，但是忽略了负数情况的输入
*/
int distributeCandies(int* candyType, int candyTypeSize){
    int i, type;    
    int hashTable[100001] = {0};
    for(i = 0; i < candyTypeSize; i++){
        hashTable[candyType[i]]++;
    }
    for(i = 0; i < 100001; i++){
        if(hashTable[i]){
            type++;
        }
    }
    if(type > candyTypeSize/2){
        return candyTypeSize/2;
    }else{
        return type;
    }
}

/*
负数情况的解决方法：将负数映射到正数
由于-10e5 <= candyType[i] <= 10e5
*/
int hashTable[200001] = {0};
    for(i = 0; i < candyTypeSize; i++){
        hashTable[candyType[i]+100000]++;
    }
    for(i = 0; i < 200001; i++){
        if(hashTable[i]){
            type++;
        }
    }

/*
方法二：使用set去重
*/
class Solution {
    public int distributeCandies(int[] candyType) {
        Set<Integer> set = new HashSet<>();
        for (int i = 0; i < candyType.length; i++) {
            set.add(candyType[i]);
        }
        return set.size() <= candyType.length/2 ? set.size() : candyType.length/2;
    }
}

class Solution {
public:
    int distributeCandies(vector<int> &candyType) {
        return min(unordered_set<int>(candyType.begin(), candyType.end()).size(), candyType.size() / 2);
    }
};
