# Install script for directory: /home/wwee163we/dir/homework/Search/project/searchEnginer/redis-plus-plus-master

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/wwee163we/dir/homework/Search/project/searchEnginer/redis-plus-plus-master/build/libredis++.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libredis++.so.1.3.2"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libredis++.so.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libredis++.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/home/wwee163we/dir/homework/Search/project/searchEnginer/redis-plus-plus-master/build/libredis++.so.1.3.2"
    "/home/wwee163we/dir/homework/Search/project/searchEnginer/redis-plus-plus-master/build/libredis++.so.1"
    "/home/wwee163we/dir/homework/Search/project/searchEnginer/redis-plus-plus-master/build/libredis++.so"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libredis++.so.1.3.2"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libredis++.so.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libredis++.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHANGE
           FILE "${file}"
           OLD_RPATH "/usr/local/lib:"
           NEW_RPATH "")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/usr/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cmake/redis++/redis++-targets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cmake/redis++/redis++-targets.cmake"
         "/home/wwee163we/dir/homework/Search/project/searchEnginer/redis-plus-plus-master/build/CMakeFiles/Export/share/cmake/redis++/redis++-targets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cmake/redis++/redis++-targets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cmake/redis++/redis++-targets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cmake/redis++" TYPE FILE FILES "/home/wwee163we/dir/homework/Search/project/searchEnginer/redis-plus-plus-master/build/CMakeFiles/Export/share/cmake/redis++/redis++-targets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cmake/redis++" TYPE FILE FILES "/home/wwee163we/dir/homework/Search/project/searchEnginer/redis-plus-plus-master/build/CMakeFiles/Export/share/cmake/redis++/redis++-targets-release.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/include/sw/redis++/cmd_formatter.h;/usr/local/include/sw/redis++/command.h;/usr/local/include/sw/redis++/command_args.h;/usr/local/include/sw/redis++/command_options.h;/usr/local/include/sw/redis++/connection.h;/usr/local/include/sw/redis++/connection_pool.h;/usr/local/include/sw/redis++/errors.h;/usr/local/include/sw/redis++/pipeline.h;/usr/local/include/sw/redis++/queued_redis.h;/usr/local/include/sw/redis++/queued_redis.hpp;/usr/local/include/sw/redis++/redis++.h;/usr/local/include/sw/redis++/redis.h;/usr/local/include/sw/redis++/redis.hpp;/usr/local/include/sw/redis++/redis_cluster.h;/usr/local/include/sw/redis++/redis_cluster.hpp;/usr/local/include/sw/redis++/reply.h;/usr/local/include/sw/redis++/sentinel.h;/usr/local/include/sw/redis++/shards.h;/usr/local/include/sw/redis++/shards_pool.h;/usr/local/include/sw/redis++/subscriber.h;/usr/local/include/sw/redis++/transaction.h;/usr/local/include/sw/redis++/utils.h;/usr/local/include/sw/redis++/tls.h;/usr/local/include/sw/redis++/cxx_utils.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local/include/sw/redis++" TYPE FILE FILES
    "/home/wwee163we/dir/homework/Search/project/searchEnginer/redis-plus-plus-master/src/sw/redis++/cmd_formatter.h"
    "/home/wwee163we/dir/homework/Search/project/searchEnginer/redis-plus-plus-master/src/sw/redis++/command.h"
    "/home/wwee163we/dir/homework/Search/project/searchEnginer/redis-plus-plus-master/src/sw/redis++/command_args.h"
    "/home/wwee163we/dir/homework/Search/project/searchEnginer/redis-plus-plus-master/src/sw/redis++/command_options.h"
    "/home/wwee163we/dir/homework/Search/project/searchEnginer/redis-plus-plus-master/src/sw/redis++/connection.h"
    "/home/wwee163we/dir/homework/Search/project/searchEnginer/redis-plus-plus-master/src/sw/redis++/connection_pool.h"
    "/home/wwee163we/dir/homework/Search/project/searchEnginer/redis-plus-plus-master/src/sw/redis++/errors.h"
    "/home/wwee163we/dir/homework/Search/project/searchEnginer/redis-plus-plus-master/src/sw/redis++/pipeline.h"
    "/home/wwee163we/dir/homework/Search/project/searchEnginer/redis-plus-plus-master/src/sw/redis++/queued_redis.h"
    "/home/wwee163we/dir/homework/Search/project/searchEnginer/redis-plus-plus-master/src/sw/redis++/queued_redis.hpp"
    "/home/wwee163we/dir/homework/Search/project/searchEnginer/redis-plus-plus-master/src/sw/redis++/redis++.h"
    "/home/wwee163we/dir/homework/Search/project/searchEnginer/redis-plus-plus-master/src/sw/redis++/redis.h"
    "/home/wwee163we/dir/homework/Search/project/searchEnginer/redis-plus-plus-master/src/sw/redis++/redis.hpp"
    "/home/wwee163we/dir/homework/Search/project/searchEnginer/redis-plus-plus-master/src/sw/redis++/redis_cluster.h"
    "/home/wwee163we/dir/homework/Search/project/searchEnginer/redis-plus-plus-master/src/sw/redis++/redis_cluster.hpp"
    "/home/wwee163we/dir/homework/Search/project/searchEnginer/redis-plus-plus-master/src/sw/redis++/reply.h"
    "/home/wwee163we/dir/homework/Search/project/searchEnginer/redis-plus-plus-master/src/sw/redis++/sentinel.h"
    "/home/wwee163we/dir/homework/Search/project/searchEnginer/redis-plus-plus-master/src/sw/redis++/shards.h"
    "/home/wwee163we/dir/homework/Search/project/searchEnginer/redis-plus-plus-master/src/sw/redis++/shards_pool.h"
    "/home/wwee163we/dir/homework/Search/project/searchEnginer/redis-plus-plus-master/src/sw/redis++/subscriber.h"
    "/home/wwee163we/dir/homework/Search/project/searchEnginer/redis-plus-plus-master/src/sw/redis++/transaction.h"
    "/home/wwee163we/dir/homework/Search/project/searchEnginer/redis-plus-plus-master/src/sw/redis++/utils.h"
    "/home/wwee163we/dir/homework/Search/project/searchEnginer/redis-plus-plus-master/src/sw/redis++/no_tls/tls.h"
    "/home/wwee163we/dir/homework/Search/project/searchEnginer/redis-plus-plus-master/src/sw/redis++/cxx11/cxx_utils.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cmake/redis++" TYPE FILE FILES
    "/home/wwee163we/dir/homework/Search/project/searchEnginer/redis-plus-plus-master/build/cmake/redis++-config.cmake"
    "/home/wwee163we/dir/homework/Search/project/searchEnginer/redis-plus-plus-master/build/cmake/redis++-config-version.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/wwee163we/dir/homework/Search/project/searchEnginer/redis-plus-plus-master/build/cmake/redis++.pc")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/wwee163we/dir/homework/Search/project/searchEnginer/redis-plus-plus-master/build/test/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/wwee163we/dir/homework/Search/project/searchEnginer/redis-plus-plus-master/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
