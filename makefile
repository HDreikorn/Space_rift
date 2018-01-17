#Author: Hillary Dreikorn
#Date: 12/1/2017
#Description: This is a Makefile for Space Rift Final Project
CXX = g++ -std=c++11
CFLAGS = -g
CFLAGS = -Wall
CFLAGS += -pedantic
SRCS = ${wildcard *.cpp}
OBJS =  ${SRCS:.cpp=.o}
DEPS = ${wildcard *.hpp}
RSRCS = ${wildcard *.txt}

rift: $(OBJS)
	${CXX} -o $@ $^

.PHONY: clean
clean:
	rm -f ${OBJS} rift

zip: ${ZIP}
	zip -D FinalProj_Dreikorn_Hillary.zip ${SRCS} ${DEPS} ${RSRCS} \
	HDreikorn_Reflection.pdf makefile
