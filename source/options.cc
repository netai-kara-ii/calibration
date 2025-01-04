// Local.
#include "options.h"

EuropeanOption::EuropeanOption(const Underlying &underlying, option_type type)
 : underlying(underlying), type(type) {
    int j = underlying.idx;

    if (options.size() <= static_cast<std::size_t>(j)) {
        options.resize(j + 1);
    }

    int i = options[j].size();
    options[j].emplace_back(i);
    idx = std::make_tuple(i, j);
}


/* 
 *  since we are working with column vectors later on,
 *  i.e., two dimensional objects spanning over rows,
 *  we build a transposed two dimensional vector of
 *  indices, so that each column corresponds to an 
 *  underlying. this way access is effortless later on.
 *  additionally, we use the tuple stl container since
 *  it supports unpacking.
*/
