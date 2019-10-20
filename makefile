all: Jogar_Batalha_Naval

Jogar_Batalha_Naval: Main.cpp Funcoes_BatNaval.cpp
	g++ Main.cpp Funcoes_BatNaval.cpp -o Jogar_Batalha_Naval -Wall 

run:
	clear
	./Jogar_Batalha_Naval

clean:
	rm Jogar_Batalha_Naval

