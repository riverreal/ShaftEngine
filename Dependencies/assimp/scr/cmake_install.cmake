# Install script for directory: C:/Users/Riverreal/Desktop/assimp-master/code

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/Assimp")
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

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Users/Riverreal/Desktop/assimp-master/lib/Debug/assimp-vc140-mt.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Users/Riverreal/Desktop/assimp-master/lib/Release/assimp-vc140-mt.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Users/Riverreal/Desktop/assimp-master/lib/MinSizeRel/assimp-vc140-mt.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Users/Riverreal/Desktop/assimp-master/lib/RelWithDebInfo/assimp-vc140-mt.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Users/Riverreal/Desktop/assimp-master/bin/Debug/assimp-vc140-mt.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Users/Riverreal/Desktop/assimp-master/bin/Release/assimp-vc140-mt.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Users/Riverreal/Desktop/assimp-master/bin/MinSizeRel/assimp-vc140-mt.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Users/Riverreal/Desktop/assimp-master/bin/RelWithDebInfo/assimp-vc140-mt.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xassimp-devx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/assimp" TYPE FILE FILES
    "C:/Users/Riverreal/Desktop/assimp-master/code/../include/assimp/anim.h"
    "C:/Users/Riverreal/Desktop/assimp-master/code/../include/assimp/ai_assert.h"
    "C:/Users/Riverreal/Desktop/assimp-master/code/../include/assimp/camera.h"
    "C:/Users/Riverreal/Desktop/assimp-master/code/../include/assimp/color4.h"
    "C:/Users/Riverreal/Desktop/assimp-master/code/../include/assimp/color4.inl"
    "C:/Users/Riverreal/Desktop/assimp-master/code/../include/assimp/config.h"
    "C:/Users/Riverreal/Desktop/assimp-master/code/../include/assimp/defs.h"
    "C:/Users/Riverreal/Desktop/assimp-master/code/../include/assimp/Defines.h"
    "C:/Users/Riverreal/Desktop/assimp-master/code/../include/assimp/cfileio.h"
    "C:/Users/Riverreal/Desktop/assimp-master/code/../include/assimp/light.h"
    "C:/Users/Riverreal/Desktop/assimp-master/code/../include/assimp/material.h"
    "C:/Users/Riverreal/Desktop/assimp-master/code/../include/assimp/material.inl"
    "C:/Users/Riverreal/Desktop/assimp-master/code/../include/assimp/matrix3x3.h"
    "C:/Users/Riverreal/Desktop/assimp-master/code/../include/assimp/matrix3x3.inl"
    "C:/Users/Riverreal/Desktop/assimp-master/code/../include/assimp/matrix4x4.h"
    "C:/Users/Riverreal/Desktop/assimp-master/code/../include/assimp/matrix4x4.inl"
    "C:/Users/Riverreal/Desktop/assimp-master/code/../include/assimp/mesh.h"
    "C:/Users/Riverreal/Desktop/assimp-master/code/../include/assimp/pbrmaterial.h"
    "C:/Users/Riverreal/Desktop/assimp-master/code/../include/assimp/postprocess.h"
    "C:/Users/Riverreal/Desktop/assimp-master/code/../include/assimp/quaternion.h"
    "C:/Users/Riverreal/Desktop/assimp-master/code/../include/assimp/quaternion.inl"
    "C:/Users/Riverreal/Desktop/assimp-master/code/../include/assimp/scene.h"
    "C:/Users/Riverreal/Desktop/assimp-master/code/../include/assimp/metadata.h"
    "C:/Users/Riverreal/Desktop/assimp-master/code/../include/assimp/texture.h"
    "C:/Users/Riverreal/Desktop/assimp-master/code/../include/assimp/types.h"
    "C:/Users/Riverreal/Desktop/assimp-master/code/../include/assimp/vector2.h"
    "C:/Users/Riverreal/Desktop/assimp-master/code/../include/assimp/vector2.inl"
    "C:/Users/Riverreal/Desktop/assimp-master/code/../include/assimp/vector3.h"
    "C:/Users/Riverreal/Desktop/assimp-master/code/../include/assimp/vector3.inl"
    "C:/Users/Riverreal/Desktop/assimp-master/code/../include/assimp/version.h"
    "C:/Users/Riverreal/Desktop/assimp-master/code/../include/assimp/cimport.h"
    "C:/Users/Riverreal/Desktop/assimp-master/code/../include/assimp/importerdesc.h"
    "C:/Users/Riverreal/Desktop/assimp-master/code/../include/assimp/Importer.hpp"
    "C:/Users/Riverreal/Desktop/assimp-master/code/../include/assimp/DefaultLogger.hpp"
    "C:/Users/Riverreal/Desktop/assimp-master/code/../include/assimp/ProgressHandler.hpp"
    "C:/Users/Riverreal/Desktop/assimp-master/code/../include/assimp/IOStream.hpp"
    "C:/Users/Riverreal/Desktop/assimp-master/code/../include/assimp/IOSystem.hpp"
    "C:/Users/Riverreal/Desktop/assimp-master/code/../include/assimp/Logger.hpp"
    "C:/Users/Riverreal/Desktop/assimp-master/code/../include/assimp/LogStream.hpp"
    "C:/Users/Riverreal/Desktop/assimp-master/code/../include/assimp/NullLogger.hpp"
    "C:/Users/Riverreal/Desktop/assimp-master/code/../include/assimp/cexport.h"
    "C:/Users/Riverreal/Desktop/assimp-master/code/../include/assimp/Exporter.hpp"
    "C:/Users/Riverreal/Desktop/assimp-master/code/../include/assimp/DefaultIOStream.h"
    "C:/Users/Riverreal/Desktop/assimp-master/code/../include/assimp/DefaultIOSystem.h"
    "C:/Users/Riverreal/Desktop/assimp-master/code/../include/assimp/SceneCombiner.h"
    "C:/Users/Riverreal/Desktop/assimp-master/code/../include/assimp/fast_atof.h"
    "C:/Users/Riverreal/Desktop/assimp-master/code/../include/assimp/qnan.h"
    "C:/Users/Riverreal/Desktop/assimp-master/code/../include/assimp/BaseImporter.h"
    "C:/Users/Riverreal/Desktop/assimp-master/code/../include/assimp/Hash.h"
    "C:/Users/Riverreal/Desktop/assimp-master/code/../include/assimp/MemoryIOWrapper.h"
    "C:/Users/Riverreal/Desktop/assimp-master/code/../include/assimp/ParsingUtils.h"
    "C:/Users/Riverreal/Desktop/assimp-master/code/../include/assimp/StreamReader.h"
    "C:/Users/Riverreal/Desktop/assimp-master/code/../include/assimp/StreamWriter.h"
    "C:/Users/Riverreal/Desktop/assimp-master/code/../include/assimp/StringComparison.h"
    "C:/Users/Riverreal/Desktop/assimp-master/code/../include/assimp/StringUtils.h"
    "C:/Users/Riverreal/Desktop/assimp-master/code/../include/assimp/SGSpatialSort.h"
    "C:/Users/Riverreal/Desktop/assimp-master/code/../include/assimp/GenericProperty.h"
    "C:/Users/Riverreal/Desktop/assimp-master/code/../include/assimp/SpatialSort.h"
    "C:/Users/Riverreal/Desktop/assimp-master/code/../include/assimp/SkeletonMeshBuilder.h"
    "C:/Users/Riverreal/Desktop/assimp-master/code/../include/assimp/SmoothingGroups.h"
    "C:/Users/Riverreal/Desktop/assimp-master/code/../include/assimp/SmoothingGroups.inl"
    "C:/Users/Riverreal/Desktop/assimp-master/code/../include/assimp/StandardShapes.h"
    "C:/Users/Riverreal/Desktop/assimp-master/code/../include/assimp/RemoveComments.h"
    "C:/Users/Riverreal/Desktop/assimp-master/code/../include/assimp/Subdivision.h"
    "C:/Users/Riverreal/Desktop/assimp-master/code/../include/assimp/Vertex.h"
    "C:/Users/Riverreal/Desktop/assimp-master/code/../include/assimp/LineSplitter.h"
    "C:/Users/Riverreal/Desktop/assimp-master/code/../include/assimp/TinyFormatter.h"
    "C:/Users/Riverreal/Desktop/assimp-master/code/../include/assimp/Profiler.h"
    "C:/Users/Riverreal/Desktop/assimp-master/code/../include/assimp/LogAux.h"
    "C:/Users/Riverreal/Desktop/assimp-master/code/../include/assimp/Bitmap.h"
    "C:/Users/Riverreal/Desktop/assimp-master/code/../include/assimp/XMLTools.h"
    "C:/Users/Riverreal/Desktop/assimp-master/code/../include/assimp/IOStreamBuffer.h"
    "C:/Users/Riverreal/Desktop/assimp-master/code/../include/assimp/CreateAnimMesh.h"
    "C:/Users/Riverreal/Desktop/assimp-master/code/../include/assimp/irrXMLWrapper.h"
    "C:/Users/Riverreal/Desktop/assimp-master/code/../include/assimp/BlobIOSystem.h"
    "C:/Users/Riverreal/Desktop/assimp-master/code/../include/assimp/MathFunctions.h"
    "C:/Users/Riverreal/Desktop/assimp-master/code/../include/assimp/Macros.h"
    "C:/Users/Riverreal/Desktop/assimp-master/code/../include/assimp/Exceptional.h"
    "C:/Users/Riverreal/Desktop/assimp-master/code/../include/assimp/ByteSwapper.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xassimp-devx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/assimp/Compiler" TYPE FILE FILES
    "C:/Users/Riverreal/Desktop/assimp-master/code/../include/assimp/Compiler/pushpack1.h"
    "C:/Users/Riverreal/Desktop/assimp-master/code/../include/assimp/Compiler/poppack1.h"
    "C:/Users/Riverreal/Desktop/assimp-master/code/../include/assimp/Compiler/pstdint.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE FILES "C:/Users/Riverreal/Desktop/assimp-master/code/Debug/assimp-vc140-mt.pdb")
  endif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE FILES "C:/Users/Riverreal/Desktop/assimp-master/code/RelWithDebInfo/assimp-vc140-mt.pdb")
  endif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
endif()

