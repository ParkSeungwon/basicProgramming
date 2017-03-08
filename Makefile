CFLAG = -g -fmax-errors=1 -lm -std=c++14
CC = g++
SRC = $(wildcard *.cpp)
EXE = $(patsubst %.cpp, %.x, $(SRC))
PNG = $(patsubst %.cpp, %.png, $(SRC))

all : $(EXE)
png : $(PNG)
tex : report.pdf

%.x : %.cpp
	$(CC) $< -o $@ $(CFLAG)

%.png : %.x
	@head $*.cpp
	@echo "---------- 문제 $<\b\b번 실행을 시작합니다. --------------------------"
	./$<
	@echo "---------- 문제 $<\b\b번 실행을 종료합니다. -----------------------------"
	@gnome-screenshot -wBf $@

report.pdf : report.tex $(PNG) $(EXE) $(SRC)
	pdflatex report.tex
	evince report.pdf

clean:
	rm $(EXE)
