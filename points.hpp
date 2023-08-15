#pragma once
#include <vector>
#include <cmath>
namespace path_calculator
{
    class PointXY
    {
    public:
        double x, y;
        PointXY()
        {
            x = 0.0;
            y = 0.0;
        }
        PointXY(double a_x, double a_y)
        {
            x = a_x;
            y = a_y;
        }
        double calcAbs()
        {
            return sqrt(pow(this->x, 2) + pow(this->y, 2));
        }

        bool operator==(PointXY xy) const
        {
            return this->x == xy.x && this->y == xy.y;
        }
        bool operator!=(PointXY xy) const
        {
            return !(*this==xy);
        }
    };
    class PointsVec:public std::vector<PointXY>{
        using PointsVec::vector;
    public:
        bool isInVector(PointXY a_xy){
            for(const auto& xy:*this){
                if(xy.x == a_xy.x && xy.y == a_xy.y){
                    return true;
                }
            }
            return false;
        }
    };

    class Path
    {
    public:
        Path(PointXY start, PointXY end);
        Path(PointXY start, PointXY end, PointsVec relay_points);
        //~Path();

    private:
        PointsVec path;
        PointXY start;
        PointXY end;
        PointsVec relay_points;

    public:
        PointXY GetStart();
        PointXY GetEnd();
        PointsVec GetRelayPoints();

        void SetStart(PointXY a_start);
        void SetEnd(PointXY a_end);
        void SetRelayPoints(PointsVec a_relay);

        void ConnectPath(Path a_path);

    private:
        bool CalcPath();
    };

}