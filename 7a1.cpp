#include <fstream>	
#include <iostream>	
#include <string>	
#include <stdio.h>
#include <stdlib.h>

using namespace std;

	// Estrutura pacote, max 5 fig. por pacote
	typedef struct{
		int figurinha[5];
	}Pacote;
	
	Pacote pacote;

	// Estrutura album, max 5 fig. por album
	typedef struct{
	int figurinhas[682];
	int qtdeFigColadas;
	}Album;
	
	Album album;
	
	iniciarAlbum(){
		for(int i = 0; i < 681; i++){
			album.figurinhas[i] = 0;
		}
		album.qtdeFigColadas = 0;
		for(int i = 0; i < 5; i++){
			pacote.figurinha[i] = 0;
		}
		
	}
	
	//Abrindo Album
	void abrirAlbum(){
		char url[]="eu_tenho.txt", info[50];
	}
	
	//Imprimir Album
	void imprimirAlbum(){
		cout << " ___________________________________ " << endl;
		cout << "| FIGURINHAS QUE TENHO NO MEU ALBUM |" << endl;
		cout << "|___________________________________|" << endl;
		for(int i = 0; i < 681; i++){
			if(album.figurinhas[i] > 0){
				cout << "\nAlbum contem figurinha: " << i << endl;
			}
		}
	}
	
	//Salvando Album
	void salvarAlbum(){
		ofstream albumdacopa;
		
		albumdacopa.open("eu_tenho.txt");
	
		// Agora grava as figurinhas que temos coladas.
		albumdacopa << " ___________________________________ " << endl;
		albumdacopa << "| FIGURINHAS QUE TENHO NO MEU ALBUM |" << endl;
		albumdacopa << "|___________________________________|" << endl;
		for(int i = 0; i < 681; i++){
			if(album.figurinhas[i] > 0){
				albumdacopa << i << endl;
			}
		}	
	}
		
	//COMPRANDO PACOTINHOS
	void Imprimirpacotinhos(){
	
		for(int i = 1; i < 2; i++){
			cout << "\n\nPacotinho \n";
		
			for (i=0; i < 5; i++)			
		    {
		    	//Guarda figura pacote
		    	pacote.figurinha[i] = rand() % 681;
		    	//Exibe figura pacote
		        cout << "\n" << i+1 << "� Figurinha: " << pacote.figurinha[i];
		    }  
		}
	}
	
	//Colando Figurinhas
	void colarFigurinha(int figura){
		
		if(album.figurinhas[figura] < 1){	
			// Adiciona +1 no array album.figurinhas, na posicao "figura"
			album.figurinhas[figura]++;
			// Incrementa o numero de figuras coladas
			album.qtdeFigColadas++;
		}
		else{
			// Adiciona +1 no array album.figurinhas, na posicao "figura"
			// e nao incrementa "Coladas" pois ja � figura repetida
			album.figurinhas[figura]++;
		}
	}
	
	//Figurinha unica
	void colarFigura(){
		int figura = 0;
		cout << "Informe a figurinha que voce quer colar: ";
		cin >> figura;
		colarFigurinha(figura);
	}
	
	//Colando Pacotinhos
	void colarPacoteFigurinha(){
		for(int i = 0; i < 5; i++){
			colarFigurinha(pacote.figurinha[i]);
		}
	}
	
	void conferir(){
		int figura;
		cout << "\nDigite o numero da figurinha:";
		cin >> figura;
		if(album.figurinhas[figura] > 0){
			cout << "\nVoce ja tem essa figurinha";
		}else{
			cout << "\nVoce ainda nao tem essa figurinha";
		}	
	}
	
	bool conferirBool(int figura){
		if(album.figurinhas[figura] > 0){
			return true;
		}else{
			return false;
		}	
	}
	
	
	void figfaltando(){
		// Cria output file stream (ofstream)
		ofstream faltam;
		// Cria e abre arquivo
		faltam.open("Faltantes.txt");
		cout << "\n\n\n";
		cout << " ____________________________________ " << endl;
		cout << "| FIGURINHAS QUE FALTAM NO MEU ALBUM |" << endl;
		cout << "|____________________________________|" << endl;
		for(int i = 0; i < 682; i++){

			if(album.figurinhas[i] == 0){
				cout << i << " " << endl;
			}
		} 
		faltam << " ____________________________________ " << endl;
		faltam << "| FIGURINHAS QUE FALTAM NO MEU ALBUM |" << endl;
		faltam << "|____________________________________|" << endl;
		for(int i = 0; i < 682; i++){

			if(album.figurinhas[i] == 0){
				faltam << i << " " << endl;
			}
		}
	}
	
	bool boleano()
	{	
		int figura;
		cout << "\nDigite o numero da figurinha:";
		cin >> figura;
		if(album.figurinhas[figura] > 0){
			cout << "\nTrue";
		}else{
			cout << "\nFalse";
		}
	}
	
	//Figurinhas repetidas
	void repetidass(){
		// Criando txt
		ofstream repetidasdacopa;
		repetidasdacopa.open("repetidas.txt");
		
		cout << " ___________________________________ " << endl;
		cout << "| FIGURINHAS REPETIDAS DO MEU ALBUM |" << endl;
		cout << "|___________________________________|" << endl;
		for(int i = 0; i < 681; i++){
			// Somente imprime posicao que tiver mais que 0 figurinhas
			// As repetidas subtrai 1, pois 1 figurinha ja esta colada
			if(album.figurinhas[i] > 1){
				cout << i << " " << (album.figurinhas[i] - 1) << endl;
			}
		}
		
		// Gravando as figurinhas no txt.
		repetidasdacopa << " ___________________________________ " << endl;
		repetidasdacopa << "| FIGURINHAS REPETIDAS DO MEU ALBUM |" << endl;
		repetidasdacopa << "|___________________________________|" << endl;
		for(int i = 0; i < 681; i++){
			// Somente imprime posicao que tiver mais que 0 figurinhas
			// As repetidas subtrai 1, pois 1 figurinha ja esta colada
			if(album.figurinhas[i] > 0){
				repetidasdacopa << i << " " << (album.figurinhas[i] - 1) << endl;
			}
		}
	}
	
	bool boleano_repetidas(int digfigurinha ){	
		if(album.figurinhas[digfigurinha] > 1){
			cout << "true";
			return true;
		}else{
			cout << "false"; 
			return false;
		}	
	}
	
	void troca(){
		int figura = 0;
		int repetida = 0;
		cout << "Figurinha a receber: ";
		cin >> figura;
		bool teste;
		teste = conferirBool(figura);
		if(teste = false){
			cout << "Voce ja tem essa figurinha!" << endl;
			return;
		}
		cout << "Figura repetida para troca: ";
		cin >> repetida;
		teste = boleano_repetidas(repetida);
		if(teste = true){
			album.figurinhas[figura]++;
			album.qtdeFigColadas++;
			album.figurinhas[repetida]--;
		}else{
			cout << "Voce n tem essa figurinha repetida" << endl;
		}	
	}
	
		
void menu(){
	
	int opcao;
	
	do{        //Menu para cadastrar
		cout << "\n\nALBUM COPA\n";
		cout << "\n1 - Figurinhas Coladas no album";
		cout << "\n2 - Figurinhas que est�o faltando no album";
		cout << "\n3 - (True) se ter a figurinha senao (False)";
		cout << "\n4 - Comprar pacotinho";
		cout << "\n5 - Colar Figurinha";
		cout << "\n6 - Salvar Album";
		cout << "\n7 - Abrir Album";
		cout << "\n8 - Saber se a figurinha esta colada no album";
		cout << "\n9 - Figurinhas Repetidas";
		cout << "\n10 - (True) se ter a figurinha repetida senao (False)";
		cout << "\n11 - Troca";
		cout << "\n12 - Informe a figura que voce quer colar";
		cout << "\n0 - Sair\n\n";
		cin >> 	opcao;

    switch (opcao){
    	
        case 1: imprimirAlbum();
        break;	
		
		case 2: figfaltando();
        break;  
		  
		case 3: boleano();
        break;       
        
        case 4:	Imprimirpacotinhos(); // Compra de pacotinhos
        break;	      
        
        case 5:	colarPacoteFigurinha();
        break;
        
        case 6:	salvarAlbum();
        break;
        
        case 7:	abrirAlbum();
        break;
        
    	case 8:	conferir();
        break;
        
        case 9:	repetidass();
        break;
        
        case 10: 
		bool bolrepetidas;
		int f;
		cout << "Digite figurinha repetida a ser pesquisada: ";
		cin >> f;
		bolrepetidas=boleano_repetidas(f);
		if(bolrepetidas == true){
			cout << "Figurinha encontrada";
		}else{
			cout << "Figurinha nao encontrada";
		}
        break;
        
        case 11: troca();
        break;
        
        case 12: colarFigura();
        break;
        
        case 0:	//sair
        break;
        
       	default: cout << "\nOp��o n�o existente.\n";
		break;
	
		}
	}while(opcao != 0);

}	

int main(){

    setlocale(LC_ALL, "Portuguese");
	iniciarAlbum();
	menu();

	return 0;
}
