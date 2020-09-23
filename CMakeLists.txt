cmake_minimum_required(VERSION 3.0)
project(FirstLab)
add_executable(1 main.cpp)
set_target_properties(1 PROPERTIES
	CXX_STANDARD 14
	CXX_STANDARD_REQUIRED ON
	)
