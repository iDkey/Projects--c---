if(NOT EXISTS "A:/Programming/Projects--c---/Course/Module 30/Task 3/cmake-build-debug/_deps/curl-build/install_manifest.txt")
  message(FATAL_ERROR "Cannot find install manifest: A:/Programming/Projects--c---/Course/Module 30/Task 3/cmake-build-debug/_deps/curl-build/install_manifest.txt")
endif()

if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/Task_3")
endif()
message(${CMAKE_INSTALL_PREFIX})

file(READ "A:/Programming/Projects--c---/Course/Module 30/Task 3/cmake-build-debug/_deps/curl-build/install_manifest.txt" files)
string(REGEX REPLACE "\n" ";" files "${files}")
foreach(file ${files})
  message(STATUS "Uninstalling $ENV{DESTDIR}${file}")
  if(IS_SYMLINK "$ENV{DESTDIR}${file}" OR EXISTS "$ENV{DESTDIR}${file}")
    exec_program(
      "A:/Programs/CLion/CLion 2021.3/bin/cmake/win/bin/cmake.exe" ARGS "-E remove \"$ENV{DESTDIR}${file}\""
      OUTPUT_VARIABLE rm_out
      RETURN_VALUE rm_retval
      )
    if(NOT "${rm_retval}" STREQUAL 0)
      message(FATAL_ERROR "Problem when removing $ENV{DESTDIR}${file}")
    endif()
  else()
    message(STATUS "File $ENV{DESTDIR}${file} does not exist.")
  endif()
endforeach()
