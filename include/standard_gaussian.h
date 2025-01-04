#ifndef STANDARD_GAUSSIAN_H
#define STANDARD_GAUSSIAN_H


// From boost.
#include <boost/math/distributions.hpp>


class StandardGaussian {
    // Standard gaussian distribution wrapper.

    public:
        StandardGaussian(void) : dist(0.0, 1.0) {};

        float cdf(float x) {
            return boost::math::cdf(dist, x);
        };

        float icdf(float p) {
            return boost::math::quantile(dist, p);
        };

        float pdf(float x) {
            return boost::math::pdf(dist, x);
        };

    private:
        boost::math::normal_distribution<float> dist;
};


#endif 
