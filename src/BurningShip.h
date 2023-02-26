#ifndef _BURNING_SHIP_H
#define _BURNING_SHIP_H
#include <iostream>
#include "ComplexFractal.h"

class BurningShip : public ComplexFractal {
    public:
        BurningShip( );
        BurningShip( const int& height, const int& width, const double& min_x, const double& max_x, const double& min_y, const double& max_y );
        virtual ~BurningShip( );
        virtual void calculateNextPoint( const double x0, const double y0, const double& a, const double& b, double& x1, double &y1 ) const;
        int calculatePlaneEscapeCount( const double& a, const double& b ) const;
        virtual int calculateNumber( const int& row, const int& column ) const;
};

#endif /* BURNING_SHIP_H */