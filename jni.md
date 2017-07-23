# JNI的用法
### Java Native Interface，是Java与本地代码库（C/C++）相互调用的接口。
### 实现Hello World
* 在java文件里([JniTest.java](https://github.com/y0711/Java/blob/master/JniTest.java))load native库，并声明native函数，然后调用它
* 编译生成JniTest.class文件：javac JniTest.java
* 生成[JniTest.h](https://github.com/y0711/Java/blob/master/JniTest.h)文件：javah -jni JniTest
* 新建[JniTest.cpp](https://github.com/y0711/Java/blob/master/JniTest.cpp)文件，实现.h文件中声明的函数
* 生成库文件。mac下使用：g++ -dynamiclib -I /System/Library/Frameworks/JavaVM.framework/Headers MyTest.cpp -o libJniTest.jnilib
注意：文件名以lib开头+库名字+jnilib后缀。
* 运行:java JniTest
