CFLAG = -g -fmax-errors=1 -lm
CC = gcc
SRC = $(wildcard *.c)
EXE = $(patsubst %.c, %.x, $(SRC))
PNG = $(patsubst %.c, %.png, $(SRC))

all : $(EXE)
png : $(PNG)
tex : report.pdf

%.x : %.c
	$(CC) $< -o $@ $(CFLAG)

%.png : %.x
	@echo "---------- 문제 $<\b\b번 실행을 시작합니다. --------------------------"
	./$<
	@echo "---------- 문제 $<\b\b번 실행을 종료합니다. -----------------------------"
	@gnome-screenshot -wBf $@

report.pdf : report.tex $(PNG) $(EXE) $(SRC)
	pdflatex report.tex
	evince report.pdf

clean:
	rm $(EXE)
