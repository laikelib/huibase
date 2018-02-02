##===================================================================##
## File Name: makefile
## Create Author: Tom Hui
## Create Date: Tue Sep 12 1359 2015
## Description:
##		
##===================================================================##

include ../inc.mk


TARGET = ${BIN_PATH}/test.a

SRC = $(wildcard *.cpp)

OBJS = ${patsubst %.cpp, %.o, ${SRC}}

CXX_INCLUDE += -I../crypto -I../http
LINK_CXX_LIBS += ../deps/openssl/libcrypto.a ../deps/curl/lib/.libs/libcurl.a -lz -pthread

ifeq "$(OS_TYPE)" "Darwin"
LINK_CC_LIBS += -liconv
endif

TTYPE = EFILE

all: def

def: ${TARGET}


include ../route.mk

