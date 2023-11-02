class Solution {
public:
    int getSum(int x, int y) {
        return log2(std::pow(2,x)*std::pow(2,y));
    }
};