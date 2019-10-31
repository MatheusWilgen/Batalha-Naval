all: Jogar_Batalha_Naval

Jogar_Batalha_Naval: Main.cpp Funcoes_BatNaval.cpp Barcos.cpp Tabuleiro.cpp Tabuleiro.h
	g++ Main.cpp Funcoes_BatNaval.cpp Tabuleiro.cpp Barcos.cpp -o Jogar_Batalha_Naval -Wall 

run:
	clear
	./Jogar_Batalha_Naval

clean:
	rm Jogar_Batalha_Naval

