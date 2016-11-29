// 题目描述
// 请实现一个函数，将一个字符串中的空格替换成“%20”。
// 例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。

// 思路:
// 先遍历一遍字符串，求出字符串的实际长度，和空格个数，之后算出替换后的字符串长度，
// 然后str字符串末尾到开头进行替换字符串（如果是从开头到末尾的顺序替换字符串， 当替换空格之后，需要将后面的字符串往后挪，更加耗时)

class Solution {
public:
	void replaceSpace(char *str,int length) {
	    if (str == NULL || length == 0)
	    {
	        return ;
	    }
	    int spaceCounts = 0;
	    int strLength = 0;
	    int newLength = 0;
	    for (int i = 0; str[i] != '\0' ; i++)
	    {
	        if (str[i] == ' ')
	        {
	            spaceCounts++;
	        }
	        strLength++;
	    }

	    newLength = strLength + spaceCounts * 2;

	    for (int i = strLength - 1, j = newLength - 1; i >= 0; i--)
	    {
	        if (str[i] == ' ')
	        {
	            str[j--] = '0';
	            str[j--] = '2';
	            str[j--] = '%';
	        }
	        else
	        {
	            str[j--] = str[i];
	        }
	    }
	    str[newLength] = '\0';
	}
};