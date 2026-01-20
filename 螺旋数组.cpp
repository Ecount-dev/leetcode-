class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> res(n, vector<int>(n, 0));      //创建n*n的二维数组，初始值为0
		int startX = 0;                                     //起始位置横坐标=0
		int startY = 0;                                     //起始位置纵坐标=0
		int O = n / 2;                                      //圈数
		int count = 1;                                      //计数器
        int chag = 1;                                       //可以理解为每圈减少的长度，每圈填充数字的过程
                                                           //1.从左到右填充
                                                           //2.从上到下填充
                                                           //3.从右到左填充
                                                           //4.从下到上填充
                                                           //每完成一圈，起始位置向内移动一位，圈数减一，长度减少2
                                                           //当n为奇数时，最后剩下的一个数字需要单独处理
														   //最终返回填充好的二维数组
		int i, j;                                          //定义循环变量
        while (O--)
        {
            i = startX;
            j = startY;
			for (j; j < n - chag; j++)                      //从左到右填充
            {
                res[startX][j] = count++;

            }
			for (i; i < n - chag; i++)                      //从上到下填充
            {
                res[i][j] = count++;
            }
			for (j = n - chag; j > startX; j--)             //从右到左填充
            {
                res[i][j] = count++;
            }
			for (i = n - chag; i > startY; i--)             //从下到上填充
            {
                res[i][startY] = count++;
            }
			startX++;                                      //起始位置X轴方向向内移动一位，填充的数组往里缩小一圈
			startY++;                                       //起始位置Y轴方向向内移动一位，填充的数组往里缩小一圈
            chag++;

        }
		if (n % 2 == 1)                                     //当n为奇数时，填充最后一个数字
        {
            res[n / 2][n / 2] = n * n;
        }
        return res;
    }

};