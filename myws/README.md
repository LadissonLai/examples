为了学习apollo的编译方法，学习了最基本的bazel编译c++的方法。
首先将编译一个thirdparty的第三方库（包含头文件），然后在main文件夹调用第三方库并编译成一个二进制文件。

Bazel的基本文件夹结构
```shell
myws
├── main
│   ├── BUILD（必须）
│   └── main.cc
├── REAME.md
├── thirdparty
│   └── mylib
│       ├── BUILD(必须)
│       ├── mylib.cc
│       ├── mylib.h
│       └── mymath.h
└── WORKSPACE(必须)
```

第三方库的编译规则文件BUILD内容
```
cc_library(
    name = "mylib",
    srcs = ["mylib.cc"],
    hdrs = ["mylib.h", "mymath.h"],
    visibility = ["//visibility:public"]
)
```

主程序的BUILD
```
cc_binary(
    name = "main",
    srcs = ["main.cc"],
    deps = [
        "//thirdparty/mylib:mylib",
    ]
)
```

编译，参看build-custom.sh
```
./build-custom.sh
```

运行
```shell
./bazel-bin/main/main
```

备注：
第三方库虽然有头文件，但是和源文件cc放在同一个目录的，因此在主程序BUILD中并没有添加第三方库的头文件，这是一种巧妙的办法。