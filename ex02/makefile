SRC:=*.cpp
EXE:=ex02

all :
	gcc $(SRC) -o $(EXE)
	@echo ---------run process $(EXE)-----------
	@./$(EXE)
	@echo ---------$(EXE) finished!-----------
.PHONY : clean
clean:
	@rm -fr *.o
	@rm -f $(EXE)
