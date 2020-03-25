#include <iostream>
using namespace std;

class Maxheap{
	private:
		int capacidade;
		int tamanho;
		int* dados;
	public:
		Maxheap(int cap)
		{
			capacidade=cap;
			tamanho=0;
			dados=new int[capacidade];
		}
		void insere(int valor)
		{
			if(tamanho!=capacidade)
			{
				dados[tamanho]=valor;
				if(tamanho!=0)
				{
					corrigeSubindo(tamanho);
				}
				tamanho++;
			}
		};
		int GetFilhoEsquerda(int pos)
		{
			return ((2*pos)+1);
		};
		int GetFilhoDireita(int pos)
		{
			return ((2*pos)+2);
		};
		int GetPai(int pos)
		{
			return ((pos-1)/2);
		};
		void corrigeSubindo(int pos)
		{
			int pai=GetPai(pos);
			if(pos!=0)
			{
				if(dados[pos] > dados[pai])
				{
					int temp = dados[pai];
					dados[pai] = dados[pos];
					dados[pos] =temp;
					corrigeSubindo(pai);
				}
			}
		};
		int remove()
		{
			if(tamanho!=0)
			{
				int temp=dados[0];
				dados[0]=dados[tamanho-1];
				if(tamanho!=1)
				{
					CorrigeDescendo(0);
				}
				tamanho--;
				return temp;
			}
			return -1;
		}
		void CorrigeDescendo(int pos)
		{
			int fe=GetFilhoEsquerda(pos);
			int fd=GetFilhoDireita(pos);
			int maior = pos;
			
			if((fe<tamanho) and (dados[maior]<dados[fe]))
			{
				maior=fe;
			}
			
			if((fd<tamanho) and (dados[maior]<dados[fd]))
			{
				maior=fd;
			}
			
			if(maior!=pos)
			{
				int temp =dados[maior];
				dados[maior]=dados[pos];
				dados[pos]=temp;
				CorrigeDescendo(maior);
			}
		};
		void imprime()
		{
			for (int i = 0; i < tamanho; i++)
			{
				cout<<dados[i]<<" ";
			}
			cout<<endl;
		};
		void heapsort()
		{
			while(tamanho>0)
			{
				cout<<remove()<<" ";
			}
			cout<<endl;
		};
};
int main(){
	
	Maxheap heap(10);
	int n;
	for (int i = 0; i < 8; i++)
	{
		cin>>n;
		heap.insere(n);
	}
	heap.imprime();
	heap.heapsort();
	
	return 0;
}
