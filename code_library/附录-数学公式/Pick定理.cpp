/***********************************************
POJ 1265 2954 Pick定理
************************************************
Pick定理：如果一个简单多边形(以下称为"多边形")的每
个顶点都是直角坐标平面上的格点，则称该多边形为格点
多边形。若一个面积为S的格点多边形，其边界上有a个格
点，内部有b个格点，则S = a / 2 + b - 1。知道其中的
任意两个量可以计算出第三个量，给定格点平面上的点集
，则可以使用叉乘计算出S * 2(也可以是S)。这里计算a
的值时利用了一个巧妙的关系：多边形上相邻端点p1和p2
之间边上的格点数量(包含一个端点)为gcd (abs (p2.x -
 p1.x), abs (p2.y - p1.y))
************************************************/