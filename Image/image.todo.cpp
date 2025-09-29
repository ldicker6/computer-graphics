#include <algorithm>
#include "image.h"
#include <stdlib.h>
#include <math.h>
#include <Util/exceptions.h>

using namespace Util;
using namespace Image;

/////////////
// Image32 //
/////////////
Image32 Image32::addRandomNoise( double noise ) const
{
	///////////////////////////
	// Add random noise here //
	///////////////////////////
	Image32 edited;
	edited.setSize(width(), height());
	for(int y = 0; y < height(); y++){
		for(int x=0; x<width(); x++){
			Pixel32 p = (*this)(x,y);
			//we want our random offset to be chosen from the range of (-noise factor, +noise factor)
			float noise_offset = (((rand() / (float)RAND_MAX)*2) -1 )*noise;
			float red = p.r + noise_offset;
			p.r = (red < 0.0f)   ? 0 : (red > 255.0f) ? 255 : red;
			float blue = p.b + noise_offset;
			p.b = (blue < 0.0f)   ? 0 : (blue > 255.0f) ? 255 : blue;
			float green = p.g + noise_offset;
			p.g = (green < 0.0f)   ? 0 : (green > 255.0f) ? 255 : green;
			edited(x,y) = p;
		}
	}
	return edited;
}

Image32 Image32::brighten( double brightness ) const
{
	/////////////////////////
	// Do brightening here //
	/////////////////////////

	Image32 edited;
	edited.setSize(width(), height());
	for(int y = 0; y < height(); y++){
		for(int x=0; x<width(); x++){
			Pixel32 p = (*this)(x,y);
			float red = p.r * (float)brightness;
			p.r = (red < 0.0f)   ? 0 : (red > 255.0f) ? 255 : red;
			float blue = p.b * (float)brightness;
			p.b = (blue < 0.0f)   ? 0 : (blue > 255.0f) ? 255 : blue;
			float green = p.g * (float)brightness;
			p.g = (green < 0.0f)   ? 0 : (green > 255.0f) ? 255 : green;
			edited(x,y) = p;
		}
	}
	return edited;
}

Image32 Image32::luminance( void ) const
{
	//////////////////////////////////
	// Compute luminance image here //
	//////////////////////////////////
	Image32 edited;
	edited.setSize(width(), height());
	for(int y = 0; y < height(); y++){
		for(int x=0; x<width(); x++){
			Pixel32 p = (*this)(x,y);
			float weighted_avg = 0.30*(p.r) + (0.59*p.g) + (0.11*p.b);
			p.r = weighted_avg;
			p.g = weighted_avg;
			p.b = weighted_avg;
			edited(x,y) = p;
		}
	}

	//WARN( "method undefined" );
	return edited;
}

Image32 Image32::contrast( double contrast ) const
{
	//////////////////////////////////
	// Do contrast enhancement here //
	//////////////////////////////////
	Image32 edited;
    edited.setSize(width(), height());
    for(int y = 0; y < height(); y++){
        for(int x = 0; x < width(); x++){
            Pixel32 p = (*this)(x,y);
			//adj around midpoint
            float red   = (p.r - 128.0f) * contrast + 128.0f;
            p.r = (red   < 0.0f) ? 0 : (red   > 255.0f ? 255 : red);
            float blue  = (p.b - 128.0f) * contrast + 128.0f;
            p.b = (blue  < 0.0f) ? 0 : (blue  > 255.0f ? 255 : blue);
			float green = (p.g - 128.0f) * contrast + 128.0f;
            p.g = (green < 0.0f) ? 0 : (green > 255.0f ? 255 : green);
            edited(x,y) = p;
        }
    }
    return edited;
}

Image32 Image32::saturate( double saturation ) const
{
	////////////////////////////////////
	// Do saturation enhancement here //
	////////////////////////////////////
	Image32 edited;
	edited.setSize(width(), height());
	for(int y = 0; y < height(); y++){
		for(int x=0; x<width(); x++){
			Pixel32 p = (*this)(x,y);
			float per_pix_lum = 0.30*(p.r) + (0.59*p.g) + (0.11*p.b);
			float red = (p.r - per_pix_lum)*saturation + per_pix_lum;
			p.r = (red < 0.0f)   ? 0 : (red > 255.0f) ? 255 : red;
			float blue = (p.b - per_pix_lum)*saturation + per_pix_lum;
			p.b = (blue < 0.0f)   ? 0 : (blue > 255.0f) ? 255 : blue;
			float green = (p.g - per_pix_lum)*saturation + per_pix_lum;
			p.g = (green < 0.0f)   ? 0 : (green > 255.0f) ? 255 : green;
			edited(x,y) = p;
		}
	}
	//WARN( "method undefined" );
	return edited;
}

Image32 Image32::quantize( int bits ) const
{
	//////////////////////////
	// Do quantization here //
	//////////////////////////
	int num_levels = 1 << bits;  
	float scale = (num_levels - 1)/255;

	Image32 edited;
	edited.setSize(width(), height());
	for(int y = 0; y < height(); y++){
		for(int x=0; x<width(); x++){
			Pixel32 p = (*this)(x,y);

			int level = (int)round( (p.r / 255.0f) * (num_levels - 1) );
			p.r = (unsigned char)( (level * 255.0f) / (num_levels - 1) );
			level = (int)round( (p.b / 255.0f) * (num_levels - 1) );
			p.b = (unsigned char)( (level * 255.0f) / (num_levels - 1) );
			level = (int)round( (p.g / 255.0f) * (num_levels - 1) );
			p.g = (unsigned char)( (level * 255.0f) / (num_levels - 1) );
			edited(x,y) = p;
		}
	}
	//WARN( "method undefined" );
	return edited;
}

Image32 Image32::randomDither( int bits ) const
{
	//////////////////////////////
	// Do random dithering here //
	//////////////////////////////
	 // number of quantization levels
    int num_levels = 1 << bits;  // 2^bits

    Image32 edited;
    edited.setSize(width(), height());
    //loop through pixels
    for(int y = 0; y < height(); y++){
        for(int x = 0; x < width(); x++){
            Pixel32 p = (*this)(x,y);

            //normalize the red value, scale it to quantization levels
            float red_normalized = p.r / 255.0f;
            float red_scaled = red_normalized * num_levels;
            //add a rand fraction
            float red_random = (float)rand() / (float)RAND_MAX;  // [0,1)
            red_scaled = red_scaled + red_random;
            //floor + get integer level, then clamp it in bounds
            int red_level = (int)floor(red_scaled);
            if(red_level < 0) red_level = 0;
            if(red_level > num_levels - 1) red_level = num_levels - 1;
            //map it back to 0,255
            unsigned char red_out = (unsigned char)((red_level * 255.0f) / (num_levels - 1));
			p.r = red_out;

            //same process for green and blue
            float green_normalized = p.g / 255.0f;
            float green_scaled = green_normalized * num_levels;
            float green_random = (float)rand() / (float)RAND_MAX;
            green_scaled = green_scaled + green_random;
            int green_level = (int)floor(green_scaled);
            if(green_level < 0) green_level = 0;
            if(green_level > num_levels - 1) green_level = num_levels - 1;
            unsigned char green_out = (unsigned char)((green_level * 255.0f) / (num_levels - 1));
			p.g = green_out;

            float blue_normalized = p.b / 255.0f;
            float blue_scaled = blue_normalized * num_levels;
            float blue_random = (float)rand() / (float)RAND_MAX;
            blue_scaled = blue_scaled + blue_random;
            int blue_level = (int)floor(blue_scaled);
            if(blue_level < 0) blue_level = 0;
            if(blue_level > num_levels - 1) blue_level = num_levels - 1;
            unsigned char blue_out = (unsigned char)((blue_level * 255.0f) / (num_levels - 1));
			p.b = blue_out;

            edited(x,y) = p;
        }
    }
    return edited;
}

Image32 Image32::orderedDither2X2( int bits ) const
{
	///////////////////////////////
	// Do ordered dithering here //
	///////////////////////////////
	// number of  levels (2^bits)
     int num_levels = 1 << bits;  // 2^bits
    int k = 2;

    // D2 matrix from the slides
    int D2[2][2] = { {1, 3},
                     {4, 2} };

    Image32 edited;
    edited.setSize(width(), height());

    for(int y = 0; y < height(); y++){
        for(int x = 0; x < width(); x++){
            Pixel32 p = (*this)(x,y);
            //find out where in 2x2 matrix we are
            int i = x % k;
            int j = y % k;
            //compute threshold in [0,1], from D2 / (k^2+1)
            float threshold = (float)D2[j][i] / (float)(k*k + 1);

            //normalize red, scale it to quantization levels
            float red_fraction = p.r / 255.0f;
            float red_scaled   = red_fraction * num_levels;
            //depending on threshold, round up or down
            int red_level = (red_fraction > threshold) ? (int)ceil(red_scaled) : (int)floor(red_scaled);
            //clamp it so it doesn't go out of range
            if(red_level < 0) { red_level = 0; }
            if(red_level > num_levels - 1){red_level = num_levels - 1;}
            //convert back to 0,255
            unsigned char red_out = (unsigned char)((red_level * 255.0f) / (num_levels - 1));

            //same process for green
            float green_fraction = p.g / 255.0f;
            float green_scaled   = green_fraction * num_levels;
            int green_level  = (green_fraction > threshold) ? (int)ceil(green_scaled) : (int)floor(green_scaled);
            if(green_level < 0) green_level = 0;
            if(green_level > num_levels - 1) green_level = num_levels - 1;
            unsigned char green_out = (unsigned char)((green_level * 255.0f) / (num_levels - 1));

            //same process for blue
            float blue_fraction = p.b / 255.0f;
            float blue_scaled= blue_fraction * num_levels;
            int  blue_level = (blue_fraction > threshold) ? (int)ceil(blue_scaled) : (int)floor(blue_scaled);
            if(blue_level < 0) blue_level = 0;
            if(blue_level > num_levels - 1) blue_level = num_levels - 1;
            unsigned char blue_out = (unsigned char)((blue_level * 255.0f) / (num_levels - 1));

            p.r = red_out;
            p.g = green_out;
            p.b = blue_out;
            edited(x,y) = p;
        }
    }
    return edited;
}

Image32 Image32::floydSteinbergDither( int bits ) const
{
	int w = width();
	int h = height();
	//num leveles =  2^bits
	int num_levels = 1 << bits;                  

	//store the original pixels in buffers 
	int num_pixels = w*h;
	std::vector<float> orig_r(num_pixels), orig_g(num_pixels), orig_b(num_pixels);
	for (int j = 0; j < h; j++){
		for (int i = 0; i < w; i++){
			//borrow the pixel, and copy its value to the original copy
			const Pixel32& s = (*this)(i,j);
			int idx = j*w + i;
			orig_r[idx] = (float)s.r;
			orig_g[idx] = (float)s.g;
			orig_b[idx] = (float)s.b;
		}
	}

	Image32 edited;
	edited.setSize(w, h);

	//mark down the weights for floyd steinberg from notes (alpha, beta, gamma, delta) 
	float alpha = 7.0f / 16.0f;   //top right(i+1, j)
	float beta  = 3.0f / 16.0f;   //bottom left(i-1, j+1)
	float gamma = 5.0f / 16.0f;   //down(i,   j+1)
	float delta = 1.0f / 16.0f;   //bottom right(i+1, j+1)

	//quantize channel val from 0-255 to num levels, and round 
	for (int j = 0; j < h; j++){
		for (int i = 0; i < w; i++){
			int idx = j*w + i; //make the index accessible in one dimension for accessing our original pixels

			float src_red = orig_r[idx];
            //map into levels
			int  level_red = (int)round( (src_red / 255.0f) * (num_levels - 1) );
			if (level_red < 0) level_red = 0;
			if (level_red > num_levels - 1) level_red = num_levels - 1;
			float quantized_red = (level_red * 255.0f) / (float)(num_levels - 1);
            //again for green 
			float src_green = orig_g[idx];
			int   level_green = (int)round( (src_green / 255.0f) * (num_levels - 1) );
			if (level_green < 0) level_green = 0;
			if (level_green > num_levels - 1) level_green = num_levels - 1;
			float quantized_green = (level_green * 255.0f) / (float)(num_levels - 1);
            //blue
			float src_blue = orig_b[idx];
			int   level_blue = (int)round( (src_blue / 255.0f) * (num_levels - 1) );
			if (level_blue < 0) level_blue = 0;
			if (level_blue > num_levels - 1) level_blue = num_levels - 1;
			float quantized_blue = (level_blue * 255.0f) / (float)(num_levels - 1);

			//calc the error (orig - quantized)
			float err_red = src_red - quantized_red;
			float err_green = src_green - quantized_green;
			float err_blue = src_blue - quantized_blue;
			//wruite curr pixel
			Pixel32 q = (*this)(i,j);
			int r_pix = (int)lround(quantized_red); if (r_pix < 0) r_pix = 0; if (r_pix > 255) r_pix = 255;
			int g_pix = (int)lround(quantized_green); if (g_pix < 0) g_pix = 0; if (g_pix > 255) g_pix = 255;
			int b_pix = (int)lround(quantized_blue); if (b_pix < 0) b_pix = 0; if (b_pix > 255) b_pix = 255;
			q.r = (unsigned char)r_pix;
			q.g = (unsigned char)g_pix;
			q.b = (unsigned char)b_pix;
			edited(i,j) = q;

			//distribute error
			// source{i+1, j}   += α * error
			if (i + 1 < w){
				int n = j*w + (i + 1);
				orig_r[n] += alpha * err_red;
				orig_g[n] += alpha * err_green;
				orig_b[n] += alpha * err_blue;
			}
			// sourc{i-1, j+1} += β * error
			if (i - 1 >= 0 && j + 1 < h){
				int n = (j + 1)*w + (i - 1);
				orig_r[n] += beta * err_red;
				orig_g[n] += beta * err_green;
				orig_b[n] += beta * err_blue;
			}
			// source{i,   j+1} += γ * error
			if (j + 1 < h){
				int n = (j + 1)*w + i;
				orig_r[n] += gamma * err_red;
				orig_g[n] += gamma * err_green;
				orig_b[n] += gamma * err_blue;
			}
			// source{i+1, j+1} += δ * error
			if (i + 1 < w && j + 1 < h){
				int n = (j + 1)*w + (i + 1);
				orig_r[n] += delta * err_red;
				orig_g[n] += delta * err_green;
				orig_b[n] += delta * err_blue;
			}
		}
	}

	return edited;
}

Image32 Image32::blur3X3( void ) const
{
	//////////////////////
	// Do blurring here //
	//////////////////////
	const int w  = width();
	const int h  = height();
	Image32 edited;
    edited.setSize(w, h);

	int weight_sum = 16;
	std::vector<std::vector<int>> blur_mat(3, std::vector<int>(3));	
	blur_mat[0][0] = 1;
	blur_mat[0][1] = 2;
	blur_mat[0][2] = 1;
	blur_mat[1][0] = 2;
	blur_mat[1][1] = 4;
	blur_mat[1][2] = 2;
	blur_mat[2][0] = 1;
	blur_mat[2][1] = 2;
	blur_mat[2][2] = 1;

	for(int y = 0; y < h; y++){
		for(int x = 0; x < w; x++){
			float r_sum = 0.0f;
			float g_sum = 0.0f;
			float b_sum = 0.0f;
			const Pixel32& p = (*this)(x,y);
			//loop over neighbords
			for(int horiz = -1; horiz <= 1; horiz++){
				for(int vert = -1; vert <= 1; vert++){
					int ny = y + horiz;
					int nx = x + vert;

					//clamp edge cases
					if (ny < 0) ny = 0;
					if (ny >= h) ny = h - 1;
					if (nx < 0) nx = 0;
					if (nx >= w) nx = w - 1;

					Pixel32 neighbor = (*this)(nx, ny);
					int weight = blur_mat[horiz + 1][vert + 1];
                    //add weighted vals to sums
					r_sum += weight * neighbor.r;
					g_sum += weight * neighbor.g;
					b_sum += weight * neighbor.b;
				}
			}
			//normalize the final sums , then clamp
			int r_new = (int)lround(r_sum / (float)weight_sum);
			if (r_new < 0) r_new = 0;
			if (r_new > 255) r_new = 255;
			int b_new = (int)lround(b_sum / (float)weight_sum);
			if (b_new < 0) b_new = 0;
			if (b_new > 255) b_new = 255;
			int g_new = (int)lround(g_sum / (float)weight_sum);
			if (g_new < 0) g_new = 0;
			if (g_new > 255) g_new = 255;

			//copy new pixel and set to edited
			Pixel32 out_pixel = p;
			out_pixel.r = (unsigned char)r_new;
			out_pixel.g = (unsigned char)g_new;
			out_pixel.b = (unsigned char)b_new;
			edited(x,y) = out_pixel;
		}
	}
	return edited;
}

Image32 Image32::edgeDetect3X3(void) const
{
    const int w = width();
    const int h = height();
    Image32 edited;
    edited.setSize(w, h);

    int laplacian_filter[3][3] = {
        {-1, -1, -1},
        {-1,  8, -1},
        {-1, -1, -1}
    };

    std::vector<float> r_vals(w*h), g_vals(w*h), b_vals(w*h);
    float max_val = 1e-6f; //track global max

    //iterate over the pixels
    for(int y = 0; y < h; y++){
        for(int x = 0; x < w; x++){
            float r_sum = 0, g_sum = 0, b_sum = 0;
            //iterate over the 3x3 neighborhood
            for(int dy = -1; dy <= 1; dy++){
                for(int dx = -1; dx <= 1; dx++){
                    //clamp border pixels
                    int ny = y + dy; if(ny < 0) ny = 0; if(ny >= h) ny = h-1;
                    int nx = x + dx; if(nx < 0) nx = 0; if(nx >= w) nx = w-1;
                    //mult neighbor pixel by kernel weight and add to our rgbsum
                    Pixel32 p = (*this)(nx, ny);
                    int weight = laplacian_filter[dy+1][dx+1];
                    r_sum += weight * p.r;
                    g_sum += weight * p.g;
                    b_sum += weight * p.b;
                }
            }
            //after convolution take abs 
            int idx = y*w + x;
            //store in buff
            r_vals[idx] = std::fabs(r_sum);
            g_vals[idx] = std::fabs(g_sum);
            b_vals[idx] = std::fabs(b_sum);
            //update global max
            if(r_vals[idx] > max_val) max_val = r_vals[idx];
            if(g_vals[idx] > max_val) max_val = g_vals[idx];
            if(b_vals[idx] > max_val) max_val = b_vals[idx];
        }
    }
    //normalize the channels
    for(int y = 0; y < h; y++){
        for(int x = 0; x < w; x++){
            int idx = y*w + x;
            int r_new = (int)(255.0f * r_vals[idx] / max_val);
            int g_new = (int)(255.0f * g_vals[idx] / max_val);
            int b_new = (int)(255.0f * b_vals[idx] / max_val);
            //assign edited pixel
            Pixel32 res;
            res.r = (unsigned char)r_new;
            res.g = (unsigned char)g_new;
            res.b = (unsigned char)b_new;
            edited(x,y) = res;
        }
    }
    return edited;
}

Image32 Image32::scaleNearest( double scaleFactor ) const
{
	/////////////////////////////////////////////////
	// Do scaling with nearest-point sampling here //
	/////////////////////////////////////////////////
    int w = width();
    int h = height();

    int new_w = (int)std::floor(w * scaleFactor + 0.5);
    int new_h = (int)std::floor(h * scaleFactor + 0.5);

    Image32 edited;
    edited.setSize(new_w, new_h);
    //loop through pixels of the new img
    for (int j = 0; j < new_h; j++) {
        for (int i = 0; i < new_w; i++) {
            //map back to where it cme from
            double u = i / scaleFactor;
            double v = j / scaleFactor;
            //use nearest sample which clamps/rounds
            Pixel32 res = nearestSample(Point2D(u, v));
            edited(i, j) = res;
        }
    }
    return edited;
}

Image32 Image32::scaleBilinear( double scaleFactor ) const
{
	////////////////////////////////////////////
	// Do scaling with bilinear sampling here //
	////////////////////////////////////////////
    int w = width();
    int h = height();
    int new_w = (int)std::floor(w * scaleFactor + 0.5);
    int new_h = (int)std::floor(h * scaleFactor + 0.5);

    Image32 edited;
    edited.setSize(new_w, new_h);

    for (int j = 0; j < new_h; j++) {
        for (int i = 0; i < new_w; i++) {
            //map back to og image
            double u = i / scaleFactor;
            double v = j / scaleFactor;
            // use our bilinearSample 
            Pixel32 out = bilinearSample(Point2D(u, v));
            edited(i, j) = out;
        }
    }

    return edited;
}

Image32 Image32::scaleGaussian( double scaleFactor ) const
{
	////////////////////////////////////////////
	// Do scaling with Gaussian sampling here //
	////////////////////////////////////////////
    int w = width();
    int h = height();
    int new_w = (int)std::floor(w * scaleFactor + 0.5);
    int new_h = (int)std::floor(h * scaleFactor + 0.5);

    Image32 edited;
    edited.setSize(new_w, new_h);

    //chose 1,2
    double variance = 1.0;   
    double radius   = 2.0;   //how many neighbors to check

    for (int j = 0; j < new_h; j++) {
        for (int i = 0; i < new_w; i++) {
            double u = i / scaleFactor;
            double v = j / scaleFactor;
            // call gaussianSample
            Pixel32 out = gaussianSample(Point2D(u, v), variance, radius);
            edited(i, j) = out;
        }
    }

    return edited;
}

Image32 Image32::rotateNearest( double angle ) const
{
	//////////////////////////////////////////////////
	// Do rotation with nearest-point sampling here //
	//////////////////////////////////////////////////
	const int w  = width();
	const int h  = height();

	//compute theta in radians
	double rad_angle = angle * M_PI /180;
	double cos_ang = std::cos(rad_angle);
	double sin_ang = std::sin(rad_angle);

	double x_center = (w - 1) * 0.5;
	double y_center = (h - 1) * 0.5;
	//definte 4 og corners:
	std::vector<std::pair<double,double>> corners = { {-w/2.0, -h/2.0},{ w/2.0, -h/2.0},{-w/2.0,  h/2.0},{ w/2.0,  h/2.0}};
	//using the Φ rotation function as given in notes
	std::vector<std::pair<double,double>> rotated_corners;
	for (size_t i = 0; i < corners.size(); i++) {
		double u = corners[i].first;   
		double v = corners[i].second;  

		double x_prime = u * cos_ang - v * sin_ang;
		double y_prime = u * sin_ang + v * cos_ang;
		rotated_corners.push_back(std::pair<double,double>(x_prime, y_prime));
	}
	double min_x = rotated_corners[0].first;
	double max_x = rotated_corners[0].first;
	double min_y = rotated_corners[0].second;
	double max_y = rotated_corners[0].second;

	for (int i = 1; i < 4; i++) {
		double curr_x = rotated_corners[i].first;
		double curr_y = rotated_corners[i].second;

		if (curr_x < min_x) min_x = curr_x;
		if (curr_x > max_x) max_x = curr_x;

		if (curr_y < min_y) min_y = curr_y;
		if (curr_y > max_y) max_y = curr_y;
	}
	//to fit the new image, we find the new output size
	int output_width = std::ceil(max_x - min_x);
	int output_height = std::ceil(max_y - min_y);


	Image32 edited;
	edited.setSize(output_width, output_height);

	double output_cent_x = (output_width  - 1) * 0.5;
	double output_cent_y = (output_height - 1) * 0.5;


	for (int j = 0; j < output_height; j++) {
        for (int i = 0; i < output_width; i++) {

            double x_output_centered = i - output_cent_x;
            double y_output_centered = j - output_cent_y;

            //apply inverse rotation to original image
            double x_orig_centered =  x_output_centered * cos_ang + y_output_centered * sin_ang;
            double y_orig_centered = -x_output_centered * sin_ang + y_output_centered * cos_ang;

            double u = x_orig_centered + x_center;
            double v = y_orig_centered + y_center;

            //for nearest neighbours round-to-nearest via floor(x+0.5)
            int new_u = (int)std::floor(u + 0.5);
            int new_v = (int)std::floor(v + 0.5);

			//check that the new pixel is grabbable from the orig image and then write to new pixel
            if (new_u >= 0 && new_u < w && new_v >= 0 && new_v < h) {
                edited(i, j) = (*this)(new_u, new_v);
            } else {
                Pixel32 background_pixel;
                background_pixel.r = background_pixel.g = background_pixel.b = 0; 
                edited(i, j) = background_pixel;
            }
        }
    }

	return edited;
}

Image32 Image32::rotateBilinear( double angle ) const
{

	const int w  = width();
	const int h  = height();

	//compute theta in radians
	double rad_angle = angle * M_PI /180;
	double cos_ang = std::cos(rad_angle);
	double sin_ang = std::sin(rad_angle);

	double x_center = (w - 1) * 0.5;
	double y_center = (h - 1) * 0.5;
	//definte 4 og corners:
	std::vector<std::pair<double,double>> corners = { {-w/2.0, -h/2.0},{ w/2.0, -h/2.0},{-w/2.0,  h/2.0},{ w/2.0,  h/2.0}};
	//using the Φ rotation function
	std::vector<std::pair<double,double>> rotated_corners;
	for (size_t i = 0; i < corners.size(); i++) {
		double u = corners[i].first;   
		double v = corners[i].second;  

		double x_prime = u * cos_ang - v * sin_ang;
		double y_prime = u * sin_ang + v * cos_ang;

		rotated_corners.push_back(std::pair<double,double>(x_prime, y_prime));
	}
	double min_x = rotated_corners[0].first;
	double max_x = rotated_corners[0].first;
	double min_y = rotated_corners[0].second;
	double max_y = rotated_corners[0].second;

	for (int i = 1; i < 4; i++) {
		double curr_x = rotated_corners[i].first;
		double curr_y = rotated_corners[i].second;

		if (curr_x < min_x) min_x = curr_x;
		if (curr_x > max_x) max_x = curr_x;

		if (curr_y < min_y) min_y = curr_y;
		if (curr_y > max_y) max_y = curr_y;
	}
	//to fit the new image, we find the new output size
	int output_width = std::ceil(max_x - min_x);
	int output_height = std::ceil(max_y - min_y);


	Image32 edited;
	edited.setSize(output_width, output_height);

	double output_cent_x = (output_width  - 1) * 0.5;
	double output_cent_y = (output_height - 1) * 0.5;


	for (int j = 0; j < output_height; j++) {
        for (int i = 0; i < output_width; i++) {

            double x_output_centered = i - output_cent_x;
            double y_output_centered = j - output_cent_y;

            //apply inverse rotation to original image
            double x_orig_centered =  x_output_centered * cos_ang + y_output_centered * sin_ang;
            double y_orig_centered = -x_output_centered * sin_ang + y_output_centered * cos_ang;

            double u = x_orig_centered + x_center;
            double v = y_orig_centered + y_center;

			//bilinear interpolation

			int u1 = (int)std::floor(u);   
			int u2 = u1 + 1;               
			int v1 = (int)std::floor(v);   
			int v2 = v1 + 1;  

			double du = u - u1;            
			double dv = v - v1; 
			
			if (u1 >= 0 && u2 < w && v1 >= 0 && v2 < h) {
				Pixel32 p_1 = (*this)(u1,v1);  
				Pixel32 p_2 = (*this)(u2,v1);  
				Pixel32 p_3 = (*this)(u1,v2);  
				Pixel32 p_4 = (*this)(u2,v2);  

				Pixel32 out;

				// red channel
				double a_r = p_1.r * (1 - du) + p_2.r * du;
				double b_r = p_3.r * (1 - du) + p_4.r * du;
				out.r = (unsigned char)(a_r * (1 - dv) + b_r * dv);

				// green channel
				double a_g = p_1.g * (1 - du) + p_2.g * du;
				double b_g = p_3.g * (1 - du) + p_4.g * du;
				out.g = (unsigned char)(a_g * (1 - dv) + b_g * dv);

				// blue channel
				double a_b = p_1.b * (1 - du) + p_2.b * du;
				double b_b = p_3.b * (1 - du) + p_4.b * du;
				out.b = (unsigned char)(a_b * (1 - dv) + b_b * dv);
				edited(i,j) = out;
			} else {
				Pixel32 background;
				background.r = background.g = background.b = 0;
				edited(i,j) = background;
			}



        }
    }

	return edited;
}

Image32 Image32::rotateGaussian(double angle) const
{
    const int w = width();
    const int h = height();
    double rad_angle = angle * M_PI / 180.0;
    double cos_ang = std::cos(rad_angle);
    double sin_ang = std::sin(rad_angle);

    double x_center = (w - 1) * 0.5;
    double y_center = (h - 1) * 0.5;

    // define 4 orig corners
    std::vector<std::pair<double,double>> corners = {{-w/2.0, -h/2.0}, { w/2.0, -h/2.0},{-w/2.0,  h/2.0},{ w/2.0,  h/2.0}};

    //rotate corners
    std::vector<std::pair<double,double>> rotated_corners;
    for (size_t i = 0; i < corners.size(); i++) {
        double u = corners[i].first;
        double v = corners[i].second;
        double x_prime = u * cos_ang - v * sin_ang;
        double y_prime = u * sin_ang + v * cos_ang;
        rotated_corners.push_back(std::pair<double,double>(x_prime, y_prime));
    }

    // find bounding box of rotated corners
    double min_x = rotated_corners[0].first;
    double max_x = rotated_corners[0].first;
    double min_y = rotated_corners[0].second;
    double max_y = rotated_corners[0].second;
    for (int i = 1; i < 4; i++) {
        if (rotated_corners[i].first  < min_x) min_x = rotated_corners[i].first;
        if (rotated_corners[i].first  > max_x) max_x = rotated_corners[i].first;
        if (rotated_corners[i].second < min_y) min_y = rotated_corners[i].second;
        if (rotated_corners[i].second > max_y) max_y = rotated_corners[i].second;
    }

    // output image size
    int output_width  = (int)std::ceil(max_x - min_x);
    int output_height = (int)std::ceil(max_y - min_y);

    Image32 edited;
    edited.setSize(output_width, output_height);

    double output_cent_x = (output_width  - 1) * 0.5;
    double output_cent_y = (output_height - 1) * 0.5;

    //gaussian parameters so that we have a 3x3 neighborhood
    double sigma = 2/3;
    int radius = (int)std::ceil(3 * sigma);

    for (int j = 0; j < output_height; j++) {
        for (int i = 0; i < output_width; i++) {

            // center the output pixel coords
            double x_output_centered = i - output_cent_x;
            double y_output_centered = j - output_cent_y;

            // inverse rotation to original coords
            double x_orig_centered =  x_output_centered * cos_ang + y_output_centered * sin_ang;
            double y_orig_centered = -x_output_centered * sin_ang + y_output_centered * cos_ang;

            double u = x_orig_centered + x_center;
            double v = y_orig_centered + y_center;

            // accumulators
            double r_acc = 0.0, g_acc = 0.0, b_acc = 0.0;
            double tot_weight = 0.0;

            //loop over neighbors
            for (int ny = -radius; ny <= radius; ny++) {
                for (int nx = -radius; nx <= radius; nx++) {
                    int potential_x = (int)std::floor(u) + nx;
                    int potential_y = (int)std::floor(v) + ny;

                    if (potential_x >= 0 && potential_x < w &&
                        potential_y >= 0 && potential_y < h) {
                        //compute distance
                        double dx = potential_x - u;
                        double dy = potential_y - v;
                        //use gaussian function
                        double weight = std::exp(-(dx*dx + dy*dy) / (2 * sigma * sigma));

                        Pixel32 p = (*this)(potential_x, potential_y);
                        //accumulate weight so we can divide by tot_weight
                        r_acc += weight * p.r;
                        g_acc += weight * p.g;
                        b_acc += weight * p.b;
                        tot_weight += weight;
                    }
                }
            }
            //normalize and assign to output pixel
            Pixel32 res;
            if (tot_weight > 0) {
                res.r = (unsigned char)(r_acc / tot_weight);
                res.g = (unsigned char)(g_acc / tot_weight);
                res.b = (unsigned char)(b_acc / tot_weight);
            } else {
                res.r = res.g = res.b = 0;
            }

            edited(i, j) = res;
        }
    }
    return edited;
}


void Image32::setAlpha( const Image32& matte )
{
	///////////////////////////
	// Set alpha values here //
	///////////////////////////
	WARN( "method undefined" );
}

Image32 Image32::composite( const Image32& overlay ) const
{
	/////////////////////////
	// Do compositing here //
	/////////////////////////
	WARN( "method undefined" );
	return Image32();
}

Image32 Image32::CrossDissolve( const Image32& source , const Image32& destination , double blendWeight )
{
	////////////////////////////
	// Do cross-dissolve here //
	////////////////////////////
	int w = source.width();
    int h = source.height();
    Image32 result;
    result.setSize(w, h);
    //loop through all the pixels
	for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {

            //grab source and dest pixels, and one that blends them (p)
            Pixel32 p1 = source(x, y);
            Pixel32 p2 = destination(x, y);

            Pixel32 p;

            //take a fraction of both images for all channel values and add the fractional components
            p.r = (unsigned char)((1.0 - blendWeight) * p1.r + blendWeight * p2.r);
            p.g = (unsigned char)((1.0 - blendWeight) * p1.g + blendWeight * p2.g);
            p.b = (unsigned char)((1.0 - blendWeight) * p1.b + blendWeight * p2.b);
            result(x, y) = p;
        }
    }
    return result;
}

Image32 Image32::warp(const OrientedLineSegmentPairs &olsp) const {
    Image32 warped;
    warped.setSize(width(), height());
    //loop through dest pixels and find corresponding source point
    for (int y = 0; y < height(); y++) {
        for (int x = 0; x < width(); x++) {
            Util::Point2D dest_point(x, y);

            //get src position
            Util::Point2D src_point = olsp.getSourcePosition(dest_point);

            //use samplign to grab the pixel/coloring from the source point
            Pixel32 color = this->nearestSample(src_point); //accounts for out of bounds
            warped(x, y) = color;
        }
    }

    return warped;
}


Image32 Image32::funFilter( void ) const
{
    //swirl fucntion
	const int w = width();
    const int h = height();
    Image32 edited;
    edited.setSize(w, h);
    //get center
    double x_center = (w - 1) * 0.5;
    double y_center = (h - 1) * 0.5;

    //distortion factor
    double k = 3;
    //find largest radius(distance from center to outer corner)
    double r_max = std::sqrt(x_center*x_center + y_center*y_center);

    for (int j = 0; j < h; j++) {
        for (int i = 0; i < w; i++) {
            //shift pixels so 0,0 is still at center
            //(cartesian)
            double x_c = i - x_center;
            double y_c = j - y_center;
            //find our r and theta  (polar coordinates_)
            double r = std::sqrt(x_c*x_c + y_c*y_c);
            double theta = std::atan2(y_c, x_c);
            //find the theta, and theta offset we need to apply to the pixel
            double theta_prime = theta + k * (r / r_max);
            //map back to cartesian
            double x_src = r * std::cos(theta_prime);
            double y_src = r * std::sin(theta_prime);
            //shift back to the original space we were in (ceneterd)
            double u = x_src + x_center;
            double v = y_src + y_center;
            //resample using nearest (round to nearest pixel location)
            int u_round = (int)std::floor(u + 0.5);
            int v_round = (int)std::floor(v + 0.5);
            Pixel32 res;
            if (u_round >= 0 && u_round < w && v_round >= 0 && v_round < h) {
                res = (*this)(u_round, v_round);
            } else {
                res.r = res.g = res.b = 0;
            }
            edited(i, j) = res;
        }
    }
    return edited;
}

Image32 Image32::crop( int x1 , int y1 , int x2 , int y2 ) const
{
	//////////////////////
	// Do cropping here //
	//////////////////////
	//clamp coordinates
	x1 = (x1 < 0) ? 0 : x1;
    y1 = (y1 < 0) ? 0 : y1;
    x2 = (x2 >= width())  ? width()  - 1 : x2;
    y2 = (y2 >= height()) ? height() - 1 : y2;
    //make sure the 1 is less than the 2 coord
	if(x2 < x1){ int temp = x1; x1 = x2; x2 = temp;}
	if(y2 < y1){ int temp = y1; y1 = y2; y2 = temp;}
    //find new w/h
	int crop_w = x2 - x1 + 1;
    int crop_h = y2 - y1 + 1;

	Image32 edited;
    edited.setSize(crop_w, crop_h);
	for (int j = 0; j < crop_h; j++) {
        for (int i = 0; i < crop_w; i++) {
            edited(i, j) = (*this)(x1 + i, y1 + j);
        }
    }
	return edited;

}

Pixel32 Image32::nearestSample( Point2D p ) const
{
    int u = (int)std::floor(p[0] + 0.5);
    int v = (int)std::floor(p[1] + 0.5);

    if (u >= 0 && u < width() && v >= 0 && v < height()) {
        return (*this)(u, v);
    } else {
        //if out of bounds return  a black pixel for the backgroun d
        Pixel32 background;
        background.r = background.g = background.b = 0;
        return background;
    }
}


Pixel32 Image32::bilinearSample( Point2D p ) const
{
    const int w = width();
    const int h = height();

    //coords
    double u = p[0];
    double v = p[1];
    //bottom left and to pright pixel
    int u1 = (int)std::floor(u);
    int u2 = u1 + 1;
    int v1 = (int)std::floor(v);
    int v2 = v1 + 1;
    //offsets
    double du = u - u1;
    double dv = v - v1;

    Pixel32 res;
    //make sure inside range
    if (u1 >= 0 && u2 < w && v1 >= 0 && v2 < h) {
        //grab four surroudning pix
        Pixel32 p_1 = (*this)(u1, v1);
        Pixel32 p_2 = (*this)(u2, v1);
        Pixel32 p_3 = (*this)(u1, v2);
        Pixel32 p_4 = (*this)(u2, v2);
        //interpolate horiz then vertically
		//red
        double a_r = p_1.r * (1 - du) + p_2.r * du;
        double b_r = p_3.r * (1 - du) + p_4.r * du;
        res.r = (unsigned char)(a_r * (1 - dv) + b_r * dv);
        //gree n
        double a_g = p_1.g * (1 - du) + p_2.g * du;
        double b_g = p_3.g * (1 - du) + p_4.g * du;
        res.g = (unsigned char)(a_g * (1 - dv) + b_g * dv);
        //blue
        double a_b = p_1.b * (1 - du) + p_2.b * du;
        double b_b = p_3.b * (1 - du) + p_4.b * du;
        res.b = (unsigned char)(a_b * (1 - dv) + b_b * dv);
    } else {
        res.r = res.g = res.b = 0;
    }
    return res;
}

Pixel32 Image32::gaussianSample( Point2D p , double variance , double radius ) const
{
    const int w = width();
    const int h = height();

    double u = p[0];
    double v = p[1];
	//get sigma from variance
    double sigma = std::sqrt(variance);
    double r_acc = 0.0, g_acc = 0.0, b_acc = 0.0;
    double tot_weight = 0.0;

    //loop over neighbors (radius is how many pix)
    for (int ny = -radius; ny <= radius; ny++) {
        for (int nx = -radius; nx <= radius; nx++) {

            int potential_x = (int)std::floor(u) + nx;
            int potential_y = (int)std::floor(v) + ny;
            if (potential_x >= 0 && potential_x < w && potential_y >= 0 && potential_y < h) {
                //distance to the neighbor
                double dx = potential_x - u;
                double dy = potential_y - v;
                //gaussian wieght using gaussian formula
                double weight = std::exp(-(dx*dx + dy*dy) / (2 * sigma * sigma));

                Pixel32 p = (*this)(potential_x, potential_y);
                //accumulate weighted contribution
                r_acc += weight * p.r;
                g_acc += weight * p.g;
                b_acc += weight * p.b;
                tot_weight += weight;
            }
        }
    }
    //normalize and return pixel
    Pixel32 res;
    if (tot_weight > 0) {
        res.r = (unsigned char)(r_acc / tot_weight);
        res.g = (unsigned char)(g_acc / tot_weight);
        res.b = (unsigned char)(b_acc / tot_weight);
    } else {
        res.r = res.g = res.b = 0;
    }

    return res;
}
