SRC:=*.cpp
EXE:=ex01

all :
	gcc $(SRC) -o $(EXE)
	@echo ---------run process $(EXE)-----------
	@./$(EXE)
	@echo ---------$(EXE) finished!-----------
.PHONY : clean
clean:
	@rm -fr *.o
	@rm -f $(EXE)
