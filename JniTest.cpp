#include "JniTest.h"
#include <jni.h>
#include <stdio.h>

// Note: the function should be indentical to JniTest.h
JNIEXPORT void JNICALL Java_JniTest_sayHello(JNIEnv *, jobject) {
	printf("Hello World\n");
	return;
}
