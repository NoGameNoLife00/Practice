// 题目描述
// 在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
// 输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 即输出P%1000000007
// 输入描述:
// 题目保证输入的数组中没有的相同的数字
// 数据范围：
// 	对于%50的数据,size<=10^4
// 	对于%75的数据,size<=10^5
// 	对于%100的数据,size<=2*10^5

思路：
1. 扫描数组，每扫描一个数字的时候，依次比较该数字后面的数字，判断逆序对。这样的解法时间效率是O(n^2)，太慢
2. 使用归并排序的思路，排序合并过程中比较逆序对。时间效率为O(nlogn)。注意防止整型溢出

class Solution {
public:
    int Merge(vector<int> &source, vector<int> &target, int start, int mid, int end) {
        long count = 0;
        int n = end;
        int m = mid;
        int i, j, l;

        for (j = m + 1, i = start; i <= m && j <= n;) {
            if (source[i] > source[j]) {
                target.push_back(source[i++]);
                count += n - j + 1;
                if (count >= 1000000007) {
                   count = count % 1000000007;
                }
            }
            else {
                target.push_back(source[j++]);
            }
        }
        while (i <= mid){
            target.push_back(source[i++]);
        }

        while (j <= n) {
            target.push_back(source[j++]);
        }

        for (int i = start, k = 0; i <= end && k < target.size(); i++, k++) {
            source[i] = target[k];
        }
        return count;
    }


    long InversePairs(vector<int> &data, int s, int e) {
        if (s >= e) {
            return 0;
        }
        vector<int> copy;
        int m = (s + e) / 2;
        long left = InversePairs(data, s, m);
        long right = InversePairs(data, m + 1, e);
        int count = Merge(data, copy, s, m, e);
        return (left + right + count) % 1000000007;

    }

    int InversePairs(vector<int> data) {
        if (data.size() == 0) {
            return 0;
        }

        return InversePairs(data, 0, data.size() - 1);
    }
};