# Find the Thrift includes and library

FIND_PATH(THRIFT_INCLUDE_DIR thrift/Thrift.h
    /usr/local/include
    /usr/include
)

# On unix system, debug and release have the same name
FIND_LIBRARY(THRIFT_LIBRARY thrift
    ${THRIFT_INCLUDE_DIR}/../lib64
    /usr/local/lib64
    /usr/lib64)

IF (THRIFT_INCLUDE_DIR AND THRIFT_LIBRARY)
    SET(THRIFT_FOUND TRUE)
ENDIF (THRIFT_INCLUDE_DIR AND THRIFT_LIBRARY)

IF (THRIFT_FOUND)
    MESSAGE(STATUS "Found THRIFT INCLUDE: ${THRIFT_INCLUDE_DIR}")
    MESSAGE(STATUS "Found THRIFT LIBRARY: ${THRIFT_LIBRARY}")
    MESSAGE(STATUS "Found THRIFT_NB LIBRARY: ${THRIFT_NB_LIBRARY}")
    SET(THRIFT_LIBRARIES ${THRIFT_LIBRARY})
ELSE (THRIFT_FOUND)
    IF (THRIFT_FIND_REQUIRED)
        MESSAGE(FATAL_ERROR "THRIFT not found")
    ELSE (THRIFT_FIND_REQUIRED)
        MESSAGE(STATUS "THRIFT not found")
    ENDIF (THRIFT_FIND_REQUIRED)
ENDIF (THRIFT_FOUND)

MARK_AS_ADVANCED(THRIFT_INCLUDE_DIR THRIFT_LIBRARY)
