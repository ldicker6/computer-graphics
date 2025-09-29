#include "lineSegments.h"
#include <math.h>
#include <Util/exceptions.h>

using namespace Util;
using namespace Image;

////////////////////////////
// Image processing stuff //
////////////////////////////


double OrientedLineSegment::length( void ) const
{
	////////////////////////////
	// Return the length here //
	////////////////////////////
	//distance between the endpints = length
	double x_dist = endPoints[1][0] - endPoints[0][0];
	double y_dist = endPoints[1][1] - endPoints[0][1];
	return sqrt(x_dist*x_dist+ y_dist*y_dist);

}



double OrientedLineSegment::distance( Point2D p ) const
{
	//////////////////////////////
	// Return the distance here //
	//////////////////////////////
	//This method returns the shortest distance from the point (x,y) to the line segment.
	//perpendicular dist

	//from lec we know the formula is dist(p) = perp distance to the line if the projection is 0-1
											//= ||p-s|| if proj < 0
											//= ||p-t|| if proj >1

	double start_x = endPoints[0][0], start_y = endPoints[0][1];
    double end_x = endPoints[1][0], end_y = endPoints[1][1];
	double x_dist = endPoints[1][0] - endPoints[0][0];
	double y_dist = endPoints[1][1] - endPoints[0][1]; 
	
	double x_dir = end_x - start_x;
    double y_dir = end_y - start_y;
	double len = length(); // this is ||t-s|| 

	double p_to_s_x = p[0] - start_x;
	double p_to_s_y = p[1] - start_y;

	//from lec, define u = ((p-s)(t-s))/||t-s||^2
	double u = ((p_to_s_x * x_dir) + (p_to_s_y*y_dir) ) / (len*len);

	if(u < 0.0) {
    	return sqrt(p_to_s_x*p_to_s_x + p_to_s_y*p_to_s_y);
    }
	else if(u > 1.0) {
        double p_t_x = p[0] - end_x;
        double p_t_y = p[1] - end_y;
        return sqrt(p_t_x*p_t_x + p_t_y*p_t_y);
    }
    else {
        Point2D perp = perpendicular(); //perpendicular dist to line (unit)
        double ret = p_to_s_x*perp[0] + p_to_s_y*perp[1];
        return fabs(ret);
    }

	//return -1.;
}


Point2D OrientedLineSegment::perpendicular( void ) const
{
	////////////////////////////////
	// Set the perpendicular here //
	////////////////////////////////
	double x_dist = endPoints[1][0] - endPoints[0][0];
	double y_dist = endPoints[1][1] - endPoints[0][1];
	//perpendicular vector (-y, x)
    double perp_x = -x_dist;
    double perp_y = y_dist;

	double len = length();
	//normalize it  for unit vec
    if(len != 0) {
        perp_x /= len;
        perp_y /= len;
    }
	//return new vec 
	return Point2D(perp_x, perp_y);

}


Point2D OrientedLineSegment::GetSourcePosition( const OrientedLineSegment& source , const OrientedLineSegment& destination , Point2D target )
{
	//p = pt in dest image
	//destination = destination line segment s,t
	//source = source line segment s't'
	//v1 = p-s, v2 = t-s , u:proj v1 onto v2 div v2^2, v: proj v1 onto perp v2

    //grab endpionts
    Point2D s_dst = destination.endPoints[0];
    Point2D t_dst = destination.endPoints[1];
    Point2D s_src = source.endPoints[0];
    Point2D t_src = source.endPoints[1];
    //grab direction vectors
    Point2D dir_dst = t_dst - s_dst;
    Point2D dir_src = t_src - s_src;

    //vec from start of destination to target
    Point2D p_vec = target - s_dst;

    double len_dst = destination.length();
	//er check
    if (len_dst == 0){
		return s_src;
	} 
    //compute u (par)
    double u = (p_vec[0]*dir_dst[0] + p_vec[1]*dir_dst[1])/ (len_dst*len_dst);
    //compute v (perp)
    Point2D perp_dst(-dir_dst[1], dir_dst[0]); 
    double v = (p_vec[0]*perp_dst[0] + p_vec[1]*perp_dst[1])/ len_dst;

    //now we can get srcpt
    double len_src = source.length();
    if (len_src == 0){
		return s_src;
	}
	//perpendicular to source
    Point2D perp_src(-dir_src[1], dir_src[0]); 

    Point2D result = s_src + (dir_src * u)+ (perp_src * (v / len_src));
    return result;
}
