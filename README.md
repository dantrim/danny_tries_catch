# danny_tries_catch
A test repo for me to learn how to use the [Catch2 testing framework](https://github.com/catchorg/Catch2)

[![GitHub Actions Status Badge: CI/CD]][GitHub Actions Status: CI/CD]

## Checkout and Install
```bash
$ git clone --recursive git@github.com:dantrim/danny_tries_catch.git
$ cd danny_tries_catch
$ mkdir build
$ cd build
$ cmake ..
$ make
```

## Structure
All tests are are defined following the file format `test_<name>.h` under 
the [tests/ directory](tests/).

All tests are compiled into a single executable `tests_main`, defined
under [tests/tests_main.cpp](tests/tests_main.cpp).

A dummy library `foo` is built under [src/foo.h](src/foo.h), in order to
add a test calling a method from an external library.

## Run all Tests
To list all available tests (their names and tags), do:
```bash
$ cd /path/to/danny_tries_catch/build/tests
$ ./tests_main --list-tests
All available test cases:
  Add one to an input number
      [add1][simple]
  Add two to an input number
      [add2][simple]
  Testing Catch2 sections
      [sections]
  Fibonacci
      [benchmark]
  Illustrating basic GENERATE functionality with integers
      [generators][int]
  Illustrating basic GENERATE functionality with vectors
      [generators][vector]
  Illustrating custom generator
      [custom][generators]
  Test contents of data0
      [fixtures]
  Test of libfoo
      [foo]
9 test cases
```
To run all tests, simply run the top-level test executable with no arguments:
```bash
$ ./tests_main

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
tests_main is a Catch v2.13.4 host application.
Run with -? for options
... # cut
===============================================================================
test cases:  9 |  8 passed | 1 failed
assertions: 45 | 44 passed | 1 failed
```


## Run Specific Tests
Tests are defined with specific [tags](https://github.com/catchorg/Catch2/blob/devel/docs/test-cases-and-sections.md#tags) in Catch2, and they
can be used to specify specific tests to run. To list all tags, one can
do:
```bash
$ ./tests_main --list-tags 
All available tags:
   1  [add1]
   1  [add2]
   1  [benchmark]
   1  [custom]
   1  [fixtures]
   1  [foo]
   3  [generators]
   1  [int]
   1  [sections]
   2  [simple]
   1  [vector]
11 tags
```
We can list all tests matching a specific tag using the command
line option `-t`:
```bash
./tests_main -t [generators]
Tags for matching test cases:
   1  [custom]
   3  [generators]
   1  [int]
   1  [vector]
4 tags
```
If we want to run only those tests matching the `generators` tag, we
can do:
```bash
$ ./tests_main [generators]
Filters: [generators]
===============================================================================
All tests passed (24 assertions in 3 test cases)
```
If we want to run only those tests that match a sub-tag, we can provide 
multiple sets of tags:
```bash
./tests_main [generators][custom]
Filters: [generators][custom]
===============================================================================
All tests passed (12 assertions in 1 test case)
```

## Benchmarking Functionality
Catch2 provides some minimal benchmarking functionality, which is
exercised in the [test_benchmark test](tests/test_benchmark.h):
```bash
$ ./tests_main [benchmark]
Filters: [benchmark]

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
tests_main is a Catch v2.13.4 host application.
Run with -? for options

-------------------------------------------------------------------------------
Fibonacci
-------------------------------------------------------------------------------
/Users/dantrim/workarea/danny_tries_catch/tests/test_benchmark.h:8
...............................................................................

benchmark name                       samples       iterations    estimated
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
[benchmark][20]                                100             2     6.7996 ms 
                                        37.5611 us    35.1604 us     41.249 us 
                                        14.9277 us    10.8343 us    20.3578 us 
                                                                               
[benchmark][25]                                100             1    35.2081 ms 
                                        350.014 us    346.449 us    358.169 us 
                                        26.1602 us    14.4852 us    50.6317 us 
                                                                               
[benchmark][30]                                100             1     400.25 ms 
                                        3.93643 ms    3.89937 ms    4.03341 ms 
                                         284.51 us    136.813 us    596.665 us 
                                                                               
[benchmark][35]                                100             1     4.65895 s 
                                        46.1587 ms    45.7395 ms    46.6272 ms 
                                        2.25356 ms    2.00019 ms    2.54572 ms 
                                                                               

===============================================
```

### Reducing the Output from Benchmarks
To reduce the output, and just get the mean evaluation time over the
samples, provide the `--benchmark-no-analysis` option:
```bash
$ ./tests_main [benchmark] --benchmark-no-analysis
Filters: [benchmark]

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
tests_main is a Catch v2.13.4 host application.
Run with -? for options

-------------------------------------------------------------------------------
Fibonacci
-------------------------------------------------------------------------------
/Users/dantrim/workarea/danny_tries_catch/tests/test_benchmark.h:8
...............................................................................

benchmark name                            samples    iterations          mean
-------------------------------------------------------------------------------
[benchmark][20]                                100             2    32.9106 us 
[benchmark][25]                                100             1    389.447 us 
[benchmark][30]                                100             1    4.15934 ms 
[benchmark][35]                                100             1    46.6336 ms 

===============================================================================
All tests passed (2 assertions in 1 test case)
```
Configuration of the benchmarking (number of samples, etc) can be seen by
inspecting the command line options (`./tests_main -h`).

<!--- LINKS --->
[GitHub Actions Status Badge: CI/CD]:https://github.com/dantrim/danny_tries_catch/workflows/CI/CD/badge.svg?branch=main
[GitHub Actions Status: CI/CD]:https://github.com/dantrim/danny_tries_catch/actions?query=workflow%3ACI%2FCD+branch%3Amain