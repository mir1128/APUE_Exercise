SRC:=*.cpp
EXE:=ex22

all :
	g++ $(SRC) -o $(EXE)
	@echo ---------run process $(EXE)-----------
	@./$(EXE)
	@echo ---------$(EXE) finished!-----------
.PHONY : clean
clean:
	@rm -fr *.o
	@rm -f $(EXE)
