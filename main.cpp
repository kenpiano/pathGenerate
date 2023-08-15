#include "main.hpp"
#include "points.hpp"

using namespace path_calculator;
int main()
{
    PointXY start(1,2),end(100,200);
    Path path(start,end);
    
    PointXY start2(-100,2),end2(1,2);
    Path second_path(start2,end2);

    path.ConnectPath(second_path);
    return 0;
}


