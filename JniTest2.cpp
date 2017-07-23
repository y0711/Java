#include "JniTest2.h"

#include <jni.h>

JNIEXPORT jstring JNICALL Java_JniTest2_getLine
  (JNIEnv *env, jobject, jstring prompt) {
  	signed char buf[128];
  	// This is C++ style. C style is like: (*env)->GetStringUTFChars(env, prompt, NULL)
  	const jbyte *str = (signed char*)env->GetStringUTFChars(prompt, NULL);
  	if (str == NULL) {
  		return NULL;
  	}
  	printf("%s", str);
  	printf("string length is %d, utf length is %d, chars is [%s], utf chars is [%s]",
  	 env->GetStringLength(prompt),
  	 env->GetStringUTFLength(prompt),
  	 // Returns const jchar*, aka const unsigned short.
  	 // isCopy = JNI_TRUE, or JNI_FALSE, or NULL.
  	 (char*)env->GetStringChars(prompt, NULL),
  	 (char*)env->GetStringUTFChars(prompt, NULL)
  	 );
  	int length = env->GetStringLength(prompt);

  	jchar outBuff[128];
  	env->GetStringRegion(prompt, 0, length, outBuff);
  	printf("outBuff: %s\n", (char*)outBuff);

  	env->ReleaseStringUTFChars(prompt, NULL);
  	scanf("%s", buf);
  	return env->NewStringUTF((const char*)buf);
  }
