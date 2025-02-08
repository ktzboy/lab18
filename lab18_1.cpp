#include<iostream>
using namespace std;

struct Rect{
	double x,y,w,h;
};

double overlap(Rect s1, Rect s2){
    Rect Rsq, Lsq, Tsq, Usq;

    double findRsq = max(s1.x+s1.w, s2.x+s2.w);
    if(findRsq == s1.x+s1.w) {
        Rsq = s1;
        Lsq = s2;
    } else {
        Lsq = s1;
        Rsq = s2;
    }
    
    double x;
    if(Lsq.x+Lsq.w <= Rsq.x) return 0;
    else x = Lsq.x+Lsq.w-max(Rsq.x, Lsq.x);
	//x-axis
	//--------------------------------------------------
	//y-axis
	double findTsq = max(s1.y, s2.y);
	if(findTsq == s1.y) {
        Tsq = s1;
        Usq = s2;
    } else {
        Usq = s1;
        Tsq = s2;
    }
    
    double y;
	if(Tsq.y > Usq.y) y = Usq.y - max(Usq.y-Usq.h, Tsq.y-Tsq.h);
	else y = Tsq.y - max(Usq.y-Usq.h, Tsq.y-Tsq.h);
	
    return x*y;
}