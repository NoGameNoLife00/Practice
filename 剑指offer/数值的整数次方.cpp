题目描述
给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。

// 思路：
// 本题主要容易忽略两点：
// 1. 当exponent为负数的时候。
// 2. 当exponent为负数，且base为0的时候， 运算出现异常（求0的倒数）.当判断base为0时，
//    同时也要注意base是double类型，直接使用==判断有可能出现误差。

class Solution {
public:
    double Power(double base, int exponent) {
    	double result = 1.0;
        if (equal(base, 0.0) && exponent)
        {
            // 错误处理 todo
        	return 0.0;
        }
        if (exponent > 0)
        {
            for (int i = 0; i < exponent; i++)
            {
                result *= base;
            }
        }
        else
        {
        	int absExponent = (unsigned int) (-exponent);
            for (int i = 0; i < absExponent; i++)
            {
                result /= base;
            }
        }

        return result;
    }

    bool equal(double n1, double n2)
    {
    	if ((n1 - n2 > -0.0000001) &&
            (n1 - n2 < 0.0000001))
        {
            return true;
        }
        else
        {
        	return false;
        }
    }
};

// 思路2：
// 使用a的n次方公式：n为偶数 a^n = a^(n/2)*a(n/2)， n为奇数 a^n = a((n-1)/2) * a ((n-1)/2) * a

class Solution {
public:
    double Power(double base, int exponent) {
        int absExponent = exponent < 0 ? -exponent : exponent;

        if (absExponent == 0)
            return 1;
        if (absExponent == 1)
            return base;

        double result = Power(base, absExponent >> 1);
        result *= result;
        if ((absExponent & 0x1) == 1)
            result *= base;
        return exponent < 0? 1/result : result;
    }

};