
if(NOT "A:/Programming/Projects--c---/Tests/cmake-build-debug/_deps/cpr-subbuild/cpr-populate-prefix/src/cpr-populate-stamp/cpr-populate-gitinfo.txt" IS_NEWER_THAN "A:/Programming/Projects--c---/Tests/cmake-build-debug/_deps/cpr-subbuild/cpr-populate-prefix/src/cpr-populate-stamp/cpr-populate-gitclone-lastrun.txt")
  message(STATUS "Avoiding repeated git clone, stamp file is up to date: 'A:/Programming/Projects--c---/Tests/cmake-build-debug/_deps/cpr-subbuild/cpr-populate-prefix/src/cpr-populate-stamp/cpr-populate-gitclone-lastrun.txt'")
  return()
endif()

execute_process(
  COMMAND ${CMAKE_COMMAND} -E rm -rf "A:/Programming/Projects--c---/Tests/cmake-build-debug/_deps/cpr-src"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to remove directory: 'A:/Programming/Projects--c---/Tests/cmake-build-debug/_deps/cpr-src'")
endif()

# try the clone 3 times in case there is an odd git clone issue
set(error_code 1)
set(number_of_tries 0)
while(error_code AND number_of_tries LESS 3)
  execute_process(
    COMMAND "A:/Programs/Git/cmd/git.exe"  clone --no-checkout --config "advice.detachedHead=false" "https://github.com/libcpr/cpr.git" "cpr-src"
    WORKING_DIRECTORY "A:/Programming/Projects--c---/Tests/cmake-build-debug/_deps"
    RESULT_VARIABLE error_code
    )
  math(EXPR number_of_tries "${number_of_tries} + 1")
endwhile()
if(number_of_tries GREATER 1)
  message(STATUS "Had to git clone more than once:
          ${number_of_tries} times.")
endif()
if(error_code)
  message(FATAL_ERROR "Failed to clone repository: 'https://github.com/libcpr/cpr.git'")
endif()

execute_process(
  COMMAND "A:/Programs/Git/cmd/git.exe"  checkout c8d33915dbd88ad6c92b258869b03aba06587ff9 --
  WORKING_DIRECTORY "A:/Programming/Projects--c---/Tests/cmake-build-debug/_deps/cpr-src"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to checkout tag: 'c8d33915dbd88ad6c92b258869b03aba06587ff9'")
endif()

set(init_submodules TRUE)
if(init_submodules)
  execute_process(
    COMMAND "A:/Programs/Git/cmd/git.exe"  submodule update --recursive --init 
    WORKING_DIRECTORY "A:/Programming/Projects--c---/Tests/cmake-build-debug/_deps/cpr-src"
    RESULT_VARIABLE error_code
    )
endif()
if(error_code)
  message(FATAL_ERROR "Failed to update submodules in: 'A:/Programming/Projects--c---/Tests/cmake-build-debug/_deps/cpr-src'")
endif()

# Complete success, update the script-last-run stamp file:
#
execute_process(
  COMMAND ${CMAKE_COMMAND} -E copy
    "A:/Programming/Projects--c---/Tests/cmake-build-debug/_deps/cpr-subbuild/cpr-populate-prefix/src/cpr-populate-stamp/cpr-populate-gitinfo.txt"
    "A:/Programming/Projects--c---/Tests/cmake-build-debug/_deps/cpr-subbuild/cpr-populate-prefix/src/cpr-populate-stamp/cpr-populate-gitclone-lastrun.txt"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to copy script-last-run stamp file: 'A:/Programming/Projects--c---/Tests/cmake-build-debug/_deps/cpr-subbuild/cpr-populate-prefix/src/cpr-populate-stamp/cpr-populate-gitclone-lastrun.txt'")
endif()

