# Install script for directory: /home/su/CLionProjects/XmlRepo/tinyXml

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
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
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
  set(CMAKE_INSTALL_SO_NO_EXE "0")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/llvm-objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "tinyxml2_development" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64" TYPE STATIC_LIBRARY FILES "/home/su/CLionProjects/XmlRepo/cmake-build-debug/tinyXml/libtinyxml2.a")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "tinyxml2_development" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/cmake/tinyxml2/tinyxml2-static-targets.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/cmake/tinyxml2/tinyxml2-static-targets.cmake"
         "/home/su/CLionProjects/XmlRepo/cmake-build-debug/tinyXml/CMakeFiles/Export/b22fc8d8db2702d542b15f76ebe2d748/tinyxml2-static-targets.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/cmake/tinyxml2/tinyxml2-static-targets-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/cmake/tinyxml2/tinyxml2-static-targets.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/cmake/tinyxml2" TYPE FILE FILES "/home/su/CLionProjects/XmlRepo/cmake-build-debug/tinyXml/CMakeFiles/Export/b22fc8d8db2702d542b15f76ebe2d748/tinyxml2-static-targets.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/cmake/tinyxml2" TYPE FILE FILES "/home/su/CLionProjects/XmlRepo/cmake-build-debug/tinyXml/CMakeFiles/Export/b22fc8d8db2702d542b15f76ebe2d748/tinyxml2-static-targets-debug.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "tinyxml2_development" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/cmake/tinyxml2" TYPE FILE FILES
    "/home/su/CLionProjects/XmlRepo/tinyXml/cmake/tinyxml2-config.cmake"
    "/home/su/CLionProjects/XmlRepo/cmake-build-debug/tinyXml/tinyxml2-config-version.cmake"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "tinyxml2_development" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES "/home/su/CLionProjects/XmlRepo/tinyXml/tinyxml2.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "tinyxml2_development" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/pkgconfig" TYPE FILE FILES "/home/su/CLionProjects/XmlRepo/cmake-build-debug/tinyXml/tinyxml2.pc")
endif()

