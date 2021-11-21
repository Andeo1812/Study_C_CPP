INCLUDE_DIRECTORIES(include)
ADD_LIBRARY(prepmatrix STATIC
        src/matrix.cpp
        src/opr_base.cpp
        src/opr_math.cpp
        src/opr_step_view.cpp
        src/opr_extra.cpp)

ADD_SUBDIRECTORY(tests)
