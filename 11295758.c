#include <stdio.h>
#define MAX 15
#define FALSE 0
#define TRUE 1

int remover1(int k, int n, int* v){
    int i = 0;
    if(k>n-1){
        return -1;
    }
	for(i=k;i<n;i++){
        v[i] = v[i+1];
    }
	n--;
    return n;
}
int inserir1(int x, int k, int n, int*v){
    int i = 0;

    for(i=n;i>k;i--){
        v[i] = v[i-1];
    }
    v[k] = x;
	n++;
	return n;
}
int remover2(int k, int n, int ini, int fim, int v[]){
	int met = n/2;
	int i = 0;
	if(k>n-1){
        return -1;
    }
	if(k>met){
		for(i=k+1;i<fim;i++){
			v[i] = v[i+1];
		}
		n--;
		return n;
	}else{
		for(i=k;i>ini;i--){
			v[i] = v[i-1];
		}
		n--;
		return n;
	}
}
void inserir3(int x, int k, int n, int* v){
	int i=0;
	if(n==MAX-1){
		v[MAX] = v[k];
	}
	for(i=n;i>=k;i--){
		v[i+1] = v[i];
	}
	v[k+1] = x;
	n++;
}
int tamanhoSegmentoHorizontal (int n, int * v){
    int contAtu = 1;
	int i = 0;
	int cont = 0;
    for(i=0;i<n-1;i++){
        if(v[i]==v[i+1]){
            contAtu++;
            if(contAtu>cont){
                cont = contAtu;
            }
        }else{
            contAtu = 1;
        }
    }
	return cont;
}
void remover6(int y, int n, int ini, int fim, int* v){
	int i,j=0;
	for(i=0;i<fim;i++){
		if(v[i]==y){
			for(j=i;j<fim;j++){
				v[j] = v[j+1]; 
			}
		}
	}
}
int onde(int x, int n, int* v){
	if(v[n]==x){
		return n;
	}else{
		if(n>=0){
			n--;
			onde(x,n,v);
		}else{
			return n;
		}
	}
}
int localiza(int x, int n, int ini, int fim, int* v){
	if(v[fim]==x){
		return fim;
	}else{
		if(fim>ini){
			fim--;
			localiza(x,n,ini,fim,v);
		}else{
			return -1;
		}
	}
}