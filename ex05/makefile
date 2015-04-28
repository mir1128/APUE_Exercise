SRC:=*.cpp
EXE:=ex05

all :
	g++ $(SRC) -o $(EXE)
	@echo ---------run process $(EXE)-----------
	@./$(EXE)
	@echo ---------$(EXE) finished!-----------
.PHONY : clean
clean:
	@rm -fr *.o
	@rm -f $(EXE)
	@rm -f file.hole
