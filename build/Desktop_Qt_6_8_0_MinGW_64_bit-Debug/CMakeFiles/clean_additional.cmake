# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\appqt-qml-series_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\appqt-qml-series_autogen.dir\\ParseCache.txt"
  "appqt-qml-series_autogen"
  )
endif()
