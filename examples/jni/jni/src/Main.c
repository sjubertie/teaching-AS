#include "Main.h"
#include "test.h"

JNIEXPORT jint JNICALL Java_Main_quaranteDeux (JNIEnv * env, jclass obj) {
  return quaranteDeux();
}

JNIEXPORT jint JNICALL Java_Main_fact(JNIEnv* env, jclass obj, jint n) {
  return fact(n);
}
