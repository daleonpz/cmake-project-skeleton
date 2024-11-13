A collection of guides on how to perform various tasks using CMake and Ninja.

Table of Contents:
- [How to Build a Project Using CMake and Ninja](#how-to-build-a-project-using-cmake-and-ninja)
- [How to Run Tests Using CMake and Ninja](#how-to-run-tests-using-cmake-and-ninja)
- [How to Run Coverage Analysis, Static Code Analysis, and Code Formatting on Your Project Using CMake and Ninja](#how-to-run-coverage-analysis-static-code-analysis-and-code-formatting-on-your-project-using-cmake-and-ninja)
- [How to Flash a Binary to an STM32 Microcontroller Using STM32CubeProgrammer](#how-to-flash-a-binary-to-an-stm32-microcontroller-using-stm32cubeprogrammer)

# How to Build a Project Using CMake and Ninja
This guide explains how to build a project using CMake and Ninja.

## Step 1: Configure the Project

First, configure the project using CMake:

```sh
mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Debug -G Ninja
```

You can also specify additional options when configuring the project. For example, to enable coverage analysis:

```sh
cmake .. -DCMAKE_BUILD_TYPE=Debug -DENABLE_COVERAGE_ANALYSIS=ON -G Ninja
```

Or disable Position Independent Code (PIC):

```sh
cmake .. -DCMAKE_BUILD_TYPE=Debug -DCMAKE_POSITION_INDEPENDENT_CODE=OFF -G Ninja
```

## Step 2: Build the Project
Next, build the project using Ninja:

```sh
ninja
```

# How to Run Tests Using CMake and Ninja
This guide explains how to run tests using CMake and Ninja.

## Step 1: Configure the Project

First, configure the project with tests enabled:

```sh
cmake .. -DCMAKE_BUILD_TYPE=Debug -DENABLE_TESTS=ON -DBUILD_WITH_CPPCHECK_ANALYSIS=ON -G Ninja
```

## Step 2: Build the Project

Next, build the project using Ninja:

```sh
ninja
```

## Step 3: Run the Tests

Run all the tests:

```sh
ninja test
```

=======
>>>>>>> origin/main
# How to Run Coverage Analysis, Static Code Analysis, and Code Formatting on Your Project Using CMake and Ninja

This guide explains how to run coverage analysis, static code analysis, and code formatting on your project using CMake and Ninja.
## Step 1: Configure the Project

First, configure the project with coverage analysis enabled:

```sh
cmake .. -DCMAKE_BUILD_TYPE=Debug -DENABLE_COVERAGE_ANALYSIS=ON -DBUILD_WITH_CPPCHECK_ANALYSIS=ON -DUSE_SANITIZER=leak -G Ninja
```

## Step 2: Build the Project

Next, build the project using Ninja:

```sh
ninja
```

## Step 3: Run the Tests

Run all the tests to generate coverage data:

```sh
ninja test
```

Example output:

```sh
[0/1] Running tests...
Test project /home/dnl/Documents/git/cmake-project-skeleton/build
    Start 1: CMocka.ClearResults
1/4 Test #1: CMocka.ClearResults ..............   Passed    0.02 sec
    Start 2: MYPROJECT.Test
2/4 Test #2: MYPROJECT.Test ...................   Passed    0.00 sec
    Start 3: MYPROJECT.Catch2.Test
3/4 Test #3: MYPROJECT.Catch2.Test ............   Passed    0.01 sec
    Start 4: MYPROJECT.Google.Test
4/4 Test #4: MYPROJECT.Google.Test ............   Passed    0.01 sec

100% tests passed, 0 tests failed out of 4

Total Test time (real) =   0.03 sec
```

## Step 4: Verify Coverage Data Files

Verify the generation of coverage data files (`*.gcda`):

```sh
find . -name "*.gcda"
```

Example output:

```bash
./_deps/gtest-build/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.gcda
./_deps/gtest-build/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.gcda
./_deps/gtest-build/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.gcda
./test/CMakeFiles/MYPROJECT_google_tests.dir/gmock_test_case.cpp.gcda
./test/CMakeFiles/MYPROJECT_google_tests.dir/google_test_case.cpp.gcda
./test/CMakeFiles/MYPROJECT_tests.dir/main.c.gcda
./test/CMakeFiles/MYPROJECT_tests.dir/test_suite.c.gcda
./test/CMakeFiles/MYPROJECT_catch_tests.dir/catch2_test_case.cpp.gcda
./test/CMakeFiles/MYPROJECT_catch_tests.dir/__/cmake/test/catch_main.cpp.gcda
```

## Step 5: Generate Coverage Report

Generate the coverage report:

```sh
ninja ExperimentalCoverage
```

Example output:

```sh
[0/1] cd /home/dnl/Documents/git/cmake-project-skeleton/build && /home/dnl/Documents/stm32/st/CMake/bin/ctest -D ExperimentalCoverage
   Site: dnl
   Build name: Linux-c++
Performing coverage
   Processing coverage (each . represents one file):
    .........
   Accumulating results (each . represents one file):
    ......................................
        Covered LOC:         2777
        Not covered LOC:     7474
        Total LOC:           10251
        Percentage Coverage: 27.09%
```

## Step 6: Run Static Code Analysis and Formatting

You can also run static code analysis and code formatting tools:
**Run cppcheck**

```sh
ninja cppcheck
```

**Run clang-tidy**

```sh
ninja tidy
```

**Run clang-format**

```sh
ninja clang-format
```

This completes the process of running coverage analysis, static code analysis, and code formatting on your project.
<<<<<<< HEAD


# How to Flash a Binary to an STM32 Microcontroller Using STM32CubeProgrammer

This guide explains how to flash a binary to an STM32 microcontroller using STM32CubeProgrammer.

## Step 1: Build the Project

Build the project using Ninja and CMake:

```sh
mkdir build
cd build
cmake .. \
     # Specify the build type: Debug Release MinSizeRel RelWithDebInfo
    -DCMAKE_BUILD_TYPE=Debug  \
    -DCMAKE_TOOLCHAIN_FILE=cmake/toolchains/cross/STM32746G_Discovery.cmake \
    -DCMAKE_POSITION_INDEPENDENT_CODE=OFF -G Ninja
ninja all
```

## Step 2: Flash the Binary

When the build is successful, you can flash the binary to the STM32 microcontroller using STM32CubeProgrammer:

```sh
<PATH_TO_YOUR_STM32_TOOLS>/STM32CubeProgrammer/bin/STM32_Programmer_CLI -c port=swd freq=4000 -w src/Core/Core.bin 0x08000000 -rst
```

In this example, the binary file is `src/Core/Core.bin`, and the memory address is `0x08000000`.

This completes the process of flashing a binary to an STM32 microcontroller using STM32CubeProgrammer.
