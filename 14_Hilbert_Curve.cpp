//http://bit-player.org/extras/hilbert/hilbert-construction.html
//Hilbert曲线可以无限阶下去，从1阶开始，落在一个矩阵里，让你写个function，三个参数（x,y,阶数），return 这个点（x,y）是在这阶curve里从原点出发的第几步
int hilbertCurve(int x, int y, int iter) {
    if (iter == 0) return 1;
    int areaCnt = (1 << (iter * 2 - 2)); // 每一象限走的步数，其实可以看成是 pow(4, iter) / 4;
    int borderLen = (1 << (iter - 1)); // 跨象限移动的长度，可以看成求原点的转换坐标

    if (x >= borderLen && y >= borderLen) //右上角区域 = 前一阶往右上角移动borderLen
        return areaCnt * 2 + hilbertCurve(x - borderLen, y - borderLen, iter - 1);
    else if (x < borderLen && y >= borderLen) //左上角区域 = 前一阶往上移动borderLen
        return areaCnt + hilbertCurve(x, y - borderLen, iter - 1);
    else if (x < borderLen && y < borderLen) //右下角区域 = 前一阶按照y=x对称
        return hilbertCurve(y, x, iter - 1);
    else //右下角区域 = 前一阶按照y=-x对称，然后右移2*borderLen - 1，上移borderLen - 1
    // 设原来坐标(a,b) => (-b, -a) => (2*borderLen - 1 - b, borderLen - 1 - a) = (x, y)
    // => a = borderLen - 1 - y, b = 2*borderLen - 1 - x
        return areaCnt * 3 + hilbertCurve(borderLen - 1 - y, 2 * borderLen - 1 - x, iter - 1);
}
