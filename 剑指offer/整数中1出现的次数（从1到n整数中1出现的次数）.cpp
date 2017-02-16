// 题目描述
// 求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？
// 为此他特别数了一下1~13中包含1的数字有1、10、11、12、13因此共出现6次,但是对于后面问题他就没辙了。
// ACMer希望你们帮帮他,并把问题更加普遍化,可以很快的求出任意非负整数区间中1出现的次数。

// 思路：
// 遍历1到n中的数字，每个数字通过对10取余判断个位是否为1,如果这个数大于10,取余之后再除以10,在重复判断。

class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
    	int counts = 0;
        for (int i = 1; i <= n; i++)
        {
            int num = i;
            while (num > 0)
            {
                if (num % 10 == 1)
                {
                    counts++;
                }
                num /= 10;
            }
        }

        return counts;
    }
};

// 思路2：
// 将数字区间拆分处理。比如1到21345,分成1-1345和1346-21345。
// 1346-21345中1出现的分为两种情况，当1出现在最高位时，
// 1出现在10000-19999这个区间中出现了10000次。当1出现在最高位之外的其他四位数中时，
// 我们可以将1346-21345分成两段，1346-11345和11346-21345。
// 每一段剩下的4位数字选择其中一位为1，其余可以在0-9中任意选择。然后由排列组合的原则，
// 得到出现的次数为2*10^3=2000次。
// 1-1345中1出现的次数，可以递归求得。

class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
		if (n <= 0)
        {
        	return 0;
        }
        char strN[50];
        sprintf(strN, "%d", n);

        return NumberOf1(strN);
    }

    int NumberOf1(const char * strN)
    {
        if (!strN || *strN < '0' || *strN > '9' || *strN == '\0')
        {
        	return 0;
        }

        int first = *strN - '0';
        unsigned int length = static_cast<unsigned int> (strlen(strN));
        if (length == 1 && first == 0)
        {
        	return 0;
        }
        if (length == 1 && first > 0)
        {
        	return 1;
        }

        int numFirstDigit = 0;
        if (first > 1)
        {
             numFirstDigit = PowerBase10(length - 1);
        }
        else if (first ==  1)
        {
        	numFirstDigit = atoi(strN + 1) + 1;
        }

        int numOtherDigit = first * (length-1) * PowerBase10(length-2);
        int numRecursive = NumberOf1(strN+1);
        return numFirstDigit + numOtherDigit + numRecursive;
    }

    int PowerBase10(unsigned int n)
    {
    	int result = 1;
        for (unsigned int i = 0; i < n; i++)
        {
        	result *= 10;
        }
        return result;
    }
};