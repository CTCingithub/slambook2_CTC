# 使用cmake编译静态库

使用cmake编译静态库（static library）需要以下步骤：

1. 编写CMakeLists.txt文件;
2. 在终端中创建build文件夹，并进入build文件夹;
3. 调用cmake对该工程进行cmake编译;
4. 使用make进行编译。

具体命令如下：

```bash
mkdir build
cd build
cmake ..
make
```

此时，会在build文件夹中生成一个libhello.a的静态库文件。
