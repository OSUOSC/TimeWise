# TimeWise Contributing Guide

TimeWise is a Free and Open Source Software project under the MIT license. To ensure that the codebase is able to maintain a level of integrity, performance, and memory safety some guidelines are in place to ensure your success as a developer and the success of the software as a whole.

## Code Style Guidelines

- Tabs = 4 spaces
- Use tailing brackets:
```C
if (x) {
} else {
}
```
- Always use precision specification for floating point values
```C
correct:
float f = 0.5f;

incorrect:
float f = 0.5;
```
- All functions will start lowercase and use camel case
- All classes will start uppercase and use camelcase
```C++
void exampleFunction() {}
class ExampleClass {};
```
- Use the function naming convention for variables too.
- Avoid unclear abbreviation, favor more explicit variable names.
```C++
best:
clearBuffer

acceptable:
clrBuff

worst:
clBf
```

- End all typedefs with _t
- All defs and enums should be all caps snake case
- End all recursive functions with _r to ensure safety
- Error check any function that can fail
- Use sized operations as often as possible to avoid buffer overflows ex: strncpy vs strcpy
- Always favor passing by reference over pointer if possible
- Make all parameters that don't get modified in the function const for clearer function contracts
- Always favor C++ std over glibc.

## PR Guidelines

When opening a pull request ensure that your PR is limited in scope to a singular change, fix, or feature. Also make sure it includes the following

- A detailed description of what your changes include
- If a new function is added to the Lua API also include demo code in the example.lua file showing its use
- If you can, attach a screenshot demonstrating your change
- Please run your code through the e2e testing in the test folder. Simply cd into tests in the shell and execute run_tests.lua

PR's will be reviewed by one of the maintainers. If they request changes, please make them or the PR will not be able to be accepted.

## Issue Guidelines

When opening an issue please follow a similar format to PRs

- A detailed description of what your issue is
- If it is a bug include steps to recreate the issue
- If the issue is asking for a new lua API method, show an example of its intended use if you can
- If you can, attach a screenshot showing your issue

