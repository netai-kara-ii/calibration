#ifndef TYPES_H
#define TYPES_H


#include <complex>
#include <cstdint>
#include <memory>


// From eigen.
#include <Eigen/Dense>



// Linear algebra and component-wise template datastruct. aliases, for easier reading.
// Fixed sizes are preferable when known at compile time and are small.
//
// See [The Matrix Class, Fixed vs. Dynamic Size]
//        @ https://eigen.tuxfamily.org/dox/group__TutorialMatrixClass.html
// for full discussion. 

// Why we do not change the storage order of datastructs. (i.e., row-major or column-major)?
// This has to do with Eigen's default order, which is column-major, meaning columns are stored
// contiguously in the memory. It also means that most of their testing/operations work best with 
// it, rather than row-major. 
//
// Even when most of the time we traverse Eigen objects in our code we do so row-by-row, 
// they are mostly column vectors, and otherwise accessed by full index. This minimises 
// effects of corrupting cache locality, as row or column vector elements are always contiguously
// stored regardless of the (row/col) order. 
//
// See [Storage Orders, Storage Orders in Eigen]
//      @ https://eigen.tuxfamily.org/dox/group__TopicStorageOrders.html
// for details on storage order.


template <typename T, Eigen::Index n = Eigen::Dynamic, Eigen::Index m = Eigen::Dynamic>
using ndarray = Eigen::Array<T, n, m>;


template <typename T, Eigen::Index n = Eigen::Dynamic, Eigen::Index m = Eigen::Dynamic>
using ndarray_ptr = std::shared_ptr<ndarray<T, n, m>>;


template <typename T, Eigen::Index n = Eigen::Dynamic>
using vector = Eigen::Matrix<T, n, 1>;


template <typename T, Eigen::Index n = Eigen::Dynamic, Eigen::Index m = Eigen::Dynamic>
using matrix = Eigen::Matrix<T, n, m>;


#endif
