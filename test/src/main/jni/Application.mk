APP_ABI := armeabi
#APP_ABI := armeabi armeabi-v7a x86 mips
APP_STL := gnustl_static

APP_CPPFLAGS := -frtti -DCC_ENABLE_CHIPMUNK_INTEGRATION=1 -DCOCOS2D_DEBUG=1 -std=c++11
APP_PLATFORM := android-8

NDK_TOOLCHAIN_VERSION := clang