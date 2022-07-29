![](https://github.com/wniemiec-util-cpp/string-utils/blob/master/docs/img/logo/logo.jpg)

<h1 align='center'>String Utils</h1>
<p align='center'>Contains methods that perform string manipulation.</p>
<p align="center">
	<a href="https://github.com/wniemiec-util-cpp/string-utils/actions/workflows/windows.yml"><img src="https://github.com/wniemiec-util-cpp/string-utils/actions/workflows/windows.yml/badge.svg" alt=""></a>
	<a href="https://github.com/wniemiec-util-cpp/string-utils/actions/workflows/macos.yml"><img src="https://github.com/wniemiec-util-cpp/string-utils/actions/workflows/macos.yml/badge.svg" alt=""></a>
	<a href="https://github.com/wniemiec-util-cpp/string-utils/actions/workflows/ubuntu.yml"><img src="https://github.com/wniemiec-util-cpp/string-utils/actions/workflows/ubuntu.yml/badge.svg" alt=""></a>
	<a href="https://codecov.io/gh/wniemiec-util-cpp/string-utils"><img src="https://codecov.io/gh/wniemiec-util-cpp/string-utils/branch/master/graph/badge.svg?token=R2SFS4SP86" alt="Coverage status"></a>
	<a href="https://docs.microsoft.com/en-us/cpp/"><img src="https://img.shields.io/badge/C++-17+-D0008F.svg" alt="Cpp compatibility"></a>
	<a href="https://github.com/wniemiec-util-cpp/string-utils/releases"><img src="https://img.shields.io/github/v/release/wniemiec-util-cpp/string-utils" alt="Release"></a>
	<a href="https://github.com/wniemiec-util-cpp/string-utils/blob/master/LICENSE"><img src="https://img.shields.io/github/license/wniemiec-util-cpp/string-utils" alt="License"></a>
</p>
<hr />

## ❇ Introduction
Methods package that perform string manipulation.

## ❓ How to use
1. Add the content of the [`src`](https://github.com/wniemiec-util-cpp/string-utils/blob/master/src) folder to the folder containing your project's source files

2. Add the content of the [`include`](https://github.com/wniemiec-util-cpp/string-utils/blob/master/include) folder to the folder containing your project's header files

3. Copy the [`Makefile`](https://github.com/wniemiec-util-cpp/string-utils/blob/master/Makefile) to your project's root folder (if you already has one, merge the files)

4. Run the following commands:
```
$ make clean
$ make
```

5. Use it
```
[...]

#include "wniemiec/data/cpp/StringUtils.hpp";

[...]

std::string text = "hello world";

std::vector<std::string> words = StringUtils::split(text, " ");  // Returns ["hello", "world"]

std::cout << StringUtils::to_upper("hello world") << std::endl;  // Returns "HELLO WORLD"

[...]
```

**Note:** You can use cmake if you wish. To do this, use the [`CMakeLists.txt`](https://github.com/wniemiec-util-cpp/string-utils/blob/master/CMakeLists.txt) file.


## 📖 Documentation
|        Property        |Type|Description|Default|
|----------------|-------------------------------|-----------------------------|--------|
|split |`str: std::string, delimiter: std::string`|Returns a list of the words in the string, separated by the delimiter string| - |
|to_upper |`str: std::string`|Returns a copy of the string in UPPER CASE| - |
|replace_all |`str: std::string, old_value: std::string, new_value: std::string`|Searches a string for a value and generates a new string with the value(s) replaced| - |


## 🚩 Changelog
Details about each version are documented in the [releases section](https://github.com/williamniemiec/wniemiec-util-cpp/string-utils/releases).

## 🤝 Contribute!
See the documentation on how you can contribute to the project [here](https://github.com/wniemiec-util-cpp/string-utils/blob/master/CONTRIBUTING.md).

## 📁 Files

### /
|        Name        |Type|Description|
|----------------|-------------------------------|-----------------------------|
|dist |`Directory`|Released versions|
|docs |`Directory`|Documentation files|
|src     |`Directory`| Source files|
