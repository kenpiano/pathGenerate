#include "points.hpp"
#include <cmath>
#include <iostream>
#include <err.h>

namespace path_calculator{
    Path::Path(PointXY a_start,PointXY a_end){
        this->SetStart(a_start);
        this->SetEnd(a_end);
        this->CalcPath();
    }
    Path::Path(PointXY a_start,PointXY a_end, PointsVec a_relay_points){
        this->SetStart(a_start);
        this->SetEnd(a_end);
        this->SetRelayPoints(a_relay_points);
        this->CalcPath();
    }

    PointXY Path::GetStart(){
        return this->start;
    }

    PointXY Path::GetEnd(){
        return this->end;
    }

    PointsVec Path::GetRelayPoints(){
        return this->relay_points;
    }

    void Path::SetStart(PointXY a_start){
        this->start = a_start;
    }

    void Path::SetEnd(PointXY a_end){
        this->end = a_end;
    }

    void Path::SetRelayPoints(PointsVec a_relay){
        this->relay_points.clear();
        std::copy(a_relay.begin(),a_relay.end(),std::back_inserter(this->relay_points));
    }

    void Path::ConnectPath(Path a_path){
        if(this->start == a_path.end){
            if(this->start != a_path.start && !this->path.isInVector(a_path.start)){
                this->SetStart(a_path.start);
                if(!this->CalcPath()){
                std::cerr << __FILE__ << __LINE__ << "faild to path connection"<<std::endl;
                }
            }else{
                std::cerr << __FILE__ << __LINE__ << "faild to path connection"<<std::endl;
            }
        }else if(this->end == a_path.start){
            if(this->end != a_path.end && !this->path.isInVector(a_path.end)){
                this->SetEnd(a_path.end);
                if(this->CalcPath()){
                std::cerr << __FILE__ << __LINE__ << "faild to path connection"<<std::endl;
                }
            }else{
                std::cerr << __FILE__ << __LINE__ << "faild to path connection"<<std::endl;
            }
        }else {
            std::cerr << __FILE__ <<":"<< __LINE__ << "wrong path was given"<<std::endl;
            return;
        }
        
    }
    bool Path::CalcPath(){
        
        return false;
    }
    
}