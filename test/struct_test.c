/* makepoint: make a point from x and y components */

/*注意,参数名和结构成员同名不会引起冲突。事实上,使用重名可以强调两者之间的关系。
现在可以使用 makepoint 函数动态地初始化任意结构, 也可以向函数提供结构类型的参
数。例如:*/
struct point {
int x;
int y;
};

struct point makepoint(int x, int y)
{
struct point temp;
temp.x = x;
temp.y = y;
return temp;
}

 struct rect {
struct point pt1;
struct point pt2;
};

int main(){

struct rect screen;
struct point middle;
struct point makepoint(int, int);
screen.pt1 = makepoint(0,0);
screen.pt2 = makepoint(2, 2);
middle = makepoint((screen.pt1.x + screen.pt2.x)/2,(screen.pt1.y + screen.pt2.y)/2);

//接下来需要编写一系列的函数对点执行算术运算。例如:
/* addpoints: add two points */
 return 0;
}
