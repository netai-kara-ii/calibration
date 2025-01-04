add_executable(test_market)

target_sources( test_market PRIVATE 
    test-market.cc
    options.cc
    underlying.cc
)

target_include_directories(test_market PRIVATE 
    ${CMAKE_SOURCE_DIR}/include
    include_directories
    /usr/include/eigen3
)

set_target_properties(test_market PROPERTIES
    CXX_STANDARD_REQUIRED ON    
    CXX_EXTENSIONS OFF
)
